#include "videoPlayerWidget.h"
#include "videoPlayerControlsWidget.h"

#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QMediaMetadata>
#include <QSlider>

VideoPlayerWidget::VideoPlayerWidget(const QUrl &videoFileUrl, QWidget *parent)
    : QWidget(parent)
    , videoFileUrl(videoFileUrl)
{
    setupUi();
}

void VideoPlayerWidget::setVideoProgress(float progress)
{
    const qint64 position = qint64(progress * float(mediaPlayer->duration()));
    mediaPlayer->setPosition(position);
}

void VideoPlayerWidget::setupUi() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSizeConstraint(QLayout::SetMinimumSize);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(10);

    createVideoWidget();
    layout->addWidget(videoWidget);
    layout->setAlignment(videoWidget, Qt::AlignCenter);

    videoPlayerControlsWidget = new VideoPlayerControlsWidget(this);
    connect(videoPlayerControlsWidget->getTimelineSlider(), &QSlider::sliderMoved, this, &VideoPlayerWidget::onTimelineSliderMoved);
    layout->addWidget(videoPlayerControlsWidget);
    layout->setAlignment(videoPlayerControlsWidget, Qt::AlignHCenter | Qt::AlignTop);

    setLayout(layout);
}

void VideoPlayerWidget::createVideoWidget()
{
    mediaPlayer = new QMediaPlayer;
    mediaPlayer->setSource(videoFileUrl);
    connect(mediaPlayer, &QMediaPlayer::metaDataChanged, this, &VideoPlayerWidget::onMetadataChanged);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoPlayerWidget::onMediaPlayerPositionChanged);

    audioOutput = new QAudioOutput;
    audioOutput->setVolume(100);
    mediaPlayer->setAudioOutput(audioOutput);

    videoWidget = new QVideoWidget;
    videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);
    mediaPlayer->setVideoOutput(videoWidget);

    mediaPlayer->play();
}

void VideoPlayerWidget::onMetadataChanged()
{
    QVariant resolutionValue = mediaPlayer->metaData().value(QMediaMetaData::Resolution);
    if (resolutionValue.canConvert<QSize>()) {
        QSize resolution = resolutionValue.toSize();
        if (resolution.width() > 0 && resolution.height() > 0) {
            videoWidget->setFixedSize(resolution);
            videoPlayerControlsWidget->setTimelineWidth(resolution.width());
        }
    }
}

void VideoPlayerWidget::onMediaPlayerPositionChanged(quint64 position)
{
    const float progress = float(position) / float(mediaPlayer->duration());
    videoPlayerControlsWidget->setTimelineProgress(progress);
}

void VideoPlayerWidget::onTimelineSliderMoved(int value)
{
    const float progress = VideoPlayerControlsWidget::calculateProgress(value);
    setVideoProgress(progress);
}

void VideoPlayerWidget::onPlayPausePressed()
{
    switch(mediaPlayer->playbackState()) {
        case QMediaPlayer::PlayingState: mediaPlayer->pause(); break;
        case QMediaPlayer::PausedState: mediaPlayer->play(); break;
        case QMediaPlayer::StoppedState:;
    }
}

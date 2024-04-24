#include "videoPlayerWidget.h"
#include "videoPlayerControlsWidget.h"

#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QMediaMetadata>

VideoPlayerWidget::VideoPlayerWidget(const QUrl &videoFileUrl, QWidget *parent)
    : QWidget(parent)
    , videoFileUrl(videoFileUrl)
{
    setupUi();
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
    layout->addWidget(videoPlayerControlsWidget);
    layout->setAlignment(videoPlayerControlsWidget, Qt::AlignHCenter | Qt::AlignTop);

    setLayout(layout);
}

void VideoPlayerWidget::createVideoWidget()
{
    mediaPlayer = new QMediaPlayer;
    mediaPlayer->setSource(videoFileUrl);
    connect(mediaPlayer, &QMediaPlayer::metaDataChanged, this, &VideoPlayerWidget::onMetadataChanged);

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

void VideoPlayerWidget::onPlayPausePressed()
{
    switch(mediaPlayer->playbackState()) {
        case QMediaPlayer::PlayingState: mediaPlayer->pause(); break;
        case QMediaPlayer::PausedState: mediaPlayer->play(); break;
        case QMediaPlayer::StoppedState:;
    }
}

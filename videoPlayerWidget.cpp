#include "videoPlayerWidget.h"

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

    createVideoWidget();
    layout->addWidget(videoWidget);

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
        }
    }
}

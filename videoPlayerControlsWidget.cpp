#include "videoPlayerControlsWidget.h"
#include "videoPlayerWidget.h"

#include <QHBoxLayout>
#include <QPushButton>

VideoPlayerControlsWidget::VideoPlayerControlsWidget(QWidget *parent)
    : QWidget{parent}
{
    setupUi();
}

void VideoPlayerControlsWidget::setupUi()
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    playPauseButton = new QPushButton("pause", this);
    connect(playPauseButton, &QPushButton::clicked, this, &VideoPlayerControlsWidget::onPlayPausePressed);
    playPauseButton->setFixedSize(120, 40);
    layout->addWidget(playPauseButton);

    setLayout(layout);
}

void VideoPlayerControlsWidget::onPlayPausePressed()
{
    playPauseButton->setText(isPlaying ? "play" : "pause");
    isPlaying = !isPlaying;

    // Try to cast the parent to VideoPlayerWidget.
    // Use dynamic_cast to detect if the parent can be casted at all.
    // If parent cannot be casted, or is null, we will not call its slot.
    if (VideoPlayerWidget *parentCasted = dynamic_cast<VideoPlayerWidget*>(parent())) {
        parentCasted->onPlayPausePressed();
    }
}

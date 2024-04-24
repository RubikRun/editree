#include "videoPlayerControlsWidget.h"
#include "videoPlayerWidget.h"

#include <QHBoxLayout>
#include <QPushButton>

VideoPlayerControlsWidget::VideoPlayerControlsWidget(QWidget *parent)
    : QWidget{parent}
    , playIcon("C:/dev/editree/icons/play_button.png")
    , pauseIcon("C:/dev/editree/icons/pause_button.png")
{
    setupUi();
}

void VideoPlayerControlsWidget::setupUi()
{
    QHBoxLayout *layout = new QHBoxLayout(this);

    playPauseButton = new QPushButton(pauseIcon, "", this);
    playPauseButton->setIconSize(PLAY_PAUSE_BUTTONS_SIZE);
    playPauseButton->setFixedSize(PLAY_PAUSE_BUTTONS_SIZE);
    connect(playPauseButton, &QPushButton::clicked, this, &VideoPlayerControlsWidget::onPlayPausePressed);
    layout->addWidget(playPauseButton);

    setLayout(layout);
}

void VideoPlayerControlsWidget::onPlayPausePressed()
{
    playPauseButton->setIcon(isPlaying ? playIcon : pauseIcon);
    isPlaying = !isPlaying;

    // Try to cast the parent to VideoPlayerWidget.
    // Use dynamic_cast to detect if the parent can be casted at all.
    // If parent cannot be casted, or is null, we will not call its slot.
    if (VideoPlayerWidget *parentCasted = dynamic_cast<VideoPlayerWidget*>(parent())) {
        parentCasted->onPlayPausePressed();
    }
}

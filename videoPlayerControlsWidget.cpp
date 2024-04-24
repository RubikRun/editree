#include "videoPlayerControlsWidget.h"
#include "videoPlayerWidget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

VideoPlayerControlsWidget::VideoPlayerControlsWidget(QWidget *parent)
    : QWidget(parent)
    , parentVideoPlayer(dynamic_cast<VideoPlayerWidget*>(parent))
    , playIcon("C:/dev/editree/icons/play_button.png")
    , pauseIcon("C:/dev/editree/icons/pause_button.png")
{
    setupUi();
}

void VideoPlayerControlsWidget::setTimelineWidth(int width)
{
    timelineSlider->setFixedWidth(width);
}

void VideoPlayerControlsWidget::setTimelineProgress(float progress)
{
    timelineSlider->setValue(int(progress * float(TIMELINE_SLIDER_POSITIONS_COUNT)));
}

const QSlider *VideoPlayerControlsWidget::getTimelineSlider() const
{
    return timelineSlider;
}

float VideoPlayerControlsWidget::calculateProgress(int value)
{
    const float progress = float(value) / float(TIMELINE_SLIDER_POSITIONS_COUNT);
    return progress;
}

void VideoPlayerControlsWidget::setupUi()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    timelineSlider = new QSlider(Qt::Horizontal, this);
    timelineSlider->setMinimum(0);
    timelineSlider->setMaximum(TIMELINE_SLIDER_POSITIONS_COUNT);
    layout->addWidget(timelineSlider);

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

    if (parentVideoPlayer) {
        parentVideoPlayer->onPlayPausePressed();
    }
}

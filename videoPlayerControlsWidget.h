#ifndef VIDEOPLAYERCONTROLSWIDGET_H
#define VIDEOPLAYERCONTROLSWIDGET_H

#include <QWidget>
#include <QIcon>

QT_BEGIN_NAMESPACE
class QPushButton;
class QSlider;
QT_END_NAMESPACE

class VideoPlayerWidget;

class VideoPlayerControlsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerControlsWidget(QWidget *parent = nullptr);

    void setTimelineWidth(int width);
    void setTimelineProgress(float progress);
    const QSlider *getTimelineSlider() const;
    static float calculateProgress(int value);

private:
    void setupUi();

    VideoPlayerWidget *parentVideoPlayer = nullptr;

    QPushButton *playPauseButton = nullptr;
    QIcon playIcon;
    QIcon pauseIcon;

    QSlider *timelineSlider = nullptr;

    bool isPlaying = true;

private slots:
    void onPlayPausePressed();

private:
    static constexpr QSize PLAY_PAUSE_BUTTONS_SIZE = QSize(40, 40);
    static const int TIMELINE_SLIDER_POSITIONS_COUNT = 1000;
};

#endif // VIDEOPLAYERCONTROLSWIDGET_H

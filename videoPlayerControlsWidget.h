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
};

#endif // VIDEOPLAYERCONTROLSWIDGET_H

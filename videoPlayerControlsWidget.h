#ifndef VIDEOPLAYERCONTROLSWIDGET_H
#define VIDEOPLAYERCONTROLSWIDGET_H

#include <QWidget>
#include <QIcon>
#include <QSize>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class VideoPlayerControlsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerControlsWidget(QWidget *parent = nullptr);

private:
    void setupUi();

    QPushButton *playPauseButton = nullptr;
    QIcon playIcon;
    QIcon pauseIcon;

    bool isPlaying = true;

private slots:
    void onPlayPausePressed();

private:
    static constexpr QSize PLAY_PAUSE_BUTTONS_SIZE = QSize(60, 60);
};

#endif // VIDEOPLAYERCONTROLSWIDGET_H

#ifndef VIDEOPLAYERCONTROLSWIDGET_H
#define VIDEOPLAYERCONTROLSWIDGET_H

#include <QWidget>

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

    bool isPlaying = true;

private slots:
    void onPlayPausePressed();
};

#endif // VIDEOPLAYERCONTROLSWIDGET_H

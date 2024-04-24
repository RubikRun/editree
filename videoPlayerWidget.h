#ifndef VIDEOPLAYERWIDGET_H
#define VIDEOPLAYERWIDGET_H

#include <QWidget>
#include <QUrl>

QT_BEGIN_NAMESPACE
class QMediaPlayer;
class QAudioOutput;
class QVideoWidget;
QT_END_NAMESPACE

class VideoPlayerControlsWidget;

class VideoPlayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerWidget(const QUrl &videoFileUrl, QWidget *parent = nullptr);

    void setVideoProgress(float progress);

public slots:
    void onPlayPausePressed();

private:
    void setupUi();
    void createVideoWidget();

    QMediaPlayer *mediaPlayer = nullptr;
    QAudioOutput *audioOutput = nullptr;
    QVideoWidget *videoWidget = nullptr;

    VideoPlayerControlsWidget *videoPlayerControlsWidget = nullptr;

    QUrl videoFileUrl;

    bool timelineLocked = false;

private slots:
    void onMetadataChanged();
    void onMediaPlayerPositionChanged(quint64 position);
    void onTimelineSliderMoved(int value);
    void onTimelineSliderPressed();
    void onTimelineSliderReleased();
};

#endif // VIDEOPLAYERWIDGET_H

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

private slots:
    void onMetadataChanged();
};

#endif // VIDEOPLAYERWIDGET_H

#ifndef VIDEOPLAYERWIDGET_H
#define VIDEOPLAYERWIDGET_H

#include <QWidget>
#include <QUrl>

QT_BEGIN_NAMESPACE
class QMediaPlayer;
class QAudioOutput;
class QVideoWidget;
QT_END_NAMESPACE

class VideoPlayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerWidget(const QUrl &videoFileUrl, QWidget *parent = nullptr);

private:
    void setupUi();
    void createVideoWidget();

    void onMetadataChanged();

    QMediaPlayer *mediaPlayer = nullptr;
    QAudioOutput *audioOutput = nullptr;
    QVideoWidget *videoWidget = nullptr;

    QUrl videoFileUrl;
};

#endif // VIDEOPLAYERWIDGET_H

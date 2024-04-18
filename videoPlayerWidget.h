#ifndef VIDEOPLAYERWIDGET_H
#define VIDEOPLAYERWIDGET_H

#include <QWidget>
#include <QLabel>

class VideoPlayerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayerWidget(const char *labelStr, QWidget *parent = nullptr);

private:
    void setupUi(const char *labelStr);

    QLabel *label = nullptr;
};

#endif // VIDEOPLAYERWIDGET_H

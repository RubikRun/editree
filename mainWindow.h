#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class VideoPlayerWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupUi();

    VideoPlayerWidget *videoPlayerWidget = nullptr;
};
#endif // MAINWINDOW_H

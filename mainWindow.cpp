#include "mainWindow.h"
#include "videoPlayerWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(640, 480);
    setupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi()
{
    videoPlayerWidget = new VideoPlayerWidget(QUrl::fromLocalFile("C:/dev/editree/videos/jluch.mp4"), this);
    setCentralWidget(videoPlayerWidget);
}

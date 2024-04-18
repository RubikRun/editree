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
    videoPlayerWidget = new VideoPlayerWidget("VideoPlayerWidget", this);
    setCentralWidget(videoPlayerWidget);
}

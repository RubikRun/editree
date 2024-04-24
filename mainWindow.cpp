#include "mainWindow.h"
#include "videoPlayerWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1300, 860);
    setupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi()
{
    videoPlayerWidget = new VideoPlayerWidget(QUrl::fromLocalFile("C:/dev/editree/videos/jluch.mp4"), this);
    setCentralWidget(videoPlayerWidget);
}

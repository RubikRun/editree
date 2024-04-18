#include "videoPlayerWidget.h"

#include <QVBoxLayout>

VideoPlayerWidget::VideoPlayerWidget(const char *labelStr, QWidget *parent)
    : QWidget(parent)
{
    setupUi(labelStr);
}

void VideoPlayerWidget::setupUi(const char *labelStr) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSizeConstraint(QLayout::SetMinimumSize);

    label = new QLabel(labelStr, this);
    label->adjustSize();
    layout->addWidget(label);

    setLayout(layout);
}

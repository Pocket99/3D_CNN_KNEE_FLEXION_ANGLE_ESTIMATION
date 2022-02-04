#ifndef OUTPUTVIDEO_H
#define OUTPUTVIDEO_H

#include <QDialog>

namespace Ui {
class OutputVideo;
}

class OutputVideo : public QDialog
{
    Q_OBJECT

public:
    explicit OutputVideo(QWidget *parent = nullptr);
    ~OutputVideo();

private:
    Ui::OutputVideo *ui;
};

#endif // OUTPUTVIDEO_H

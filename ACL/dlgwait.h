#ifndef DLGWAIT_H
#define DLGWAIT_H

#include <QDialog>

namespace Ui {
class DlgWait;
}

class DlgWait : public QDialog
{
    Q_OBJECT

public:
    explicit DlgWait(QWidget *parent = nullptr);
    ~DlgWait();

private:
    Ui::DlgWait *ui;
};

#endif // DLGWAIT_H

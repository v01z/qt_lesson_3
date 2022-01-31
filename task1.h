#ifndef TASK1_H
#define TASK1_H

#include <QDialog>

namespace Ui {
class Task1;
}

class Task1 : public QDialog
{
    Q_OBJECT

public:
    explicit Task1(QWidget *parent = nullptr);
    ~Task1();

private slots:
    void on_btnClose_clicked();

    void on_btnSave_clicked();

    void on_btnOpen_clicked();

    void on_btnHelp_clicked();

private:
    Ui::Task1 *ui;
};

#endif // TASK1_H

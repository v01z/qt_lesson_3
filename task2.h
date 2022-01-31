#ifndef TASK2_H
#define TASK2_H

#include <QDialog>

namespace Ui {
class Task2;
}

class Task2 : public QDialog
{
    Q_OBJECT

public:
    explicit Task2(QWidget *parent = nullptr);
    ~Task2();

private slots:
    void on_btnClose_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Task2 *ui;
    bool comboboxTipIsRemoved;
};

#endif // TASK2_H

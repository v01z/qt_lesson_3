#include "task1.h"
#include "ui_task1.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Task1::Task1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task1)
{
    ui->setupUi(this);
}

Task1::~Task1()
{
    delete ui;
}

void Task1::on_btnClose_clicked()
{
   close();
}


void Task1::on_btnSave_clicked()
{
    QString filePath { QFileDialog::getSaveFileName(this,
         "Save file as", QDir::current().path(),
            trUtf8("Text file(*.txt)")) };

    if (filePath.length())
    {
        QString ext { QString { &(filePath.data()
            [ filePath.length() - 4 ])}};

        QFile file { filePath };
        if (file.open(QFile::WriteOnly | QFile::NewOnly))
         {
           QTextStream stream(&file);
           stream << ui->plainTextEdit->toPlainText();
           file.close();
         }
        else //!open
        {
        QMessageBox::warning(this, "File not found",
             "Can't open file " + filePath);

        }

    }


}


void Task1::on_btnOpen_clicked()
{
    QString filePath { QFileDialog::getOpenFileName(this,
        "Choose file to open", QDir::current().path(),
            trUtf8("Text file(*.txt)")) };

    if (filePath.length())
    {
         int index = filePath.indexOf(".txt");
         if (index != -1 && filePath.length() - 4 == index)
         {
             QFile file { filePath };
             if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
             {
                 QTextStream stream(&file);
                 ui->plainTextEdit->setPlainText(
                    stream.readAll());
                 file.close();
             }
             else //!open
                 QMessageBox::warning(this, "File not found",
                    "Can't open file " + filePath);
         }

    }
}


void Task1::on_btnHelp_clicked()
{
    QString filePath { ":help.txt" };

    QFile file { filePath };
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
    {
     QTextStream stream(&file);
     ui->plainTextEdit->setPlainText(stream.readAll());
     file.close();
    }
    else //if !file.open()
        QMessageBox::warning(this, "File not found",
            "Can't open resource " + filePath);

}


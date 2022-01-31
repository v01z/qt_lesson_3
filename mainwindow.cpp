#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task1.h"
#include "task2.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnTask1_clicked()
{
   Task1 form;
   form.setModal(true);
   form.exec();

}


void MainWindow::on_btnTask2_clicked()
{
   Task2 form;
   form.setModal(true);
   form.exec();
}


void MainWindow::on_btnExit_clicked()
{
   QApplication::quit();
}


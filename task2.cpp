#include "task2.h"
#include "ui_task2.h"
#include "webinfo.h"

Task2::Task2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task2), comboboxTipIsRemoved(false)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Choose host");
    ui->comboBox->addItem(hostConvArr[0].hostName);
    ui->comboBox->addItem(hostConvArr[1].hostName);

    ui->label->setText("Here will be info when you " \
        "click on the combobox above.");

}

Task2::~Task2()
{
    delete ui;
}

void Task2::on_btnClose_clicked()
{
   close();
}


void Task2::on_comboBox_activated(const QString &arg1)
{
   WebInfo *webInfo = new WebInfo(ui->comboBox->currentText());

   ui->label->setText(webInfo->getWeather() + webInfo->getCurrency());

   if (comboboxTipIsRemoved == false)
   {
       ui->comboBox->removeItem(0); //Подсказка  нам более не требуется
       comboboxTipIsRemoved = true;
   }

   delete webInfo;

}


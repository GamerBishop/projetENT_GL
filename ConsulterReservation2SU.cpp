#include "consulterreservation2su.h"
#include "ui_consulterreservation2su.h"

ConsulterReservation2su::ConsulterReservation2su(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConsulterReservation2su)
{
    ui->setupUi(this);
    QDate  today = ui->calendar->selectedDate();
    QDate tomorrow = ui->calendar->selectedDate().addDays(1);

    QString today_date =  today.toString("ddd d MMMM");
    QString tomor_date =  tomorrow.toString("ddd d MMMM");

    const char* tod = today_date.toStdString().c_str();
    const char* tom = tomor_date.toStdString().c_str();
    ui->label_today->setText(ui->label_today->text()+" "+tod+" :");
    ui->label_next_day->setText(ui->label_next_day->text()+" "+tom+" :");

}

ConsulterReservation2su::~ConsulterReservation2su()
{
    delete ui;
}

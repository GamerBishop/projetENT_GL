#include "ihm_consulterreservations.h"
#include "ui_ihm_consulterreservations.h"

IHM_ConsulterReservations::IHM_ConsulterReservations(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_ConsulterReservations)
{
    ui->setupUi(this);
}

IHM_ConsulterReservations::~IHM_ConsulterReservations()
{
    delete ui;
}

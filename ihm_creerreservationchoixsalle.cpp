#include "ihm_creerreservationchoixsalle.h"
#include "ui_ihm_creerreservationchoixsalle.h"

IHM_CreerReservationChoixSalle::IHM_CreerReservationChoixSalle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_CreerReservationChoixSalle)
{
    ui->setupUi(this);
}

IHM_CreerReservationChoixSalle::~IHM_CreerReservationChoixSalle()
{
    delete ui;
}

#include "creerreservationsallesu.h"
#include "ui_creerreservationsallesu.h"

CreerReservationSalleSU::CreerReservationSalleSU(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreerReservationSalleSU)
{
    ui->setupUi(this);
    this->bdd=bdd;
}

CreerReservationSalleSU::~CreerReservationSalleSU()
{
    delete ui;
}

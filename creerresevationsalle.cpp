#include "creerresevationsalle.h"
#include "ui_creerresevationsalle.h"

CreerResevationSalle::CreerResevationSalle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreerResevationSalle)
{
    ui->setupUi(this);
    connect(ui->button_ok,SIGNAL(clicked()),this,SLOT(afficherCreerReservationChoixSalle()));
}

CreerResevationSalle::~CreerResevationSalle()
{
    delete ui;
}


CreerResevationSalle::afficherCreerReservationChoixSalle()
{
    choixSalle = new Ui::IHM_CreerReservationChoixSalle(*parent =0);
    //this->hide();
    //choixSalle
}

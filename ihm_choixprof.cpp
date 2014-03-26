#include "ihm_choixprof.h"
#include "ui_ihm_choixprof.h"

IHM_ChoixProf::IHM_ChoixProf(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM_ChoixProf)
{
    ui->setupUi(this);
}

IHM_ChoixProf::~IHM_ChoixProf()
{
    delete ui;
}

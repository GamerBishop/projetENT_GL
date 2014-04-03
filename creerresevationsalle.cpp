#include "creerresevationsalle.h"
#include "ui_creerresevationsalle.h"
#include "ihm_creerreservationchoixsalle.h"

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


void CreerResevationSalle::afficherCreerResevationChoixSalle()
{
    choixSalle = new IHM_CreerReservationChoixSalle();

    this->hide();
}

void CreerResevationSalle::on_combo_type_salle_currentIndexChanged(const QString &arg1)
{
    QString type_salle = arg1;
}


void CreerResevationSalle::on_combo_type_cours_currentIndexChanged(const QString &arg1)
{
    QString type_cours = arg1;
}

void CreerResevationSalle::on_combo_ue_currentIndexChanged(const QString &arg1)
{
    QString unite_en = arg1;
}

void CreerResevationSalle::on_combo_promo_currentIndexChanged(const QString &arg1)
{
    QString promotion = arg1;
}

void CreerResevationSalle::on_combo_groupe_currentIndexChanged(const QString &arg1)
{
    QString groupe = arg1;
}

void CreerResevationSalle::on_combo_prof_currentIndexChanged(const QString &arg1)
{
    QString prof_supp = arg1;
}

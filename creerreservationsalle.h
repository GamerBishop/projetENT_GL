#ifndef CREERRESEVATIONSALLE_H
#define CREERRESEVATIONSALLE_H

#include <QMainWindow>
#include "ihm_creerreservationchoixsalle.h"
#include "BDD.h"
namespace Ui {
class CreerReservationSalle;
}

class CreerReservationSalle : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreerReservationSalle(BDD * bdd,QWidget *parent = 0);
    ~CreerReservationSalle();
    IHM_CreerReservationChoixSalle *ihm_choixSalle;

private:
    Ui::CreerReservationSalle *ui;
    BDD * bdd;
signals:
    void signalRetour();
public slots:
    void retour();
    void choixSalle();
    void retourIHMSuivante();
};

#endif // CREERRESEVATIONSALLE_H

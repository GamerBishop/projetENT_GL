#ifndef IHM_CREERRESERVATIONCHOIXSALLE_H
#define IHM_CREERRESERVATIONCHOIXSALLE_H

#include <QMainWindow>
#include "BDD.h"
namespace Ui {
class IHM_CreerReservationChoixSalle;
}

class IHM_CreerReservationChoixSalle : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationChoixSalle(BDD *bdd,QWidget *parent = 0);
    ~IHM_CreerReservationChoixSalle();

private:
    Ui::IHM_CreerReservationChoixSalle *ui;
    QList<QList<QString> > tab;
    BDD * bdd;
signals:
    void signalRetour();
public slots:
    void retour();
};

#endif // IHM_CREERRESERVATIONCHOIXSALLE_H

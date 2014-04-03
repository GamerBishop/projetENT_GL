#ifndef CREERRESEVATIONSALLE_H
#define CREERRESEVATIONSALLE_H

#include <QMainWindow>
#include "ihm_creerreservationchoixsalle.h"


namespace Ui {
class CreerResevationSalle;
}

class CreerResevationSalle : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreerResevationSalle(QWidget *parent = 0);
    ~CreerResevationSalle();

private:
    Ui::CreerResevationSalle *ui;
    Ui::IHM_CreerReservationChoixSalle *choixSalle;

};

#endif // CREERRESEVATIONSALLE_H

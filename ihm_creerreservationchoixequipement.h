#ifndef IHM_CREERRESERVATIONCHOIXEQUIPEMENT_H
#define IHM_CREERRESERVATIONCHOIXEQUIPEMENT_H

#include <QMainWindow>

namespace Ui {
class IHM_CreerReservationChoixEquipement;
}

class IHM_CreerReservationChoixEquipement : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationChoixEquipement(QWidget *parent = 0);
    ~IHM_CreerReservationChoixEquipement();

private:
    Ui::IHM_CreerReservationChoixEquipement *ui;
};

#endif // IHM_CREERRESERVATIONCHOIXEQUIPEMENT_H
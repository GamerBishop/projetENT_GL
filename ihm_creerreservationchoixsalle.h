#ifndef IHM_CREERRESERVATIONCHOIXSALLE_H
#define IHM_CREERRESERVATIONCHOIXSALLE_H

#include <QMainWindow>

namespace Ui {
class IHM_CreerReservationChoixSalle;
}

class IHM_CreerReservationChoixSalle : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_CreerReservationChoixSalle(QWidget *parent = 0);
    ~IHM_CreerReservationChoixSalle();

private:
    Ui::IHM_CreerReservationChoixSalle *ui;
};

#endif // IHM_CREERRESERVATIONCHOIXSALLE_H

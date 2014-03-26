#ifndef IHM_CHOIXPROF_H
#define IHM_CHOIXPROF_H

#include <QMainWindow>

namespace Ui {
class IHM_ChoixProf;
}

class IHM_ChoixProf : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_ChoixProf(QWidget *parent = 0);
    ~IHM_ChoixProf();

private:
    Ui::IHM_ChoixProf *ui;
};

#endif // IHM_CHOIXPROF_H

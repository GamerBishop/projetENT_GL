#ifndef CONSULTEPLANNING_H
#define CONSULTEPLANNING_H

#include <QMainWindow>

namespace Ui {
class consultePlanning;
}

class consultePlanning : public QMainWindow
{
    Q_OBJECT

public:
    explicit consultePlanning(QWidget *parent = 0);
    ~consultePlanning();

private:
    Ui::consultePlanning *ui;
};

#endif // CONSULTEPLANNING_H

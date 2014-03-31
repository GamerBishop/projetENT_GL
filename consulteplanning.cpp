#include "consulteplanning.h"
#include "ui_consulteplanning.h"

consultePlanning::consultePlanning(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::consultePlanning)
{
    ui->setupUi(this);
}

consultePlanning::~consultePlanning()
{
    delete ui;
}

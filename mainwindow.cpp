#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(BDD * bdd,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->bdd=bdd;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(this->ui->id->text()!="")
    {
        if(this->ui->mdp->text()!="")
        {
            if(this->bdd->Connexion(this->ui->id->text(),this->ui->mdp->text()))
            {
                if(this->bdd->isProf())
                {
                    IHM_ChoixProf *w = new IHM_ChoixProf(this->bdd,this);
                    w->show();
                    connect(w,SIGNAL(signalExtinction()),this,SLOT(on_return()));
                    this->hide();
                }
                else
                {
                    IHM_ConsulterPlanning*w = new IHM_ConsulterPlanning(this->bdd,this);
                    w->show();
                    connect(w,SIGNAL(signalRetour(bool)),this,SLOT(on_return()));

                     this->hide();
                }
            }
            else
                QMessageBox::warning(this,"Attention","Votre login et/ou votre mot de passe sont incorrects");
        }
        else
            QMessageBox::warning(this,"Attention","Le mot de passe doit être renseigné");
    }
    else
        QMessageBox::warning(this,"Attention","Le login doit être renseigné");

}
void MainWindow::on_return(){
    this->ui->id->setText("");
    this->ui->mdp->setText("");
    this->show();
}

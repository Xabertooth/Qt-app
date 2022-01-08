#include "mainwin.h"
#include "ui_mainwin.h"
#include "QPixmap"
#include <QMessageBox>

MainWin::MainWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWin)
{
    ui->setupUi(this);  
}

MainWin::~MainWin()
{
    delete ui;
}

void MainWin::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        hide();
        dial = new Dialog(this);
        dial->ifs.open(":/filsRes/files/Ex_file.txt", std::ios::in);
        if(!dial->ifs.is_open()) std::runtime_error("Fail opened file!");
            dial->mapFiller(); //
            dial->ifs.close();
        dial->show();
    }
}

void MainWin::on_radioButton_clicked(bool checked)
{
    if(checked){
        QPixmap pixEx(":/res/img/vzrivozaschita.png");
        int w = ui->image->width();
        int h = ui->image->height();
        ui->statusbar->showMessage("Information about explosion protection");
        ui->image->setPixmap(pixEx.scaled(w, h, Qt::KeepAspectRatio));
    }
}


void MainWin::on_action_triggered()
{
    QMessageBox::about(this, "Xabertooth", "     konigan07@gmail.com     ");
}

void MainWin::on_actionExit_triggered()
{
    close();
}


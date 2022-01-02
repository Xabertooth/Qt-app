#include "mainwin.h"
#include "ui_mainwin.h"
#include "QPixmap"

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


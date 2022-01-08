#include "dialog.h"
#include "ui_dialog.h"
#include <regex>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //QObject::connect(ui->lineEdit_2, SIGNAL(textChanged()), this, SLOT(rewriter()));
}

void Dialog::mapFiller(){
    bool flag {true}; //
        std::string sKey, sValue; //
        map.clear(); //
        for (std::string s; std::getline(ifs, s);) { //
            if (flag) { //
                sKey = s; //
                flag = !flag; //
            }
            else if (s == "---") {
                flag = !flag;
                sValue += '\n';
                map.insert(std::make_pair(sKey, sValue)); //
                sValue.clear();
            }
            else {
                (sValue += s)+= '\n';
            }
        }
}

void Dialog::rewriter(){
    QString txt = ui->lineEdit_2->text()+ui->lineEdit_3->text()+ui->lineEdit_4->text()+ui->lineEdit_5->text()+ui->lineEdit_6->text();
    ui->lineEdit->clear();
    ui->lineEdit->insert(txt);
}

Dialog::~Dialog()
{
    delete ui;
}
//========================================================
void Dialog::on_pushButton_clicked()
{
    close();

}
//=========================================================
void Dialog::on_lineEdit_2_textChanged()
{
    std::string s;
    std::smatch matches;
    const std::regex pat {R"([0-2])"};
    if(!std::regex_match(s, matches, pat)){//
        auto search = map.find("");
    }
    rewriter();
}

void Dialog::on_lineEdit_3_textChanged()
{
    rewriter();
}

void Dialog::on_lineEdit_4_textChanged()
{
    rewriter();
}

void Dialog::on_lineEdit_5_textChanged()
{
    rewriter();
}

void Dialog::on_lineEdit_6_textChanged()
{
    rewriter();

}
//========================================================

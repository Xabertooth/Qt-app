#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMap>
#include<fstream>

namespace Ui {
class Dialog;
}
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    std::ifstream ifs;
    void mapFiller();
    void rewriter();

    ~Dialog();

private:
    void incert();
    void checkInput();
    std::map<std::string, std::string> map;
    QVector<QString> v;

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_2_textChanged();
    void on_lineEdit_3_textChanged();
    void on_lineEdit_4_textChanged();
    void on_lineEdit_5_textChanged();
    void on_lineEdit_6_textChanged();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

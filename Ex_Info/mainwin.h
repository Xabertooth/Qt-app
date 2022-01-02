#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked(bool checked);

private:
    Ui::MainWin *ui;
    Dialog* dial;
};
#endif // MAINWIN_H

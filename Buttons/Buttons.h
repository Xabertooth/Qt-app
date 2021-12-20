#pragma once
#include <QtWidgets>

//===============================================
class Buttons : public QGroupBox{
    Q_OBJECT
private:
    QWidget wgt;
    QCheckBox* m_pchk;
    QRadioButton* m_pradRed;
    QRadioButton* m_pradGreen;
    QRadioButton* m_pradBlue;
public:
    Buttons(QWidget* pwgt = 0);

public slots:
    void slotButtonClicked();
};

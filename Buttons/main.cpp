#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    QCheckBox* pchkNormal = new QCheckBox("&Normal Check Box");
    pchkNormal->setChecked(true);

    QGroupBox gbx("&Colors");
    QRadioButton* pradRed = new QRadioButton("&Red");
    QRadioButton* pradGreen = new QRadioButton("&Green");
    QRadioButton* pradBlue = new QRadioButton("&Blue");
    pradGreen->setChecked(true);

    QCheckBox* pchkTristate = new QCheckBox("&Tristate Check Box");
    pchkTristate->setTristate(true);
    pchkTristate->setCheckState(Qt::PartiallyChecked);

    //Layout setup=================================================
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pchkNormal);
    pvbxLayout->addWidget(pchkTristate);
    pvbxLayout->addWidget(pradRed);
    pvbxLayout->addWidget(pradGreen);
    pvbxLayout->addWidget(pradBlue);

    wgt.setLayout(pvbxLayout);

    wgt.show();

    return a.exec();
}

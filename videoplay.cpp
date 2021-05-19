#include "videoplay.h"

videoplay::videoplay(QWidget *parent)
    : QWidget(parent)
{
    //ui.setupUi(this);
    this->resize(1000, 300);

    leftwd = new leftwid;
    topwd = new topwid;
    mainwd = new mainwid;

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->setSpacing(0);
    vlayout->addWidget(topwd);
    vlayout->addWidget(mainwd);

    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->setSpacing(0);
    hlayout->addWidget(leftwd);
    hlayout->addLayout(vlayout);

    this->setLayout(hlayout);
}

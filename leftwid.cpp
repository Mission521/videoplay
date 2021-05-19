#include "leftwid.h"

leftwid::leftwid(QWidget *parent)
	: QWidget(parent)
{
    btn_movie = new QPushButton("��Ӱ");
    btn_tv = new QPushButton("���Ӿ�");
    btn_variety = new QPushButton("����");
    btn_documentary = new QPushButton("��¼Ƭ");
    btn_children = new QPushButton("����");

    btn_movie->resize(100, 50);
    btn_tv->resize(100, 50);
    btn_variety->resize(100, 50);
    btn_documentary->resize(100, 50);
    btn_children->resize(100, 50);

    leftlayout = new QVBoxLayout;
    leftlayout->addWidget(btn_movie);
    leftlayout->addWidget(btn_tv);
    leftlayout->addWidget(btn_variety);
    leftlayout->addWidget(btn_documentary);
    leftlayout->addWidget(btn_children);

    this->setLayout(leftlayout);
}

leftwid::~leftwid()
{
}

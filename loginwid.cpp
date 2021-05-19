#include "loginwid.h"
#include <qlayout.h>
#include<qdebug.h>
#include"videoplay.h"
#include<qmessagebox.h>

loginwid::loginwid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
    this->setWindowTitle("登录");

    user = new QLabel;
    passwd = new QLabel;
    useredit = new QLineEdit;
    passwdedit = new QLineEdit;
    ok = new QPushButton;
    sign = new QPushButton;

    ok->setText("登录");
    sign->setText("取消");
    user->setText("用户名");
    passwd->setText("密码");
    passwdedit->setEchoMode(QLineEdit::Password);

    QGridLayout* glayout = new QGridLayout;
    glayout->addWidget(user, 0, 0);
    glayout->addWidget(useredit, 0, 1);
    glayout->addWidget(passwd, 1, 0);
    glayout->addWidget(passwdedit, 1, 1);

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(ok);
    hbox->addWidget(sign);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addLayout(glayout);
    vbox->addLayout(hbox);

    this->setLayout(vbox);

    connect(ok, SIGNAL(clicked()), this, SLOT(okslots()));
    connect(sign, SIGNAL(clicked()), this, SLOT(close()));
}

void loginwid::okslots()
{
    if (useredit->text() == "test" && passwdedit->text() == "123")
    {
        qDebug() << "登陆成功";
        videoplay* viplay = new videoplay;
        viplay->show();
        this->close();
    }
    else if (useredit->text() == "" || passwdedit->text() == "")
        QMessageBox::information(NULL, "ERROR", "用户名或密码不能为空！");
}

loginwid::~loginwid()
{
}

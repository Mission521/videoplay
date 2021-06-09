#include "regiswid.h"
#include <qlayout.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qdebug.h>

regiswid::regiswid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);

	this->setWindowTitle("注册");
	this->resize(500, 300);

	user_l = new QLabel;
	pwd_l = new QLabel;
	rpwd_l = new QLabel;
	le_user = new QLineEdit;
	le_pwd = new QLineEdit;
	le_rpwd = new QLineEdit;
	go = new QPushButton;
	re = new QPushButton;

	user_l->setText("用户名");
	pwd_l->setText("密码");
	rpwd_l->setText("确认密码");
	le_user->setPlaceholderText("请输入用户名");
	le_pwd->setPlaceholderText("请输入密码");
	le_rpwd->setPlaceholderText("请再次输入密码");
	go->setText("注册");
	re->setText("返回登录");

	QGridLayout* glayout = new QGridLayout;
	glayout->addWidget(user_l, 0, 0);
	glayout->addWidget(le_user, 0, 1);
	glayout->addWidget(pwd_l, 1, 0);
	glayout->addWidget(le_pwd, 1, 1);
	glayout->addWidget(rpwd_l, 2, 0);
	glayout->addWidget(le_rpwd, 2, 1);

	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->addWidget(go);
	hbox->addWidget(re);

	QVBoxLayout* vbox = new QVBoxLayout;
	vbox->addLayout(glayout);
	vbox->addLayout(hbox);

	this->setLayout(vbox);

//	logwd = new loginwid;

	connect(go, SIGNAL(clicked()), this, SLOT(okregist()));
	connect(re, SIGNAL(clicked()), this, SLOT(gotologin()));


}

void regiswid::okregist()
{
	QString uname = le_user->text();
	QString upwd = le_pwd->text();
	QString urpwd = le_rpwd->text();

	if (uname == NULL || upwd == NULL || urpwd == NULL)
		QMessageBox::information(NULL,"ERROR","用户名或密码不能为空!");
	else if(upwd != urpwd)
		QMessageBox::information(NULL, "ERROR", "两次密码输入不一致!");
	else
	{
		loginwid* logwd = new loginwid;
		logwd->Adduser(uname, upwd);
		qDebug() << "注册成功 用户名：" << uname << "密码：" << upwd;
	}

}

void regiswid::gotologin()
{
	loginwid* logwd = new loginwid;
	logwd->show();
	this->close();
}

regiswid::~regiswid()
{
}


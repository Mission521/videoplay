#include "regiswid.h"
#include <qlayout.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qdebug.h>

regiswid::regiswid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);

	this->setWindowTitle("ע��");
	this->resize(500, 300);

	user_l = new QLabel;
	pwd_l = new QLabel;
	rpwd_l = new QLabel;
	le_user = new QLineEdit;
	le_pwd = new QLineEdit;
	le_rpwd = new QLineEdit;
	go = new QPushButton;
	re = new QPushButton;

	user_l->setText("�û���");
	pwd_l->setText("����");
	rpwd_l->setText("ȷ������");
	le_user->setPlaceholderText("�������û���");
	le_pwd->setPlaceholderText("����������");
	le_rpwd->setPlaceholderText("���ٴ���������");
	go->setText("ע��");
	re->setText("���ص�¼");

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
		QMessageBox::information(NULL,"ERROR","�û��������벻��Ϊ��!");
	else if(upwd != urpwd)
		QMessageBox::information(NULL, "ERROR", "�����������벻һ��!");
	else
	{
		loginwid* logwd = new loginwid;
		logwd->Adduser(uname, upwd);
		qDebug() << "ע��ɹ� �û�����" << uname << "���룺" << upwd;
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


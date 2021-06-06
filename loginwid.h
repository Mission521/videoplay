#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QWidget>
#include "ui_loginwid.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <qlist.h>
#include "user.h"
#include "regiswid.h"

//QList<user*> lguser;

class loginwid : public QWidget
{
	Q_OBJECT

public:
	loginwid(QWidget *parent = Q_NULLPTR);
	~loginwid();

	QLabel* luser;
	QLabel* passwd;
	QLineEdit* useredit;
	QLineEdit* passwdedit;
	QPushButton* ok;
	QPushButton* sign;

//	QList<user *> lguser;

	void Adduser(const QString &uname,const QString &upwd);

public slots:
	void okslots();
	void goregis();

private:
	Ui::loginwid ui;
};

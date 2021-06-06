#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include "loginwid.h"
#include <QWidget>
#include "ui_regiswid.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <qlist.h>
#include "user.h"


class regiswid : public QWidget
{
	Q_OBJECT

public:
	regiswid(QWidget *parent = Q_NULLPTR);
	~regiswid();

	QLabel* user_l;
	QLabel* pwd_l;
	QLabel* rpwd_l;
	QLineEdit* le_user;
	QLineEdit* le_pwd;
	QLineEdit* le_rpwd;
	QPushButton* go;
	QPushButton* re;

//	loginwid* logwd = new loginwid;

public slots:
	void okregist();
	void gotologin();

private:
	Ui::regiswid ui;
};

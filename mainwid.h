#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QWidget>
#include "ui_mainwid.h"
#include <qlistwidget.h>

class mainwid : public QWidget
{
	Q_OBJECT

public:
	mainwid(QWidget *parent = Q_NULLPTR);
	~mainwid();

	QListWidget* listwd;

private:
	Ui::mainwid ui;
};

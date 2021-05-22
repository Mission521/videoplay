#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QWidget>
#include "ui_mainwid.h"
#include <qlistwidget.h>
#include "playwid.h"

class mainwid : public QWidget
{
	Q_OBJECT

public:
	mainwid(QWidget *parent = Q_NULLPTR);
	~mainwid();

	QListWidget* listwd;

	playwid* playwd = new playwid;

public slots:
	void ItemSlot(QListWidgetItem* item);

private:
	Ui::mainwid ui;
};

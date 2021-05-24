#pragma once

#include <QWidget>
#include "ui_regiswid.h"

class regiswid : public QWidget
{
	Q_OBJECT

public:
	regiswid(QWidget *parent = Q_NULLPTR);
	~regiswid();

private:
	Ui::regiswid ui;
};

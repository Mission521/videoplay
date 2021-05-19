#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QWidget>
#include "ui_leftwid.h"
#include <QVBoxLayout>
#include <QPushButton>


class leftwid : public QWidget
{
	Q_OBJECT

public:
	leftwid(QWidget *parent = Q_NULLPTR);
	~leftwid();

	QVBoxLayout* leftlayout;

	QPushButton* btn_variety; //����
	QPushButton* btn_tv; //���Ӿ�
	QPushButton* btn_movie; //��Ӱ
	QPushButton* btn_documentary; //��¼Ƭ
	QPushButton* btn_children; //����

private:
	Ui::leftwid ui;
};

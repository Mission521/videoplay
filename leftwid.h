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

	QPushButton* btn_variety; //综艺
	QPushButton* btn_tv; //电视剧
	QPushButton* btn_movie; //电影
	QPushButton* btn_documentary; //纪录片
	QPushButton* btn_children; //动画

private:
	Ui::leftwid ui;
};

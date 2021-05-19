#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QWidget>
#include "ui_topwid.h"
#include <qlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>

class topwid : public QWidget
{
	Q_OBJECT

public:
	topwid(QWidget *parent = Q_NULLPTR);
	~topwid();

    QHBoxLayout* toplayout;

    QLineEdit* ledit_search; //搜索输入框
    QPushButton* btn_search; //搜索按钮
    QPushButton* btn_login; //登录
    QPushButton* btn_history; //历史
    QPushButton* btn_download; //下载
    QPushButton* btn_message; //个人信息

public slots:
    void loginslots();

private:
	Ui::topwid ui;
};

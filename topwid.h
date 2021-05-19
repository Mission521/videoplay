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

    QLineEdit* ledit_search; //���������
    QPushButton* btn_search; //������ť
    QPushButton* btn_login; //��¼
    QPushButton* btn_history; //��ʷ
    QPushButton* btn_download; //����
    QPushButton* btn_message; //������Ϣ

public slots:
    void loginslots();

private:
	Ui::topwid ui;
};

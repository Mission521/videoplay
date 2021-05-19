#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QtWidgets/QWidget>
#include "ui_videoplay.h"
#include"topwid.h"
#include"leftwid.h"
#include"mainwid.h"
#include"loginwid.h"

class videoplay : public QWidget
{
    Q_OBJECT

public:
    videoplay(QWidget *parent = Q_NULLPTR);

    leftwid *leftwd;
    topwid *topwd;
    mainwid *mainwd;

private:
    Ui::videoplayClass ui;
};

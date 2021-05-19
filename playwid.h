#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include <QWidget>
#include "ui_playwid.h"
#include <qmediaplayer.h>
#include <qvideowidget.h>
#include <qslider.h>
#include <qpushbutton.h>
#include <qurl.h>
#include <qstring.h>

class playwid : public QWidget
{
	Q_OBJECT

public:
	playwid(QWidget *parent = Q_NULLPTR);
	~playwid();

	QMediaPlayer* player;
	QVideoWidget* videowid;
	QSlider* slid;
	QPushButton* btn_choise;
	QPushButton* btn_play;

	void Seturl(const QUrl &url);

public slots:
	void openFile();
	void Playvideo();

private:
	Ui::playwid ui;
};

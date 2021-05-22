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
#include <qlabel.h>

class playwid : public QWidget
{
	Q_OBJECT

public:
	playwid(QWidget *parent = Q_NULLPTR);
	~playwid();

	QMediaPlayer* player;
	QVideoWidget* videowid;
	QSlider* slid;
	QPushButton* btn_stop;
	QPushButton* btn_play;
	QLabel* time;
	QLabel* totaltime;
	QLabel* placeholder;

	void Seturl(const QUrl &url);

public slots:
	void StopVideo();
	void Playvideo();
	void positionChangedSlot(qint64 i);
	void durationChangedSlot(qint64 i);
	void sliderMovedSlot(int i);

private:
	Ui::playwid ui;
};

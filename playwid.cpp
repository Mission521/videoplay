#include "playwid.h"
#include <qlayout.h>
#include <qfiledialog.h>

playwid::playwid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);

	this->resize(500, 300);
	player = new QMediaPlayer(this);

	videowid = new QVideoWidget(this);
	player->setVideoOutput(videowid);

	btn_stop = new QPushButton;
	btn_play = new QPushButton;
	slid = new QSlider(Qt::Horizontal);

	time = new QLabel;
	totaltime = new QLabel;
	placeholder = new QLabel;

	placeholder->setFixedWidth(5);
	placeholder->setText("/");
	time->setFixedWidth(48);
	totaltime->setFixedWidth(48);


	btn_stop->setText("Í£Ö¹");
	btn_play->setText("²¥·Å");

	QHBoxLayout* l_hlayout = new QHBoxLayout;
	l_hlayout->addWidget(time);
	l_hlayout->addWidget(placeholder);
	l_hlayout->addWidget(totaltime);

	QHBoxLayout* hlayout = new QHBoxLayout;
	hlayout->addWidget(btn_play);
	hlayout->addWidget(btn_stop);
	hlayout->addLayout(l_hlayout);

	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->addWidget(videowid);
	vlayout->addWidget(slid);
	vlayout->addLayout(hlayout);

	this->setLayout(vlayout);

	connect(btn_stop, SIGNAL(clicked(bool)), this, SLOT(StopVideo()));
	connect(btn_play, SIGNAL(clicked(bool)), this, SLOT(Playvideo()));
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChangedSlot(qint64)));
	connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChangedSlot(qint64)));
	connect(slid,SIGNAL(sliderMoved(int)),this,SLOT(sliderMovedSlot(int)));

	//videowid->show();
}

void playwid::Seturl(const QUrl &url)
{
	player->setMedia(url);
}

QString SetTime(qint64 i)
{
	int h, d, s;
	i /= 1000;
	h = i / 3600;
	d = (i - h * 3600) / 60;
	s = i - h * 3600 - d * 60;
	QString times = QString("%1:%2:%3").arg(h,2,10,QChar('0')).arg(d, 2, 10, QChar('0')).arg(s, 2, 10, QChar('0'));
	return times;

}

void playwid::StopVideo()
{
	player->stop();
	slid->setValue(0);
}

void playwid::Playvideo()
{
	switch (player->state())
	{
	case QMediaPlayer::PlayingState:
		player->pause();
		break;
	default:
		player->play();
		break;
	}
}

void playwid::positionChangedSlot(qint64 i)
{
	slid->setValue(i);
	time->setText(SetTime(i));
}

void playwid::durationChangedSlot(qint64 i)
{
	slid->setRange(0,i);
	totaltime->setText(SetTime(i));
}

void playwid::sliderMovedSlot(int i)
{
	player->setPosition(i);
}

playwid::~playwid()
{
}

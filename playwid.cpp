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

	btn_choise = new QPushButton;
	btn_play = new QPushButton;
	slid = new QSlider(Qt::Horizontal);

	btn_choise->setText("选择");
	btn_play->setText("播放");
	
	QHBoxLayout* hlayout = new QHBoxLayout;
	hlayout->addWidget(btn_choise);
	hlayout->addWidget(btn_play);

	QVBoxLayout* vlayout = new QVBoxLayout;
	vlayout->addWidget(videowid);
	vlayout->addWidget(slid);
	vlayout->addLayout(hlayout);

	this->setLayout(vlayout);

	connect(btn_choise, SIGNAL(clicked(bool)), this, SLOT(openFile()));
	connect(btn_play, SIGNAL(clicked(bool)), this, SLOT(Playvideo()));

	videowid->show();
}

void playwid::Seturl(const QUrl &url)
{
	player->setMedia(url);
}

void playwid::openFile()
{
	QString files = QFileDialog::getOpenFileName(this, tr("Open Video"), "./", tr("Video Files(*.mp4 *.mov)"));
	qDebug() << files;
	Seturl(files);
}

void playwid::Playvideo()
{
	qDebug() << "开始播放";
	player->play();
}

playwid::~playwid()
{
}

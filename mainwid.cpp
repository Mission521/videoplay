#include "mainwid.h"
#include"qdir.h"
#include<qscrollbar.h>
#include<qdebug.h>

const int W_ICON = 100;
const int H_ICON = 100;
const int H_ITEM = 140;

mainwid::mainwid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
    listwd = new QListWidget(this);
    listwd->resize(810, 200);
    listwd->setIconSize(QSize(W_ICON, H_ICON));
    listwd->setResizeMode(QListView::Adjust);
    listwd->setViewMode(QListView::IconMode);
    listwd->setMovement(QListView::Static);
    listwd->setSpacing(10);
    listwd->horizontalScrollBar()->setDisabled(true);

    QString path = QString(QDir::currentPath() + "/" + "image");
    qDebug() << "路径" << path;
    QDir dir(path);
    QStringList files = dir.entryList(QDir::Files | QDir::Readable, QDir::Name);
    qDebug() << "资源" << files;
    

    for (int i = 0; i < files.count(); i++)
    {
        QString file = QString("image/%1").arg(files.at(i));
        QStringList name = files.at(i).split(".");
        QString fname = name[0];
        QPixmap pic(file);
        QListWidgetItem* item = new QListWidgetItem(QIcon(pic.scaled(QSize(W_ICON, H_ICON))), fname);
        item->setSizeHint(QSize(W_ICON, H_ITEM));
        listwd->insertItem(i, item);
    }

    listwd->show();

    connect(listwd, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ItemSlot(QListWidgetItem*)));
}

void mainwid::ItemSlot(QListWidgetItem* item)
{
    QString text = item->text();
    QStringList list = text.split(".");
    QString names = list[0];
    QString filename = QString(QDir::currentPath() + "/" + "image/vid/%1.mp4").arg(names);
    playwd->Seturl(filename);
    qDebug() << "sp" << filename;
    playwd->player->play();
    playwd->show();
}

mainwid::~mainwid()
{
}

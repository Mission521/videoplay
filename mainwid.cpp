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
    qDebug() << "Â·¾¶£º" << path;
    QDir dir(path);
    QStringList files = dir.entryList(QDir::Files | QDir::Readable, QDir::Name);
    qDebug() << "ËØ²Ä£º" << files;

    for (int i = 0; i < files.count(); i++)
    {
        QString file = QString("image/%1").arg(files.at(i));
        //QString name = path.mid(6);
        QPixmap pic(file);
        QListWidgetItem* item = new QListWidgetItem(QIcon(pic.scaled(QSize(W_ICON, H_ICON))), files.at(i));
        item->setSizeHint(QSize(W_ICON, H_ITEM));
        listwd->insertItem(i, item);
    }

    listwd->show();
}

mainwid::~mainwid()
{
}

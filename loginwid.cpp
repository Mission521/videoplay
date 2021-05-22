#include "loginwid.h"
#include <qlayout.h>
#include <qdebug.h>
#include "videoplay.h"
#include <qmessagebox.h>
#include <qstring.h>
#include "playwid.h"

loginwid::loginwid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
    this->setWindowTitle("��¼");

    luser = new QLabel;
    passwd = new QLabel;
    useredit = new QLineEdit;
    passwdedit = new QLineEdit;
    ok = new QPushButton;
    sign = new QPushButton;

    ok->setText("��¼");
    sign->setText("�˳�");
    luser->setText("�û���");
    passwd->setText("����");
    passwdedit->setEchoMode(QLineEdit::Password);

    QGridLayout* glayout = new QGridLayout;
    glayout->addWidget(luser, 0, 0);
    glayout->addWidget(useredit, 0, 1);
    glayout->addWidget(passwd, 1, 0);
    glayout->addWidget(passwdedit, 1, 1);

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(ok);
    hbox->addWidget(sign);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addLayout(glayout);
    vbox->addLayout(hbox);

    this->setLayout(vbox);

    myuser.append(new user("admin","123"));
    myuser.append(new user("test","321"));
    qDebug() << myuser.at(1)->username << myuser.at(1)->userpwd;

    connect(ok, SIGNAL(clicked()), this, SLOT(okslots()));
    connect(sign, SIGNAL(clicked()), this, SLOT(close()));
}

void loginwid::okslots()
{
    QString uname = useredit->text();
    QString upwd = passwdedit->text();
    for (int i = 0; i < myuser.count(); i++)
    {
        qDebug() << myuser.at(i)->username << myuser.at(i)->userpwd;
        if (uname == NULL || upwd == NULL)
        {
            QMessageBox::information(NULL, "ERROR", "�û��������벻��Ϊ�գ�");
            break;
        }
        else if (strcmp(uname.toLatin1(), myuser.at(i)->username.toLatin1()) == 0 && strcmp(upwd.toLatin1(),myuser.at(i)->userpwd.toLatin1()) == 0)
        {
            qDebug() << "��½�ɹ�";
            videoplay* viplay = new videoplay;
            viplay->show();
            this->close();
            break;
        }
        else if (strcmp(uname.toLatin1(), myuser.at(i)->username.toLatin1()) != 0 || strcmp(upwd.toLatin1(), myuser.at(i)->userpwd.toLatin1()) != 0)
        {
            QMessageBox::information(NULL, "ERROR", "�û������������");
            continue;
        }
        
    }
}

loginwid::~loginwid()
{
}

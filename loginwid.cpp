#include "loginwid.h"
#include <qlayout.h>
#include <qdebug.h>
#include "videoplay.h"
#include <qmessagebox.h>
#include <qstring.h>
#include "playwid.h"


QList<user*> lguser;

loginwid::loginwid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
    this->setWindowTitle("��¼");

    QString bgColor = "#FFFFFF";    //������ɫ
    QString borderColor = "#A6B5B8";//�߿���ɫ

    luser = new QLabel;
    passwd = new QLabel;
    b_ico = new QPushButton;

    useredit = new QLineEdit;
    passwdedit = new QLineEdit;
    ok = new QPushButton;
    sign = new QPushButton;

    ok->setText("��¼");
    sign->setText("ע��");
    luser->setText("�û���");
    passwd->setText("����");
    useredit->setPlaceholderText("�������û���");
    passwdedit->setPlaceholderText("����������");
    passwdedit->setEchoMode(QLineEdit::Password);
    passwdedit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    b_ico->resize(20, 20);
    b_ico->setStyleSheet(QString("border:0px;background-color:%1").arg(bgColor));
    b_ico->setFlat(true);
    b_ico->setIcon(QPixmap("image/ico/eye_close"));

    QFrame* frame = new QFrame;
    frame->setObjectName("framePassword");

    QStringList qss;
    qss.append(QString("QFrame#framePassword{border:1px solid %1;background-color:%2;}").arg(borderColor).arg(bgColor));
    qss.append(QString("QPushButton{min-width:15px;background-color:%1;}").arg(bgColor));
    qss.append(QString("QLineEdit{background-color:%1;border:none;}").arg(bgColor));
    frame->setStyleSheet(qss.join(""));

    QHBoxLayout* l_ico = new QHBoxLayout(frame);
    l_ico->setMargin(0);
    l_ico->setSpacing(0);
    l_ico->addWidget(passwdedit);
    l_ico->addWidget(b_ico);

    QGridLayout* glayout = new QGridLayout;
    glayout->addWidget(luser, 0, 0);
    glayout->addWidget(useredit, 0, 1);
    glayout->addWidget(passwd, 1, 0);
    glayout->addWidget(frame,1,1);

    QHBoxLayout* hbox = new QHBoxLayout;
    hbox->addWidget(ok);
    hbox->addWidget(sign);

    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addLayout(glayout);
    vbox->addLayout(hbox);

    this->setLayout(vbox);

    lguser.append(new user("admin","123"));
    lguser.append(new user("test","321"));
    for (int i = 0 ; i < lguser.count() ; i++)
        qDebug() << lguser.at(i)->username << lguser.at(i)->userpwd;

    connect(ok, SIGNAL(clicked()), this, SLOT(okslots()));
    connect(sign, SIGNAL(clicked()), this, SLOT(goregis()));
    connect(b_ico, SIGNAL(clicked()), this, SLOT(changeshow()));
}

void loginwid::okslots()
{
    QString uname = useredit->text();
    QString upwd = passwdedit->text();

    int flag;
    for (int i = 0; i < lguser.count(); i++)
    {
       /* qDebug() << myuser.at(i)->username << myuser.at(i)->userpwd;
        if (uname == NULL || upwd == NULL)
        {
            QMessageBox::information(NULL, "ERROR", "�û��������벻��Ϊ�գ�");
            break;
        }
        else if (strcmp(uname.toLatin1(), myuser.at(i)->username.toLatin1()) != 0 || strcmp(upwd.toLatin1(), myuser.at(i)->userpwd.toLatin1()) != 0)
        {
            QMessageBox::information(NULL, "ERROR", "�û������������");
            continue;
        }
        else if (strcmp(uname.toLatin1(), myuser.at(i)->username.toLatin1()) == 0 && strcmp(upwd.toLatin1(),myuser.at(i)->userpwd.toLatin1()) == 0)
        {
            qDebug() << "��½�ɹ�";
            videoplay* viplay = new videoplay;
            viplay->show();
            this->close();
            break;
        }*/

        if (uname == NULL || upwd == NULL) {
            flag = 1;
            break;
        } else if(uname != lguser.at(i)->username || upwd != lguser.at(i)->userpwd) {
            flag = 2;
        } else if (uname == lguser.at(i)->username && upwd == lguser.at(i)->userpwd) {
            flag = 3;
            break;
        }
       
    }
    switch (flag)
    {
    case 1:QMessageBox::information(NULL, "ERROR", "�û��������벻��Ϊ�գ�"); break;
    case 2:QMessageBox::information(NULL, "ERROR", "�û������������"); break;
    default: 
        
        qDebug() << "��½�ɹ�";
        videoplay* viplay = new videoplay;
        viplay->show();
        this->close();
        break; 

    }
}

void loginwid::goregis()
{
    regiswid* regwd = new regiswid;
    regwd->show();
    this->close();
}

int tag = 0;
void loginwid::changeshow()
{
    if (tag == 0)
    {
        tag = 1;
        passwdedit->setEchoMode(QLineEdit::Normal);
        b_ico->setIcon(QPixmap("image/ico/eye_open"));
    }
    else if (tag == 1)
    {
        tag = 0;
        passwdedit->setEchoMode(QLineEdit::Password);
        b_ico->setIcon(QPixmap("image/ico/eye_close"));
    }
}

void loginwid::Adduser(const QString &uname,const QString &upwd)
{
    lguser.append(new user(uname, upwd));
}

loginwid::~loginwid()
{
}

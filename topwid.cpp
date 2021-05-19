#include "topwid.h"
#include "loginwid.h"

topwid::topwid(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);

    ledit_search = new QLineEdit; //搜索输入框
    btn_search = new QPushButton("搜索"); //搜索按钮
    btn_login = new QPushButton("登录"); //登录
    btn_history = new QPushButton("历史"); //历史
    btn_download = new QPushButton("下载"); //下载
    btn_message = new QPushButton("个人信息");

    btn_search->resize(100, 50);
    btn_history->resize(100, 50);
    btn_download->resize(100, 50);
    btn_login->resize(100, 50);
    btn_message->resize(100, 50);

    toplayout = new QHBoxLayout;
    toplayout->addWidget(ledit_search);
    toplayout->addWidget(btn_search);
    toplayout->addWidget(btn_history);
    toplayout->addWidget(btn_download);
    toplayout->addWidget(btn_login);
    toplayout->addWidget(btn_message);

    this->setLayout(toplayout);

    connect(btn_login, SIGNAL(clicked(bool)), this, SLOT(loginslots()));
}

void topwid::loginslots()
{
    loginwid* logwd = new loginwid;
    logwd->show();
}

topwid::~topwid()
{
}

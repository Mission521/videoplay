#pragma once

#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif 

#include<qstring.h>

class user
{
public:
	user(QString username,QString userpwd);

	QString username;
	QString userpwd;
};


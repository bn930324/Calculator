/*
 * Copyright (C) 2011 @HIT Footoo Lab
 * Author:shiyanhui
 * Create Date: 2011-3-20
 */
#include <QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}

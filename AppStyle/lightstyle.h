/**************************************************
**
**
** 亮色系皮肤文件
**
** LICENSE:LGPL
**************************************************/
#ifndef LIGHTSTYLE_H
#define LIGHTSTYLE_H

#include <QApplication>

class LightStyle{

public:
    LightStyle();
    static void polish();

private:
    static void setPalette();
    static void setQss();

};

#endif // LIGHTSTYLE_H

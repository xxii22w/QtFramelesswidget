/**************************************************
**
**
** 暗色系皮肤文件，包含 polish() 接口
** 配套有darkstyle.qss样式表以及资源图片
**
** LICENSE:LGPL
**************************************************/
#ifndef DARKSTYLE_HPP
#define DARKSTYLE_HPP

#include <QApplication>

class DarkStyle{

public:
    DarkStyle();
    static void polish();

private:
    static void setPalette();
    static void setQss();

};

#endif  // DARKSTYLE_HPP

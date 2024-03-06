/**************************************************
**
**
** StyleManager 样式管理，只需在需要的地方调用该文件的
** StyleUpdate()静态函数接口来设置当前应用程序的样式，
** 来达到换肤的功能
**
** LICENSE:LGPL
**************************************************/
#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QObject>
#include "DarkStyle.h"
#include "lightstyle.h"

enum class StyleTypes{
    NONE = 0,
    DARK = 1,
    LIGHT,
    UBUNTU,
    MACOS
};

class StyleManager: public QObject
{
    Q_OBJECT
public:
    StyleManager();
    static bool StyleUpdate(StyleTypes flag);


private:
    StyleTypes styletype;
};

#endif // STYLEMANAGER_H

/**************************************************
**
**
** 程序入口。
** 终于借这个机会将这个具备无边框+换肤功能的窗口框架完成了，
** 以后做任何软件都可以直接套用这个框架，通过简单的修修改改
** 便可以实现很漂亮的界面设计了。
**
**
** LICENSE:LGPL
**************************************************/
#include "mainwindow.h"
#include <QApplication>
#include "framelesswindow.h"
#include "AppStyle/stylemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   

    //通过样式管理器的接口来设置初始样式为暗色系皮肤
    StyleManager::StyleUpdate(StyleTypes::DARK);

    //创建无边框界面窗口并通过setContent()接口将主窗口嵌入
    FramelessWindow framelessWindow;
    MainWindow *mainWindow = new MainWindow;
    framelessWindow.setContent(mainWindow);
    framelessWindow.show();

    return a.exec();
}

//qDebug()<<"[FUNCTION]:"<<__FUNCTION__<<"[LINE]:"<<__LINE__<<"[LOG]:"
//       <<QString::fromLocal8Bit("切换为orange_loop");

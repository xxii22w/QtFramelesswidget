/**************************************************
**
**
** titlebar文件 负责自定义标题栏，标题栏的UI布局和样式可以完全自定义
** 除自定义的内容外，titlebar类还包含了窗口标题栏的常见功能，如双击标题栏
** 窗体全屏、拖动标题栏可拖动窗体、全屏状态下拖动标题栏可恢复正常尺寸等。
** titlebar还包含了设置标题栏的标志、标题等接口。
**
** LICENSE:LGPL
**************************************************/
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QMouseEvent>
#include <QWidget>
#include <QVariant>
#include <QAction>
#include <QIcon>
#include <QApplication>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QToolButton>


class TitleBar : public QWidget
{
    Q_OBJECT

//公共函数均可重写、自定义
public:
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();
    void InitDesigner();

protected:
    virtual void changeEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

protected:
 QPoint mousePos;
 QPoint wndPos;
 bool mousePressed;
 int last_width;

//UI界面控件的信号槽函数，可自定义重新设计
private slots:
     void on_minimizeButton_clicked();

     void on_restoreButton_clicked();

     void on_maximizeButton_clicked();

     void on_closeButton_clicked();

     void on_darkstyle_action_triggered();

     void on_lightstyle_action_triggered();

     void on_ubuntustyle_action_triggered();

     void on_macosstyle_action_triggered();

     void on_noteButton_clicked();

private:

    QWidget *parent_MainWindow;

    QAction* darkstyle_action;
    QAction* lightstyle_action;
    QAction* ubuntustyle_action;
    QAction* macosstyle_action;
    QHBoxLayout* horizontalLayout_3;
    QGridLayout* gridLayout;
    QHBoxLayout* horizontalLayout;
    QToolButton* skinButton;
    QToolButton* minimizeButton;
    QToolButton* restoreButton;
    QToolButton* maximizeButton;
    QToolButton* closeButton;
    QSpacerItem* horizontalSpacer;
};

#endif // TITLEBAR_H

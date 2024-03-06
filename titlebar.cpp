/**************************************************
**
** Copyright (C) 2022 zhouxuan.
** Contact: 微信公众号【周旋机器视觉】
**
** titlebar自定义标题栏类，通过重写鼠标响应事件，实现以下功能：
** 1、拖动自定义标题栏可拖动窗口界面
** 2、双击标题栏窗口全屏放大， 再次双击窗口恢复正常大小
** 3、应用窗口全屏状态下，拖动标题栏可使窗口恢复正常大小并跟随拖动
** 标题栏界面布局可自定义，但应保留最基本的四个按钮实现最小化、最大化、关闭等
** 基本功能。
** 其它功能可通过添加控件和槽函数来自行设计填充
**
** LICENSE:LGPL
**************************************************/
#include "titlebar.h"
#include <QPainter>
#include <QStyleOption>
#include <QMenu>
#include <qfile.h>
#include <QDebug>
#include <QMessageBox>
#include "AppStyle/stylemanager.h"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    parent_MainWindow(parent)
{
    mousePressed = false;
    last_width = 1000;
    InitDesigner();
    restoreButton->setVisible(false);
}

TitleBar::~TitleBar()
{

}

void TitleBar::InitDesigner() {

    if (this->objectName().isEmpty())
        this->setObjectName("titlebar");
    this->resize(734, 65);
    QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(0, 0));
    this->setStyleSheet(QString::fromUtf8(""));
    darkstyle_action = new QAction(this);
    darkstyle_action->setObjectName("darkstyle_action");
    darkstyle_action->setCheckable(false);
    lightstyle_action = new QAction(this);
    lightstyle_action->setObjectName("lightstyle_action");
    ubuntustyle_action = new QAction(this);
    ubuntustyle_action->setObjectName("ubuntustyle_action");
    macosstyle_action = new QAction(this);
    macosstyle_action->setObjectName("macosstyle_action");
    horizontalLayout_3 = new QHBoxLayout(this);
    horizontalLayout_3->setObjectName("horizontalLayout_3");
    gridLayout = new QGridLayout();
    gridLayout->setObjectName("gridLayout");
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName("horizontalLayout");
    skinButton = new QToolButton(this);
    skinButton->setObjectName("skinButton");
    skinButton->setEnabled(true);
    skinButton->setStyleSheet(QString::fromUtf8("#skinButton{\n"
        "  background-color:none;\n"
        "  border:none;\n"
        "  width:30px;\n"
        "  height:30px;\n"
        "  padding:4px;\n"
        "  image:url(:/frameless_images/skin_button.png);\n"
        "}\n"
        "#skinButton:hover{\n"
        "  background-color:palette(alternate-base);\n"
        "}\n"
        "#skinButton:pressed{\n"
        "  background-color:palette(highlight);\n"
        "}"));
    skinButton->setPopupMode(QToolButton::InstantPopup);
    skinButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
    skinButton->setAutoRaise(false);

    horizontalLayout->addWidget(skinButton);

    minimizeButton = new QToolButton(this);
    minimizeButton->setObjectName("minimizeButton");
    minimizeButton->setStyleSheet(QString::fromUtf8("#minimizeButton{\n"
        "  background-color:none;\n"
        "  border:none;\n"
        "  width:16px;\n"
        "  height:16px;\n"
        "  padding:4px;\n"
        "  image:url(:/frameless_images/icon_window_minimize.png);\n"
        "}\n"
        "#minimizeButton:hover{\n"
        "  background-color:palette(alternate-base);\n"
        "}\n"
        "#minimizeButton:pressed{\n"
        "  background-color:palette(highlight);\n"
        "}"));
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/icon_window_minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
    minimizeButton->setIcon(icon);
    minimizeButton->setPopupMode(QToolButton::DelayedPopup);
    minimizeButton->setArrowType(Qt::NoArrow);

    horizontalLayout->addWidget(minimizeButton);

    restoreButton = new QToolButton(this);
    restoreButton->setObjectName("restoreButton");
    restoreButton->setStyleSheet(QString::fromUtf8("#restoreButton{\n"
        "  background-color:none;\n"
        "  border:none;\n"
        "  width:16px;\n"
        "  height:16px;\n"
        "  padding:4px;\n"
        "  image:url(:/frameless_images/icon_window_restore.png);\n"
        "}\n"
        "#restoreButton:hover{\n"
        "  background-color:palette(alternate-base);\n"
        "}\n"
        "#restoreButton:pressed{\n"
        "  background-color:palette(highlight);\n"
        "}"));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/icon_window_restore.png"), QSize(), QIcon::Normal, QIcon::Off);
    restoreButton->setIcon(icon1);

    horizontalLayout->addWidget(restoreButton);

    maximizeButton = new QToolButton(this);
    maximizeButton->setObjectName("maximizeButton");
    maximizeButton->setStyleSheet(QString::fromUtf8("#maximizeButton{\n"
        "  background-color:none;\n"
        "  border:none;\n"
        "  width:16px;\n"
        "  height:16px;\n"
        "  padding:4px;\n"
        "  image:url(:/frameless_images/icon_window_maximize.png);\n"
        "}\n"
        "#maximizeButton:hover{\n"
        "  background-color:palette(alternate-base);\n"
        "}\n"
        "##maximizeButton:pressed{\n"
        "  background-color:palette(highlight);\n"
        "}"));
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/images/icon_window_maximize.png"), QSize(), QIcon::Normal, QIcon::Off);
    maximizeButton->setIcon(icon2);

    horizontalLayout->addWidget(maximizeButton);

    closeButton = new QToolButton(this);
    closeButton->setObjectName("closeButton");
    closeButton->setStyleSheet(QString::fromUtf8("#closeButton{\n"
        "  background-color:none;\n"
        "  border:none;\n"
        "  width:16px;\n"
        "  height:16px;\n"
        "  padding:4px;\n"
        "  image:url(:/frameless_images/icon_window_close.png);\n"
        "  border-top-right-radius: 5px;\n"
        "}\n"
        "#closeButton:hover{\n"
        "  background-color:palette(alternate-base);\n"
        "}\n"
        "##closeButton:pressed{\n"
        "  background-color:palette(highlight);\n"
        "}"));
    QIcon icon3;
    icon3.addFile(QString::fromUtf8(":/images/icon_window_close.png"), QSize(), QIcon::Normal, QIcon::Off);
    closeButton->setIcon(icon3);

    horizontalLayout->addWidget(closeButton);


    gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

    gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

    this->setWindowTitle(QCoreApplication::translate("titlebar", "Form", nullptr));
    darkstyle_action->setText(QCoreApplication::translate("titlebar", "darkstyle", nullptr));
    lightstyle_action->setText(QCoreApplication::translate("titlebar", "lightstyle", nullptr));
    ubuntustyle_action->setText(QCoreApplication::translate("titlebar", "ubuntustyle", nullptr));
    macosstyle_action->setText(QCoreApplication::translate("titlebar", "macosstyle", nullptr));
    skinButton->setText(QString());
    minimizeButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
    restoreButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
    maximizeButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
    closeButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));

    horizontalLayout_3->addLayout(gridLayout);

    QMetaObject::connectSlotsByName(this);

    //创建下拉菜单
    QMenu *skinButton_menu = new QMenu(this);
    skinButton_menu->addAction(darkstyle_action);
    skinButton_menu->addAction(lightstyle_action);
    skinButton_menu->addAction(ubuntustyle_action);
    skinButton_menu->addAction(macosstyle_action);

    skinButton->setPopupMode(QToolButton::InstantPopup);
    skinButton->setMenu(skinButton_menu);
}

//void TitleBar::setTitleText(const QString &text) {
//  ui->titleText_lable->setText(text);
//}

//void TitleBar::setNoteText(const QString &text) {
//  ui->noteText_lable->setText(text);
//}

//void TitleBar::setIcon(QString path) {
//    ui->icon_label->setPixmap(QPixmap(path));
//}

void TitleBar::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        last_width = parent_MainWindow->width();
    }
}


void TitleBar::mousePressEvent(QMouseEvent *event) {
  mousePressed = true;
  mousePos = event->globalPos();

  if (parent_MainWindow) wndPos = parent_MainWindow->pos();
}

void TitleBar::mouseMoveEvent(QMouseEvent *event) {
//  QWidget *parent = parentWidget();
//  if (parent) parent = parent->parentWidget();

  if (parent_MainWindow && mousePressed)
  {
      if(!parent_MainWindow->isMaximized())
      {
          //界面的全局位置 + （当前鼠标位置-鼠标按下时的位置）
          parent_MainWindow->move(wndPos + (event->globalPos() - mousePos));
      }
      else
      {
          //窗口最大化时鼠标拖动标题栏使窗体复原，且鼠标相对窗体的相对位置不变
          //相对位置不变指的是：鼠标点击拖动窗口1/4处进行拖动，复原时鼠标依然位于窗口1/4处
          //达到此效果，仅需更改窗口的位置即可
          float width_ratio = float(event->globalPos().x())/float(parent_MainWindow->width());
          on_restoreButton_clicked();
          //更新窗体的位置，将鼠标点击的窗体标题栏的相对位置定位到鼠标当前位置
          int normal_width = last_width * width_ratio;
          int normal_higth = this->height()/4;
          wndPos = event->globalPos() - QPoint(normal_width,normal_higth);
      }
  }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event) {
  Q_UNUSED(event);
  mousePressed = false;
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event) {
    Q_UNUSED(event);

    if (parent_MainWindow->windowState().testFlag(Qt::WindowNoState)) {
      on_maximizeButton_clicked();
    }
    else{
      on_restoreButton_clicked();
    }
}

void TitleBar::on_minimizeButton_clicked()
{
    parent_MainWindow->setWindowState(Qt::WindowMinimized);
}

void TitleBar::on_restoreButton_clicked()
{
    restoreButton->setVisible(false);
    maximizeButton->setVisible(true);

    parent_MainWindow->setWindowState(Qt::WindowNoState);
}

void TitleBar::on_maximizeButton_clicked()
{
    restoreButton->setVisible(true);
    maximizeButton->setVisible(false);

    parent_MainWindow->setWindowState(Qt::WindowMaximized);
    parent_MainWindow->showMaximized();
}

void TitleBar::on_closeButton_clicked()
{
    parent_MainWindow->close();
}

void TitleBar::on_darkstyle_action_triggered()
{
    // TODO(周旋机器视觉): 换肤的设计还是比较差劲，代码不够简洁美观。由于样式文件直接覆盖整个应用程序
    //因此每次换肤需要单独对独立的titlebar的相关样式进行更新，这部分代码应该集成于titlebar文件自身
    // TODO(zhouxuan): 可以通过为titlebar写一个单独的样式更新函数来提高代码的可阅读性
    StyleManager::StyleUpdate(StyleTypes::DARK);

    minimizeButton->setIcon(QIcon(QPixmap(":/frameless_images/icon_window_minimize.png")));
    restoreButton->setIcon(QIcon(QPixmap(":/frameless_images/icon_window_restore.png")));
    maximizeButton->setIcon(QIcon(QPixmap(":/frameless_images/icon_window_maximize.png")));
    closeButton->setIcon(QIcon(QPixmap(":/frameless_images/icon_window_close.png")));

}

void TitleBar::on_lightstyle_action_triggered()
{
    StyleManager::StyleUpdate(StyleTypes::LIGHT);
    minimizeButton->setIcon(QIcon(QPixmap(":/lightstyle/light_window_minimize.png")));
    restoreButton->setIcon(QIcon(QPixmap(":/lightstyle/light_window_restore.png")));
    maximizeButton->setIcon(QIcon(QPixmap(":/lightstyle/light_window_maximize.png")));
    closeButton->setIcon(QIcon(QPixmap(":/lightstyle/light_window_close.png")));
}

void TitleBar::on_ubuntustyle_action_triggered()
{
    // loadstylesheet
    QFile qfDarkstyle(":/QSS-master/Ubuntu.qss");

    if (qfDarkstyle.open(QFile::ReadOnly)) {
      // set stylesheet
      qApp->setStyleSheet(qfDarkstyle.readAll());
      qfDarkstyle.close();
    }
}

void TitleBar::on_macosstyle_action_triggered()
{
    // loadstylesheet
    QFile qfDarkstyle(":/QSS-master/MacOS.qss");

    if (qfDarkstyle.open(QFile::ReadOnly)) {
      // set stylesheet
      qApp->setStyleSheet(qfDarkstyle.readAll());
      qfDarkstyle.close();
    }
}

void TitleBar::on_noteButton_clicked()
{
    // TODO(周旋机器视觉): 可以使用同样的方式为QMessageBox消息提示窗口设计一款无边框窗口，
    // TODO(zhouxuan): 来达到与主窗口风格一致且可自定义的效果，此处仅使用QT原生QMessageBox
    QMessageBox::information(this,"imformation",QString::fromLocal8Bit("Copyright (C) 2022 zhouxuan.\
                                                                       Contact: 微信公众号【周旋机器视觉】"));
}

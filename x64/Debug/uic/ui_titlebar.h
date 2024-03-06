/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_titlebar
{
public:
    QAction *darkstyle_action;
    QAction *lightstyle_action;
    QAction *ubuntustyle_action;
    QAction *macosstyle_action;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *skinButton;
    QToolButton *minimizeButton;
    QToolButton *restoreButton;
    QToolButton *maximizeButton;
    QToolButton *closeButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *titlebar)
    {
        if (titlebar->objectName().isEmpty())
            titlebar->setObjectName("titlebar");
        titlebar->resize(734, 65);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titlebar->sizePolicy().hasHeightForWidth());
        titlebar->setSizePolicy(sizePolicy);
        titlebar->setMinimumSize(QSize(0, 0));
        titlebar->setStyleSheet(QString::fromUtf8(""));
        darkstyle_action = new QAction(titlebar);
        darkstyle_action->setObjectName("darkstyle_action");
        darkstyle_action->setCheckable(false);
        lightstyle_action = new QAction(titlebar);
        lightstyle_action->setObjectName("lightstyle_action");
        ubuntustyle_action = new QAction(titlebar);
        ubuntustyle_action->setObjectName("ubuntustyle_action");
        macosstyle_action = new QAction(titlebar);
        macosstyle_action->setObjectName("macosstyle_action");
        horizontalLayout_3 = new QHBoxLayout(titlebar);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        skinButton = new QToolButton(titlebar);
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

        minimizeButton = new QToolButton(titlebar);
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

        restoreButton = new QToolButton(titlebar);
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

        maximizeButton = new QToolButton(titlebar);
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

        closeButton = new QToolButton(titlebar);
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


        horizontalLayout_3->addLayout(gridLayout);


        retranslateUi(titlebar);

        QMetaObject::connectSlotsByName(titlebar);
    } // setupUi

    void retranslateUi(QWidget *titlebar)
    {
        titlebar->setWindowTitle(QCoreApplication::translate("titlebar", "Form", nullptr));
        darkstyle_action->setText(QCoreApplication::translate("titlebar", "darkstyle", nullptr));
        lightstyle_action->setText(QCoreApplication::translate("titlebar", "lightstyle", nullptr));
        ubuntustyle_action->setText(QCoreApplication::translate("titlebar", "ubuntustyle", nullptr));
        macosstyle_action->setText(QCoreApplication::translate("titlebar", "macosstyle", nullptr));
        skinButton->setText(QString());
        minimizeButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
        restoreButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
        maximizeButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
        closeButton->setText(QCoreApplication::translate("titlebar", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class titlebar: public Ui_titlebar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H

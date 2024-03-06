/********************************************************************************
** Form generated from reading UI file 'framelesswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAMELESSWINDOW_H
#define UI_FRAMELESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FramelessWindow
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *Content_widget;
    QVBoxLayout *verticalLayout;
    QWidget *titlebarContent_widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QWidget *windowContent_widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *FramelessWindow)
    {
        if (FramelessWindow->objectName().isEmpty())
            FramelessWindow->setObjectName("FramelessWindow");
        FramelessWindow->resize(1000, 800);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FramelessWindow->sizePolicy().hasHeightForWidth());
        FramelessWindow->setSizePolicy(sizePolicy);
        FramelessWindow->setMinimumSize(QSize(10, 10));
        verticalLayout_5 = new QVBoxLayout(FramelessWindow);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(5, 5, 5, 5);
        Content_widget = new QWidget(FramelessWindow);
        Content_widget->setObjectName("Content_widget");
        Content_widget->setStyleSheet(QString::fromUtf8("#Content_widget{\n"
"border:1px solid palette(highlight); \n"
"border-radius:5px 5px 5px 5px; \n"
"background-color:palette(Window);\n"
"}"));
        verticalLayout = new QVBoxLayout(Content_widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        titlebarContent_widget = new QWidget(Content_widget);
        titlebarContent_widget->setObjectName("titlebarContent_widget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titlebarContent_widget->sizePolicy().hasHeightForWidth());
        titlebarContent_widget->setSizePolicy(sizePolicy1);
        titlebarContent_widget->setMinimumSize(QSize(0, 20));
        verticalLayout_4 = new QVBoxLayout(titlebarContent_widget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout->addWidget(titlebarContent_widget);

        windowContent_widget = new QWidget(Content_widget);
        windowContent_widget->setObjectName("windowContent_widget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(windowContent_widget->sizePolicy().hasHeightForWidth());
        windowContent_widget->setSizePolicy(sizePolicy2);
        verticalLayout_3 = new QVBoxLayout(windowContent_widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addWidget(windowContent_widget);


        verticalLayout_5->addWidget(Content_widget);


        retranslateUi(FramelessWindow);

        QMetaObject::connectSlotsByName(FramelessWindow);
    } // setupUi

    void retranslateUi(QWidget *FramelessWindow)
    {
        FramelessWindow->setWindowTitle(QCoreApplication::translate("FramelessWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FramelessWindow: public Ui_FramelessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAMELESSWINDOW_H

/**************************************************
**
** Copyright (C) 2022 zhouxuan.
** Contact: 微信公众号【周旋机器视觉】
**
** 主窗口类，可以在该处实现自己的界面设计。
**
** LICENSE:LGPL
**************************************************/
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init()
{
    if (this->objectName().isEmpty())
        this->setObjectName("MainWindow");
    this->resize(903, 535);
    this->setMinimumSize(QSize(800, 0));
    actionsave = new QAction(this);
    actionsave->setObjectName("actionsave");
    actionload = new QAction(this);
    actionload->setObjectName("actionload");
    actionset = new QAction(this);
    actionset->setObjectName("actionset");
    actionskin = new QAction(this);
    actionskin->setObjectName("actionskin");
    actionfile = new QAction(this);
    actionfile->setObjectName("actionfile");
    centralwidget = new QWidget(this);
    centralwidget->setObjectName("centralwidget");
    listWidget = new QListWidget(centralwidget);
    new QListWidgetItem(listWidget);
    new QListWidgetItem(listWidget);
    new QListWidgetItem(listWidget);
    listWidget->setObjectName("listWidget");
    listWidget->setGeometry(QRect(80, 80, 191, 331));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName("tabWidget");
    tabWidget->setGeometry(QRect(310, 80, 321, 171));
    tab = new QWidget();
    tab->setObjectName("tab");
    pushButton = new QPushButton(tab);
    pushButton->setObjectName("pushButton");
    pushButton->setGeometry(QRect(20, 20, 93, 28));
    checkBox = new QCheckBox(tab);
    checkBox->setObjectName("checkBox");
    checkBox->setGeometry(QRect(150, 30, 91, 19));
    pushButton_2 = new QPushButton(tab);
    pushButton_2->setObjectName("pushButton_2");
    pushButton_2->setGeometry(QRect(20, 60, 93, 28));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName("tab_2");
    radioButton = new QRadioButton(tab_2);
    radioButton->setObjectName("radioButton");
    radioButton->setGeometry(QRect(20, 30, 115, 19));
    tabWidget->addTab(tab_2, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName("tab_3");
    textBrowser = new QTextBrowser(tab_3);
    textBrowser->setObjectName("textBrowser");
    textBrowser->setGeometry(QRect(30, 20, 261, 101));
    tabWidget->addTab(tab_3, QString());
    tab_4 = new QWidget();
    tab_4->setObjectName("tab_4");
    spinBox = new QSpinBox(tab_4);
    spinBox->setObjectName("spinBox");
    spinBox->setGeometry(QRect(10, 10, 42, 22));
    lineEdit = new QLineEdit(tab_4);
    lineEdit->setObjectName("lineEdit");
    lineEdit->setGeometry(QRect(10, 50, 221, 21));
    label = new QLabel(tab_4);
    label->setObjectName("label");
    label->setGeometry(QRect(70, 10, 72, 15));
    tabWidget->addTab(tab_4, QString());
    horizontalSlider = new QSlider(centralwidget);
    horizontalSlider->setObjectName("horizontalSlider");
    horizontalSlider->setGeometry(QRect(410, 370, 160, 22));
    horizontalSlider->setOrientation(Qt::Horizontal);
    horizontalScrollBar = new QScrollBar(centralwidget);
    horizontalScrollBar->setObjectName("horizontalScrollBar");
    horizontalScrollBar->setGeometry(QRect(400, 410, 160, 16));
    horizontalScrollBar->setOrientation(Qt::Horizontal);
    progressBar = new QProgressBar(centralwidget);
    progressBar->setObjectName("progressBar");
    progressBar->setGeometry(QRect(410, 330, 191, 21));
    progressBar->setValue(24);
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName("groupBox");
    groupBox->setGeometry(QRect(650, 100, 161, 131));
    radioButton_2 = new QRadioButton(groupBox);
    radioButton_2->setObjectName("radioButton_2");
    radioButton_2->setGeometry(QRect(20, 30, 115, 19));
    checkBox_2 = new QCheckBox(groupBox);
    checkBox_2->setObjectName("checkBox_2");
    checkBox_2->setGeometry(QRect(20, 60, 91, 19));
    toolBox = new QToolBox(centralwidget);
    toolBox->setObjectName("toolBox");
    toolBox->setGeometry(QRect(620, 290, 85, 143));
    page = new QWidget();
    page->setObjectName("page");
    page->setGeometry(QRect(0, 0, 85, 83));
    toolBox->addItem(page, QString::fromUtf8("Page 1"));
    page_2 = new QWidget();
    page_2->setObjectName("page_2");
    page_2->setGeometry(QRect(0, 0, 98, 28));
    toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
    this->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(this);
    statusbar->setObjectName("statusbar");
    this->setStatusBar(statusbar);

    tabWidget->setCurrentIndex(0);
    toolBox->setCurrentIndex(0);

    this->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    actionsave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
    actionload->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
    actionset->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
    actionskin->setText(QCoreApplication::translate("MainWindow", "skin", nullptr));
    actionfile->setText(QCoreApplication::translate("MainWindow", "file", nullptr));

    const bool __sortingEnabled = listWidget->isSortingEnabled();
    listWidget->setSortingEnabled(false);
    QListWidgetItem* ___qlistwidgetitem = listWidget->item(0);
    ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
    QListWidgetItem* ___qlistwidgetitem1 = listWidget->item(1);
    ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
    QListWidgetItem* ___qlistwidgetitem2 = listWidget->item(2);
    ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
    listWidget->setSortingEnabled(__sortingEnabled);

    pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    checkBox->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
    pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
    radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Tab 3", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Tab 4", nullptr));
    groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
    radioButton_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    checkBox_2->setText(QCoreApplication::translate("MainWindow", "CheckBox", nullptr));
    toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Page 1", nullptr));
    toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Page 2", nullptr));
}


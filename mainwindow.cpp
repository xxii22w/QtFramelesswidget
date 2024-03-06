/**************************************************
**
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

    this->setWindowTitle("MainWindow");

    const bool sortingEnabled = listWidget->isSortingEnabled();
    listWidget->setSortingEnabled(false);
    QListWidgetItem* listwidget1 = listWidget->item(0);
    listwidget1->setText("新建项目");
    QListWidgetItem* listwidget2 = listWidget->item(1);
    listwidget2->setText("新建项目");
    QListWidgetItem* listwidget3 = listWidget->item(2);
    listwidget3->setText("新建项目");
    listWidget->setSortingEnabled(sortingEnabled);

    pushButton->setText("PushButton");
    checkBox->setText("CheckBox");
    pushButton_2->setText("PushButton");
    tabWidget->setTabText(tabWidget->indexOf(tab),"Tab 1");
    radioButton->setText("RadioButton");
    tabWidget->setTabText(tabWidget->indexOf(tab_2),"Tab 2");
    tabWidget->setTabText(tabWidget->indexOf(tab_3),"Tab 3");
    label->setText(  "TextLabel");
    tabWidget->setTabText(tabWidget->indexOf(tab_4),"Tab 4");
    groupBox->setTitle(  "GroupBox");
    radioButton_2->setText(  "RadioButton");
    checkBox_2->setText(  "CheckBox");
    toolBox->setItemText(toolBox->indexOf(page),"Page 1");
    toolBox->setItemText(toolBox->indexOf(page_2),"Page 2");
}


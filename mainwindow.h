/**************************************************
**
**
** 主窗口类，可以在该处实现自己的界面设计
**
** LICENSE:LGPL
**************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QLineEdit>
#include <QAction>
#include <qlistwidget.h>
#include <QTabWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextBrowser>
#include <QScrollBar>
#include <QSpinBox>
#include <QLabel>
#include <QProgressBar>
#include <QToolBox>
#include <QGroupBox>
#include <QStatusBar>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();

private:

    QAction* actionsave;
    QAction* actionload;
    QAction* actionset;
    QAction* actionskin;
    QAction* actionfile;
    QWidget* centralwidget;
    QListWidget* listWidget;
    QTabWidget* tabWidget;
    QWidget* tab;
    QPushButton* pushButton;
    QCheckBox* checkBox;
    QPushButton* pushButton_2;
    QWidget* tab_2;
    QRadioButton* radioButton;
    QWidget* tab_3;
    QTextBrowser* textBrowser;
    QWidget* tab_4;
    QSpinBox* spinBox;
    QLineEdit* lineEdit;
    QLabel* label;
    QSlider* horizontalSlider;
    QScrollBar* horizontalScrollBar;
    QProgressBar* progressBar;
    QGroupBox* groupBox;
    QRadioButton* radioButton_2;
    QCheckBox* checkBox_2;
    QToolBox* toolBox;
    QWidget* page;
    QWidget* page_2;
    QStatusBar* statusbar;
};
#endif // MAINWINDOW_H

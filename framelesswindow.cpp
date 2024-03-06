/**************************************************
**
** Copyright (C) 2022 zhouxuan.
** Contact: 微信公众号【周旋机器视觉】
**
** framelesswindow无边框窗口类，为整个应用程序的基本窗口类，具备
** 1、无边框扁平化窗口
** 2、可拖动边界调整窗口大小（基于窗体九宫格布局，自己改写鼠标响应事件）
** 3、具备窗体阴影效果
** 4、可自定义标题栏（详见titlebar文件）
**
** LICENSE:LGPL
**************************************************/
#include "framelesswindow.h"

#include <QGraphicsDropShadowEffect>

FramelessWindow::FramelessWindow(QWidget* parent) :
    QWidget(parent),
    titlebar(new TitleBar(this))
{
    initui();
    Content_widget->setMinimumSize(200, 200);

    //【1】将窗口设为无边框窗口
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    //【2】添加最小化按钮标志，获取正确的Windows本机处理最小化函数
    //若注释掉则无法响应点击系统任务栏软件最大最小化操作
#if defined(Q_OS_WIN)
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
#endif
    //【3】设置鼠标跟踪，以此来编写自己无边框自定义标题栏窗口的鼠标事件
    setMouseTracking(true);
    //【4】important to watch mouse move from all child widgets
    QApplication::instance()->installEventFilter(this);
    //【5】添加自定义的标题栏
    titlebarContent_widget->layout()->addWidget(titlebar);

    //【6】设置窗口的阴影效果
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
    windowShadow->setBlurRadius(9.0);
    windowShadow->setColor(palette().color(QPalette::Highlight));
    windowShadow->setOffset(0.0);
    Content_widget->setGraphicsEffect(windowShadow);

    //参数初始化
    isLeftPressDown = false;
    this->dir = NONE;
}

FramelessWindow::~FramelessWindow()
{
    // delete ui;
}

void FramelessWindow::setContent(QWidget* w)
{
    windowContent_widget->layout()->addWidget(w);
}

void FramelessWindow::initui()
{
    if (this->objectName().isEmpty())
        this->setObjectName("FramelessWindow");
    this->resize(1000, 800);
    QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    this->setMinimumSize(QSize(10, 10));
    verticalLayout_5 = new QVBoxLayout(this);
    verticalLayout_5->setSpacing(6);
    verticalLayout_5->setObjectName("verticalLayout_5");
    verticalLayout_5->setContentsMargins(5, 5, 5, 5);
    Content_widget = new QWidget(this);
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


    QMetaObject::connectSlotsByName(this);

    this->setWindowTitle(QCoreApplication::translate("FramelessWindow", "Form", nullptr));
}

void FramelessWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        isLeftPressDown = false;
        if (dir != NONE) {
            this->releaseMouse();
            this->setCursor(QCursor(Qt::ArrowCursor));
            dir = NONE;
        }
    }
}

void FramelessWindow::mousePressEvent(QMouseEvent* event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        isLeftPressDown = true;
        if (dir != NONE) {
            this->mouseGrabber();
        }
        else {
            dragPosition = event->globalPos() - this->frameGeometry().topLeft();
        }
        break;
        //    case Qt::RightButton:
        //        this->close();
        //        break;
    default:
        QWidget::mousePressEvent(event);
    }
}

void FramelessWindow::mouseMoveEvent(QMouseEvent* event)
{
    QPoint gloPoint = event->globalPos();
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());

    if (!isLeftPressDown) {
        this->region(gloPoint);
    }
    else {

        if (dir != NONE) {
            QRect rMove(tl, rb);

            switch (dir) {
            case LEFT:
                if (rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                break;
            case RIGHT:
                rMove.setWidth(gloPoint.x() - tl.x());
                break;
            case UP:
                if (rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case DOWN:
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            case LEFTTOP:
                if (rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                if (rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case RIGHTTOP:
                rMove.setWidth(gloPoint.x() - tl.x());
                rMove.setY(gloPoint.y());
                break;
            case LEFTBOTTOM:
                rMove.setX(gloPoint.x());
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            case RIGHTBOTTOM:
                rMove.setWidth(gloPoint.x() - tl.x());
                rMove.setHeight(gloPoint.y() - tl.y());
                break;
            default:

                break;
            }
            this->setGeometry(rMove);
        }
        //此处会导致整个窗体都可以跟随鼠标移动
//        else {
//            move(event->globalPos() - dragPosition);
//            event->accept();
//        }
    }
    QWidget::mouseMoveEvent(event);
}

void FramelessWindow::region(const QPoint& cursorGlobalPoint)
{
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());
    int x = cursorGlobalPoint.x();
    int y = cursorGlobalPoint.y();

    if (tl.x() + PADDING >= x && tl.x() <= x && tl.y() + PADDING >= y && tl.y() <= y) {
        // 左上角
        dir = LEFTTOP;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (x >= rb.x() - PADDING && x <= rb.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        // 右下角
        dir = RIGHTBOTTOM;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    }
    else if (x <= tl.x() + PADDING && x >= tl.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        //左下角
        dir = LEFTBOTTOM;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (x <= rb.x() && x >= rb.x() - PADDING && y >= tl.y() && y <= tl.y() + PADDING) {
        // 右上角
        dir = RIGHTTOP;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    }
    else if (x <= tl.x() + PADDING && x >= tl.x()) {
        // 左边
        dir = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (x <= rb.x() && x >= rb.x() - PADDING) {
        // 右边
        dir = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }
    else if (y >= tl.y() && y <= tl.y() + PADDING) {
        // 上边
        dir = UP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else if (y <= rb.y() && y >= rb.y() - PADDING) {
        // 下边
        dir = DOWN;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }
    else {
        // 默认
        dir = NONE;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}

bool FramelessWindow::eventFilter(QObject* obj, QEvent* event) {
    if (isMaximized()) {
        return QWidget::eventFilter(obj, event);
    }

    // check mouse move event when mouse is moved on any object
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent* pMouse = dynamic_cast<QMouseEvent*>(event);
        if (pMouse) {
            mouseMoveEvent(pMouse);
        }
    }
    // press is triggered only on frame window
    else if (event->type() == QEvent::MouseButtonPress && obj == this) {
        QMouseEvent* pMouse = dynamic_cast<QMouseEvent*>(event);
        if (pMouse) {
            mousePressEvent(pMouse);
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease) {
        if (isLeftPressDown) {
            QMouseEvent* pMouse = dynamic_cast<QMouseEvent*>(event);
            if (pMouse) {
                mouseReleaseEvent(pMouse);
            }
        }
    }

    return QWidget::eventFilter(obj, event);
}

void FramelessWindow::changeEvent(QEvent* event) {
    if (event->type() == QEvent::WindowStateChange) {
        if (windowState().testFlag(Qt::WindowMaximized)) {
            styleWindow(true, false);
            event->ignore();
        }
        else //if (windowState().testFlag(Qt::WindowNoState)) {
        {
            styleWindow(true, true);
            event->ignore();
        }
    }
    event->accept();
}

void FramelessWindow::styleWindow(bool bActive, bool bNoState) {
    if (bActive) {
        if (bNoState) {
            layout()->setContentsMargins(PADDING, PADDING, PADDING, PADDING);
            //      ui->titlebarContent_widget->setStyleSheet(QStringLiteral(
            //          "#titlebarContent_widget{border: 0px none palette(shadow); "
            //          "border-top-left-radius:5px; border-top-right-radius:5px; "
            //          "background-color:palette(shadow); height:20px;}"));
            Content_widget->setStyleSheet(QStringLiteral(
                "#Content_widget{border:1px solid palette(highlight); border-radius:5px "
                "5px 5px 5px; background-color:palette(Window);}"));
            QGraphicsEffect* oldShadow = Content_widget->graphicsEffect();
            if (oldShadow) delete oldShadow;
            QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
            windowShadow->setBlurRadius(9.0);
            windowShadow->setColor(palette().color(QPalette::Highlight));
            windowShadow->setOffset(0.0);
            Content_widget->setGraphicsEffect(windowShadow);
        }
        else {
            layout()->setContentsMargins(0, 0, 0, 0);
            //      ui->titlebarContent_widget->setStyleSheet(QStringLiteral(
            //          "#titlebarContent_widget{border: 0px none palette(shadow); "
            //          "border-top-left-radius:0px; border-top-right-radius:0px; "
            //          "background-color:palette(shadow); height:20px;}"));
            Content_widget->setStyleSheet(QStringLiteral(
                "#Content_widget{border:1px solid palette(dark); border-radius:0px 0px "
                "0px 0px; background-color:palette(Window);}"));
            QGraphicsEffect* oldShadow = Content_widget->graphicsEffect();
            if (oldShadow) delete oldShadow;
            Content_widget->setGraphicsEffect(nullptr);
        }  // if (bNoState) else maximize
    }
    else {
        if (bNoState) {
            layout()->setContentsMargins(PADDING, PADDING, PADDING, PADDING);
            //      ui->titlebarContent_widget->setStyleSheet(QStringLiteral(
            //          "#titlebarContent_widget{border: 0px none palette(shadow); "
            //          "border-top-left-radius:5px; border-top-right-radius:5px; "
            //          "background-color:palette(dark); height:20px;}"));
            Content_widget->setStyleSheet(QStringLiteral(
                "#Content_widget{border:1px solid #000000; border-radius:5px 5px 5px "
                "5px; background-color:palette(Window);}"));
            QGraphicsEffect* oldShadow = Content_widget->graphicsEffect();
            if (oldShadow) delete oldShadow;
            QGraphicsDropShadowEffect* windowShadow = new QGraphicsDropShadowEffect;
            windowShadow->setBlurRadius(9.0);
            windowShadow->setColor(palette().color(QPalette::Shadow));
            windowShadow->setOffset(0.0);
            Content_widget->setGraphicsEffect(windowShadow);
        }
        else {
            layout()->setContentsMargins(0, 0, 0, 0);
            //      ui->titlebarContent_widget->setStyleSheet(QStringLiteral(
            //          "#titlebarContent_widget{border: 0px none palette(shadow); "
            //          "border-top-left-radius:0px; border-top-right-radius:0px; "
            //          "background-color:palette(dark); height:20px;}"));
            Content_widget->setStyleSheet(QStringLiteral(
                "#Content_widget{border:1px solid palette(shadow); border-radius:0px "
                "0px 0px 0px; background-color:palette(Window);}"));
            QGraphicsEffect* oldShadow = Content_widget->graphicsEffect();
            if (oldShadow) delete oldShadow;
            Content_widget->setGraphicsEffect(nullptr);
        }  // if (bNoState) { else maximize
    }    // if (bActive) { else no focus
}

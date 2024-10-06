#include "taskframe.h"

TaskFrame::TaskFrame(QWidget *parent)
    : QWidget{parent}
{
    initTaskFrame();

    QFont name_font = Font::initFont(20,-1);
    QFont footer_font = Font::initFont(10,-1);

    //Main Box of Widget
    QHBoxLayout* groupBoxLayout = new QHBoxLayout(this);
    gb->setMinimumHeight(920);
    groupBoxLayout->addStretch(0);
    groupBoxLayout->addWidget(gb);

    QVBoxLayout* headMainLayout = new QVBoxLayout(head);
    head->setStyleSheet("background-color: rgb(28,28,28); border-radius: 16px;");
    head->setMaximumSize(350, 150);
    head->setMinimumHeight(150);
    head->setLayout(headMainLayout);

    name->setMaximumHeight(30);
    name->setStyleSheet("border: 0");
    name->setMaxLength(20);
    name->setFont(name_font);

    TaskFrame::createToolButtons(plusBtn, ":/res/img/plus.svg", 25, 25);
    TaskFrame::createToolButtons(moreBtn, ":/res/img/more.svg", 25, 25);

    moreBtn->setMenu(menu);
    moreBtn->setPopupMode(QToolButton::InstantPopup);
    moreBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    QPushButton* editBtn = createMenuAction("Edit Date", menu);
    QPushButton* deleteTaskBtn = createMenuAction("Delete", menu);

    QHBoxLayout* headerLayout = new QHBoxLayout();
    headerLayout->setContentsMargins(15,15,15,15);
    headerLayout->addWidget(name);
    headerLayout->addWidget(plusBtn);
    headerLayout->addWidget(moreBtn);

    QHBoxLayout* footerLayout = new QHBoxLayout();
    footerLayout->setContentsMargins(20,0,0,0);
    footerLayout->addWidget(date);
    footerLayout->addItem(new QSpacerItem(10,0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    footerLayout->addWidget(notescount);

    date->setFont(footer_font);
    notescount->setFont(footer_font);
    notescount->setContentsMargins(20,10,20,10);
    changeLabelsColor(date, qRgb(142,142,142));
    changeLabelsColor(notescount, qRgb(142,142,142));

    headMainLayout->addLayout(headerLayout);
    headMainLayout->addLayout(footerLayout);

    QVBoxLayout* taskLayout = new QVBoxLayout(taskBlock);
    taskBlock->setLayout(taskLayout);
    taskLayout->addStretch(1);
    taskLayout->setContentsMargins(0,0,0,0);

    QVBoxLayout* mainStructLayout = new QVBoxLayout(gb);
    mainStructLayout->addWidget(head);
    mainStructLayout->addWidget(taskBlock);

    connect(plusBtn, &QToolButton::clicked, this, &TaskFrame::onplusBtn);
    connect(deleteTaskBtn, &QPushButton::clicked, this, &TaskFrame::deleteFrame);
    connect(editBtn, &QPushButton::clicked, this, &TaskFrame::editDate);
    connect(timer, &QTimer::timeout, this, &TaskFrame::refreshCount);

    timer->start(1);
}

void TaskFrame::initTaskFrame() {
    count = 0;
    timer = new QTimer(this);
    gb = new QGroupBox(this);
    head = new QWidget(gb);
    name = new QLineEdit("New Task Group",head);
    plusBtn = new QToolButton(head);
    moreBtn = new QToolButton(head);
    taskBlock = new QWidget(gb);
    menu = new QMenu(this);
    notescount = new QLabel("0/10");
    date = new QLabel("Due: 1 Jan");
}

QPushButton* TaskFrame::createMenuAction(QString text, QMenu* menu) {
    QWidgetAction *btnAction= new QWidgetAction(menu);
    QHBoxLayout* menuLyt = new QHBoxLayout();
    QPushButton* act = new QPushButton(text, menu);

    act->setStyleSheet("QPushButton{border:none; background-color:none}");
    act->setStyleSheet("QWidget:hover{background-color:gray;}");
    act->setMinimumSize(70,30);
    menu->setStyleSheet("border: 1px solid rgb(73,73,73);");

    menuLyt->addWidget(act);
    btnAction->setDefaultWidget(act);
    btnAction->setText(text);
    menu->addAction(btnAction);

    return act;
}

void TaskFrame::changeLabelsColor(QLabel* label, QRgb rgb) {
    QColor color = rgb;
    QPalette palette = label->palette();
    palette.setColor(QPalette::WindowText,color);
    label->setPalette(palette);
}

void TaskFrame::editDate() {
    DateEdit dateWindow;
    dateWindow.setModal(true);
    dateWindow.exec();

    QDate dateValue = dateWindow.date;
    QString dateString;
    QString month;
    QString day = dateValue.day() == 0? "1" : QString::number(dateValue.day());

    switch (dateValue.month()) {
    case 1:
        month = "Jan";
        break;
    case 2:
        month = "Feb";
        break;
    case 3:
        month = "Mar";
        break;
    case 4:
        month = "Apr";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "Jun";
        break;
    case 7:
        month = "Jul";
        break;
    case 8:
        month = "Aug";
        break;
    case 9:
        month = "Sep";
        break;
    case 10:
        month = "Oct";
        break;
    case 11:
        month = "Nov";
        break;
    case 12:
        month = "Dec";
        break;
    default:
        month = "Jan";
        break;
    }
    dateString = QString("Due: %1 %2").arg(day,month);
    date->setText(dateString);
}

void TaskFrame::deleteFrame() {
    delete this;
}

void TaskFrame::refreshCount() {
    QVBoxLayout* lay = qobject_cast<QVBoxLayout*>(taskBlock->layout());
    count = lay->count()-1;
    notescount->setText(QString("%1/10").arg(QString::number(count)));
}

void TaskFrame::onplusBtn() {
    QVBoxLayout* lay = qobject_cast<QVBoxLayout*>(taskBlock->layout());
    count = lay->count()-1;
    if(count < 10) {
        taskwidget* task = new taskwidget(taskBlock);
        lay->insertWidget(count,task);
    }
}

void TaskFrame::createToolButtons(QToolButton* btn, QString iconPath, int w, int h) {
    btn->setStyleSheet("border-radius: 4px; background-color: rgb(38,38,38);");
    btn->setIcon(QIcon(iconPath));
    btn->setIconSize(QSize(w,h));
}

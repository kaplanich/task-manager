#include "./libs/taskwidget.h"

taskwidget::taskwidget(QWidget *parent)
    : QWidget{parent}
{
    initTaskWidget();

    QHBoxLayout* groupBoxLayout = new QHBoxLayout(this);
    QFont name_font = Font::initFont(13,500);
    QFont description_font = Font::initFont(9,400);

    groupBoxLayout->addWidget(groupBox);
    groupBoxLayout->setContentsMargins(0,5,0,0);
    groupBox->setMinimumSize(320,75);
    groupBox->setStyleSheet("border-radius: 12px; background-color: rgb(38,38,38)");

    name->setFont(name_font);
    name->setMaxLength(25);
    description->setFont(description_font);
    description->setMaxLength(30);
    description->setStyleSheet("color: rgb(142,142,142); background-color: rgb(38,38,38);" );

    minusBtn->setStyleSheet("border-radius: 4px; border: 1px solid rgb(59,59,59);");
    minusBtn->setIcon(QIcon(":/res/img/minus.svg"));
    minusBtn->setMaximumSize(25,25);
    minusBtn->setIconSize(QSize(25,25));

    QHBoxLayout* taskLayout = new QHBoxLayout();
    taskLayout->addWidget(check);
    taskLayout->addWidget(name);
    taskLayout->addWidget(minusBtn);

    QVBoxLayout* mainTaskLayout = new QVBoxLayout(groupBox);
    mainTaskLayout->addLayout(taskLayout);
    mainTaskLayout->addWidget(description);

    connect(minusBtn, &QToolButton::clicked, this, &taskwidget::onMinus);
}

void taskwidget::initTaskWidget() {
    groupBox = new QGroupBox(this);
    check = new QCheckBox(groupBox);
    name = new QLineEdit("New Task",groupBox);
    minusBtn = new QToolButton(groupBox);
    description = new QLineEdit("Task Description",groupBox);
}

void taskwidget::onMinus() {
    delete this;
}

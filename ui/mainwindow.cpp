#include "./libs/mainwindow.h"
#include "./ui_mainwindow.h"
#include "./libs/taskframe.h"
#include <QGroupBox>
#include <QToolButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setStyleSheet("border: 0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_Task_triggered()
{
    QHBoxLayout* lay = qobject_cast<QHBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    TaskFrame* item = new TaskFrame;
    item->setMaximumWidth(380);
    item->setMinimumWidth(380);

    lay->addWidget(item);
}

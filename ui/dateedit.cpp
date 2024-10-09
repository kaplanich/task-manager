#include "dateedit.h"
#include "./ui_dateedit.h"

DateEdit::DateEdit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DateEdit)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(confirmDate()));
}

DateEdit::~DateEdit()
{
    delete ui;
}

void DateEdit::confirmDate()
{
    date = ui->calendarWidget->selectedDate();
    this->close();
}

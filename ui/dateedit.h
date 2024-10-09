#ifndef DATEEDIT_H
#define DATEEDIT_H

#include <QDate>
#include <QDialog>

namespace Ui {
class DateEdit;
}

class DateEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DateEdit(QWidget *parent = nullptr);
    ~DateEdit();
    QDate date;

private slots:
    void confirmDate();

private:
    Ui::DateEdit *ui;
};

#endif // DATEEDIT_H

#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QToolButton>
#include <QHBoxLayout>
#include "font.h"

class taskwidget : public QWidget
{
    Q_OBJECT
public:
    explicit taskwidget(QWidget *parent = nullptr);
    void initTaskWidget();
    void onMinus();

signals:

private:
    QGroupBox* groupBox;
    QCheckBox* check;
    QLineEdit* name;
    QToolButton* minusBtn;
    QLineEdit* description;
};

#endif // TASKWIDGET_H

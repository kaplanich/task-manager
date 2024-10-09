#ifndef TASKFRAME_H
#define TASKFRAME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QLabel>
#include <QStyle>
#include <QScrollArea>
#include <QFontDatabase>
#include <QTimer>
#include <QSpacerItem>
#include <QMenu>
#include <./libs/font.h>
#include <QWidgetAction>
#include <QPushButton>
#include <QColor>
#include <QPalette>
#include "./ui/dateedit.h"
#include "./libs/taskwidget.h"

class TaskFrame : public QWidget
{
    Q_OBJECT
public:
    explicit TaskFrame(QWidget *parent = nullptr);
    void initTaskFrame();
    void onplusBtn();
    void createToolButtons(QToolButton* btn, QString iconPath, int h, int w);
    QPushButton* createMenuAction(QString text, QMenu* menu);
    void editDate();
    void deleteFrame();
    void changeLabelsColor(QLabel* label, QRgb rgb);
    void refreshCount();
signals:

private:
    QTimer* timer;
    QGroupBox* gb;
    QWidget* head;
    QLineEdit* name;
    QToolButton* plusBtn;
    QToolButton* moreBtn;
    QLabel* notescount;
    QLabel* date;
    QWidget* taskBlock;
    QMenu* menu;
    int count;

};

#endif // TASKFRAME_H

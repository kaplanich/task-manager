#ifndef FONT_H
#define FONT_H

#include <QString>
#include <QFont>
#include <QFontDatabase>
#include <QList>

class Font
{
public:
    Font();

    static QFont initFont(int size, int weight);
};

#endif // FONT_H

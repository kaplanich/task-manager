#include "font.h"

Font::Font() {}

QFont Font::initFont(int size, int weight = -1) {
    int id = QFontDatabase::addApplicationFont(":/res/fonts/Inter-VariableFont_opsz,wght.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family,size,weight);
    return font;
}

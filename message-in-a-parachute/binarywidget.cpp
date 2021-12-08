#include "binarywidget.h"
#include <QPainter>
#include <QDebug>
binarywidget::binarywidget(QWidget * parent) : QWidget(parent) {
     bitSet = std::vector<bool>();
     numberLetterDraw = 14;
     bitByLetter = 7;
     backgroundColor = Qt::white;
     painterColor = Qt::red;

}

void binarywidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  QBrush backgroundBrush = QBrush(backgroundColor);
  QBrush painterBrush = QBrush(painterColor);
  for (int i = 0; i < numberLetterDraw; ++i) {
      for (int j = 0; j < bitByLetter; ++j) {
          if(bitSet.size() > (i*7+j) && bitSet.at(i*7+j)){
              painter.setBrush(painterBrush);
          }else{
               painter.setBrush(backgroundBrush);
          }
         painter.drawEllipse(i*12,j*12,10,10);
      }
  }
}

void binarywidget::updateBitSet(std::vector<bool> b){
    bitSet = b;
}
void binarywidget::setNumberLetterDraw(int number){
    numberLetterDraw = number;
    this->update();
}
void binarywidget::setBitByLetter(int bit){
    bitByLetter = bit;
    this->update();
}
void binarywidget::setBackgroundColor(QColor b){
    backgroundColor = b;
}
void binarywidget::setPainterColor(QColor p){
    painterColor = p;
}

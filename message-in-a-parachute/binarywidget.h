#ifndef BINARYWIDGET_H
#define BINARYWIDGET_H
#include <QWidget>
#include <QColor>
class binarywidget: public QWidget
{
    Q_OBJECT
public:
    explicit binarywidget(QWidget * parent = nullptr);
    void updateBitSet(std::vector<bool>);
    void setNumberLetterDraw(int);
    void setBitByLetter(int);
    void setBackgroundColor(QColor);
    void setPainterColor(QColor);
protected:
  void paintEvent(QPaintEvent *) override;
private :
  std::vector<bool> bitSet;
  int numberLetterDraw;
  int bitByLetter;
  QColor backgroundColor;
  QColor painterColor;
};

#endif // BINARYWIDGET_H

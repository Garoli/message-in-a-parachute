#ifndef PARACHUTEWIDGET_H
#define PARACHUTEWIDGET_H
#include <QWidget>
#include <QColor>
#include <iostream>
class parachutewidget : public QWidget
{
    Q_OBJECT
public:
    explicit parachutewidget(QWidget * parent = nullptr);
    std::vector<QPointF> computePoints(int);
    void updateBitSet(std::vector<bool>);

    void setNumberSectors(int);
    void setBackgroundColor(QColor);
    void setPainterColor(QColor);

protected:
  void paintEvent(QPaintEvent *) override;

private :
  std::vector<bool> bitSet;
  int numberTracks;
  int numberSectors;
  QColor backgroundColor;
  QColor painterColor;

public slots :
     void setNumberTracks(int);
};


#endif // PARACHUTEWIDGET_H

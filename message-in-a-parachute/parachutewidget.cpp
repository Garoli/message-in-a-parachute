#include "parachutewidget.h"
#include <QPainter>
#include <QDebug>
#include <QtMath>

parachutewidget::parachutewidget(QWidget * parent) : QWidget(parent) {
    bitSet = std::vector<bool>();
    numberTracks = 5;
    numberSectors = 21;
    backgroundColor = Qt::white;
    painterColor = Qt::red;

}

void parachutewidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  QBrush painterBrush(painterColor);
  QBrush backgroundBrush(backgroundColor);
  std::vector<QPointF> points = computePoints(150);
  for (int i= 0;  i< points.size(); i+=4) {
     if(bitSet.size() > (i/4) && bitSet.at(i/4)){
            painter.setBrush(painterBrush);
        }else{
             painter.setBrush(backgroundBrush);
        }
        painter.drawConvexPolygon(&points[i], 4);
    }
}

std::vector<QPointF> parachutewidget::computePoints(int radiusSize){
    std::vector<QPointF> points;
    float ae = 2*M_PI/numberSectors;
    float we = radiusSize/numberTracks;
    int s,t;
    float a1,a2,rp,rq;
    for (int k = 0; k < numberTracks*numberSectors; ++k) {
        s = k % numberSectors;
        a1 = s * ae;
        a2 = (s+1)*ae;
        t = k / numberSectors;
        rp = t * we;
        rq = (t+1) * we;
        points.push_back(QPointF(rq * cos(a2)+radiusSize, rq * sin(a2)+radiusSize));
        points.push_back(QPointF(rq * cos(a1)+radiusSize, rq * sin(a1)+radiusSize));
        points.push_back(QPointF(rp * cos(a1)+radiusSize, rp * sin(a1)+radiusSize));
        points.push_back(QPointF(rp * cos(a2)+radiusSize, rp * sin(a2)+radiusSize));
    }
    return points;

}
void parachutewidget::updateBitSet(std::vector<bool> b){
    bitSet = b;
}
void parachutewidget::setNumberTracks(int tracks){
    numberTracks = tracks;
    this->update();
}
void parachutewidget::setNumberSectors(int sectors){
    numberSectors = sectors;
    this->update();
}
void parachutewidget::setBackgroundColor(QColor b){
    backgroundColor = b;
}
void parachutewidget::setPainterColor(QColor p){
    painterColor = p;
}


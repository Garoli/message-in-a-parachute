#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QtGui>
#include <QColorDialog>
#include <QColor>
#include <QPushButton>

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ColorButton(QWidget *parent = 0);
    QColor getColor();

signals:
    void colorChanged(QColor);

public slots:
    void changeColor(const QColor &);
    void chooseColor();
    void paintEvent(QPaintEvent *event);

private:
    QColor currentColor;
};

#endif // COLORBUTTON_H

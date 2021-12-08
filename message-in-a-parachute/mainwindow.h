#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSpinBox>
#include <QSlider>
#include "message.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateMessage();
    void openFromFile();
    void saveToFile();
    void reset();
    void about();
    void exportImage();

private:
    Ui::MainWindow *ui;
    Message * message;

public slots:
    void updateSectors(int);
    void updateTracks(int);
    void updateBackgroundColor();
    void updatePainterColor();
};
#endif // MAINWINDOW_H

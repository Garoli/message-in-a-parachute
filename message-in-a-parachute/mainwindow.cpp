#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->messageEdit,&QTextEdit::textChanged,this,&MainWindow::updateMessage);

    connect(ui->sliderTracks, &QSlider::valueChanged,ui->spinTracks, &QSpinBox::setValue);
    connect(ui->spinTracks, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), ui->sliderTracks, &QSlider::setValue);

    connect(ui->sliderTracks, &QSlider::valueChanged, this, &MainWindow::updateTracks);

    connect(ui->sliderSectors, &QSlider::valueChanged,ui->spinSectors, &QSpinBox::setValue);
    connect(ui->spinSectors, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), ui->sliderSectors, &QSlider::setValue);

    connect(ui->sliderSectors, &QSlider::valueChanged, this, &MainWindow::updateSectors);

    connect(ui->action_Open,&QAction::triggered,this,&MainWindow::openFromFile);
    connect(ui->action_Save,&QAction::triggered,this,&MainWindow::saveToFile);
    connect(ui->action_New,&QAction::triggered,this,&MainWindow::reset);
    connect(ui->action_about, &QAction::triggered, this, &MainWindow::about);
    connect(ui->backgroundButton, &QPushButton::clicked,this,&MainWindow::updateBackgroundColor);
    connect(ui->painterButton, &QPushButton::clicked,this,&MainWindow::updatePainterColor);
    connect(ui->imageButton, &QPushButton::clicked, this, &MainWindow::exportImage);
    ui->backgroundButton->changeColor(Qt::white);
    ui->painterButton->changeColor(Qt::red);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateMessage(){
    message = new Message(ui->messageEdit->toPlainText().toStdString());
    std::vector<bool> bitSet;
    for(std::size_t i = 0; i < message->getMessage().size(); ++i) {
        Letter letter = message->getMessage()[i];
        for (int j = letter.get_letter().size()-1; j >= 0; j--) {
            bitSet.push_back(letter.get_letter()[j]);
        }
    }
    ui->parachute->updateBitSet(bitSet);
    ui->binary->updateBitSet(bitSet);
    ui->parachute->update();
    ui->binary->update();
}
void MainWindow::updateBackgroundColor(){
    QColor color = ui->backgroundButton->getColor();
    ui->parachute->setBackgroundColor(color);
    ui->binary->setBackgroundColor(color);
    ui->parachute->update();
    ui->binary->update();
}

void MainWindow::updatePainterColor(){
    QColor color = ui->painterButton->getColor();
    ui->parachute->setPainterColor(color);
    ui->binary->setPainterColor(color);
    ui->parachute->update();
    ui->binary->update();
}

void MainWindow::updateTracks(int){
    int value = ui->sliderTracks->value();
    int value_2 = ui->sliderSectors->value();
    ui->parachute->setNumberTracks(value);
    ui->binary->setNumberLetterDraw((value*value_2)/7);
}


void MainWindow::updateSectors(int){
    int value = ui->sliderTracks->value();
    int value_2 = ui->sliderSectors->value();
    ui->parachute->setNumberSectors(value_2);
    ui->binary->setNumberLetterDraw((value*value_2)/7);
}

void MainWindow::openFromFile(){
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Parachute"), "/home/", tr("Parachute Format (*.par)"));
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        ui->messageEdit->setText(in.readLine());
        QStringList list = in.readLine().split(" ");
        ui->sliderTracks->setValue(list[0].toInt());
        ui->sliderSectors->setValue(list[1].toInt());
    }
}
void MainWindow::saveToFile(){
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Parachute"), "",
                                                    tr("Parachute Format (*.par);;"));
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << ui->messageEdit->toPlainText().toLatin1() << "\n";
        out << ui->sliderTracks->value() << " "<< ui->sliderSectors->value();
    }

}
void MainWindow::reset(){
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Save:
          saveToFile();
          break;
      case QMessageBox::Discard:
          ui->messageEdit->setText(QString(""));
          break;
      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
      default:
          // should never be reached
          break;
    }
}


void MainWindow::about(){
    QMessageBox::about(this,"About",tr("Program developped by Adrien & Sarah"));
}


void MainWindow::exportImage(){
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save image"), "/home/", tr("PNG Format (*.png)"));
    if(!fileName.isEmpty()){
        ui->parachute->grab().save(fileName);
    }
}

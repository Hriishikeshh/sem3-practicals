#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<cmath>

using namespace std;
QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int order;
    order=ui->textEdit->toPlainText().toInt();
    Paint_recurssive(order,50,400,350,400);
    Paint_recurssive(order,350,400,200,140);
    Paint_recurssive(order,200,140,50,400);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Paint_recurssive(int order, int x1, int y1, int x5, int y5)
{
    int deltaX,deltaY,x2,y2,x3,y3,x4,y4;
    if (order==1){
        DDA(x1,y1,x5,y5);
    }
    else{
        deltaX=(x5-x1)/3;
        deltaY=(y5-y1)/3;
        x2=x1+deltaX;
        y2=y1+deltaY;
        x3=int((x1+x5)/2+sqrt(3)*(y1-y5)/6);
        y3=int((y1+y5)/2+sqrt(3)*(x5-x1)/6);
        x4=x1+deltaX*2;
        y4=y1+deltaY*2;
        Paint_recurssive(order-1,x1,y1,x2,y2);
        Paint_recurssive(order-1,x2,y2,x3,y3);
        Paint_recurssive(order-1,x3,y3,x4,y4);
        Paint_recurssive(order-1,x4,y4,x5,y5);
    }

}

void MainWindow:: DDA(int x1,int y1,int x2,int y2){
    float dx,dy,step;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        step=abs(dx);
    }
    else{
        step=abs(dy);
    }
    float x,y;
    float xinc,yinc;
    xinc=dx/step;
    yinc=dy/step;
    int sign;
    if(dx>1){
        sign=1;
    }
    else if(dx==0){sign=0;}
    else{
        sign=-1;
    }

    x=x1+sign*0.5;
    y=y1+sign*0.5;
    int i=0;
    while(i<=step){
        img.setPixel(int(x),int(y),qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

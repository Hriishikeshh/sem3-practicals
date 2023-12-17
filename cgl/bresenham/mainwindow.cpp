#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>

QImage img(300,300,QImage::Format_RGB888);

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
    int x0,y0,l,b;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    rectangle(x0,y0,l,b);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(float x0,float y0,float x1,float y1){
    float dx=x1-x0;
    float dy=y1-y0;
    float length;
    if(abs(dx)>abs(dy)){
        length=abs(dx);
    }

    else{
        length=abs(dy);
    }

    float xinc=dx/length;
    float yinc=dy/length;
    float x=x0,y=y0;
    int k=1;
    img.setPixel(x,y,qRgb(200,200,0));
    while(k<=length){
        x+=xinc;
        y+=yinc;
        k+=1;
        img.setPixel(x,y,qRgb(200,200,0));
    }
}

void MainWindow::bresenham(int x0,int y0,int x1,int y1){
    int dx=x1-x0;
    int dy=y1-y0;
    int x=x0;
    int y=y0;
    img.setPixel(x,y,qRgb(200,200,0));

    int p;
    p=2*dy-dx;
    while(x!=x1){
        if(p>=0){
            p+=(2*dy-2*dx);
            x+=1;
            y+=1;
        }
        else{
            p+=2*dy;
            x+=1;
        }
        img.setPixel(x,y,qRgb(200,200,0));
    }
}

void MainWindow::rectangle(float x0, float y0, float l, float b){
    dda(x0,y0,x0+l,y0);
    dda(x0+l,y0,x0+l,y0+b);
    dda(x0+l,y0+b,x0,y0+b);
    dda(x0,y0+b,x0,y0);
}

void MainWindow::rhombus(float x0, float y0, float l, float b){
    dda(x0,(y0+b/2),(x0+l/2),y0);
    dda((x0+l/2),y0,(x0+l),(y0+b/2));
    dda((x0+l),(y0+b/2),(x0+l/2),(y0+b));
    dda((x0+l/2),(y0+b),(x0),(y0+b/2));
}

void MainWindow::circle(float x0,float y0,float l,float b){
    float h=x0+(l/2);
    float k=y0+(b/2);
    float r=((l*b)/(2*sqrt(l*l+b*b)));
    float d=3*(2-r);
    float x=0,y=r;
    while(x<=y){
        img.setPixel(x+h,y+k,qRgb(200,200,0));
        img.setPixel(-x+h,y+k,qRgb(200,200,0));
        img.setPixel(x+h,-y+k,qRgb(200,200,0));
        img.setPixel(-x+h,-y+k,qRgb(200,200,0));
        img.setPixel(y+h,x+k,qRgb(200,200,0));
        img.setPixel(-y+h,x+k,qRgb(200,200,0));
        img.setPixel(y+h,-x+k,qRgb(200,200,0));
        img.setPixel(-y+h,-x+k,qRgb(200,200,0));

        if(d>=0){
            d+=4*(x-y)+10;
            y--;
        }
        else{
            d+=4*x+6;
        }
        x+=1;
    }

}
















void MainWindow::on_pushButton_2_clicked()
{
    int x0,y0,l,b;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    rhombus(x0,y0,l,b);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_3_clicked()
{
    int x0,y0,l,b;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    circle(x0,y0,l,b);
    ui->label->setPixmap(QPixmap::fromImage(img));
}


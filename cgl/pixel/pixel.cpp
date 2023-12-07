#include "pixel.h"
#include "ui_pixel.h"
QImage img(450,450,QImage::Format_RGB888);
pixel::pixel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pixel)
{
    ui->setupUi(this);
}

pixel::~pixel()
{
    delete ui;
}

void pixel::DDA(float x1,float y1,float x2,float y2){
    float dx,dy,xinc,yinc,x,y,length;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        length=abs(dx);
    }
    else{
        length=abs(dy);
    }

    xinc=dx/length;
    yinc=dy/length;

    x=x1;
    y=y1;
    int i=0;
    while(i<length){
        img.setPixel(int(x),int(y),qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void Drawcircle(int xc,int yc,int x,int y){
    img.setPixel(x+xc,y+yc,qRgb(255,255,255));
    img.setPixel(x-xc,y+yc,qRgb(255,255,255));
    img.setPixel(x+xc,y-yc,qRgb(255,255,255));
    img.setPixel(x-xc,y-yc,qRgb(255,255,255));
    img.setPixel(x+y,y+xc,qRgb(255,255,255));
    img.setPixel(x-yc,y+xc,qRgb(255,255,255));
    img.setPixel(x+yc,y-xc,qRgb(255,255,255));
    img.setPixel(x-yc,y-xc,qRgb(255,255,255));
}

void Circle(int xc,int yc,int r){
    int x=0,y=r;
    int d = 3-2 * r;
    Drawcircle(xc,yc,x,y);
    while(y>=x){
        x++;
        if(d>0){
            y--;
            d=d+4 * (x-y)+ 10;
        }
        else{
            d=d+4*x+6;
        }
        Drawcircle(xc,yc,x,y);
    }
}



void pixel::on_pushButton_clicked()
{
    int x1,x2,y1,y2,xc,yc,radius;
    x1=ui->textEdit->toPlainText().toInt();
    x2=ui->textEdit_3->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    y2=ui->textEdit_4->toPlainText().toInt();
    xc=ui->textEdit_5->toPlainText().toInt();
    yc=ui->textEdit_6->toPlainText().toInt();
    radius=ui->textEdit_7->toPlainText().toInt();
    DDA(x1,y1,x2,y2);
    Circle(xc,yc,radius);
    img.setPixel(x1,y1,qRgb(255,255,255));
    ui->label->setPixmap(QPixmap::fromImage(img));
}


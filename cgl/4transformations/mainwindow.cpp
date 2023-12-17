#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage img(400,400,QImage::Format_RGB888);

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

void MainWindow::dda(float x1,float y1,float x2,float y2){
    float dx=x2-x1;
    float dy=y2-y1;
    float length;
    if(abs(dx)>abs(dy)){
        length=abs(dx);
    }
    else{
        length=abs(dy);
    }
    float x,y;
    x=x1;
    y=y1;
    float xinc=dx/length;
    float yinc=dy/length;
    img.setPixel(x,y,qRgb(255,255,255));
    int k=1;
    while(k<=length){
        x+=xinc;
        y+=yinc;
        k+=1;
        img.setPixel(x,y,qRgb(255,255,255));
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_clicked()
{
    dda(0,200,400,200);
    dda(200,0,200,400);
}


void MainWindow::on_pushButton_2_clicked()
{
    float x0,y0,x1,y1,x2,y2;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    x1=ui->textEdit_3->toPlainText().toInt();
    y1=ui->textEdit_4->toPlainText().toInt();
    x2=ui->textEdit_5->toPlainText().toInt();
    y2=ui->textEdit_6->toPlainText().toInt();

    dda(200+x0,200+y0,200+x1,200+y1);
    dda(200+x1,200+y1,200+x2,200+y2);
    dda(200+x2,200+y2,200+x0,200+y0);

}


void MainWindow::on_pushButton_3_clicked()
{
    float x0,y0,x1,y1,x2,y2,xt,yt;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    x1=ui->textEdit_3->toPlainText().toInt();
    y1=ui->textEdit_4->toPlainText().toInt();
    x2=ui->textEdit_5->toPlainText().toInt();
    y2=ui->textEdit_6->toPlainText().toInt();
    xt=ui->textEdit_7->toPlainText().toInt();
    yt=ui->textEdit_8->toPlainText().toInt();

    dda(200+x0+xt,200+y0+yt,200+x1+xt,200+y1+yt);
    dda(200+x1+xt,200+y1+yt,200+x2+xt,200+y2+yt);
    dda(200+x2+xt,200+y2+yt,200+x0+xt,200+y0+yt);

}




void MainWindow::on_pushButton_4_clicked()
{
    float x0,y0,x1,y1,x2,y2,xs,ys;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    x1=ui->textEdit_3->toPlainText().toInt();
    y1=ui->textEdit_4->toPlainText().toInt();
    x2=ui->textEdit_5->toPlainText().toInt();
    y2=ui->textEdit_6->toPlainText().toInt();
    xs=ui->textEdit_9->toPlainText().toInt();
    ys=ui->textEdit_10->toPlainText().toInt();

    dda(200+x0*xs,200+y0*ys,200+x1*xs,200+y1*ys);
    dda(200+x1*xs,200+y1*ys,200+x2*xs,200+y2*ys);
    dda(200+x2*xs,200+y2*ys,200+x0*xs,200+y0*ys);
}




void MainWindow::on_pushButton_5_clicked()
{
    float x0,y0,x1,y1,x2,y2,theta;
    x0=ui->textEdit->toPlainText().toInt();
    y0=ui->textEdit_2->toPlainText().toInt();
    x1=ui->textEdit_3->toPlainText().toInt();
    y1=ui->textEdit_4->toPlainText().toInt();
    x2=ui->textEdit_5->toPlainText().toInt();
    y2=ui->textEdit_6->toPlainText().toInt();
    theta=ui->textEdit_11->toPlainText().toInt();

    float radian=theta*(3.14/180);

    dda(200+(x0*cos(radian)-y0*sin(radian)),200+(x0*sin(radian)+y0*cos(radian)),200+(x1*cos(radian)-y1*sin(radian)),200+(x1*sin(radian)+y1*cos(radian)));
    dda(200+(x1*cos(radian)-y1*sin(radian)),200+(x1*sin(radian)+y1*cos(radian)),200+(x2*cos(radian)-y2*sin(radian)),200+(x2*sin(radian)+y2*cos(radian)));
    dda(200+(x2*cos(radian)-y2*sin(radian)),200+(x2*sin(radian)+y2*cos(radian)),200+(x0*cos(radian)-y0*sin(radian)),200+(x0*sin(radian)+y0*cos(radian)));
}










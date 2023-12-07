#ifndef PIXEL_H
#define PIXEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pixel; }
QT_END_NAMESPACE

class pixel : public QMainWindow
{
    Q_OBJECT

public:
    pixel(QWidget *parent = nullptr);
    ~pixel();

private slots:
    void on_pushButton_clicked();
    void DDA(float x1,float y1,float x2,float y2);
    void Drawcircle(int xc,int yc,int x,int y);
    void Circle(int xc,int yc,int r);

private:
    Ui::pixel *ui;
};
#endif // PIXEL_H

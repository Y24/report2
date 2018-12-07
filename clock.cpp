#include "clock.h"
enum flag{
   HOUR,MINUTE,SECOND
};
clock::clock(QWidget *parent) :
    QWidget(parent),baseClock ()
{
    this->resize(1500,1000);
    this->setWindowTitle("clock");
    Timer=new QTimer(this);
    connect(Timer,SIGNAL(timeout()),this,SLOT(increaseByseconds()));
     Timer->start(1000);
}
QPointF calculatePoint(const QPointF & center,flag f,double number,int lineLength){
    QPointF re;
    double rad;
    switch(f){
    case HOUR:
        rad=number*PI/6;
        break;
    case MINUTE:
    case SECOND:
        rad=number*PI/30;
        break;
    }
    re.setX(center.x()+lineLength*sin(rad));
    re.setY(center.y()-lineLength*cos(rad));
    return re;
}
void clock::Paint(QPainter& painter,int clockCenterX,int clockCenterY,int clockR){
     QPointF clockCenter(clockCenterX,clockCenterY);
     QPointF TextStart(clockCenterX-clockR+60,clockCenterY+clockR+50);
     painter.drawText(TextStart,getTime().toString());
     painter.drawText(QPointF(clockCenterX+clockR-20,clockCenterY+10),QString::number(3));
     painter.drawText(QPointF(clockCenterX-5,clockCenterY+clockR-10),QString::number(6));
     painter.drawText(QPointF(clockCenterX-clockR+10,clockCenterY+10),QString::number(9));
     painter.drawText(QPointF(clockCenterX-10,clockCenterY-clockR+20),QString::number(12));
     for(int i=0;i<60;i++){
         painter.drawLine(QLineF(calculatePoint(clockCenter,MINUTE,i+1,clockR-10),calculatePoint(clockCenter,MINUTE,i+1,clockR)));
     }
     auto time=getTime().time();
     int hour=time.hour();
     int minute=time.minute();
     int second =time.second();
     painter.save();
     QColor hcolor(0,0xFF,0);
     QPen h(hcolor);
     h.setWidth(5);
     painter.setPen(h);
     painter.drawLine(QLineF(clockCenter,calculatePoint(clockCenter,HOUR,hour+minute/60.0+second/3600.0,clockR-80)));
     QColor mcolor(0,0xFF,0xFF);
     QPen m(mcolor);
     m.setWidth(4);
     painter.setPen(m);
     painter.drawLine(QLineF(clockCenter,calculatePoint(clockCenter,MINUTE,minute+second/60.0,clockR-40)));
     QColor scolor(0xFF,0xFF,0xFF);
     QPen s(scolor);
     s.setWidth(3);
     painter.setPen(s);
      painter.drawLine(QLineF(clockCenter,calculatePoint(clockCenter,SECOND,second,clockR-10)));
      painter.restore();
}
void clock::paintEvent(QPaintEvent*){
     QPainter painter(this);
     Paint(painter,400,300,200);
     Paint(painter,1000,300,200);
     painter.drawRect(400-200,300-200,2*200,2*200);
     painter.drawEllipse(1000-200,300-200,2*200,2*200);
}
clock::~clock()
{
    delete Timer;
}
void clock::increaseByseconds(){
    increaseOneSecond();
    this->repaint();
}

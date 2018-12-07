#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include "baseclock.h"
#include<qpainter.h>
#include <QPointF>
#include<QTimer>
#include<QTime>
#include<cmath>
#define PI 3.1415926
namespace Ui {
class clock;
}

class clock : public QWidget , baseClock
{
    Q_OBJECT

public:
    explicit clock(QWidget *parent = nullptr);
    ~clock();
    void paintEvent(QPaintEvent*);
signals:
private slots:
    void increaseByseconds();
private:
    QTimer *Timer;
};

#endif // CLOCK_H

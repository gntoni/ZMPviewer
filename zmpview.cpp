#include "zmpview.h"
#include "ui_zmpview.h"
#include <QGraphicsWidget>
#include <vector>

zmpview::zmpview(TGauges *Gauges, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::zmpview)
{
    this->Gauges = Gauges;
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
}

zmpview::~zmpview()
{
    delete ui;
}


//class QGraphicsRectWidget : public QGraphicsWidget
//{
//public:
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
//               QWidget *)
//    {
//        painter->fillRect(rect(), Qt::blue);
//    }
//};

void zmpview::on_pushButton_clicked()
{
    double xpos = ui->xvalue->value();
    double ypos = ui->yvalue->value();
    int chvalue = ui->chvalue->value();
    double calib = ui->calibvalue->value();

    scene->addRect(xpos*20,ypos*20,50,100,QPen(Qt::black),QBrush(Qt::red));
    Tgauge gauge;
    gauge.xpos = xpos;
    gauge.ypos = ypos;
    gauge.channel = chvalue;
    gauge.K_calib = calib;
    Gauges->push_back(gauge);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->update();
}

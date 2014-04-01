#include "zmpview.h"
#include "ui_zmpview.h"
 #include <QGraphicsWidget>

zmpview::zmpview(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::zmpview)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
}

zmpview::~zmpview()
{
    delete ui;
}

class QGraphicsRectWidget : public QGraphicsWidget
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *)
    {
        painter->fillRect(rect(), Qt::blue);
    }
};

void zmpview::on_pushButton_clicked()
{
    double xpos = ui->xvalue->value();
    double ypos = ui->yvalue->value();
    //QGraphicsScene *scene = ui->graphicsView->scene();

    //QGraphicsRectWidget *button1 = new QGraphicsRectWidget;
    //button1->setX(xpos);
    //button1->setY(ypos);
    scene->addRect(xpos,ypos,50,50,QPen(Qt::black),QBrush(Qt::red));
    //scene->addItem(button1);
    //ui->graphicsView->scene()->addRect(xpos,ypos,50,50);
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->scene()->addItem(button1);
    ui->graphicsView->scene()->update();
}

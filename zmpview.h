#ifndef ZMPVIEW_H
#define ZMPVIEW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <stdlib.h>
#include "gauges.h"

namespace Ui {
class zmpview;
}

class zmpview : public QMainWindow
{
    Q_OBJECT

public:
    explicit zmpview(TGauges *Gauges, QWidget *parent = 0);
    ~zmpview();

private slots:
    void on_pushButton_clicked();

private:
    Ui::zmpview *ui;
    QGraphicsScene *scene;
    TGauges *Gauges;
};

#endif // ZMPVIEW_H

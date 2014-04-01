#ifndef ZMPVIEW_H
#define ZMPVIEW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <stdlib.h>

namespace Ui {
class zmpview;
}

class zmpview : public QMainWindow
{
    Q_OBJECT

public:
    explicit zmpview(QWidget *parent = 0);
    ~zmpview();

private slots:
    void on_pushButton_clicked();

private:
    Ui::zmpview *ui;
    QGraphicsScene *scene;
};

#endif // ZMPVIEW_H

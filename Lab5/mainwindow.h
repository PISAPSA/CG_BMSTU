#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QMouseEvent>
#include "list.h"
#include <QVector>
#include <QList>
#include <QPixmap>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void mousePressEvent(QMouseEvent *event);
    void on_addPointPushButton_clicked();
    void on_closePushButton_clicked();
    void on_fillPushButton_clicked();
    void on_clearPushButton_clicked();
    void on_setColorPushButton_clicked();

private:
    Ui::MainWindow *ui;

    bool closed;
    QVector<QPoint> points;
    QVector<QLine> edges;
    struct list* intersections[720];

    QPixmap pixmap;
    QImage image;
    const QColor defaultBoundColor = Qt::black;
    const QColor defaultFillColor = QColor(2, 2, 2);
    QColor fillColor;

    int start_point;

    int n_edges;
    enum DrawType {	none, horizontal, vertical, diagonal };
    void addPoint(const QPoint &point, DrawType drawType);
    void addEdge(const QLine &edge);
    void add_to_ygroup(const QLine &edge);

    void delay(int);
    void clearImage();
    void displayImage();
    void colorLabel();
};

#endif // MAINWINDOW_H

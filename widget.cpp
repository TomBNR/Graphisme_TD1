#include "widget.h"
#include "ui_widget.h"
//ouioui
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene=new QGraphicsScene;
    scene->setSceneRect(0,0,400,300);
    ui->maVue->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    ui->maVue->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonDessiner_clicked()
{
    QGraphicsRectItem *rectangle=new QGraphicsRectItem(10,10,100,50);
    QColor bleu(0,0,255);
    QPen contour(bleu);
    rectangle->setPen(contour);
    QBrush remplissage(bleu);
    rectangle->setBrush(remplissage);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(rectangle);
    QPolygon poly;
    poly.setPoints(3,33,0,65,47,1,46);
    QGraphicsPolygonItem *triangle=new QGraphicsPolygonItem(poly);
    QColor rouge(255,0,0);
    triangle->setPen(rouge);
    triangle->setBrush(bleu);
    triangle->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(triangle);
    QGraphicsEllipseItem *rond =new QGraphicsEllipseItem(50,50,50,50);
    QColor magenta(255,0,255);
    QColor vert(0,255,0);
    rond->setPen(magenta);
    rond->setBrush(vert);
    rond->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(rond);

    //Gradiants
    QGraphicsRectItem *  rectGradItem = new
    QGraphicsRectItem(10,20,300,100);
    QLinearGradient degrade(0,0,300,100);
    degrade.setColorAt(0,QColor(0,0,0));
    degrade.setColorAt(1,QColor(255,0,0));
    rectGradItem->setBrush(degrade);
    rectGradItem->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(rectGradItem);




}

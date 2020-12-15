#include "birditem.h"
#include <QTimer>

BirdItem::BirdItem(QPixmap pixmap) :
    wingPositon(WingPositon::Up),
    wingDirection(0)
{
    setPixmap(pixmap);

    QTimer * birdWingsTimer = new QTimer(this);
    connect(birdWingsTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });

    birdWingsTimer->start(80);

    groundPosition = scenePos().y() + 290;

    yAnimation = new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);

    yAnimation->start();
}

qreal BirdItem::rotation() const
{
    return m_rotation;
}

qreal BirdItem::y() const
{
    return m_y;
}

void BirdItem::setRotation(qreal rotation)
{
    m_rotation = rotation;
}

void BirdItem::setY(qreal y)
{
//    moveBy(0,y-m_y);
    m_y = y;
}

void BirdItem::updatePixmap()
{
    if(wingPositon == WingPositon::Middle)
    {
        if(wingDirection)
        {
            //Up
            setPixmap(QPixmap(":/new/prefix1/images/bird_blue_up.png"));
            wingPositon = WingPositon::Up;
            wingDirection = 0;
        } else
        {
            //down
            setPixmap(QPixmap(":/new/prefix1/images/bird_blue_down.png"));
            wingPositon = WingPositon::Down;
            wingDirection = 1;
        }
    } else
    {
        setPixmap(QPixmap(":/new/prefix1/images/bird_blue_middle.png"));
        wingPositon = WingPositon::Middle;
    }
}

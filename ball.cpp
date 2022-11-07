/****************
Section: ball.cpp
Author: Xueey
Email: xuey666@gmail.com
Description: Constructs the ball object
*****************/

#include"ball.h"
#include<ctime>
#include<QDebug>
#include<iostream>

using namespace std;

Ball::Ball():radius(50),speed(50),x(540),y(360)
{
    cout<<"Ball created."<<endl;
}

Ball::Ball(const Ball& b)
{
    x = b.x;
    y = b.y;
    radius = b.radius;
    speed = b.speed;
}

Ball::Ball(Ball&& b)
{
    x = b.x;
    y = b.y;
    radius = b.radius;
    speed = b.speed;
}

Ball::~Ball()
{
    cout<<"Ball deleted."<<endl;
}


void Ball::incre_speed(double x)
{
    speed *= (1+x);
}

double Ball::current_speed() const
{
    return speed;
}

void Ball::incre_size(double r)
{
    radius += sqrt(r);
}

/*
 Default params of player balls.
*/
void Ball::init()
{
    radius = 50;
    speed = 50;
    x = 540;
    y = 360;
}

/*
 Default params of enemy balls.
*/
EBall::EBall():radius(20),speed(50),x(20),y(20)
{
    color = QColor(rand()%255, rand()%255, rand()%255);
}

EBall::EBall(const EBall& b)
{
    x = b.x;
    y = b.y;
    radius = b.radius;
    speed = b.speed;
    color = b.color;
}

EBall::EBall(EBall&& b)
{
    x = b.x;
    y = b.y;
    radius = b.radius;
    speed = b.speed;
    color = b.color;
}


/*
 Adjust the birth of enemy balls.
*/
EBall::EBall(const Ball& p)
{
    color = QColor(rand()%255, rand()%255, rand()%255);

    bool a = rand()%2;
    bool b = rand()%2;

    if(a)
        x = rand()%(p.x-p.radius*3/2+1000)-1000;
    else
        x = rand()%(2000-p.x-p.radius*3/2)+p.x+p.radius*3/2;

    if(b)
        y = rand()%(p.y-p.radius*3/2+800)-800;
    else
        y = rand()%(1400-p.y-p.radius*3/2)+p.y+p.radius*3/2;

    radius = rand()%(p.radius) + 3/2*rand()%(p.radius);
}

EBall::~EBall()
{
    cout<<"EBall deleted."<<endl;
}


EBall &EBall::operator= (EBall b)
{
    std::swap(x, b.x);
    std::swap(y, b.y);
    std::swap(radius, b.radius);
    std::swap(color, b.color);

    return *this;
}


/*
  Enemy balls move stochastically.
*/
void EBall::random_move()
{

    switch(direction)
    {
    case 0:
    {
        goUp();
        break;
    }
    case 1:
    {
        goDown();
        break;
    }
    case 2:
    {
        goLeft();
        break;
    }
    case 3:
    {
        goRight();
        break;
    }
    case 4:
    {
        goUp();
        goLeft();
        break;
    }
    case 5:
    {
        goUp();
        goRight();
        break;
    }
    case 6:
    {
        goDown();
        goLeft();
        break;
    }
    case 7:
    {
        goDown();
        goRight();
        break;
    }
    default:
    {
        break;
    }
    }
    return;
}











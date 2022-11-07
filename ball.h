/****************
Section: ball.h
Author: Xueey
Email: xuey666@gmail.com
Description: Constructs the ball object
*****************/

#ifndef BALL_H
#define BALL_H

#include <cmath>
#include <QColor>

using namespace std;

class Ball{

private:
    //params
    int radius;
    int speed;
    int x;
    int y;

public:

    Ball();

    Ball(const Ball& b); //copy constructor

    Ball(Ball&& b); //move constructor

    ~Ball(); //destructor

    void init();

    void incre_speed(double x);

    double current_speed() const;

    void incre_size(double r);

    void goUp() { if(y>0) y -= speed/25; }

    void goDown(){ if(y<720-radius) y += speed/25; }

    void goLeft(){ if(x>0) x -= speed/25; }

    void goRight(){ if(x<1080-radius) x += speed/25; }


    friend class Widget;
    friend class EBall;

};


//Enemy Balls
class EBall : public Ball{

private:

    int radius;
    int speed;
    int x;
    int y;

    QColor color;

public:

    int direction = rand()%8;

    EBall();

    EBall(const EBall& b);

    EBall(EBall&& b);

    ~EBall();

    EBall(const Ball& p);

    EBall &operator=(EBall b);

    void random_move();

    void goUp(){ if(y>0) y -= 1;}

    void goDown(){ if(y<720-radius) y += 1; }

    void goLeft(){ if(x>0) x -= 1; }

    void goRight(){ if(x<1080-radius) x += 1; }

    friend class Widget;
};



#endif // BALL_H

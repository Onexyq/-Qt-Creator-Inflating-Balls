/****************
Section: widget.h
Author: Xueey
Email: xuey666@gmail.com
Description: Constructs behavior of the gameplay, including basic rules and actions of players.
*****************/

#ifndef WIDGET_H
#define WIDGET_H

#include "audiothread.h"
#include <QWidget>
#include <vector>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include "ball.h"
#include <QSound>
#include <QSoundEffect>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{

Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    ~Widget();

    void init();

protected:
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *e);

    void keyReleaseEvent(QKeyEvent *e);

private slots:

    void Player_Move();

    void Player2_Move();

    void generate_balls();

    void start_moving();

    void change_direction();

    void checkState();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_single_clicked();

    void on_pushButton_double_clicked();

private:
    //audio
    static void absorbSound();

private:
    Ui::Widget *ui;

    AudioThread* audio;

    QTimer *canvasTimer;
    QTimer *gameTimer;
    QTimer *repeatTimer;
    QTimer *movementTimer;

    Ball player;
    Ball player2;

    QString dir;

    int gamemode;   //single-player=1, two-player=2;

    bool is_pressing(Qt::Key k);

    vector<Qt::Key> pressedkeys;

    vector<EBall> Enemy_Balls;

    int score = 0;
    int score2 = 0;

};

#endif // WIDGET_H

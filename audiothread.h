/****************
Section: audiothread.h
Author: Xueey
Email: xuey666@gmail.com
Description: audio control module
*****************/

#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QObject>
#include <QSoundEffect>
#include <QThread>

class AudioThread : public QObject
{
    Q_OBJECT
public:
    explicit AudioThread(QObject *parent = nullptr);
    ~AudioThread();

signals:
    void doPlay();

public slots:
    void play();

private:

    QSoundEffect* m_pSoundEffect;

    QThread* m_pThread;

};

#endif // AUDIOTHREAD_H

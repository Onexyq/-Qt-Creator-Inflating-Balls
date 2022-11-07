/****************
Section: audiothread.cpp
Author: Xueey
Email: xuey666@gmail.com
Description: audio control module
*****************/

#include "audiothread.h"

AudioThread::AudioThread(QObject *parent)
    : QObject{parent}
{
    m_pThread = new QThread();
    m_pSoundEffect = new QSoundEffect();
    m_pSoundEffect->moveToThread(m_pThread);
    connect(this, SIGNAL(doPlay()), m_pSoundEffect, SLOT(play()));
    m_pThread->start();
}

AudioThread::~AudioThread()
{
    if(m_pThread->isRunning())
    {
        //m_pThread->terminate(); //insafe
        m_pThread->quit();
        m_pThread->wait();
    }
}

void AudioThread::play()
{
    if(!m_pSoundEffect->isPlaying())
    {
        m_pSoundEffect->setSource(QUrl::fromLocalFile("../InflatingBalls/Sounds/eat.wav"));
        m_pSoundEffect->setLoopCount(1);
        m_pSoundEffect->setVolume(0.25f);  //volume between 0~1
        emit this->doPlay();
    }
}


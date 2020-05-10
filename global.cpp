#include "global.h"

void Couper()
{
    m_player->stop();
}

void Fondu()
{
    m_player->setVolume(m_player->volume()-1);
    if(m_player->volume() > 0)
        QTimer::singleShot(temps_fondu*10, &Fondu);
    else
        Couper();
}

void Jouer(QUrl url){
    m_player->setMedia(url);
    m_player->setVolume(100);
    m_player->play();
}

void Jouer(const char * url){
    Jouer(QUrl(url));
}

void Jouer(QString url){
    Jouer(QUrl::fromLocalFile(url));
}

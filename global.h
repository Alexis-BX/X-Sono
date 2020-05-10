#ifndef GLOBAL_H
#define GLOBAL_H

#include <QMediaPlayer>
#include <QTimer>
#include <QtWidgets> // imports quite a few Qt libs

class QMediaPlayer;
extern QMediaPlayer* m_player;

const static int temps_fondu{5};

void Couper();
void Fondu();
void Jouer(QUrl url);
void Jouer(const char * url);
void Jouer(QString url);

#endif // GLOBAL_H

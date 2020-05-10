#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include "global.h"
#include "mychamp.h"

class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    FenPrincipale(int n);

    void keyPressEvent(QKeyEvent * event);

private slots:
    void JouerLocal(int i);

    void durationChanged(int duration);
    void positionChanged(int progress);
    void seek(int seconds);

    void Reinit();
    void CouperLocal();
    void FonduLocal();

private:
    int nbHymnes, m_duration;
    const static int temps_fondu{5}, nbUsuels{14};

    const char *urls[nbUsuels], *bouttons[nbUsuels];

    QVBoxLayout *boxes[nbUsuels], *layBouttons, *layC, *layR, *layMarches;

    MyChamp** m_hymnes;

    QGroupBox *m_pistes, *m_usuels, *m_ordres, *m_accomp, *m_regl, *m_marches;

    QPushButton *m_reinit, *m_quit;

    QSlider *m_slider;

    QLabel *m_labelDuration;

    void updateDurationInfo(int currentInfo);

    void setArrays();
};

#endif // FENPRINCIPALE_H

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "global.h"
#include "fenprincipale.h"

class affichage : public QWidget
{
    Q_OBJECT
public:
    affichage();

public slots:
    void Valider();

private:
    QLabel* m_texte;
    QSpinBox* m_n;
    QPushButton* m_ok;
};

#endif // AFFICHAGE_H

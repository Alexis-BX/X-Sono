#include "affichage.h"

affichage::affichage()
{
    this->setWindowTitle("Réglages");

    m_texte = new QLabel("Nombre d'hymnes : ");
    m_n = new QSpinBox();
    m_ok = new QPushButton("&Valider");
    m_n->setValue(1);                           //Par défaut

    QHBoxLayout* layN = new QHBoxLayout();
    layN->addWidget(m_texte);
    layN->addWidget(m_n);
    QVBoxLayout* lay = new QVBoxLayout();
    lay->addLayout(layN);
    lay->addWidget(m_ok);
    this->setLayout(lay);

    connect(m_ok,SIGNAL(clicked(bool)),this,SLOT(Valider()));
}

void affichage::Valider()
{
    FenPrincipale* fen = new FenPrincipale(m_n->value());
    fen->show();
    this->close();
}

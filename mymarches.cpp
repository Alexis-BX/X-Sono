#include "mymarches.h"

mymarches::mymarches(QString m_nom)
{
    m_lire = new QPushButton(m_nom);
    m_couper = new QPushButton("Couper");
    m_fondu = new QPushButton("Fondu");

    QHBoxLayout* lay = new QHBoxLayout();
    lay->addWidget(m_lire);
    lay->addWidget(m_couper);
    lay->addWidget(m_fondu);
    this->setLayout(lay);

    connect(m_lire,SIGNAL(clicked(bool)),this,SLOT(Joue()));
    connect(m_couper,SIGNAL(clicked(bool)),this,SLOT(Coupe()));
    connect(m_fondu,SIGNAL(clicked(bool)),this,SLOT(Fondu()));
}

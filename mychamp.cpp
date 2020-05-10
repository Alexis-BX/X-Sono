#include "mychamp.h"

MyChamp::MyChamp(QString nom){
    QHBoxLayout* lay = new QHBoxLayout();

    QLabel * m_nom = new QLabel(nom);
    lay->addWidget(m_nom);

    m_piste = new MyLineEdit();
    lay->addWidget(m_piste);

    QPushButton *m_cherche = new QPushButton("Parcourir");
    lay->addWidget(m_cherche);
    connect(m_cherche,SIGNAL(clicked(bool)),m_piste,SLOT(Recherche()));

    QPushButton *m_lire = new QPushButton("Lire");
    lay->addWidget(m_lire);
    connect(m_lire,SIGNAL(clicked(bool)),m_piste,SLOT(JouerLocal()));

    this->setLayout(lay);
}

void MyChamp::Reinit(){
    m_piste->clear();
}

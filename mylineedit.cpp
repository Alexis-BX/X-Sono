#include "mylineedit.h"

MyLineEdit::MyLineEdit()
{
    m_disque = new QDirModel();
    m_vue = new QTreeView();
    m_vue->setModel(m_disque);
    m_vue->setRootIndex(m_disque->index("./Hymnes/"));
    m_vue->setIndentation(5); //Condense l'affichage en réduisant l'indentation

    m_affichage = new QWidget();
    m_selec = new QPushButton("Sélectionner");
    m_quit = new QPushButton("Annuler");

    QHBoxLayout* layB = new QHBoxLayout();
    layB->addWidget(m_selec);
    layB->addWidget(m_quit);
    QVBoxLayout* lay = new QVBoxLayout();
    lay->addWidget(m_vue);
    lay->addLayout(layB);
    m_affichage->setLayout(lay);

    connect(m_selec,SIGNAL(clicked(bool)),this,SLOT(Selection()));
    connect(m_quit,SIGNAL(clicked(bool)),m_affichage,SLOT(close()));
}

void MyLineEdit::Recherche()
{
    m_affichage->show();
}

void MyLineEdit::Selection()
{
    QItemSelectionModel* m_selection = m_vue->selectionModel();
    this->setText(m_disque->filePath(m_selection->currentIndex()));
    m_affichage->close();
}

void MyLineEdit::JouerLocal(){
    if(this->text()!=""){
        Jouer(QUrl::fromLocalFile(this->text()));
    }
}

#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include "global.h"

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit();

public slots:
    void Recherche();
    void Selection();
    void JouerLocal();

private:
    const static int temps_fondu{5};

    QDirModel* m_disque;
    QTreeView* m_vue;

    QWidget* m_affichage;
    QPushButton* m_selec;
    QPushButton* m_quit;
};

#endif // MYLINEEDIT_H

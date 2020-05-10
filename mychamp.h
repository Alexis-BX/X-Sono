#ifndef MYCHAMP_H
#define MYCHAMP_H

#include "global.h"
#include "mylineedit.h"

class MyChamp : public QWidget
{
    Q_OBJECT
public:
    MyChamp(QString nom);
    void Reinit();

private:
    MyLineEdit* m_piste;
};

#endif // MYCHAMP_H

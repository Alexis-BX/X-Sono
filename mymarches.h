#ifndef MYMARCHES_H
#define MYMARCHES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class mymarches : public QWidget
{
    Q_OBJECT
public:
    mymarches(QString m_nom, QUrl);

private:
    QPushButton* m_lire;
    QPushButton* m_couper;
    QPushButton* m_fondu;
};

#endif // MYMARCHES_H

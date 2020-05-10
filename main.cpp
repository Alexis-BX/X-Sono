#include <QApplication>
#include "affichage.h"

int main(int argc, char** argv){
    QApplication app(argc,argv);

    affichage* fen = new affichage();
    fen->show();

    return app.exec();
}

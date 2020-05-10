#include "fenprincipale.h"

QMediaPlayer* m_player;

FenPrincipale::FenPrincipale(int n){
    m_player = new QMediaPlayer();

    this->setWindowTitle("X Sono");

    // genere l'integralite de la boite avec les hymnes
    nbHymnes = n;
    m_hymnes = new MyChamp*[nbHymnes];
    for(int i=0; i<nbHymnes; i++){
        m_hymnes[i] = new MyChamp("Hymne " + QString::number(i+1) + " : ");
    }

    m_pistes = new QGroupBox("Pistes");
    QVBoxLayout* layPistes = new QVBoxLayout();
    for(int i=0; i<nbHymnes; i++){
        layPistes->addWidget(m_hymnes[i]);
    }
    m_pistes->setLayout(layPistes);

    // tout les bouttons (hors des hymes, quit et reinit)
    m_usuels = new QGroupBox("Céleustique");
    m_ordres = new QGroupBox("Ordres");
    m_accomp = new QGroupBox("Accompagnements");
    m_regl = new QGroupBox("Réglages");
    m_marches = new QGroupBox("Marches");

    setArrays();

    for (int i=0; i<nbUsuels; i++){
        QPushButton * tmp = new QPushButton(bouttons[i]);
        boxes[i]->addWidget(tmp);

        if (i==7){
            connect(tmp,SIGNAL(clicked(bool)), this, SLOT(CouperLocal()));
        }
        else if(i==8){
            connect(tmp,SIGNAL(clicked(bool)), this, SLOT(FonduLocal()));
        }
        else{
            QSignalMapper* signalmapper = new QSignalMapper();
            connect (tmp, SIGNAL(clicked(bool)), signalmapper, SLOT(map())) ;
            signalmapper -> setMapping (tmp, i);
            connect (signalmapper , SIGNAL(mapped(int)), this, SLOT(JouerLocal(int)));
        }
    }

    QGridLayout* layOrdres = new QGridLayout();

    m_ordres->setLayout(layBouttons);
    layOrdres->addWidget(m_ordres,0,0,2,1);
    m_accomp->setLayout(layC);
    layOrdres->addWidget(m_accomp,0,1,1,1);
    m_regl->setLayout(layR);
    layOrdres->addWidget(m_regl,1,1,1,1);
    m_marches->setLayout(layMarches);
    layOrdres->addWidget(m_marches,0,2,2,1);
    m_usuels->setLayout(layOrdres);

    // cree quit et reinit
    QHBoxLayout* layBas = new QHBoxLayout();

    m_reinit = new QPushButton("Réinitialiser");
    layBas->addWidget(m_reinit);
    connect(m_reinit,SIGNAL(clicked(bool)),this,SLOT(Reinit()));

    m_quit = new QPushButton("Quitter");
    layBas->addWidget(m_quit);
    connect(m_quit,SIGNAL(clicked(bool)),this,SLOT(close()));

    // slider et temps
    connect(m_player, &QMediaPlayer::durationChanged, this, &FenPrincipale::durationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &FenPrincipale::positionChanged);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setRange(0, int(m_player->duration()) / 1000);

    m_labelDuration = new QLabel(this);
    connect(m_slider, &QSlider::sliderMoved, this, &FenPrincipale::seek);

    QHBoxLayout *layHaut = new QHBoxLayout();
    layHaut->addWidget(m_slider);
    layHaut->addWidget(m_labelDuration);

    // Layout general
    QVBoxLayout* layGen = new QVBoxLayout();
    layGen->addLayout(layHaut);
    layGen->addWidget(m_pistes);
    layGen->addWidget(m_usuels);
    layGen->addLayout(layBas);

    this->setLayout(layGen);

    // pour display la bar des le debut
    JouerLocal(0);Couper();

    setFocus();
}

void FenPrincipale::keyPressEvent(QKeyEvent * event){
    switch (event->key()) {
        case Qt::Key_G:
            JouerLocal(0);
            break;
        case Qt::Key_D:
            JouerLocal(1);
            break;
        case Qt::Key_B:
            if (event->modifiers() != Qt::NoModifier) JouerLocal(3);
            else JouerLocal(2);
            break;
        case Qt::Key_M:
            if (event->modifiers() != Qt::NoModifier) JouerLocal(4);
            break;
        case Qt::Key_C:
            JouerLocal(5);
            break;
        case Qt::Key_R:
            JouerLocal(6);
            break;
        case Qt::Key_Space:
            if (event->modifiers() != Qt::NoModifier) Fondu();
            else Couper();
            break;
        case Qt::Key_1:
            JouerLocal(9);
            break;
        case Qt::Key_2:
            JouerLocal(10);
            break;
        case Qt::Key_3:
            JouerLocal(11);
            break;
        case Qt::Key_4:
            JouerLocal(12);
            break;
        case Qt::Key_5:
            JouerLocal(13);
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            setFocus();
            break;
        case Qt::Key_Escape:
            Reinit();
            break;
    }
}

void FenPrincipale::Reinit(){
    for(int i=0; i<nbHymnes; i++){
        m_hymnes[i]->Reinit();
    }
    setFocus();
}

void FenPrincipale::JouerLocal(int i){
    Jouer(QUrl(urls[i]));
    setFocus();
}

void FenPrincipale::CouperLocal(){Couper(); setFocus();}

void FenPrincipale::FonduLocal(){Fondu(); setFocus();}

void FenPrincipale::setArrays(){
    const char * setBouttons[nbUsuels]={" Garde à vous (g)",
                                  "   Au drapeau  (d)",
                                  "Ouvrez le ban (b)",
                                  "Fermez le ban (B)",
                                  "    Aux morts    (M)",
                                  "Aux champs (c)",
                                  "    Rappel     (r)",
                                  "Couper ( )",
                                  "Fondu (^ )",
                                  "                9BIMa               (1)",
                                  "      Entre terre et mer      (2)",
                                  "           Robert Bruce         (3)",
                                  "Marche des commandos (4)",
                                  "             La Galette            (5)"};
    for (int i=0; i<nbUsuels; i++){bouttons[i] = setBouttons[i];}

    const char * setUrls[nbUsuels] = {"qrc:/mp3files/Celeustique/Garde_a_vous.mp3",
                             "qrc:/mp3files/Celeustique/Au_drapeauSEUL.mp3",
                             "qrc:/mp3files/Celeustique/Ouvrez_le_ban.mp3",
                             "qrc:/mp3files/Celeustique/Fermez_le_ban.mp3",
                             "qrc:/mp3files/Celeustique/Aux_morts.mp3",
                             "qrc:/mp3files/Celeustique/Aux_champs.mp3",
                             "qrc:/mp3files/Celeustique/Rappel.mp3",
                             "couper",
                             "fondu",
                             "qrc:/mp3files/Marches/9e_BIMa.mp3",
                             "qrc:/mp3files/Marches/Entre_Terre_et_Mer.mp3",
                             "qrc:/mp3files/Marches/Robert_Bruce.mp3",
                             "qrc:/mp3files/Marches/Marche_des_commandos.mp3",
                             "qrc:/mp3files/Marches/La_Galette.mp3"};
    for (int i=0; i<nbUsuels; i++){urls[i] = setUrls[i];}

    layBouttons = new QVBoxLayout();
    layC = new QVBoxLayout();
    layR = new QVBoxLayout();
    layMarches = new QVBoxLayout();

    QVBoxLayout * setBoxes[nbUsuels] = {
        layBouttons, layBouttons, layBouttons, layBouttons, layBouttons,
        layC, layC, layR, layR,
        layMarches, layMarches, layMarches, layMarches, layMarches};
    for (int i=0; i<nbUsuels; i++){boxes[i] = setBoxes[i];}
}

void FenPrincipale::durationChanged(int duration){
    m_duration = duration / 1000;
    m_slider->setMaximum(m_duration);
}

void FenPrincipale::positionChanged(int progress){
    if (!m_slider->isSliderDown())
        m_slider->setValue(progress / 1000);

    updateDurationInfo(progress / 1000);
}

void FenPrincipale::seek(int seconds){
    m_player->setPosition(seconds * 1000);
}

void FenPrincipale::updateDurationInfo(int currentInfo){
    QString tStr;
    if (currentInfo || m_duration) {
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
            currentInfo % 60, (currentInfo * 1000) % 1000);
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
            m_duration % 60, (m_duration * 1000) % 1000);

        tStr = currentTime.toString("mm:ss") + " / " + totalTime.toString("mm:ss");
    }
    m_labelDuration->setText(tStr);
}

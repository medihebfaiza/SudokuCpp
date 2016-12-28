#include "fenetre.h"
#include <QFile>       // Pour utiliser le fichier
#include <QString>     // Stocke le contenu du fichier
#include <QTextStream>

fenetre::fenetre() :
    QWidget()
{
    L = new QGridLayout;

    GB = new QGroupBox("",this);
    GB->setLayout(L);
    GB->setFixedSize(500,500);

    label = new QLabel**[16];
    spin = new QLineEdit**[16];
        for(int i=0;i<16;i++)
        {
            label[i]=new QLabel*[16];
            spin[i]=new QLineEdit*[16];
            for(int j=0;j<16;j++){
                label[i][j]=NULL;
                spin[i][j]=NULL;
            }
        }
     ancTai=16;



        this->setFixedSize(760,540);

        gen = new QPushButton("Générer",this);
        gen->setAutoFillBackground(true);
        gen->setStyleSheet("background-color: #4094FD ; "
                           "border-radius: 10px ; "
                           "font : bold 14px ; "
                           "color: rgb(255, 255, 255)");
        gen->setFixedSize(220,60);
        gen->move(510,10);
        QObject::connect(gen, SIGNAL(clicked()), this, SLOT(generer()));

        res = new QPushButton("Résoudre",this);
        res->setAutoFillBackground(true);
        res->setStyleSheet("background-color: #FF564B ; "
                           "border-radius: 10px ; "
                           "font : bold 14px ; "
                           "color: rgb(255, 255, 255)");
        res->setFixedSize(220,60);
        res->move(510,80);
        QObject::connect(res, SIGNAL(clicked()), this, SLOT(resoudre()));


        val = new QPushButton("Valider",this);
        val->setAutoFillBackground(true);
        val->setStyleSheet("background-color: #68FF57 ;"
                           "border-radius: 10px ; "
                           "font : bold 14px ; "
                           "color: rgb(255, 255, 255)");
        val->setFixedSize(220,60);
        val->move(510,150);
        QObject::connect(val, SIGNAL(clicked()), this, SLOT(valider()));

        sauv = new QPushButton("Sauvegarder",this);
        sauv->setAutoFillBackground(true);
        sauv->setStyleSheet("background-color: #E8BD41 ;"
                            "border-radius: 10px; "
                            "font : bold 14px ; "
                            "color: rgb(255, 255, 255)");
        sauv->setFixedSize(220,60);
        sauv->move(510,220);
        QObject::connect(sauv, SIGNAL(clicked()), this, SLOT(sauvegarder()));

        cha = new QPushButton("Charger",this);
        cha->setAutoFillBackground(true);
        cha->setStyleSheet("background-color: #A541E8 ; "
                           "border-radius: 10px ; "
                           "font : bold 14px ; "
                           "color: rgb(255, 255, 255)");
        cha->setFixedSize(220,60);
        cha->move(510,290);
        QObject::connect(cha, SIGNAL(clicked()), this, SLOT(charger()));

        Dif = new QGroupBox("Difficultés",this);

        fac = new QRadioButton("Facile");
        med = new QRadioButton("Moyen");
        diff = new QRadioButton("Difficile");

        Dif->setFixedSize(220,60);
        Dif->move(510,360);

        QHBoxLayout *vbox = new QHBoxLayout;

        vbox->addWidget(fac);
        vbox->addWidget(med);
        vbox->addWidget(diff);

        Dif->setLayout(vbox);

        tai = new QGroupBox("Taille",this);

        qua = new QRadioButton("4x4");
        neu = new QRadioButton("9x9");
        sei = new QRadioButton("16x16");

        tai->setFixedSize(220,60);
        tai->move(510,430);

        QHBoxLayout *vbox2 = new QHBoxLayout;

        vbox2->addWidget(qua);
        vbox2->addWidget(neu);
        vbox2->addWidget(sei);

        tai->setLayout(vbox2);

        fac->setChecked("true");

        qua->setChecked("true");
}

void fenetre::remplir()
{
    int t=g->getTaille();
    int tt=500/t-10;
    QString s = "";

    for(int i=0;i<ancTai;i++){
        for(int j=0;j<ancTai;j++){
            if(label[i][j]!=NULL){
                label[i][j]->~QLabel();
            }
            if(spin[i][j]!=NULL){
                spin[i][j]->~QLineEdit();
            }
        }
    }


   t=g->getTaille();
   ancTai = t ;
    label = new QLabel**[t];
    spin = new QLineEdit**[t];
        for(int i=0;i<t;i++)
        {
            label[i]=new QLabel*[t];
            spin[i]=new QLineEdit*[t];
            for(int j=0;j<t;j++){
                label[i][j]=NULL;
                spin[i][j]=NULL;
            }
        }

    for(int i=0;i<t;i++)
    {
        for(int j=0;j<t;j++)
        {
            s = QString::number(g->get(j,i));
            QFont font;

            if(g->get(j,i)!=0){
                    label[i][j]=new QLabel;
                    //taille police
                    font = label[i][j]->font();
                    font.setPointSize(tt-12);
                    label[i][j]->setFont(font);
                    //taille et aspect widget

                    label[i][j]->setFrameStyle(QFrame::Box | QFrame::Plain);//bordure des Qlabels
                    label[i][j]->setFixedWidth(tt);//Tailles des
                    label[i][j]->setFixedHeight(tt);// Qlabels
                    label[i][j]->setText(s);
                    L->addWidget(label[i][j],i+1,j+0);
            }
            else{
                    spin[i][j]=new QLineEdit;
                    //taille police
                    font = spin[i][j]->font();
                    font.setPointSize(tt-12);
                    spin[i][j]->setFont(font);
                    //taille widget
                    spin[i][j]->setFixedWidth(tt);//Tailles des
                    spin[i][j]->setFixedHeight(tt);// Qlabels

                    spin[i][j]->setText("");
                    L->addWidget(spin[i][j],i+1,j+0);
                }
        }
    }
}

void fenetre::sauvegarder()
{
    QString chemin="sauvegarde.sudoku";

    QFile fichier(chemin);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream flux(&fichier);

    flux << g->getTaille() << "|";

    for(size_t j=0;j<g->getTaille();j++)
    {
        for(size_t i=0;i<g->getTaille();i++)
        {
            if(g->get(i,j)!=0)
                flux << label[j][i]->text() << ",";

            else
                flux << spin[j][i]->text() << ";";
        }
    }
    fichier.close();

}

bool fenetre::valider()
{
    int n=0;
    QString s="";
    for(size_t i=0;i<g->getTaille();i++){
        for(size_t j=0;j<g->getTaille();j++){
            if(spin[i][j]!=NULL){
                s=spin[i][j]->text();
                if(!g->onPeutMettre(s.toInt(),j,i)){
                    spin[i][j]->setStyleSheet("background: red");
                    n++;
                }
                else
                    spin[i][j]->setStyleSheet("background: green");
            }
        }
    }
    if(n==0)
        QMessageBox::information(this, "Félicitations", "Félicitations ! Vous avez réussi");
    return !n;
}

void fenetre::charger()
{
    QString chemin="sauvegarde.sudoku";

    QFile fichier(chemin);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream flux(&fichier);

    int t;
    int tt;
    QString s = "";

    for(int i=0;i<ancTai;i++){
        for(int j=0;j<ancTai;j++){
            if(label[i][j]!=NULL){
                label[i][j]->~QLabel();
            }
            if(spin[i][j]!=NULL){
                spin[i][j]->~QLineEdit();
            }
        }
    }

    char c ;
    flux>>c ;
    t = (size_t)c - (size_t)'0' ; //on charge la taille
    flux>>c ;
    if (c!='|') {
      t = 16 ;
    }

    g = new Grille(t) ;

    ancTai = t ;
    label = new QLabel**[t];
    spin = new QLineEdit**[t];
        for(int i=0;i<t;i++){
            label[i]=new QLabel*[t];
            spin[i]=new QLineEdit*[t];
            for(int j=0;j<t;j++){
                label[i][j]=NULL;
                spin[i][j]=NULL;
            }
        }

    tt = 500/t-10;

    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            QFont font;
            flux>>c ;
            while ((c != ',')&&(c != ';')) {
               s += c ;
               flux>>c ;
            }

            if(c==','){
                    label[i][j]=new QLabel;
                    //taille police
                    font = label[i][j]->font();
                    font.setPointSize(tt-12);
                    label[i][j]->setFont(font);
                    //taille et aspect widget

                    label[i][j]->setFrameStyle(QFrame::Box | QFrame::Plain);//bordure des Qlabels
                    label[i][j]->setFixedWidth(tt);//Tailles des
                    label[i][j]->setFixedHeight(tt);// Qlabels
                    label[i][j]->setText(s);
                    L->addWidget(label[i][j],i+1,j+0);

                    g->set(s.toInt(0,10),i,j) ;
            }
            else{
                    spin[i][j]=new QLineEdit;
                    //taille police
                    font = spin[i][j]->font();
                    font.setPointSize(tt-12);
                    spin[i][j]->setFont(font);
                    //taille widget
                    spin[i][j]->setFixedWidth(tt);//Tailles des
                    spin[i][j]->setFixedHeight(tt);// Qlabels

                    spin[i][j]->setText(s);
                    L->addWidget(spin[i][j],i+1,j+0);
                }
            s = "";
        }
    }

  fichier.close();

}

void fenetre::generer()
{
    size_t taille, niveau;

    if(neu->isChecked())
        taille = 9;
    if(sei->isChecked())
        taille = 16 ;
    if(qua->isChecked())
        taille = 4 ;

    if(fac->isChecked())
        niveau = 1;
    if(med->isChecked())
        niveau = 2;
    if(diff->isChecked())
        niveau = 3;

    delete[] g ;
    g = s.genererSudoku(taille,niveau) ;
    this->remplir();
}

void fenetre::resoudre()
{
    s.resoudre(g);
    this->remplir();
}

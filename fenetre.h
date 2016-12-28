#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include "grille.h"
#include "sudoku.h"
#include <QtWidgets>
#include <QFile>       // Pour utiliser le fichier
#include <QString>
#include <QTextStream>


/**
 * définition de la classe fenetre
 *
 * @file fenetre.h
 * @author ABBAS M'hamad
 */
class fenetre : public QWidget
{
    Q_OBJECT

private:
    QLabel ***label; //tableau de QLabel (cases non trouées) pour remplir le QGridLayout
    QLineEdit ***spin; //tableau de QLineEdit (case trouées) pour remplir le QGridLayout
    QGridLayout *L; //Widget en forme de tableau pour représenter la grille de sudoku

    QGroupBox *GB; //Widget prenant simplement le QGridLayout

    QGroupBox *Dif;

    QRadioButton *fac;
    QRadioButton *med;
    QRadioButton *diff;

    QGroupBox *tai;

    QRadioButton *qua;
    QRadioButton *neu;
    QRadioButton *sei;

    QPushButton *gen;
    QPushButton *res; //Bouton lié à resoudre()
    QPushButton *val; //Bouton lié à valider()
    QPushButton *sauv; //Bouton lié à sauvegarder()
    QPushButton *cha; //Bouton lié à charger()

public:

     Grille* g; // pointeur vers une grille
     Sudoku s ;
     int ancTai;
    /**
     * Créer une instance de fenêtre
    */
    fenetre();

    /**
     * Remplit L (QGridLayout) avec le contenu de g (instance de Grille)
    */
    void remplir(); //effacer les anciens widgets

public slots:

    /**
     * Sauvegarde le contenu du sudoku en cours
     * Dans un fichier text
    */
    void sauvegarder();

    /**
     * Vérifie les cases remplies par l'utilisateur
     *
     * @return
     *      false s'il y a des erreurs sinon true
    */
    bool valider();//à revoir

    /**
     * Charge le dernier sudoku
     * A partir d'un fichier text
    */
    void charger();

    /**
     * Résout le Sudoku en cours
    */
    void resoudre();

    /**
     * Genere un nouveau sudoku
    */
    void generer();
};

#endif // FENETRE_H

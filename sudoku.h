#ifndef SUDOKU
#define SUDOKU
#include <iostream>
#include <cstdlib>
#include "grille.h"

/**
 * Définition de la classe sudoku
 *
 * @file sudoku.h
 * @author FAIZA Mohamed Iheb & SADOUIOUI El Khamis
*/
class Sudoku{
  public :

    /**
     * Résout une grille de sudoku
     * @param grille
     *        la grille à resoudre
     * @return
     *  Vrai si la grille est résolue à la fin et faux sinon
    */
    bool resoudre(Grille* grille) const ;

    /**
     * Essaye de résoudre la grille en mettant dans chaque case la seule valeur possible si il existe une seule
     * @param grille
     *        la grille à resoudre
     * @return
     *  Vrai si la grille est résolue à la fin et faux sinon
    */
    bool resoudreBetement(Grille* grille) const ;

    /**
     * Résout la grille avec la méthode du BackTracking classique à partir d'une position
     * @param grille
     *        la grille à resoudre
     * @return
     *  Vrai si la grille est résolue à la fin et faux sinon
    */
    bool backTrackSolve(Grille* board, size_t debx, size_t deby) const ;


    /**
     * Génére une grille de sudoku résolue (compléte et valide)
     *
     * @param grille
     *  Pointeur vers la grille
    */
    void genererSolutionAlea(Grille* grille) const ;

    /**
     * vérifie si une grille est soluble (on utilisant seulement resoudreBetement par défaut)
     *
     * @param grille
     *  la grille qu'on veut vérifier
     * @param BetementSeulement
     *  mis à vrai si on veut utiliser que la méthode resoudreBetement()
     * @return
     *  soluble
    */
    bool onPeutResoudre(Grille grille, bool BetementSeulement = true) const ;

    /**
     * Vérifie si on peut resoudre la grille en utilisant resoudreBetement si on en enléve un element particulier
     * tout en gardant une solution unique
     *
     * @param grille
     *        la grille qu'on veut résoudre
     * @param x, y
     *        Coordonnées de l'élément qu'on veut enlever
     *
     * @return
     *  soluble
    */
    bool onPeutTrouer(Grille* grille, size_t x, size_t y) const ;

    /**
     * Efface selon un niveau de difficulté donné un certain nombre de cases d'une grille compléte pour la rendre jouable
     *
     * @param grille
     *  la grille qu'on veut trouer
     * @param niveau
     *  le niveau de difficulté de la grille
     *
     * @return
     *  tr le nombre des troues qu'on a réussit à faire
    */
    size_t trouer(Grille* grille, const size_t niveau) const ;

    /**
     * Génére un grille de sudoku jouable avec une certaine taille (4, 9, 16) et une cetaine difficulté (1 facile, 2 moyenne, 3 difficile)
     *
     * @param taille
     *        la taille de la grille à générer
     * @param niveau
     *        le niveau de difficulté de la grille
     * @return
     *  pointeur vers la grille générée
    */
    Grille* genererSudoku(size_t taille, size_t niveau) const ;
} ;


#endif

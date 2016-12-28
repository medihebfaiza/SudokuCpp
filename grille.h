#ifndef GRILLE
#define GRILLE
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>

/**
 * définition de la classe grille
 *
 * @file grille.h
 * @author FAIZA Mohamed Iheb & SADOUIOUI El Khamis
 */
class Grille{
   private :
   size_t taille ;
   size_t** M_grille ;

   /**
    * vérifie si l'élément e n'existe pas dans la ligne y
    * @param e
    *        nombre à vérifier
    * @param x
    *        numero de la colonne
    * @param y
    *        numero de la ligne
    * @return
    *  False si e existe dans la ligne y et True sinon
   */
   bool verifHorizontal(size_t x, size_t y, size_t e) const ;

   /**
    * vérifie si l'élément e n'existe pas dans la colonne x
    * @param e
    *        nombre à vérifier
    * @param x
    *        numero de la colonne
    * @param y
    *        numero de la ligne
    * @return
    *  False si e existe dans la colonne x et True sinon
   */
   bool verifVertical(size_t x, size_t y, size_t e) const ;

   /**
    * vérifie si l'élément e n'existe pas dans le bloc
    * @param e
    *        nombre à vérifier
    * @param x
    *        numero de la colonne
    * @param y
    *        numero de la ligne
    * @return
    *  False si e existe dans le block y et True sinon
   */
   bool verifBloc(size_t x, size_t y, size_t e) const ;

   public :
      /**
       * Crée une instance de Grille
      */
      Grille() ;

      /**
       * Crée une grille de taille t
       * @param t
       *        taille de la grille
      */
      Grille(const size_t t) ;

      /**
       * Crée une instance de la classe Grille par copie à partir d'une grille
       *
       * @param grille
       *        la grille qu'on veut copier
       */
      Grille(const Grille& grille) ;

      /**
       * Renvoie la taille de la grille
       * @return
       *  taille de la grille
      */
      size_t getTaille() const ;

      /**
        * Modifie la taille de la grille
        * @param s
        *        nouvelle taille de la grille
      */
      void setTaille(const size_t t) ;

      /**
       * Renvoie la valeur de la position [y,x] dans la grille
       * @param x
       *        numéro de la colonne
       * @param y
       *        numéro de la ligne
       * @return
       *  la valeur de la position [y,x]
      */
      size_t get(const size_t x, const size_t y) const ;

      /**
       * Met la valeur e dans la case [y,x]
       * @param x
       *        numéro de la colonne
       * @param y
       *        numéro de la ligne
       * @param e
       *        le nombre à mettre
      */
      void set(const size_t e, const size_t x, const size_t y) ;

      /**
       * Enleve la valeur de la case [y,x], la met à zero
       * @param x
       *        numéro de la colonne
       * @param y
       *        numéro de la ligne
      */
      void enlever(const size_t x, const size_t y) ;

      /**
       * Vide la grille, met toutes les cases à zero
      */
      void vider() ;

      /**
       * Vérifie si la grille est pleine
       * @return
       *  Vrai si elle est pleine et faux sinon
      */
      bool pleine() const ;

      /**
       * Vérifie si on peut mettre e dans la case [y,x] sans causer un conflit
       * @param e
       *        nombre à mettre
       * @param x
       *        numéro de la colonne
       * @param y
       *        numéro de la ligne
      */
      bool onPeutMettre(const size_t e, const size_t x, const size_t y) const ;

      /**
       * Vérifie si la grille est valide
       * @return
       *  Vrai si aucune case cause un conflict et faux sinon
      */
      bool estValide() const ;

      /**
       * Renvoie les nombre qu'on peut mettre dans [y,x] représenté par un tableau de bool
       * @param x
       *        numéro de la colonne
       * @param y
       *        numéro de la ligne
       * @return
       *  Tableau de booléen qui représente les nombres possibles pour la case [y,x]
      */
      bool* possibilites(size_t x, size_t y) const ;

      /**
       * affiche la grille dans un terminal
      */
      void afficher() const ;

      /**
       * Enregistre la grille dans un fichier qu'on lui donne son nom
       * @param F
       *        nom du fichier
      */
      void enregistrer(const std::string F) const ;

      /**
       * Charge la grille d'un fichier
       * @param F
       *        nom du fichier
      */
      void charger(const std::string F) ;
};

#endif

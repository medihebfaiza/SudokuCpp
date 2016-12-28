#include "sudoku.h"
using namespace std ;

bool Sudoku::resoudre(Grille* grille) const {
  bool resolue=false;
  if(grille->estValide()){
    resolue = resoudreBetement(grille);
      if(!resolue){
        resolue = backTrackSolve(grille,0,0);
      }
  }
  return resolue;
}

bool Sudoku::resoudreBetement(Grille* grille) const{
  size_t taille = grille->getTaille() ;
  bool* possibilites ;
  bool trouve = grille->estValide() ; //On essaye de resoudre que quand la grille est valide
  size_t nbtrouve, elemtrouve ;

  while (!grille->pleine() && trouve){
    trouve = false ;
    for (size_t y=0 ; y<taille ; y++)
      for (size_t x=0 ; x<taille ; x++)
        if (grille->get(x,y)==0){
          nbtrouve = 0 ;
          elemtrouve = 0 ;
          possibilites = grille->possibilites(x,y) ;
          for (size_t i = 1 ; i<taille+1 ; i++)
            if (possibilites[i]){
              nbtrouve++ ;
              elemtrouve = i ;
            }
          if (nbtrouve == 1){
            grille->set(elemtrouve,x,y) ;
            trouve = true ;
          }
          delete possibilites ;
        }
    }
  return grille->pleine() ;
}

bool Sudoku::backTrackSolve(Grille* grille, size_t debx , size_t deby) const{
  bool resolue = grille->pleine();
  bool zeroTrouve = false;
  size_t x = debx, y;
  size_t taille = grille->getTaille() ;

  for (y = deby ; !resolue && !zeroTrouve && y < taille ; y++) {
    for (x = debx ; !zeroTrouve && x < taille ; x++)
       zeroTrouve = (grille->get(x,y) == 0);
    debx = 0;
  }
  x-- ;
  y-- ;
  if (!resolue && zeroTrouve) {
    for (size_t e = 1; e < taille+1 && !resolue; e++)
      if (grille->onPeutMettre(e, x, y)) {
        grille->set(e, x, y);
        if (backTrackSolve(grille, x + 1, y))
          resolue = true;
        else
          grille->enlever(x, y);
      }
  }
  return resolue;
}

void Sudoku::genererSolutionAlea(Grille* grille) const {
      size_t x, y, nb; // nb c'est le nombre des nombres aleatoires qu'on veut générer
      size_t e;
      size_t taille = grille->getTaille() ;

      srand((unsigned int) time(NULL)); // crée la graine des nombres aléatoires
      do {
        grille->vider();
        (taille>4)?nb = 25 : nb = 5 ; //Après beaucoup d'essais, ça semblait être le bon nombre d'éléments aléatoires pour toutes les tailles
        for (size_t i = 0; i < nb; i++) {
          x = rand() % taille ;
          y = rand() % taille;
          e = rand() % taille + 1;
          if (grille->onPeutMettre(e, x, y))
            grille->set(e, x, y) ;
          else
            i--;
        }
      }
      while (!resoudre(grille));
}

bool Sudoku::onPeutResoudre(Grille grille, bool BetementSeulement) const {
    if (grille.estValide()) {
        bool resolue = resoudreBetement(&grille); //parce qu'on on utilise une copie de la grille

        if (!BetementSeulement && !resolue)
            resolue = backTrackSolve(&grille,0,0);

        return resolue;
    }
    else
        return false;
}

bool Sudoku::onPeutTrouer(Grille* grille, size_t x, size_t y) const {
    bool soluble = false;

    if (grille->get(x, y) == 0)
        return false;

    int valeur = grille->get(x, y);
    grille->enlever(x, y);
    soluble = (onPeutResoudre(*grille, true)); // avec resoudreBetement() seulement
    grille->set(valeur, x, y);
    return soluble;
}

//Renvoie vrai si le tableau est rempli de vrai
bool estPlein(bool** T, size_t taille){
  for(size_t i=0; i<taille;i++)
    for(size_t j=0;j<taille;j++)
      if (T[i][j]==false)
        return false ;
  return true ;
}

//Renvoie le nombre de trous à faire dans ue sudoku selon le niveau et la taille
size_t nbTrous(size_t niveau, size_t taille){
  if (taille == 4){
    switch (niveau) {
        case 1:
            return 4;
        case 2:
            return 8;
        default :
            return 16;
    }
  }
  else if (taille == 9){
    switch (niveau) {
        case 1:
            return 25;
        case 2:
            return 40;
        default :
            return 81;
    }
  }
  else {
    switch (niveau) {
        case 1:
            return 50;
        case 2:
            return 100;
        default :
            return 256; 
    }
  }
}

size_t Sudoku::trouer(Grille* grille, const size_t niveau) const {
  size_t tr=0; //Nombre de trous fait
  size_t taille = grille->getTaille() ;
  bool** Vu = new bool*[taille] ;
  size_t x, y ;

  //On met nos deux tableaux à false c-a-d qu'on a vu aucune case et qu'on en a troué aucune
  for(size_t i=0 ; i<taille ; i++){
    Vu[i] = new bool[taille] ;
    for(size_t j=0 ; j<taille ; j++){
      Vu[i][j]=false;
    }
  }

  srand((unsigned int) time(NULL)); // crée la graine des nombres aléatoires

  //pour le niveau 3 (difficile) on troue le maximum de cases possibles
  while(tr<nbTrous(niveau, taille) && !estPlein(Vu, taille)){
    x=rand()%taille;
    y=rand()%taille;
    if(!Vu[y][x]){
      Vu[y][x] = true;
      if(onPeutTrouer(grille, x, y)){
        grille->enlever(x,y) ;
        tr++ ;
      }
    }
  }
  return tr;
}

Grille* Sudoku::genererSudoku(size_t taille, size_t niveau) const {
 if (taille != 4 && taille != 9 && taille != 16) {
   cout<<"Erreur : taille invalide"<<endl ;
   return NULL ;
 }
 if (niveau != 1 && niveau != 2  && niveau != 3 ) {
   cout<<"Erreur : niveau invalide"<<endl ;
   return NULL ;
 }
 Grille* g = new Grille(taille) ;
 genererSolutionAlea(g) ;
 trouer(g,niveau) ;
 return g ;
}

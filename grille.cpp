#include "grille.h"

using namespace std ;

Grille::Grille() {
  taille = 0;
  M_grille = NULL ;
}

Grille::Grille(const size_t t){
  taille = t ;
  if ((t==4)||(t==9)||(t==16)){
    M_grille = new size_t*[taille] ;
    for (size_t i=0 ; i<taille ; i++) {
      M_grille[i] = new size_t[taille] ;
    }
    for (size_t i=0 ; i<taille ; i++) {
      for (size_t j=0 ; j<taille ; j++) {
        M_grille[i][j] = 0 ;
      }
    }
  }
  else
    cout<<"Erreur : taille invalide" ;
}

Grille::Grille(const Grille& grille){
    taille = grille.taille ;
    M_grille = new size_t*[taille] ;
    for (size_t i=0 ; i<taille ; i++) {
      M_grille[i] = new size_t[taille] ;
    }
    for (size_t i=0 ; i<taille ; i++) {
      for (size_t j=0 ; j<taille ; j++) {
        M_grille[i][j] = grille.M_grille[i][j] ;
      }
    }
}

size_t Grille::getTaille() const {
  return taille ;
}

void Grille::setTaille(const size_t t) {
  if (t == 4 || t == 9 || t == 16)
    taille = t ;
  else
    cout<<"Erreur : taille invalide"<<endl ;
}

size_t Grille::get(const size_t x, const size_t y) const {
  return M_grille[y][x] ;
}

void Grille::set(const size_t e, const size_t x, const size_t y) {
  M_grille[y][x] = e ;
}

void Grille::enlever(const size_t x, const size_t y) {
  set(0,x,y) ;
}

void Grille::vider() {
  for (size_t i=0 ; i<taille ; i++)
    for (size_t j=0 ; j<taille ; j++)
      enlever(j,i) ;
}

bool Grille::pleine() const {
  for (size_t i=0 ; i<taille ; i++)
     for (size_t j=0 ; j<taille ; j++)
        if (M_grille[i][j] == 0 )
            return false ;
  return true ;

}

bool Grille::onPeutMettre(const size_t e, const size_t x, const size_t y) const {
  return (verifHorizontal(x, y, e) && verifVertical(x, y, e) && verifBloc(x, y, e)) ;
}

bool Grille::estValide() const {
  for (size_t y = 0 ; y<taille ; y++){
    for (size_t x = 0 ; x<taille ; x++){
      if (M_grille[y][x]!=0){
        for (size_t k = x+1 ; k<taille ; k++)
          if (M_grille[y][x]==M_grille[y][k]){
            return false ;
          }
        for (size_t k = y+1 ; k<taille ; k++)
          if (M_grille[y][x]==M_grille[k][x]){
            return false ;
          }
      }
    }
  }

  size_t t = (size_t)sqrt(taille) ;// t c'est la taille du bloc
  for (size_t deby=0 ; deby<taille ; deby+=t){
    for (size_t debx=0 ; debx<taille ; debx+=t){
      for (size_t y=deby ; y<deby+t ; y++){
        for (size_t x=debx ; x<debx+t ; x++){
          if (M_grille[y][x]!=0) {
            size_t m = y ;
            size_t n = x+1 ;
            while (m<deby+t) {
              if (!(n<debx+t)){
                n=debx ;
                m++ ;
              }
              else if (M_grille[y][x]==M_grille[m][n]) {
                return false ;
              }
              n++ ;
            }
          }
        }
      }
    }
  }
  return true ;
}

void Grille::afficher() const{
  for (size_t i=0 ; i<taille ; i++) {
    for (size_t j=0 ; j<taille ; j++) {
      cout<<M_grille[i][j]<<" " ;
      if (taille==16 && M_grille[i][j]<10)
        cout<<" " ;
    }
    cout<<endl ;
  }
}

bool Grille::verifVertical(size_t x, size_t y, size_t e) const {
    bool valide = (M_grille[y][x] == 0)&&(e<=taille); //si la case est déjà remplie on ne vérifie pas
    for (size_t i = 0; valide && i < taille; i++)
        valide = (M_grille[i][x] != e);

    return valide;
}

bool Grille::verifHorizontal(size_t x, size_t y, size_t e) const {
    bool valide = (M_grille[y][x] == 0)&&(e<=taille); //si la case est déjà remplie on ne vérifie pas
    for (size_t i = 0; valide && i < taille; i++)
        valide = (M_grille[y][i] != e);

    return valide;
}

bool Grille::verifBloc(size_t x, size_t y, size_t e) const {
  bool valide = (M_grille[y][x] == 0)&&(e<=taille);
  int debx, deby;
  size_t t = (size_t)sqrt(taille) ;
  debx = x-x%t ;
  deby = y-y%t ;
  for (size_t i = deby ; valide && i<deby+t ; ++i) // While not in the next block, and not at end of the board
      for (size_t j = debx ; valide && j<debx+t ; ++j)
          valide = (M_grille[i][j] != e);
  return valide;
}

bool* Grille::possibilites(size_t x, size_t y) const {
    bool* t = new bool[taille+1];
    t[0] = false ; //on commence à 1 pour eviter les confusions
    for (size_t i = 1; i < taille+1; i++)
        t[i] = onPeutMettre(i, x, y);

    return t;
}

void Grille::enregistrer(const string F) const{
  ofstream out ;
  out.open(F.c_str()) ;
  out<<taille<<"|" ; //on enregistre la taille
  for (size_t i=0 ; i<taille ; i++){
    for (size_t j=0 ; j<taille ; j++){
      out<<M_grille[i][j]<<"," ;
    }
  }
  out.close() ;
}

void Grille::charger(const string F){
  ifstream in ;
  char c ;
  in.open(F.c_str()) ;
  if (in.is_open()) {
    in.get(c) ;
    taille = (size_t)c - (size_t)'0' ; //on charge la taille
    in.get(c) ;
    if (c!='|') {
      taille = 16 ;
    }
    for (size_t i=0 ; i<taille ; i++){
      for (size_t j=0 ; j<taille ; j++){
        in.get(c) ;
        M_grille[i][j] = (size_t)c - (size_t)'0' ;
        in.get(c) ;
        while (c!=',') {
          M_grille[i][j] = M_grille[i][j]*10+(size_t)c - (size_t)'0' ;
          in.get(c) ;
        }
      }
    }
  }
  else {
    cout<<"Erreur : le fichier n'existe pas "<<endl ;
  }
}

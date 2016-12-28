#include "grille.h"
#include "sudoku.h"
using namespace std ;

int main(){

  Grille g(9) ;
  Sudoku s ;

  cout<<"                                      ..:: Testes de Resolution ::.."<<endl ;
  cout<<"chargement de la grille depuis save1.sudoku"<<endl ;
  g.charger("save1.sudoku") ;
  g.afficher() ;
  cout<<"resolution de la grille avec backTrackSolve"<<endl ;
  int debut_s=clock();
  s.backTrackSolve(&g,0,0) ;
  int fin_s=clock();
  g.afficher() ;
  cout << "temps de resolution : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"chargement de la grille depuis save2.sudoku"<<endl ;
  g.charger("save2.sudoku") ;
  g.afficher() ;
  cout<<"resolution de la grille avec resoudreBetement"<<endl ;
  debut_s=clock();
  s.resoudreBetement(&g) ;
  fin_s=clock();
  g.afficher() ;
  cout << "temps de resolution : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"chargement de la grille depuis save3.sudoku"<<endl ;
  g.charger("save3.sudoku") ;
  g.afficher() ;
  cout<<"resolution de la grille avec resoudre"<<endl ;
  debut_s=clock();
  s.resoudre(&g) ;
  fin_s=clock();
  g.afficher() ;
  cout << "temps de resolution : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"chargement de la grille depuis save4.sudoku le sudoku le plus difficile au monde"<<endl ;
  g.charger("save4.sudoku") ;
  g.afficher() ;
  cout<<"resolution de la grille avec backTrackSolve"<<endl ;
  debut_s=clock();
  s.backTrackSolve(&g,0,0) ;
  fin_s=clock();
  g.afficher() ;
  cout << "temps de resolution : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"chargement de la grille depuis save4.sudoku le sudoku le plus difficile au monde"<<endl ;
  g.charger("save4.sudoku") ;
  g.afficher() ;
  cout<<"resolution de la grille avec backTrackSolve"<<endl ;
  debut_s=clock();
  s.backTrackSolve(&g,0,0) ;
  fin_s=clock();
  g.afficher() ;
  cout << "temps de resolution : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  g.charger("save4.sudoku") ;
  g.afficher() ;
  cout<<"resolution de la grille avec resoudre"<<endl ;
  debut_s=clock();
  s.resoudre(&g) ;
  fin_s=clock();
  g.afficher() ;
  cout << "temps de resolution : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"                                      ..:: Testes de Géneration ::.."<<endl ;
  Grille g4(4) ;
  cout<<"generation d'une grille aleatoire 4x4"<<endl ;
  debut_s=clock();
  s.genererSolutionAlea(&g4) ;
  fin_s=clock();
  g4.afficher() ;
  cout << "temps de generation : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  Grille g9(9) ;
  cout<<"generation d'une grille aleatoire 9x9"<<endl ;
  debut_s=clock();
  s.genererSolutionAlea(&g9) ;
  fin_s=clock();
  g9.afficher() ;
  cout << "temps de generation : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  Grille g16(16) ;
  cout<<"generation d'une grille aleatoire 16x16 (ça peut prendre un peu de temps)"<<endl ;
  debut_s=clock();
  s.genererSolutionAlea(&g16) ;
  fin_s=clock();
  g16.afficher() ;
  cout << "temps de generation : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"                                      ..:: Testes de Trouage ::.."<<endl ;
  cout<<"trouage de la grille 4x4 precedente /niveau difficile"<<endl ;
  debut_s=clock();
  cout<<"nombre des cases trouees : "<<s.trouer(&g4,0)<<endl ;
  fin_s=clock();
  g4.afficher() ;
  cout << "temps de trouage : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"trouage de la grille 9x9 precedente /niveau facile"<<endl ;
  debut_s=clock();
  cout<<"nombre des cases trouees : "<<s.trouer(&g9,1)<<endl ;
  fin_s=clock();
  g9.afficher() ;
  cout << "temps de trouage : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"trouage de la grille 16x16 precedente /niveau facile"<<endl ;
  debut_s=clock();
  cout<<"nombre des cases trouees : "<<s.trouer(&g16,1)<<endl ;
  fin_s=clock();
  g16.afficher() ;
  cout << "temps de trouage : " << float(fin_s-debut_s)/CLOCKS_PER_SEC <<" s"<< endl;
  cout<<endl ;

  cout<<"                                      ..:: Testes de Géneration ::.."<<endl ;
  Grille gf ;
  gf = *s.genererSudoku(9,1) ;
  gf.afficher() ;
  cout<<endl ;
  gf = *s.genererSudoku(9,2) ;
  gf.afficher() ;
  cout<<endl ;
  gf = *s.genererSudoku(9,3) ;
  gf.afficher() ;
  cout<<endl ;
  gf = *s.genererSudoku(4,1) ;
  gf.afficher() ;
  cout<<endl ;
  gf = *s.genererSudoku(4,2) ;
  gf.afficher() ;
  cout<<endl ;
  gf = *s.genererSudoku(4,3) ;
  gf.afficher() ;
  cout<<endl ;
  cout<<"generation d'une grille aleatoire 16x16 (ça peut prendre un peu de temps)"<<endl ;
  gf = *s.genererSudoku(16,1) ;
  gf.afficher() ;
  cout<<endl ;
  cout<<"generation d'une grille aleatoire 16x16 (ça peut prendre un peu de temps)"<<endl ;
  gf = *s.genererSudoku(16,2) ;
  gf.afficher() ;
  cout<<endl ;
  cout<<"generation d'une grille aleatoire 16x16 (ça peut prendre un peu de temps)"<<endl ;
  gf = *s.genererSudoku(16,3) ;
  gf.afficher() ;
  cout<<endl ;

  return 0 ;
}

char r = 'n' ;
string nomfichier ;
Grille g ;
Sudoku s ;
size_t niveau ;

cout<<"                                      ..:: Testes de Generation ::.."<<endl ;
while (r!='y') {
  cout<<"Charger un grille ? (y/n)"<<endl ;
  cin>>r ;
  if (r=='y'){
    cout<<"Donnez le nom du fichier : " ;
    cin>>nomfichier ;
    g.charger(nomfichier) ;
    g.afficher() ;
    if (!g.pleine()) {
      cout<<"resoudre ? (y/n)"<<endl ;
      cin>>r ;
      if (r == 'y'){
        s.resoudre(&g) ;
        g.afficher() ;
      }
    }
    cout<<"Testez la validité de la grille ? : " ;
    cin>>r ;
    if (r == 'y'){
      g.estValide()?cout<<"VALIDE !"<<endl : cout<<"N'EST PAS VALIDE"<<endl ;
    }
    cout<<"Quitter ? (y/n)"<<endl ;
    cin>>r ;
  }
  else {
    cout<<"Générer une grille ? (y/n)"<<endl ;
    cin>>r ;
    if (r=='y'){
      g.afficher() ;
      s.genererSolutionAlea() ;
      g.afficher() ;
      *************************************************************  
    }
    else {
      cout<<"Quitter ? (y/n)"<<endl ;
      cin>>r ;
    }
  }
}

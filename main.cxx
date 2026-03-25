#include<iostream>
#include<fstream>
#include "board.hpp"
#include "view.hpp"
using namespace std;

// code dans terminal pour test : make main , puis : ./main

int main(){
    char C1, C2;
    int l1 ,c1 , l2 , c2;
    square Plateau2D[L][C];

    empty_2D(Plateau2D);


    start_2D(Plateau2D);
    
    string fichier = "text.txt";
    

    write_FEN(Plateau2D, fichier);

    read_FEN(Plateau2D, fichier);
    
    for (int i = 0; i < 2; i++){
        // joueur blanc
        cout << "tour joueur blanc" << endl;

        print_board(Plateau2D);

        cout<<"Case de depart (ligne et colonne) :";
        cin>>l1>>C1;

        l1=l1-1;
        c1 = (int) C1 - 97 ;

        while (l1 < 0 || l1 > 7 || c1 < 0 || c1 > 7){
            cout << "coordonné invalide";
            cout<<"Case de depart (ligne et colonne) :";
            cin>>l1>>C1;
            l1=l1-1;
            c1 = (int) C1 - 97 ;
        }
        
        cout<<"piece est : ";
        print_square(Plateau2D, l1, c1);
        cout << endl;
    

        
        cout<<"Case d'arrivee (ligne et colonne) :";
        cin>>l2>>C2;

        l2=l2-1;
        c2 = (int) C2 - 97 ;
        
        while (l2 < 0 || l2 > 7 || c2 < 0 || c2 > 7){
            cout << "coordonné invalide";
            cout<<"Case de depart (ligne et colonne) :";
            cin>>l2>>C2;
            l2=l2-1;
            c2 = (int) C2 - 97 ;
        }
          

        move_piece_2D(Plateau2D,l1,c1,l2,c2);

        //jouer noir
        cout << "tour joueur noir" << endl;

        print_board(Plateau2D);

        cout<<"Case de depart (ligne et colonne) :";
        cin>>l1>>C1;

        l1=l1-1;
        c1 = (int) C1 - 97 ;

        while (l1 < 0 || l1 > 7 || c1 < 0 || c1 > 7){
            cout << "coordonné invalide";
            cout<<"Case de depart (ligne et colonne) :";
            cin>>l1>>C1;
            l1=l1-1;
            c1 = (int) C1 - 97 ;
        }
        
        cout<<"piece est : ";
        print_square(Plateau2D, l1, c1);
        cout << endl;
    

        
        cout<<"Case d'arrivee (ligne et colonne) :";
        cin>>l2>>C2;

        l2=l2-1;
        c2 = (int) C2 - 97 ;
        
        while (l2 < 0 || l2 > 7 || c2 < 0 || c2 > 7){
            cout << "coordonné invalide";
            cout<<"Case de depart (ligne et colonne) :";
            cin>>l2>>C2;
            l2=l2-1;
            c2 = (int) C2 - 97 ;
        }
          

        move_piece_2D(Plateau2D,l1,c1,l2,c2);


    }
    
    cout << "résultat du jeu : " << endl;
    print_board(Plateau2D);

    return 0;
}

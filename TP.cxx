#include<iostream>
#include "board.hpp"
using namespace std;



// ---------------- MAIN ----------------

int main(){
    char C1, C2;
    int l1 ,c1 , l2 , c2;
    square Plateau1D[N];
    square Plateau2D[L][C];

    empty_1D(Plateau1D);
    empty_2D(Plateau2D);

    start_1D(Plateau1D);
    start_2D(Plateau2D);

    square piece1=get_square_1D(Plateau1D,0,0);
    cout<<"piece 1 est : "<<piece1<<endl;

    square piece2=get_square_2D(Plateau2D,0,0);
    cout<<"piece 2 est : "<<piece2<<endl;

    set_square_1D(Plateau1D,0,5,Btour);
    set_square_2D(Plateau2D,0,5,Btour);

    cout<<"Case de depart (ligne et colonne) :";
    cin>>l1>>C1;
    cout<<"Case d'arrivee (ligne et colonne) :";
    cin>>l2>>C2;

    c1 = (int) C1 - 97 ;
    c2 = (int) C2 - 97 ;
    if (c1 < 0 || c1 > 7 || c2 < 0 || c2 > 97){
        cout << "colonne non valide" << endl;
        return 1;
    }

    l1=l1-1;
    c1=c1-1;
    l2=l2-1;
    c2=c2-1;

    if (l1 < 0 || l1 >= 8 || c1 < 0 || c1 >= 8 ||
        l2 < 0 || l2 >= 8 || c2 < 0 || c2 >= 8){
        cout<<"Coordonnees invalides !"<<endl;
        return 1;
    }

    move_piece_1D(Plateau1D,l1,c1,l2,c2);
    cout<<"piece 1 apres mouvement 1D :" << get_square_1D(Plateau1D,l2,c2)<<endl;

    move_piece_2D(Plateau2D,l1,c1,l2,c2);
    cout<<"piece 1 apres mouvement 2D :" << get_square_2D(Plateau2D,l2,c2)<<endl;

    return 0;
}
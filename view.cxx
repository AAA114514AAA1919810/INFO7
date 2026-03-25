#include<iostream>
#include<fstream>
#include <string>
#include "type.hpp"
#include "board.hpp"
using namespace std;

void print_square(square Plateau2D[L][C], int l1, int c1){
    int x = Plateau2D[l1][c1];
    string s;
    if(x == Ntour)s = "r";
    if(x == Ncavalier)s = "n";
    if(x == Nfou)s = "b";
    if(x == Ndame)s = "q";
    if(x == Nroi)s = "k";
    if(x == Npion)s = "p";
    if(x == Btour)s = "R";
    if(x == Bcavalier)s = "N";
    if(x == Bfou)s = "B";
    if(x == Bdame)s = "Q";
    if(x == Broi)s = "K";
    if(x == Bpion)s = "P";
    if(x == vide)s = "-";
    
    cout << s ;
}

void print_board(square Plateau2D[L][C]){
    cout << "  a b c d e f g h  " << endl;
    for(int j = L-1; j>-1 ; j--){
        cout << (j+1) << " ";
        for(int i = 0; i < C; i++){
            print_square(Plateau2D,j,i);
            cout << " " ;
        }
        cout << (j+1) << endl;
    }
    cout << "  a b c d e f g h  " << endl;
}




void write_FEN(square Plateau2D[L][C], string fichier){
    ofstream fic(fichier);
    string ch_FEN;
    int tmp;
    int n = 0;
    for(int j = L-1; j>-1 ; j--){

        for(int i = 0; i < C; i++){
            tmp = get_square_2D(Plateau2D , j , i);
            if (tmp == vide) n+=1;
            else {
                if(n != 0){
                    ch_FEN += to_string(n);
                    n = 0;
                }

                if(tmp == Ntour)ch_FEN += "r";
                if(tmp == Ncavalier)ch_FEN += "n";
                if(tmp == Nfou)ch_FEN += "b";
                if(tmp == Ndame)ch_FEN += "q";
                if(tmp == Nroi)ch_FEN += "k";
                if(tmp == Npion)ch_FEN += "p";
                if(tmp == Btour)ch_FEN += "R";
                if(tmp == Bcavalier)ch_FEN += "N";
                if(tmp == Bfou)ch_FEN += "B";
                if(tmp == Bdame)ch_FEN += "Q";
                if(tmp == Broi)ch_FEN += "K";
                if(tmp == Bpion)ch_FEN += "P";
                if(tmp == vide)ch_FEN += "-";
            }
        
        }
        if(n != 0){
            ch_FEN += to_string(n);
            n = 0;
        }
        if( j != 0 )ch_FEN += "/";
    }
    cout << ch_FEN<<endl;

    if (fic) {
        fic << ch_FEN;
    }
    else {
        cout << "ERREUR : impossible d’ouvrir le fichier en sortie" << endl;
    }
    fic.close();
}

void read_FEN(square Plateau2D[L][C], string fichier){
    ifstream fic(fichier);
    string s;
    if (fic) {
        fic >> s;
        cout << s << endl;
    }
    else {
        cout << "ERREUR : impossible d’ouvrir le fichier" << endl;
    }

}

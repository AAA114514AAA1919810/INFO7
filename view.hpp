#ifndef _view_HPP
#define _view_HPP

#include <string>
using namespace std;

#include "type.hpp"
#include "board.hpp"

void print_square(square Plateau2D[L][C], int l1, int c1);

void print_board(square Plateau2D[L][C]);

void write_FEN(square Plateau2D[L][C], string fichier);

void read_FEN(square Plateau2D[L][C], string fichier);

#endif
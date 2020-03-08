#include <iostream>
#include "geometria.h"

#define max std::max
#define min std::min

void Ponto::set_x (long long int a) { x = a; }
void Ponto::set_y (long long int a) { y = a; }

long long int Ponto::get_x () { return x; }
long long int Ponto::get_y () { return y; }

Ponto::Ponto ()
{
	x = 0;
	y = 0;
}

Ponto::Ponto (long long int x_, long long int y_)
{
	x = x_;
	y = y_;
}

int orient (Ponto p, Ponto q, Ponto r)
{
    long long int result,
                  p_x = p.get_x(), p_y = p.get_y(),
                  q_x = q.get_x(), q_y = q.get_y(),
                  r_x = r.get_x(), r_y = r.get_y();

    result = ( (q_x - p_x) * (r_y - p_y) - (r_x - p_x) * (q_y - p_y) ); // Determinante (ou produto vetorial bidimensional)

    if (result < 0) return DIR; // -1
    else if (result == 0) return COLINEAR;  // 0
    else return ESQ;    // 1
}


// Dados 3 pontos colineares 'p1, p2, q', checa se o ponto 'q' está no segmento 'p1 p2'

bool ponto_colinear_no_segmento (Ponto p1, Ponto p2, Ponto q)
{
    long long int p1_x = p1.get_x(), p1_y = p1.get_y(),
                  p2_x = p2.get_x(), p2_y = p2.get_y(),
                  q_x = q.get_x(), q_y = q.get_y();

    if ( q_x <= max (p1_x, p2_x) && q_x >= min (p1_x, p2_x) &&
         q_y <= max (p1_y, p2_y) && q_y >= min (p1_y, p2_y) ) return true;

    else return false;
}


// Dados 4 pontos (ou duas retas), retorna 'true' se a reta 'p1 p2' intercepta a reta 'q1 q2', 'false' caso contrário

bool existe_intersecao (Ponto p1, Ponto p2, Ponto q1, Ponto q2)
{
    int or1, or2, or3, or4;

    or1 = orient (p1, p2, q1);
    or2 = orient (p1, p2, q2);
    or3 = orient (q1, q2, p1);
    or4 = orient (q1, q2, p2);

    if (or1 != or2 && or3 != or4) return true;

    // Sabendo que 'q1' é colinear a 'p1 p2', retorna 'true' se 'q1' estiver no segmento 'p1 p2'. Faça igual para os outros 'else if's
    else if ( or1 == 0 && ponto_colinear_no_segmento (p1, p2, q1) == true ) return true;

    else if ( or2 == 0 && ponto_colinear_no_segmento (p1, p2, q2) == true ) return true;

    else if ( or3 == 0 && ponto_colinear_no_segmento (q1, q2, p1) == true ) return true;

    else if ( or4 == 0 && ponto_colinear_no_segmento (q1, q2, p2) == true ) return true;

    else return false;
}

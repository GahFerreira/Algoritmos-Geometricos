#ifndef GEOMETRIA_H
#define GEOMETRIA_H

#define ESQ 1
#define DIR -1
#define COLINEAR 0

#define INF 1222333444

class Ponto
{
  public:
    void set_x (long long int a);
    void set_y (long long int a);

    long long int get_x ();
    long long int get_y ();

    Ponto ();

    Ponto (long long int x_, long long int y_);

  private:
    long long int x;
    long long int y;
};

int orient (Ponto p, Ponto q, Ponto r);

bool ponto_colinear_no_segmento (Ponto p1, Ponto p2, Ponto q);

bool existe_intersecao (Ponto p1, Ponto p2, Ponto q1, Ponto q2);

#endif

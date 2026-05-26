#ifndef DRESOVI_H
#define DRESOVI_H

#define MAX_DRESOVA 100


typedef enum
{
    XS,
    S,
    M,
    L,
    XL
} Velicina;


typedef struct
{
    int id;
    char klub[50];
    char igrac[50];
    int broj;
    Velicina velicina;
    float cijena;
    int kolicina;
} Dres;


extern Dres dresovi[MAX_DRESOVA];
extern int brojDresova;

void dodajDres();
void prikaziDresove();
void urediDres();
void obrisiDres();
void prikaziVelicinu(Velicina velicina);

#endif

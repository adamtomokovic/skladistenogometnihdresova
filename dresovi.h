#ifndef DRESOVI_H
#define DRESOVI_H

#define MAX_DRESOVA 100

typedef enum //enum
{
	XS, S, M, L, XL
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

extern int brojacOperacija;

// 9 makro funkcije
#define UKUPNA_VRIJEDNOST(c, k) ((c) * (k))
#define JE_PRAZNO(b) ((b) == 0) 

void DodajDres();
void PrikaziDresove();
void UrediDres();
void ObrisiDres();
void PrikaziVelicinu(const Dres* dresPtr);

#endif

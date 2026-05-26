#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "dresovi.h"


static Dres dresovi[MAX_DRESOVA];
static int brojDresova = 0;


void DodajDres()
{
    if (brojDresova >= MAX_DRESOVA)
    {
        printf("Skladiste je puno!\n");
        return;
    }

	static int idBrojac = 1; //static

    Dres noviDres;
    int velicinaBroj;

	noviDres.id = idBrojac++;
	printf("\nAutomatski dodijeljen jedinstveni ID dresa: %d\n", noviDres.id);

    printf("Unesi naziv kluba: ");
    scanf(" %49[^\n]", noviDres.klub);


    printf("Unesi ime igraca: ");
    scanf(" %49[^\n]", noviDres.igrac);

    printf("Unesi broj igraca: ");
    scanf("%d", &noviDres.broj);

    printf("0 - XS\n1 - S\n2 - M\n3 - L\n4 - XL\n");
    printf("Odaberi velicinu: ");
    scanf("%d", &velicinaBroj);

    noviDres.velicina = (Velicina)velicinaBroj;

    printf("Unesi cijenu: ");
    scanf("%f", &noviDres.cijena);

    printf("Unesi kolicinu: ");
    scanf("%d", &noviDres.kolicina);

    dresovi[brojDresova] = noviDres;
    brojDresova++;

    printf("Dres uspjesno dodan!\n");
}


void PrikaziDresove()
{
	if (brojDresova == 0)
	{
		printf("Nema dresova!\n");
		return;
	}

	for (int i = 0; i < brojDresova; i++)
	{
		printf("\n====================\n");
		printf("ID: %d\n", dresovi[i].id);
		printf("Klub: %s\n", dresovi[i].klub);
		printf("Igrac: %s\n", dresovi[i].igrac);
		printf("Broj: %d\n", dresovi[i].broj);

		printf("Velicina: ");
		PrikaziVelicinu(&dresovi[i]);
		printf("\n");

		printf("Cijena: %.2f\n", dresovi[i].cijena);
		printf("Kolicina: %d\n", dresovi[i].kolicina);

		//makro funkcija primjena
		printf("Ukupna vrijednost zaliha: %.2f EUR\n", UKUPNA_VRIJEDNOST(dresovi[i].cijena, dresovi[i].kolicina));
	}
}

void UrediDres()
{
    int trazeniId;

    printf("Unesi ID dresa: ");
    scanf("%d", &trazeniId);

    for (int i = 0; i < brojDresova; i++)
    {
        if (dresovi[i].id == trazeniId)
        {
            printf("Novi klub: ");
            scanf(" %49[^\n]", dresovi[i].klub);

            printf("Novi igrac: ");
            scanf(" %49[^\n]", dresovi[i].igrac);

            printf("Nova cijena: ");
            scanf("%f", &dresovi[i].cijena);

            printf("Nova kolicina: ");
            scanf("%d", &dresovi[i].kolicina);

            printf("Dres uređen!\n");
            return;
        }
    }

    printf("Dres nije pronađen!\n");
}


void ObrisiDres()
{
    int trazeniId;

    printf("Unesi ID dresa za brisanje: ");
    scanf("%d", &trazeniId);

    for (int i = 0; i < brojDresova; i++)
    {
        if (dresovi[i].id == trazeniId)
        {
            for (int j = i; j < brojDresova - 1; j++)
            {
                dresovi[j] = dresovi[j + 1];
            }

            brojDresova--;

            printf("Dres obrisan!\n");
            return;
        }
    }

    printf("Dres nije pronađen!\n");
}


void PrikaziVelicinu(const Dres* dresPtr) //12 koncept
{
    switch (dresPtr->velicina) //12 koncept
    {
    case XS:
        printf("XS");
        break;

    case S:
        printf("S");
        break;

    case M:
        printf("M");
        break;

    case L:
        printf("L");
        break;

    case XL:
        printf("XL");
        break;

    default:
        printf("Nepoznato");
    }
}

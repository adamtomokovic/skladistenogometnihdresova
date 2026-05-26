#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "dresovi.h"


Dres dresovi[MAX_DRESOVA];
int brojDresova = 0;


void dodajDres()
{
    if (brojDresova >= MAX_DRESOVA)
    {
        printf("Skladiste je puno!\n");
        return;
    }

    Dres noviDres;
    int velicinaBroj;

    printf("\nUnesi ID: ");
    scanf("%d", &noviDres.id);

    printf("Unesi naziv kluba: ");
    scanf(" %d", noviDres.klub);


    printf("Unesi ime igraca: ");
    scanf(" %d", noviDres.igrac);

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


void prikaziDresove()
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
        prikaziVelicinu(dresovi[i].velicina);
        printf("\n");

        printf("Cijena: %.2f\n", dresovi[i].cijena);
        printf("Kolicina: %d\n", dresovi[i].kolicina);
    }
}


void urediDres()
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


void obrisiDres()
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


void prikaziVelicinu(Velicina velicina)
{
    switch (velicina)
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

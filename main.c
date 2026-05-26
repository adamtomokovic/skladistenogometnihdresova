#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"
#include "dresovi.h"

int main()
{
    int opcija;

    do
    {
        prikaziMenu();

        printf("Odaberi opciju: ");
        scanf("%d", &opcija);

        switch (opcija)
        {
        case 1:
            dodajDres();
            break;

        case 2:
            prikaziDresove();
            break;

        case 3:
            urediDres();
            break;

        case 4:
            obrisiDres();
            break;

        case 0:
            printf("Izlaz iz programa.\n");
            break;

        default:
            printf("Neispravna opcija!\n");
        }

    } while (opcija != 0);

    return 0;
}

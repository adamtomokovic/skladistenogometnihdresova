#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"
#include "dresovi.h"

int main()
{
    int opcija;

    do
    {
        PrikaziMenu();

        printf("Odaberi opciju: ");
        scanf("%d", &opcija);

        switch (opcija)
        {
        case 1:
            DodajDres();
            break;

        case 2:
            PrikaziDresove();
            break;

        case 3:
            UrediDres();
            break;

        case 4:
            ObrisiDres();
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

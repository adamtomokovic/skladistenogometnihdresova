#define _CRT_SECURE_NO_WARNINGS
#ifndef MENU_H
#define MENU_H
typedef enum {
	IZLAZ = 0,
	DODAJ,      //enum 11.
	PRIKAZI,    
	UREDI,      
	OBRISI      
} OpcijaIzbornika;

void PrikaziMenu();

#endif

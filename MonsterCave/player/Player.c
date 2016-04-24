/*
 * Player.c
 *
 *  Created on: Apr 7, 2016
 *      Author: jomod
 */
#include "Player.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void crearPlayer(Player* pl){

	char str[10];
	printf("Escribe el nombre del personaje:");
	fflush(stdout);
	fgets(str, 10, stdin); //incluye el '\n' al final (si lo hay)
	char *str_fmt = malloc((10) * sizeof(char));
	sscanf(str, "%s", str_fmt); //le quita el 'n' (si lo hay)
	pl->name=malloc((10) * sizeof(char));
	strcpy(pl->name,str_fmt);

	//strcpy(pl->name , str);

	pl->fuerza=5;
	pl->inteligencia=5;
	pl->carisma=5;
	pl->vida=100;
	pl->numerodesalas=0;
	free(str_fmt);



}

void printPlayer(Player pl){
	printf("PERSONAJE: %s\n",pl.name);
//	printf("\nfuerza:%i",pl.fuerza);

}

void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}

void guardarPlayer(){

}


/*
 * Player.h
 *
 *  Created on: Apr 7, 2016
 *      Author: jomod
 */
#include <stdio.h>

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct
{
	char* name;
	int fuerza;
	int inteligencia;
	int carisma;
	int vida;
	int numerodesalas;
	int historia[7];
}Player;

typedef struct
{

	char** frases;

}Historia;

void crearPlayer(Player* pl);
void printPlayer(Player pl);
void printHistoria(Player* pl,Historia* historia);
void cargarHistoria(Historia* historia);
void guardarPlayer();
void clearIfNeeded(char *str, int max_line);

#endif /* PLAYER_H_ */

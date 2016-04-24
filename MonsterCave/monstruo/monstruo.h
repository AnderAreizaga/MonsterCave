/*
 * monstruo.h
 *
 *  Created on: 7 de abr. de 2016
 *      Author: ander
 */

#include <stdlib.h>

#ifndef MONSTRUO_H_
#define MONSTRUO_H_

typedef struct{
	char* nombre;
	int codsala; //la sala en la que esta el monstruo
	int vida;
	int ataque;
	int resistencia ;//0 fisico , 1 Fuego , 2 viento , 3 tierra , 4 agua, 5 nada
	char** interacciones; //Lo que quereis que diga el monstruo y tal
}Monstruo;

void inicializarArrayMonstruos(Monstruo* monstruos);

#endif /* MONSTRUO_H_ */

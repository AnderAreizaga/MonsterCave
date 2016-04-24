/*
 * monstruo.c
 *
 *  Created on: 7 de abr. de 2016
 *      Author: ander
 */
#include "monstruo.h"
#include <string.h>
#include <stdio.h>

void inicializarArrayMonstruos(Monstruo* monstruos){
	Monstruo m;
	char str[200];
	char nom[10];
	FILE *fichero;
	fichero = fopen("monstruo/Monstruos.txt", "r");
	int i=0;
	int x=0;
	do{
		fgets(nom, 10, fichero);
		if(nom[0]!='&'){
			m.nombre=malloc(sizeof(char)*strlen(nom));
			int a=0;
			for(;a<strlen(nom)+1;a++)
			{
				m.nombre[a]=nom[a];
			}
			fgets(str, 10, fichero);
			m.codsala = atoi(str);
			fgets(str, 10, fichero);
			m.vida = atoi(str);
			fgets(str, 10, fichero);
			m.ataque = atoi(str);
			fgets(str, 10, fichero);
			m.resistencia = atoi(str);
			fgets(str, 199, fichero);
			//m.interacciones[0] = str;
			monstruos[x] = m;
			x++;
		}
		else if(nom[0]=='&'){
			i=1;
		}
	}while(i==0);
}

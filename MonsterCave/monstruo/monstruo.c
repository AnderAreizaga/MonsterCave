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
	char nom[25];
	FILE *fichero;
	fichero = fopen("monstruo/Monstruos.txt", "r");
	int i=0;
	int x=0;
	int z=0;
	do{
		fgets(nom, 25, fichero);
		if(nom[0]!='&'&&nom[0]!='%'){
			m.nombre=malloc(sizeof(char)*strlen(nom));
			int a=0;
			for(a=0;a<strlen(nom)+1;a++)
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
			int y=0;
			m.interacciones=malloc(sizeof(char)*2000);
			do{
				fgets(str, 199, fichero);
				if(str[0]!='%'&&str[0]!='&'){
					m.interacciones[z]=malloc(strlen(str)+1);
					for(a=0;a<strlen(str)+1;a++)
					{
						m.interacciones[z][a]=str[a];
					}
				}
				else if(str[0]=='&'){
					y=1;
					i=1;
				}
				else if(str[0]=='%'){
					y=1;
				}
				else{
					z++;
				}
			}while(y==0);
			monstruos[x] = m;
			x++;
		}
	}while(i==0);
}

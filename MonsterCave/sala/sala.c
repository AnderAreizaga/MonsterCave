/*
 * sala.c
 *
 *  Created on: 7 de abr. de 2016
 *      Author: ander
 */

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "sala.h"

void cargarSalas(Sala *puntS)
{
	int endF=0;

	FILE *salas;
	salas=fopen("salas.txt","r");
	char line[280];

	int endS=0;

	int j=0;
	do{

		endS=0;
		fgets(line,280,salas);
		puntS[j].codSala=atoi(line);
//		printf("%i\n",puntS[j].codSala);

		fgets(line,280,salas);
		puntS[j].tipo=atoi(line);
//		printf("%i\n",puntS[j].tipo);

		fgets(line,280,salas);
		puntS[j].respuestaCorr=atoi(line);

		puntS[j].textosDeSala=malloc(sizeof(char)*1000);
		int i=0;
		do{
			fgets(line,280,salas);
			if(line[0]!='#'){
				int a=0;
				puntS[j].textosDeSala[i]=malloc(strlen(line)+1);
				for(;a<strlen(line)+1;a++)
				{
					puntS[j].textosDeSala[i][a]=line[a];
				}
				//printf("%s",puntS[j].textosDeSala[i]);
				i++;
			}else{
				endS=1;
			}
		}while(endS!=1);
		j++;
		fgets(line,280,salas);
		if(line[0]=='@'){
			endF=1;
		}

	}while(endF!=1);

	fclose(salas);
}

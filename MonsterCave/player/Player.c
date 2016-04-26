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

void printHistoria(Player* pl, Historia* historia)
{
	fflush(stdout);

	FILE *fichero;
	fichero = fopen("tuHistoria.txt", "w");

	if(fichero!=NULL)
	{
		printf("\nLa historia de %s , sera contada por los juglares, pase por la salida para recoger su escrito :)\n", pl->name);
		fprintf(fichero,"Life of %s \n\n", pl->name);
		fprintf(fichero,"Era una oscura mañana de otoño, %s se disponía a empezar su primer dia en su nuevo trabajo.\nEra su oportunidad de servir a la sociedad y por primera vez cumplir su sueño  de ser un héroe,\nalguien que combatiera el mal y salvara al mundo varias veces. Pero sin embargo no era tal\ny como se esperaba, barrer el suelo en la taberna más sucia del barrio no era tan emocionante como pensaba que sería\ncuando le dijeron que su misión principal sería combatir la suciedad con esa escoba. Pero un día unos mercenarios entraron\nmientras él trabajaba, llegaron con el objetivo de cumplir la mision mas dificil que podría\nhaber llegado a los oídos de nuestro protagonista: ''Rescatar la gallina de los huevos dorados''\n"
				,pl->name);

		int i=0;
		for(;i<pl->numerodesalas;i++)
		{
			fprintf(fichero,"%s",historia[(pl->historia[i]-1)].frases[0]);
			if(i==5){
				fprintf(fichero,"%s",historia[pl->historia[i]-1].frases[1]);
				fprintf(fichero,"Encuentra la salida y vuelve a casa habiendo cumplido su sueño");
			}
			else if(i<pl->numerodesalas-1){
				fprintf(fichero,"%s",historia[pl->historia[i]-1].frases[1]);
			}else{
				fprintf(fichero,"%s",historia[pl->historia[i]-1].frases[2]);
			}

		}
	}

	fclose(fichero);
}

void cargarHistoria(Historia* historia)
{
	char str[280];
	FILE *fichero;
	fichero = fopen("historia.txt", "r");

	int i=0;
		int x=0;

		do{
			int z=0;
			fgets(str, 10, fichero);
			if(str[0]!='&'&&str[0]!='%'){
				int y=0;
				historia[x].frases=malloc(sizeof(char)*1000);
				do{
					fgets(str, 199, fichero);
					if(str[0]!='%'&&str[0]!='&'){
						historia[x].frases[z]=malloc(strlen(str)+1);
						int a=0;
						for(;a<strlen(str)+1;a++)
						{
							historia[x].frases[z][a]=str[a];
						}
						z++;
					}
					else if(str[0]=='&'){
						y=1;
						i=1;
					}
					else{
						y=1;
					}
				}while(y==0);
				x++;
			}
		}while(i==0);
}

void guardarPlayer(){

}


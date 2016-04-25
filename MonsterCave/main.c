/*
 * main2.c
 *
 *  Created on: 7/4/2016
 *      Author: ander.areizagab
 */

#include <stdio.h>
#include "player/Player.h"
#include "sala/sala.h"
#include "monstruo/monstruo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFile(char *name)
{
	char c;
	FILE *fichero;
	fichero = fopen("murloc.txt", "rb");
	if (!fichero) {
		fclose(fichero);
		printf("No se puede abrir el fichero:\n");
	}

	/* El siguiente bucle lee caracteres uno a uno y los imprime en pantalla. */
	while (!feof(fichero)) {
		c = getc(fichero);
		printf("%c", c);
	}
	fclose(fichero);

}
void creaHistoria(Player* p)
{
	int x ;
	int j;
	int i=0;

	while (i < 6)
	{
		int r = rand() % 15 + 1 ;

		for (x = 0; x < i; x++)
		{
			if (p->historia[x] == r)
			{
				break;
			}
		}
		if (x == i)
		{
			p->historia[i++] = r+1;
		}
	}
	for (j = 0; j < 6; j++)
	{
		printf("%i ", p->historia[j]);
	}
}
void logicaUpdate( Player* p, Sala* s, Monstruo* m)
{

	// elige una sala aleatoria
	int numSala = p->historia[p->numerodesalas] ;//= rand() % 15;



	if (p->numerodesalas <= 6)
	{
		//A donde quieres ir
		printf("¿Por donde deseas ir? N/S/E/W /n");
		fflush(stdout);
		char r;
		while (r != 'N' && r != 'S' && r != 'E' && r != 'W' && r != 'n'
				&& r != 's' && r != 'e' && r != 'w')
		{

			r = getchar();
			fflush(stdin);
		}

		if (s[numSala].tipo == 0)// SAla de adivinanza
		{
			//pasa algo
			printf("Inicio sala adivinanza \n");
			fflush(stdout);
			sleep(1);

			//supongamos que recibes un array de salas y abres la sala x entonces te aparece un acertijo
			printf("Sala %d: \n %s  \n", numSala + 1, s[numSala].textosDeSala[0]);
			fflush(stdout);
			sleep(1);
			printf("Opcion 1 %s \n", s[numSala].textosDeSala[3]);
			fflush(stdout);
			printf("Opcion 2 %s \n", s[numSala].textosDeSala[4]);
			fflush(stdout);
			printf("Opcion 3 %s \n", s[numSala].textosDeSala[5]);
			fflush(stdout);
			int elec;
			int corr = s[numSala].respuestaCorr;
			do{


				printf("ELIGE TU RESPUESTA CON SABIDURIA (1/2/3): ");
				fflush(stdout);
				scanf("%d", &elec);
				fflush(stdin);
				printf("\n");
				fflush(stdout);
				if(corr!=elec)
				{
					printf("%s \n", s[numSala].textosDeSala[1]);
					fflush(stdout);
					printf("Pierdes 20 de vida\n");
					fflush(stdout);
					p->vida=p->vida-20;
				}

			}while(corr!=elec);
//			system("cls");
			//texto de salida de la
			printf("%s\n",s[numSala].textosDeSala[2]);
			fflush(stdout);


			//Limpia la consola
//			system("cls");
			p->historia[p->numerodesalas+1]=numSala;

			//Sale del bucle


		}
		else if (s[numSala].tipo == 1)//sala de peleas
		{
			printf("Sala %d  \n%s", numSala + 1, s[numSala].textosDeSala[0]);
			//Te has encontrado con un mega monstruo feo
			fflush(stdout);
			//Busca el monstruo con el codigo de sala
			int i=0;
			for(;i<1;i++ )//OJOOOO EL  con el numero de monstruos en el array esta en 1 para probar
			{


				if(s[numSala].codSala == m[i].codsala)
				{


					break;
				}
			}


			int vida = m[i].vida;

			printf("%s  \n" , m[i].interacciones[0]);
			while(vida>0)
			{

				if(p->vida<=0)//Game over
				{
					printf("%s /nVaya, parece que tu vida esta a 0", s[numSala].textosDeSala[2]);
					fflush(stdout);// Texto de game over
					char m;
					m =getchar();
					break;

				}
				//Print de la vida
				printf("%s \n", m[i].nombre);
				printf("Vida del monstruo :");
				fflush(stdout);
				int j=0;
				for(;j<vida;j++)
				{
					printf("|");
					fflush(stdout);
				}
				printf("\n%s:",p->name);

				int k=0;
				for(;k<p->vida;k++)
				{
					printf("|");
					fflush(stdout);
				}

				printf("\n 1 - Espada de palo      2 - Piro++      \n 3-Hielo++          4 - Cura++       \n");
				printf("\n Escoge un arma (1/2/3/4) : ");
				fflush(stdout);
				int eleccion = 0;
				scanf("%i", &eleccion);
				fflush(stdin);
				switch(eleccion)
				{
				case 1:

					vida=vida-20;
					printf("Dañas al monstruo con tu legendaria espadad de madera ");
					fflush(stdout);
					sleep(2);
					p->vida = p->vida - 10;
					printf("Sin embargo el monstruo te goplpea y obviamente recibes daño. ");
					fflush(stdout);
					sleep(1);

					break;

				case 2:
					vida=vida-15;
					printf("Conjuras una gran llama, el animal daña al monstruo, ");
					fflush(stdout);
					p->vida = p->vida - 7;
					sleep(2);
					printf("te escupe y te da asco, genial, ahora tienes baba de llama. ");
					sleep(1);
					break;
				case 3:
					vida=vida-5;
					printf("Enfrias la sala muchisimo, ");
					sleep(2);
					p->vida = p->vida - 3;
					printf(",genial ahora tienes un resfriado! ");
					sleep(1);
					break;
				case 4:
					printf("Aparece un obispo que te echa agua bendita, se curan tus heridas, \nun poco, mas bien casi nada, digamos que es placebo ");
					sleep(1);
					p->vida = p->vida + 20;
					if(p->vida>100)
					{
						p->vida = 100;
					}

					break;
				default:

					printf("La proxima vez ataque subnormal");
					fflush(stdout);
					sleep(2);
					p->vida = p->vida - 10;

					break;
				}



			}


			//texto de salida de la
			printf("\n%s", s->textosDeSala[2]);
			fflush(stdout);
		}
		else if (s[numSala].tipo == 2)// sala en la que consigues algo

		{
			printf("Sala %d  \n %s", numSala + 1, s->textosDeSala[0]);
			fflush(stdout);
			p->vida=100;
			int k=0;
			for(;k<p->vida;k++)
			{
				printf("|");
				fflush(stdout);
				sleep(0.005);
			}


		}

		p->numerodesalas=p->numerodesalas+1;


	}
}

int main()
{

	Player pl;
	crearPlayer(&pl);

	Sala* s = malloc(sizeof(Sala)*30);


	cargarSalas(s);
	printf("Hola 1");
	fflush(stdout);
	//system("cls");



	Monstruo* monstruos=malloc(sizeof(Monstruo)*10);;
	inicializarArrayMonstruos(monstruos);
	printf("Hola 2");
	fflush(stdout);

	creaHistoria(&pl);
	printf("Hola 3");
	fflush(stdout);
	//Bucle constante
	while (pl.vida>=1 && pl.numerodesalas<=6)
	{
		logicaUpdate(&pl ,s , monstruos);

	}
	if(pl.vida<=0)
	{
	printf("----------------- Has perecido, en la cueva de los monstruos ----------------");
	fflush(stdout);
	}
	else
	{
	printf("----------------- ENHORABUENA, HAS SALIDO DE LA CUEVA, AHORA SIGUE CON TU MORTAL VIDA -------------------");
	fflush(stdout);
	}
	return 0;
}

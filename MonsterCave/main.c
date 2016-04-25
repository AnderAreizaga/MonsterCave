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

/*
 * No se usa para nada pero imprime un murloc por pantalla
 */
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

/*
 * Este metodo crea la historia sin repeticiones
 */
void creaHistoria(Player* p)
{
	// elige una sala aleatoria
	int x ;
	int j;
	int i=0;
	srand(time(NULL));
	while (i < 6)
	{
		int r = rand() % 14+1;

		for (x = 0; x < i; x++)
		{
			if (p->historia[x] == r)
			{
				break;
			}
		}
		if (x == i)
		{
			p->historia[i++] = r;
		}
	}
}
void logicaUpdate( Player* p, Sala* s, Monstruo* m)
{

	int numSala;
	if(p->numerodesalas<6){
		numSala = p->historia[p->numerodesalas]-1 ;
	}

	if (p->numerodesalas < 6)
	{
		//A donde quieres ir
		printf("¿Por donde deseas ir? N/S/E/W \n");
		fflush(stdout);
		char r='0';
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
			printf("Sala %d: \n %s  \n", numSala+2, s[numSala].textosDeSala[0]);
			fflush(stdout);
			sleep(1);
			printf("Opcion 1 %s \n", s[numSala].textosDeSala[3]);
			fflush(stdout);
			sleep(1);
			printf("Opcion 2 %s \n", s[numSala].textosDeSala[4]);
			fflush(stdout);
			sleep(1);
			printf("Opcion 3 %s \n", s[numSala].textosDeSala[5]);
			fflush(stdout);
			sleep(1);
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
			//texto de salida de la
			printf("%s\n",s[numSala].textosDeSala[2]);
			fflush(stdout);






		}
		else if (s[numSala].tipo == 1)//sala de peleas
		{
			printf("Sala %d  \n%s", numSala+2, s[numSala].textosDeSala[0]);
			//Te has encontrado con un mega monstruo feo
			fflush(stdout);
			//Busca el monstruo con el codigo de sala
			int i=0;
			for(;i<5;i++ )//OJOOOO EL  con el numero de monstruos en el array esta en 1 para probar
			{


				if(s[numSala].codSala == m[i].codsala)
				{
					printf("%d" ,m[i].codsala);

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
				printf("\n%s \n", m[i].nombre);
				printf("Vida del monstruo :");
				fflush(stdout);
				int j=0;
				for(;j<vida/10;j++)
				{
					printf("|");
					fflush(stdout);
				}
				printf("\n%s:",p->name);

				int k=0;
				for(;k<p->vida/10;k++)
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
					printf("Dañas al monstruo con tu legendaria espadad de madera,");
					fflush(stdout);
					sleep(2);
					p->vida = p->vida - 10;
					printf("Sin embargo el monstruo te goplpea y obviamente recibes daño. \n");
					fflush(stdout);
					sleep(1);

					break;

				case 2:
					vida=vida-15;
					printf("Conjuras una gran llama, el animal daña al monstruo, ");
					fflush(stdout);
					p->vida = p->vida - 7;
					sleep(2);
					printf("te escupe y te da asco, genial, ahora tienes baba de llama. \n");
					sleep(1);
					break;
				case 3:
					vida=vida-5;
					printf("Enfrias la sala muchisimo, ");
					sleep(2);
					p->vida = p->vida - 3;
					printf(",genial ahora tienes un resfriado!\n");
					sleep(1);
					break;
				case 4:
					printf("Aparece un obispo que te echa agua bendita, se curan tus heridas, un poco, mas bien casi nada, digamos que es placebo\n");
					sleep(1);
					p->vida = p->vida + 20;
					if(p->vida>100)
					{
						p->vida = 100;
					}

					break;
				default:

					printf("La proxima vez ataque subnormal\n");
					fflush(stdout);
					sleep(2);
					p->vida = p->vida - 10;

					break;
				}



			}


			//texto de salida de la
			if(p->vida>1)//Game over
			{
			printf("\n%s", s[numSala].textosDeSala[2]);
			fflush(stdout);
			}
		}
		else if (s[numSala].tipo == 2)// sala en la que consigues algo

		{
			printf("Sala %d  \n %s\n", numSala+2 , s[numSala].textosDeSala[0]);
			fflush(stdout);
			sleep(3);
			printf("Tomate un ratete para respirar \n");
			fflush(stdout);
			sleep(1);


		}



	}

	p->numerodesalas=p->numerodesalas+1;//Por el que le habiamos quitado al principio para que no diera out of boundsMike
	printf("Numero de salas pasadas : %d\n",p->numerodesalas);
	fflush(stdout);

}

int main()
{

	Player pl;
	Historia * h1= malloc(sizeof(Historia)*30);
	//Se crea el jugador
	crearPlayer(&pl);

	Sala* s = malloc(sizeof(Sala)*30);

	//Se cargan las salas de fichero
	cargarSalas(s);


	//system("cls");



	Monstruo* monstruos=malloc(sizeof(Monstruo)*10);
	//Se crean los monstruos
	inicializarArrayMonstruos(monstruos);
	//Se carga la historia
	cargarHistoria(h1);

	fflush(stdout);

	creaHistoria(&pl);

	fflush(stdout);

	printf("Life of %s \n\n", pl.name);
	fflush(stdout);
	sleep(1);
	printf("Era una oscura mañana de otoño, %s se disponía a empezar su primer dia en su nuevo trabajo.\n",pl.name);
	fflush(stdout);
	sleep(1);
	printf("Era su oportunidad de servir a la sociedad y por primera vez cumplir su sueño  de ser un héroe,\n");
	fflush(stdout);
	sleep(1);
	printf("alguien que combatiera el mal y salvara al mundo varias veces. Pero sin embargo no era tal\n");
	fflush(stdout);
	sleep(1);
	printf("y como se esperaba, barrer el suelo en la taberna más sucia del barrio no era tan emocionante como pensaba que sería\n");
	fflush(stdout);
	sleep(1);
	printf("cuando le dijeron que su misión principal sería combatir la suciedad con esa escoba. Pero un día unos mercenarios entraron\n");
	fflush(stdout);
	sleep(1);
	printf("mientras él trabajaba, llegaron con el objetivo de cumplir la mision mas dificil que podría\n");
	fflush(stdout);
	sleep(1);
	printf("haber llegado a los oídos de nuestro protagonista: ''Rescatar la gallina de los huevos dorados''\n");
	fflush(stdout);
	sleep(1);

//	Bucle constante
	while (pl.vida>=1 && pl.numerodesalas<6)
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

	printHistoria(&pl,h1);


	return 0;
}

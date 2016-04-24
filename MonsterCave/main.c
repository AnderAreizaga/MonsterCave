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

void nuevasala( Player* p, Sala* s, Monstruo* m)
{

	// elige una sala aleatoria
	int numSala = 0 ;//= rand() % 15;
	int valido = 1; //= 0;
	printf("Llega aqui");
	while (valido != 1)
	{
		int i = 0;
		for (; i < p->numerodesalas; i++)
		{

			if (p->historia[i] == numSala)
			{
				break;
			}


		}
		if (valido == 0)
		{
			numSala = rand() % 15;
		}
	};

	while (p->numerodesalas <= 6) {

		if (s[numSala].tipo == 0)// SAla de adivinanza
		{
			//pasa algo
			printf("entra aqui");
			//supongamos que recibes un array de salas y abres la sala x entonces te aparece un acertijo
			printf("Sala %d  \n %s", numSala + 1, s[numSala].textosDeSala[0]);

			fflush(stdout);
			char* respuesta;
			//Ciclo de sala si acierta bien sino no


//			do {
//				fflush(stdout);
//				fflush(stdin);
//				scanf("%s", &respuesta);
//				if (respuesta != s[numSala].reScorrecta)
//				{
//					printf("%s", s[numSala].textosDeSala[1]);
//				}
//			} while (respuesta != s->reScorrecta);

			//texto de salida de la
			printf("Sala %d  \n %s", numSala + 1, s[numSala].textosDeSala[2]);
			fflush(stdout);


			//Limpia la consola
			system("cls");
			p->historia[p->numerodesalas+1]=numSala;

			//Sale del bucle
			break;

		}
		else if (s[numSala].tipo == 1)//sala de peleas
		{
			printf("Sala %d  \n %s", numSala + 1, s[numSala].textosDeSala[0]);//Te has encontrado con un mega monstruo feo
			//Busca el monstruo con el codigo de sala
			int i=0;
			int k=0;

			for(;i<5;i++ )//Numero de monstruos es igual a 6?
			{

				if(s[numSala].codSala== m[i].codsala)
				{

					//encontrado sale del for
					break;
					k++;
				}

				k++;
			}
			int vida = m[k].vida;
			printf("%s  \n" , m[k].interacciones[0]);
			while(vida>=0)
			{
				int i=0;
				if(p->vida<=0)//Game over
				{
					printf("%s /n   Pulsa cualquier tecla para continuar", s[numSala].textosDeSala[2]);// Texto de game over
					char r;
					r =getchar();
					break;

				}
				//Ciclo de combate
				//Print de la vida
				printf("Vida : ");
				fflush(stdout);
				for(;i<vida;i++)
				{
					printf("|");
					fflush(stdout);
				}

				//No se como ponerlo


				//Escoge una magia?

				printf("/n Escoge un arma (1/2/3/4/5)");
				for(;;)//un bucle donde se muestran los hechizos disponibles
				{


				}
				//Espera una respuesta

				//Se le quita vida y sale respuesta de monstruo de ay me has hecho ¿daño?


				//¿esperar un tiempo?

			}


			//texto de salida de la
			printf("Sala %d  \n %s", numSala + 1, s->textosDeSala[2]);
		}
		else if (s[numSala].tipo == 2)// sala en la que consigues algo

		{
			printf("Sala %d  \n %s", numSala + 1, s->textosDeSala[0]);

			//sala en la que te encuentras con un hechizo random?



		}

		//A donde quieres ir
		printf("¿Por donde deseas ir? N/S/E/W /n");
		fflush(stdout);
		char r;
		while(r!='N'||r!='S'||r!='E'||r!='W'||r!='n'||r!='s'||r!='e'||r!='w')
		{
			fflush(stdin);
			r =getchar();
		}



	}
}

int main()
{

	Player pl;
	crearPlayer(&pl);
	Sala* s = malloc(sizeof(Sala)*30);
	//Monstruo m;

	cargarSalas(s);

	//system("cls");

	printPlayer(pl);

	Monstruo* monstruos=malloc(sizeof(Monstruo)*10);;
	inicializarArrayMonstruos(monstruos);


//	//Bucle constante
//	while (pl.vida>=1 )
//	{
//		nuevasala(&pl ,&s , &m);
//
//	}
	return 0;
}

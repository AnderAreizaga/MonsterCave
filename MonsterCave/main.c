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

//	    int t;
//	    int count;
//	    int i=0;
//
//
//
//	    while (i < 15)
//	    {
//			int r = rand() % 15;
//
//			for (t = 0; t < i; t++)
//			{
//				if (p->historia[t] == r)
//				{
//					break;
//				}
//			}
//			if (t == i)
//			{
//				p->historia[t] = r;
//			}
//		}



	 if (p->numerodesalas <= 6)
	 {
//A donde quieres ir
//		printf("¿Por donde deseas ir? N/S/E/W /n");
//		fflush(stdout);
//		char r;
//		while (r != 'N' || r != 'S' || r != 'E' || r != 'W' || r != 'n'
//				|| r != 's' || r != 'e' || r != 'w')
//		{
//
//			r = getchar();
//			fflush(stdin);
//		}

		if (s[numSala].tipo == 0)// SAla de adivinanza
		{
			//pasa algo
			printf("Inicio sala adivinanza \n");
			fflush(stdout);
			sleep(1);

			//supongamos que recibes un array de salas y abres la sala x entonces te aparece un acertijo
			printf("Sala %d: \n %s  \n", numSala + 1, s[numSala].textosDeSala[0]);
			fflush(stdout);

		    int array[3];
		    int x, o;

		    int i=0;
		    srand(time(NULL));
		    while (i < 3)
		    {
				int r = rand() % 3;

				for (x = 0; x < i; x++)
				{
					if (array[x] == r)
					{
						break;
					}
				}
				if (x == i)
				{
					array[i++] = r;
				}
			}
			for (o = 0; o < 3; o++)
			{
			printf("Opcion %i %s \n" ,o + 1  , s[numSala].textosDeSala[array[o]+3] );
			fflush(stdout);
			sleep(1);
			}
			int elec;
			int corr = rand() % 3+1;
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
			system("cls");
			//texto de salida de la
			printf("%s\n",s[numSala].textosDeSala[2]);
			fflush(stdout);


			//Limpia la consola
			system("cls");
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
				printf("¿Peta aqui? \n");
				fflush(stdout);
				if(s[numSala].codSala == m[i].codsala)
				{
					printf("¿Peta aqui? \n");
					fflush(stdout);
					break;
				}
			}
			printf("¿Peta aqui? \n");
			fflush(stdout);
			int vida = m[i].vida;

			printf("%s  \n" , m[i].interacciones[0]); // <---------------------- AQUI PETA ------------------------------------------------------------
			while(vida>=0)
			{

				if(p->vida<=0)//Game over
				{
					printf("%s /n   Pulsa cualquier tecla para continuar", s[numSala].textosDeSala[2]);// Texto de game over
					char m;
					m =getchar();
					break;

				}
				//Print de la vida
				printf("Vida del monstruo : ");
				fflush(stdout);
				for(;i<vida;i++)
				{
					printf("|");
					fflush(stdout);
				}

				printf("/n Escoge un arma (1/2/3/4)");
				printf("/n 1 - Espada de palo      2 - Piro++      \n 3-Hielo++          4 - Cura++       ");

				int k;
				printf("Tu vida :");
				for(;k<p->vida;k++)
				{
					printf("|");
					fflush(stdout);
				}
				int eleccion = 0;
				scanf("%i", &eleccion);
				fflush(stdin);
				switch(eleccion)
				{
				case 1:

					vida=vida-20;
					p->vida = p->vida - 10;

					break;
				case 2:
					vida=vida-15;
					p->vida = p->vida - 7;

					break;
				case 3:
					vida=vida-5;
					p->vida = p->vida - 3;


					break;
				case 4:
					p->vida = p->vida + 20;

					break;
				default:

					printf("La proxima vez ataque subnormal");
					fflush(stdout);
					sleep(2);
					p->vida = p->vida - 10;

				break;
				}




				//Espera una respuesta

				//Se le quita vida y sale respuesta de monstruo de ay me has hecho ¿daño?


				//¿esperar un tiempo?

			}


			//texto de salida de la
			printf("Sala %d  \n %s", numSala + 1, s->textosDeSala[2]);
		}
//		else if (s[numSala].tipo == 2)// sala en la que consigues algo
//
//		{
//			printf("Sala %d  \n %s", numSala + 1, s->textosDeSala[0]);
//
//			//sala en la que te encuentras con un hechizo random?
//
//
//
//		}





	}
}

int main()
{

	Player pl;
	crearPlayer(&pl);

	Sala* s = malloc(sizeof(Sala)*30);


	cargarSalas(s);

	//system("cls");



	Monstruo* monstruos=malloc(sizeof(Monstruo)*10);;
	inicializarArrayMonstruos(monstruos);


	//Bucle constante
	while (pl.vida>=1 && pl.numerodesalas<=6)
	{
		nuevasala(&pl ,s , monstruos);

	}
	printf("----------------- HAS LLEGADO A LA SALIDA, ENHORABUENA ----------------");
	return 0;
}

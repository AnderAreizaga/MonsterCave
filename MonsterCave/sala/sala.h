/*
 * sala.h
 *
 *  Created on: 7 de abr. de 2016
 *      Author: ander
 */

#ifndef SALA_H_
#define SALA_H_

typedef struct{


	int codSala; //de 0 a 29
	int tipo; // 0: Adivinanza 1: Pelea 2: No recuerdo, igual era sala de movimiento simple
	// char* resCorrecta;
	char** textosDeSala;  // Son normalmente 1º estado de presentacion, 2º estado de fallido(respuesta incorrecta) 3º puedes seguir
	//en el caso de sala de monstruos el estado 2 se repite hasta que la vida del monstruo tenga 0 vida
	//el cambio de sala siempre es aleatorio


}Sala;


void cargarSalas(Sala *puntS);
//no se si tiene que recibir un puntero o un file f la cosa es que tiene que cargar salas, y meter correctamente los strings en cada sala
//Hay que pensar como quereis meter las osas en el etc



#endif /* SALA_H_ */

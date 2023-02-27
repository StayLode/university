/*
 * tipo.h
 *
 *  Created on: 17 set 2021
 *      Author: Gabriel
 */

typedef struct {
	char data[7];
	char ora_i[5];
	char ora_f[5];
	char descr[51];
} tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);




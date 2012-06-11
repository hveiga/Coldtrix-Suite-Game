//   Leds.c

//
// Authors:
//   Luis Antonio Úbeda Medina (lubeme23@gmail.com)
//   Héctor Veiga Ortiz (hveiga@hawk.iit.edu)
//
// Copyright 2010 Héctor Veiga Ortiz and Luis Antonio Úbeda Medina.
//
// This file is part of Coldtrix Game Suite.
// 
// Coldtrix Game Suite is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Coldtrix Game Suite is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Coldtrix Game Suite.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include "leds.h"

//------------------------------------------------------

// void excitaFilas(int col)

//

// Descripción:

//   Excita las filas donde tenemos el tablero ocupado

//------------------------------------------------------
void excitaFilas(int col){
	int fila=0;
	for (fila=0;fila<ALTO;fila++){
		if(arrayTablero[fila][col] == ON){
			filaXEncender(fila); //Si la posicion está ocupada es que hay pieza, y por lo tanto encendemos el LED
		}
	}
}

//------------------------------------------------------

// void excitaFilasPiezaSiguiente(int col)

//

// Descripción:

//   Excita las filas de la matriz de la pieza siguiente

//------------------------------------------------------
void excitaFilasPiezaSiguiente(int col){
	int fila = 0;

	for (fila = PRIM_FILA_PS;fila<ULTI_FILA_PS;fila++){
		if(matrizPS[fila-PRIM_FILA_PS][col] == ON){
			filaXEncender(fila); //Si la posicion está ocupada es que hay pieza, y por lo tanto encendemos el LED
		}
	}
}

//------------------------------------------------------

// void pintaPiezaSiguiente(int pieza)
//

// Descripción:

//   Pinta la pieza siguiente en su matriz

//------------------------------------------------------
void pintaPiezaSiguiente(int pieza) {
	int i,j;
	
	for(i = 0;i < ALTO_PS; i++) {
		for(j = 0;j < ANCHO_PS; j++) {
			matrizPS[i][j] = matricesPS[pieza][i][j]; //Cargamos la pieza en la matriz
		}
	}		
}
	

//------------------------------------------------------

// void seleccionaColumna(int col)
//

// Descripción:

//   Selecciona la columna a excitar 

//------------------------------------------------------
void seleccionaColumna(int col){
	borraFilas();
	columnaXActiva(col);
	if((col == COLUMNA4) || (col == COLUMNA5)) {
		if(col == COLUMNA4) { excitaFilasPiezaSiguiente(COL0PS); }
		if(col == COLUMNA5) { excitaFilasPiezaSiguiente(COL1PS); }
	} else {
		excitaFilas(col);
	}
}

//------------------------------------------------------

// void pintaArrayLeds(void) 

//
// Descripción:

//   Método de ayuda para pintar el tablero por consola

//------------------------------------------------------		
void pintaArrayLeds(void) {
	int i,j;
	output("\n");
	for (i=0;i<ALTO;i++){
		for(j=0;j<ANCHO;j++){
			outNum(BASE10, arrayTablero[i][j], OP_OUTNUM);
			output(" ");
		}
	output("\n");
	}	
}
//------------------------------------------------------

// void pintaBloques(void) 

//

// Descripción:

//   Método de pintado de un numero aleatorio de bloques
//   en una posición también aleatoria.

//------------------------------------------------------
void pintaBloques(void) {
	 int i;
	 int rand_ancho;
	 int rand_alto;	     
     	 int randNumeroBloques=(mbar_readShort(MCFSIM_TCN1) % COEF12);

   	 for(i =0;i<randNumeroBloques;i++){
      		 rand_ancho = (mbar_readShort(MCFSIM_TCN1) % COEF4);
      		 rand_alto = (mbar_readShort(MCFSIM_TCN1) % COEF3);
	
      		arrayTablero[ALTO - rand_alto][rand_ancho] = ON ;
	}      
}
	
	
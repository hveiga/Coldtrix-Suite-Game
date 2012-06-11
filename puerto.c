//   Puerto.c

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

#include "Puerto.h"

TpuertoSal puerto; //Creamos el objeto puerto

//------------------------------------------------------

// void puertoInic(void)

//

// Descripción:

//   Inicializa el objeto puerto

//------------------------------------------------------
void puertoInic(void){
	puerto.varAux = HEX_CERO; //Inicializamos el valor auxiliar del puerto
	}


//------------------------------------------------------

// void borraFilas(void)

//

// Descripción:

//   Borra la excitacion de las filas del tablero

//------------------------------------------------------	
void borraFilas(void){
	puerto.varAux = puerto.varAux | MASCARA_FILAS;
	}

//------------------------------------------------------

// void limpiadoFinJuego(void)

//

// Descripción:

//   Borramos todas las excitaciones del puerto

//------------------------------------------------------	
void limpiadoFinJuego(void){
	puerto.varAux = puerto.varAux & HEX_UNO;
	set16_puertoS(puerto.varAux);
}

//------------------------------------------------------

// void puerto_excitaColumnaTeclado(void) 

//

// Descripción:

//   Rutina de excitacion del pin del teclado

//------------------------------------------------------	
void puerto_excitaColumnaTeclado(void) {
	puerto.varAux = puerto.varAux & MASCARA_TECLADO;
	puerto.varAux = puerto.varAux | EXCIT_TECLADO;
	set16_puertoS(puerto.varAux);

}


//------------------------------------------------------

// void filaXEncender(int fila)

//

// Descripción:

//   Rutina de excitacion de la fila pasada por parámetro

//------------------------------------------------------	
void filaXEncender(int fila) {
	UWORD mascara;
	
	switch(fila) {
		case F0:
			mascara = MASCARA_F0;
			break;
		case F1:
			mascara = MASCARA_F1;
			break;
		case F2:
			mascara = MASCARA_F2;
			break;
		case F3:
			mascara = MASCARA_F3;
			break;
		case F4:
			mascara = MASCARA_F4;
			break;
		case F5:
			mascara = MASCARA_F5;
			break;
		case F6:
			mascara = MASCARA_F6;
			break;
		case F7:
			mascara = MASCARA_F7;
			break;
		
	}
	
	puerto.varAux = puerto.varAux & mascara;
	set16_puertoS(puerto.varAux);
}


//------------------------------------------------------

// void columnaXActiva(int col)

//

// Descripción:

//   Rutina de excitacion de la columna pasada por parámetro

//------------------------------------------------------
void columnaXActiva(int col) {
	UWORD mascara;
	
	switch(col) {
		case C0:
			mascara = MASCARA_C0;
			break;	
		case C1:
			mascara = MASCARA_C1;
			break;	
		case C2:
			mascara = MASCARA_C2;
			break;	
		case C3:
			mascara = MASCARA_C3;
			break;	
		case C4:
			mascara = MASCARA_C4;
			break;	
		case C5:
			mascara = MASCARA_C5;
			break;	
	
	}
	
	puerto.varAux = puerto.varAux & MASCARA_COLUMNAS;
	puerto.varAux = puerto.varAux | mascara;
	set16_puertoS(puerto.varAux);
}
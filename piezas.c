//------------------------------------------------------------------------------
//   Piezas.c

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

#include "piezas.h"

//------------------------------------------------------

// int evaluaAnchura(Tpieza pieza)

//

// Descripción:

//   Rutina de evaluacion de anchura de una pieza

//------------------------------------------------------
/*int evaluaAnchura(Tpieza pieza) {
	int i, j;
	int ancho = 0;
	int maxAnchAnterior = 0;
	for(i = 0; i < MAX_TAMANO; i++){
		for(j = maxAnchAnterior; j < MAX_TAMANO; j++){
			if(pieza.matrizPiezaLive[i][j]==1){
				ancho = j+1;
				}
			}
		maxAnchAnterior = ancho;  
		if(ancho == MAX_TAMANO) {
			return ancho; //Devolvemos el ancho de la pieza
		}
	}
	return ancho; //Devolvemos el ancho de la pieza
} */

//------------------------------------------------------

// int evaluaAnchuraPUNTEROS(Tpieza *pieza)

//

// Descripción:

//   Rutina de evaluacion de anchura de una pieza

//------------------------------------------------------
int evaluaAnchuraPUNTEROS(Tpieza *pieza) {
	int i, j;
	int ancho = 0;
	int maxAnchAnterior = 0;
	for(i = 0; i < MAX_TAMANO; i++){
		for(j = maxAnchAnterior; j < MAX_TAMANO; j++){
			if(pieza->matrizPiezaLive[i][j]==1){
				ancho = j+1;
				}
			}
		maxAnchAnterior = ancho;  
		if(ancho == MAX_TAMANO) {
			return ancho; //Devolvemos el ancho de la pieza
		}
	}
	return ancho; //Devolvemos el ancho de la pieza
}

	
//------------------------------------------------------

// int evaluaAltura(Tpieza pieza)

//
// Descripción:

//   Rutina de evaluacion de altura de una pieza

//------------------------------------------------------
/*int evaluaAltura(Tpieza pieza) {
	int i, j;
	int alto = 0;
	int maxAltAnterior = 0;
	for(i = 0; i < MAX_TAMANO; i++){
		for(j = maxAltAnterior; j < MAX_TAMANO; j++){
			if(pieza.matrizPiezaLive[j][i]==1){
				alto = j+1;
				}
			}
		maxAltAnterior = alto;
		if(alto == MAX_TAMANO){
			return alto; //Devolvemos el alto de la pieza
		}
	}
	return alto; //Devolvemos el alto de la pieza
} */
	
//------------------------------------------------------

// int evaluaAlturaPUNTEROS(Tpieza *pieza)

//

// Descripción:

//   Rutina de evaluacion de altura de una pieza

//------------------------------------------------------
int evaluaAlturaPUNTEROS(Tpieza *pieza) {
	int i, j;
	int alto = 0;
	int maxAltAnterior = 0;
	for(i = 0; i < MAX_TAMANO; i++){
		for(j = maxAltAnterior; j < MAX_TAMANO; j++){
			if(pieza->matrizPiezaLive[j][i]==1){
				alto = j+1;
				}
			}
		maxAltAnterior = alto;
		if(alto == MAX_TAMANO){
			return alto; //Devolvemos el alto de la pieza
		}
	}
	return alto; //Devolvemos el alto de la pieza
}
	
//------------------------------------------------------

// void rotaPieza(void)

//
// Descripción:

//   Rutina de rotacion de una pieza

//------------------------------------------------------	
/*void rotaPieza(void) {
	int i,j;
	piezaAux.rotacion++; //Rotamos la pieza una posicion
	
	if(piezaAux.rotacion > MAX_ROTACION){
		piezaAux.rotacion = 0;
	}
	
	for(i = 0;i < MAX_TAMANO;i++) {
		for(j = 0;j < MAX_TAMANO;j++) {
			piezaAux.matrizPiezaLive[i][j]=piezaAux.matricesPieza[piezaAux.rotacion][i][j];
			
		}
	}
	
	piezaAux.anchura = evaluaAnchura(piezaAux);
	piezaAux.altura = evaluaAltura(piezaAux);	
} */

//------------------------------------------------------

// void rotaPiezaPUNTEROS(Tpieza *piezaAuxP)

//

// Descripción:

//   Rutina de rotacion de una pieza

//------------------------------------------------------	
void rotaPiezaPUNTEROS(Tpieza *piezaAuxP) {
	int i,j;
	piezaAuxP->rotacion++; //Rotamos la pieza una posicion
	
	if(piezaAuxP->rotacion > MAX_ROTACION){
		piezaAuxP->rotacion = 0;
	}
	
	for(i = 0;i < MAX_TAMANO;i++) {
		for(j = 0;j < MAX_TAMANO;j++) {
			piezaAuxP->matrizPiezaLive[i][j]=piezaAuxP->matricesPieza[piezaAuxP->rotacion][i][j];
			
		}
	}
	
	piezaAuxP->anchura = evaluaAnchuraPUNTEROS(piezaAuxP);
	piezaAuxP->altura = evaluaAlturaPUNTEROS(piezaAuxP);	
}

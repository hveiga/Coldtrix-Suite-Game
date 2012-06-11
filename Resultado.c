//------------------------------------------------------------------------------
//   Resultado.c

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
#include "resultado.h"

Tresultado resultado; //Creamos el objeto resultados

//------------------------------------------------------

// void resultadoInic(void)

//

// Descripción:

//   Inicializa el objeto resultado

//------------------------------------------------------
void resultadoInic(void) {
	resultado.puntos = 0;
	resultado.lineas = 0;
	resultado.tetris = 0;
	resultado.comidas = 0;
	resultado.tiempo = 0;	
}

//------------------------------------------------------

// int getResultado(void)

//

// Descripción:

//   Devuelve el resultado en puntos
//------------------------------------------------------
int getResultado(void) {
	int result = 0;
	
	if(estado.juego==JUEGO_TETRIS){
		result = resultado.puntos;
	}
	
	if(estado.juego==JUEGO_SNAKE){
		result = resultado.comidas * PUNTOS_COMIDA; //Sacamos los puntos multiplicando por un coeficiente
	}
	
	return result; //Devolvemos el resultado
}
//------------------------------------------------------

// void setResultado(void)

//

// Descripción:

//   Establece el numero de puntos conseguidos en cada jugada

//------------------------------------------------------
void setResultado(int lineas){
	int puntos = BASE_FACTORIAL;
	int i;
	
	if(lineas == 0) { return; }
	
	for(i=INICIO_CUENTA;i<=lineas;i++){
		puntos=puntos*i;
	}
	resultado.puntos+=puntos*PUNTOS_LINEA;
}


//------------------------------------------------------

// int getTetris(void)

//

// Descripción:

//   Devuelve el numero de tetris

//------------------------------------------------------
int getTetris(void) {
	return resultado.tetris;
}

//------------------------------------------------------

// int getTiempo(void)

//

// Descripción:

//   Devuelve el numero de tetris

//------------------------------------------------------
int getTiempo(void) {
	return resultado.tiempo;
}

//------------------------------------------------------

// double getFilasPorSegundo(void)

//

// Descripción:

//   Devuelve el numero de filas por segundo

//------------------------------------------------------
double getFilasPorSegundo(void) {
	return (double)resultado.lineas/(double)resultado.tiempo;
}

//------------------------------------------------------

// double getPuntosPorSegundo(void)

//

// Descripción:

//   Devuelve el numero de puntos por segundo

//------------------------------------------------------
double getPuntosPorSegundo(void) {
	return (double)resultado.puntos/(double)resultado.tiempo;
}

//------------------------------------------------------

// double getComidasPorSegundo(void)

//

// Descripción:

//   Devuelve el numero de comidas por segundo

//------------------------------------------------------
double getComidasPorSegundo(void) {
	return (double)resultado.comidas/(double)resultado.tiempo;
}
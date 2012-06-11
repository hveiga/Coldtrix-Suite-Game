//------------------------------------------------------------------------------
// XT-2.c
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
#define V_BASE 0x40				  // Dirección de inicio de los vectores de interrupción
#define DIR_VTMR0 4*(V_BASE+5)			  // Dirección del vector de TMR0
#define DIR_VTMR1 4*(V_BASE+6)			  // Dirección del vector de TMR1
#define DIR_VTMR2 4*(V_BASE+7)			  // Dirección del vector de TMR2
#define DIR_VTMR3 4*(V_BASE+8)			  // Dirección del vector de TMR3


#include "m5272.h"
#include "m5272lib.c"
#include "m5272gpio.c"
#include "m5272adc_dac.c"

#include "DAC.c"
#include "puerto.c"
#include "estado.c"
#include "melodias.c"
#include "teclado.c"
#include "piezas.c"
#include "leds.c"
#include "resultado.c"

#include "pantalla.c"
#include "posicion.c"
#include "snake.c"
#include "juego.c"
#include "relojes.c"

//------------------------------------------------------
// void bucleMain(void)
//
// Descripción:
//   Función del programa principal
//------------------------------------------------------
void bucleMain(void){
  while(TRUE) {
	 if(estado.jugando == NO_JUGANDO) {
		seleccionJuego();
	} else {
		if(estado.juego == JUEGO_TETRIS) { bucleMainTetris(); }
		if(estado.juego == JUEGO_SNAKE) { bucleMainSnake(); }
				
	}
    }	
}

//------------------------------------------------------
// void rutina_tout1(void)
//
// Descripción:
//   Función de atención a la interrupción para TIMER1
//------------------------------------------------------
void rutina_tout1(void) {

	mbar_writeShort(MCFSIM_TER1,BORRA_REF); // Reset del bit de fin de cuenta
		
	if(estado.jugando==JUGANDO) {
		actualizaRelojes();
	}

	

}

//------------------------------------------------------
// void rutina_tout2(void)
//
// Descripción:
//   Función de atención a la interrupción para TIMER2
//------------------------------------------------------
void rutina_tout2(void) {

	mbar_writeShort(MCFSIM_TER2,BORRA_REF);  // Reset del bit de fin de cuenta
		
	if((estado.jugando==JUGANDO) && (estado.juego == JUEGO_TETRIS)) {
		actualizaTiempoMelodia();
	}
	
 
}


//------------------------------------------------------
// void rutina_tout3(void)
//
// Descripción:
//   Función de atención a la interrupción para TIMER3
//------------------------------------------------------
void rutina_tout3(void){
	mbar_writeShort(MCFSIM_TER3,BORRA_REF);     // Reset del bit de fin de cuenta

	if(estado.jugando == NO_JUGANDO) {
		if(cont_retardo > 0){
       		cont_retardo--;                	  // Decrementa el contador cada 125us
      		}
      	}	
}

//------------------------------------------------------
// void __init(void)
//
// Descripción:
//   Función por defecto de inicialización del sistema
//------------------------------------------------------
void __init(void) {
	puertoInic();
	tecladoInic();
	estadoInic();
	resultadoInic();
	juegoInic();
	relojesInic();
	DACInic();
}

//---------------------------------------------------------
// Definición de rutinas de atención a la interrupción
// Es necesario definirlas aunque estén vacías
void rutina_int1(void){}
void rutina_int2(void){}
void rutina_int3(void){}
void rutina_int4(void){}
void rutina_tout0(void){}



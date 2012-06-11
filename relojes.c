//   Relojes.c

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

#include "Relojes.h"

//------------------------------------------------------

// void relojesInic(void)

//

// Descripción:

//   Inicializamos los relojes

//------------------------------------------------------
void relojesInic(void) {
  mbar_writeByte(MCFSIM_PIVR,V_BASE);				// Fija comienzo de vectores de interrupción en V_BASE.

  ACCESO_A_MEMORIA_LONG(DIR_VTMR0)= (ULONG)_prep_TOUT0; 	// Escribimos la dirección de la función para TMR0
  mbar_writeShort(MCFSIM_TMR0, (PRESCALADO-1)<<8|0x28);		// TMR0: PS=1-1=0 CE=00 OM=1 ORI=0 FRR=1 CLK=00 RST=0
  mbar_writeShort(MCFSIM_TCN0, 0x0000);				// Ponemos a 0 el contador del TIMER0
  mbar_writeShort(MCFSIM_TRR0, CNT_INT0);			// Fijamos la cuenta final del contador

  ACCESO_A_MEMORIA_LONG(DIR_VTMR1)= (ULONG)_prep_TOUT1; 	// Escribimos la dirección de la función para TMR1
  mbar_writeShort(MCFSIM_TMR1, (PRESCALADO-1)<<8|0x3D);		// TMR1: PS=1-1=0 CE=00 OM=1 ORI=1 FRR=1 CLK=10 RST=1
  mbar_writeShort(MCFSIM_TCN1, 0x0000);				// Ponemos a 0 el contador del TIMER1
  mbar_writeShort(MCFSIM_TRR1, CNT_INT1);			// Fijamos la cuenta final del contador


  ACCESO_A_MEMORIA_LONG(DIR_VTMR2)= (ULONG)_prep_TOUT2; 	// Escribimos la dirección de la función para TMR2
  mbar_writeShort(MCFSIM_TMR2, (PRESCALADO-1)<<8|0x3D);		// TMR2: PS=1-1=0 CE=00 OM=1 ORI=1 FRR=1 CLK=10 RST=1
  mbar_writeShort(MCFSIM_TCN2, 0x0000);				// Ponemos a 0 el contador del TIMER2
  mbar_writeShort(MCFSIM_TRR2, CNT_INT2);			// Fijamos la cuenta final del contador
  
  ACCESO_A_MEMORIA_LONG(DIR_VTMR3)= (ULONG)_prep_TOUT3; 	// Escribimos la dirección de la función para TMR3
  mbar_writeShort(MCFSIM_TMR3, 0x4F3D);				// TMR3: PS=0x50-1 CE=00 OM=1 ORI=1 FRR=1 CLK=10 RST=1
  mbar_writeShort(MCFSIM_TCN3, 0x0000);				// Ponemos a 0 el contador del TIMER3
  mbar_writeShort(MCFSIM_TRR3, CNT_INT3);			// Fijamos la cuenta final del contador
  

  mbar_writeLong(MCFSIM_ICR1, 0x88888CDE);			// Mascaras de prioridad

  sti(); 							//Habilitamos interrupciones

  relojMov.cuenta = 0;
  relojCuentaTiempo.cuenta = 0;
  relojMelodia.cuenta = 0;
}


//------------------------------------------------------

// void actualizaRelojes(void)

//

// Descripción:

//   Función actualización de relojes

//------------------------------------------------------

void actualizaRelojes(void) {
	int numColsExcitadas;
	static int colUpdate = 0;
	
	relojMov.cuenta++; //Actualizamos el reloj de mover pieza o actualizar serpiente
	relojCuentaTiempo.cuenta++; //Actualizamos el reloj de contar tiempo
	
	colUpdate++; //Actualizamos la columna a excitar
	if(estado.juego == JUEGO_TETRIS) { numColsExcitadas = NUM_COLS_TETRIS; }
	if(estado.juego == JUEGO_SNAKE) { numColsExcitadas = NUM_COLS_SNAKE;  }	
	
	if(colUpdate >= numColsExcitadas) { colUpdate = 0; }
	seleccionaColumna(colUpdate);
	
	if((relojMov.cuenta >= (COEF_TIEMPO * estado.nivel)) && (estado.recursoLibre == LIBRE)) {
		relojMov.cuenta = 0;
		if(estado.juego == JUEGO_TETRIS) { caePieza(); }
		if(estado.juego == JUEGO_SNAKE) { avanza(); }		
		
	}
	
	if(relojCuentaTiempo.cuenta >= COEF_CUENTA_TIEMPO) {
		resultado.tiempo++;
		relojCuentaTiempo.cuenta = 0;
	}
	
}

//------------------------------------------------------

// void actualizaTiempoMelodia(void)

//

// Descripción:

//   Función actualización de reloj de melodia

//------------------------------------------------------
void actualizaTiempoMelodia(void) {
	if(relojMelodia.cuenta >= COEF_CUENTA_MELODIA) { 
		compruebaTiempoMelodia();
		relojMelodia.cuenta = 0;
	}
	relojMelodia.cuenta++;
}
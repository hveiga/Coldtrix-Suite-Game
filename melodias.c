//------------------------------------------------------------------------------
//   melodias.c

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

#include "melodias.h"

//------------------------------------------------------

// void enciendeMelodia(void)

//

// Descripción:

//   Inicia la melodia

//------------------------------------------------------
void enciendeMelodia(void) {
	melodia.notaActual = 0;
	mbar_writeShort(MCFSIM_TMR0, (PRESCALADO-1)<<8|0x2D); //Comentar que metemos en los registros
	mbar_writeShort(MCFSIM_TRR0, MCF_CLK/(melodia.frecTetris[melodia.notaActual]*PRESCALADO*16*(MODIFICADOR_FREC-estado.nivel)));
}

//------------------------------------------------------

// void melodiasInic(void)

//

// Descripción:

//   Inicializa el objeto melodia

//------------------------------------------------------
void melodiasInic(void) {
	melodia.flagTNota = 0;
	melodia.notaActual = 0;
	enciendeMelodia(); //Encendemos la melodía
}

//------------------------------------------------------

// void pararMelodia(void)

//

// Descripción:

//   Detiene la melodia

//------------------------------------------------------
void pararMelodia(void) {
	mbar_writeShort(MCFSIM_TMR0, (PRESCALADO-1)<<8|0x28); //Apagamos el timer
}



//------------------------------------------------------

// void cambiarFrecuencia(void)

//

// Descripción:

//   Función actualización de relojes

//------------------------------------------------------ 
void cambiaFrecuencia(void){
        mbar_writeShort(MCFSIM_TCN0, 0x0000);				// Ponemos a 0 el contador del TIMER0
	
	if(melodia.frecTetris[melodia.notaActual] == 0) {
		mbar_writeShort(MCFSIM_TMR0, (PRESCALADO-1)<<8|0x28);

	} else {
		if(melodia.notaActual - UNO >= 0) {
			if(melodia.frecTetris[melodia.notaActual-1] == 0) { 		//Reiniciamos el contador tras un silencio
				mbar_writeShort(MCFSIM_TMR0, (PRESCALADO-1)<<8|0x2D); //Comentar que metemos en los registros
                  	}
			mbar_writeShort(MCFSIM_TRR0, MCF_CLK/(melodia.frecTetris[melodia.notaActual]*PRESCALADO*16*(MODIFICADOR_FREC-estado.nivel)));
		}
		mbar_writeShort(MCFSIM_TRR0, MCF_CLK/(melodia.frecTetris[melodia.notaActual]*PRESCALADO*16*(MODIFICADOR_FREC-estado.nivel)));

	}
				
}


//------------------------------------------------------

// void compruebaTiempoMelodia(void)

//

// Descripción:

//   Función actualización de relojes

//------------------------------------------------------
void compruebaTiempoMelodia(void) {
	if(melodia.flagTNota>=melodia.tiempoMelodias[melodia.notaActual]) {
		melodia.flagTNota=0;
		melodia.notaActual++;
		cambiaFrecuencia();
		if(melodia.notaActual >= NUM_TIEMPOS) {
			enciendeMelodia();
		}
	}	
	melodia.flagTNota++;

}

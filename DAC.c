//------------------------------------------------------------------------------
// DAC.c
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
#include "DAC.h"
#include "PorFavorSeleccionElJuego.c"
#include "SeleccioneElModoDeJuego.c"
#include "SeleccioneElNivelDeJuego.c"


volatile ULONG cont_retardo;

//------------------------------------------------------
// void DACInic(void)
//
// Descripción:
//   Función que inicializa el DAC.
//
//------------------------------------------------------
void DACInic(void)
{
      DAC_ADC_init();
}

//------------------------------------------------------
// void sleep(ULONG)
//
// Descripción:
//   Espera el tiempo que le especifiquemos como parametro
//------------------------------------------------------
void sleep(ULONG retardo)
   {
      cont_retardo = retardo;    // Inicializa el contador
      while(cont_retardo > 0);    // Espera a que llegua a cero
      return;
   }

//------------------------------------------------------
// void reproducirDAC(int array)
//
// Descripción:
//   Reproduce un sonido mediante el DAC
//------------------------------------------------------
void reproducirDAC(int array){
	int i,dato;
	
	switch(array) {
		case DAC_JUEGO:
		    for(i=0;i<sizeof(ArrayJuego)/sizeof(int);i++){
        	    	dato=ArrayJuego[i];
        	    	DAC_dato(dato);
         	    	sleep(RET_DAC_125US);   //Esperamos 1/8000 segundos (Frecuencia de muestreo de la señal de audio)
      		    }
		    break;
			
		case DAC_MODO:
		    for(i=0;i<sizeof(ArrayModo)/sizeof(int);i++){
        	    	dato=ArrayModo[i];
        	    	DAC_dato(dato);
         	    	sleep(RET_DAC_125US);   //Esperamos 1/8000 segundos (Frecuencia de muestreo de la señal de audio)
      		    }
		    break;
				
		case DAC_NIVEL:
		    for(i=0;i<sizeof(ArrayNivel)/sizeof(int);i++){
        	    	dato=ArrayNivel[i];
        	    	DAC_dato(dato);
         	    	sleep(RET_DAC_125US);   //Esperamos 1/8000 segundos (Frecuencia de muestreo de la señal de audio)
      		    }
		    break;
		
	}
	
 }


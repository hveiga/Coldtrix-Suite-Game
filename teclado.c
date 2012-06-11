//------------------------------------------------------------------------------

// Teclado.c
//
// Authors:
//   Luis Antonio �beda Medina (lubeme23@gmail.com)
//   H�ctor Veiga Ortiz (hveiga@hawk.iit.edu)
//
// Copyright 2010 H�ctor Veiga Ortiz and Luis Antonio �beda Medina.
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

#define NUM_FILAS 4

#define NUM_COLS 1

#define EXCIT 1
#define RETARDO 1150


//------------------------------------------------------

// void tecladoInic(void)

//

// Descripci�n:

//   Excita la primera columna del teclado (�nica que usaremos)

//   

//------------------------------------------------------
void tecladoInic(void){
	puerto_excitaColumnaTeclado();	// Se env�a la excitaci�n de columna
}

//------------------------------------------------------

// char teclado(void)

//

// Descripci�n:

//   Explora el teclado matricial y devuelve la tecla 

//   pulsada

//------------------------------------------------------

char teclado(void)
{
  
BYTE fila, fila_mask;
  
static char teclas[NUM_FILAS] = {"147A"};

  // Bucle de exploraci�n del teclado
  
while(TRUE){

      // Exploramos las filas en busca de respuesta
      
  for(fila = NUM_FILAS - 1; fila >= 0; fila--){
        
    fila_mask = EXCIT << fila;		// M�scara para leer el bit de la fila actual
        
    if(lee_puertoE() & fila_mask){		// Si encuentra tecla pulsada,
          
      while(lee_puertoE() & fila_mask);	//   Esperamos a que se suelte
          
        retardo(RETARDO);			//   Retardo antirrebotes
          
        return teclas[fila];		//   Devolvemos la tecla pulsada
        
      }
      
    }
    // Exploraci�n finalizada sin encontrar una tecla pulsada
  
  }
  // Reiniciamos exploraci�n

}


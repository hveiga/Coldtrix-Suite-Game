//------------------------------------------------------------------------------
//   melodias.h

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

#define NUM_TIEMPOS 55
#ifndef PRESCALADO
#define PRESCALADO 2
#endif

#define MODIFICADOR_FREC 4
#define UNO 1

typedef struct {
	int frecTetris[NUM_TIEMPOS];
	int tiempoMelodias[NUM_TIEMPOS];
	int notaActual;
	int flagTNota;
}Tmelodia;
	
Tmelodia melodia = 	{	{1319, 988, 1047, 1175,
		    		 1047, 988, 880, 880,
		   		 1047, 1319, 1175, 1047,
		   		 988, 988, 1047, 1175,
		   		 1319, 1047, 880, 880,
		   		 0, 1175, 1397, 1760,
		   		 1568, 1397, 1319, 1047,
		  		 1319, 1175, 1047, 988,
		   		 988, 1047, 1175, 1319,
		   		 1047, 880, 880, 0, 
		   		 659,523, 587, 494,
		   		 523,440, 415, 659,
		   		 523,587, 494, 523,
		   		 659,880, 831} ,
		
				{2, 1, 1, 2, 
				 1, 1, 2, 1, 
				 1, 2, 1, 1, 
				 2, 1, 1, 2, 
			         2, 2, 2, 2, 
				 3, 2, 1, 2, 
				 1, 1, 3, 1, 
				 2, 1, 1, 2, 
				 1, 1, 2, 2, 
				 2, 2, 2, 1, 
				 4, 4, 4, 4, 
				 4, 4, 8, 4, 
				 4, 4, 4, 2, 
			         2, 4, 8},
			
				 0,0};
//------------------------------------------------------------------------------
//   relojes.h
//
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


#define FREC_INT1 250			  	  // Frec. de interr. TMR1 = 250 Hz (cada 4ms)
#define FREC_INT2 40			  	  // Frec. de interr. TMR2 = 40 Hz (cada 25ms)
#define FREC_INT3 8000                  	  // Frec. de interr. TMR3 = 8000 Hz (cada 1/8000 seg)

#define PRESCALADO 2
#define PRESCALADO3 0x4F

#define CNT_INT0 MCF_CLK/(FREC_INT1*PRESCALADO*16)	  // Valor de precarga del temporizador de interrupciones TRR0
#if CNT_INT0>0xFFFF
#error PRESCALADO demasiado pequeño para esa frecuencia (CNT_INT0>0xFFFF)
#endif

#define CNT_INT1 MCF_CLK/(FREC_INT1*PRESCALADO*16)	  // Valor de precarga del temporizador de interrupciones TRR1
#if CNT_INT1>0xFFFF
#error PRESCALADO demasiado pequeño para esa frecuencia (CNT_INT1>0xFFFF)
#endif

#define CNT_INT2 MCF_CLK/(FREC_INT2*PRESCALADO*16)	  // Valor de precarga del temporizador de interrupciones TRR2
#if CNT_INT1>0xFFFF
#error PRESCALADO demasiado pequeño para esa frecuencia (CNT_INT2>0xFFFF)
#endif

#define CNT_INT3 MCF_CLK/(FREC_INT3*PRESCALADO3*16)	  // Valor de precarga del temporizador de interrupciones TRR3
#if CNT_INT3>0xFFFF
#error PRESCALADO demasiado pequeño para esa frecuencia (CNT_INT3>0xFFFF)
#endif

#define BORRA_REF 0x0002			         // Valor de borrado de interr. pendientes de tout1 para TER0

#define T_ACT_COLS 5
#define NUM_COLS_TETRIS 6
#define NUM_COLS_SNAKE 4
#define COEF_CUENTA_TIEMPO 250
#define COEF_CUENTA_MELODIA 9

typedef struct { 
	int cuenta;
} Treloj;

Treloj relojMov;
Treloj relojCuentaTiempo;
Treloj relojMelodia;
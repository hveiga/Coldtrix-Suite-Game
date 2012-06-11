//------------------------------------------------------------------------------
// estado.h

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

#define JUGANDO 1
#define NO_JUGANDO 0 

#define JUEGO_TETRIS 0
#define JUEGO_SNAKE 1

#define LIBRE 1
#define OCUPADO 0

#define PPIEZA 1
#define NO_PPIEZA 0

#define PSERP 1
#define NO_PSERP 0

typedef struct {
	int jugando;
	int nivel;
	int nivelIncremental;
	int juegoBloques;
	int juego;
	int primeraPieza;
	int primeraSerp;
	int recursoLibre;
} Testado;
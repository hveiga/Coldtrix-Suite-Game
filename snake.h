//------------------------------------------------------------------------------
//   snake.h

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

#define DERECHA 0
#define ABAJO 1 
#define IZQUIERDA 2 
#define ARRIBA 3
#define TAM_MAX_SERP 32
#define TAMANO_INICIAL 3
#define NUM_DIR_MAX 3
#define ANCHOTAB 3
#define ALTOTAB 7
#define COM_NIV_MEDIO 5
#define COM_NIV_DIFICIL 9

#define NUM4 4
#define NUM8 8

typedef struct {
	int direccion;
	int tamano;
	Tposicion arraySnake[TAM_MAX_SERP];
	Tposicion comidaActual;
	int comio;
	} Tsnake;
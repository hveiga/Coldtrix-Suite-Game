//------------------------------------------------------------------------------
//   Puerto.h
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

#define MASCARA_TECLADO 0xFFFE
#define EXCIT_TECLADO 0x0001
#define MASCARA_FILAS 0xFF00
#define MASCARA_F0 0xFEFF
#define MASCARA_F1 0xFDFF
#define MASCARA_F2 0xFBFF
#define MASCARA_F3 0xF7FF
#define MASCARA_F4 0xEFFF
#define MASCARA_F5 0xDFFF
#define MASCARA_F6 0xBFFF
#define MASCARA_F7 0x7FFF
#define MASCARA_COLUMNAS 0xFF01
#define MASCARA_C0 0x0010
#define MASCARA_C1 0x0020
#define MASCARA_C2 0x0040
#define MASCARA_C3 0x0080
#define MASCARA_C4 0x0004
#define MASCARA_C5 0x0008
#define COLUMNA_TEC 0x1
#define HEX_CERO 0x0000
#define HEX_UNO 0x0001

#define F0 0
#define F1 1
#define F2 2
#define F3 3
#define F4 4
#define F5 5
#define F6 6
#define F7 7

#define C0 0
#define C1 1
#define C2 2
#define C3 3
#define C4 4
#define C5 5


typedef struct { 
	WORD varAux;
} TpuertoSal;
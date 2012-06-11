//------------------------------------------------------------------------------
//   pantalla.c

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

#include "pantalla.h"

//------------------------------------------------------

// void seleccionarMensaje(int mensaje) 

//

// Descripción:

//   Muestra por consola el mensaje seleccionado

//------------------------------------------------------
void seleccionarMensaje(int mensaje) {
	switch(mensaje) {
		case MENSAJE0:
			output("\nElija el nivel de dificultad del juego:\n- Pulse (1) Fácil\n- Pulse (4) Medio\n- Pulse (7) Difícil.\n");
			break;
		case MENSAJE1: 
			output("\nNivel seleccionado: Fácil.\n");
			break;
		case MENSAJE2: 
			output("\nNivel seleccionado: Medio.\n");
			break;
		case MENSAJE3: 
			output("\nNivel seleccionado: Difícil.\n");
			break;
		case MENSAJE4: 
			output("Tecla no válida.\n");
			break;
		case MENSAJE5: 
			output("Pulse A para comenzar la partida\n");

			break;
		case MENSAJE6: 
			output("Tecla no válida, por favor, pulse A para jugar\n");
			break;
		case MENSAJE7: 
			output("Empieza el juego!\n\n");
			break;
		case MENSAJE8: 
			output("\nPerdiste");
			if(estado.juego==JUEGO_TETRIS){
				output("\nNúmero de líneas completadas: ");
				outNum(BASE10, resultado.lineas, OP_OUTNUM);
				output("\nPuntos conseguidos: ");
				outNum(BASE10, getResultado(), OP_OUTNUM);
				output("\nTetris conseguidos: ");
				outNum(BASE10, getTetris(), OP_OUTNUM);
				output("\nTiempo empleado: ");
				outNum(BASE10, getTiempo(), OP_OUTNUM);
				output(" segundos");
				output("\nFilas por segundo: ");
				outNumDec(BASE10, getFilasPorSegundo(), NUM_DECIMALES, OP_OUTNUM);
				output("\nPuntos por segundo: ");
				outNumDec(BASE10, getPuntosPorSegundo(), NUM_DECIMALES, OP_OUTNUM);
				}
			if(estado.juego==JUEGO_SNAKE){
				output("\nNúmero de alimentos obtenidos: ");
				outNum(BASE10, resultado.comidas, OP_OUTNUM);
				output("\nPuntos conseguidos: ");
				outNum(BASE10, getResultado(), OP_OUTNUM);
				output("\nTiempo empleado: ");
				outNum(BASE10, getTiempo(), OP_OUTNUM);
				output(" segundos");
				output("\nComidas por segundo: ");
				outNumDec(BASE10, getComidasPorSegundo(), NUM_DECIMALES, OP_OUTNUM);
			}
			output("\nPulse una tecla para continuar\n\n");
			break;
		case MENSAJE9: 
			output("\nSeleccione modo de juego:\n- Pulse (1) para el modo de nivel incremental\n- Pulse (4) para el modo normal\n- Pulse (7) para el modo de juego con bloques fijos\n");
			break;
		case MENSAJE10: 
			output(" ,-----. ,-----. ,--.   ,------. ,--------.,------. ,--.,--.   ,--. 
'  .--./'  .-.  '|  |   |  .-.  \\'--.  .--'|  .--. '|  | \\  `.'  /  
|  |    |  | |  ||  |   |  |  \\  :  |  |   |  '--'.'|  |  .'    \\   
'  '--'\\'  '-'  '|  '--.|  '--'  /  |  |   |  |\\  \\ |  | /  .'.  \\  
 `-----' `-----' `-----'`-------'   `--'   `--' '--'`--''--'   '--' ");

			output("\nSeleccione juego:\n- Pulse (1) para el Tetris\n- Pulse (4) para Snake\n");
			break;
		case MENSAJE11: 
			output("\nSeleccione modo de juego:\n- Pulse (1) para el modo de nivel incremental\n- Pulse (4) para el modo normal\n");
			break;		
				
	}

}



//------------------------------------------------------

// void pulsarA() {

//

// Descripción:

//   Espera a pulsar 'A' para comenzar el juego
//------------------------------------------------------
void pulsarA() {
        char inicio;
	seleccionarMensaje(MENSAJE5); //Mensaje pulsar A
	inicio = teclado();
	
	while(inicio != CHAR_A){
		inicio = teclado();
		if(inicio != CHAR_A) seleccionarMensaje(MENSAJE6); //Mensaje tecla no valida, pulsar A
	}
	seleccionarMensaje(MENSAJE7); //Mensaje empieza el juego
}


//------------------------------------------------------

// int seleccionNivel(char tPulsada)

//

// Descripción:

//   Selecciona un nivel de juego en caso
//   contrario, espera a recibir un nivel correcto

//------------------------------------------------------
void seleccionNivel(void){
	char tPulsada;
	seleccionarMensaje(MENSAJE0); //Mensaje seleccion de nivel
	reproducirDAC(DAC_NIVEL); //Reproducimos el mensaje por el DAC
	tPulsada = teclado();
	
	while(!((tPulsada == CHAR_UNO)|| (tPulsada == CHAR_CUATRO) || (tPulsada == CHAR_SIETE))){
		seleccionarMensaje(MENSAJE4);
		seleccionarMensaje(MENSAJE0); //Mensaje seleccion de nivel
		tPulsada = teclado();
	}

	if(tPulsada == CHAR_UNO) { 
		seleccionarMensaje(MENSAJE1);//Mensaje seleccion de nivel facil
		estado.nivel = FACIL;
	}
	if(tPulsada == CHAR_CUATRO) { 
		seleccionarMensaje(MENSAJE2); //Mensaje seleccion de nivel medio
		estado.nivel = MEDIO;
	}
	if(tPulsada == CHAR_SIETE) { 
		seleccionarMensaje(MENSAJE3); //Mensaje seleccion de nivel dificil
		estado.nivel = DIFICIL;
	}
			
	pulsarA();
	estado.jugando = JUGANDO; //Empezamos a jugar
}

//------------------------------------------------------

// int seleccionTipoNivel(void)

//

// Descripción:

//   Selecciona un nivel de juego en caso
//   contrario, espera a recibir un nivel correcto

//------------------------------------------------------
void seleccionTipoNivel(void){
	char tecla;
	seleccionarMensaje(MENSAJE9); //Mensaje seleccion de modo
	reproducirDAC(DAC_MODO); //Reproducimos el mensaje por el DAC
	tecla = teclado();
	
	while(!((tecla == CHAR_UNO) || (tecla == CHAR_CUATRO) || (tecla == CHAR_SIETE))) {
		seleccionarMensaje(MENSAJE4);
		seleccionarMensaje(MENSAJE9); //Mensaje seleccion de modo
		tecla = teclado();
	}
	

	if(tecla == CHAR_UNO) { 
		estado.nivelIncremental = TRUE;
		estado.juegoBloques = FALSE;
		estado.nivel = FACIL;
		pulsarA();
		estado.jugando = JUGANDO;
	}

	if(tecla == CHAR_CUATRO) { 
		estado.nivelIncremental = FALSE;
		estado.juegoBloques = FALSE;
		seleccionNivel();
	}
	
	if(tecla == CHAR_SIETE) { 
		estado.nivelIncremental = FALSE;
		estado.juegoBloques = TRUE;
		seleccionNivel();
	}
	

}

//------------------------------------------------------

// int seleccionModoSerp(void)

//

// Descripción:

//   Selecciona un nivel de juego en caso
//   contrario, espera a recibir un nivel correcto

//------------------------------------------------------
void seleccionModoSerp(void){
	char tecla;
	seleccionarMensaje(MENSAJE11); //Mensaje seleccion de modo
	reproducirDAC(DAC_MODO); //Reproducimos el mensaje por el DAC
	tecla = teclado();
	
	while(!((tecla == CHAR_UNO) || (tecla == CHAR_CUATRO))) {
		seleccionarMensaje(MENSAJE4);
		seleccionarMensaje(MENSAJE11); //Mensaje seleccion de modo
		tecla = teclado();
	}
	

	if(tecla == CHAR_UNO) { 
		estado.nivelIncremental = TRUE;
		estado.juegoBloques = FALSE;
		estado.nivel = FACIL;
		pulsarA();
		estado.jugando = JUGANDO;
	}

	if(tecla == CHAR_CUATRO) { 
		estado.nivelIncremental = FALSE;
		estado.juegoBloques = FALSE;
		seleccionNivel();
	}

}

//------------------------------------------------------

// int seleccionJuego(void)

//

// Descripción:

//   Selecciona un nivel de juego en caso
//   contrario, vuelve a preguntar

//------------------------------------------------------
void seleccionJuego(void){
	char tecla;
	seleccionarMensaje(MENSAJE10); //Mensaje seleccion de juego
	reproducirDAC(DAC_JUEGO); //Reproducimos el mensaje por el DAC
	tecla = teclado();
	
	while(!((tecla == CHAR_UNO) || (tecla == CHAR_CUATRO))) {
		seleccionarMensaje(MENSAJE4);
		seleccionarMensaje(MENSAJE10); //Mensaje seleccion de juego
		tecla = teclado();
	}
	

	if(tecla == CHAR_UNO) { 
		estado.juego = JUEGO_TETRIS;
	}

	if(tecla == CHAR_CUATRO) { 
		estado.juego = JUEGO_SNAKE;
	}
	if(estado.juego == JUEGO_TETRIS) { seleccionTipoNivel(); }
	if(estado.juego == JUEGO_SNAKE) { seleccionModoSerp(); }

}
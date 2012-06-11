//------------------------------------------------------------------------------
//   juego.c
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

#include "Juego.h"


//------------------------------------------------------
// void juegoInic(void)
//
// Descripción:
//   Inicializa el objeto juego
//------------------------------------------------------
void juegoInic(void) {
	estado.primeraPieza = PPIEZA;
}


//------------------------------------------------------
// void pintaTPieza(Tpieza pieza)
//
// Descripción:
//   Pinta una pieza sobre el tablero segun su posicion
//------------------------------------------------------
void pintaTPieza(Tpieza pieza){
        int i=0;
        int j=0;

        for (i = 0; i < pieza.altura; i++) {
            for(j=0; j < pieza.anchura; j++) {
		if(i+piezaAux.posicion[0] >= 0) {
                	if((arrayTablero[i+pieza.posicion[POS_Y]][j+pieza.posicion[POS_X]]==OFF) && (pieza.matrizPiezaLive[i][j]==ON) ){
                    		arrayTablero[i+pieza.posicion[POS_Y]][j+pieza.posicion[POS_X]]=ON; //Si no nos salimos del tablero, pintamos la pieza
                	}
		}
 
            }
                    
        }
        
} 


//------------------------------------------------------
// void bajaFilas(int fila)
//
// Descripción:
//   Baja todas las filas del tablero una posicion introduce un array de ceros en la fila 0
//------------------------------------------------------
void bajaFilas(int fila){
	int i,j;
        for(i=fila;i>OFF;i--){
		for(j = 0;j < MAX_TAMANO; j++) { 
            		arrayTablero[i][j]=arrayTablero[i-1][j]; //Bajamos las filas
		}
        }
        for(i = 0;i < MAX_TAMANO; i++) {
		arrayTablero[0][i] = OFF; //Rellenamos con 0s las filas
	}
}


//------------------------------------------------------
// void evaluarTablero(void)
//
// Descripción:
//   Analiza el Tablero para borrar filas si fuese necesario
//------------------------------------------------------
void evaluarTablero(void){
    	int flag = FALSE; //Indicador de que se ha borrado fila
	static int flagTetris = FALSE; //Indicador de tetris
	int i,j;
	
        for(i=ALTO-1;i>=0;i--){
            flag = TRUE;
            for(j=0;j<ANCHO;j++){
                    if(arrayTablero[i][j]==0){
                        flag = FALSE;
                    }
            }
            if(flag == TRUE){
		resultado.lineas++; //Actualizamos los resultados
		flagTetris++; //contamos filas caidas
        	bajaFilas(i);
        	evaluarTablero();
            }
        }
	if(flagTetris == TAM_TETRIS){
		resultado.tetris++; //tenemos un tetris
	}
	setResultado(flagTetris);
	flagTetris = 0;//poner el false bien
	if(estado.nivelIncremental) { //Comprobamos si estamos en nivel incremental si hay que subir el nivel
		if(resultado.lineas >= NUM_LINEAS_N2) {
			estado.nivel = MEDIO; //Aumentamos el nivel
		}
		if(resultado.lineas >= NUM_LINEAS_N3) {
			estado.nivel = DIFICIL; //Aumentamos el nivel
		}
			
	}
}

//------------------------------------------------------
// int comprobacionColision(Tpieza piezaColision)
//
// Descripción:
//   Comprueba si hay colision con la pieza que le pasamos por parámetro
//------------------------------------------------------
int comprobacionColision(Tpieza piezaColision){
        int colision = FALSE; //Indicador de colision
	int i,j;
	
        if((piezaColision.posicion[POS_Y]+piezaColision.altura > ALTO)   ||   ( (piezaColision.posicion[POS_X]<0) ||  (piezaColision.posicion[POS_X]+piezaColision.anchura >ANCHO ) ) ){ 
            colision = TRUE; // Ha habido colision por salirnos del tablero
            return colision; //Devolvemos el resultado
        }

        for(i =0; i<piezaColision.altura; i++){
            for(j= 0; j<piezaColision.anchura; j++){
		if(i+piezaColision.posicion[POS_Y] >= 0) {
                	if((piezaColision.matrizPiezaLive[i][j]==1)&&(arrayTablero[i+ piezaColision.posicion[POS_Y]][j+piezaColision.posicion[POS_X]]==1)){
                    		colision = TRUE; // Ha habido colision porque habia una pieza en esa posicion
                    		return colision; //Devolvemos el resultado
                	}
		}
            }
        }
        return colision;
}

//------------------------------------------------------
// void borraPieza(Tpieza piezaBorrada)
//
// Descripción:
//   Borra del tablero la pieza que le pasas por parametro
//------------------------------------------------------
void borraPieza(Tpieza piezaBorrada){
	int i,j;
	
        for(i = 0; i < piezaBorrada.altura; i++){
            for(j = 0; j< piezaBorrada.anchura; j++){
		if(i+piezaAux.posicion[POS_Y] >= 0) { 
	           	if(piezaBorrada.matrizPiezaLive[i][j]==ON){
                		arrayTablero[piezaBorrada.posicion[POS_Y] + i][piezaBorrada.posicion[POS_X]+j]=OFF; //Borramos la pieza del tablero
                	}
		}
            }
        }
}

//------------------------------------------------------
// void pActual2pAux(void)
//
// Descripción:
//   Copia los parametros de la pieza actual a la auxiliar
//------------------------------------------------------
void pActual2pAux(void) {
	int i,j,k;
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			for(k = 0;k < MAX_TAMANO; k++) {
				piezaAux.matricesPieza[i][j][k] = piezaActual.matricesPieza[i][j][k];
			}
		}
	}
	
	piezaAux.rotacion = piezaActual.rotacion;
	
	piezaAux.posicion[POS_Y] = piezaActual.posicion[POS_Y];
	piezaAux.posicion[POS_X] = piezaActual.posicion[POS_X];
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			piezaAux.matrizPiezaLive[i][j] = piezaActual.matrizPiezaLive[i][j];
		}
	}
		
        piezaAux.anchura = evaluaAnchura(piezaAux);
        piezaAux.altura = evaluaAltura(piezaAux);
}

//------------------------------------------------------
// void pActual2pAuxPUNTEROS(Tpieza *piezaAuxP, Tpieza *piezaActualP) 
//
// Descripción:
//   Copia los parametros de la pieza actual a la auxiliar
//------------------------------------------------------
void pActual2pAuxPUNTEROS(Tpieza *piezaAuxP, Tpieza *piezaActualP) {
	int i,j,k;
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			for(k = 0;k < MAX_TAMANO; k++) {
				piezaAuxP->matricesPieza[i][j][k] = piezaActualP->matricesPieza[i][j][k];
			}
		}
	}
	
	piezaAuxP->rotacion = piezaActualP->rotacion;
	
	piezaAuxP->posicion[POS_Y] = piezaActualP->posicion[POS_Y];
	piezaAuxP->posicion[POS_X] = piezaActualP->posicion[POS_X];
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			piezaAuxP->matrizPiezaLive[i][j] = piezaActualP->matrizPiezaLive[i][j];
		}
	}
		
        piezaAuxP->anchura = evaluaAnchuraPUNTEROS(piezaAuxP);
        piezaAuxP->altura = evaluaAlturaPUNTEROS(piezaAuxP);
}

//------------------------------------------------------
// void pAux2pActual(void)
//
// Descripción:
//   Copia los parametros de la pieza auxiliar a la actual
//------------------------------------------------------
void pAux2pActual(void) {
	int i,j,k;
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			for(k = 0;k < MAX_TAMANO; k++) {
				piezaActual.matricesPieza[i][j][k] = piezaAux.matricesPieza[i][j][k];
			}
		}
	}
		
	piezaActual.rotacion = piezaAux.rotacion;
	
	piezaActual.posicion[POS_Y] = piezaAux.posicion[POS_Y];
	piezaActual.posicion[POS_X] = piezaAux.posicion[POS_X];
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			piezaActual.matrizPiezaLive[i][j] = piezaAux.matrizPiezaLive[i][j];
		}
	}
		
        piezaActual.anchura = evaluaAnchura(piezaActual);
        piezaActual.altura = evaluaAltura(piezaActual);
}

//------------------------------------------------------
// void pAux2pActualPUNTEROS(Tpieza *piezaAuxP, Tpieza *piezaActualP) 
//
// Descripción:
//   Copia los parametros de la pieza auxiliar a la actual
//------------------------------------------------------
void pAux2pActualPUNTEROS(Tpieza *piezaAuxP, Tpieza *piezaActualP) {
	int i,j,k;
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			for(k = 0;k < MAX_TAMANO; k++) {
				
				piezaActualP->matricesPieza[i][j][k] = piezaAuxP->matricesPieza[i][j][k];
			}
		}
	}
		
	piezaActualP->rotacion = piezaAuxP->rotacion;
	
	piezaActualP->posicion[POS_Y] = piezaAuxP->posicion[POS_Y];
	piezaActualP->posicion[POS_X] = piezaAuxP->posicion[POS_X];
	
	for(i = 0;i < MAX_TAMANO; i++) {
		for(j = 0;j < MAX_TAMANO; j++) {
			piezaActualP->matrizPiezaLive[i][j] = piezaAuxP->matrizPiezaLive[i][j];
		}
	}
		
        piezaActualP->anchura = evaluaAnchuraPUNTEROS(piezaActualP);
        piezaActualP->altura = evaluaAlturaPUNTEROS(piezaActualP);
}

//------------------------------------------------------
// void borraTablero(void)
//
// Descripción:
//   Borra el tablero
//------------------------------------------------------
void borraTablero(void) {
	int i,j;

	for(i=0;i<ALTO;i++){
            for(j=0;j<ANCHO;j++){
                    arrayTablero[i][j] = OFF; //Borramos todas las casillas
            }
        }
}

//------------------------------------------------------
// void nuevaPieza(void)
//
// Descripción:
//   Introduce una nueva pieza en juego
//------------------------------------------------------
void nuevaPieza(void){
	int rand = (mbar_readShort(MCFSIM_TCN1) % NUM7); //Cogemos un numero aleatorio modulo 7
	int i,j;
	
	if(estado.primeraPieza == NO_PPIEZA){
		piezaAux = piezaSiguiente; 
	}
	
	switch(rand) { //Elegimos una pieza al azar para ser la siguiente
		case PIEZA_I:			
			piezaSiguiente = iTetri;
			break;
		case PIEZA_S:
			piezaSiguiente = sTetri;
			break;
		case PIEZA_Z:
			piezaSiguiente = zTetri;
			break;
		case PIEZA_T:
			piezaSiguiente = tTetri;
			break;								
		case PIEZA_O:
			piezaSiguiente = oTetri;
			break;
		case PIEZA_J:
			piezaSiguiente = jTetri;
			break;								
		case PIEZA_L:
			piezaSiguiente = lTetri;
			break;
	}
	pintaPiezaSiguiente(rand); //Pintamos la piezaSiguiente en su matriz de leds
		
	if(estado.primeraPieza == PPIEZA){
		piezaAux = piezaSiguiente;
		estado.primeraPieza = NO_PPIEZA;
	}
		
	for(i = 0;i < MAX_TAMANO;i++) {
		for(j = 0;j < MAX_TAMANO;j++) {
			piezaAux.matrizPiezaLive[i][j]=piezaAux.matricesPieza[0][i][j];
			
		}
	}

	piezaAux.anchura = evaluaAnchura(piezaAux);
        piezaAux.altura = evaluaAltura(piezaAux);

	piezaAux.posicion[POS_Y] = - (piezaAux.altura);	//La altura inicial de la pieza será -Altura para que caiga progresivamente
        pAux2pActual();
        pintaTPieza(piezaActual);
}
//------------------------------------------------------
// void perdiste(void)
//
// Descripción:
//   Realiza las funciones necesarias tras perder, para resetear el juego.
//  
//------------------------------------------------------
void perdiste(void) {
	estado.jugando = NO_JUGANDO;
	pararMelodia();
	borraTablero();
        limpiadoFinJuego();
        seleccionarMensaje(MENSAJE8);
	juegoInic();
	resultadoInic();
}

//------------------------------------------------------
// void caePieza(void)
//
// Descripción:
//   Mueve la pieza una posicion hacia abajo
//------------------------------------------------------
void caePieza(void) {
	estado.recursoLibre = OCUPADO;
	
	pActual2pAux(); //Copiamos los parametros de la pieza actual en la auxiliar
        borraPieza(piezaActual); //Borramos la pieza del tablero
	
        piezaAux.posicion[POS_Y]++; //Bajamos una posicion la pieza y comprobamos si es posible
        
        if(comprobacionColision(piezaAux) == FALSE) { 
            	pAux2pActual(); //Copiamos los parametros actualizados de la pieza auxiliar a la actual
            	pintaTPieza(piezaActual); //Pintamos la pieza en el tablero
        } else {
		pintaTPieza(piezaActual); //Pintamos la pieza en el tablero
		if(piezaActual.posicion[POS_Y]<0){
			perdiste();
			estado.recursoLibre = LIBRE;	
			return;		
		}
		
		evaluarTablero();
                nuevaPieza();
        }

	estado.recursoLibre = LIBRE;
}


//------------------------------------------------------
// void mueveDerecha(void)
//
// Descripción:
//   Mueve la pieza una posicion hacia la derecha
//------------------------------------------------------
void mueveDerecha(void) {
	estado.recursoLibre = OCUPADO;
	
        pActual2pAux(); //Copiamos los parametros de la pieza actual en la auxiliar
        borraPieza(piezaActual); //Borramos la pieza del tablero
        piezaAux.posicion[POS_X]++; //Actualizamos la pieza una posicion a la derecha y comprobamos que es posible pintarla

        if(comprobacionColision(piezaAux) == FALSE) { 
		pAux2pActual(); //Copiamos los parametros de la pieza auxiliar en la actual
	}
     
        pintaTPieza(piezaActual); //Pintamos la pieza en el tablero

	estado.recursoLibre = LIBRE;
}

//------------------------------------------------------
// void mueveIzquierda(void)
//
// Descripción:
//   Mueve la pieza una posicion hacia la izquierda
//------------------------------------------------------
void mueveIzquierda(void) {
	estado.recursoLibre = OCUPADO;
	
        pActual2pAux(); //Copiamos los parametros de la pieza actual en la auxiliar
	borraPieza(piezaActual); //Borramos la pieza del tablero
        piezaAux.posicion[POS_X]--; //Actualizamos la pieza una posicion a la izquierda y comprobamos que es posible pintarla

        if(comprobacionColision(piezaAux) == FALSE) { 
		//pAux2pActual(); //Copiamos los parametros de la pieza auxiliar en la actual
		pAux2pActualPUNTEROS(&piezaAux, &piezaActual);
	}

        
        pintaTPieza(piezaActual); //Pintamos la pieza en el tablero

	estado.recursoLibre = LIBRE;
}

//------------------------------------------------------
// void rotacion(void)
//
// Descripción:
//   Rota la pieza una vez 90 grados antihorarios
//------------------------------------------------------
void rotacion(void){
	estado.recursoLibre = OCUPADO;
	
        pActual2pAux(); //Copiamos los parametros de la pieza actual en la auxiliar
        borraPieza(piezaActual); //Borramos la pieza del tablero
	//rotaPieza(); //Actualizamos la pieza una posicion a la izquierda y comprobamos que es posible pintarla
        rotaPiezaPUNTEROS(&piezaAux); //Actualizamos la pieza una posicion a la izquierda y comprobamos que es posible pintarla
     
        if(comprobacionColision(piezaAux) == FALSE) { 
		pAux2pActual();  //Copiamos los parametros de la pieza auxiliar en la actual
	}
                
        pintaTPieza(piezaActual); //Pintamos la pieza en el tablero

	estado.recursoLibre = LIBRE;
}


//------------------------------------------------------
// void bucleMainTetris(void)
//
// Descripción:
//   Juega
//------------------------------------------------------
void bucleMainTetris(void){
	char tecla;
	
	if(estado.primeraPieza == PPIEZA){
		melodiasInic();
		borraTablero();
		if(estado.juegoBloques){
			pintaBloques();
			evaluarTablero();
		}
		resultadoInic();
		nuevaPieza();
		nuevaPieza();
		estado.primeraPieza = NO_PPIEZA;
	}
	
	tecla = teclado();
	//podemos usar una variable de estado para evitar pulsar una tecla
	
	if(tecla == CHAR_UNO) { mueveIzquierda(); }
	if(tecla == CHAR_CUATRO) { caePieza(); }
	if(tecla == CHAR_SIETE) { mueveDerecha(); }
	if(tecla == CHAR_A) { rotacion(); }
						
}
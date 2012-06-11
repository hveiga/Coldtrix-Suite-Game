//------------------------------------------------------------------------------

// Snake.c

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

#include "snake.h"

Tsnake serpActual; //Creamos el objeto global serpiente actual

//------------------------------------------------------

// void borraPosicion(Tposicion pos) 

//

// Descripción:

//   Borra una posicion del tablero

//------------------------------------------------------
void borraPosicion(Tposicion pos) {
            arrayTablero[getAltoPosicion(pos)][getAnchoPosicion(pos)] = 0; //Ponemos a 0 la posicion en el tablero 
}

//------------------------------------------------------
// void borraSerpiente(void)

//

// Descripción:

//   Borra la serpiente del tablero

//------------------------------------------------------
void borraSerpiente(void){
	int i;
        for(i = 0;i<serpActual.tamano;i++){
            borraPosicion(serpActual.arraySnake[i]); //Borramos cada posicion de la serpiente en el tablero
        }
}

//------------------------------------------------------

// void snakeInic(void)

//

// Descripción:

//   Inicializa el objeto serpActual

//------------------------------------------------------
void snakeInic(void) {
        Tposicion pos2 = {0,0};
        Tposicion pos1 = {0,1};
        Tposicion pos0 = {0,2};
	Tposicion posComida = {3,3};

	
	serpActual.direccion = DERECHA; //Empezamos moviendonos hacia la derecha
	serpActual.tamano = TAMANO_INICIAL;
        serpActual.arraySnake[0] = pos0; //Inicializamos la serpiente con 3 posiciones predefinidas
        serpActual.arraySnake[1] = pos1;
        serpActual.arraySnake[2] = pos2;
	serpActual.comidaActual = posComida;
	serpActual.comio = FALSE;
}

//------------------------------------------------------

// Tposicion getPosCabeza(Tsnake snake) {

//

// Descripción:

//   Devuelve la posicion de la serpiente pasada por parámetro

//------------------------------------------------------
Tposicion getPosCabeza(Tsnake snake) {
	return snake.arraySnake[0]; //Devuelve la posicion de la cabeza
}

//------------------------------------------------------

// void calculaDireccionMenor(void)

//

// Descripción:

//   Calcula la direccion en la que tiene que girar la cabeza

//------------------------------------------------------
void calculaDireccionMenor(void){
	serpActual.direccion--;
	if(serpActual.direccion<0){
		serpActual.direccion = NUM_DIR_MAX;		
	}

}

//------------------------------------------------------

// void calculaDireccionMayor(void)

//

// Descripción:

//   Calcula la direccion en la que tiene que girar la cabeza

//------------------------------------------------------
void calculaDireccionMayor(void){
	serpActual.direccion++; //Actualizamos la dirección
	if(serpActual.direccion > NUM_DIR_MAX){
		serpActual.direccion=0;	
	}

}

//------------------------------------------------------

// void pintaPosicion(Tposicion pos) 

//

// Descripción:

//   Pinta la posicion pasada por parámetro en el tablero

//------------------------------------------------------
void pintaPosicion(Tposicion pos) {
            arrayTablero[getAltoPosicion(pos)][getAnchoPosicion(pos)] = ON; //Pintamos una posicion sobre el tablero
}

//------------------------------------------------------

// BOOL compruebaPosicionComida(Tposicion pos)

//

// Descripción:

//   Comprueba que la posicion de la comida es válida

//------------------------------------------------------
BOOL compruebaPosicionComida(Tposicion pos) {
	int i;
        for(i = 0;i<serpActual.tamano;i++){
            if( ( pos.alto == serpActual.arraySnake[i].alto ) && ( pos.ancho == serpActual.arraySnake[i].ancho ) ){
		return FALSE;
		}
        }
	return TRUE;
}

//------------------------------------------------------

// void pintaComida(void) 

//

// Descripción:

//   Método que pinta la comida aleatoriamente en el tablero

//------------------------------------------------------
void pintaComida(void) {
      Tposicion comida;

      int rand_ancho = (mbar_readShort(MCFSIM_TCN1) % NUM4); //Sacamos un numero aleatorio modulo 4
      int rand_alto = (mbar_readShort(MCFSIM_TCN1) % NUM8);  //Sacamos un numero aleatorio modulo 8

      borraPosicion(serpActual.comidaActual);

      comida.ancho = rand_ancho;
      comida.alto = rand_alto;

      if(compruebaPosicionComida(comida)) { //Comprobamos que es un posicion posible para la comida
      	serpActual.comidaActual = comida;
      	pintaPosicion(serpActual.comidaActual);
      } else {
	borraPosicion(comida);
	pintaComida(); //Si no es una posicion valida, llamamos al metodo otra vez
      }
}

//------------------------------------------------------

// void pintaSerpiente(void)

//

// Descripción:

//   Método que pinta la serpiente en el tablero

//------------------------------------------------------
void pintaSerpiente(void){
	int i;
        for(i = 0;i<serpActual.tamano;i++){
            pintaPosicion(serpActual.arraySnake[i]); //Recorre la serpiente y va pintando sus posiciones en el tablero
        }
}

//------------------------------------------------------

// Tposicion calculaPosicion(Tposicion posicionActual) 

//

// Descripción:

//   Método que calcula la posicion siguiente para avanzar

//------------------------------------------------------
Tposicion calculaPosicion(Tposicion posicionActual) {
	Tposicion sigPos = {getAltoPosicion(posicionActual),getAnchoPosicion(posicionActual)};

	switch(serpActual.direccion) { //Calculamos la siguiente posicion dependiendo de la direccion de la serpiente
		case DERECHA:
			if(getAnchoPosicion(posicionActual)+UNO > ANCHOTAB) {
                 		sigPos.ancho = 0;
             		} else {
                 		sigPos.ancho = getAnchoPosicion(posicionActual)+UNO;
             		}
			break;
		
		case ABAJO:
             		if(getAltoPosicion(posicionActual)+UNO > ALTOTAB) {
                 		sigPos.alto = 0;
             		} else {
                 		sigPos.alto = getAltoPosicion(posicionActual)+UNO;
             		}
      			break;
		
		case IZQUIERDA:
			if(getAnchoPosicion(posicionActual)-UNO < 0) {
                 		sigPos.ancho = ANCHOTAB;
             		} else {
                 		sigPos.ancho = getAnchoPosicion(posicionActual)-UNO;
             		}
			break;
			
		case ARRIBA:
			if(getAltoPosicion(posicionActual)-UNO < 0) {
                 		sigPos.alto = ALTOTAB;
             		} else {
                 		sigPos.alto = getAltoPosicion(posicionActual)-UNO;
             		}
			break;
	}
	return sigPos;	
}

//------------------------------------------------------

// int compruebaColision(void)

//

// Descripción:

//   Rutina que comprueba si hay colision, si la hay pierde el juego

//------------------------------------------------------
int compruebaColision(void){
	Tposicion posicionSiguiente = calculaPosicion(serpActual.arraySnake[0]);
        int colision = FALSE;
	int i;
	
        for(i=0; i < serpActual.tamano-UNO; i++){
            if((getAltoPosicion(posicionSiguiente) == getAltoPosicion(serpActual.arraySnake[i])) & (getAnchoPosicion(posicionSiguiente) == getAnchoPosicion(serpActual.arraySnake[i]))) {
                colision = TRUE;
                return colision;
            }          
        }

        return colision;
}

//------------------------------------------------------

// void creceSerp(Tposicion comida)

//

// Descripción:

//   Rutina que hace crecer la serpiente cuando come

//------------------------------------------------------
void creceSerp(Tposicion comida) {
	int i;
	for(i=serpActual.tamano-1; i >= 0; i--) {
		serpActual.arraySnake[i+1] = serpActual.arraySnake[i]; //Movemos la serpiente una posicion para atras
	}
	serpActual.arraySnake[0] = comida; //La comida pasa a ser la primera posicion de la serpiente
	serpActual.comio = TRUE; //Cambiamos el indicador advirtiendo que ha comido
	serpActual.tamano++; //Aumentamos el tamaño de la serpiente
}

//------------------------------------------------------

// void compruebaComida(Tposicion comida, Tposicion posicionSig) {

//

// Descripción:

//   Rutina que hace crecer la serpiente cuando come y actualiza resultados

//------------------------------------------------------
void compruebaComida(Tposicion comida, Tposicion posicionSig) {
        if((getAltoPosicion(posicionSig) == getAltoPosicion(comida)) && (getAnchoPosicion(posicionSig) == getAnchoPosicion(comida))) {
          	  creceSerp(comida); //Hacemos crecer la serpiente una posicion
		  resultado.comidas++; //Actualizamos el resultado
		  
		  if(estado.nivelIncremental) { //Miramos si el nivel es incremental, si lo es miramos si tenemos que incrementar el nivel
			if(resultado.comidas >= COM_NIV_MEDIO) {
				estado.nivel = MEDIO;
			}
			if(resultado.lineas >= COM_NIV_DIFICIL) {
				estado.nivel = DIFICIL;
			}
		  }
		}
}

//------------------------------------------------------

// void avanzaSerpiente(void) 

//

// Descripción:

//   Rutina que hace avanzar la serpiente

//------------------------------------------------------
void avanzaSerpiente(void) {
	int i;
	Tposicion posCabTemp = getPosCabeza(serpActual);
	
         for(i=serpActual.tamano-UNO;i>=UNO;i--){
             serpActual.arraySnake[i].ancho = getAnchoPosicion(serpActual.arraySnake[i-UNO]);
             serpActual.arraySnake[i].alto = getAltoPosicion(serpActual.arraySnake[i-UNO]);
         }
	
	switch(serpActual.direccion) { //Hacemos avanzar la serpiente dependiendo de la direccion
		case DERECHA:
			if(getAnchoPosicion(posCabTemp)+UNO > ANCHOTAB) {
                 		posCabTemp.ancho = 0;
             		} else {
                 		posCabTemp.ancho = getAnchoPosicion(posCabTemp)+UNO;
             		}
			break;
		
		case ABAJO:
             		if(getAltoPosicion(posCabTemp)+UNO > ALTOTAB) {
                 		posCabTemp.alto = 0;
             		} else {
                 		posCabTemp.alto = getAltoPosicion(posCabTemp)+UNO;
             		}
      			break;
		
		case IZQUIERDA:
			if(getAnchoPosicion(posCabTemp)-UNO < 0) {
                 		posCabTemp.ancho = ANCHOTAB;
             		} else {
                 		posCabTemp.ancho = getAnchoPosicion(posCabTemp)-UNO;
             		}

			break;
			
		case ARRIBA:
			if(getAltoPosicion(posCabTemp)-UNO < 0) {
                 		posCabTemp.alto = ALTOTAB;
             		} else {
                 		posCabTemp.alto = getAltoPosicion(posCabTemp)-UNO;
             		}

			break;
	}
	
	serpActual.arraySnake[0] = posCabTemp;
}

//------------------------------------------------------

// void borraTableroSnake(void) 

//

// Descripción:

//   Rutina que borra las posiciones del tablero

//------------------------------------------------------
void borraTableroSnake(void) {
	int i,j;
	for(i=0;i<ALTO;i++){
            for(j=0;j<ANCHO;j++){
		Tposicion pos = {i,j};
                borraPosicion(pos); //Borramos del tablero la posicion de la serpiente
            }
        }
}

//------------------------------------------------------

// void avanza(void) 

//

// Descripción:

//   Rutina que hace avanzar la serpiente

//------------------------------------------------------
void avanza(void){
	estado.recursoLibre = OCUPADO; //Marcamos el recurso como ocupado
	
	if(compruebaColision()==FALSE){
		Tposicion cola = serpActual.arraySnake[serpActual.tamano-1];
		Tposicion sigPos = calculaPosicion(serpActual.arraySnake[0]);
       	 	borraPosicion(cola);
         
    		compruebaComida(serpActual.comidaActual,sigPos); //Comprueba si comemos
        	avanzaSerpiente(); //Avanzamos la serpiente
         
        	if(serpActual.comio){
            		pintaComida(); //Si hemos comido, pintamos una nueva comida
            		serpActual.comio = FALSE;
        	}

        	pintaSerpiente();
	} else {
		estado.jugando=NO_JUGANDO;
		estado.primeraSerp = PSERP;
		borraTableroSnake();
		limpiadoFinJuego();
		snakeInic();
		seleccionarMensaje(MENSAJE8);
		resultadoInic();
	}
	
	estado.recursoLibre = LIBRE; //Liberamos el recurso
}

//------------------------------------------------------

// void mueveCabezaDerecha(void)

//

// Descripción:

//   Rutina que gira la cabeza hacia la derecha

//------------------------------------------------------
void mueveCabezaDerecha(void) {
	estado.recursoLibre = OCUPADO; //Marcamos el recurso como ocupado
	
	calculaDireccionMayor();
	avanza();
	
	estado.recursoLibre = LIBRE; //Liberamos el recurso
}

//------------------------------------------------------

// void mueveCabezaIzquierda(void)

//

// Descripción:

//   Rutina que gira la cabeza hacia la izquierda

//------------------------------------------------------
void mueveCabezaIzquierda(void) {
	estado.recursoLibre = OCUPADO; //Marcamos el recurso como ocupado
	
	calculaDireccionMenor();
	avanza();
	
	estado.recursoLibre = LIBRE; //Liberamos el recurso
}

//------------------------------------------------------

// void inicio(void)

//

// Descripción:

//   Rutina que inicia el juego de la serpiente

//------------------------------------------------------
void inicio(void) {
	borraTableroSnake();
	snakeInic(); //Iniciamos la serpiente
        pintaSerpiente(); //Pintamos la serpiente en el tablero
	pintaComida(); //Pintamos la comida
}

//------------------------------------------------------

// void bucleMainSnake(void)

//

// Descripción:

//   Rutina principal del juego snake

//------------------------------------------------------
void bucleMainSnake(void){
	char tecla;
	
	if(estado.primeraSerp == PSERP){
		inicio(); //Si es la primera pasada por el metodo, iniciamos el juego
		estado.primeraSerp = NO_PSERP;
	}
	
	tecla = teclado();
	
	if(tecla == CHAR_UNO) { mueveCabezaIzquierda(); }
	if(tecla == CHAR_SIETE) { mueveCabezaDerecha(); }
	if(tecla == CHAR_CUATRO) { avanza(); }
						
}
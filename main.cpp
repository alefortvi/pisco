#include <iostream>
#include <conio.h> // Para getch() y kbhit() en Windows
#include <unistd.h> // Para getch() en Linux

#include <conio2.h>
#include "include/PiscoDraw.h"
#include "include/PiscoSprite.h"
#include "include/Pisco.h"
using namespace std;



int main() {
	
	
	PiscoDraw spriteDraw2(5, 5, 10, 20);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			Pixel pixel("O", PiscoColor::BLUE);
			spriteDraw2.setValue(i, j, pixel);
		}
	}
	PiscoSprite sprite1;
	sprite1.addSprite("ob1", spriteDraw2);
	Pisco::draw(sprite1.getActivatedSprite());
	
	
	
	// Crear un PiscoSprite con una matriz de 5x5 del carácter "X" y color "RED"
	PiscoDraw spriteDraw(5, 5, 0, 0);
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			Pixel pixel("X", PiscoColor::RED);
			spriteDraw.setValue(i, j, pixel);
		}
	}
	PiscoSprite sprite;
	sprite.addSprite("default", spriteDraw);
	
	// Variables para la posición del sprite
	int x = 0;
	int y = 0;
	
	// Mostrar el sprite inicialmente
	Pisco::Pisco::draw(sprite.getActivatedSprite());
	
	// Loop principal
	while (true) {
		// Si hay una tecla presionada
		if (kbhit()) {
			// Leer la tecla presionada
			char key = getch(); // Usar getch() en Windows o getch() en Linux
			
			// Mover el sprite según la tecla presionada
			switch (key) {
			case 'w':
				
				y=-1;
				x = 0;
				
				break;
			case 's':
				// Cambiar 19 por el tamaño máximo de la ventana
				y=1;
				x= 0;
				
				break;
			case 'a':
				x = -1;
				y=0;
				
				break;
			case 'd':
				if (x < 59) { // Cambiar 59 por el ancho máximo de la ventana
					x = 1;
					y=0;
				}
				break;
			case 'q':
				// Salir del programa si se presiona 'q'
				return 0;
			}
			
			
			
			
			Pisco::erase(sprite.getActivatedSprite());
			// Actualizar la posición del sprite
			sprite.getActivatedSprite().move(x, y);
			
			// Limpiar la pantalla y dibujar el sprite en la nueva posición
			//system("cls"); // Usar "cls" en Windows o "clear" en Linux
			Pisco::draw(sprite.getActivatedSprite());
			Pisco::draw(sprite1.getActivatedSprite());
			Pisco::gotoxy(2,10);
			cout<<"colisiona: "<<Pisco::areColliding(sprite, sprite1);
			
		}
	}
	
	return 0;
}

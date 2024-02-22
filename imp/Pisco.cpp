
#include <cmath>

#include <string>
#include "../include/Pisco.h"

using namespace std;


	WORD Pisco::getCurrentConsoleColor() {
#ifdef _WIN32
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		return csbi.wAttributes;
#else
		// Implementación para otros sistemas operativos
		return 0;
#endif
	}
	
	void Pisco::gotoxy(int x, int y) {
#ifdef _WIN32
		COORD coord;
		coord.X = static_cast<SHORT>(x);
		coord.Y = static_cast<SHORT>(y);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
		// Implementación para otros sistemas operativos
#endif
	}
	
	void Pisco::textColor(PiscoColor color) {
#ifdef _WIN32
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
#else
		// Implementación para otros sistemas operativos
#endif
	}
	
	void Pisco::putchxy(int x, int y, const std::string& ch, PiscoColor color) {
		WORD prevConsoleColor = getCurrentConsoleColor(); // Guardar el color actual de la consola
		
		textColor(color); // Cambiar temporalmente el color de la consola
		gotoxy(x, y); // Mover el cursor a la posición deseada
		std::cout << ch; // Escribir el carácter en la posición deseada
		
		textColor(static_cast<PiscoColor>(prevConsoleColor)); // Restaurar el color original de la consola
	}
	
	void Pisco::putchxy(int x, int y, const std::string& ch) {
		gotoxy(x, y); // Mover el cursor a la posición deseada
		std::cout << ch; // Escribir el carácter en la posición deseada
	}
	
	
	void Pisco::draw( PiscoSprite& sprite) {
		Pisco::draw(sprite.getActivatedSprite());
	}
	
	void Pisco::draw( PiscoDraw& canvas) {
		int canvasWidth = canvas.getWidth();
		int canvasHeight = canvas.getHeight();
		int startX = canvas.getX();
		int startY = canvas.getY();
		
		for (int y = 0; y < canvasHeight; ++y) {
			for (int x = 0; x < canvasWidth; ++x) {
				Pixel pixel = canvas.getValue(x, y);
				putchxy(startX + x, startY + y, pixel.getCharacter(), pixel.getColor());
			}
		}
	}
	
	void Pisco::erase( PiscoDraw& canvas) {
		int canvasWidth = canvas.getWidth();
		int canvasHeight = canvas.getHeight();
		int startX = canvas.getX();
		int startY = canvas.getY();
		
		for (int y = 0; y < canvasHeight; ++y) {
			for (int x = 0; x < canvasWidth; ++x) {
				Pixel pixel = canvas.getValue(x, y);
				putchxy(startX + x, startY + y, " ");
			}
		}
	}
	
	void Pisco::erase( PiscoSprite& sprite) {
		Pisco::erase(sprite.getActivatedSprite());
	}
	
	int Pisco::areColliding(PiscoSprite& sprite1, PiscoSprite& sprite2) {
		PiscoDraw& draw1 = sprite1.getActivatedSprite();
		PiscoDraw& draw2 = sprite2.getActivatedSprite();
		
		// Obtener las coordenadas del área de intersección entre los dos sprites
		int left = std::max(draw1.getX(), draw2.getX());
		int right = std::min(draw1.getX() + draw1.getWidth() - 1, draw2.getX() + draw2.getWidth() - 1);
		int top = std::max(draw1.getY(), draw2.getY());
		int bottom = std::min(draw1.getY() + draw1.getHeight() - 1, draw2.getY() + draw2.getHeight() - 1);
		
		
		// Verificar si hay colisión en alguno de los bordes
		if (right >= left && bottom >= top) {
			if (right == draw1.getX() || left == draw1.getX() + draw1.getWidth() - 1) return 1; // Colisión izquierda o derecha
			if (bottom == draw1.getY() || top == draw1.getY() + draw1.getHeight() - 1) return 2; // Colisión arriba o abajo
			if (right == draw2.getX() || left == draw2.getX() + draw2.getWidth() - 1) return 3; // Colisión izquierda o derecha
			if (bottom == draw2.getY() || top == draw2.getY() + draw2.getHeight() - 1) return 4; // Colisión arriba o abajo
		}
		
		// Verificar si hay alguna posición de píxel en el área de intersección
		for (int x = left; x <= right; ++x) {
			for (int y = top; y <= bottom; ++y) {
				Pixel pixel1 = draw1.getValue(x - draw1.getX(), y - draw1.getY());
				Pixel pixel2 = draw2.getValue(x - draw2.getX(), y - draw2.getY());
				if (pixel1.getCharacter() != " " && pixel2.getCharacter() != " ") {
					return 5; // Colisión en todas las esquinas
				}
			}
		}
		
		return 0; // No hay colisión
	}

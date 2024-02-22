/*
  Archivo generado autom谩ticamente.
*/

#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <Windows.h>
#include <map>

#ifndef PISCO_COLOR_H
#define PISCO_COLOR_H


	enum class PiscoColor {
		BLACK,
		BLUE,
		GREEN,
		CYAN,
		RED,
		MAGENTA,
		BROWN, // en conio suele ser equivalente al amarillo
		LIGHTGRAY, // en conio suele ser equivalente al blanco
		DARKGRAY,
		LIGHTBLUE,
		LIGHTGREEN,
		LIGHTCYAN,
		LIGHTRED,
		LIGHTMAGENTA,
		YELLOW,
		WHITE
	};

#endif // PISCO_COLOR_H


#ifndef PIXEL_H
#define PIXEL_H



	class Pixel {
	public:
		Pixel(int x, int y, const std::string& character, PiscoColor color);
		Pixel(const std::string& character, PiscoColor color);
		int getX() const;
		int getY() const;
		const std::string& getCharacter() const;
		PiscoColor getColor() const;
		
	private:
		int x;
		int y;
		std::string character;
		PiscoColor color;
	};

#endif // PIXEL_H


#ifndef PISCO_DRAW_H
#define PISCO_DRAW_H




	class PiscoDraw {
	public:
		PiscoDraw(int width, int height, int x, int y);
		PiscoDraw();
		
		int getWidth() const;
		int getHeight() const;
		int getX() const;
		int getY() const;
		
		Pixel getValue(int x, int y);
		void setValue(int x, int y, Pixel& pixel);
		void move(int offsetX, int offsetY);
		
	private:
		int width;
		int height;
		int x;
		int y;
		std::vector<std::vector<Pixel>> matrix;
	};

#endif // PISCO_DRAW_H


#ifndef PISCO_SPRITE_H
#define PISCO_SPRITE_H




	class PiscoSprite {
	public:
		void addSprite(const std::string& key, PiscoDraw& sprite);
		void setActiveSprite(const std::string& key);
		PiscoDraw& getActivatedSprite();
		std::string getActivatedKey() const;
		
	private:
		std::map<std::string, PiscoDraw> sprites;
		std::string activeSpriteKey;
	};

#endif // PISCO_SPRITE_H


#ifndef PISCO_H
#define PISCO_H





	class Pisco {
	public:
		static WORD getCurrentConsoleColor();
		static void gotoxy(int x, int y);
		static void textColor(PiscoColor color);
		static void putchxy(int x, int y, const std::string& ch, PiscoColor color);
		static void putchxy(int x, int y, const std::string& ch);
		static void draw(PiscoDraw& canvas);
		static void erase(PiscoDraw& canvas);
		static int areColliding( PiscoSprite& spriteFrom, PiscoSprite& spriteTo);
		
	};


#endif // PISCO_H



/* Implementaci贸n de Pixel.cpp */




	Pixel::Pixel(int x, int y, const std::string& character, PiscoColor color)
		: x(x), y(y), character(character), color(color) {}
	
	Pixel::Pixel(const std::string& character, PiscoColor color)
		: character(character), color(color) {}
	
	int Pixel::getX() const {
		return x;
	}
	
	int Pixel::getY() const {
		return y;
	}
	
	const std::string& Pixel::getCharacter() const {
		return character;
	}
	
	PiscoColor Pixel::getColor() const {
		return color;
	}




/* Implementaci贸n de PiscoDraw.cpp */



	PiscoDraw::PiscoDraw() = default; // Constructor predeterminado
	
	PiscoDraw::PiscoDraw(int width, int height, int x, int y)
		: width(width), height(height), x(x), y(y), matrix(height, std::vector<Pixel>(width, Pixel(x, y, " ", PiscoColor::WHITE))) {}
	
	int PiscoDraw::getWidth() const {
		return width;
	}
	
	int PiscoDraw::getHeight() const {
		return height;
	}
	
	int PiscoDraw::getX() const {
		return x;
	}
	
	int PiscoDraw::getY() const {
		return y;
	}
	
	Pixel PiscoDraw::getValue(int x, int y) {
		return matrix[y][x];
	}
	
	void PiscoDraw::setValue(int x, int y, Pixel& pixel) {
		matrix[y][x] = pixel;
	}
	
	
	void PiscoDraw::move(int offsetX, int offsetY) {
		x += offsetX;
		y += offsetY;
	}

	



/* Implementaci贸n de PiscoSprite.cpp */




	void PiscoSprite::addSprite(const std::string& key, PiscoDraw& sprite) {
		sprites[key] = sprite;
		activeSpriteKey = key; // Establecer el sprite activo como el 鷏timo agregado
	}
	
	void PiscoSprite::setActiveSprite(const std::string& key) {
		auto it = sprites.find(key);
		if (it != sprites.end()) {
			activeSpriteKey = key;
		} else {
			throw std::invalid_argument("Sprite with key '" + key + "' does not exist.");
		}
	}
	
	
	PiscoDraw& PiscoSprite::getActivatedSprite(){
		auto it = sprites.find(activeSpriteKey);
		if (it != sprites.end()) {
			return it->second;
		} else {
			throw std::invalid_argument("Active sprite does not exist.");
		}
	}
	
	std::string PiscoSprite::getActivatedKey() const {
		return activeSpriteKey;
	}




/* Implementaci贸n de Pisco.cpp */




using namespace std;


	WORD Pisco::getCurrentConsoleColor() {
#ifdef _WIN32
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		return csbi.wAttributes;
#else
		// Implementaci髇 para otros sistemas operativos
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
		// Implementaci髇 para otros sistemas operativos
#endif
	}
	
	void Pisco::textColor(PiscoColor color) {
#ifdef _WIN32
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
#else
		// Implementaci髇 para otros sistemas operativos
#endif
	}
	
	void Pisco::putchxy(int x, int y, const std::string& ch, PiscoColor color) {
		WORD prevConsoleColor = getCurrentConsoleColor(); // Guardar el color actual de la consola
		
		textColor(color); // Cambiar temporalmente el color de la consola
		gotoxy(x, y); // Mover el cursor a la posici髇 deseada
		std::cout << ch; // Escribir el car醕ter en la posici髇 deseada
		
		textColor(static_cast<PiscoColor>(prevConsoleColor)); // Restaurar el color original de la consola
	}
	
	void Pisco::putchxy(int x, int y, const std::string& ch) {
		gotoxy(x, y); // Mover el cursor a la posici髇 deseada
		std::cout << ch; // Escribir el car醕ter en la posici髇 deseada
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
	
	int Pisco::areColliding(PiscoSprite& sprite1, PiscoSprite& sprite2) {
		PiscoDraw& draw1 = sprite1.getActivatedSprite();
		PiscoDraw& draw2 = sprite2.getActivatedSprite();
		
		// Obtener las coordenadas del 醨ea de intersecci髇 entre los dos sprites
		int left = std::max(draw1.getX(), draw2.getX());
		int right = std::min(draw1.getX() + draw1.getWidth() - 1, draw2.getX() + draw2.getWidth() - 1);
		int top = std::max(draw1.getY(), draw2.getY());
		int bottom = std::min(draw1.getY() + draw1.getHeight() - 1, draw2.getY() + draw2.getHeight() - 1);
		
		
		// Verificar si hay colisi髇 en alguno de los bordes
		if (right >= left && bottom >= top) {
			if (right == draw1.getX() || left == draw1.getX() + draw1.getWidth() - 1) return 1; // Colisi髇 izquierda o derecha
			if (bottom == draw1.getY() || top == draw1.getY() + draw1.getHeight() - 1) return 2; // Colisi髇 arriba o abajo
			if (right == draw2.getX() || left == draw2.getX() + draw2.getWidth() - 1) return 3; // Colisi髇 izquierda o derecha
			if (bottom == draw2.getY() || top == draw2.getY() + draw2.getHeight() - 1) return 4; // Colisi髇 arriba o abajo
		}
		
		// Verificar si hay alguna posici髇 de p韝el en el 醨ea de intersecci髇
		for (int x = left; x <= right; ++x) {
			for (int y = top; y <= bottom; ++y) {
				Pixel pixel1 = draw1.getValue(x - draw1.getX(), y - draw1.getY());
				Pixel pixel2 = draw2.getValue(x - draw2.getX(), y - draw2.getY());
				if (pixel1.getCharacter() != " " && pixel2.getCharacter() != " ") {
					return 5; // Colisi髇 en todas las esquinas
				}
			}
		}
		
		return 0; // No hay colisi髇
	}



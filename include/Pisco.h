#ifndef PISCO_H
#define PISCO_H

#include <iostream>
#include <string>
#include <Windows.h>
#include "Pisco.h"
#include "PiscoColor.h"
#include "PiscoDraw.h"
#include "PiscoSprite.h"




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

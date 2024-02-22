#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include "PiscoColor.h"
#include "Pixel.h"


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

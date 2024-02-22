
#include "../include/Pixel.h"


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


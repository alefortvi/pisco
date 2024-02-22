
#include "../include/PiscoDraw.h"

	PiscoDraw::PiscoDraw() = default; // Constructor predeterminado
	
	PiscoDraw::PiscoDraw(int width, int height, int x, int y)
		: width(width), height(height), x(x), y(y), matrix(height, std::vector<Pixel>(width, Pixel(x, y, " ", PiscoColor::WHITE))) {}
	
	PiscoDraw::PiscoDraw(int x, int y, const std::vector<std::vector<Pixel>>& initialMatrix)
		: x(x), y(y), matrix(initialMatrix) {
		// Asegurar que la matriz tenga el tamaño correcto
		if (!matrix.empty()) {
			width = matrix[0].size();
			height = matrix.size();
		} else {
			width = height = 0;
		}
	}
	
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

	

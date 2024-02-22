#ifndef PISCO_DRAW_H
#define PISCO_DRAW_H


#include <vector>
#include "Pixel.h"


	class PiscoDraw {
	public:
		PiscoDraw(int x, int y, const std::vector<std::vector<Pixel>>& initialMatrix);
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

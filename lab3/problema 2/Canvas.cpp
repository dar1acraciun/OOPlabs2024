#include "Canvas.h"
#include <stdlib.h>
#include <iostream>
Canvas::Canvas(int width, int height)
{
	this->matrix = (char**)(malloc(height * sizeof(char)));
	for (int i = 0; i < height; i++)
		this->matrix[i] = (char*)(malloc(width * sizeof(char)));
	this->n = height;
	this->m = width;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			this->matrix[i][j] = ' ';

}
void Canvas::DrawCircle(int x, int y, int r, char ch)
{
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= r * (r - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= r * (r + 1))
				this->matrix[i][j] = ch;

}
void Canvas::FillCircle(int x, int y, int r, char ch)
{
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
				this->matrix[i][j] = ch;


}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	
	for (int i = top; i <= bottom; i++)
		this->matrix[left][i] = ch,this->matrix[right][i]=ch;
	for (int i = left; i <= right; i++)
		this->matrix[i][top] = ch,this->matrix[i][bottom]=ch;
	


}
void Canvas::Print() {
	for (int i = 0; i < this->n; i++)
	{
		for (int j = 0; j < this->m; j++)
			std::cout << this->matrix[i][j];
		std::cout << '\n';
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	
	for (int i = left + 1; i < right; i++)
		for (int j = top + 1; j < bottom; j++)
			this->matrix[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch) {
	this->matrix[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int dy = abs(y1 - y2);
	int sx, sy;
	if (x1 < x2)
		sx = 1;
	else sx = -1;
	if (y1 < y2)
		sy = 1;
	else sy=- 1;
	int err = dx - dy;
	while (x1 != x2 || y1 != y2) {
		this->matrix[y1][x1] = ch;
		int err2 = 2 * err;
		if (err2 > -dy)
			err -= dy, x1 += sx;
		if (err2 < dx)
			err += dx, y1 += sy;
	}


}
void Canvas::Clear() {
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->m; j++)
			this->matrix[i][j] = ' ';

}

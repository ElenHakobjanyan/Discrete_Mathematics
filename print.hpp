#ifndef PRINT_HPP
#define PRINT_HPP

// color output
void c_out(std::string text, int text_color);

// prints grid without color
void print_grid(int l, int c, int step);

// prints connections on line
void text_line(int c);

// draws connections on line
void draw_line(int c);

// gives back the number of vertex
int g_num(int i, int j, int c);

// generates random colors for connections
int** generate_color_matrix(int l, int c);

// prints connections on grid
void text_grid(int l, int c);

// draws connections on grid
void draw_grid(int l, int c);

// calls text and draw functions for line
void cover_line(int c);

// calls text and draw functions for grid
void cover_grid(int l, int c);

// decides to call line or grid
void cover(int l, int c);


#include "print.impl.hpp"

#endif // PRINT_HPP
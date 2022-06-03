#ifndef PRINT_IMPL_HPP
#define PRINT_IMPL_HPP

void c_out(std::string text, int text_color)
{
	switch(text_color)
	{ 
		case  1: std::cout << "\x1b[31;1m" << text << "\x1b[0m"; break; // red
		case  2: std::cout << "\x1b[34;1m" << text << "\x1b[0m"; break; // blue
		case  3: std::cout << "\x1b[90;1m" << text << "\x1b[0m"; break; // gray
		case  4: std::cout << "\x1b[95;1m" << text << "\x1b[0m"; break; // pink
		case  5: std::cout << "\x1b[36;1m" << text << "\x1b[0m"; break; // cyan
		case  6: std::cout << "\x1b[33;1m" << text << "\x1b[0m"; break; // yellow
		case  7: std::cout << "\x1b[32;1m" << text << "\x1b[0m"; break; // green
		default: std::cout << "\x1b[97;1m" << text << "\x1b[0m";
	}
}

void print_grid(int l, int c, int step)
{
	for (int i = 0; i <= step*(l-1); ++i)
	{
		for (int j = 0; j <= step*(c-1); ++j)
		{
			if (i == 0 && j == 0) std::cout << "╔";
			else if (i == 0 && j == step*(c - 1)) std::cout << "╗";
			else if (i == step*(l - 1) && j == 0) std::cout << "╚";
			else if (i == step*(l - 1) && j == step*(c - 1)) std::cout << "╝";
			else if (i == 0 && j % step == 0) std::cout << "╦";
			else if (i == step*(l - 1) && j % step == 0) std::cout << "╩";
			else if (i % step == 0 && j == 0) std::cout << "╠";
			else if (i % step == 0 && j == step*(c - 1)) std::cout << "╣";
			else if (i % step == 0 && j % step == 0) std::cout << "╬";
			else if (j % step == 0) std::cout << "║";
			else std::cout << ((i % step == 0)? "═══" : "   ");
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void text_line(int c)
{
	for (int i = 2; i < c; i +=2)
	{
		std::cout << "<g" << i-2 << " - g" << i-1 << " - g" << i << ">\n";
	}
	std::cout << std::endl;
}

void draw_line(int c)
{
	int clr = 0;
	for (int j = 0; j < c-1; ++j)
	{
		clr = j / 2 % 8;
		std::cout << j;
		c_out("══", clr);
	}
	std::cout << c-1 << std::endl;
}

int g_num(int i, int j, int c)
{
	return i*c+j;
}

int** generate_color_matrix(int l, int c)
{
	srand(time(0));
	
	int** clr = new int*[l];
	for (int i = 0; i < l; ++i)
	{
		clr[i] = new int[c]{};
	}
	
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			clr[i][j] = rand()%8;
		}
	}
	
	for (int i = 1; i < l; i+=2)
	{
		clr[i][c-1] = clr[i-1][c-1];
	}
	
	for (int j = 1; j < c; j+=2)
	{
		clr[l-1][j] = clr[l-1][j-1];
	}
	
	if (l % 2 == 0 && c % 2 == 0)
	{
		clr[l-1][c-2] = rand()%8;
		clr[l-2][c-1] = clr[l-1][c-2];
	}
	
	return clr;
}

void text_grid(int l, int c)
{
	for (int i = 0; i < l-1; ++i)
	{
		for (int j = 0; j < c-1; ++j)
		{
			std::cout << "<g" << g_num(i,j+1,c) << " - g" << g_num(i,j,c) << " - g" << g_num(i+1,j,c) << ">\n";
		}
	}
	
	for (int i = 2; i < l; i+=2)
	{
		std::cout << "<g" << g_num(i-2,c-1,c) << " - g" << g_num(i-1,c-1,c) << " - g" << g_num(i,c-1,c) << ">\n";
	}
	
	for (int j = 2; j < c; j+=2)
	{
		std::cout << "<g" << g_num(l-1,j-2,c) << " - g" << g_num(l-1,j-1,c) << " - g" << g_num(l-1,j,c) << ">\n";
	}
	
	if (l % 2 == 0 && c % 2 == 0)
	{
		std::cout << "<g" << g_num(l-2,c-1,c) << " - g" << g_num(l-1,c-1,c) << " - g" << g_num(l-1,c-2,c) << ">\n";
	}
}

void draw_grid(int l, int c)
{
	int** clr_matrix = generate_color_matrix(l, c);
	
	for (int i = 0; i < l-1; ++i)
	{
		for (int j = 0; j < c-1; ++j)
		{
			std::cout << std::setw(3) << g_num(i,j,c); 
			c_out("══", clr_matrix[i][j]);
		}
		std::cout << std::setw(3) << g_num(i,c-1,c) << "\n";
		
		for (int j = 0; j < c; ++j)
		{
			std::cout << "  ";
			c_out("║", clr_matrix[i][j]);
			std::cout << "  ";
		}
		std::cout << std::endl;
	}
	
	for (int j = 0; j < c-1; ++j)
	{
		std::cout << std::setw(3) << g_num(l-1,j,c); 
		c_out("══", clr_matrix[l-1][j]);
	}
	std::cout << std::setw(3) << g_num(l-1,c-1,c) << "\n";
}

void cover_line(int c)
{
	text_line(c);
	draw_line(c);
}

void cover_grid(int l, int c)
{
	text_grid(l, c);
	draw_grid(l, c);
}

void cover(int l, int c)
{
	if (l == 1 || c == 1)
		cover_line(l * c);
	else
		if (l < c) cover_grid(l, c);
		else cover_grid(c, l);
}

#endif // PRINT_IMPL_HPP
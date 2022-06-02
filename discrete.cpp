#include <cassert>
#include <iomanip>
#include <iostream>

#include "matrix.hpp"
#include "print.hpp"

//Տրված է mxn քառակուսային ցանց: Մշակել և իրացնել ցանցը երկու երկարության պարզ շղթաներով ծածկույթ իրացնող ալգորիթմ:

void user_input(int& l, int& c);

int main()
{
	int line, col, chain = 2;
	user_input(line, col);
	
	int edge_count = line * (col - 1) + (line - 1) * col;
	assert((edge_count % chain == 0) && "Unable to generate coverage. Try changing input numbers.");
	assert(edge_count != 0 && "Unable to generate coverage. Nothing to cover.");
	
	bool** matrix = generate_matrix(line, col);
	print_matrix(matrix, line, col);
	
	cover(line, col);
	//print_two_coverage(line, col, 1);
	
	delete_matrix(matrix, line, col);
}


void user_input(int& line, int& col)
{
	std::cout << "Input paramerer m:   "; std::cin >> line;
	assert(line > 0 && "Number of lines must be a positive natural number.");
	std::cout << "Input paramerer n:   "; std::cin >> col;
	assert(col > 0 && "Number of columns must be a positive natural number.");
	assert(!(line == 1 && col == 1) && "One by one grid will not generate cover. Try different parameters.");
}

#ifndef MATRIX_IMPL_HPP
#define MATRIX_IMPL_HPP

bool isEmpty(bool** m, int line, int col)
{
	long v = line*col;
	
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			if (m[i][j])
			{
				return false;
			}
		}
	}
	
	return true;
}

bool** generate_matrix(int l, int c)
{
	const long v = l*c;
	bool** m = new bool*[v];
	for (int i = 0; i < v; ++i)
	{
		m[i] = new bool[v]{};
	}
	
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int curr = c*i + j;
			if (j != c - 1)
			{
				m[curr][curr+1] = 1;
				m[curr+1][curr] = 1;
			}
			if (i != l - 1)
			{
				m[curr][curr+c] = 1;
				m[curr+c][curr] = 1;
			}
		}
	}
	
	return m;
}

void print_matrix(bool** m, int l, int c)
{
	long v = l*c;
	
	std::cout << std::setw(3) << "";
	for (int j = 0; j < v; ++j)
	{
		std::cout << std::setw(3) << j;
	}
	std::cout << std::endl;
	
	for (int i = 0; i < v; ++i)
	{
		std::cout << std::setw(3) << i;
		for (int j = 0; j < v; ++j)
		{
			if (m[i][j])
			{
				std::cout << std::setw(3) << m[i][j];
			}
			else
			{
				std::cout << std::setw(3) << ".";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void delete_matrix(bool** m, int l, int c)
{
	long v = l*c;
	for (int i = 0; i < v; ++i)
	{
		delete[] m[i];
	}
	delete[] m;
}

#endif // MATRIX_IMPL_HPP
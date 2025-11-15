#include "ETM.hpp"

template <typename K>
void	Matrix<K>::add(const Matrix<K> & m)
{
	if (_rows != m.getRows() || _cols != m.getCols()) {
		cerr << "The matrices doesn't have the same dimensions." << endl; return;
	}
	const vector<vector<K>> & mdata = m.getData();
	for (size_t i = 0; i != _rows; i++)
		for (size_t j = 0; j != _cols; j++)
			_data[i][j] += mdata[i][j];
}

template <typename K>
void	Matrix<K>::sub(const Matrix<K> & m)
{
	if (_rows != m.getRows() || _cols != m.getCols()) {
		cerr << "The matrices doesn't have the same dimensions." << endl; return;
	}
	const vector<vector<K>> & mdata = m.getData();
	for (size_t i = 0; i != _rows; i++)
		for (size_t j = 0; j != _cols; j++)
			_data[i][j] -= mdata[i][j];
}

template <typename K>
void	Matrix<K>::scl(const K n)
{
	for (size_t i = 0; i != _rows; i++)
		for (size_t j = 0; j != _cols; j++)
			_data[i][j] *= n;
}

template <typename K>
ostream & operator<<(ostream & o, const Matrix<K> & m)
{
	if (!m.getRows())
		return (o);
	for (size_t i = 0; i != m.getRows(); i++)
	{
		o << "[ ";
		for (size_t j = 0; j != m.getCols(); j++)
		{
			o << m.getData()[i][j];
			if (j != m.getCols() - 1)
				o << ",";
			o << " ";
		}
		o << "]" << endl;
	}
	return (o);
}
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
Vector<K>	Matrix<K>::mul_vec(const Vector<K> & vec) const
{
	if (vec.getSize() != _cols) {
		cerr << "The matrix columns and vector size are not compatible." << endl;
		return Vector<K>(0);
	}
	vector<K>			result;
	result.reserve(_rows);
	const vector<K> &	vdata = vec.getData();
	for (size_t i = 0; i < _rows; i++)
	{
		K tmp(0);
		for (size_t j = 0; j < _cols; j++)
			tmp += _data[i][j] * vdata[j];
		result.push_back(tmp);
	}
	return Vector<K>(result);
}

template <typename K>
Matrix<K>	Matrix<K>::mul_mat(const Matrix<K> & mat) const
{
	if (mat.getRows() != _cols) {
		cerr << "The matrix dimensions are not compatible." << endl;
		return Matrix<K>();
	}
	vector<vector<K>>			result;
	result.reserve(_rows);
	const vector<vector<K>> &	mdata = mat.getData();
	for (size_t i = 0; i < _rows; i++)
	{
		vector<K>	vtmp;
		vtmp.reserve(mat.getCols());
		for (size_t k = 0; k < mat.getCols(); k++)
		{
			K	tmp(0);
			for (size_t j = 0; j < _cols; j++)
				tmp += _data[i][j] * mdata[j][k];
			vtmp.push_back(tmp);
		}
		result.push_back(vtmp);
	}
	return Matrix<K>(result);
}

template <typename K>
K	Matrix<K>::trace() const
{
	if (!isSquare()) {
		cerr << "The matrix is not square." << endl;
		return K(0);
	}
	K	res(0);
	for (size_t i = 0; i < _rows; i++)
		res += _data[i][i];
	return (res);
}

template <typename K>
Matrix<K>	Matrix<K>::transpose() const
{
	vector<vector<K>> result;
	result.reserve(_cols);
	for (size_t i = 0; i < _cols; i++)
	{
		vector<K>	tmp;
		tmp.reserve(_rows);
		for (size_t j = 0; j < _rows; j++)
			tmp.push_back(_data[j][i]);
		result.push_back(tmp);
	}
	return (Matrix(result));
}

template <typename K>
Matrix<K> Matrix<K>::row_echelon() const
{

	vector<vector<K>>	data = _data;

	size_t	row = 0;
	for (size_t col = 0; col < _cols && row < _rows; col++)
	{
		K	pivot(0);
		// Chercher pivot sur la colonne
		for (size_t i = row; i < _rows; i++)
		{
			if (data[i][col] != 0)
			{
				pivot = data[i][col];
				if (i != row)
					swap(data[i], data[row]);
				break;
			}
		}

		if (pivot == 0)
			continue;

		// Normaliser la ligne du pivot pour que pivot == 1
		for (size_t j = 0; j < _cols; j++)
			data[row][j] /= pivot;

		// Eliminer les autres lignes
		for (size_t k = 0; k < _rows; k++)
		{
			if (k == row) continue;
			K	factor = data[k][col];
			for (size_t j = 0; j < _cols; j++)
				data[k][j] -= factor * data[row][j];
		}
		row++;
	}

	return Matrix<K>(data);
}

template <typename K>
K Matrix<K>::determinant() const
{
	if (!isSquare()) {
		cerr << "The matrix is not square." << endl;
		return K(0);
	}

	if (_rows == 1)
		return _data[0][0];
	else if (_rows == 2)
		return (_data[0][0] * _data[1][1]) - (_data[0][1] * _data[1][0]);
	else if (_rows == 3)
	{
		K	aei = _data[0][0] * _data[1][1] * _data[2][2];
		K	bfg = _data[0][1] * _data[1][2] * _data[2][0];
		K	cdh = _data[0][2] * _data[1][0] * _data[2][1];
		K	ceg = _data[0][2] * _data[1][1] * _data[2][0];
		K	bdi = _data[0][1] * _data[1][0] * _data[2][2];
		K	afh = _data[0][0] * _data[1][2] * _data[2][1];
		return (aei + bfg + cdh - ceg - bdi - afh);
	}
	else if (_rows == 4)
	{
		K	result(0);
		for (size_t i = 0; i < 4; i++)
		{
			vector<vector<K>>	minor;
			minor.reserve(3);
			for (size_t j = 1; j < _rows; j++)
			{
				vector<K>	minor_row;
				minor_row.reserve(3);
				for (size_t k = 0; k < _cols; k++)
				{
					if (k == i)
						continue;
					minor_row.push_back(_data[j][k]);
				}
				minor.push_back(minor_row);
			}
			int minus = i % 2 == 0 ? 1 : -1;
			result += _data[0][i] * minus * Matrix<K>(minor).determinant();
		}
		return (result);
	}
	cerr << "Determinant calculation for matrices larger than 4x4 is not implemented." << endl;
	return K(0);
}

template <typename K>
Matrix<K>	Matrix<K>::inverse() const
{
	if (!isSquare()) {
		cerr << "The matrix is not square." << endl;
		return Matrix<K>();
	}

	if (determinant() == 0) {
		cerr << "The determinant of the matrix is zero." << endl;
		return Matrix<K>();
	}

	vector<vector<K>>	inv(_rows, vector<K>(_cols, 0));
	vector<vector<K>>	data = _data;
	for (size_t i = 0; i < _rows; i++)
		inv[i][i] = 1;

	for (size_t col = 0; col < _cols; col++)
	{
		K	pivot(0);
		// Chercher pivot sur la colonne
		for (size_t i = col; i < _rows; i++)
		{
			if (data[i][col] != 0)
			{
				pivot = data[i][col];
				if (i != col)
				{
					swap(data[i], data[col]);
					swap(inv[i], inv[col]);
				}
				break;
			}
		}

		if (pivot == 0) {
			cerr << "The determinant of the matrix is zero." << endl;
			return Matrix<K>();
		}

		// Normaliser la ligne du pivot pour que pivot == 1
		for (size_t j = 0; j < _cols; j++)
		{
			data[col][j] /= pivot;
			inv[col][j] /= pivot;
		}

		// Eliminer les autres lignes
		for (size_t k = 0; k < _rows; k++)
		{
			if (k == col) continue;
			K	factor = data[k][col];
			for (size_t j = 0; j < _cols; j++)
			{
				data[k][j] -= factor * data[col][j];
				inv[k][j] -= factor * inv[col][j];
			}
		}
	}

	return Matrix<K>(inv);
}

template <typename K>
size_t	Matrix<K>::rank() const
{
	Matrix<K>	rref = this->row_echelon();
	size_t		rank = 0;

	for (size_t i = 0; i < rref.getRows(); i++)
	{
		for (size_t j = 0; j < rref.getCols(); j++)
		{
			if (rref.getData()[i][j] != 0)
			{
				rank++;
				break;
			}
		}
	}

	return rank;
}

// ================ //

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
			float x = m.getData()[i][j];
			if (fabs(x) < 1e-8)
				x = 0;
			o << x;
			if (j != m.getCols() - 1)
				o << ",";
			o << " ";
		}
		o << "]" << endl;
	}
	return (o);
}
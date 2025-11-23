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

// Row echelon form

template <typename K>
K	Matrix<K>::determinant() const
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
			o << m.getData()[i][j];
			if (j != m.getCols() - 1)
				o << ",";
			o << " ";
		}
		o << "]" << endl;
	}
	return (o);
}
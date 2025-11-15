#ifndef CLASS_HPP
#define CLASS_HPP

#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename K>
class Vector
{
	public:
		Vector() : _size(0) {}
		Vector(initializer_list<K> l) : _data(l) { _size = _data.size(); }
		Vector(const Vector<K> & v) : _data(v.getData()), _size(v.getSize()) {}

		Vector<K> & operator=(const Vector<K> & v) {
			_data = v.getData();
			_size = v.getSize();
			return (*this);
		}

		size_t				getSize() const { return (_size); }
		const vector<K> &	getData() const { return (_data); }

		void    add(const Vector<K> & v);
		void    sub(const Vector<K> & v);
		void    scl(const K n);

	private:
		vector<K>	_data;
		size_t		_size;

};

#include "Vector.tpp"

template <typename K>
class Matrix
{
	public:
		Matrix(initializer_list<initializer_list<K>> l) {
			_data.reserve(l.size());
			for (auto &row : l)
				_data.emplace_back(row);
			_rows = _data.size();
			_cols = _data.empty() ? 0 : _data[0].size();
		}	

		size_t						getRows() const { return (_rows); }
		size_t						getCols() const { return (_cols); }
		const vector<vector<K>> &	getData() const { return (_data); }
		bool						isSquare() const { return (_rows == _cols); }

		void    add(const Matrix<K> & m);
		void    sub(const Matrix<K> & m);
		void    scl(const K n);

	private:
		vector<vector<K>>	_data;
		size_t				_rows;
		size_t				_cols;
};

#include "Matrix.tpp"

template <typename K>
ostream & operator<<(ostream & o, const Vector<K> & v);
template <typename K>
ostream & operator<<(ostream & o, const Matrix<K> & m);

// ============ //

template <typename K, typename T>
K	linear_combination(initializer_list<K> const & v, initializer_list<T> const & coefs)
{
	K		result;
	auto	vit = v.begin();
	auto	cit = coefs.begin();
	size_t	n = vit->getSize();
	for (; vit != v.end(); ++vit, ++cit)
	{
		K tmp = *vit;
		if (tmp.getSize() != n) {
			cerr << "The vectors doesn't have the same size." << endl;
			return K();
		}
		if (cit != coefs.end())
			tmp.scl(*cit);
		if (vit == v.begin())
			result = tmp;
		else
			result.add(tmp);
	}
	return result;
}

#endif
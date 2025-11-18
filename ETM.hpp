#ifndef CLASS_HPP
#define CLASS_HPP

#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

template <typename K>
class Vector
{
	public:
		Vector() : _data(), _size(0) {}
		Vector(int size) : _data(size, 0), _size(size) {}
		Vector(vector<K> const & data) : _data(data), _size(data.size()) {}
		Vector(initializer_list<K> l) : _data(l) { _size = _data.size(); }
		Vector(const Vector<K> & v) : _data(v.getData()), _size(v.getSize()) {}

		Vector<K> & operator=(const Vector<K> & v) {
			_data = v.getData();
			_size = v.getSize();
			return (*this);
		}

		Vector<K> & operator+(const Vector<K> & v) {
			this->add(v);
			return (*this);
		}

		Vector<K> & operator-(const Vector<K> & v) {
			this->sub(v);
			return (*this);
		}

		Vector<K> & operator*(const K n) {
			this->scl(n);
			return (*this);
		}

		size_t				getSize() const { return (_size); }
		const vector<K> &	getData() const { return (_data); }

		void    add(const Vector<K> & v);
		void    sub(const Vector<K> & v);
		void    scl(const K n);

		K		dot(const Vector<K> & v) const;

		float	norm_1() const;
		float	norm_2() const;
		float	norm_inf() const;

	private:
		vector<K>	_data;
		size_t		_size;

};

#include "Vector.tpp"

template <typename K>
class Matrix
{
	public:
		Matrix() : _data(), _rows(0), _cols(0) {}
		Matrix(vector<vector<K>> const & data) : _data(data) {
			_rows = data.size();
			_cols = _data.empty() ? 0 : _data[0].size();
		}
		Matrix(int rows, int cols) : _data(rows, vector<K>(cols, 0)), _rows(rows), _cols(cols) {}
		Matrix(initializer_list<initializer_list<K>> l) {
			_data.reserve(l.size());
			for (auto &row : l)
				_data.emplace_back(row);
			_rows = _data.size();
			_cols = _data.empty() ? 0 : _data[0].size();
		}
		Matrix(const Matrix<K> & m) : _data(m.getData()), _rows(m.getRows()), _cols(m.getCols()) {}

		Matrix<K> & operator=(const Matrix<K> & m) {
			_data = m.getData();
			_rows = m.getRows();
			_cols = m.getCols();
			return (*this);
		}

		Matrix<K> & operator+(const Matrix<K> & m) {
			this->add(m);
			return (*this);
		}

		Matrix<K> & operator-(const Matrix<K> & m) {
			this->sub(m);
			return (*this);
		}

		Matrix<K> & operator*(const K n) {
			this->scl(n);
			return (*this);
		}

		size_t						getRows() const { return (_rows); }
		size_t						getCols() const { return (_cols); }
		const vector<vector<K>> &	getData() const { return (_data); }
		bool						isSquare() const { return (_rows == _cols); }

		void    add(const Matrix<K> & m);
		void    sub(const Matrix<K> & m);
		void    scl(const K n);

		Vector<K>	mul_vec(const Vector<K> & vec) const;
		Matrix<K>	mul_mat(const Matrix<K> & mat) const;

		K	trace() const;

		Matrix<K>	transpose() const;

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
	auto	vit = v.begin();
	auto	cit = coefs.begin();
	K		result(vit->getSize());
	for (; vit != v.end(); ++vit, ++cit)
	{
		K tmp = *vit;
		if (result.getSize() != tmp.getSize()) {
			cerr << "The vectors doesn't have the same size." << endl;
			return K(0);
		}
		if (cit != coefs.end())
			result = result + (tmp * (*cit));
	}
	return result;
}

template <typename V>
V	lerp(V const & u, const V& v, float const t)
{
	if (t < 0.f || t > 1.f) {
		cerr << "t must be in [0, 1]." << endl;
		return V();
	}
	V	tmpu = u;
	V	tmpv = v;
	return ((tmpv - tmpu) * t) + tmpu;
}

template <typename K>
float	angle_cos(const Vector<K> & v, const Vector<K> & u)
{
	float dot = v.dot(u);

	return (dot / (u.norm_2() * v.norm_2()));
}

template <typename K>
Vector<K>	cross_product(const Vector<K> & u,const Vector<K> & v)
{
	if (u.getSize() != 3 || v.getSize() != 3) {
		cerr << "The vectors need to be 3-dimensional." << endl; return Vector<K>(0);
	}

	K	x(0), y(0), z(0);

	auto& a = u.getData();
	auto& b = v.getData();

	x = (a[1] * b[2]) - (a[2] * b[1]);
	y = (a[2] * b[0]) - (a[0] * b[2]);
	z = (a[0] * b[1]) - (a[1] * b[0]);

	return Vector<K>({x, y, z});
}

#endif
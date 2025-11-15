#ifndef CLASS_HPP
#define CLASS_HPP

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Vector
{
	public:
		Vector(initializer_list<float> l) : _data(l) { _size = _data.size(); }

		size_t					getSize() const { return (_size); }
		const vector<float> &	getData() const { return (_data); }

		void    add(const Vector & v);
		void    sub(const Vector & v);
		void    scl(const float n);

	private:
		vector<float>   _data;
		size_t          _size;

};

class Matrix
{
	public:
		Matrix(initializer_list<initializer_list<float>> l) {
			_data.reserve(l.size());
			for (auto &row : l)
				_data.emplace_back(row);
			_rows = _data.size();
			_cols = _data.empty() ? 0 : _data[0].size();
		}

		size_t							getRows() const { return (_rows); }
		size_t							getCols() const { return (_cols); }
		const vector<vector<float>> &	getData() const { return (_data); }
		bool							isSquare() const { return (_rows == _cols); }

		void    add(const Matrix & m);
		void    sub(const Matrix & m);
		void    scl(const float n);

	private:
		vector<vector<float>>	_data;
		size_t					_rows;
		size_t					_cols;
};

ostream & operator<<(ostream & o, const Vector & v);
ostream & operator<<(ostream & o, const Matrix & m);

#endif
#include "Class.hpp"

void    Vector::add(const Vector & v)
{
	const vector<float>& src = v.getData();
	size_t vsize = v.getSize();
	if (vsize != _size) {
		cerr << "The vectors doesn't have the same size." << endl; return ;
	}
	for (size_t i = 0; i != _size; i++)
		_data[i] += src[i];
}

void    Vector::sub(const Vector & v)
{
	const vector<float>& src = v.getData();
	size_t vsize = v.getSize();
	if (vsize != _size) {
		cerr << "The vectors doesn't have the same size." << endl; return ;
	}
	for (size_t i = 0; i != _size; i++)
		_data[i] -= src[i];
}

void    Vector::scl(const float n)
{
	for (size_t i = 0; i != _size; i++)
		_data[i] *= n;
}

ostream & operator<<(ostream & o, const Vector & v)
{
	for (size_t i = 0; i != v.getSize(); i++)
		o << "[ " << v.getData()[i] << " ]" << endl;
	return (o);
}
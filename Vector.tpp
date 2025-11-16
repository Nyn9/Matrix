#include "ETM.hpp"

template <typename K>
void    Vector<K>::add(const Vector<K> & v)
{
	if (v.getSize() != _size) {
		cerr << "The vectors doesn't have the same size." << endl; return ;
	}
	const vector<K>& src = v.getData();
	for (size_t i = 0; i != _size; i++)
		_data[i] += src[i];
}

template <typename K>
void    Vector<K>::sub(const Vector<K> & v)
{
	if (v.getSize() != _size) {
		cerr << "The vectors doesn't have the same size." << endl; return ;
	}
	const vector<K>& src = v.getData();
	for (size_t i = 0; i != _size; i++)
		_data[i] -= src[i];
}

template <typename K>
void    Vector<K>::scl(const K n)
{
	for (size_t i = 0; i != _size; i++)
		_data[i] *= n;
}

template <typename K>
K	Vector<K>::dot(const Vector<K> & v)
{
	if (v.getSize() != _size) {
		cerr << "The vectors doesn't have the same size." << endl; return K(0);
	}
	K result(0);
	const vector<K>& src = v.getData();
	for (size_t i = 0; i < _size; i++)
		result = result + (_data[i] * src[i]);
	return result;
}

template <typename K>
ostream & operator<<(ostream & o, const Vector<K> & v)
{
	for (size_t i = 0; i != v.getSize(); i++)
		o << "[ " << v.getData()[i] << " ]" << endl;
	return (o);
}

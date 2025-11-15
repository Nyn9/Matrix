#include <iostream>
#include "Class.hpp"

using namespace std;

int main(void)	
{
	cout << "===== Vector tests =====" << endl;

	{
		Vector u({2., 3.});
		const Vector v({5., 7.});
		u.add(v);
		cout << u;
		// [7]
		// [10]
	}

	cout << "-----" << endl;

	{
		Vector u({2., 3.});
		const Vector v({5., 7.});
		u.sub(v);
		cout << u;
		// [-3]
		// [-4]
	}

	cout << "-----" << endl;

	{
		Vector u({2., 3.});
		u.scl(2.);
		cout << u;
		// [4]
		// [6]
	}

	cout << "===== Matrix tests =====" << endl;

	{
		Matrix u({
			{1., 2.},
			{3., 4.}
		});
		const Matrix v({
			{7., 4.},
			{-2, 2.}
		});
		u.add(v);
		cout << u;
		// [8, 6]
		// [1, 6]
	}

	cout << "-----" << endl;

	{
		Matrix u({
			{1., 2.},
			{3., 4.}
		});
		const Matrix v({
			{7., 4.},
			{-2, 2.}
		});
		u.sub(v);
		cout << u;
		// [-6, -2]
		// [5, 2]
	}

	cout << "-----" << endl;

	{
		Matrix u({
			{1., 2.},
			{3., 4.}
		});
		u.scl(2.);
		cout << u;
		// [2, 4]
		// [6, 8]
	}
}
#include "../ETM.hpp"

using namespace std;

int main(void)	
{
	cout << "===== Vector tests =====" << endl << endl;

	{
		Vector<float> u({2., 3.});
		const Vector<float> v({5., 7.});
		u.add(v);
		cout << u;
		// [7]
		// [10]
	}

	cout << "-----" << endl;

	{
		Vector<float> u({2., 3.});
		const Vector<float> v({5., 7.});
		u.sub(v);
		cout << u;
		// [-3]
		// [-4]
	}

	cout << "-----" << endl;

	{
		Vector<float> u({2., 3.});
		u.scl(2.);
		cout << u;
		// [4]
		// [6]
	}

	cout <<  endl << "===== Matrix tests =====" << endl << endl;

	{
		Matrix<float> u({
			{1., 2.},
			{3., 4.}
		});
		const Matrix<float> v({
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
		Matrix<float> u({
			{1., 2.},
			{3., 4.}
		});
		const Matrix<float> v({
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
		Matrix<float> u({
			{1., 2.},
			{3., 4.}
		});
		u.scl(2.);
		cout << u;
		// [2, 4]
		// [6, 8]
	}

	cout <<  endl << "===== Error cases =====" << endl << endl;

	{
		Matrix<float> u({
			{1., 2., 3.},
			{4., 5., 6.}
		});
		const Matrix<float> v({
			{7., 8.},
			{9., 10.}
		});
		u.add(v);
		// The matrices doesn't have the same dimensions.
	}

	cout << "-----" << endl;

	{
		Matrix<float> u({
			{1., 2., 3.},
			{4., 5., 6.}
		});
		const Matrix<float> v({
			{7., 8.},
			{9., 10.}
		});
		u.sub(v);
		// The matrices doesn't have the same dimensions.
	}

	cout << "-----" << endl;

	{
		Vector<float> u({1., 2., 3.});
		const Vector<float> v({4., 5.});
		u.sub(v);
		// The vectors doesn't have the same size.
	}

	cout << "-----" << endl;

	{
		Vector<float> u({1., 2., 3.});
		const Vector<float> v({4., 5.});
		u.add(v);
		// The vectors doesn't have the same size.
	}
}
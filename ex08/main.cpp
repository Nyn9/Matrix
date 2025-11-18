#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Trace tests =====" << endl << endl;
	{
		const Matrix<float> u({
			{1., 0.},
			{0., 1.}
		});
		cout << u.trace() << endl;
		// 2
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{2., -5., 0.},
			{4., 3., 7.},
			{-2., 3., 4.}
		});
		cout << u.trace() << endl;
		// 9
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{-2., -8., 4.},
			{1., -23., 4.},
			{0., 6., 4.},
		});
		cout << u.trace() << endl;
		// -21
	}

	cout << endl << "===== Error cases =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 2., 3.},
			{4., 5., 6.}
		});
		cout << u.trace() << endl;
		// The matrix is not square.
	}
}
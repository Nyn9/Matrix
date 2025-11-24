#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Matrix inverse tests =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 0., 0.},
			{0., 1., 0.},
			{0., 0., 1.}
		});
		cout << u.inverse() << endl;
		// [1.0, 0.0, 0.0]
		// [0.0, 1.0, 0.0]
		// [0.0, 0.0, 1.0]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{2., 0., 0.},
			{0., 2., 0.},
			{0., 0., 2.}
		});
		cout << u.inverse() << endl;
		// [0.5, 0.0, 0.0]
		// [0.0, 0.5, 0.0]
		// [0.0, 0.0, 0.5]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{8., 5., -2.},
			{4., 7., 20.},
			{7., 6., 1.},
		});
		cout << u.inverse() << endl;
		// [0.649425, 0.0977011, -0.655172]
		// [-0.781609, -0.1264367, 0.965517]
		// [0.143678, 0.0747126, -0.206897]
	}

	cout << "===== Error cases =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 2., 3.},
			{4., 5., 6.}
		});
		cout << u.inverse() << endl;
		// The matrix is not square.
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{1., 2.},
			{2., 4.}
		});
		cout << u.inverse() << endl;
		// The determinant of the matrix is zero.
	}
}
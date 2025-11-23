#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Matrix determinant tests =====" << endl << endl;
	{
		const Matrix<float> u({
			{1.0, -1.0},
			{-1.0, 1.0}
		});
		cout << u.determinant() << endl;
		// 0
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{2., 0., 0.},
			{0., 2., 0.},
			{0., 0., 2.},
		});
		cout << u.determinant() << endl;
		// 8
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{8., 5., -2.},
			{4., 7., 20.},
			{7., 6., 1.},
		});
		cout << u.determinant() << endl;
		// -174
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u ({
			{8., 5., -2., 4.},
			{4., 2.5, 20., 4.},
			{8., 5., 1., 4.},
			{28., -4., 17., 1.},
		});
		cout << u.determinant() << endl;
		// 1032
	}

	cout << endl << "===== Error cases =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 2., 3.},
			{4., 5., 6.}
		});
		cout << u.determinant() << endl;
		// The matrix is not square.
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{1., 8., 6., 4., -5.},
			{7., 6., 4., 8., 2.},
			{5., 0., -11., 12., 3.},
			{4., 5., 6., 7., 1.},
			{8., 5., 1., 4., 9.},
		});
		cout << u.determinant() << endl;
	}
}
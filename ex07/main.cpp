#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Matrix mul_vec tests =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 0.},
			{0., 1.}
		});
		const Vector<float> v({4., 2.});
		cout << u.mul_vec(v) << endl;
		// [4]
		// [2]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{2., 0.},
			{0., 2.}
		});
		const Vector<float> v({4., 2.});
		cout << u.mul_vec(v) << endl;
		// [8]
		// [4]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{2., -2.},
			{-2., 2.},
		});
		const Vector<float> v({4., 2.});
		cout << u.mul_vec(v) << endl;
		// [4]
		// [-4]
	}

	cout << endl << "===== Matrix mul_mat tests =====" << endl << endl; 

	{
		const Matrix<float> u({
			{1., 0.},
			{0., 1.}
		});
		const Matrix<float> v({
			{1., 0.},
			{0., 1.}
		});
		cout << u.mul_mat(v) << endl;
		// [1, 0]
		// [0, 1]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{1., 0.},
			{0., 1.}
		});
		const Matrix<float> v({
			{2., 1.},
			{4., 2.}
		});
		cout << u.mul_mat(v) << endl;
		// [2, 1]
		// [4, 2]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{3., -5.},
			{6., 8.}
		});
		const Matrix<float> v({
			{2., 1.},
			{4., 2.}
		});
		cout << u.mul_mat(v) << endl;
		// [-14, -7]
		// [44, 22]
	}

	cout << endl << "===== Error cases =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 0., 2.},
			{0., 1., 3.}
		});
		const Vector<float> v({4., 2.});
		cout << u.mul_vec(v) << endl;
		// The matrix columns and vector size are not compatible.
	}

	{
		const Matrix<float> u({
			{1., 0., 2.},
			{0., 1., 3.}
		});
		const Matrix<float> v({
			{2., 1., 0., 2.},
			{4., 2., 0., 2.}
		});
		cout << u.mul_mat(v) << endl;
		// The matrix columns and vector size are not compatible.
	}
}
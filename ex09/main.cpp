#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Transpose tests =====" << endl << endl;

	{
		const Matrix<float> u({
			{2., 6., 1},
			{4., 0, -5}
		});
		cout << u.transpose() << endl;
		// [2, 4]
		// [6, 0]
		// [1, -5]
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{6., -4.},
			{2., 0.},
			{-8., -1.}
		});
		cout << u.transpose() << endl;
		// [6,  2, -8]
		// [-4, 0, -1]
	}
}
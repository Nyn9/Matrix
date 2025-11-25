#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Matrix rank tests =====" << endl << endl;

	{
		const Matrix<float> u({
			{1., 0., 0.},
			{0., 1., 0.},
			{0., 0., 1.}
		});
		cout << u.rank() << endl;
		// 3
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{ 1., 2., 0., 0.},
			{ 2., 4., 0., 0.},
			{-1., 2., 1., 1.}
		});
		cout << u.rank() << endl;
		// 2
	}

	cout << "-----" << endl;

	{
		const Matrix<float> u({
			{ 8., 5., -2.},
			{ 4., 7., 20.},
			{ 7., 6., 1.},
			{21., 18., 7.},
		});
		cout << u.rank() << endl;
		// 3
	}
}
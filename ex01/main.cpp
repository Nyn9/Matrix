#include "../ETM.hpp"

using namespace std;

int main(void)	
{
	cout << "===== Linear Combination tests =====" << endl << endl;
	{
		const Vector<float> e1({1., 0., 0.});
		const Vector<float> e2({0., 1., 0.});
		const Vector<float> e3({0., 0., 1.});
		cout << linear_combination<Vector<float>, float>({e1, e2, e3}, {10., -2., 0.5});
		// [10]
		// [-2]
		// [0.5]
	}

	cout << "-----" << endl;

	{
		const Vector<float> v1({1., 2., 3.});
		const Vector<float> v2({0., 10., -100.});
		cout << linear_combination<Vector<float>, float>({v1, v2}, {10., -2.});
		// [10]
		// [0]
		// [230]
	}

	cout << endl << "===== Error cases =====" << endl << endl;

	{
		const Vector<float> v1({1., 2.});
		const Vector<float> v2({1., 2., 3.});
		cout << linear_combination<Vector<float>, float>({v1, v2}, {1., 1.});
		// The vectors doesn't have the same size.
	}
}
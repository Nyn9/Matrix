#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Cross product tests =====" << endl << endl;

	{
		const Vector<float> u({0., 0., 1.});
		const Vector<float> v({1., 0., 0.});
		cout << cross_product(u, v) << endl;
		// [0]
		// [1]
		// [0]
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({1., 2., 3.});
		const Vector<float> v({4., 5., 6.});
		cout << cross_product(u, v) << endl;
		// [-3]
		// [6]
		// [-3]
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({4., 2., -3.});
		const Vector<float> v({-2., -5., 16.});
		cout << cross_product(u, v) << endl;
		// [17]
		// [-58]
		// [-16]
	}
}
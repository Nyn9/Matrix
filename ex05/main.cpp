#include "../ETM.hpp"

using namespace std;

int main()
{
	{
		const Vector<float> u({1., 0.});
		const Vector<float> v({1., 0.});
		cout << angle_cos(u, v) << endl;
		// 1.0
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({1., 0.});
		const Vector<float> v({0., 1.});
		cout << angle_cos(u, v) << endl;
		// 0.0
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({-1., 1.});
		const Vector<float> v({1., -1.});
		cout << angle_cos(u, v) << endl;
		// -1.0
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({2., 1.});
		const Vector<float> v({4., 2.});
		cout << angle_cos(u, v) << endl;
		// 1.0
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({1., 2., 3.});
		const Vector<float> v({4., 5., 6.});
		cout << angle_cos(u, v) << endl;
		// 0.974632
	}
}
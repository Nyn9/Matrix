#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << "===== Dot product tests =====" << endl << endl;
	{
		Vector<float> u({0., 0.});
		const Vector<float> v({1., 1.});
		cout << u.dot(v) << endl;
		// 0
	}

	cout << "-----" << endl;

	{
		Vector<float> u({1., 1.});
		const Vector<float> v({1., 1.});
		cout << u.dot(v) << endl;
		// 2
	}

	cout << "-----" << endl;

	{
		Vector<float> u({-1., 6.});
		const Vector<float> v({3., 2.});
		cout << u.dot(v) << endl;
		// 9
	}

	cout << endl << "===== Error cases =====" << endl << endl;

	{
		Vector<float> u({1., 2., 3.});
		const Vector<float> v({4., 5.});
		cout << u.dot(v) << endl;
		// The vectors doesn't have the same size.
	}
}
#include "../ETM.hpp"

using namespace std;

int main()
{
	cout << endl << "===== Norms tests =====" << endl << endl;

	{
		const Vector<float> u({0., 0., 0.});
		cout << u.norm_1() << " " << u.norm_2() << " " << u.norm_inf() << endl;
		// 0, 0, 0
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({1., 2., 3.});
		cout << u.norm_1() << " " << u.norm_2() << " " << u.norm_inf() << endl;
		// 6, 3.74166, 3
	}

	cout << "-----" << endl;

	{
		const Vector<float> u({-1., -2.});
		cout << u.norm_1() << " " << u.norm_2() << " " << u.norm_inf() << endl;
		// 3, 2.23607, 2
	}
}
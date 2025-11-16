#include "../ETM.hpp"

int main()
{
	cout << "===== Lerp tests =====" << endl << endl;

	{
		cout << lerp(0., 1., 0.) << endl;
		// 0
	}

	cout << "-----" << endl;

	{
		cout << lerp(0., 1., 1.) << endl;
		// 1
	}

	cout << "-----" << endl;

	{
		cout << lerp(0., 1., 0.5) << endl;
		// 0.5
	}

	cout << "-----" << endl;

	{
		cout << lerp(21., 42., 0.3) << endl;
		// 27.3
	}

	cout << "-----" << endl;

	{
		cout << lerp(Vector({2., 1.}), Vector({4., 2.}), 0.3);
		// [2.6]
		// [1.3]
	}

	cout << "-----" << endl;

	{
		cout << lerp(Matrix({{2., 1.}, {3., 4.}}), Matrix({{20., 10.}, {30., 40.}}), 0.5);
		// [11, 5.5]
		// [16.5, 22]
	}

	cout << endl << "===== Error cases =====" << endl << endl;

	{
		cout << lerp(Vector({2., 1.}), Vector({4., 2.}), -0.5);
		// t must be in [0, 1].
	}

	{
		cout << lerp(Vector({2., 1.}), Vector({4., 2.}), 2);
		// t must be in [0, 1].
	}
}
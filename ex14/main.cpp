#include "../ETM.hpp"
#include <fstream>

using namespace std;

int main()
{
	cout << "===== Matrix projection test =====" << endl << endl;
	{
		Matrix<float> proj = projection(66.0f, 1.0f, 0.1f, 100.0f);
		cout << proj << endl;

		std::ofstream file("proj");

		if (!file) {
			std::cerr << "Impossible d'ouvrir le fichier\n";
			return 1;
		}

		for (size_t i = 0; i < proj.getCols(); ++i) {
			for (size_t j = 0; j < proj.getRows(); ++j) {
				file << proj.getData()[j][i] << ", ";
			}
			file << std::endl;
		}
		file.close();
	}
}
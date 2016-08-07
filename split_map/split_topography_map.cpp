#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
int main()
{

	// Create a test file
	/*std::ofstream test("./test.xyz");

	if (!test.good()) return 0;
	
	std::cout << "Create test file... "; fflush(stdout);
	double dx = 360 / 50.0;
	double dy = 180 / 50.0;
	for (double j = 90; j >= -90; j -= dy)
	{	
		for (double i = -180; i <= 180; i += dx)
		{	
			test << i << " " << j << " " << 1.2 << std::endl;	
		}
	}	
	test.close();
	std::cout << "Done" << std::endl;*/

	// Split the file
	//std::ifstream file("./test.xyz");

	const int num_div = 50;
	const double degree_per_fileX = 360.0 / (double)num_div;
	const double degree_per_fileY = 180.0 / (double)num_div;

	double longitude = -180;
	double latitude = 90; 	
	double next_degreeX = -180 + degree_per_fileX;
	double next_degreeY = 90 - degree_per_fileY;

	int countX = 0;
	int countY = 0;

	std::string line;

	std::stringstream outName;
	std::ofstream outVector[num_div];
	for (int i = 0; i < num_div; i++)
	{
		outName.str("");
		outName << "./splitted/etopo1_x" << i+1 << "_y1";
		outName << "_R" << num_div << ".xyz";

		outVector[i].open(outName.str().c_str());
		std::cout << "Open new file " << outName.str() << std::endl;
	}

	std::ifstream file("../data/ETOPO1_Ice_g_int.xyz");
	if (!file.good()) throw "Impossible to open file ../data/ETOPO1_Ice_g_int.xyz";

	file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);

    int nextPer = 1;
    int per = 0;
    std::cout << "File size: " << length/100000 << "MB" << std::endl;
	std::cout << "Split the file into sub-files..." << std::endl;
	while (!file.eof())
	{
		getline(file, line);
		std::stringstream streamline(line);
		streamline >> longitude;
		streamline >> latitude;

		per = file.tellg() / (double)length * 10;
		if (per > nextPer)
		{
			std::cout << per << "%" << std::endl;
			nextPer++;
		}

		outVector[countX] << line << std::endl;

		if (abs(longitude - next_degreeX) < 1e-8)
		{
			next_degreeX += degree_per_fileX;

			if (next_degreeX > 180)
			{
				next_degreeX = -180 + degree_per_fileX;
				countX = -1;

				if (abs(latitude - next_degreeY) < 1e-8)
				{
					next_degreeY -= degree_per_fileY;
					countY++;

					if (countY >= num_div) return 0;

					for (int i = 0; i < num_div; i++)
					{
						outName.str("");
						outName << "./splitted/etopo1_x" << i+1 << "_y" << countY+1;
						outName << "_R" << num_div << ".xyz";

						outVector[i].close();
						outVector[i].open(outName.str().c_str());
						std::cout << "Open new file " << outName.str() << std::endl;
					}
				}
			}
			//std::cout << next_degreeX << "  " << longitude << "  " << latitude << std::endl;

			countX++;

			if (!outVector[countX].good()) 
				throw std::string("Impossible to open file " + outName.str());
		}
	}
}

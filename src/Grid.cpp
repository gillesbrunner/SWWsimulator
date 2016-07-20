/*
 * Grid.cpp
 *
 *  Created on: 13 juil. 2016
 *      Author: gbrunner
 */

#include "Grid.h"

Grid::Grid(uint SIZE, uint RESOLUTION)
: _size(SIZE), _resolution(RESOLUTION), Zfactor(10)
{
	_resolution = std::max(2, (int)_resolution);

	_dx = _size / (double)_resolution;


	_topography = new double[_resolution * _resolution];
	memset(_topography, 0, _resolution * _resolution * sizeof(double));

	int x = 0, y = 0;
	for (size_t i = 0; i < _resolution; i++)
	{
			x = (i + 0.5) * _dx;
			for (size_t j = 0; j < _resolution; j++)
			{
				y = (j + 0.5) * _dx;
				Set(i,j, Zfactor * sin(x / 10.0) * cos(y / 10.0));
			}
	}
}

Grid::~Grid()
{
	delete[] _topography;
}

void Grid::interpolateGrid(VectorGrid& grid, double centerX, double centerY)
{
	int minX = tan((centerX - grid[0].first) * M_PI / 180.0) * _earth_ray;
	int maxX = tan((centerX + grid.back().first) * M_PI / 180.0) * _earth_ray;

	int minY = tan((centerY - grid[0].second[0]) * M_PI / 180.0) * _earth_ray;
	int maxY = tan((centerY + grid[0].second.back()) * M_PI / 180.0) * _earth_ray;

	for (size_t i = 0; i < _resolution; i++)
	{
		for (size_t j = 0; j < _resolution; j++)
		{
			int
		}
	}
}

void Grid::loadTopography(double latitude, double longitude)
{
	double angle = (_size / 2.0) / (double)_earth_ray * 180.0 / M_PI;
	int minfileX = floor((longitude + 180 - angle) / (360 / (double)(_num_files))) + 1;
	int maxfileX = ceil((longitude + 180 + angle) / (360 / (double)(_num_files))) + 1;

	int minfileY = floor((-latitude + 90 - angle) / (180 / (double)(_num_files))) + 1;
	int maxfileY = ceil((-latitude + 90 + angle) / (180 / (double)(_num_files))) + 1;

	std::cout << angle << std::endl;
	std::cout << minfileX << "  " << maxfileX << std::endl;
	std::cout << minfileY << "  " << maxfileY << std::endl;

	std::string line;
	std::stringstream streamline("");

	std::unordered_map<double,std::unordered_map<double,double>> loadedtopo;
	double lat, lon, height;

	for (int i = minfileX; i <= maxfileX; i++)
	{
		for(int j = minfileY; j <= maxfileY; j++)
		{
			std::stringstream filename;
			filename << "../data/splitted/etopo1_x" << i << "_y" << j << "_R" << _num_files << ".xyz";
			std::ifstream file(filename.str().c_str());

			if (!file.good()) throw std::string("Error reading file " + filename.str());
			while (!file.eof())
			{
				getline(file, line);
				streamline.str(line);

				// Deal with an empty line at the end of file
				if (streamline.fail()) streamline.clear();
				streamline >> lon;
				streamline >> lat;

				if (lon >= longitude - angle && lat >= latitude - angle
					&&  lon <= longitude + angle && lat <= latitude + angle)
				{
					streamline >> height;
					loadedtopo[lon][lat] = height;
				}
			}
			file.close();
		}
	}

	// Reconstruct the sorted grid
	VectorGrid grid;

	for (auto it = loadedtopo.begin(); it != loadedtopo.end(); it++)
	{
		std::pair<double,std::vector<std::pair<double,double>>> pair(it->first, std::vector<std::pair<double, double>>());
		grid.push_back(pair);
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			std::pair<double,double> pair2(it2->first, it2->second);
			grid.back().second.push_back(pair2);
		}
	}

	//sort the new grid
	for (int i = 0; i < grid.size(); i++)
	{
		std::sort(grid[i].second.begin(), grid[i].second.end());
	}
	std::sort(grid.begin(), grid.end());

}

void Grid::loadColorMap()
{

	tif = TIFFOpen("foo.tif", "r");


	TIFFClose(tif);
}
// 100km = 1 on (x,y)
//   1km = 1 on z
void Grid::render(osg::Group* root)
{
	loadTopography(46.519196, 6.580698);

	osg::Geode* geode = new osg::Geode();
	osg::Geometry* 	geo = new osg::Geometry();
	osg::Vec4Array* colors = new osg::Vec4Array;

	geode->addDrawable(geo);

	// Define the vertices
	osg::Vec3Array* GridVertices = new osg::Vec3Array;
	for (size_t i = 0; i < _resolution; i++)
	{
		for (size_t j = 0; j < _resolution; j++)
		{
			GridVertices->push_back( osg::Vec3( (i + 0.5) * _dx, (j + 0.5) * _dx, Get(i,j) ) );
			//colors->push_back(osg::Vec4(1.0f, 0.89f, 0.77f, 1.0f) );
		}
	}
	geo->setVertexArray( GridVertices );


	// define the triangles
	for (size_t i = 0; i < _resolution; i++)
	{
		for (size_t j = 0; j < _resolution; j++)
		{
			if (i > 0 && j > 0)
			{
				osg::DrawElementsUInt* face =
					new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i-1) * _resolution + j-1);
				face->push_back(    i * _resolution + j-1);
				face->push_back(    i * _resolution + j  );
				geo->addPrimitiveSet(face);
				colors->push_back(osg::Vec4(1.0f, 0.89f, 0.77f, 1.0f) );


				osg::DrawElementsUInt* faceTwo =
					new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				faceTwo->push_back((i-1) * _resolution + j-1);
				faceTwo->push_back((i-1) * _resolution + j  );
				faceTwo->push_back(    i * _resolution + j  );
				geo->addPrimitiveSet(faceTwo);
				colors->push_back(osg::Vec4(1.0f, 0.75f, 0.65f, 1.0f) );
			}
		}
	}

	geo->setColorArray(colors);
	geo->setColorBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);

	// Declare and initialize a transform node.
	osg::PositionAttitudeTransform* gridTransform =
			new osg::PositionAttitudeTransform();

	root->addChild(gridTransform);
	gridTransform->addChild(geode);
	gridTransform->setPosition( osg::Vec3d(0,0,0) );

}

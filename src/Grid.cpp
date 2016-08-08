/*
 * Grid.cpp
 *
 *  Created on: 13 juil. 2016
 *      Author: gbrunner
 */

#include "Grid.h"

Grid::Grid(uint SIZE, uint RESOLUTION)
: _size(SIZE), _resolution(RESOLUTION), Zfactor(0.05)
{
	_resolution = std::max(2, (int)_resolution);

	_dx = _size / (double)_resolution;


	_topography = new double[_resolution * _resolution];
	memset(_topography, 0, _resolution * _resolution * sizeof(double));

	_colorMapRGB = new int[_resolution * _resolution];
	memset(_colorMapRGB, 0, _resolution * _resolution * sizeof(int));

}

Grid::~Grid()
{
	delete[] _topography;
	delete[] _colorMapRGB;
}

/*void Grid::ComputeCellsVolumes(VectorGrid& grid)
{
	int GSize = grid.size()-1;
	for (size_t i = 1; i < grid.size() - 1; i++)
	{
		grid[i].second[0].second = (1.0 / 9.0 * grid[i-1].second[0].second +  4.0 / 9.0 * grid[i-1].second[0].second + 1.0 / 9.0 * grid[i-1].second[1].second
						   	      + 4.0 / 9.0 * grid[i  ].second[0].second + 16.0 / 9.0 * grid[i  ].second[0].second + 4.0 / 9.0 * grid[i  ].second[1].second
								  + 1.0 / 9.0 * grid[i+1].second[0].second +  4.0 / 9.0 * grid[i+1].second[0].second + 1.0 / 9.0 * grid[i+1].second[1].second) / 4;

		for (size_t j = 1; j < grid[i].second.size() - 1; j++)
		{
			grid[i].second[j].second = (1.0 / 9.0 * grid[i-1].second[j-1].second +  4.0 / 9.0 * grid[i-1].second[j].second + 1.0 / 9.0 * grid[i-1].second[j+1].second
					           	   	  + 4.0 / 9.0 * grid[i  ].second[j-1].second + 16.0 / 9.0 * grid[i  ].second[j].second + 4.0 / 9.0 * grid[i  ].second[j+1].second
									  + 1.0 / 9.0 * grid[i+1].second[j-1].second +  4.0 / 9.0 * grid[i+1].second[j].second + 1.0 / 9.0 * grid[i+1].second[j+1].second) / 4;
		}

		grid[i].second[GSize].second = (1.0 / 9.0 * grid[i-1].second[GSize-1].second +  4.0 / 9.0 * grid[i-1].second[GSize].second + 1.0 / 9.0 * grid[i-1].second[GSize].second
							   	   	  + 4.0 / 9.0 * grid[i  ].second[GSize-1].second + 16.0 / 9.0 * grid[i  ].second[GSize].second + 4.0 / 9.0 * grid[i  ].second[GSize].second
									  + 1.0 / 9.0 * grid[i+1].second[GSize-1].second +  4.0 / 9.0 * grid[i+1].second[GSize].second + 1.0 / 9.0 * grid[i+1].second[GSize].second) / 4;
	}

	for (size_t j = 1; j < grid[0].second.size() - 1; j++)
	{
		grid[0].second[j].second = (1.0 / 9.0 * grid[0].second[j-1].second +  4.0 / 9.0 * grid[0].second[j].second + 1.0 / 9.0 * grid[0].second[j+1].second
						   	   	  + 4.0 / 9.0 * grid[0].second[j-1].second + 16.0 / 9.0 * grid[0].second[j].second + 4.0 / 9.0 * grid[0].second[j+1].second
								  + 1.0 / 9.0 * grid[1].second[j-1].second +  4.0 / 9.0 * grid[1].second[j].second + 1.0 / 9.0 * grid[1].second[j+1].second) / 4;
	}


	for (size_t j = 1; j < grid[GSize].second.size() - 1; j++)
	{
		grid[GSize].second[j].second = (1.0 / 9.0 * grid[GSize-1].second[j-1].second +  4.0 / 9.0 * grid[GSize-1].second[j].second + 1.0 / 9.0 * grid[GSize].second[j+1].second
						       	      + 4.0 / 9.0 * grid[GSize].second[j-1].second + 16.0 / 9.0 * grid[GSize].second[j].second + 4.0 / 9.0 * grid[GSize-1].second[j+1].second
									  + 1.0 / 9.0 * grid[GSize].second[j-1].second +  4.0 / 9.0 * grid[GSize].second[j].second + 1.0 / 9.0 * grid[GSize].second[j+1].second) / 4;
	}
}*/

void Grid::interpolateGrid(VectorGrid& grid)
{
	double angledx = (grid.X[grid.X.length()-1] - grid.X[0]) / (double)(_resolution-1);
	double angledy = (grid.Y[grid.Y.length()-1] - grid.Y[0]) / (double)(_resolution-1);

	alglib::spline2dinterpolant s;

	// build spline
	alglib::spline2dbuildbicubicv(grid.X, grid.X.length(), grid.Y, grid.Y.length(), grid.H, 1, s);

	double minH = DBL_MAX;
	double maxH = DBL_MIN;
	for (size_t i = 0; i < _resolution; i++)
	{
		for (size_t j = 0; j < _resolution; j++)
		{
		    // Interpolate the height
			Set(i, j, alglib::spline2dcalc(s, grid.X[0] + i * angledx , grid.Y[0] + j * angledy));

			if (minH > Get(i,j)) minH = Get(i,j);
			if (maxH < Get(i,j)) maxH = Get(i,j);

			assert(grid.X[0] + i * angledx <= grid.X[grid.X.length()-1]);
			assert(grid.Y[0] + j * angledy <= grid.Y[grid.Y.length()-1]);
		}
	}

	Zfactor = 200 / (maxH-minH);
	std::cout << "Zfactor " << Zfactor << std::endl;
}

void Grid::loadTopography(double latitude, double longitude)
{
	double angle = (_size / 2.0) / (double)_earth_ray * 180.0 / M_PI;
	int minfileX = floor((longitude + 180 - angle) / (360 / (double)(_num_files))) + 1;
	int maxfileX = ceil((longitude + 180 + angle) / (360 / (double)(_num_files))) + 1;

	int minfileY = floor((-latitude + 90 - angle) / (180 / (double)(_num_files))) + 1;
	int maxfileY = ceil((-latitude + 90 + angle) / (180 / (double)(_num_files))) + 1;

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "minX: " << minfileX << "  maxX: " << maxfileX << std::endl;
	std::cout << "minY: " << minfileY << "  maxY: " << maxfileY << std::endl;

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
	std::vector<std::pair<double,std::vector<std::pair<double,double>>>> grid;

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
	for (size_t i = 0; i < grid.size(); i++)
	{
		std::sort(grid[i].second.begin(), grid[i].second.end());
	}
	std::sort(grid.begin(), grid.end());


	// Construct the Spline structure to be used for interpolation
	VectorGrid SplineGrid;
	size_t n = grid.size();
	size_t m = grid[0].second.size();

	SplineGrid.X.setlength(n);
	SplineGrid.Y.setlength(m);
	SplineGrid.H.setlength(n*m);

	for (size_t i = 0; i < n; i++)
	{
		SplineGrid.X[i] = grid[i].first;
		for (size_t j = 0; j < m; j++)
		{
			if (i == 0) SplineGrid.Y[j] =  grid[0].second[j].first;
			else assert(SplineGrid.Y[j] == grid[0].second[j].first);
			SplineGrid.H[i + j * n] = grid[i].second[j].second;
		}
	}

	interpolateGrid(SplineGrid);
	loadColorMap(latitude, longitude);
}

void Grid::loadColorMap(double latitude, double longitude)
{

	std::string fileName = "../data/color_etopo1_ice_full.tif";
	tif = TIFFOpen(fileName.c_str(), "r");

	if (tif)
	{
		uint32 w, h;
		size_t npixels;
		uint32* raster;

		TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &w);
		TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &h);
		npixels = w * h;
		raster = (uint32*) _TIFFmalloc(npixels * sizeof (uint32));
		if (raster != NULL)
		{
		    if (TIFFReadRGBAImage(tif, w, h, raster, 0))
		    {
				const double pixeldx = w / 360.0;
				const double pixeldy = h / 180.0;

		    	double angle = (_size / 2.0) / (double)_earth_ray * 180.0 / M_PI;
		    	double lonS = longitude + 180 - angle;
		    	double lonE = longitude + 180 + angle;
		    	double latS = -latitude + 90 - angle;
		    	double latE = -latitude + 90 + angle;

		    	uint minX = floor(lonS * pixeldx);
		    	uint maxX = ceil(lonE * pixeldx);
		    	uint minY = floor(latS * pixeldy);
		    	uint maxY = ceil(latE * pixeldy);

		    	assert(maxX < w);
		    	assert(maxY < h);

		    	uint n = maxX-minX+1;
		    	uint m = maxY-minY+1;

		    	double dx = (lonE - lonS) / (double)(n-1);
		    	double dy = (latE - latS) / (double)(m-1);

		    	VectorGrid colorGrid;
		    	colorGrid.X.setlength(n);
		    	colorGrid.Y.setlength(m);
		    	colorGrid.H.setlength(3 * n * m);

		    	int val = 0;
		    	std::cout << "Npixels " << npixels << std::endl;
		    	std::cout << "w " << w << " h " << h << std::endl;
		    	std::cout << "minX " << minX << " maxX " << maxX << std::endl;
		    	std::cout << "minY " << minY << " maxY " << maxY << std::endl;
		    	std::cout << "n " << n << " m " << m << std::endl;

		    	// Create the RGB grid to interpolate the colors
		    	for (uint i = 0; i < n; i++)
		    	{
		    		colorGrid.X[i] = lonS +  i * dx;
		    		for (uint j = 0; j < m; j++)
		    		{
		    			if (i == 0) colorGrid.Y[j] = latS +  j * dy;
		    			val = raster[(i + minX) + (h - j - minY) * w]; // Starts at low-left corner

		    			colorGrid.H[i * 3     + (m-1 - j) * 3 * n] = TIFFGetR(val);
		    			colorGrid.H[i * 3 + 1 + (m-1 - j) * 3 * n] = TIFFGetG(val);
		    			colorGrid.H[i * 3 + 2 + (m-1 - j) * 3 * n] = TIFFGetB(val);
		    		}
		    	}

		    	// Interpolate the color
		    	alglib::spline2dinterpolant c;

		    	// build spline
		    	alglib::spline2dbuildbicubicv(colorGrid.X, colorGrid.X.length(), colorGrid.Y, colorGrid.Y.length(), colorGrid.H, 3, c);

		    	dx = (colorGrid.X[colorGrid.X.length()-1] - colorGrid.X[0]) / (double)(_resolution-1);
		    	dy = (colorGrid.Y[colorGrid.Y.length()-1] - colorGrid.Y[0]) / (double)(_resolution-1);

		    	alglib::real_1d_array buffer;
		    	for (size_t i = 0; i < _resolution; i++)
		    	{
		    		for (size_t j = 0; j < _resolution; j++)
		    		{
		    			// interpolate the color
		    		    alglib::spline2dcalcv(c, colorGrid.X[0] + i * dx , colorGrid.Y[0] + j * dy, buffer);
		    		    _colorMapRGB[i * _resolution + j] = (int)(((char)buffer[2] << 16) + ((char)buffer[1] << 8) + (int)buffer[0]);

		    			assert(colorGrid.X[0] + i * dx <= colorGrid.X[colorGrid.X.length()-1]);
		    			assert(colorGrid.Y[0] + j * dy <= colorGrid.Y[colorGrid.Y.length()-1]);
		    		}
		    	}
		    }
		    _TIFFfree(raster);
		}
		TIFFClose(tif);
	}
}

// 100km = 1 on (x,y)
void Grid::render(osg::Group* root)
{
	//loadTopography(17.827623, 145.132992);	// Mariane Trench
	//loadTopography(28.861680, -15.286634);	// Tenerif
	loadTopography(25.881838, -80.805156);	// Miami
	//loadTopography(46.47246, 6.580616);		// Lausanne 150kms
	//loadTopography(-33.959678, 18.670304); 	// Cape Town
	//loadTopography(64.887146, -18.430727);	// Islande
	//loadTopography(39.356189, 14.083115);		// Sicile

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
			GridVertices->push_back( osg::Vec3( (i + 0.5) * _dx, (j + 0.5) * _dx, Zfactor * Get(i,j) ) );
			//colors->push_back(osg::Vec4(1.0f, 0.89f, 0.77f, 1.0f) );
		}
	}
	geo->setVertexArray( GridVertices );


	// define the triangles
	for (size_t i = 0; i < _resolution; i++)
	{
		for (size_t j = 0; j < _resolution; j++)
		{
			colors->push_back(osg::Vec4(GetR(i,j), GetG(i,j), GetB(i,j), 1.0f) );

			if (i > 0 && j > 0)
			{
				osg::DrawElementsUInt* face =
					new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i-1) * _resolution + j-1);
				face->push_back(    i * _resolution + j-1);
				face->push_back(    i * _resolution + j  );
				geo->addPrimitiveSet(face);


				osg::DrawElementsUInt* faceTwo =
					new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				faceTwo->push_back((i-1) * _resolution + j-1);
				faceTwo->push_back((i-1) * _resolution + j  );
				faceTwo->push_back(    i * _resolution + j  );
				geo->addPrimitiveSet(faceTwo);
			}
		}
	}

	geo->setColorArray(colors);
	geo->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	// Declare and initialize a transform node.
	osg::PositionAttitudeTransform* gridTransform =
			new osg::PositionAttitudeTransform();

	root->addChild(gridTransform);
	gridTransform->addChild(geode);
	gridTransform->setPosition( osg::Vec3d(0,0,0) );

}

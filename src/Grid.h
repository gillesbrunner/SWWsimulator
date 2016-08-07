/*
 * Grid.h
 *
 *  Created on: 13 juil. 2016
 *      Author: gbrunner
 */

#ifndef GRID_H_
#define GRID_H_

#include "included.h"
#include <tiffio.h>

struct VectorGrid
{
	alglib::real_1d_array X;
	alglib::real_1d_array Y;
	alglib::real_1d_array H;
};

class Grid
{
private:
	const double _num_files = 50;
	const double _earth_ray = 6371;

	uint _size;		 // size of the domain [km]
	uint _resolution; // number of points
	double _dx;

	double Zfactor;
	double* _topography;
	int* _colorMapRGB;

	TIFF* tif;

	inline int lonlatToXY(double lon, double cLon) { return (int)tan((cLon - lon) * M_PI / 180.0) * _earth_ray; }

	//void ComputeCellsVolumes(VectorGrid& grid);
	void interpolateGrid(VectorGrid& grid);

public:
	Grid(uint size, uint resolution);
	Grid(std::string filename);
	virtual ~Grid();

	inline double Get(uint i, uint j)
	{
		assert(i < _resolution && j < _resolution);
		return _topography[i * _resolution + j];
	}

	inline void Set(uint i, uint j, double val)
	{
		assert(i < _resolution && j < _resolution);
		_topography[i * _resolution + j] = val;
	}

	// Colors
	inline float GetR(uint i, uint j) { return (float)(TIFFGetR(_colorMapRGB[i *_resolution + j]) / 255.0);}
	inline float GetG(uint i, uint j) { return (float)(TIFFGetG(_colorMapRGB[i *_resolution + j]) / 255.0);}
	inline float GetB(uint i, uint j) { return (float)(TIFFGetB(_colorMapRGB[i *_resolution + j]) / 255.0);}

	// OSG
	void loadTopography(double latitude, double longitude);
	void loadColorMap(double latitude, double longitude);
	void render(osg::Group* root);
};

#endif /* GRID_H_ */

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

typedef std::vector<std::pair<double,std::vector<std::pair<double,double>>>> VectorGrid;
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

	TIFF* tif;

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

	// OSG
	void loadTopography(double latitude, double longitude);
	void loadColorMap();
	void render(osg::Group* root);
};

#endif /* GRID_H_ */

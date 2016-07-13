/*
 * Grid.h
 *
 *  Created on: 13 juil. 2016
 *      Author: gbrunner
 */

#ifndef GRID_H_
#define GRID_H_

#include "included.h"

class Grid
{
private:
	uint _size;		 // size of the domain [km]
	uint _resolution; // number of points

	double* _topography;
public:
	Grid(uint size, uint resolution);
	Grid(std::string filename);
	virtual ~Grid();

	inline double Get(uint i, uint j) { assert(i < _size && j < _size); return _topography[i * _size + j]; }

	void render(osg::Group* root);
};

#endif /* GRID_H_ */

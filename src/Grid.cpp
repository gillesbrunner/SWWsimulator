/*
 * Grid.cpp
 *
 *  Created on: 13 juil. 2016
 *      Author: gbrunner
 */

#include "Grid.h"

Grid::Grid(uint SIZE, uint RESOLUTION)
: _size(SIZE), _resolution(RESOLUTION)
{
	_topography = new double[_size * _size];
	memset(_topography, 0, _size * _size * sizeof(double));
}

Grid::~Grid()
{
	delete[] _topography;
}


// 100km = 1 on (x,y)
//   1km = 1 on z
void Grid::render(osg::Group* root)
{
	double dx = _size / (double)(_resolution-1);

	osg::Geode* geode = new osg::Geode();
	osg::Geometry* 	geo = new osg::Geometry();;
	osg::PositionAttitudeTransform* gridTransform = new osg::PositionAttitudeTransform();

	geode->addDrawable(geo);
	root->addChild(geode);

	// Define the vertices
	osg::Vec3Array* GridVertices = new osg::Vec3Array;
	for (size_t i = 0; i < _size; i++)
		for (size_t j = 0; j < _size; j++)
			GridVertices->push_back( osg::Vec3( i * dx, j * dx, Get(i,j) ) );

	// define the triangles
	for (size_t i = 0; i < _size; i++)
	{
		for (size_t j = 0; j < _size; j++)
		{
			if (i > 0 && j > 0)
			{
				osg::DrawElementsUInt* face =
					new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i-1) * _size + j-1);
				face->push_back(    i * _size + j-1);
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);

				face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i-1) * _size + j-1);
				face->push_back((i-1) * _size + j  );
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);
			}

			if (i > 0 && j < _size-1)
			{
				osg::DrawElementsUInt* face =
					new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i-1) * _size + j+1);
				face->push_back(    i * _size + j+1);
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);

				face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i-1) * _size + j+1);
				face->push_back((i-1) * _size + j  );
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);
			}

			if (i < _size-1 && j > 0)
			{
				osg::DrawElementsUInt* face =
				new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i+1) * _size + j-1);
				face->push_back(    i * _size + j-1);
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);

				face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i+1) * _size + j-1);
				face->push_back((i+1) * _size + j );
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);
			}

			if (i < _size-1 && j < _size-1)
			{
				osg::DrawElementsUInt* face =
				new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i+1) * _size + j+1);
				face->push_back(    i * _size + j+1);
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);

				face = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
				face->push_back((i+1) * _size + j+1);
				face->push_back((i+1) * _size + j );
				face->push_back(    i * _size + j  );
				geo->addPrimitiveSet(face);
			}
		}
	}

	osg::Vec4Array* colors = new osg::Vec4Array;
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 0 red
	colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f) ); //index 1 green
	colors->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f) ); //index 2 blue
	colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f) ); //index 3 white
	colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f) ); //index 4 red
	geo->setColorArray(colors);
	geo->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	gridTransform->addChild(geode);
	gridTransform->setPosition( osg::Vec3d(0,0,0) );
}

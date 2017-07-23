#ifndef __SHADEREC_H
#define __SHADEREC_H

class World;

#include "Constants.h" // includes Point3D, Normal, RGBColor
#include "Ray.h"

class ShadeRec {
	public:
		bool hitObject;
		Point3D hitPoint;
		Point3D localHitPoint;
		
		Normal normal;
		Ray ray;
		int depth;
		float t;
		World& world;
		RGBColor color;
		
		ShadeRec(World&);
		
		ShadeRec(const ShadeRec&);
};

#endif
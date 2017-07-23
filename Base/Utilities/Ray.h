#ifndef __RAY_H
#define __RAY_H

#include "Constants.h"

class Ray {
	public:
		Point3D origin;
		Vector3D direction;
		
		Ray();
		Ray(const Point3D&, const Vector3D&);
		Ray(const Ray&);
		Ray& operator=(const Ray&);
		~Ray();
};

#endif
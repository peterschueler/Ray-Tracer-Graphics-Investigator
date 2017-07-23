#ifndef __SPHERE_H
#define __SPHERE_H

#include "GeometricObject.h"

class Sphere: public GeometricObject {
	public:
		Sphere();
		Sphere(Point3D, double);
		Sphere(const Sphere&);
		virtual Sphere* clone() const;
		virtual ~Sphere();
		
		Sphere& operator=(const Sphere&);
		
		void setCenter(const Point3D&);
		void setCenter(const double, const double, const double);
		void setRadius(const double);
		
		virtual bool hit(const Ray& ray, double&, ShadeRec&) const;
		
	private:
		Point3D center;
		double radius;
		
		static const double kEpsilon;
};

inline void Sphere::setCenter(const Point3D& c) {
	center = c;
}

inline void Sphere::setCenter(const double x, const double y, const double z) {
	center.x = x;
	center.y = y;
	center.z = z;
}

inline void Sphere::setRadius(const double r) {
	radius = r;
}

#endif
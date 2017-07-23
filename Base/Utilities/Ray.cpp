#include "Ray.h"

Ray::Ray(): origin(), direction(0.0, 0.0, 1.0) {
}

Ray::Ray(const Point3D& org, const Vector3D& dir): origin(org), direction(dir) {
}

Ray::Ray(const Ray& ray): origin(ray.origin), direction(ray.direction) {
}

Ray& Ray::operator=(const Ray& rhs) {
	if (this == &rhs) {
		return *this;
	}
	
	origin = rhs.origin;
	direction = rhs.direction;
	
	return *this;
}

Ray::~Ray() {
}
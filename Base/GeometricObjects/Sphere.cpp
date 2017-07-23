#include "Sphere.h"
#include "math.h"

const double Sphere::kEpsilon = 0.001;

Sphere::Sphere(): GeometricObject(), center(), radius(1.0) {
}

Sphere::Sphere(Point3D c, double r): GeometricObject(), center(c), radius(r) {
}

Sphere* Sphere::clone() const {
	return (new Sphere(*this));
}

Sphere::Sphere(const Sphere& sphere): GeometricObject(sphere), center(sphere.center), radius(sphere.radius) {
}

Sphere& Sphere::operator=(const Sphere& rhs) {
	if (this == &rhs) {
		return *this;
	}
	
	GeometricObject::operator= (rhs);
	
	center = rhs.center;
	radius = rhs.radius;
	
	return *this;
}

Sphere::~Sphere() {
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
	double t;
	Vector3D temp = ray.origin - center;
	double a = ray.direction * ray.direction;
	double b = 2.0 * temp * ray.direction;
	double c = temp * temp -radius * radius;
	double disc = b * b - 4.0 * a * c;
	
	if (disc < 0.0) {
		return false;
	} else {
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;
		
		if (t > kEpsilon) {
			tmin = t;
			sr.normal = (temp + t * ray.direction) / radius;
			sr.localHitPoint = ray.origin + t * ray.direction;
			return true;
		}
		
		t = (-b + e) / denom;
		
		if (t > kEpsilon) {
			tmin = t;
			sr.normal = (temp + t * ray.direction) / radius;
			sr.localHitPoint = ray.origin + t * ray.direction;
			return true;
		}
	}
	return false;
}
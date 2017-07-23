#include "SingleSphere.h"
#include "../World/World.h"
#include "../Utilities/ShadeRec.h"

SingleSphere::SingleSphere(): Tracer() {
}

SingleSphere::SingleSphere(World* ptr): Tracer(ptr) {
}

SingleSphere::~SingleSphere() {
}

RGBColor SingleSphere::traceRay(const Ray& ray) const {
	ShadeRec sr(*worldPointer);
	double t;
	
	if (worldPointer->sphere.hit(ray, t, sr)) {
		return RGBColor(1.0, 0.0, 0.0);
	} else {
		return RGBColor();
	}
}
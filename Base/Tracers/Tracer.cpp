#include "Tracer.h"

Tracer::Tracer(): worldPointer(NULL) {
}

Tracer::Tracer(World* ptr): worldPointer(ptr) {
}

Tracer::~Tracer() {
	if (worldPointer) {
		worldPointer = NULL;
	}
}

RGBColor Tracer::traceRay(const Ray& ray) const {
	return RGBColor();
}

RGBColor Tracer::traceRay(const Ray ray, const int depth) const {
	return RGBColor();
}
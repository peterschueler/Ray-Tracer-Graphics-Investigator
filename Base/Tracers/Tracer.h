#ifndef __TRACER_H
#define __TRACER_H

#include "../Utilities/Constants.h" // includes RGBColor
#include "../Utilities/Ray.h"

class World;

class Tracer {
	public:
		Tracer();
		Tracer(World*);
		virtual ~Tracer();
		
		virtual RGBColor traceRay(const Ray&) const;
		virtual RGBColor traceRay(const Ray, const int) const;
		
	protected:
		World* worldPointer;
};

#endif
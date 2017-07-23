#ifndef __SINGLE_SPHERE_H
#define __SINGLE_SPHERE_H

#include "Tracer.h"

class SingleSphere: public Tracer {
	public:
		SingleSphere();
		SingleSphere(World*);
		virtual ~SingleSphere();
		
		virtual RGBColor traceRay(const Ray&) const;
};

#endif
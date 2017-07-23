#ifndef __GEOMETRICOBJECT_H
#define __GEOMETRICOBJECT_H

#include "../Utilities/Constants.h"
#include "../Utilities/ShadeRec.h"

class GeometricObject {
	public:
		GeometricObject();
		GeometricObject(const GeometricObject&);
		virtual GeometricObject* clone() const = 0;
		
		virtual ~GeometricObject();
		
		virtual bool hit(const Ray&, double&, ShadeRec&) const = 0;
		
	protected:
		RGBColor color;
		
		GeometricObject& operator=(const GeometricObject&);
};

#endif
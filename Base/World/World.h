#ifndef __WORLD_H
#define __WORLD_H

#include <vector>

#include "ViewPlane.h"
#include "../Utilities/Constants.h"
#include "../GeometricObjects/Sphere.h"
#include "../Tracers/Tracer.h"


class World {
	public:
		ViewPlane viewPlane;
		RGBColor backgroundColor;
		Sphere sphere;
		Tracer* tracerPointer;
		
		World();
		~World();
		void build();
		
		std::vector<sf::Uint8> renderScene();
		void displayPixel(const int, const int, const RGBColor&);
		
		RGBColor maxToOne(const RGBColor&) const;
		RGBColor clampToColor(const RGBColor&) const;
		
	private:
		std::vector<sf::Uint8> pixels;
};

#endif
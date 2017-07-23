#include "World.h"
#include "../Utilities/Constants.h"
#include "../GeometricObjects/Sphere.h"
#include "../Tracers/SingleSphere.h"

#include <SFML/Graphics.hpp>

#include <iostream>

World::World(): backgroundColor(RGBColor()), tracerPointer(NULL), pixels(200*200*4) {
	build();
}

World::~World() {
	if (tracerPointer) {
		delete tracerPointer;
		tracerPointer = NULL;
	}
}

void World::build() {
	viewPlane.setHorizontalResolution(200);
	viewPlane.setVerticalResolution(200);
	viewPlane.setPixelSize(1.0);
	
	backgroundColor = RGBColor();
	tracerPointer = new SingleSphere(this);
	sphere.setCenter(Point3D());
	sphere.setRadius(85.0);
}

std::vector<sf::Uint8> World::renderScene() {
	RGBColor pixelColor;
	Ray ray;
	int hRes = viewPlane.horizontalResolution;
	int vRes = viewPlane.verticalResolution;
	float size = viewPlane.size;
	float zw = 100.0;
	
	ray.direction = Vector3D(0, 0, -1);
	
	for (int r=0; r < vRes; r++) {
		for (int c=0; c <= hRes; c++) {
			ray.origin = Point3D(size * (c - hRes / 2.0 + 0.5), size * (r - vRes / 2.0 + 0.5), zw);
			pixelColor = tracerPointer->traceRay(ray);
			displayPixel(r, c, pixelColor);
		}
	}
	
	return pixels;
}

void World::displayPixel(const int row, const int column, const RGBColor& pixelColor) {
	RGBColor mappedColor;
	
	if (viewPlane.showOutOfGamut) {
		mappedColor = clampToColor(pixelColor);
	} else {
		mappedColor = maxToOne(pixelColor);
	}
	
	if (viewPlane.gamma != 1.0) {
	}
	
	int x = column;
	int y = viewPlane.verticalResolution - row - 1;
	
	// here be the render code
	pixels[(x + y * 200) * 4 + 0] = mappedColor.x * 255;
	pixels[(x + y * 200) * 4 + 1] = mappedColor.y * 255;
	pixels[(x + y * 200) * 4 + 2] = mappedColor.z * 255;
	pixels[(x + y * 200) * 4 + 3] = 255;
}

RGBColor World::maxToOne(const RGBColor& c) const {
	float maxValue = std::max(c.x, std::max(c.y, c.z));
	
	if (maxValue > 1.0) {
		return c / maxValue;
	} else {
		return c;
	}
}

RGBColor World::clampToColor(const RGBColor& rawColor) const {
	RGBColor c(rawColor);
	
	if (rawColor.x > 1.0 || rawColor.y > 1.0 || rawColor .z > 1.0) {
		c.x = 1.0; c.y = 0.0; c.z = 0.0;
	}
	return c;
}
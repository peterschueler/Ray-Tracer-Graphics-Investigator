#include "ViewPlane.h"

ViewPlane::ViewPlane(): horizontalResolution(400), verticalResolution(400), size(1.0), numberOfSamples(1), gamma(1.0), inverseGamma(1.0), showOutOfGamut(false) {
}

ViewPlane::ViewPlane(const ViewPlane& vp): horizontalResolution(vp.horizontalResolution), verticalResolution(vp.verticalResolution), size(vp.size), numberOfSamples(vp.numberOfSamples), gamma(vp.gamma), inverseGamma(vp.inverseGamma), showOutOfGamut(vp.showOutOfGamut) {
}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs) {
	if (this == &rhs) {
		return *this;
	}
	
	horizontalResolution = rhs.horizontalResolution;
	verticalResolution = rhs.verticalResolution;
	size = rhs.size;
	numberOfSamples = rhs.numberOfSamples;
	gamma = rhs.gamma;
	inverseGamma = rhs.inverseGamma;
	showOutOfGamut = rhs.showOutOfGamut;
	
	return *this;
}

ViewPlane::~ViewPlane() {
}
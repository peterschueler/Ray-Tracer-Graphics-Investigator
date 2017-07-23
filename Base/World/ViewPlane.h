#ifndef __VIEWPLANE_H
#define __VIEWPLANE_H

class ViewPlane {
	public:
		int horizontalResolution;
		int verticalResolution;
		float size;
		int numberOfSamples;
		float gamma;
		float inverseGamma;
		bool showOutOfGamut;
		
	public:
		ViewPlane();
		ViewPlane(const ViewPlane&);
		ViewPlane& operator=(const ViewPlane&);
		~ViewPlane();
		
		void setHorizontalResolution(const int);
		void setVerticalResolution(const int);
		void setPixelSize(const float);
		void setGamma(const float);
		void setGamutDisplay(const bool);
		void setSamples(const int);
};

inline void ViewPlane::setHorizontalResolution(const int hRes) {
	horizontalResolution = hRes;
}

inline void ViewPlane::setVerticalResolution(const int vRes) {
	verticalResolution = vRes;
}

inline void ViewPlane::setPixelSize(const float _size) {
	size = _size;
}

inline void ViewPlane::setGamma(const float g) {
	gamma = g;
	inverseGamma = 1.0 / gamma;
}

inline void ViewPlane::setGamutDisplay(const bool show) {
	showOutOfGamut = show;
}

inline void ViewPlane::setSamples(const int n) {
	numberOfSamples = n;
}

#endif
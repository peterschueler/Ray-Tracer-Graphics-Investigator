#include "GeometricObject.h"

GeometricObject::GeometricObject() {
}

GeometricObject::GeometricObject(const GeometricObject& object) {
}

GeometricObject& GeometricObject::operator=(const GeometricObject& rhs) {
	if (this == &rhs) {
		return *this;
	}
	// TODO: Code Dealing With Materials
	return *this;
}

GeometricObject::~GeometricObject() {

}
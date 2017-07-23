#ifndef __CONSTANTS_H
#define __CONSTANTS_H

#include <sfml/Graphics.hpp>

typedef sf::Vector3f Normal;
typedef sf::Vector3f Point3D;
typedef sf::Vector3f RGBColor;
typedef sf::Vector3f Vector3D;

template <typename T>
sf::Vector3<T> operator*(const double left, const sf::Vector3<T>& right) {
	return sf::Vector3<T>(right.x * left, right.y * left, right.z * left);
}

template <typename T>
sf::Vector3<T> operator/(const sf::Vector3<T>& left, const double right) {
	return sf::Vector3<T>(left.x / right, left.y / right, left.z / right);
}

template <typename T>
double operator*(const sf::Vector3<T>& left, const sf::Vector3<T>& right) {
	return (right.x * left.x + right.y * left.y + right.z * left.z);
}

#endif
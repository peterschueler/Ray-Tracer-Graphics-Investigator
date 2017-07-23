#include "ShadeRec.h"

ShadeRec::ShadeRec(World& w): hitObject(false), hitPoint(), localHitPoint(), normal(), ray(), depth(0), t(0.0), world(w) {
}

ShadeRec::ShadeRec(const ShadeRec& source): hitObject(source.hitObject), hitPoint(source.hitPoint), localHitPoint(source.localHitPoint), normal(source.normal), ray(source.ray), depth(source.depth), t(source.t), world(source.world) {
}
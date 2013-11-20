#include <iostream>
#include "vector.hpp"
#include "color.hpp"
#include "source.hpp"



source::source(rt::vector origin, rt::color color, double intensity) {
	_origin = origin;
	_color = color;
	_intensity = intensity;
}
		
source::source(rt::vector origin) {
	_origin = origin;
	_color = rt::color::WHITE;
	_intensity = 1.0;
}

rt::vector source::get_origin() {
	return _origin;
}

rt::color source::get_color() {
	return _color;
}

double source::get_intensity() {
	return _intensity;
}


void source::set_origin(rt::vector origin) {
	_origin = origin;
}

void source::set_color(rt::color color) {
	_color = color;
}

void source::set_intensity(double intensity) {
	_intensity = intensity;
}



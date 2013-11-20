#include "scene.hpp"

#include "vector.hpp"
#include "camera.hpp"
#include "object.hpp"

#include <iostream>
#include <vector>

void scene::add_source(source source) {
	_sources.push_back(source);
}

void scene::add_object(object object) {
	_objects.push_back(object);
}

int scene::nb_sources() {
	return _sources.size();
}

int scene::nb_objects() {
	return _objects.size();
}

source scene::get_source(int i) {
	return _sources[i];
}

object scene::get_object(int i) {
	return _objects[i];
}

bool scene::empty_object() {
	return _objects.empty();
}



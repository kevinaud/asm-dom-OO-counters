#include "./component.hpp"

void Component::updateView() {
    parent->updateView(); 
}

// child management
void Component::add(Component*) { };
void Component::remove(Component*) { };
Component* Component::getChild(int) { return NULL; }

int Component::numChildren() {
    return 0; 
}

Children Component::renderChildren() {
    return vector<VNode*>();
}

void Component::log(int i) {
    emscripten::val::global("console").call<void>("log", emscripten::val(i));
}

void Component::log(string s) {
    emscripten::val::global("console").call<void>("log", emscripten::val(s));
}

void Component::log(emscripten::val v) {
    emscripten::val::global("console").call<void>("log", v);
}

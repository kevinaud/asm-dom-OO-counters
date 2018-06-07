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

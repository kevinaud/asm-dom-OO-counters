#include "./composite-component.hpp"

int CompositeComponent::numChildren() {
    return children.size(); 
}

void CompositeComponent::add(Component* child) {
    children.push_back(child);
}

void CompositeComponent::remove(Component* child) {
    for (int i = 0; i < numChildren(); i++) {
        if (getChild(i) == child) {
            children.erase(children.begin() + i); 
        } 
    }
}

Children CompositeComponent::renderChildren() {
    Children renderedChildren;

    for (int i = 0; i < children.size(); i++) {
        renderedChildren.push_back(children[i]->render());
    }
    return renderedChildren;
}

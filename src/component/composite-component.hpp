#ifndef COMPOSITE_COMPONENT_H 
#define COMPOSITE_COMPONENT_H

#include <vector>
#include "./component.hpp"

class CompositeComponent : public Component {

    public:
        CompositeComponent(Component* parent) : Component(parent) {}

        virtual int numChildren();
        virtual void add(Component* child);

        virtual void remove(Component* child);

    protected:
        vector<Component*> children;

        virtual Children renderChildren();

};

#endif

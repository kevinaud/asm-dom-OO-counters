#ifndef COMPONENT_H
#define COMPONENT_H

#include "../../../node_modules/asm-dom/cpp/asm-dom.hpp"

using namespace asmdom;
using namespace std;

class Component {
    public:
        Component(Component* parent) : parent(parent) {};

        virtual VNode* render() = 0;
        virtual void updateView();

        // child management
        virtual void add(Component*);
        virtual void remove(Component*);
        virtual Component* getChild(int);
        virtual int numChildren();

    protected:
        Component* parent;

        virtual Children renderChildren();
};


#endif

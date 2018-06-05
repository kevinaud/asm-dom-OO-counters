#ifndef WIDGET_H
#define WIDGET_H

#include "../../node_modules/asm-dom/cpp/asm-dom.hpp"

class Widget {
    public:
        Widget(Widget* parent) : parent(parent) {};
        virtual asmdom::VNode* render() = 0;

        virtual void updateView() {
            parent->updateView(); 
        }

    protected:
        Widget* parent;

};

#endif

#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include "../widget/widget.hpp"

class Button : public Widget {

    public:
        Button(
            Widget* parent,
            std::string label,
            std::function<void()> handler
        );

        void setClickHandler(std::function<void()> handler);
        asmdom::VNode* render();

    private:
        std::string label;
        std::function<void()> handler;
};


#endif

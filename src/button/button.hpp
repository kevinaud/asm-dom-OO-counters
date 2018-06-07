#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include "../component/component.hpp"

class Button : public Component {

    public:
        Button(
            Component* parent,
            string label,
            function<void()> handler
        );

        void setClickHandler(function<void()> handler);
        VNode* render();

    private:
        string label;
        function<void()> handler;
};


#endif

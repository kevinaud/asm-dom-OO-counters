#ifndef INPUT_H
#define INPUT_H

#include "../../component/component.hpp"
#include "../../view-property/view-property.hpp"

class Input : public Component {

    public:
        Input(Component* parent);
        Input(Component* parent, string initValue);
        VNode* render();

    private:
        ViewProperty<string>* value;
};

#endif

#ifndef COUNTER_H
#define COUNTER_H

#include "../component/component.hpp"

class Counter : public Component {

    public:
        Counter(Component* parent, int initValue);
        VNode* render();

    private:
        int count;

        void decrease();
        void increase();
};


#endif

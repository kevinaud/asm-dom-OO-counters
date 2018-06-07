#ifndef COUNTER_H
#define COUNTER_H

#include "../framework/framework.hpp"

class Counter : public Component {

    public:
        Counter(Component* parent, int initValue);
        VNode* render();

    private:
        ViewProperty<int>* count;

        void decrease();
        void increase();
};


#endif

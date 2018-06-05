#ifndef COUNTER_H
#define COUNTER_H

#include "../widget/widget.hpp"

class Counter : public Widget {

    public:
        Counter(Widget* parent, int initValue);
        asmdom::VNode* render();

    private:
        int count;

        void decrease();
        void increase();
};


#endif

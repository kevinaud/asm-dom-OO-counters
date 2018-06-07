#ifndef APP_H
#define APP_H

#include <vector>
#include "../component/composite-component.hpp"

class App : public CompositeComponent {
    public:
        App() : CompositeComponent(NULL) {};

        void init();
        VNode* render();

        void updateView();
    private:
        VNode* current_view = NULL;
};


#endif

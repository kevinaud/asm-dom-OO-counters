#ifndef APP_H
#define APP_H

#include <vector>
#include "../widget/widget.hpp"

class App : public Widget {
    public:
        App();

        void init();
        asmdom::VNode* render();
        void addChild(Widget*);

        void updateView();
    private:
        asmdom::VNode* current_view = NULL;
        std::vector<Widget*> children;
};


#endif

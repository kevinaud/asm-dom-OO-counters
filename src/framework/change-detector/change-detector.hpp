#ifndef CHANGE_DETECTOR_H
#define CHANGE_DETECTOR_H

#include "../component/component.hpp"

// Singleton
class ChangeDetector {
   
    public:
        static ChangeDetector* Instance();

        void viewChanged();
        void notify(Component* listener);

    //protected:
        static ChangeDetector* instance;
        Component* listener = NULL;

        ChangeDetector();

};

#endif

#include "./change-detector.hpp"

ChangeDetector* ChangeDetector::instance = 0;

ChangeDetector::ChangeDetector() {

}

ChangeDetector* ChangeDetector::Instance() {
    if (instance == 0) {
        instance = new ChangeDetector();
    }
    return instance;

}

void ChangeDetector::viewChanged() {
    if (listener) {
        listener->updateView();  
    }
}

void ChangeDetector::notify(Component* listener) {
    this->listener = listener;
}

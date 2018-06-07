#ifndef VIEW_PROPERTY_H
#define VIEW_PROPERTY_H

#include "../change-detector/change-detector.hpp"

template<typename T>
class ViewProperty {
    public:
        ViewProperty() : data() {
            changeDetector = ChangeDetector::Instance();
        }

        ViewProperty<T>& operator=(const T& newvalue) {
            this->data = newvalue;
            this->changeDetector->viewChanged();

            return *this;
        }

        /* ViewProperty& operator--(const T); */
        /* ViewProperty& operator++(const T); */

        void test();

        operator T() const {
            return data; 
        };

        void set(T newValue) {
            data = newValue;
        }

        T getVal() {
            return data; 
        }

    /* private: */
        T data;
        ChangeDetector* changeDetector;
};

#endif

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

        ViewProperty<T>& operator=(const emscripten::val& newvalue) {
            this->data = newvalue.as<T>();
            this->changeDetector->viewChanged();

            return *this;
        }

        /* ViewProperty& operator--(const T); */
        /* ViewProperty& operator++(const T); */

        operator T() const {
            return data; 
        };

        function<bool (emscripten::val)> bind() {
            return [this](emscripten::val e) -> bool {
                *this = e;
                return true;
            };
        }

        function<bool (emscripten::val)> bind(
            function<emscripten::val (emscripten::val)> resolver
        ) {
            return [this, resolver](emscripten::val e) -> bool {
                *this = resolver(e);
                return true;
            };
        }

    private:
        T data;
        ChangeDetector* changeDetector;
};

#endif

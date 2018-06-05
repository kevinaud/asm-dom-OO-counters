#include "counter.hpp"

Counter::Counter(Widget* parent, int initValue) : Widget(parent) {
    count = initValue;
}

asmdom::VNode* Counter::render() {

    return (
        <div>
            <a class="button" onclick={[this](emscripten::val e) -> bool {
                this->decrease(); 
                updateView();
                return true;
            }}>
               - 
            </a>

            <span>{{ std::to_string(this->count) }}</span>

            <a class="button" onclick={[this](emscripten::val e) -> bool {
                this->increase(); 
                updateView();
                return true;
            }}>
               +
            </a>
        </div>
    );

}

void Counter::decrease() {
    count--;
}

void Counter::increase() {
    count++;
}

#include "counter.hpp"

Counter::Counter(Component* parent, int initValue) : Component(parent) {
    count = new ViewProperty<int>();
    *count = initValue;
}

VNode* Counter::render() {

    return (
        <div>
            <a class="button" onclick={[this](emscripten::val e) -> bool {
                this->decrease(); 
                return true;
            }}>
               - 
            </a>

            <span>{{ to_string(*count) }}</span>


            <a class="button" onclick={[this](emscripten::val e) -> bool {
                this->increase(); 
                return true;
            }}>
               +
            </a>
        </div>
    );

}

void Counter::decrease() {
    *count = *count - 1;
}

void Counter::increase() {
    *count = *count + 1;
}

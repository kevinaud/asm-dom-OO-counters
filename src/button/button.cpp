#include "button.hpp"


Button::Button(
    Component* parent,
    string label,
    function<void()> handler
) : Component(parent), label(label), handler(handler) { }

void Button::setClickHandler(function<void()> handler) {
    this->handler = handler;
}

VNode* Button::render() {
    return (
        <button onclick={[this](emscripten::val e) -> bool {
            this->handler(); 
            updateView();
            return true;
        }}>
            {{ label }}
        </button>
    );
}

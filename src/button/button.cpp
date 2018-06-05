#include "button.hpp"


Button::Button(
    Widget* parent,
    std::string label,
    std::function<void()> handler
) : Widget(parent), label(label), handler(handler) { }

void Button::setClickHandler(std::function<void()> handler) {
    this->handler = handler;
}

asmdom::VNode* Button::render() {
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

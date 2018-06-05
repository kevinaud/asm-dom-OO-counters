#include "app.hpp"

App::App() : Widget(NULL) { }

void App::init() {
    current_view = <div class="root" />;
    asmdom::patch(
        emscripten::val::global("document").call<emscripten::val>(
            "getElementById",
            std::string("root")
        ),
        current_view
    );
}

asmdom::VNode* App::render() {

    std::vector<asmdom::VNode*> renderedChildren;

    for (int i = 0; i < children.size(); i++) {
        renderedChildren.push_back(children[i]->render());
    }

    return (
        <div class="root">

            {...renderedChildren}

            <div style="
                position: absolute;
                bottom: 8px;
                font-size: 12px;">
            asm-dom-boilerplate
            </div>
        </div>
    );
}

void App::addChild(Widget* child) {
    children.push_back(child);
}

void App::updateView() {
    asmdom::VNode* new_node = render();
    current_view = asmdom::patch(current_view, new_node);
}

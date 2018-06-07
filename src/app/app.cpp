#include "app.hpp"

//App::App() { }

void App::init() {
    current_view = <div class="root" />;
    patch(
        emscripten::val::global("document").call<emscripten::val>(
            "getElementById",
            string("root")
        ),
        current_view
    );
}

VNode* App::render() {

    //emscripten::val::global("console").call<void>("log", emscripten::val("added"));
    vector<VNode*> renderedChildren;

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


void App::updateView() {
    VNode* new_node = render();
    current_view = patch(current_view, new_node);
}

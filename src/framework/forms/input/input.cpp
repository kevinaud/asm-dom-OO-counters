#include "input.hpp"

Input::Input(Component* parent) : Input(parent, "") { }

Input::Input(Component* parent, string initValue) : Component(parent) {
    value = new ViewProperty<string>();
    *value = initValue;
}

VNode* Input::render() {

    return (
        <div>

            <input type="text" oninput={ value->bind([](emscripten::val e) {
                return e["target"]["value"];      
            })}/><br/>

            <span>{{ *value }}</span><br/>

        </div>
    );

}

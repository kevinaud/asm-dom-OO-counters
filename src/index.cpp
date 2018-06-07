#include <emscripten/val.h>
#include <functional>
#include <string>
#include "../node_modules/asm-dom/cpp/asm-dom.hpp"

// FRAMEWORK
#include "./framework/framework.hpp"

// APPLICATION HEADERS
//#include "./app/app.hpp"
#include "./counter/counter.hpp"
#include "./button/button.hpp"
//#include "./framework/input/input.hpp"
//#include "./change-detector/change-detector.hpp"

using namespace asmdom;

App* buildApp();

int main() {
    asmdom::Config config;
    asmdom::init(config);

    App* app = buildApp();
    app->updateView();

    return 0;
};

App* buildApp() {

    // create and initialize app
    App* app = new App();
    app->init();

    // register app with change detector
    // *MUST BE DONE AFTER App->init()
    ChangeDetector::Instance()->notify(app);

    Button* counterBtn = new Button(app, std::string("add counter"), [app] {
        app->add(new Counter(app, 0));
    });

    Input* input = new Input(app);

    app->add(counterBtn);
    app->add(input);

    return app;
}

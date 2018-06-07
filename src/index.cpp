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
    App* app = new App();
    ChangeDetector::Instance()->notify(app);

    Button* counterBtn = new Button(app, std::string("add counter"), [app] {
        app->add(new Counter(app, 0));
    });

    app->init();
    app->add(counterBtn);

    return app;
}

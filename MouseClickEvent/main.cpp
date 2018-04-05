#include <iostream>
#include <emscripten/val.h>
#include <emscripten.h>
#include <emscripten/html5.h>

using namespace emscripten;

int main() {
    val document = val::global("document");
    val h1 = document.call<val>("querySelector", std::string("h1"));
    h1.set("innerHTML", "Hello Wasm");

    val btn = document.call<val>("querySelector", val("button"));
    btn.set("innerHTML", "Click me");

    emscripten_set_click_callback("btn", nullptr, 0,
                                  [](int eventType, const EmscriptenMouseEvent *mouseEvent, void *userData) {
                                      EM_ASM(alert("按钮被点击了"));
                                      return 0;
                                  });
    return 0;
}
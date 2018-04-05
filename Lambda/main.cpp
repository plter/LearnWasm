#include <iostream>
#include <emscripten/val.h>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(my_module) {
    function("btn_clicked", (void (*)(const val &)) ([](const val &e) {
        EM_ASM(alert("OK"));
    }));
}

int main() {
    val hello = val::global("Function").new_(std::string("console.log('Hello JavaScript')"));
    hello.call<void>("call");

    val btn = val::global("document").call<val>("querySelector", std::string("button"));
    btn.set("innerHTML", std::string("Click me to show alert"));
    btn.set("onclick", val::global("Function").new_(val("e"), val("Module.btn_clicked(e)")));
    return 0;
}
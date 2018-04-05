#include <iostream>
#include <emscripten/val.h>
#include <emscripten.h>
#include <emscripten/bind.h>

using namespace emscripten;

void btn_clicked(const val &v) {
    std::cout << v["type"].as<std::string>() << std::endl;
    EM_ASM(alert("你好，小云"));
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("btn_clicked", &btn_clicked);
}

int main() {
    val hello = val::global("Function").new_(std::string("console.log('Hello JavaScript')"));
    hello.call<void>("call");

    val btn = val::global("document").call<val>("querySelector", std::string("button"));
    btn.set("innerHTML", std::string("Click me to show alert"));
    btn.set("onclick", val::global("Function").new_(val("e"), val("Module.btn_clicked(e)")));
    return 0;
}
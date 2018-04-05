#include <iostream>
#include <emscripten/bind.h>
#include <emscripten.h>

using namespace emscripten;


void sayHello(const std::string &name) {
    std::cout << "Hello " << name << std::endl;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("sayHello", &sayHello);
}

int main() {
    EM_ASM(
            Module.sayHello("ZhangSan");
    );
    return 0;
}
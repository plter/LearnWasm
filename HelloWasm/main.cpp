#include <iostream>
#include <emscripten/val.h>

using namespace emscripten;

int main() {
    val document = val::global("document");
    document["body"].set("innerHTML", "Hello World");
    return 0;
}
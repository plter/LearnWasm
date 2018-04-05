emcc main.cpp -s WASM=1 -o out/HelloWasm.js -std=c++11 -Wall --bind
cp index.html out
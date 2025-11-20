import std;

import ilua;

int main() {
    auto lua = ilua::LuaVM::create();

    lua.set_function("cpp_print", []() {
        std::println("c++: this call from lua...");
        return 0;
    });

    lua.set_function("hello_world", []() {
        std::println("c++: hello_world...");
        return 0;
    });

    lua.run("cpp_print()");
    lua.script("test.lua");
    lua.run("fk()");

    auto add = lua.set_function("add", [](int a, int b) {
        static int i = 0; i++;
        return a + b + i;
    });

    lua.run("print('lua: a + b =', add(1, 2))");

    std::println("c++: a + b = {}", add(1, 2));

}

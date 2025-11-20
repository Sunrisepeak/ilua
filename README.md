# ilua

`import ilua` in modern c++

## Example

```cpp
import std;

import ilua;

int main() {
    auto lua = ilua::LuaVM::create();

    lua.set_function("say_hi", []() {
        std::println("say_hi from lua...");
    });

    lua.run("say_hi()");

    auto add = lua.set_function("add", [](int a, int b) {
        static int i = 0;
        return a + b + i;
    });

    // call add function in lua
    lua.run("print('lua: a + b =', add(1, 2))");

    // call add function in c++
    std::println("c++: a + b = {}", add(1, 2));
}
```

## Build

```bash
xlings install # install gcc15
xmake
```
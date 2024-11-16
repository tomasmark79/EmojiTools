# Emoji Tools 😉🪄🎯

#### How to implement
This project is compatible with Setup-free [CMake dependency management](https://github.com/cpm-cmake/CPM.cmake)).

#### add CPM.cmake snippet

```cmake
# git@github.com:tomasmark79/EmojiTools.git
CPMAddPackage(
  NAME EmojiTools
  GIT_TAG main
  GITHUB_REPOSITORY tomasmark79/EmojiTools
  OPTIONS "EMOJI_INSTALL YES" # create an installable target
)
```

#### add link dependencies

```cmake
# Link dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt EmojiTools::EmojiTools)
```

#### add C++ header

``` cpp
#include <emoji/EmojiWrapper.hpp>
```

#### use library in C++

```cpp
Emoji emoji;
std::cout << emoji.getEmojiStringCharByCodePoint(U"1F600", 1) << std::endl;
```
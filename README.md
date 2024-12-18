Emoji Tools 😉🪄🎯

This repository provides a simple library that facilitates working with emoji characters. It allows for proper code processing and transforms them into emojis. Alternatively, it can simply return a random smiley or a list of emoji names. 

This project is a library CMake compatible
```cmake
# EmojiTools
CPMAddPackage(
    NAME EmojiToolsLib
    GIT_TAG main
    GITHUB_REPOSITORY tomasmark79/EmojiTools
    OPTIONS "EMOJI_INSTALL NO" # create an installable target
)
if(EmojiToolsLib_ADDED)
    target_link_libraries(${PROJECT_LIBRARY_NAME} PRIVATE name.digitalspace.www::EmojiToolsLib)
endif()
```

#### Implementation
 
 ```cpp
#include <EmojiToolsLib/EmojiToolsLib.hpp>

auto main(int argc, char **argv) -> int
{
    EmojiToolsLib /*💋*/ emojiTools;
    std::string emoji;

    std::cout << "Version: " << EMOJITOOLSLIB_VERSION << " " << emojiTools.getRandomEmoji(emoji)
              << std::endl;

    return 0;

    // library interface
    std::string getEmojiStringCharByCodePoint(char32_t *emojiCodePoints, size_t length)
    char8_t getEmojiChar8_tCharByCodePoint(char32_t *emojiCodePoints, size_t length)
    std::string &getRandomEmoji(std::string &randomEmoji)
    std::string getRandomEmojiFromGroup(const std::string emojiGroup)
    std::string getRandomEmojiFromSubGroup(const std::string emojiSubGroup)
    std::string getAllEmojiesFromGroup(const std::string emojiGroup)
    std::string getAllEmojiesFromSubGroup(const std::string emojiSubGroup)
    std::vector<std::string> getEmojiGroups()
    std::vector<std::string> getEmojiSubGroups()
    int getSizeOfGroupItems(const std::string emojiGroup)
    int getSizeOfSubGroupItems(const std::string emojiSubGroup)
    std::string getEmojiStringByIndexFromGroup(const std::string emojiGroup, const int index)
    std::string getEmojiStringByIndexFromSubGroup(const std::string emojiSubGroup, const int index)
    std::string getEmojiGroupDescription(const std::string emojiGroup)
    std::string getEmojiSubGroupDescription(const std::string)
}

```

---

notice 👇
Below you can also find the documentation for the template from which this project is made. I leave this documentation attached for completeness.

# MarkWare VCMake Template 🎁
v1.1.0rc2 

---

### Project Overview

- Another C++ template based on a modern structured foundation.
- This template incorporates the best ideas from environments like **VSCode**, **Modern CMake**, **CPM**, **ModernCppStarter**, and **C/C++**.
- It serves as a CMake wrapper replacement for the official CMake extension, which did not meet my specific needs.

#### The Fact

With this project and its settings, you can start developing in C++ within a few seconds.

### This C++ Template Project Consists of Two Parts:

- A C++ library
- A C++ standalone application that links with the library
  
### Implemented Features 

✅ - VSCode tasks for comfort  
✅ - VSCode key bindings template  
✅ - VSCode C/C++ debugger launcher  
✅ - Project renamer is awesome  
✅ - Debug - **F5**  
✅ - Interactive menu selection for all CMake tasks - **F7**  
✅ - Configure  
✅ - Cross Compile  
✅ - Clean  
✅ - Install  
✅ - Collect licenses **generating third_party.txt**  
✅ - C/C++ Lint - **ctrl+alt+l**  
✅ - C/C++ format (clang) - **ctrl+alt+m**  
✅ - CMake format - **ctrl+alt+f**

### TODO

- port to Windows, Mac
- some tests, sanitizing, ...

---

### Code Codex

I am using 🐫amel🐫ode🐫apitals.  
One exception: No capital letter in the "include" folder is intentional!

### Quick Start

```bash
sudo apt-get update
sudo apt-get install build-essential cmake -y
git clone https://github.com/tomasmark79/MarkWareVCMake
cd MarkWareVCMake/
code .
```

#### Rename your Library and Standalone in seconds

```bash
./TemplateRenamer.sh <old_lib_name> <new_lib_name> <old_standalone_name> <new_standalone_name>
```

---

### Template Parts Explanation

#### `.vscode/c_cpp_properties.json`

CPM is able to use cache. The path to the cache folder is stored here.

#### `.vscode/tasks.json` and `CMakeConfigure.sh`

Both files are used to smoothly glue CMake and VSCode. The result is a light and robust mechanism for controlling all CMake tasks.

#### `.vscode/launch.json`

It is the debugger definition. Thanks to predictability, it is defined out of the box. ;-)

#### `.vscode/keybindings.json`

My own keybindings. If you want to use them, you need to copy/paste the content to your user settings in `~/.config/Code/${user}/keybindings.json`.

---

### Thank You 

*To all the awesome people who share the same mindset as me* 🙏

### Thank to those

Use those links to get more documentation to used technologies in my template.

https://cmake.org

https://github.com/TheLartians/ModernCppStarter

https://github.com/cpm-cmake/CPM.cmake

https://github.com/cpm-cmake/CPMLicenses.cmake.git


---

### About Me 👨‍💻

"The result of a lot of hours of incredible fun. Time seemed to stand still. The outcome is a template that takes C++ development to a whole new level. 
    
"Buy me a coffee ☕🍵 or spare some time. 🙂"

```
paypal.me/TomasMark
Bitcoin: 3JMZR6SQo65kLAxxxXKrVE7nBKrixbPgSZ
Ethereum: 0x7a6C564004EdecFf8DD9EAd8bD4Bbc5D2720BeE7
```

I look forward to seeing your contributions!

### License
I built the project primarily for myself and for my future projects. Nevertheless, if we use the project, we should adhere to the licensing policy. Therefore, I have implemented the package `CPMLicenses.cmake`, which automatically scans all source directories of your CPM.cmake dependencies and finds any file that starts with LICENSE or LICENCE, appending the content to an output file that you can use as a license disclaimer. If no license is found for a package, a warning will be issued in the output during license collection.


Copyright (c) Tomáš Mark 2024 




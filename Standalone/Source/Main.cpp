#include <EmojiToolsLib/EmojiToolsLib.hpp>
#include <emojitoolslib/version.h>
#include <iostream>

// Standalone applications are the ones that are not part of a library
// (c) Tomáš Mark 2024

auto main(int argc, char **argv) -> int
{
    EmojiToolsLib Lib;
    std::cout << "Version: " << EMOJITOOLSLIB_VERSION << std::endl;

    return 0;
}
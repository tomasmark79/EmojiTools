#include <EmojiToolsLib/EmojiToolsLib.hpp>
#include <emojitoolslib/version.h>
#include <iostream>

// Standalone applications are the ones that are not part of a library
// (c) Tomáš Mark 2024

auto main(int argc, char **argv) -> int
{
    EmojiToolsLib /*💋*/ emojiTools;
    std::string emoji;

    std::cout << "Version: " << EMOJITOOLSLIB_VERSION << " " << emojiTools.getRandomEmoji(emoji)
              << std::endl;

    return 0;
}
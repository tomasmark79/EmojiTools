#include "EmojiTools/EmojiTools.hpp"

#include <EmojiTools/EmojiTools.hpp>
#include <iostream>
#include <emojitools/version.h>

// Library implementation

EmojiTools::EmojiTools()
{
    std::cout << "--- EmojiTools v." << EMOJITOOLS_VERSION << " instantiated ---"
              << std::endl;
}

EmojiTools::~EmojiTools()
{
    std::cout << "--- EmojiTools uninstantiated ---" << std::endl;
}

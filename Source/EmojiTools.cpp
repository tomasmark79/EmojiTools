#include "EmojiTools/EmojiTools.hpp"

#include <EmojiTools/EmojiTools.hpp>
#include <emojitools/version.h>
#include <iostream>

// Library implementation

EmojiTools::EmojiTools()
{
    std::cout << "--- EmojiTools v." << EMOJITOOLS_VERSION
              << " instantiated ---" << std::endl;
}

EmojiTools::~EmojiTools()
{
    std::cout << "--- EmojiTools uninstantiated ---" << std::endl;
}

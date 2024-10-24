#include "Emoji.hpp" // wrapper class for EmojiParser namespace
#include <iostream>

int main()
{
    // HOW TO USE EmojiWrapper
    
    Emoji /*💋*/ emojiWrapper;

    // get emoji by codepoints

    std::cout << "get 😀 = "
              << emojiWrapper.getEmojiByCodePoint((char32_t *)U"\U0001F600", 1)
              << std::endl;

    std::cout << "get 😶‍🌫️ = "
              << emojiWrapper.getEmojiByCodePoint((char32_t *)U"\U0001F636\U0000200D\U0001F32B\U0000FE0F", 4)
              << std::endl;

    // get all emojis from group or subgroup

    std::cout << "get all from Flags = "
              << emojiWrapper.getAllEmojiesFromGroup("Flags").substr(0, 32)
              << std::endl;

    std::cout << "get all from face-smiling = "
              << emojiWrapper.getAllEmojiesFromSubGroup("country-flag").substr(0, 32)
              << std::endl;

    // get random emoji from group or subgroup

    std::cout << emojiWrapper.getRandomEmojiFromGroup("Smileys & Emotion") << std::endl;
    std::cout << emojiWrapper.getRandomEmojiFromSubGroup("face-smiling") << std::endl;

    return 0;
}

// MIT License
//
// Copyright (c) 2024 Tomas Mark

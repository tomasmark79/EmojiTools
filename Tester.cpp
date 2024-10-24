#include "Emoji.hpp" // wrapper class for EmojiParser namespace
#include <iostream>
#include <vector>

int main()
{
    // HOW TO USE EmojiWrapper

    Emoji /*💋*/ emojiWrapper;

    // get emoji by codepoints

    // char32_t emojiCodePoint[1] = {0x1F600}; // 😀
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

    // get list of names of emoji groups and subgroups
    std::vector<std::string> emojiGroups = emojiWrapper.getEmojiGroups();
        std::cout << "Emoji groups: " << emojiGroups.size() << std::endl;
    std::vector<std::string> emojiSubGroups = emojiWrapper.getEmojiSubGroups();
        std::cout << "Emoji sub-groups: " << emojiSubGroups.size() << std::endl;

    // get number of items in a emoji group or subgroup
    std::cout << "Number of items in group Smileys & Emotion = "
              << emojiWrapper.getSizeOfGroupItems("Smileys & Emotion")
              << std::endl;
    
    std::cout << "Number of items in subgroup face-smiling = "
                << emojiWrapper.getSizeOfSubGroupItems("face-smiling")
                << std::endl;














    return 0;
}

// MIT License
//
// Copyright (c) 2024 Tomas Mark

#include "Emoji.hpp" // wrapper class for EmojiParser namespace

#include <iostream>


int main() 
{
    Emoji /*💋*/ emojiWrapper;
    std::cout << emojiWrapper.getRandomEmojiFromGroup("Smileys & Emotion");
    std::cout << emojiWrapper.getRandomEmojiFromSubGroup("face-smiling");

        
    return 0;
   
}

// MIT License
//
// Copyright (c) 2024 Tomas Mark

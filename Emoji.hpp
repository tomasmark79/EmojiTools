// wrapper class for EmojiParser namespace
// wrapper is defined to be stable as possible

#pragma once
#include "EmojiTools.hpp"

class Emoji 
{
public:
    Emoji() {};
    ~Emoji() {};


    std::string getRandomEmojiFromGroup(const std::string emojiGroup)
    {
        return emojiTools.getRandomEmojiFromGroup(emojiGroup);
    }
    std::string getRandomEmojiFromSubGroup(const std::string emojiSubGroup)
    {
        return emojiTools.getRandomEmojiFromSubGroup(emojiSubGroup);
    }


private:
    EmojiParser::EmojiTools emojiTools;
};

// wrapper class for EmojiParser namespace
// wrapper is defined to be stable as possible

#pragma once
#include "EmojiTools.hpp"

class Emoji 
{
public:
    Emoji() {};
    ~Emoji() {};

    std::string getEmojiByCodePoint(char32_t *emojiCodePoints, size_t length)
    {
        return emojiTools.getEmojiCodePoint(emojiCodePoints, length);
    }
    std::string getRandomEmojiFromGroup(const std::string emojiGroup)
    {
        return emojiTools.getRandomEmojiFromGroup(emojiGroup);
    }
    std::string getRandomEmojiFromSubGroup(const std::string emojiSubGroup)
    {
        return emojiTools.getRandomEmojiFromSubGroup(emojiSubGroup);
    }
    std::string getAllEmojiesFromGroup(const std::string emojiGroup)
    {
        return emojiTools.getEmojiesFromGroup(emojiGroup);
    }
    std::string getAllEmojiesFromSubGroup(const std::string emojiSubGroup)
    {
        return emojiTools.getEmojiesFromSubGroup(emojiSubGroup);
    }

private:
    EmojiParser::EmojiTools emojiTools;
};

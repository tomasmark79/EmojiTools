// wrapper class for EmojiParser namespace
// wrapper is defined to be stable as possible

#pragma once
#include "EmojiTools.hpp"

class Emoji 
{
public:
    Emoji() {};
    ~Emoji() {};

    // get emoji std::string character by codepoint or codepoints
    std::string getEmojiStringCharByCodePoint(char32_t *emojiCodePoints, size_t length)
    {
        return et.getEmojiStringCharByCodePoint(emojiCodePoints, length);
    }

    // get emoji char8_t character by codepoint or codepoints
    char8_t getEmojiChar8_tCharByCodePoint(char32_t *emojiCodePoints, size_t length)
    {
        return et.getEmojiChar8_tCharByCodePoint(emojiCodePoints, length);
    }

    // get random emoji contained in a group
    std::string getRandomEmojiFromGroup(const std::string emojiGroup)
    {
        return et.getRandomEmojiFromGroup(emojiGroup);
    }

    // get random emoji contained in a subgroup
    std::string getRandomEmojiFromSubGroup(const std::string emojiSubGroup)
    {
        return et.getRandomEmojiFromSubGroup(emojiSubGroup);
    }

    // get all emoji chars contained in a group
    std::string getAllEmojiesFromGroup(const std::string emojiGroup)
    {
        return et.getEmojiesFromGroup(emojiGroup);
    }

    // get all emoji chars contained in a subgroup
    std::string getAllEmojiesFromSubGroup(const std::string emojiSubGroup)
    {
        return et.getEmojiesFromSubGroup(emojiSubGroup);
    }

    // get the vector containing names of emoji groups
    // vector.size() to retrieve the number of groups
    std::vector<std::string> getEmojiGroups()
    {
        return et.getEmojiGroupsNames();
    }

    // get the vector containing names of emoji subgroups
    // vector.size() to retrieve the number of subgroups
    std::vector<std::string> getEmojiSubGroups()
    {
        return et.getEmojiSubGroupsNames();
    }
    
    // get number of items in a group
    int getSizeOfGroupItems(const std::string emojiGroup)
    {
        return et.getSizeOfGroupItems(emojiGroup);
    }

    // get number of items in a subgroup
    int getSizeOfSubGroupItems(const std::string emojiSubGroup)
    {
        return et.getSizeOfSubGroupItems(emojiSubGroup);
    }






private:
    EmojiTransmitter et;
};

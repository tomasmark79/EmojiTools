// wrapper class for EmojiParser namespace
// wrapper is defined to be stable as possible

#pragma once
#include "EmojiTools.hpp"

class Emoji 
{
public:
    Emoji() {};
    ~Emoji() {};

    // get emoji character by codepoint or codepoints
    std::string getEmojiByCodePoint(char32_t *emojiCodePoints, size_t length)
    {
        return emojiTools.getEmojiByCodePoint(emojiCodePoints, length);
    }

    // get random emoji contained in a group
    std::string getRandomEmojiFromGroup(const std::string emojiGroup)
    {
        return emojiTools.getRandomEmojiFromGroup(emojiGroup);
    }

    // get random emoji contained in a subgroup
    std::string getRandomEmojiFromSubGroup(const std::string emojiSubGroup)
    {
        return emojiTools.getRandomEmojiFromSubGroup(emojiSubGroup);
    }

    // get all emoji chars contained in a group
    std::string getAllEmojiesFromGroup(const std::string emojiGroup)
    {
        return emojiTools.getEmojiesFromGroup(emojiGroup);
    }

    // get all emoji chars contained in a subgroup
    std::string getAllEmojiesFromSubGroup(const std::string emojiSubGroup)
    {
        return emojiTools.getEmojiesFromSubGroup(emojiSubGroup);
    }

    // get the vector containing names of emoji groups
    // vector.size() to retrieve the number of groups
    std::vector<std::string> getEmojiGroups()
    {
        return emojiTools.getEmojiGroupsNames();
    }

    // get the vector containing names of emoji subgroups
    // vector.size() to retrieve the number of subgroups
    std::vector<std::string> getEmojiSubGroups()
    {
        return emojiTools.getEmojiSubGroupsNames();
    }
    
    // get number of items in a group
    int getSizeOfGroupItems(const std::string emojiGroup)
    {
        return emojiTools.getSizeOfGroupItems(emojiGroup);
    }

    // get number of items in a subgroup
    int getSizeOfSubGroupItems(const std::string emojiSubGroup)
    {
        return emojiTools.getSizeOfSubGroupItems(emojiSubGroup);
    }






private:
    EmojiParser::EmojiTools emojiTools;
};

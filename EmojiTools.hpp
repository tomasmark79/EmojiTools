// include/EmojiTools.hpp
#ifndef __EMOJITOOLS_H__
#define __EMOJITOOLS_H__

#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <assert.h>

#if __cplusplus < 202002L
using char8_t = char; // C++17 and older
#endif

#ifndef size_t
using size_t = decltype(sizeof(0));
#endif

namespace Utf8Tools
{
    class Utf8Tools
    {
    public:
        /// @brief encode a UTF-8 code point
        /// @param emojiCodePoint
        /// @param buffer8
        /// @return char8_t*
        char8_t *encodeUtf8(char32_t emojiCodePoint, char8_t *buffer8);

        /// @brief encode a sequence of UTF-8 code points
        /// @param emojiCodePoints
        /// @param length
        /// @param buffer8
        /// @return char8_t*
        char8_t *encodeUtf8Sequence(const char32_t *emojiCodePoints, size_t length, char8_t *buffer8);
    };

} // namespace Utf8Tools

namespace EmojiParser
{
    class EmojiTools
    {
    public:
        /// @brief Construct a new EmojiTools object
        EmojiTools();

    private:
        bool m_isPopulated{false};
        struct EmojiPropertiesStructure
        {
            std::vector<char32_t> m_emojiCodePoints;
            std::string m_emojiGroup;
            std::string m_emojiSubGroup;
            std::string m_emojiUnicodeVersion;
            std::string m_emojiTextDescription;
        };

        std::map<int, EmojiPropertiesStructure> m_emojiPropertiesMap;

        void constructEmojiPropertiesMap(std::map<int, EmojiPropertiesStructure> &epm, std::istream &file);

        std::istringstream loadEmojiAssetsFromHardcodedHeader();
        std::ifstream loadEmojiAssetsFromFile();

    public:
        // get emoji character by codepoint or codepoints
        std::string getEmojiByCodePoint(char32_t *emojiCodePoints, size_t length);
        // get random emoji contained in a group
        std::string getRandomEmojiFromGroup(std::string emojiGroup);
        // get random emoji contained in a subgroup
        std::string getRandomEmojiFromSubGroup(std::string emojiSubGroup);
        // get all emoji chars contained in a group
        std::string getEmojiesFromGroup(std::string emojiGroup);
        // get all emoji chars contained in a subgroup
        std::string getEmojiesFromSubGroup(std::string emojiSubGroup);
        // get the vector containing names of emoji groups
        std::vector<std::string> getEmojiGroupsNames();
        // get the vector containing names of emoji subgroups
        std::vector<std::string> getEmojiSubGroupsNames();
        // get number of items in a group
        int getSizeOfGroupItems(std::string emojiGroup);
        // get number of items in a subgroup
        int getSizeOfSubGroupItems(std::string emojiSubGroup);

        // TODO
        // Get emoji by name
        // Get emoji by description
        // Get emoji by unicode version

        std::string getEmojiByIndexFromGroup(std::string emojiGroup, int index);
        std::string getEmojiByIndexFromSubGroup(std::string emojiSubGroup, int index);

        void printEmojiCodePointChar32_t(char32_t *emojiCodePoints, size_t length);
        void printEmojiGroupWDescription(std::string emojiGroup);
        void printEmojiGroup(std::string emojiGroup);
        void printEmojiSubGroupWDescription(std::string emojiSubGroup);
        void printEmojiSubGroup(std::string emojiSubGroup);

        void printGroupsText();
        void printSubGroupsText();
        void printEmojiDescription(std::string emojiDescription);

        void TEST();
    };
} // namespace EmojiTools

#endif // __EMOJITOOLS_H__

// MIT License
//
// Copyright (c) 2024 Tomas Mark

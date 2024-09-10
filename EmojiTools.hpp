// include/EmojiTools.hpp
#ifndef __EMOJITOOLS_H__
#define __EMOJITOOLS_H__

#include <string>
#include <fstream>
#include <vector>
#include <map>

#if __cplusplus < 202002L
using char8_t = char; // C++17 and older
#endif

#ifndef size_t
using size_t = decltype(sizeof(0));
#endif

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
    
    std::string getEmojiCodePoint(char32_t *emojiCodePoints, size_t length);

    std::string getEmojiGroupsDelimitered(char32_t delimiter);
    std::vector<std::string> getEmojiGroupsList();

    std::string getEmojiSubGroupsDelimitered(char32_t delimiter);
    std::vector<std::string> getEmojiSubGroupsList();

    std::string getEmojiesFromGroup(std::string emojiGroup);
    int getEmojiGroupSize(std::string emojiGroup);

    std::string getEmojiesFromSubGroup(std::string emojiSubGroup);
    int getEmojiSubGroupSize(std::string emojiSubGroup);

    std::string getEmojiByIndexFromGroup(std::string emojiGroup, int index);
    std::string getRandomEmojiFromGroup(std::string emojiGroup);

    std::string getEmojiByIndexFromSubGroup(std::string emojiSubGroup, int index);
    std::string getRandomEmojiFromSubGroup(std::string emojiSubGroup);


    std::string getSubGroupsText(std::string delimiter);
    void printEmojiCodePoint(char32_t *emojiCodePoints, size_t length);
    void printEmojiGroupWDescription(std::string emojiGroup);
    void printEmojiGroup(std::string emojiGroup);
    void printEmojiSubGroupWDescription(std::string emojiSubGroup);
    void printEmojiSubGroup(std::string emojiSubGroup);
    void printGroupsText();
    void printSubGroupsText();
    void printEmojiDescription(std::string emojiDescription);
    void visualTest();
};

#endif // __EMOJITOOLS_H__

//MIT License
//
//Copyright (c) 2024 Tomas Mark
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

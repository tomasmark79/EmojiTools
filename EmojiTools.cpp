#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <regex>
#include <random>

#include "assets/emoji-test.hpp" // Unicode defition of emojis converted to source code
#include "EmojiTools.hpp"

namespace EmojiParser
{

    /// @brief Construct a new EmojiTools object
    /// @param epm std::map
    /// @param file std::ifstream
    void EmojiTools::constructEmojiPropertiesMap(std::map<int, EmojiPropertiesStructure> &epm, std::istream &file)
    {
        int mapKey = 0;
        std::vector<char32_t> emojiCodePoints;
        std::string emojiGroup;
        std::string emojiSubGroup;
        std::string emojiUnicodeVersion;
        std::string emojiTailDescription;
        std::string emojiTextDescription;
        std::string line;
        std::string token;

        // TODO Robust error handling (artefacted file, etc.)
        while (std::getline(file, line))
        {
            if (line.empty())
            {
                continue;
            }
            else if (line[0] == '#' && (line.find("# subgroup:") == std::string::npos) && (line.find("# group:") == std::string::npos))
            {
                continue;
            }
            else if (line.find("# subgroup:") != std::string::npos)
            {

                emojiSubGroup = line.substr(12);
                // pr("\tSubgroup: ");pr(emojiSubGroup); br();
                continue;
            }
            else if (line.find("# group:") != std::string::npos)
            {
                emojiGroup = line.substr(9);
                // pr("Group: "); pr(emojiGroup); br();
                continue;
            }
            else if (
                (line[0] != '#') &&
                (line.find("#") != std::string::npos) &&
                (line.find("# subgroup:") == std::string::npos) &&
                (line.find("# group:") == std::string::npos))
            {

                std::string unicodeString = line.substr(0, line.find(";"));
                // pr("\t\t"); pr(unicodeString);

                std::istringstream iss(unicodeString);
                emojiCodePoints.clear();
                while (iss >> token)
                {
                    token.erase(std::remove_if(token.begin(), token.end(), [](char c)
                                               { return !std::isxdigit(c); }),
                                token.end());

                    uint32_t value;
                    std::stringstream ss;
                    ss << std::hex << token;
                    ss >> value;
                    emojiCodePoints.push_back(static_cast<char32_t>(value));
                }

                emojiTailDescription = line.substr(line.find("#") + 1);
                // pr("\t"); pr(emojiTailDescription); br();

                // regular expression for extract unicode version
                std::regex unicodeRegex(R"((E\d+\.\d+))");
                std::smatch unicodeMatch;
                if (std::regex_search(emojiTailDescription, unicodeMatch, unicodeRegex))
                {
                    emojiUnicodeVersion = unicodeMatch[0];
                    // pr("\t");pr("Unicode v.: "); pr(unicodeMatch[0]);
                }

                // extract emoji text description
                std::string::size_type unicodeVersionPos = emojiTailDescription.find(unicodeMatch[0]);
                if (unicodeVersionPos != std::string::npos)
                {
                    emojiTextDescription = emojiTailDescription.substr(unicodeVersionPos + unicodeMatch[0].length() + 1, emojiTailDescription.size());
                    // pr("\t");pr("Desc.: ");pr(emojiTextDescription);
                }

                // combine emoji character from code points
                char8_t buffer[32];
                Utf8Tools::Utf8Tools utf8tools;
                char8_t *end = utf8tools.encodeUtf8Sequence(emojiCodePoints.data(), emojiCodePoints.size(), buffer);
                *end = '\0'; // Null-terminating the string
                // pr("\t"); pr("Emoji: "); pr(reinterpret_cast<char *>(buffer)); br();
            }

            // create copy of structure
            EmojiPropertiesStructure eps;
            eps.m_emojiCodePoints = emojiCodePoints;
            eps.m_emojiGroup = emojiGroup;
            eps.m_emojiSubGroup = emojiSubGroup;
            eps.m_emojiUnicodeVersion = emojiUnicodeVersion;
            eps.m_emojiTextDescription = emojiTextDescription;

            // insert eps to epm
            epm.insert(std::pair<int, EmojiPropertiesStructure>(mapKey++, eps));

            // ***
            m_isPopulated = true;
        }
    }

    /// @brief load emoji asset file from hardcoded header file
    /// @return std::sstringstream if successful
    std::istringstream EmojiTools::loadEmojiAssetsFromHardcodedHeader()
    {
        std::istringstream ss(emojiTestFileContent);
        if (ss.str().empty())
        {

            exit(1);
        }
        return ss;
    }

    /// @brief load emoji asset file from assets folder
    /// @return std::ifstream if successful else library exits
    std::ifstream EmojiTools::loadEmojiAssetsFromFile()
    {
        // std::string assetFilePath = std::filesystem::current_path().string() + "/assets/emoji-test.txt";
        std::string assetFilePath = "/home/tomas/dev/cpp/modules/EmojiTools/assets/emoji-test.txt-";
        std::ifstream is(assetFilePath);
        if (!is)
            std::cerr << "Emoji asset test file not found. Loading hardcoded definition." << std::endl;
        return is;
    }

    /// @brief Construct a new EmojiTools object
    EmojiTools::EmojiTools()
    {
        std::ifstream is = loadEmojiAssetsFromFile();
        if (is)
        {
            constructEmojiPropertiesMap(m_emojiPropertiesMap, is);
        }
        else
        {
            std::istringstream ss = loadEmojiAssetsFromHardcodedHeader();
            constructEmojiPropertiesMap(m_emojiPropertiesMap, static_cast<std::istream &>(ss));
        }
    }

    /// @brief receive emoji code points and return emoji character
    /// @param emojiCodePoints as array of char32_t
    /// @param length size_t of emojiCodePoints
    /// @return std::string Emoji character
    std::string EmojiTools::getEmojiCodePoint(char32_t *emojiCodePoints, size_t length)
    {
        if (m_isPopulated)
        {
            char8_t buffer[32];
            Utf8Tools::Utf8Tools utf8tools;
            char8_t *end = utf8tools.encodeUtf8Sequence(emojiCodePoints, length, buffer);
            *end = '\0'; // Null-terminating the string
            return std::string(reinterpret_cast<char *>(buffer));
        }
        else
            return "";
    }

    /// @brief get all emoji groups delimitered
    /// @param delimiter char32_t examples: ',' ';' '\n', etc.
    /// @return std::string of emoji groups delimitered
    std::string EmojiTools::getEmojiGroupsDelimitered(char32_t delimiter)
    {
        if (m_isPopulated)
        {
            std::vector<std::string> vecGroups;
            std::string stringDelimiteredGroups;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(vecGroups.begin(), vecGroups.end(), epm.second.m_emojiGroup) == vecGroups.end())
                {
                    vecGroups.push_back(epm.second.m_emojiGroup); // Groups map source
                }
            }
            for (auto &groupItem : vecGroups)
            {
                stringDelimiteredGroups += groupItem;
                if (groupItem != vecGroups.back())
                {
                    stringDelimiteredGroups += delimiter;
                }
            }
            return stringDelimiteredGroups;
        }
        return "";
    }

    /// @brief get all emoji groups list
    /// @return std::vector of emoji groups
    std::vector<std::string> EmojiTools::getEmojiGroupsList()
    {
        if (m_isPopulated)
        {
            std::vector<std::string> vecGroups;

            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(vecGroups.begin(), vecGroups.end(), epm.second.m_emojiGroup) == vecGroups.end())
                {
                    vecGroups.push_back(epm.second.m_emojiGroup); // Groups map source
                }
            }
            return vecGroups;
        }
        return {};
    }

    /// @brief get all emoji subgroups delimitered
    /// @param delimiter char32_t examples: ',' ';' '\n', etc.
    /// @return std::string of emoji subgroups delimitered
    std::string EmojiTools::getEmojiSubGroupsDelimitered(char32_t delimiter)
    {
        if (m_isPopulated)
        {
            std::vector<std::string> vecSubGroups;
            std::string stringDelimiteredSubGroups;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(vecSubGroups.begin(), vecSubGroups.end(), epm.second.m_emojiSubGroup) == vecSubGroups.end())
                {
                    vecSubGroups.push_back(epm.second.m_emojiSubGroup); // SubGroups map source
                }
            }
            for (auto &subGroupItem : vecSubGroups)
            {
                stringDelimiteredSubGroups += subGroupItem;
                if (subGroupItem != vecSubGroups.back())
                {
                    stringDelimiteredSubGroups += delimiter;
                }
            }
            return stringDelimiteredSubGroups;
        }
        return "";
    }

    /// @brief get all emoji subgroups list
    /// @return std::vector of emoji subgroups
    std::vector<std::string> EmojiTools::getEmojiSubGroupsList()
    {
        if (m_isPopulated)
        {
            std::vector<std::string> vecSubGroups;

            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(vecSubGroups.begin(), vecSubGroups.end(), epm.second.m_emojiSubGroup) == vecSubGroups.end())
                {
                    vecSubGroups.push_back(epm.second.m_emojiSubGroup); // SubGroups map source
                }
            }
            return vecSubGroups;
        }
        return {};
    }

    /// @brief get emoji group
    /// @param emojiGroup case sensitive
    /// @return std::string of emoji group
    std::string EmojiTools::getEmojiesFromGroup(std::string emojiGroup)
    {
        if (m_isPopulated)
        {
            std::string emojis = "";
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiGroup == emojiGroup)
                {
                    emojis += getEmojiCodePoint(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                }
            }
            return emojis;
        }
        return "";
    }

    int EmojiTools::getEmojiGroupSize(std::string emojiGroup)
    {
        if (m_isPopulated)
        {
            int count = 0;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiGroup == emojiGroup)
                {
                    count++;
                }
            }
            return count;
        }
        return 0;
    }

    /// @brief get emoji by index from group - 1 based index
    std::string EmojiTools::getEmojiByIndexFromGroup(std::string emojiGroup, int index)
    {
        if (m_isPopulated)
        {
            int count = 0;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiGroup == emojiGroup)
                {
                    if (count == index)
                    {
                        return getEmojiCodePoint(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                    }
                    count++;
                }
            }
        }
        return "";
    }

    std::string EmojiTools::getRandomEmojiFromGroup(std::string emojiGroup)
    {
        if (m_isPopulated)
        {
            int count = 0;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, getEmojiGroupSize(emojiGroup) - 1);
            int randomIndex = dis(gen);

            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiGroup == emojiGroup)
                {
                    if (count == randomIndex)
                    {
                        return getEmojiCodePoint(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                    }
                    count++;
                }
            }
        }
        return "";
    }

    /// @brief get emoji subgroup
    /// @param emojiSubGroup case sensitive
    /// @return std::string of emoji group
    std::string EmojiTools::getEmojiesFromSubGroup(std::string emojiSubGroup)
    {
        if (m_isPopulated)
        {
            std::string emojis = "";
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiSubGroup == emojiSubGroup)
                {
                    emojis += getEmojiCodePoint(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                }
            }
            return emojis;
        }
        return "";
    }

    int EmojiTools::getEmojiSubGroupSize(std::string emojiSubGroup)
    {
        if (m_isPopulated)
        {
            int count = 0;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiSubGroup == emojiSubGroup)
                {
                    count++;
                }
            }
            return count;
        }
        return 0;
    }

    std::string EmojiTools::getEmojiByIndexFromSubGroup(std::string emojiSubGroup, int index)
    {
        if (m_isPopulated)
        {
            int count = 0;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiSubGroup == emojiSubGroup)
                {
                    if (count == index)
                    {
                        return getEmojiCodePoint(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                    }
                    count++;
                }
            }
        }
        return "";
    }

    std::string EmojiTools::getRandomEmojiFromSubGroup(std::string emojiSubGroup)
    {
        if (m_isPopulated)
        {
            int count = 0;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, getEmojiSubGroupSize(emojiSubGroup) - 1);
            int randomIndex = dis(gen);

            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiSubGroup == emojiSubGroup)
                {
                    if (count == randomIndex)
                    {
                        return getEmojiCodePoint(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                    }
                    count++;
                }
            }
        }
        return "";
    }

    /// @brief
    /// @param emojiCodePoints
    /// @param length
    void EmojiTools::printEmojiCodePointChar32_t(char32_t *emojiCodePoints, size_t length)
    {
        char8_t buffer[32];
        Utf8Tools::Utf8Tools utf8tools;
        char8_t *end = utf8tools.encodeUtf8Sequence(emojiCodePoints, length, buffer);
        *end = '\0'; // Null-terminating the string
        std::cout << reinterpret_cast<char *>(buffer);
    }

    void EmojiTools::printEmojiGroupWDescription(std::string emojiGroup)
    {
        if (m_isPopulated)
        {
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiGroup == emojiGroup)
                {
                    std::cout << ("Emoji: ");
                    printEmojiCodePointChar32_t(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                    std::cout << "\t Group: ";
                    std::cout << epm.second.m_emojiGroup;
                    std::cout << " | Subgroup: ";
                    std::cout << epm.second.m_emojiSubGroup;
                    std::cout << " | Description: ";
                    std::cout << epm.second.m_emojiTextDescription;
                    std::cout << " | Unicode version: ";
                    std::cout << epm.second.m_emojiUnicodeVersion << std::endl;
                }
            }
        }
    }

    void EmojiTools::printEmojiGroup(std::string emojiGroup)
    {
        if (m_isPopulated)
        {
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiGroup == emojiGroup)
                {
                    printEmojiCodePointChar32_t(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                }
            }
        }
    }

    void EmojiTools::printEmojiSubGroupWDescription(std::string emojiSubGroup)
    {
        if (m_isPopulated)
        {
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiSubGroup == emojiSubGroup)
                {
                    std::cout << "Emoji: ";
                    printEmojiCodePointChar32_t(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                    std::cout << "\t Group: ";
                    std::cout << epm.second.m_emojiGroup;
                    std::cout << " | Subgroup: ";
                    std::cout << epm.second.m_emojiSubGroup;
                    std::cout << " | Description: ";
                    std::cout << epm.second.m_emojiTextDescription;
                    std::cout << " | Unicode version: ";
                    std::cout << epm.second.m_emojiUnicodeVersion << std::endl;
                }
            }
        }
    }

    void EmojiTools::printEmojiSubGroup(std::string emojiSubGroup)
    {
        if (m_isPopulated)
        {
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (epm.second.m_emojiSubGroup == emojiSubGroup)
                {
                    printEmojiCodePointChar32_t(epm.second.m_emojiCodePoints.data(), epm.second.m_emojiCodePoints.size());
                }
            }
        }
    }

    void EmojiTools::printGroupsText()
    {
        if (m_isPopulated)
        {
            std::vector<std::string> groups;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(groups.begin(), groups.end(), epm.second.m_emojiGroup) == groups.end())
                {
                    groups.push_back(epm.second.m_emojiGroup);
                }
            }

            for (auto &group : groups)
            {
                std::cout << "Group: ";
                std::cout << group << std::endl;
            }
        }
    }

    std::string EmojiTools::getSubGroupsText(std::string delimiter)
    {
        if (m_isPopulated)
        {
            std::vector<std::string> subgroups;
            std::string strSubGroups;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(subgroups.begin(), subgroups.end(), epm.second.m_emojiSubGroup) == subgroups.end())
                {
                    subgroups.push_back(epm.second.m_emojiSubGroup);
                }
            }

            for (auto &group : subgroups)
            {
                strSubGroups += group;
                if (group != subgroups.back())
                {
                    strSubGroups += delimiter;
                }
            }
            return strSubGroups;
        }
        return "";
    }

    void EmojiTools::printSubGroupsText()
    {
        if (m_isPopulated)
        {
            std::vector<std::string> subgroups;
            for (auto &epm : m_emojiPropertiesMap)
            {
                if (std::find(subgroups.begin(), subgroups.end(), epm.second.m_emojiSubGroup) == subgroups.end())
                {
                    subgroups.push_back(epm.second.m_emojiSubGroup);
                }
            }

            for (auto &subgroup : subgroups)
            {
                std::cout << "Subgroup: ";
                std::cout << subgroup << std::endl;
            }
        }
    }

    void EmojiTools::TEST()
    {
        std::cout << "START - Visual TEST" << std::endl;

        // print emoji group with description
        std::cout << "Emoji Groups List: " << getEmojiGroupsDelimitered(';') << std::endl; // delimiter may be also '\n'

        // simple codepoint - should be supported by all platforms
        char32_t emojiCodePoint[1] = {0x1F600}; // 😀
        printEmojiCodePointChar32_t(emojiCodePoint, 1);

        // advanced codepoint combination - may be not supported by all platforms
        char32_t emojiCodePointWSelector[2] = {0x2764, 0x200D}; // ❤‍❤‍
        printEmojiCodePointChar32_t(emojiCodePointWSelector, 2);

        // advanced codepoint combination - may be not supported by all platforms
        char32_t emojiCodePointWSelector3[3] = {0x2764, 0x200D, 0x1F525}; // ❤‍🔥❤‍🔥
        
        printEmojiCodePointChar32_t(emojiCodePointWSelector3, 3);

        // advanced codepoint combination - may be not supported by all platforms
        char32_t emojiCodePointWSelector4[4] = {0x2764, 0xFE0F, 0x200D, 0x1F525}; // ❤‍🔥❤‍🔥
        printEmojiCodePointChar32_t(emojiCodePointWSelector4, 4);

        // advanced codepoint combination - may be not supported by all platforms
        char32_t emojiCodePointWSelector7[7] = {0x1F9D1, 0x1F3FF, 0x200D, 0x1F9AF, 0x200D, 0x27A1, 0xFE0F}; // 🧑🏿‍🦯‍➡️🧑🏿‍🦯‍➡️
        printEmojiCodePointChar32_t(emojiCodePointWSelector7, 7);

        // show emoji group
        std::cout << getEmojiesFromGroup("Smileys & Emotion") << std::endl;
        // 😀😃😄😁😆😅🤣😂🙂🙃🫠😉😊😇🥰😍🤩😘😗 ...

        // show emoji subgroup
        std::cout << getEmojiesFromSubGroup("warning") << std::endl;
        // ⚠️⚠🚸⛔🚫🚳🚭🚯🚱🚷📵🔞☢️☢☣️☣

        printEmojiSubGroupWDescription("warning");

        std::cout << "END - Visual TEST" << std::endl;
    }
}

// MIT License
//
// Copyright (c) 2024 Tomas Mark
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

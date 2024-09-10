#ifndef __UTF8TOOLS_H__
#define __UTF8TOOLS_H__

#include <fstream>

#if __cplusplus < 202002L
using char8_t = char;
#endif

class Utf8Tools
{
public:
    Utf8Tools() = default;

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

#endif // __UTF8TOOLS_H__

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

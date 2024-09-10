// src/Utf8Tools.cpp
#include "Utf8Tools.hpp"
#include "hlog.hpp"

#include <assert.h>
#include <map>
#include <filesystem>
#include <iostream>

/// @brief encode a UTF-8 code point
/// @param emojiCodePoint 
/// @param buffer8 
/// @return char8_t*
char8_t *Utf8Tools::encodeUtf8(char32_t emojiCodePoint, char8_t *buffer8)
{
    constexpr auto byte = [](char32_t x)
    {
        assert(x <= 0x100); // 256
        return static_cast<char8_t>(x);
    };

    char32_t continuation = 0b1000'0000; // 128
    if (emojiCodePoint >= 65536)
    {
        *buffer8++ = byte(0b1111'0000 | (emojiCodePoint >> 18));
        *buffer8++ = byte(continuation | ((emojiCodePoint >> 12) & 0b0011'1111));
        *buffer8++ = byte(continuation | ((emojiCodePoint >> 6) & 0b0011'1111));
        *buffer8++ = byte(continuation | (emojiCodePoint & 0b0011'1111));
    }
    else if (emojiCodePoint >= 2048)
    {
        *buffer8++ = byte(0b1110'0000 | (emojiCodePoint >> 12));
        *buffer8++ = byte(continuation | ((emojiCodePoint >> 6) & 0b0011'1111));
        *buffer8++ = byte(continuation | (emojiCodePoint & 0b0011'1111));
    }
    else if (emojiCodePoint >= 128)
    {
        *buffer8++ = byte(0b1100'0000 | (emojiCodePoint >> 6));
        *buffer8++ = byte(continuation | (emojiCodePoint & 0b0011'1111));
    }
    else
    {
        *buffer8++ = byte(emojiCodePoint);
    }

    return buffer8;
}

/// @brief encode a sequence of UTF-8 code points
/// @param emojiCodePoints 
/// @param length 
/// @param buffer8 
/// @return char8_t*
char8_t *Utf8Tools::encodeUtf8Sequence(const char32_t *emojiCodePoints, size_t length, char8_t *buffer8)
{
    for (size_t i = 0; i < length; ++i)
    {
        buffer8 = encodeUtf8(emojiCodePoints[i], buffer8);
    }
    return buffer8;
}

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

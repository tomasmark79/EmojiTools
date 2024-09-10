# Emoji Tools 😉🪄🎯

C++ module for simple work with the Unicode defined Emojis
 - utf8 support
 - You may to get Unicode Emoji string
   - by codepoints 🎯
   - by group name 🎯
   - by sub group name 🎯
 - You may to get Emoji group or sub group list
 
The C++ module is using official document by Unicode organisation as the source definition.

## How to call examples

```cpp
std::cout << emojitools.getEmojiGroupsDelimitered(';') << std::endl;
[output]
Smileys & Emotion;People & Body;Component;Animals & Nature;Food & Drink;Travel & Places;Activities;Objects;Symbols;Flags
```

```cpp
std::cout << tomarklib::emojitools.getEmojiGroupsDelimitered('\n') << std::endl; // new line delimiter
std::vector<std::string> vecEmojiGroups = tomarklib::emojitools.getEmojiGroupsList(); // get the list of emoji groups
std::cout << tomarklib::emojitools.getEmojiSubGroupsDelimitered(';') << std::endl;
[output]
face-smiling;face-affection;face-tongue;face-hand;face-neutral-skeptical;face-sleepy;face-unwell;face-hat;face-glasses
```

```cpp
std::cout << tomarklib::emojitools.
getEmojiSubGroupsDelimitered('\n') << std::endl; // new line delimiter
std::vector<std::string> vecEmojiSubGroups = tomarklib::emojitools.getEmojiSubGroupsList();
[output]
("Smileys & Emotion") << std::endl;
😀😃😄😁😆😅🤣😂🙂🙃🫠😉😊😇🥰😍🤩😘😗 ...
```

```cpp
std::cout << tomarklib::emojitools.getEmojiSubGroup("warning") << std::endl;
[output]
⚠️⚠🚸⛔🚫🚳🚭🚯🚱🚷📵🔞☢️☢☣️☣
```

```cpp
std::cout << tomarklib::emojitools.getEmojiSubGroup("game") << std::endl;
[output]
🎯🪀🪁🔫🎱🔮🪄🎮🕹️🕹🎰🎲🧩🧸🪅🪩🪆♠️♠♥️♥♦️♦♣️♣♟️♟🃏🀄🎴
```

```cpp
std::cout << tomarklib::emojitools.getEmojiSubGroup("drink") << std::endl;
🍼🥛☕🫖🍵🍶🍾🍷🍸🍹🍺🍻🥂🥃🫗🥤🧋🧃🧉🧊
```

## Licence
```txt
MIT License

Copyright (c) 2024 Tomas Mark

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
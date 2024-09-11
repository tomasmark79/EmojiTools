# Emoji Tools 😉🪄🎯

C++ module for simple work with Unicode Emojis
 - You may to get Unicode Emoji string
   - by codepoint number 🎯
   - by combinec codepoints 🎯
   - by group name 🎯
   - by sub group name 🎯
 - You may to get Emoji group or sub group list
 - You may get Emoji group or sub group list with the description and the Unicode version
 - ...

## How to use

An examples how to call and retrieve Emojis can be found within the TEST method.

```cpp
int main()
{
    EmojiTools::EmojiTools emojitools;

    emojitools.TEST();

    return 0;
}
```

### awaited output

```txt
START - Visual TEST
Emoji Groups List: Smileys & Emotion;People & Body;Component;Animals & Nature;Food & Drink;Travel & Places;Activities;Objects;Symbols;Flags
😀❤‍❤‍🔥❤️‍🔥🧑🏿‍🦯‍➡️😀😃😄😁😆😅🤣😂🙂🙃🫠😉😊😇🥰😍🤩😘😗☺️☺😚😙🥲😋😛😜🤪😝🤑🤗🤭🫢🫣🤫🤔🫡🤐🤨😐😑😶🫥😶‍🌫️😶‍🌫😏😒🙄😬😮‍💨🤥🫨🙂‍↔️🙂‍↔🙂‍↕️🙂‍↕😌😔😪🤤😴😷🤒🤕🤢🤮🤧🥵🥶🥴😵😵‍💫🤯🤠🥳🥸😎🤓🧐😕🫤😟🙁☹️☹😮😯😲😳🥺🥹😦😧😨😰😥😢😭😱😖😣😞😓😩😫🥱😤😡😠🤬😈👿💀☠️☠💩🤡👹👺👻👽👾🤖😺😸😹😻😼😽🙀😿😾🙈🙉🙊💌💘💝💖💗💓💞💕💟❣️❣💔❤️‍🔥❤‍🔥❤️‍🩹❤‍🩹❤️❤🩷🧡💛💚💙🩵💜🤎🖤🩶🤍💋💯💢💥💫💦💨🕳️🕳💬👁️‍🗨️👁‍🗨️👁️‍🗨👁‍🗨🗨️🗨🗯️🗯💭💤
⚠️⚠🚸⛔🚫🚳🚭🚯🚱🚷📵🔞☢️☢☣️☣
Emoji: ⚠️         Group: Symbols | Subgroup: warning | Description: warning | Unicode version: E0.6
Emoji: ⚠         Group: Symbols | Subgroup: warning | Description: warning | Unicode version: E0.6
Emoji: 🚸        Group: Symbols | Subgroup: warning | Description: children crossing | Unicode version: E1.0
Emoji: ⛔        Group: Symbols | Subgroup: warning | Description: no entry | Unicode version: E0.6
Emoji: 🚫        Group: Symbols | Subgroup: warning | Description: prohibited | Unicode version: E0.6
Emoji: 🚳        Group: Symbols | Subgroup: warning | Description: no bicycles | Unicode version: E1.0
Emoji: 🚭        Group: Symbols | Subgroup: warning | Description: no smoking | Unicode version: E0.6
Emoji: 🚯        Group: Symbols | Subgroup: warning | Description: no littering | Unicode version: E1.0
Emoji: 🚱        Group: Symbols | Subgroup: warning | Description: non-potable water | Unicode version: E1.0
Emoji: 🚷        Group: Symbols | Subgroup: warning | Description: no pedestrians | Unicode version: E1.0
Emoji: 📵        Group: Symbols | Subgroup: warning | Description: no mobile phones | Unicode version: E1.0
Emoji: 🔞        Group: Symbols | Subgroup: warning | Description: no one under eighteen | Unicode version: E0.6
Emoji: ☢️         Group: Symbols | Subgroup: warning | Description: radioactive | Unicode version: E1.0
Emoji: ☢         Group: Symbols | Subgroup: warning | Description: radioactive | Unicode version: E1.0
Emoji: ☣️         Group: Symbols | Subgroup: warning | Description: biohazard | Unicode version: E1.0
Emoji: ☣         Group: Symbols | Subgroup: warning | Description: biohazard | Unicode version: E1.0
END - Visual TEST
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
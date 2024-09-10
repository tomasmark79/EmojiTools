#include <iostream>
#include "EmojiTools.hpp"

int main(int argc, char const *argv[])
{
    EmojiTools emojitools;
    std::cout << emojitools.getEmojiGroupsDelimitered(';') << std::endl;
    // Smileys & Emotion;People & Body;Component;Animals & Nature;Food & Drink;Travel & Places;Activities;Objects;Symbols;Flags

    std::cout << emojitools.getEmojiGroupsDelimitered('\n') << std::endl;      // new line delimiter
    std::vector<std::string> vecEmojiGroups = emojitools.getEmojiGroupsList(); // get the list of emoji groups

    std::cout << emojitools.getEmojiSubGroupsDelimitered(';') << std::endl;
    // face-smiling;face-affection;face-tongue;face-hand;face-neutral-skeptical;face-sleepy;face-unwell;face-hat;face-glasses;
    // ace-concerned;face-negative;face-costume;cat-face;monkey-face;heart;emotion;hand-fingers-open;hand-fingers-partial;
    // hand-single-finger;hand-fingers-closed;hands;hand-prop;body-parts;person;person-gesture;person-role;person-fantasy;
    // person-activity;person-sport;person-resting;family;person-symbol;skin-tone;hair-style;animal-mammal;animal-bird;
    // animal-amphibian;animal-reptile;animal-marine;animal-bug;plant-flower;plant-other;food-fruit;food-vegetable;food-prepared;
    // ood-asian;food-marine;food-sweet;drink;dishware;place-map;place-geographic;place-building;place-religious;place-other;
    // transport-ground;transport-water;transport-air;hotel;time;sky & weather;event;award-medal;sport;game;arts & crafts;
    // clothing;sound;music;musical-instrument;phone;computer;light & video;book-paper;money;mail;writing;office;lock;tool;
    // science;medical;household;other-object;transport-sign;warning;arrow;religion;zodiac;av-symbol;gender;math;punctuation;
    // currency;other-symbol;keycap;alphanum;geometric;flag;country-flag;subdivision-flagmm

    std::cout << emojitools.getEmojiSubGroupsDelimitered('\n') << std::endl;         // new line delimiter
    std::vector<std::string> vecEmojiSubGroups = emojitools.getEmojiSubGroupsList(); // get the list of emoji sub groups

    std::cout << emojitools.getEmojiesFromGroup("Smileys & Emotion") << std::endl;
    // 😀😃😄😁😆😅🤣😂🙂🙃🫠😉😊😇🥰😍🤩😘😗 ...

    std::cout << emojitools.getEmojiesFromSubGroup("warning") << std::endl;
    // ⚠️⚠🚸⛔🚫🚳🚭🚯🚱🚷📵🔞☢️☢☣️☣

    std::cout << emojitools.getEmojiesFromSubGroup("game") << std::endl;
    // 🎯🪀🪁🔫🎱🔮🪄🎮🕹️🕹🎰🎲🧩🧸🪅🪩🪆♠️♠♥️♥♦️♦♣️♣♟️♟🃏🀄🎴

    std::cout << emojitools.getEmojiesFromSubGroup("drink") << std::endl;
    // 🍼🥛☕🫖🍵🍶🍾🍷🍸🍹🍺🍻🥂🥃🫗🥤🧋🧃🧉🧊

    int groupSize = emojitools.getEmojiGroupSize("Smileys & Emotion");

    std::cout << std::endl
              << groupSize << std::endl;
    std::cout << "Smileys & Emotion group size: " << emojitools.getEmojiByIndexFromGroup("Smileys & Emotion", groupSize - 1) << std::endl;

    std::cout << "Random emoji from Smileys & Emotion group: " << emojitools.getRandomEmojiFromGroup("Smileys & Emotion") << std::endl;

    std::cout << "Quitting the program" << std::endl;
    return 0;
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

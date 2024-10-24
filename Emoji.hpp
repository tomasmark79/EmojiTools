#pragma once
#include <string>
#include "EmojiTools.hpp"

// Abstract Factory Pattern
class Emoji
{
public:
    virtual void print() = 0;
    virtual std::string getRandom() = 0;
    virtual ~Emoji() {};
};

// Concrete Product
class Smiley : public Emoji
{
public:
    virtual void print() override {};
    virtual std::string getRandom() override {
        EmojiTools::EmojiTools emojiTools;
        return emojiTools.getRandomEmojiFromGroup("Smileys & Emotion");
    };
};

// Concrete Product
class Winky : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override {};
};

// Abstract Factory
class EmojiFactory
{
public:
    virtual Emoji *createEmoji() = 0;
    virtual ~EmojiFactory() {};
};

// Concrete Factory
class SmileyFactory : public EmojiFactory
{
public:
    Emoji *createEmoji() override
    {
        return new Smiley();
    };
};

// Concrete Factory
class WinkyFactory : public EmojiFactory
{
public:
    Emoji *createEmoji() override
    {
        return new Winky();
    };
};

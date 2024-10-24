#pragma once
#include <string>
#include "EmojiTools.hpp"

EmojiTools::EmojiTools emojiTools;

// Abstract Factory Pattern
class Emoji
{
public:
    virtual void print() = 0;
    virtual std::string getRandom() = 0;
    virtual ~Emoji() {};
};

// Concrete Products
class Smiley : public Emoji
{
public:
    virtual void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Smileys & Emotion");
    };
};

class Emotion : public Emoji
{
public:
    virtual void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Smileys & Emotion");
    };
};

class Poeple : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("People & Body");
    };
};

class Body : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("People & Body");
    };
};

class Animals : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Animals & Nature");
    };
};

class Nature : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Animals & Nature");
    };
};
class Food : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Food & Drink");
    };
};
class Drink : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Food & Drink");
    };
};

class Travel : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Travel & Places");
    };
};
class Places : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Travel & Places");
    };
};

class Activities : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Activities");
    };
};

class Objects : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Objects");
    };
};

class Symbols : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Symbols");
    };
};

class Flags : public Emoji
{
public:
    void print() override {};
    virtual std::string getRandom() override
    {
        return emojiTools.getRandomEmojiFromGroup("Flags");
    };
};





// Abstract Factory
class EmojiFactory
{
public:
    virtual Emoji *createEmoji() = 0;
    virtual ~EmojiFactory() {};
};

// Concrete Factories
class SmileyFactory : public EmojiFactory
{
public:
    Emoji *createEmoji() override
    {
        return new Smiley();
    };
};
class PoepleFactory : public EmojiFactory
{
public:
    Emoji *createEmoji() override
    {
        return new Poeple();
    };
};

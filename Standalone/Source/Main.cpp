
#include <EmojiTools/EmojiTools.hpp>
#include <emojitools/version.h>

#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

int main()
{
    std::unique_ptr<EmojiTools> Lib = std::make_unique<EmojiTools>(); // cpp14 +
    // std::unique_ptr<EmojiTools> Lib(new EmojiTools()); // cpp11 +

    std::string randomEmoji;
    std::cout << "Print random emoji: " << Lib->getRandomEmoji(randomEmoji) << std::endl;

    // remove me ------------------👇🏻
    std::cout << "Wait for 5 seconds please ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Bye bye!" << std::endl;
    // remove me ------------------👆🏻

    return 0;
}

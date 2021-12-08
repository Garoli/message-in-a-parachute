#ifndef LETTER_H
#define LETTER_H
#include <string>
#include <bitset>

class Letter
{
public:
    Letter(char);
    std::bitset<7> get_letter();
private:
    std::bitset<7> _letter;
};

#endif // LETTER_H

#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <vector>
#include "letter.h"

class Message
{
public:
    Message(std::string);
    std::vector<Letter> getMessage();
private:
    std::vector<Letter> _message;

};

#endif // MESSAGE_H

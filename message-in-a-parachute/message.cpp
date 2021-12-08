#include "message.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <QDebug>
Message::Message(std::string str){
    size_t pos = 0;
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
    for(char& c : str) {
        _message.push_back(Letter(c));
    }
}

std::vector<Letter> Message::getMessage(){
    return _message;
}


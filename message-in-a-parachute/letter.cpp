#include "letter.h"


Letter::Letter(char letter){
    _letter= std::bitset<7>(letter-64);
}

std::bitset<7> Letter::get_letter(){
    return _letter;
}

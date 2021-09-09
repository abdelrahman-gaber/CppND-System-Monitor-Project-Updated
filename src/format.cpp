#include "format.h"

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
    std::string s, h, m;
    int mins;

    mins = seconds / 60;
    s = std::to_string(seconds % 60);
    h = std::to_string(mins / 60);
    m = std::to_string(mins % 60);

    std::string out = h.insert(0, 2 - h.length(), '0') + ":" + m.insert(0, 2 - m.length(), '0') + ":" + s.insert(0, 2 - s.length(), '0');

    return out; 
}
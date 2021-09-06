#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
    int s, h, m;

    m = seconds / 60;
    s = seconds % 60;
    h = m / 60;
    m = m % 60;

    std::string out = std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);

    return out; }
#include "parseString.h"
#include <string>
#include <vector>

void parseString(
        std::string s, std::string delim, std::vector<std::string>& text)
{
    size_t prev = 0;
    size_t next;
    size_t delta = delim.length();

    while ((next = s.find(delim, prev)) != std::string::npos) {
        std::string tmp = s.substr(prev, next - prev);

        text.push_back(s.substr(prev, next - prev));
        prev = next + delta;
    }
    std::string tmp = s.substr(prev);
    text.push_back(s.substr(prev));
}
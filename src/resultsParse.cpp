#include "resultsParse.h"

void resultsParse(const std::string resultsPath, std::vector<Results>& a)
{
    std::ifstream results(resultsPath);
    results.clear();

    while (!results.eof()) {
        std::string temp;
        Results buff;

        std::getline(results, temp, '\n');

        if (temp == "") {
            return;
        }

        std::vector<std::string> words;
        parseString(temp, " ", words);

        buff.username = words.at(0);
        buff.point = words.at(1);
        buff.time = words.at(2);

        words.clear();
        a.push_back(buff);
    }

    results.close();
}

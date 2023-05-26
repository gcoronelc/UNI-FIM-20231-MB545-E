#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }

    return tokens;
}

int main() {
    std::string input = "Hola,Mundo,Split,C++,Java";
    std::vector<std::string> result = split(input, ',');

    for (const std::string& token : result) {
        std::cout << token << std::endl;
    }

    return 0;
}
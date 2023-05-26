#include <iostream>
#include <cstring>

void split(const char* s, char delimiter, char** result, int& numTokens) {
    const char* delimiterPtr = strchr(s, delimiter);
    numTokens = 0;

    while (delimiterPtr != nullptr) {
        int tokenLength = delimiterPtr - s;
        result[numTokens] = new char[tokenLength + 1];
        strncpy(result[numTokens], s, tokenLength);
        result[numTokens][tokenLength] = '\0';
        numTokens++;

        s = delimiterPtr + 1;
        delimiterPtr = strchr(s, delimiter);
    }

    if (strlen(s) > 0) {
        int tokenLength = strlen(s);
        result[numTokens] = new char[tokenLength + 1];
        strcpy(result[numTokens], s);
        numTokens++;
    }
}

void freeTokens(char** tokens, int numTokens) {
    for (int i = 0; i < numTokens; i++) {
        delete[] tokens[i];
    }

    delete[] tokens;
}

int main() {
    const char* input = "Hola,Mundo,Split,C++,Java";
    char* tokens[10];
    int numTokens = 0;

    split(input, ',', tokens, numTokens);

    for (int i = 0; i < numTokens; i++) {
        std::cout << tokens[i] << std::endl;
    }

    freeTokens(tokens, numTokens);

    return 0;
}

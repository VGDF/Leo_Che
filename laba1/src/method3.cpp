#include <iostream>
#include <fstream>
#include <cctype>

void processString(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (isupper(str[i])) {
            int start = i;
            while (str[i] != '\0' && isupper(str[i])) {
                i++;
            }
            int wordLength = i - start;
            for (int j = start; j < i; j++) {
                str[j] = (j - start) % 2 == 0 ? 'X' : 'O';
            }
        } else {
            i++;
        }
    }
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    char str[100];
    inputFile.getline(str, 100);
    inputFile.close();

    processString(str);

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    outputFile << str;
    outputFile.close();

    std::cout << "Processed string written to output.txt" << std::endl;
    return 0;
}

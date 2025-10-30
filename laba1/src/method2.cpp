#include <iostream>
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
    char str[100];
    std::cout << "Enter a string: ";
    std::cin.getline(str, 100);
    processString(str);
    std::cout << "Processed string: " << str << std::endl;
    return 0;
}

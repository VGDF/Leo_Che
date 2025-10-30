#include <iostream>
#include <cctype>

void processString(char str[], int length) {
    int i = 0;
    while (i < length) {
        if (isupper(str[i])) {
            int start = i;
            while (i < length && isupper(str[i])) {
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
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    processString(str, length);
    std::cout << "Processed string: " << str << std::endl;
    return 0;
}

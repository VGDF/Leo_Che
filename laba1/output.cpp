#include <fstream>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>

bool isAllUppercase(const char* word, int length) {
    for (int i = 0; i < length; i++) {
        if (!std::isupper(static_cast<unsigned char>(word[i]))) {
            return false;
        }
    }
    return true;
}

void replaceWithXO(char* word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = (i % 2 == 0) ? 'X' : 'O';
    }
}

void processStringAsCString(char* str, size_t size) {
    if (str == nullptr || size == 0) return;
    
    char* current = str;
    char* end = str + size;
    
    while (current < end) {
        if (!std::isalpha(static_cast<unsigned char>(*current))) {
            current++;
            continue;
        }
        
        char* wordStart = current;
        int wordLength = 0;
        
        while (current < end && std::isalpha(static_cast<unsigned char>(*current))) {
            wordLength++;
            current++;
        }
        
        if (isAllUppercase(wordStart, wordLength)) {
            replaceWithXO(wordStart, wordLength);
        }
    }
}

int main() {
    std::ifstream in("input.exe", std::ios::binary);
    if (!in) {
        std::cerr << "Error reading input.exe" << std::endl;
        return 1;
    }


    in.seekg(0, std::ios::end);
    size_t fileSize = in.tellg();
    in.seekg(0, std::ios::beg);

    
    std::vector<char> buffer(fileSize);
    in.read(buffer.data(), fileSize);
    in.close();

  
    processStringAsCString(buffer.data(), fileSize);

    std::ofstream out("output.exe", std::ios::binary);
    if (!out) {
        std::cerr << "Error creating output.exe" << std::endl;
        return 1;
    }

    out.write(buffer.data(), fileSize);
    out.close();

    std::cout << "Processing completed: input.exe -> output.exe" << std::endl;
    std::cout << "File size: " << fileSize << " bytes" << std::endl;

    return 0;
}
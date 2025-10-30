#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <cstring>
#include <fstream>

// Предполагаем, что у вас есть эти функции в ваших программах
// Для варианта 1 - массив символов
void processStringAsArray(char* str, int size);
// Для варианта 2 - C-style строка  
void processStringAsCString(char* str);
// Для варианта 3 - работа с файлами
void processStringInFile(const char* inputFile, const char* outputFile);

// ==================== ТЕСТЫ ДЛЯ ВАРИАНТА 1 (МАССИВ СИМВОЛОВ) ====================

TEST_CASE("Process string as array - empty string", "[string_array]") {
    char str[] = "";
    int size = 0;
    processStringAsArray(str, size);
    REQUIRE(str[0] == '\0');
}

TEST_CASE("Process string as array - no uppercase words", "[string_array]") {
    char str[] = "hello world test";
    int size = strlen(str);
    char expected[] = "hello world test";
    
    processStringAsArray(str, size);
    
    REQUIRE(std::strncmp(str, expected, size) == 0);
}

TEST_CASE("Process string as array - single uppercase word", "[string_array]") {
    char str[] = "HELLO";
    int size = strlen(str);
    char expected[] = "XOXOX";
    
    processStringAsArray(str, size);
    
    REQUIRE(std::strncmp(str, expected, size) == 0);
}

TEST_CASE("Process string as array - multiple uppercase words", "[string_array]") {
    char str[] = "HELLO WORLD TEST";
    int size = strlen(str);
    char expected[] = "XOXOX XOXOX XOX";
    
    processStringAsArray(str, size);
    
    REQUIRE(std::strncmp(str, expected, size) == 0);
}

TEST_CASE("Process string as array - mixed case words", "[string_array]") {
    char str[] = "Hello WORLD mixed TEST case";
    int size = strlen(str);
    char expected[] = "Hello XOXOX mixed XOX case";
    
    processStringAsArray(str, size);
    
    REQUIRE(std::strncmp(str, expected, size) == 0);
}

// ==================== ТЕСТЫ ДЛЯ ВАРИАНТА 2 (C-STYLE СТРОКА) ====================

TEST_CASE("Process string as C string - empty string", "[string_cstr]") {
    char str[] = "";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "") == 0);
}

TEST_CASE("Process string as C string - no uppercase words", "[string_cstr]") {
    char str[] = "hello world test";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "hello world test") == 0);
}

TEST_CASE("Process string as C string - single uppercase word", "[string_cstr]") {
    char str[] = "HELLO";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "XOXOX") == 0);
}

TEST_CASE("Process string as C string - multiple uppercase words", "[string_cstr]") {
    char str[] = "HELLO WORLD TEST";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "XOXOX XOXOX XOX") == 0);
}

TEST_CASE("Process string as C string - mixed case words", "[string_cstr]") {
    char str[] = "Hello WORLD mixed TEST case";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "Hello XOXOX mixed XOX case") == 0);
}

TEST_CASE("Process string as C string - words with numbers", "[string_cstr]") {
    char str[] = "HELLO123 ABC TEST123";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "HELLO123 XOX TEST123") == 0);
}

// ==================== ТЕСТЫ ДЛЯ ВАРИАНТА 3 (РАБОТА С ФАЙЛАМИ) ====================

TEST_CASE("Process string in file - empty string", "[string_file]") {
    const char* inputFile = "test_input_empty.txt";
    const char* outputFile = "test_output_empty.txt";
    
    // Создаем входной файл
    std::ofstream in(inputFile);
    in << "";
    in.close();
    
    // Обрабатываем
    processStringInFile(inputFile, outputFile);
    
    // Проверяем результат
    std::ifstream out(outputFile);
    std::string result;
    std::getline(out, result);
    out.close();
    
    REQUIRE(result == "");
    
    // Удаляем временные файлы
    std::remove(inputFile);
    std::remove(outputFile);
}

TEST_CASE("Process string in file - no uppercase words", "[string_file]") {
    const char* inputFile = "test_input_no_upper.txt";
    const char* outputFile = "test_output_no_upper.txt";
    
    std::ofstream in(inputFile);
    in << "hello world test";
    in.close();
    
    processStringInFile(inputFile, outputFile);
    
    std::ifstream out(outputFile);
    std::string result;
    std::getline(out, result);
    out.close();
    
    REQUIRE(result == "hello world test");
    
    std::remove(inputFile);
    std::remove(outputFile);
}

TEST_CASE("Process string in file - multiple uppercase words", "[string_file]") {
    const char* inputFile = "test_input_multi_upper.txt";
    const char* outputFile = "test_output_multi_upper.txt";
    
    std::ofstream in(inputFile);
    in << "HELLO WORLD TEST PROGRAM";
    in.close();
    
    processStringInFile(inputFile, outputFile);
    
    std::ifstream out(outputFile);
    std::string result;
    std::getline(out, result);
    out.close();
    
    REQUIRE(result == "XOXOX XOXOX XOX XOXOXO");
    
    std::remove(inputFile);
    std::remove(outputFile);
}

TEST_CASE("Process string in file - mixed content", "[string_file]") {
    const char* inputFile = "test_input_mixed.txt";
    const char* outputFile = "test_output_mixed.txt";
    
    std::ofstream in(inputFile);
    in << "Hello WORLD this IS a TEST";
    in.close();
    
    processStringInFile(inputFile, outputFile);
    
    std::ifstream out(outputFile);
    std::string result;
    std::getline(out, result);
    out.close();
    
    REQUIRE(result == "Hello XOXOX this XO a XOX");
    
    std::remove(inputFile);
    std::remove(outputFile);
}

TEST_CASE("Process string in file - special characters", "[string_file]") {
    const char* inputFile = "test_input_special.txt";
    const char* outputFile = "test_output_special.txt";
    
    std::ofstream in(inputFile);
    in << "HELLO! WORLD? TEST,123";
    in.close();
    
    processStringInFile(inputFile, outputFile);
    
    std::ifstream out(outputFile);
    std::string result;
    std::getline(out, result);
    out.close();
    
    REQUIRE(result == "XOXOX! XOXOX? XOX,123");
    
    std::remove(inputFile);
    std::remove(outputFile);
}

// ==================== ГРАНИЧНЫЕ СЛУЧАИ И ОБРАБОТКА ОШИБОК ====================

TEST_CASE("Process string - single character uppercase", "[string_all]") {
    char str1[] = "A";
    char str2[] = "A";
    
    processStringAsArray(str1, 1);
    processStringAsCString(str2);
    
    REQUIRE(str1[0] == 'X');
    REQUIRE(std::strcmp(str2, "X") == 0);
}

TEST_CASE("Process string - two character uppercase", "[string_all]") {
    char str1[] = "AB";
    char str2[] = "AB";
    
    processStringAsArray(str1, 2);
    processStringAsCString(str2);
    
    REQUIRE(std::strncmp(str1, "XO", 2) == 0);
    REQUIRE(std::strcmp(str2, "XO") == 0);
}

TEST_CASE("Process string - only uppercase with punctuation", "[string_all]") {
    char str[] = "HELLO, WORLD! TEST?";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "XOXOX, XOXOX! XOX?") == 0);
}

TEST_CASE("Process string - consecutive uppercase words", "[string_all]") {
    char str[] = "HELLO WORLD TEST PROGRAM";
    processStringAsCString(str);
    REQUIRE(std::strcmp(str, "XOXOX XOXOX XOX XOXOXO") == 0);
}
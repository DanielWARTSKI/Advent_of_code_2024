#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {

    int total = 0;
    int total_v2 = 0;
    bool enabled = 1;

    std::ifstream file("Advent_of_code_2024/Day3/input3.txt");

    //std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::regex pattern_do_dont(R"(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\))");
    std::string line;
    std::smatch matches;

    while (std::getline(file, line)) {
        //std::cout << "Ligne lue : " << line << std::endl;
        auto begin = line.cbegin();
        auto end = line.cend();

        while (std::regex_search(begin, end, matches, pattern_do_dont)) {
            std::string instruction = matches[0];
            if (instruction == "do()") {
                enabled = 1;
            } else if (instruction == "don't()") {
                enabled = 0;
            } else if (matches[1].matched && matches[2].matched) {
                int x = std::stoi(matches[1]);
                int y = std::stoi(matches[2]);
                if (enabled){
                    total_v2 += x * y;
                }
                total += x * y;
            }
            begin = matches.suffix().first;
        }
    }

    file.close();
    std::cout << "Total sum of valid multiplications: " << total << std::endl;
    std::cout << "Total sum of valid multiplications with do and don't: " << total_v2 << std::endl;
    return 0;
}

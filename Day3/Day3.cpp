#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {

    int total = 0;
    int total_v2 = 0;
    bool enabled = 1;

    std::ifstream file("input3.txt");
    /*if (!file) {
        std::cerr << "Erreur d'ouverture du fichier." << std::endl;
        return 1;
    }*/
    //std::cout << "Fichier ouvert avec succès." << std::endl;

    //std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::regex pattern_do_dont(R"(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\))");
    std::string line;
    std::smatch matches;

    while (std::getline(file, line)) {
        //std::cout << "Ligne lue : " << line << std::endl; // DEBUG
        auto begin = line.cbegin();
        auto end = line.cend();
        //auto begin_v2 = begin;


        /*while (std::regex_search(begin, end, matches, pattern)) {
            //std::cout << "Détection : " << matches[0] << " (X=" << matches[1] << ", Y=" << matches[2] << ")" << std::endl;
            int x = std::stoi(matches[1].str());
            int y = std::stoi(matches[2].str());
            total += x * y;
            begin = matches.suffix().first; // continuer à chercher sur le reste de la ligne
        }
        while (std::regex_search(begin_v2, end, matches, pattern_do_dont)) {
            std::string instruction = matches[0];
            if (instruction == "do()") {
                enabled = 1;
            } else if (instruction == "don't()") {
                enabled = 0;
            } else if (matches[1].matched && matches[2].matched && enabled) {
                int x = std::stoi(matches[1]);
                int y = std::stoi(matches[2]);
                total_v2 += x * y;
            }
            begin_v2 = matches.suffix().first;
        }*/
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

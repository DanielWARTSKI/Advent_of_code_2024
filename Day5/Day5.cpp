#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>
#include <sstream>

int sum_dis_middle_pages = 0;
bool rules = 1;
std::map<int, std::vector<int>> rules_dic;

int main() {
    std::ifstream file("Advent_of_code_2024/Day5/input5.txt");
    std::regex pattern(R"((\d+)\|(\d+))");
    std::string line;
    std::smatch matches;
    while (std::getline(file, line)) {
        //std::cout << "Ligne lue : " << line << std::endl;
        auto begin = line.cbegin();
        auto end = line.cend();
        if (line.empty()){
            rules = 0;
            //std::cout << "I'm stuck" << std::endl;
            continue;
        }
        if (rules){
            //std::cout << "I'm here" << std::endl;
            while (std::regex_search(begin, end, matches, pattern)) {
                int x = std::stoi(matches[1]);
                int y = std::stoi(matches[2]);
                //std::cout << x << "|" << y << std::endl;
                rules_dic[x].emplace_back(y);
                begin = matches.suffix().first;
            }
        } else {
            //std::cout << "I'm Here" << std::endl;
            std::istringstream stream(line);
            std::string token;
            int value;
            std::vector<int> list = {};
            while (std::getline(stream, token, ',')) { // Read value by value in the line
                /*if (list.empty()){
                    continue;
                }*/
                int value = std::stoi(token);
                bool conflict = false;
                for (int i : list) {
                    for (int j : rules_dic[value]) {
                        if (i == j) {
                            conflict = true;
                            break;
                        }
                    }
                    if (conflict) break;
                }

                if (conflict) {
                    list.clear();
                    break; // rompe la lectura de esta línea si hay conflicto
                }
                //std::cout << value << " ";
                list.push_back(value);
            }
            /*for (int i : list){
                std::cout << i << " ";
            }
            std::cout << std::endl;*/
            if (list.empty()){
                continue;
            } else {
                int middle_value = list[list.size()/2];
                //std::cout << middle_value << " ";
                sum_dis_middle_pages += middle_value;
            }
        }
    }

    file.close();
    //std::cout << std::endl;


    std::cout << "Sum of middle pages: " << sum_dis_middle_pages << std::endl;
}
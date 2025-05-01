#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>

int main(){
    std::ifstream file("input2.txt");
    std::string line;
    int count_safe = 0;
    int count_really_safe = 0;
    while (std::getline(file, line)) { // Read line by line
        std::istringstream stream(line);
        double value;
        bool first_value = 1;
        int last_value = 0;
        bool Safe = 1;
        bool really_safe = 1;
        bool increasing = 0;
        bool decreasing = 0;
        while (stream >> value) { // Read value by value in the line
            if (first_value) {
                last_value = value;
                first_value = 0;
                continue;
            }
            
            if (last_value > value){
                decreasing = 1;
                if(last_value - value > 3 || increasing){
                    if (!Safe){
                        really_safe = 0;
                        break;
                    }
                    Safe = 0;
                    decreasing = 0;
                }
            } else if (last_value < value){
                increasing = 1;
                if(value - last_value > 3 || decreasing){
                    if (!Safe){
                        really_safe = 0;
                        break;
                    }
                    Safe = 0;
                    increasing = 0;
                }
            } else {
                if (!Safe){
                    really_safe = 0;
                    break;
                }
                Safe = 0;
            }
            last_value = value;
        }
        if (Safe){
            count_safe += 1;
        }
        if (really_safe){
            count_really_safe += 1;
        }
    }
    file.close();
    std::cout << "Reports that are safe: " << count_safe << std::endl;
    std::cout << "Reports that are really safe: " << count_really_safe << std::endl;

    return 0;
}

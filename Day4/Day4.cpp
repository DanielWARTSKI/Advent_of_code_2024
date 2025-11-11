#include <iostream>
#include <fstream>
#include <regex>
#include <string>


int main() {
    std::ifstream file("Advent_of_code_2024/Day4/input4.txt");
    std::vector<std::vector<char>> table;
    std::string line;
    std::vector <std::pair<int, int>> X_coord;
    std::vector <std::pair<int, int>> A_coord;
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    int Count_row = 0;
    int Count_XMAS = 0;
    int Count_X_MAS = 0;
    while (std::getline(file, line)) {
        int Count_col = 0;
        std::vector<char> row;
        for (char ch : line) {

            row.push_back(ch);
            if (ch == 'X'){
                X_coord.emplace_back(Count_row,Count_col);
            }
            if (ch == 'A'){
                A_coord.emplace_back(Count_row, Count_col);
            }
            Count_col +=1;
        }
        table.push_back(row);
        Count_row +=1;
    }

    file.close();
    size_t rows = table.size();
    size_t cols = table[0].size();
    std::cout << "rows: " << rows << " cols: " << cols << std::endl;

    for (std::pair<int, int> x_coord:X_coord){
        int i = x_coord.first;
        int j = x_coord.second;
        //std::cout << "i: " << i << " " << j << std::endl;
        for (std::pair<int, int> dir:directions){
            int di = dir.first;
            int dj = dir.second;
            if (i+3*di<0 || i+3*di>=rows || j+3*dj >= cols || j+3*dj < 0) {
                continue;
            }
            if (table[i+3*di][j+3*dj] == 'S' && table[i+2*di][j+2*dj] == 'A' && table[i+di][j+dj] == 'M'){
                Count_XMAS += 1;
            }
        }
    }
    std::cout << "Count of XMAS: " << Count_XMAS << std::endl;

    std::vector<std::pair<int, int>> directions_X_MAS = {
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    for (std::pair<int, int> a_coord:A_coord){
        int i = a_coord.first;
        int j = a_coord.second;
        if (i == 0 || i == rows-1 || j == 0 || j == cols-1){
            continue;
        }
        if (table[i-1][j-1] == 'M' && table[i+1][j+1]== 'S'){
            if (table[i+1][j-1] == 'M' && table[i-1][j+1]== 'S'){
                Count_X_MAS += 1;
            } else if (table[i+1][j-1] == 'S' && table[i-1][j+1]== 'M'){
                Count_X_MAS += 1;
            }
        } else if (table[i-1][j-1] == 'S' && table[i+1][j+1]== 'M'){
            if (table[i+1][j-1] == 'M' && table[i-1][j+1]== 'S'){
                Count_X_MAS += 1;
            } else if (table[i+1][j-1] == 'S' && table[i-1][j+1]== 'M'){
                Count_X_MAS += 1;
            }
        }
    }
    std::cout << "Count of X-MAS: " << Count_X_MAS << std::endl;



    return 0;
}

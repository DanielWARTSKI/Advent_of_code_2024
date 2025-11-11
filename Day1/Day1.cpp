#include <iostream>
#include <fstream>
#include <queue>

int distance = 0;

std::priority_queue<int, std::vector<int>, std::greater<int> > queue1;
std::priority_queue<int, std::vector<int>, std::greater<int> > queue2;

int main(){
    std::ifstream file("Advent_of_code_2024/Day1/input1.txt");

    int val1, val2;

    while (file >> val1 >> val2) {
        queue1.push(val1);
        queue2.push(val2);
    }
    file.close();
    std::priority_queue<int, std::vector<int>, std::greater<int> > queue1_bis = queue1;
    std::priority_queue<int, std::vector<int>, std::greater<int> > queue2_bis = queue2;


    // first half of the problem
    while (!queue1.empty()){
        distance += abs(queue1.top()-queue2.top());
        //std::cout << queue1.top() << " ";
        queue1.pop();
        queue2.pop();
    }
    std::cout << std::endl << "distance:" << distance << std::endl;

    //Second Half of the problem
    int similarity_score = 0;
    while (!queue1_bis.empty()){
        while (!queue2_bis.empty() && queue1_bis.top() >= queue2_bis.top()){
            if (queue1_bis.top() == queue2_bis.top()){
                similarity_score += queue1_bis.top();
            }
            queue2_bis.pop();
        }
        queue1_bis.pop();
    }
    std::cout << std::endl << "Similarity Score:" << similarity_score << std::endl;

    return 0;
}

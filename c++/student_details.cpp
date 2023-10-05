#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::ifstream inputFile("students.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    std::vector<Student> students;
    std::string name;
    int score;

    while (inputFile >> name >> score) {
        students.push_back({name, score});
    }

    inputFile.close();

    if (students.empty()) {
        std::cerr << "Error: No data found in the input file." << std::endl;
        return 1;
    }

    int totalScore = 0;
    for (const Student& student : students) {
        totalScore += student.score;
    }

    double averageScore = static_cast<double>(totalScore) / students.size();

    std::cout << "Average Score: " << averageScore << std::endl;
    std::cout << "Students with Scores Above Average:" << std::endl;

    for (const Student& student : students) {
        if (student.score > averageScore) {
            std::cout << student.name << " (" << student.score << ")" << std::endl;
        }
    }

    return 0;
}

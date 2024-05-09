#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

// Function to generate a frequency table for a given column index in a CSV file
void GenerateFrequencyTable(const std::string& file_name, size_t column_index) {
    std::ifstream file(file_name);

    std::unordered_map<std::string, int> frequency_table;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        size_t col_index = 0;
        while (std::getline(ss, cell, ',')) {
            if (col_index == column_index && !cell.empty()) {
                frequency_table[cell]++;
            }
            col_index++;
        }
    }

    file.close();

    // Output frequency table
    std::cout << "Frequency table for column " << column_index << ":" << std::endl;
    for (const auto& pair : frequency_table) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

//int main() {
//    GenerateFrequencyTable("titanic.csv", 2); // Generate frequency table for column 2 in input.csv
//}

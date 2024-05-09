#include <iostream>
#include <armadillo>
#include <vector>
#include <fstream>

using namespace std;

vector<int> Count_Null_Values_In_Columns(string file_name) {
    ifstream file(file_name);
    vector<int> null_counts;

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << file_name << endl;
        return null_counts; // Return an empty vector if file cannot be opened
    }

    string line;
    if (getline(file, line)) {
        stringstream header_ss(line);
        string cell;

        // Initialize null_counts vector with zeros
        while (getline(header_ss, cell, ',')) {
            null_counts.push_back(0);
        }

        // Read data rows and count null values
        while (getline(file, line)) {
            stringstream data_ss(line);
            size_t col_index = 0;
            while (getline(data_ss, cell, ',')) {
                // If the cell is empty, increment corresponding null count
                if (cell.empty()) {
                    null_counts[col_index]++;
                }
                col_index++;
            }
        }
    }

    file.close();
    return null_counts;
}


//int main() {
//    vector<int> null_counts = Count_Null_Values_In_Columns("titanic.csv");
//
//    for (size_t i = 0; i < null_counts.size(); ++i) {
//        cout << "Null values in Column " << i + 1 << ": " << null_counts[i] << std::endl;
//    }
//}
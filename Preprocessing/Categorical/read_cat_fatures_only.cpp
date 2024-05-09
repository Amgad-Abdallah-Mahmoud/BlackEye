#include <iostream>
#include <armadillo>
#include <vector>
#include <fstream>

using namespace std;

// Function to check if a string is numeric
bool isNumeric(const string& str) {
    for (char const& c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Function to load categorical columns from a CSV file into a matrix
vector<vector<string>> Load_CategoricalColumns(string file_name) {
    ifstream file(file_name);
    vector<vector<string>> categorical_columns;

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << file_name << endl;
        return categorical_columns; // Return an empty matrix if file cannot be opened
    }

    string line;

    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<string> row;

        // Split the line by comma and process each cell
        while (getline(ss, cell, ',')) {
            // Check if the cell is categorical (not numeric)
            if (!isNumeric(cell)) {
                // If the number of columns exceeds the number of columns already captured
                // Add new empty vectors to store the new categorical columns
                if (row.size() >= categorical_columns.size()) {
                    categorical_columns.push_back(vector<string>());
                }
                // Add the cell value to the corresponding categorical column
                categorical_columns[row.size()].push_back(cell);
            }
            row.push_back(cell); // Add the cell to the current row
        }
    }

    file.close(); // Close the file
    return categorical_columns;
}


//int main()
//{
//    vector<vector<string>> cat_cols;
//    cat_cols = Load_CategoricalColumns("titanic.csv");
//
//    // Display the loaded categorical columns
//    for (size_t i = 0; i < cat_cols.size(); ++i) {
//        cout << "Categorical Column " << i + 1 << ":" << endl;
//        for (auto& value : cat_cols[i]) {
//            cout << value << endl;
//        }
//        cout << endl;
//    }
//
//}


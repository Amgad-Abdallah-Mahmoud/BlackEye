#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <variant>

using namespace std;

// Function to count occurrences of each value in a specific column
unordered_map<string, int> Count_Column_Values(string file_name, size_t column_index) {
    ifstream file(file_name);

    unordered_map<string, int> column_value_counts;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        size_t col_index = 0;
        while (getline(ss, cell, ',')) {
            if (col_index == column_index && !cell.empty()) {
                column_value_counts[cell]++;
            }
            col_index++;
        }
    }

    file.close();
    return column_value_counts;
}

// Function to find the most frequent value in a specific column
string Most_Frequent_Value_In_Column(string file_name, size_t column_index) {
    // Count occurrences of each value in the specified column
    unordered_map<string, int> column_value_counts = Count_Column_Values(file_name, column_index);

    // Find the most frequent value
    string most_frequent_value;
    int max_count = 0;
    for (auto kv : column_value_counts) {
        if (kv.second > max_count) {
            max_count = kv.second;
            most_frequent_value = kv.first;
        }
    }

    return most_frequent_value;
}


vector<vector<variant<double, string>>> getdata(const string& filename, string &fre_val,char separator = ',', int headerlines = 0)
{
    // First pass: quick read to establish number of rows and columns
    ifstream in(filename);
    string line;
    getline(in, line);
    int nrows = 1;
    int ncols = count(line.begin(), line.end(), separator) + 2; // if separator present, count to get ncols
    while (getline(in, line))
        nrows++;
    nrows -= headerlines;

    // Second pass: set up a variant array and read directly into it (remember the headerlines)
    vector<vector<variant<double, string>>> result(nrows, vector<variant<double, string>>(ncols));
    in.close();
    in.open(filename);

    for (int i = 0; i < headerlines; i++)
        getline(in, line); // skip header lines

    for (int i = 0; i < nrows; i++) // ith row
    {
        string cell;
        getline(in, line);
        istringstream ss(line);
        for (int j = 0; j < ncols; j++) // jth column
        {
            getline(ss, cell, separator);
            try
            {
                // Try converting the cell to a double
                result[i][j] = stod(cell);
            }
            catch (const std::invalid_argument&)
            {
                // If conversion fails, store the cell as a string
                result[i][j] = cell;
                if (cell == "") {
                    result[i][j] = fre_val;
                }
            }
        }
    }

    return result;
}


//int main() {
//    // Example usage
//    string most_frequent_value = Most_Frequent_Value_In_Column("titanicmini.csv", 12);
//    cout << "Most frequent value in column: " << most_frequent_value << endl;
//
//    vector<vector<variant<double, string>>> data = getdata("titanicmini.csv", most_frequent_value);
//    for (const auto& row : data) {
//        for (const auto& cell : row) {
//            if (auto pval = get_if<double>(&cell)) {
//                cout << *pval << " ";
//            }
//            else if (auto pval = get_if<string>(&cell)) {
//                cout << *pval << " ";
//            }
//        }
//        cout << endl;
//    }
//
//   
//}
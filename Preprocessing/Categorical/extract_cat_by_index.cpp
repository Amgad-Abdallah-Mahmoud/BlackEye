//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//void selectColumns(const string& inputFile, const vector<int>& indices, const string& outputFile) {
//    ifstream fin(inputFile);
//    ofstream fout(outputFile);
//
//    string line;
//    while (getline(fin, line)) {
//        stringstream ss(line);
//        string cell;
//        int columnIndex = 0;
//        bool isFirstColumn = true;
//
//        while (getline(ss, cell, ',')) {
//            if (find(indices.begin(), indices.end(), columnIndex) != indices.end()) {
//                if (!isFirstColumn) {
//                    fout << ",";
//                }
//                fout << cell;
//                isFirstColumn = false;
//            }
//            columnIndex++;
//        }
//        fout << endl;
//    }
//
//    fin.close();
//    fout.close();
//}
//
//int main() {
//    string inputFile = "titanic_dropped_cols.csv"; // Change this to your input CSV file
//    string outputFile = "output.csv"; // Change this to your desired output CSV file
//    vector<int> selectedColumns = { 7 }; // Change these indices to select desired columns
//
//    selectColumns(inputFile, selectedColumns, outputFile);
//
//    cout << "Selected columns written to " << outputFile << endl;
//}

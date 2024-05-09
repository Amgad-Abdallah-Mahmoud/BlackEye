#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "gnuplot-iostream.h"

void GenerateFrequencyTable(const std::string& input_file, size_t column_index, const std::string& output_file) {
    std::ifstream input(input_file);
    std::ofstream output(output_file);

    std::unordered_map<std::string, int> frequency_table;

    std::string line;
    while (std::getline(input, line)) {
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

    input.close();

    // Write frequency table to output file without headers
    for (const auto& pair : frequency_table) {
        output << pair.first << "," << pair.second << "\n";
    }

    output.close();
}

/*
int main() {

    // for better results call the below function first, and then remove the headers from the file, comment the cunction and
    // run the rest of the code...we are just leaving this function without auto-deletion of the header for more generalibility.
    //GenerateFrequencyTable("titanic.csv", 2, "titanic_FT.csv"); 

    Gnuplot gp;
    gp << " set datafile separator ','\n";
        gp << "  stats 'titanic_FT.csv' u 2 noout\n";

        gp << "ang(x) = x * 360.0 / STATS_sum\n";
        gp << "perc(x) = x * 100.0 / STATS_sum\n";

        gp << "set size square\n";
        gp << "set xrange[-1:1.5]\n";
        gp << "set yrange[-1.25:1.25]\n";
        gp << "set style fill solid 1\n";

        gp << "unset border\n";
        gp << "unset tics\n";
        gp << "unset key\n";

        gp << "Ai = 0.0; Bi = 0.0;\n";
        gp << "mid = 0.0;\n";
        gp << "i = 0; j = 0;\n";
        //gp <<"set palette defined (1 0.961 0.690 0.255, 2 0.180 0.525 0.757)\n";
        gp << "yi = 0.0; yi2 = 0.0;\n";
        gp << "yi = 0.0; yi2 = 0.0;\n";


        gp << " plot 'titanic_FT.csv' u(0) :(0) : (1) : (Ai) : (Ai = Ai + ang($2)) : (i = i + 1) with circle linecolor var," <<
            //gp << " plot 'titanic_FT.csv' u(0) :(0) : (1) : (Ai) : (Ai = Ai + ang($2)) : (i = i + 1) with circle linecolor palette," <<

        "'titanic_FT.csv' u(1.5) :(yi = yi + 0.5 / STATS_records) : ($1)w labels, " <<
        "'titanic_FT.csv' u(1.3) :(yi2 = yi2 + 0.5 / STATS_records) : (j = j + 1) w p pt 5 ps 2 linecolor var, "
            //"'titanic_FT.csv' u(1.3) :(yi2 = yi2 + 0.5 / STATS_records) : (j = j + 1) w p pt 5 ps 2 linecolor palette, "

        "'titanic_FT.csv' u(mid = Bi + ang($2) * pi / 360.0, Bi = 2.0 * mid - Bi, 0.5 * cos(mid)) :(0.5 * sin(mid)) : (sprintf('%.0f (%.1f\%)', $2, perc($2))) w labels linecolor palette \n";
}

*/
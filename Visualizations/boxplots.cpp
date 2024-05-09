//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//#include <armadillo>
//#include <mlpack.hpp>
//#include "gnuplot-iostream.h"
//
//using namespace mlpack;
//using namespace mlpack::data;
//using namespace std;
//
//int main() {
//
//	arma::mat dataset;
//	mlpack::data::DatasetInfo info;
//	mlpack::data::Load("titanic.csv", dataset, info, true);
//
//
//	// Print information about the data.
//	std::cout << "The data has: " << std::endl;
//	std::cout << " - " << dataset.n_cols << " points." << std::endl;
//	std::cout << " - " << info.Dimensionality() << " dimensions." << std::endl;
//	//cout << "5 first cols: " << dataset.cols(0, 5);
//
//	arma::rowvec Y = dataset.row(9);
//	Gnuplot gp;
//
//	gp << "set style fill solid 5 border - 1\n";
//	gp << "set style boxplot outliers pointtype 7\n";
//	gp << "set style data boxplot\n";
//	gp << "set boxwidth  50\n";
//	gp << "set pointsize 5\n";
//	gp << "\n";
//	gp << "unset key\n";
//	gp << "set border 2\n";
//	gp << "set xtics('A' 1)\n";
//	gp << "set xtics nomirror\n";
//	gp << "set ytics nomirror\n";
//	gp << "set yrange[-20:200]\n";
//	gp << "\n";
//	gp << "plot '-'\n";
//	gp.send(Y);
//}
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
//		gp << "set boxwidth 0.95 absolute\n";
//		gp << "set style fill  solid 1.00 noborder\n";
//		gp << "set grid nopolar\n";
//		gp << "set grid noxtics nomxtics ytics nomytics noztics nomztics nortics nomrtics \\n";
//		gp << "set grid layerdefault   lt 0 linecolor 0 linewidth 0.500, lt 0 linecolor 0 linewidth 0.500\n";
//		gp << "set key bmargin center horizontal Right noreverse noenhanced autotitle columnhead nobox\n";
//		gp << "set key invert samplen 4 spacing 1 width 0 height 0\n";
//		gp << "set style histogram clustered gap 1 title textcolor lt - 1 font '11' offset character 2, -2\n";
//		gp << "set datafile missing '-'\n";
//		gp << "set style data histograms\n";
//		gp << "set xtics border in scale 1, 0.5 mirror rotate by - 45  autojustify\n";
//		gp << "set xtics  norangelimit\n";
//		gp << "set xtics()\n";
//		gp << "NO_ANIMATION = 1\n";
//		gp << "plot '-'\n";
//
//		gp.send(Y);
//}
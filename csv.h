/*---------------------------------------------
# CSVReader is for data loading before applying machine learning algrithm.
# so we assume that the data format is: rows*cols
# use CSVReader to convert csv file into eigen matrix
---------------------------------------------*/



#ifndef __CSV_H__
#define __CSV_H__

#include<fstream>
#include<string>
#include<array>
#include<sstream>
#include<eigen3/Eigen/Dense>

namespace csv{

typedef std::array<int,2> matrix_size;

class CSVReader
{
private:
	std::ifstream csv_ifs;
	Eigen::MatrixXd mat;
	int mat_rows,mat_cols;
	Eigen::MatrixXd cvt2mat();
	
public:
	CSVReader(std::string filename);
	~CSVReader();
	int rows();
	int cols();
	matrix_size size();
	Eigen::MatrixXd get_mat();  //template implement, detect data type as the return type
	Eigen::VectorXd get_row(int n_row);
	Eigen::VectorXd get_col(int n_col);
	double get_element(int n_row,int n_col);	
};


class CSVWriter
{
private:
	Eigen::MatrixXd mat;


public:
	CSVWriter(Eigen::MatrixXd);
	CSVWriter(Eigen::VectorXd);
	~CSVWriter();
	void write(std::string filename);
};
	
	
}  //namespace csv


#endif
#include<iostream>
#include "csv.h"

namespace csv{
	

/***********************
*****CSVReader define
************************/

CSVReader::CSVReader(std::string filename){
	csv_ifs.open(filename,std::ifstream::in);
	//check if file is open
	if(!csv_ifs.is_open()){
		std::cerr<<"Can not open the file."<<std::endl;
		exit(1);
	}
	
	//initial rows and columns
	mat_rows = rows();
	mat_cols = cols();
	
	//initial mat. convert csv to eigen matrix
	mat = cvt2mat();
}

int CSVReader::rows(){
	csv_ifs.clear();
	csv_ifs.seekg(0,std::ios::beg);
	
	int res=0;
	std::string line;
	while(std::getline(csv_ifs,line)){
		res++;
	}
	
	return res;
}

int CSVReader::cols(){
	csv_ifs.clear();
	csv_ifs.seekg(0,std::ios::beg);
	
	int res=0;
	std::string line;
	std::getline(csv_ifs,line);
	std::stringstream ss(line);
	std::string temp;
	while(std::getline(ss,temp,',')){
		res++;
	}
	return res;
}

Eigen::MatrixXd CSVReader::cvt2mat(){
	csv_ifs.clear();
	csv_ifs.seekg(0,std::ios::beg);
	
	Eigen::MatrixXd ret_mat(mat_rows,mat_cols);
	std::string line;
	int i = 0;
	while(std::getline(csv_ifs,line)){
		int j = 0;
		std::stringstream ss(line);
		std::string digit;
		while(std::getline(ss,digit,',')){
			ret_mat(i,j) = stod(digit);
			j++;
		}
		i++;
	}
	return ret_mat;
}

matrix_size CSVReader::size(){
	matrix_size res;
	res[0] = mat_rows;
	res[1] = mat_cols;
	return res;
}

Eigen::MatrixXd CSVReader::get_mat(){
	return mat;
}

Eigen::VectorXd CSVReader::get_row(int n_row){
	if(n_row+1 > mat_rows){
		std::cerr<<"ERROR: index out of bounds when calling get_row(int n_row)"<<std::endl;
		exit(1);
	}
	return mat.row(n_row);
}

Eigen::VectorXd CSVReader::get_col(int n_col){
	if(n_col+1 > mat_cols){
		std::cerr<<"ERROR: index out of bounds when calling get_col(int n_col)"<<std::endl;
		exit(1);
	}
	return mat.col(n_col);
}


double CSVReader::get_element(int n_row,int n_col){
	if(n_col+1 > mat_cols || n_row+1 > mat_rows){
		std::cerr<<"ERROR: index out of bounds when calling get_element(int n_row,int n_col)"<<std::endl;
		exit(1);
	}
	return mat(n_row,n_col);
}

CSVReader::~CSVReader(){
	csv_ifs.close();
}

	
/***********************
*****CSVWriter define
************************/
	
	
	
}//namespace csv

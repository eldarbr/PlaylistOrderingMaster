#pragma once


class DataHandler {

private:

	int ammount;

	double** data;					// 4 int*
								// [n]	 y	 array
								// [n-1] y'	 array
								// [n-2] y'' array
								// [n-3] y'''array

	void calculateDerivatives(const int stage);

public:

	DataHandler(const double* yValues, const int ammount);
								// save input

	~DataHandler();

	double** getData();

	int getAmmount();

};

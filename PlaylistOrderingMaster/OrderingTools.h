#pragma once



//////////////////////////////////////////////////////////
//														//
//					class DataHandler					//
//					start of declaration				//
//														//


class DataHandler {

private:

	int ammount;

	double** data;				// 4 int*
								// [n]	 y	 array
								// [n-1] y'	 array
								// [n-2] y'' array
								// [n-3] y'''array

	void calculateDerivatives( const int stage );

public:

	DataHandler( const double* yValues, const int ammount );
								// save input

	~DataHandler();

	double** getData() const;

	int getAmmount() const;

};


//														//
//					class DataHandler					//
//					end of declaration					//
//														//
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//														//
//					class Analisys						//
//					start of declaration				//
//														//


class Analisys {

public:

	static double calculateVariance( const double* data,
										const int ammount );

	static double calculateAverage( const double* data,
										const int ammount );

};


//														//
//					class Analisys						//
//					end of declaration					//
//														//
//////////////////////////////////////////////////////////





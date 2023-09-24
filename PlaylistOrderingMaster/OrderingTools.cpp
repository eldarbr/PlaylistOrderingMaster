#include <stdexcept>
#include "OrderingTools.h"



//////////////////////////////////////////////////////////
//														//
//					class DataHandler					//
//					start of definition					//
//														//


DataHandler::DataHandler( const double* yValues, const int ammount ) {


	if ( ammount < 3 ) {

		throw std::invalid_argument( "ammount is not valid" );
	}

	this->ammount = ammount;

	this->data = new double*[4];

	this->data[0] = new double[this->ammount];
	this->data[1] = new double[this->ammount-1];
	this->data[2] = new double[this->ammount-2];
	this->data[3] = new double[this->ammount-3];


	for ( int i = 0; i < this->ammount; i++ ) {

		data[0][i] = yValues[i];
	}

	calculateDerivatives(0);

}

DataHandler::~DataHandler() {

    for( int i = 0; i < 3; i++ ) {
		delete[] data[i];
	}
	delete[] data;
}

void DataHandler::calculateDerivatives(const int stage) {

	// calculate the derivative for this stage
	for ( int i = 0; i < ammount-stage-1; i++ ) {

		this->data[stage+1][i] = this->data[stage][i+1] - this->data[stage][i];
	}

	// if there is still stages to calculate
	if ( stage!=2 ) {

		calculateDerivatives(stage+1);
	}
	
}

double** DataHandler::getData() const {

	return this->data;

}

int DataHandler::getAmmount() const {

	return this->ammount;

}


//														//
//					class DataHandler					//
//					end of definition					//
//														//
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//														//
//					class Analisys						//
//					start of definition					//
//														//


double Analisys::calculateVariance( const double* data,
									const int ammount ) {

	double average = calculateAverage( data, ammount );

	double variance = 0;

	for ( int i = 0; i < ammount; i++ ) {

		double diff = data[i] - average;
		variance += diff*diff;
	}

	return variance;
}

double Analisys::calculateAverage( const double* data,
									const int ammount ) {

	double sum = 0;

	for ( int i = 0; i < ammount; i++ ) {

		sum += data[i];
	}

	return sum / ammount;
}


//														//
//					class Analisys						//
//					end of definition					//
//														//
//////////////////////////////////////////////////////////




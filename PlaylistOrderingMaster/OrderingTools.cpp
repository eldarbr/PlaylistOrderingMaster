#include <stdexcept>
#include "OrderingTools.h"



//////////////////////////////////////////////////////////
//														//
//					class DataHandler					//
//					start of definition					//
//														//
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

    for(int i = 0; i < 4; ++i) {
		delete[] data[i];
	}
	delete[] data;
}

void DataHandler::calculateDerivatives(const int stage) {

	// calculate the derivative for this stage
	for ( int i = 0; i < ammount-stage; i++ ) {

		this->data[1+stage][i] = this->data[stage][i+1] - this->data[stage][i];

	}


	// if there is still stages to calculate
	if (stage!=2) {

		calculateDerivatives(stage+1);

	}
	
}

double** DataHandler::getData() {

	return this->data;

}

int DataHandler::getAmmount() {

	return this->ammount;

}


//														//
//					class DataHandler					//
//					end of definition					//
//														//
//														//
//////////////////////////////////////////////////////////

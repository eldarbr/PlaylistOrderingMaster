#include "IOInterfaces.h"
#include <fstream>
#include <stdexcept>



//////////////////////////////////////////////////////////
//														//
//					class File							//
//					start of declaration				//
//														//


io::File::File( std::string filePath ): filePath( filePath ) {

	this->data = nullptr;
	this->dataLength = 0;
}

io::File::~File() {

	delete[] this->data;
}

void io::File::readValues() {

	if ( this->data != nullptr ) {

		throw std::logic_error( "The file was already read" );
	}

	std::ifstream stream;
	stream.open( this->filePath );
	if ( stream.eof() || stream.fail() ) {

		throw std::runtime_error( "File error: "+ this->filePath );
	}

	stream >> this->dataLength;
	if ( this->dataLength < 1 ) {

		throw std::logic_error( "Low ammount of data in the file" );
	}

	this->data = new double[this->dataLength];
	for ( int i = 0; i < this->dataLength; i++ ) {

		if ( stream.eof() ) {

			throw std::runtime_error( "The file ended earlier than expected" );
		}

		stream >> this->data[i];
	}

	stream.close();
}

int io::File::getDataLength() const {

	return this->dataLength;
}

double* io::File::getData() const {

	return this->data;
}


//														//
//					class File							//
//					end of declaration					//
//														//
//////////////////////////////////////////////////////////


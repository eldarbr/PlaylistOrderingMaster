#include <iostream>
#include "OrderingTools.h"
#include "Visualisations.h"
#include "IOInterfaces.h"


int main() {
	
	io::File file = io::File( "inpData.txt" );
	file.readValues();

	double* data = file.getData();
	int dataLength = file.getDataLength();

	DataHandler pp = DataHandler( data, dataLength );

	vis::TableView::outputDataTable( pp.getData(), pp.getAmmount() );

	std::cout << std::endl <<
	Analisys::calculateVariance( pp.getData()[3], pp.getAmmount()-3 ) << std::endl;

	vis::GraphView().outputDataGraph(pp.getData()[0], pp.getAmmount(), 300, 100);

	return 0;
}

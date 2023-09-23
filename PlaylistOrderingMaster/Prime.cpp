#include "OrderingTools.h"
#include "Visualisations.h"


int main() {

	double data[] = { 2.5, 2.75, 3.2, 3.65, 3.9 };

	DataHandler* pp = new DataHandler(data, 5);

	vis::TableView::outputDataTable(pp->getData(), pp->getAmmount());

	delete pp;

	return 0;
}

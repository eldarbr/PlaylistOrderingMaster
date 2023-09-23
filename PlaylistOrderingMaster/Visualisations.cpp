#include "Visualisations.h"



//////////////////////////////////////////////////////////
//														//
//					class TableView						//
//					start of definition					//
//														//
//														//


void vis::TableView::outputDataTable( double** data, int ammount ) {

		std::cout.precision(3);
		std::cout << std::fixed;
		

		for ( int i = 0; i < ammount; i++ ) {

			// output y value
			std::cout << data[0][i];

			// output y' value
			if ( i < ammount-1 ) {
				
				std::cout << "\t"
				<< data[1][i];
			}

			// output y'' value
			if ( i < ammount-2 ) {
				
				std::cout << "\t"
				<< data[2][i];
			}

			// output y''' value
			if ( i < ammount-3 ) {

				std::cout << "\t"
				<< data[3][i];
			}

			std::cout << std::endl;
		}
}


//														//
//					class TableView						//
//					end of definition					//
//														//
//														//
//////////////////////////////////////////////////////////

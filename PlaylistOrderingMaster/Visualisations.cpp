#include "Visualisations.h"
#include <Windows.h>
#include <stdexcept>



//////////////////////////////////////////////////////////
//														//
//					class TableView						//
//					start of definition					//
//														//


void vis::TableView::outputDataTable( const double*const* data,
										const int ammount ) {
	
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
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//														//
//					class GraphView						//
//					start of definition					//
//														//


vis::GraphView::GraphView() {

	getHWND();
}

vis::GraphView::~GraphView() {

}

void vis::GraphView::getHWND() {

	
	char str[128];
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str));
	SetConsoleTitle(title);
	Sleep(50);

	HWND hwnd = FindWindow(NULL, (LPWSTR)title);
	SetConsoleTitle((LPWSTR)str);
	
	if ( hwnd == NULL ) {

		throw std::runtime_error( "unable to get console window" );
	}

	console = hwnd;
}

void vis::GraphView::outputDataGraph( const double* data,
										const int ammount,
										const int startY,
										const int maxHeight ) {

	HDC hdc = GetDC(console);

	// prepare colour and column widths
	byte r=128,g=56,b=0;
	int spacing = 2;
	int columnWidth = 800 / ammount - 1;
	if ( columnWidth > 7 ) {
		columnWidth = 7;
	}
	if ( columnWidth < 1 ) {
		columnWidth = 1;
		spacing = 0;
	}
	// end of preparation of colour and column widths


	// searching minimum and maximum
	double minValue = 999999, maxValue=-999999;

	for ( int i = 0; i < ammount; i++ ) {

		if ( data[i] > maxValue ) {
			maxValue = data[i];
		}
		if ( data[i] < minValue ) {
			minValue = data[i];
		}
	}
	// end of searching minimum and maximum


	// scaling factor calculation
	double k = (maxHeight - 3) / (maxValue - minValue);
	double c = 3 - minValue * k;
	// end of the calculation of the factor


	// draw columns
	HBRUSH hBrush1 = CreateSolidBrush(RGB(r, g, b));
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(r, g, b));
	SelectObject(hdc, hBrush1);
	SelectObject(hdc, hPen);

	for ( int i = 0; i < ammount; i++ ) {

		int columnHeight = data[i] * k + c;

		Rectangle(hdc, 10+(columnWidth+spacing)*i, startY+maxHeight,
				10+(columnWidth+spacing)*i+columnWidth, startY+maxHeight-columnHeight);

	}

	SelectObject(hdc, GetStockObject(NULL_PEN));
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	DeleteObject(hBrush1);
	DeleteObject(hPen);
	// end of draw columns




	ReleaseDC(console, hdc);
}


//														//
//					class GraphView						//
//					end of definition					//
//														//
//////////////////////////////////////////////////////////

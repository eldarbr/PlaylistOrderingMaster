#pragma once

#include <iostream>
#include <Windows.h>
#include "OrderingTools.h"



// namespace vis
namespace vis {



	//////////////////////////////////////////////////////////
	//														//
	//					class TableView						//
	//					start of declaration				//
	//														//


	class TableView {

	public:

		static void outputDataTable( const double*const* data,
										const int ammount );

	};


	//														//
	//					class TableView						//
	//					end of declaration					//
	//														//
	//////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////
	//														//
	//					class GraphView						//
	//					start of declaration				//
	//														//


	class GraphView {

	private:
		HWND console;

		void getHWND();

	public:

		GraphView();
		~GraphView();

		void outputDataGraph( const double* data,
								const int ammount,
								const int startY,
								const int maxHeight );

	};


	//														//
	//					class GraphView						//
	//					end of declaration					//
	//														//
	//////////////////////////////////////////////////////////



} // end of the namespace vis

#pragma once
#include <string>



// namespace io
namespace io {



	//////////////////////////////////////////////////////////
	//														//
	//					class File							//
	//					start of declaration				//
	//														//

	class File {

		private:

			const std::string filePath;

			int dataLength;
			double* data;
			
		public:

			File( std::string filePath );
			~File();

			void readValues();

			int getDataLength() const;

			double* getData() const;

	};

	//														//
	//					class File							//
	//					end of declaration					//
	//														//
	//////////////////////////////////////////////////////////




}; // end of the namespace io

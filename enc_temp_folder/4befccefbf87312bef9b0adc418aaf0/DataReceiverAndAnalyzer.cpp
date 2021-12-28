#include "DataReceiverAndAnalyzer.h"


void DataReceiverAndAnalyzer::ReadData(HANDLE hcomm, char* SerialBuffer[]) {

	Read_Status = SetCommMask(hcomm, EV_RXCHAR);
	if (Read_Status == FALSE) {
		cout << "\n\n Error! in Setting CommMask";
	}
	else {
		cout << "\n\n  Setting CommMask successfull";
	}

	cout << "Waiting for Data Receiption";

	Read_Status = WaitCommEvent(hcomm, &dwEventMask, NULL);


	if (Read_Status == FALSE) {

		cout << "\n Error in WaitCommEvent";
	}

	else {

		cout << "\n Characters Received";

		do
		{
			//Read_Status = ReadFile(hComm, &TempChar, sizeof(TempChar), &NoBytesRead, NULL);
			if (!ReadFile(hcomm, SerialBuffer, BUFFER_LENGTH, &noBytesRead, NULL))
			{
				cout << "wrong character";
			}

		} while (noBytesRead > 0);


		cout << "\n\n" << *SerialBuffer[0];


		

	}


}
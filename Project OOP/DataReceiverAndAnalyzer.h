#ifndef DATA_RECEIVER_AND_ANALYZER_H
#define DATA_RECEIVER_AND_ANALYZER_H

#include <windows.h>
#include <iostream>

#define BUFFER_LENGTH 250

using namespace std;

class DataReceiverAndAnalyzer
{
private:
	BOOL Read_Status;
	DWORD dwEventMask;
	DWORD noBytesRead;
	

public:
	void ReadData(HANDLE hcomm);





};



#endif 




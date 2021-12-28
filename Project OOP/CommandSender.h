
#ifndef COMMAND_SENDER_H
#define COMMAND_SENDER_H
#include <windows.h>
#include <iostream>

using namespace std;

class CommandSender
{
private:

	DWORD  NumWritten;
	DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
	DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port
	BOOL Write_Status;
	
	

public:
	void WriteData(char* data, HANDLE hcomm , const char* pcCommPort, DCB dcbSerialParams);

};



#endif 



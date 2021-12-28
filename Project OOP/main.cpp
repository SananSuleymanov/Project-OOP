// Project OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <iostream>
#include <conio.h>

#include "CommandSender.h"
#include "KeyboardReceiver.h"
#include "DataReceiverAndAnalyzer.h"

#define    BUFFERLENGTH 250

using namespace std;


HANDLE hComm;
DWORD MORO;
const char* pcCommPort = "COM1";
BOOL Write_Status;
DCB dcbSerialParams;					// Initializing DCB structure
COMMTIMEOUTS timeouts = { 0 };
BOOL  Read_Status;                      // Status of the various operations 
DWORD dwEventMask;						// Event mask to trigger
						// Temperory Character
char* SerialBuffer[BUFFERLENGTH + 1];               // Buffer Containing Rxed Data
DWORD NoBytesRead;                     // Bytes read by ReadFile()

int main(int argc, char* argv[])

{


	cout<<"\n\n +==========================================+";
	cout<<"\n |  Serial Transmission (Win32 API)         |";
	cout<<"\n +==========================================+\n";

	hComm = CreateFileA(pcCommPort,
		GENERIC_READ | GENERIC_WRITE,
		0,    // must be opened with exclusive-access
		NULL, // no security attributes
		OPEN_EXISTING, // must use OPEN_EXISTING
		0,    // not overlapped I/O
		NULL  // hTemplate must be NULL for comm devices
	);

	if (hComm == INVALID_HANDLE_VALUE)
	{

		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			puts("cannot open port!");
			
		}

		puts("invalid handle value!");
		
	}
	else
		cout<<"opening serial port successful";

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	Write_Status = GetCommState(hComm, &dcbSerialParams);     //retreives  the current settings

	if (Write_Status == FALSE) {
		cout<<"\n   Error! in GetCommState()";
		CloseHandle(hComm);
		
	}


	dcbSerialParams.BaudRate = CBR_9600;      // Setting BaudRate = 9600
	dcbSerialParams.ByteSize = 8;             // Setting ByteSize = 8
											  //dcbSerialParams.
	dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1
	dcbSerialParams.Parity = ODDPARITY;      // Setting Parity = None

	Write_Status = SetCommState(hComm, &dcbSerialParams);  //Configuring the port according to settings in DCB

	if (Write_Status == FALSE)
	{
		cout<<"\n   Error! in Setting DCB Structure";
		CloseHandle(hComm);
		
	}
	else
	{
		cout<<"\n   Setting DCB Structure Successful\n";
		cout<<"\n       Baudrate = "<< dcbSerialParams.BaudRate;
		cout<<"\n       ByteSize = "<< dcbSerialParams.ByteSize;
		cout<<"\n       StopBits = "<< dcbSerialParams.StopBits;
		cout<<"\n       Parity   = "<< dcbSerialParams.Parity;
	}

	// Set COM port timeout settings
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;


	if (SetCommTimeouts(hComm, &timeouts) == 0)
	{
		cout<<"Error setting timeouts\n";
		CloseHandle(hComm);
		return 1;

	}

	while (true) {
		KeyboardReceiver key_command;
		key_command.CommandReceive();
		CommandSender command1;
		command1.WriteData(key_command.command, hComm, pcCommPort, dcbSerialParams);
		DataReceiverAndAnalyzer data;
		data.ReadData(hComm, SerialBuffer);

	}

	
	return 0;

}
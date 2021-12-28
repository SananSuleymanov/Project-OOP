#include "CommandSender.h"

const char* commands[6] = { "start", "stop", "break", "exit", "continue", "coursework"};

void CommandSender::WriteData(char data[], HANDLE hcomm, const char* pcCommPort, DCB dcbSerialParams) {

	string k;
	int size = (strlen(data)+3)*2;
	wchar_t sendCommand[50];
	sendCommand[0] = size;
	sendCommand[1] = 0;
	sendCommand[strlen(data)+2] = 0;
	for (int i = 2; i < strlen(data)+2; i++) {
		sendCommand[i] = data[i - 2];

	}

	

	cout << sendCommand;

	Write_Status = SetCommState(hcomm, &dcbSerialParams);



	dNoOFBytestoWrite = size;


	if (!WriteFile(hcomm, sendCommand, dNoOFBytestoWrite, &dNoOFBytestoWrite, NULL)) {

		cout << "Error writing text to \n" << pcCommPort;


	}

	else {

		cout << "\n bytes written to \n" << pcCommPort;
	}


	if (Write_Status == TRUE)
	{
		cout << data << " written to " << pcCommPort;
	}
	else {

		cout << "\n Error in writing to serial port" << GetLastError();
	}
	


	




}

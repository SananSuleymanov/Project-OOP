
#include "KeyboardReceiver.h"



void KeyboardReceiver::CommandReceive() {
	cout << "Enter command: ";
    cin.getline(command, COMMAND_LENGTH) ;

	
    
}

int KeyboardReceiver::commandleng() {


	int kom = strlen(command);


	return kom;

}


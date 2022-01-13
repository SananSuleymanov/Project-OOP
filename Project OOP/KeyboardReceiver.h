

#ifndef KEYBOARD_RECEIVER_H
#define KEYBOARD_RECEIVER_H

#include <iostream>
#include <string.h>

#define COMMAND_LENGTH 40
using namespace std;


class KeyboardReceiver
{
public:
	char command[COMMAND_LENGTH];
	void CommandReceive();
	int commandleng();
	


};



#endif




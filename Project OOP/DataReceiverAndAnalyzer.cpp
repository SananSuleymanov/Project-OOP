#include "DataReceiverAndAnalyzer.h"
#include "KeyboardReceiver.h"
#include <string.h>

const int BUFFERLENGTH = 280;

int value;

void DataReceiverAndAnalyzer::ReadData(HANDLE hcomm) {
	char SerialBuffer[BUFFERLENGTH];

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


		cout << "\n Characters Received\n";

		do
		{
			//Read_Status = ReadFile(hComm, &TempChar, sizeof(TempChar), &NoBytesRead, NULL);
			if (!ReadFile(hcomm, SerialBuffer, BUFFERLENGTH, &noBytesRead, NULL))
			{
				cout << "wrong character";
			}

		} while (noBytesRead > 0);

		string receivedData;

	

		int i;
		char array[8];
		double temp_val;
		double pres_val;
		int lev_val;
		double com_i_pres_val;
		double out_pres_val;
		double het_intemp_val;
		double out_temp_val;
		int ac_con_out;
		for (i = 0; i < BUFFERLENGTH; i++) {
			if (SerialBuffer[i] != 0) {

			
				
				//if (i >= 61 && i <= 68) {
					
					//array[i - 61] = SerialBuffer[i];
					

				//}

				
				//cout << SerialBuffer[i];
			    //receivedData.push_back(SerialBuffer[i]); // sting = string + "data read"
				
			}
		}
		//void* memcpy(void* dest, const void* src, std::size_t count);
	

		KeyboardReceiver key_command;

		cout << key_command.command;
		int j = 0;
		
		if (!strcmp(key_command.command, "Start") ){
			cout << "Ss";
			j=j+1;

				if (j == 1) {
					cout << "Reactor: \n";
					memcpy(&temp_val, &SerialBuffer[54], sizeof(double));
					cout << "Temperature: " << temp_val << "\n";
					memcpy(&pres_val, &SerialBuffer[71], sizeof(double));
					cout << "Pressure: " << pres_val << "\n";
					memcpy(&lev_val, &SerialBuffer[85], sizeof(int));
					cout << "Level: " << lev_val << "\n";

					memcpy(&com_i_pres_val, &SerialBuffer[119], sizeof(double));
					cout << "Compressor input pressure: " << com_i_pres_val << "\n";

					memcpy(&out_pres_val, &SerialBuffer[143], sizeof(double));
					cout << "Output pressure: " << out_pres_val << "\n";

					memcpy(&het_intemp_val, &SerialBuffer[180], sizeof(double));
					cout << "Heater input temperature: " << het_intemp_val << "\n";

					memcpy(&out_temp_val, &SerialBuffer[207], sizeof(double));
					cout << "Output temperature: " << out_temp_val << "\n";

					cout << "Separator: " << "\n";
					memcpy(&ac_con_out, &SerialBuffer[258], sizeof(int));
					cout << "Acid concentration on output: " << ac_con_out << "\n";

				}
		}
		
			
		
	
		


		
		

	}

}
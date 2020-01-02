
#include "pisco.h"
using namespace std;
using namespace pisco;

int main (int argc, char *argv[]) {
	
	
	gotoXY(0,0);
	cout<<" A, Q, W have events"<<endl;
	
	// Register the Q
	pisco::registerKey('Q');
	// Set 1000 ms of buffer, by default 100 ms
	pisco::setKeyTimeBuffer(1000,'Q');
	// Register the Q
	pisco::registerKey('A');
	// Register the W
	pisco::registerKey('W');
	pisco::setKeyTimeBuffer(1000,'W');
	
	
	int q_cont = 0;
	int a_cont = 0;
	bool flag = true;
	
	while(flag){
		if(pisco::isKeyPressed('Q')){
			gotoXY(10,10);
			setColor(P_LRED);
			cout<<"Q "<<q_cont++<<endl;
		}
		if(pisco::isKeyPressed('A')){
			gotoXY(20,20);
			setColor(P_YELLOW);
			printXY(20,20,"The A key ",P_YELLOW);
			cout<<a_cont++;
		}
		if(pisco::isKeyPressed('W')){
			setColor(P_PURPLE);
				unregisterKey('A');
				gotoXY(25,25);
				cout<<"'A' key was unregistered";

		}
			
	}

	return 0;
	
	
}


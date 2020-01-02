
#include "pisco.h"
using namespace std;
using namespace pisco;

int main (int argc, char *argv[]) {
	
	pisco::registerKey('Q');
	pisco::setKeyTimeBuffer(1000,'Q');
	pisco::registerKey('A');
	
	bool bandera = true;
	while(bandera){
		if(isKeyPressed('Q')){
			cout<<"la q"<<endl;
		}
		if(isKeyPressed('A')){
			cout<<"la a"<<endl;
		}
		
	}
	
	
	
	return 0;
	
	
}


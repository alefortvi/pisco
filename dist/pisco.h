#ifndef PISCO_H
#define PISCO_H

#include <ctime>
#include <list>
#include<windows.h>
#include <iostream>
#include <climits>

using namespace std;

namespace pisco{

	/**
	* COLORS const. From 0 to 15
	* @author Ake
	*/
	
	
#define P_BLUE 1
#define P_GREEN 2
#define P_CYAN 3
#define P_RED 4
#define P_PURPLE 5
#define P_YELLOW 6
#define P_WHITE 7
#define P_GREY 8
#define P_LBLUE 9
#define P_LGREEN 10
#define P_LCYAN 11
#define P_LRED 12
#define P_MAGENTA 13
#define P_YELLOW 14
#define P_LWHITE 15
	
	///////////////////////////////////////////////////////////////////////
	/** /////////////////////////////////////////////////////////////// **/
	/** ////////////           Definitions                 //////////// **/ 
	/** /////////////////////////////////////////////////////////////// **/
	///////////////////////////////////////////////////////////////////////
	
	
	///////////////////////////////////////////////////////////////////////
	/** ////////////             Screen module             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	/// Set color of the cursor screen
	/// @brief setColor
	/// @param value of color 
	/////////////////////////////////////////////////////////////////////////
	void setColor(int value);
	
	///////////////////////////////////////////////////////////////////////
	/// Set color of the cursor screen
	/// @brief gotoXY
	/// @param column. Y coordinate
	/// @param line. X coordinate
	/////////////////////////////////////////////////////////////////////////
	void gotoXY( int column, int line );
	
	///////////////////////////////////////////////////////////////////////
	/// print in the position XY the custom text in the custom color
	/// @brief printXY
	/// @param column. Y coordinate
	/// @param line. X coordinate
	/// @param str. string input
	/// @param color. color input
	/////////////////////////////////////////////////////////////////////////
	void printXY( int column, int line, std::string str, int color);
	
	
	///////////////////////////////////////////////////////////////////////
	/** ////////////             Time module             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	/// Make a puase
	/// @brief delay
	/// @param ms. Miliseconds to pause
	/////////////////////////////////////////////////////////////////////////
	void delay(int);
	
	///////////////////////////////////////////////////////////////////////
	/** ////////////             Key module             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	/// register the key which will be readed for the control
	/// @brief registerKey
	/// @param VK_key see https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	/////////////////////////////////////////////////////////////////////////
	void registerKey(int registeredKey);
	
	///////////////////////////////////////////////////////////////////////
	/// unregister the key
	/// @brief unregisterKey
	/// @param VK_key see https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	/////////////////////////////////////////////////////////////////////////
	int unregisterKey(int registeredKey);
	
	///////////////////////////////////////////////////////////////////////
	/// Set the time buffer to the all key
	/// @brief setKeyTimeBuffer
	/// @param timeBuffer time buffer
	/////////////////////////////////////////////////////////////////////////
	int setTimeBuffer(int timeBuffer);
	
	///////////////////////////////////////////////////////////////////////
	/// Set the time buffer to the selected key
	/// @brief setKeyTimeBuffer
	/// @param timeBuffer time buffer
	/// @param key
	/////////////////////////////////////////////////////////////////////////
	int setKeyTimeBuffer(int timeBuffer, char key);
	
	///////////////////////////////////////////////////////////////////////
	/// iterate on all the registered key and return true false if is it pressed in time
	/// @brief isKeyPressed
	/// @param ms. Miliseconds to pause
	/////////////////////////////////////////////////////////////////////////
	
	bool isKeyPressed(int key);
	
	//////////////////////////////////////////////////////////////////////
	/** ////////////             Sub namespace             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	namespace _{
		
		class keyPisco {
			private:
				int keyTimeBuffer;  // buffer de control de teclas ms
				bool keyPristime;
				int keyCurrent;
				clock_t keyLastTimePressed;  //variable para ajustar la velocidad de movimiento de la pelotita
				int key;
			protected:
			public:
				keyPisco(int);
				~keyPisco();
				
				int getKeyTimeBuffer(){return keyTimeBuffer;}
				void setKeyTimeBuffer(int kb){keyTimeBuffer = kb;}
				
				int getKeyPristime(){return keyPristime;}
				void setKeyPristime(int kp){keyPristime = kp;}
				
				clock_t getKeyLastTimePressed(){return keyLastTimePressed;}
				void setKeyLastTimePressed(clock_t kp){keyLastTimePressed = kp;}
				
				int getKey(){return key;}
				int getKeyChar(){return (char)key;}
			};
		
		
		
		keyPisco::keyPisco(int keyP) {
			key = keyP;
			keyTimeBuffer = 100;
			keyPristime = true;
			//int keyCurrent = INT_MAX;
			clock_t keyLastTimePressed = -1; 
		}
		
		keyPisco::~keyPisco() {
			
		}
		
		///////////////////////////////////////////////////////////////////////
		/** ////////////           Elements           //////////// **/ 
		///////////////////////////////////////////////////////////////////////
		
		list <keyPisco*> keyList;
		int keyCurrent = INT_MAX;

		
		
	}
	
	
	///////////////////////////////////////////////////////////////////////
	/** /////////////////////////////////////////////////////////////// **/
	/** ////////////           Implementations           //////////// **/ 
	/** /////////////////////////////////////////////////////////////// **/
	///////////////////////////////////////////////////////////////////////
	
	
	///////////////////////////////////////////////////////////////////////
	/** ////////////             Screen module             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	/// Set color of the cursor screen
	/// @brief setColor
	/// @param value of color 
	/////////////////////////////////////////////////////////////////////////
	void setColor(int value){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
	}
	///////////////////////////////////////////////////////////////////////
	/// Set color of the cursor screen
	/// @brief gotoXY
	/// @param column. Y coordinate
	/// @param line. X coordinate
	/////////////////////////////////////////////////////////////////////////
	void gotoXY( int column, int line ){
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(
								 GetStdHandle( STD_OUTPUT_HANDLE ),
								 coord
								 );
	}
	
	
	///////////////////////////////////////////////////////////////////////
	/// print in the position XY the custom text in the custom color
	/// @brief printXY
	/// @param column. Y coordinate
	/// @param line. X coordinate
	/// @param str. string input
	/// @param color. color input
	/////////////////////////////////////////////////////////////////////////
	void printXY( int column, int line, std::string str, int color=8){
		COORD coord;
		coord.X = column;
		coord.Y = line;
		SetConsoleCursorPosition(
								 GetStdHandle( STD_OUTPUT_HANDLE ),
								 coord
								 );
		// set color
		setColor(color);
		// print
		std::cout<<str;
		// set color
		setColor(P_GREY);
	}
	
	///////////////////////////////////////////////////////////////////////
	/** ////////////             Time module             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	/// Take a break ;P
	/// @brief delay
	/// @param ms. Miliseconds to pause
	/////////////////////////////////////////////////////////////////////////
	void delay(int ms){
		clock_t tempoInit= clock(); 
		clock_t lapseTime= clock();
		while(tempoInit+ms >= lapseTime){
			lapseTime= clock();
		}
	}
	
	
	
	///////////////////////////////////////////////////////////////////////
	/** ////////////             Key module             //////////// **/ 
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	/// register the key who will be readed for the contro
	/// @brief registerKey
	/// @param VK_key see https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	/////////////////////////////////////////////////////////////////////////
	void registerKey(int registeredKey){
		_::keyList.push_front(
							  new _::keyPisco(registeredKey)
							  );
							  
	}
	
	///////////////////////////////////////////////////////////////////////
	/// unregister the key
	/// @brief unregisterKey
	/// @param VK_key see https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	/////////////////////////////////////////////////////////////////////////
	int unregisterKey(int registeredKey){
		list<_::keyPisco*>::iterator it;
		for (it = _::keyList.begin(); it != _::keyList.end(); it++){
			if((*it)->getKey() == registeredKey){
				_::keyList.remove(*it);
				return 1;
			}
		}
	}
	
	///////////////////////////////////////////////////////////////////////
	/// Set the time buffer to the selected key
	/// @brief setKeyTimeBuffer
	/// @param timeBuffer time buffer
	/// @param key
	/////////////////////////////////////////////////////////////////////////
	int setKeyTimeBuffer(int timeBuffer, char key){
		list<_::keyPisco*>::iterator it;
		for (it = _::keyList.begin(); it != _::keyList.end(); it++){
			if((*it)->getKeyChar() == key){
				(*it)->setKeyTimeBuffer(timeBuffer);
				return timeBuffer;
			}
		}
	}
	
	
	///////////////////////////////////////////////////////////////////////
	/// Set the time buffer to the all key
	/// @brief setKeyTimeBuffer
	/// @param timeBuffer time buffer
	/////////////////////////////////////////////////////////////////////////
	int setTimeBuffer(int timeBuffer){
		list<_::keyPisco*>::iterator it;
		for (it = _::keyList.begin(); it != _::keyList.end(); it++){
				(*it)->setKeyTimeBuffer(timeBuffer);
				return timeBuffer;
		}
	}
	
	///////////////////////////////////////////////////////////////////////
	/// iterate on all the registered key and return true false if is it pressed in time
	/// @brief isKeyPressed
	/// @param ms. Miliseconds to pause
	/////////////////////////////////////////////////////////////////////////
	
	bool isKeyPressed(int key){
		
		if(GetAsyncKeyState( key ) & 0x8000 ){
			list<_::keyPisco*>::iterator it;
			for (it = _::keyList.begin(); it != _::keyList.end(); it++){
				if(GetAsyncKeyState( (*it)->getKeyChar() ) & 0x8000 ){
					if(_::keyCurrent == (*it)->getKey() && (*it)->getKeyPristime()){
						(*it)->setKeyPristime(false);
						_::keyCurrent = key;
						(*it)->setKeyLastTimePressed(clock());
						return true;
					}else{
						if(!(*it)->getKeyPristime() && (*it)->getKeyLastTimePressed() + (*it)->getKeyTimeBuffer() < clock()){
							_::keyCurrent = key;
							(*it)->setKeyLastTimePressed(clock());
							return true;
						}
						else{
							_::keyCurrent = key;
							return false;
						}
					}
				}
				else{
					(*it)->setKeyPristime(false);
				}
			}	
		}
	}
	
	
			
}	

	

#endif


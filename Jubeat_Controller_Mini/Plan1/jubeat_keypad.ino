#include <Keypad.h>

const byte numRows= 4;
const byte numCols= 4;

//Flip keymap to play more comfortable
char keymap[numRows][numCols]=
{
{'M', 'N', 'B', 'V'},
{'J', 'H', 'G', 'F'},
{'U', 'Y', 'T', 'R'},
{'7', '6', '5', '4'}
};
byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols]= {5,4,3,2};
Keypad kpd= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup(){
  Serial.begin(250000);
}

//Send KeyStat by Serial
void loop(){
    if (kpd.getKeys()){
        for (int i=0; i<LIST_MAX; i++){
            if ( kpd.key[i].stateChanged ){
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                  case PRESSED:
                    Serial.print(kpd.key[i].kchar);
                    Serial.print("P");
                    break;
                  case RELEASED:
                    Serial.print(kpd.key[i].kchar);
                    Serial.print("R");
                    break;
                }
            }
        }
    }
}

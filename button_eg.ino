#include <SoftwareSerial.h>
SoftwareSerial s(5,6);
const int dots = 8;
const int buttons[dots] = {2,3,4,7,8,9,10,11};
String str="";
void setup() {
  s.begin(9600);
  Serial.begin(9600);
  for (int i=0; i<dots; i++) {
    pinMode(buttons[i], INPUT_PULLUP);  // Active LOW
  }
}
void loop() {
  static unsigned char pressed = 0;
  int buttonsDown = 0;
  for (int i=0; i<dots; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      pressed |= (1<<i);  // Set a bit to remember the button being down
      buttonsDown++;
    }
  }
  if(pressed!=0){
//    Serial.println(pressed);
  }
  if (buttonsDown == 0 && pressed != 0) {
    if(pressed==1){
      Serial.println("A");
      str+="A";
    }
    else if(pressed==3){
      Serial.println("C");
      str+="C";
    }
    else if(pressed==5){
      Serial.println("B");
      str+="B";
    }
    else if(pressed==9){
      Serial.println("E");
      str+="E";
    }
    else if(pressed==7){
      Serial.println("F");
      str+="F";
    }
    else if(pressed==11){
      Serial.println("D");
      str+="D";
    }
    else if(pressed==15){
      Serial.println("G");
      str+="G";
    }
    else if(pressed==13){
      Serial.println("H");
      str+="H";
    }
    else if(pressed==6){
      Serial.println("I");
      str+="I";
    }
    else if(pressed==14){
      Serial.println("J");
      str+="J";
    }
    else if(pressed==17){
      Serial.println("K");
      str+="K";
    }
    else if(pressed==21){
      Serial.println("L");
      str+="L";
    }
    else if(pressed==19){
      Serial.println("M");
      str+="M";
    }
    else if(pressed==27){
      Serial.println("N");
      str+="N";
    }
    else if(pressed==25){
      Serial.println("O");
      str+="O";
    }
    else if(pressed==23){
      Serial.println("P");
      str+="P";
    }
    else if(pressed==31){
      Serial.println("Q");
      str+="Q";
    }
    else if(pressed==29){
      Serial.println("R");
      str+="R";
    }
    else if(pressed==22){
      Serial.println("S");
      str+="S";
    }
    else if(pressed==30){
      Serial.println("T");
      str+="T";
    }
    else if(pressed==49){
      Serial.println("U");
      str+="U";
    }
    else if(pressed==53){
      Serial.println("V");
      str+="V";
    }
    else if(pressed==46){
      Serial.println("W");
      str+="W";
    }
    else if(pressed==51){
      Serial.println("X");
      str+="X";
    }
    else if(pressed==59){
      Serial.println("Y");
      str+="Y";
    }
    else if(pressed==57){
      Serial.println("Z");
      str+="Z";
    }

    else if(pressed==64){
      Serial.println(str);
      str+=" ";
    }
    else if(pressed==128){
      Serial.println(str);
//      char str2[]=str;
      if(s.available()>0){
       Serial.println("Here");
        s.println(str);
      }
      str="";
    }
     //  pressed contains the index of the character to display
    // Process that input here
    pressed = 0; // Reset for more input
  }
}

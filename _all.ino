#include <LiquidCrystal.h>
void lead();
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the Symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','F'},
  {'4','5','6','R'},
  {'7','8','9','L'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {39, 41, 43, 45}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {47, 49, 51, 53}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int go[6];
int newNum[10];
int one =  0;
int i = 0;

void setup(){
  Serial.begin(9600);
  delay(500);
  //motors
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  
  pinMode(14, INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Autonoums CAB");
  delay(200);
  lcd.setCursor(0, 1); // bottom left 
}
void(* resetFunc) (void) = 0; //declare reset function @ address 0
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey != 'D')
  {
    if (customKey){
      Serial.println(customKey);

      if (customKey == '1')
      {
        go[i] = 1;
      }
      if (customKey == '2')
      {
        go[i] = 2;
      }
      if (customKey == '3')
      {
        go[i] = 3;
      }
      if (customKey == '4')
      {
        go[i] = 4;
      }
      if (customKey == '5')
      {
        go[i] = 5;
      }
      if (customKey == '6')
      {
        go[i] = 6;
      }
      if (customKey == '7')
      {
        go[i] = 7;
      }
      if (customKey == '8')
      {
        go[i] = 8;
      }
      if (customKey == '9')
      {
        go[i] = 9;
      }
      if (customKey == 'F')
      {
        go[i] = 10;
      }
      if (customKey == 'R')
      {
        go[i] = 20;
      }
      if (customKey == 'L')
      {
        go[i] = 30;
      }
      

      Serial.println(i);
      Serial.println(go[i]);
      i++;
      
      lcd.display();
      lcd.print(customKey);
      delay(200);
    }
    
  }
  else if (customKey == 'D')
  {
    lcd.clear();
    int a = go[0];
    int b = go[1];
    int c = go[2];
    int d = go[3];
    int e = go[4];
    int f = go[5];

    if(a == 10 && b>0 && b<10)
    {
      lcd.print("F");
      Run(b);
    }
    if(c == 20)
    {
      lcd.print("R");
      digitalWrite(20, HIGH);
      digitalWrite(21, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      delay(2000);
      digitalWrite(20, LOW);
      digitalWrite(21, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
    }
    if(c == 30)
    {
      lcd.print("L");
      digitalWrite(20, LOW);
      digitalWrite(21, HIGH);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      delay(2000);
      digitalWrite(20, LOW);
      digitalWrite(21, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
    }
    if(d == 10 && e>0 && e<10)
    {
      lcd.print("F");
      Run(e);
    }
    if(f == 20)
    {
      lcd.print("R");
      digitalWrite(20, HIGH);
      digitalWrite(21, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      delay(2000);
      digitalWrite(20, LOW);
      digitalWrite(21, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      lcd.clear();
      lcd.print("U have arrived");      
    }
    if(f == 30)
    {
      lcd.print("L");
      digitalWrite(20, LOW);
      digitalWrite(21, HIGH);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      delay(2000);
      digitalWrite(20, LOW);
      digitalWrite(21, LOW);
      digitalWrite(18, LOW);
      digitalWrite(19, LOW);
      lcd.clear();
      lcd.print("U have arrived");
    }
  }
}

void Run(int x){
  int sen = 0;
  while(x-sen != 0)
  {
    
    int sensor = digitalRead(14);
    if(sensor == 0)
    {
      sen += 1;
      delay(1000);
      lcd.clear();
      lcd.print("Block remaining:");
      lcd.setCursor(0, 1); // bottom left
      lcd.print(x-sen);
    }
        
    if (sen >= 1)
    {
      digitalWrite(20, HIGH);
      digitalWrite(21, LOW);
      digitalWrite(18, HIGH);
      digitalWrite(19, LOW);
    }
  }
  lcd.print(sen);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);

  if (x-sen == 0)
  {
    digitalWrite(20, LOW);
    digitalWrite(21, LOW);
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    delay(2000);
  }
}
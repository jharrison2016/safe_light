int blue = 7;
int red = 6;
int white = 8;
int button = 9;
int butState = 0;

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
//Variables
int value;          // Store value from photoresistor (0-1023)

void setup(){
 pinMode(blue, OUTPUT);  
 pinMode(red, OUTPUT);
 pinMode(white, OUTPUT);
 pinMode(button, INPUT);
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 Serial.begin(9600);
}


void loop(){
  butState = digitalRead(button);
  
  value = analogRead(pResistor);
  value/= 10;
  /*Serial.println(value);
  delay(500);*/

  if(butState == HIGH){
    digitalWrite(blue, LOW);
    digitalWrite(red, LOW);
    digitalWrite(white, HIGH);
  }
  
  if(value > 50 && butState != HIGH){
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(white, LOW);
  }
  else if(value <= 50 && butState != HIGH){
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(white, LOW);
  }
 
}


#define nrSensors 6

int ledState = LOW;
int buttonState;
int lastButtonState = LOW;

int motorPinLeft1 = 2;
int motorPinLeft2 = 3;
int motorPinRight1 = 4;
int motorPinRight2 = 5;

int  sensor[ nrSensors ] = { A0, A1, A2, A3, A4, A5 }; 
int valSensor[ nrSensors ];

void turnRight() {

  digitalWrite(motorPinLeft1, HIGH);
  digitalWrite(motorPinLeft2, LOW);

  digitalWrite(motorPinRight1, HIGH);
  digitalWrite(motorPinRight2, LOW);

}

void turnLeft() {

  digitalWrite(motorPinLeft1, LOW);
  digitalWrite(motorPinLeft2, HIGH);

  digitalWrite(motorPinRight1, LOW);
  digitalWrite(motorPinRight2, HIGH);
}

void goFront() {

  digitalWrite(motorPinLeft1, HIGH);
  digitalWrite(motorPinLeft2, LOW);

  digitalWrite(motorPinRight1, LOW);
  digitalWrite(motorPinRight2, HIGH);

}

void setup () {

  pinMode(motorPinLeft1, OUTPUT);
  pinMode(motorPinLeft2, OUTPUT);
  pinMode(motorPinRight1, OUTPUT);
  pinMode(motorPinRight2, OUTPUT);

  digitalWrite(motorPinLeft1, LOW);
  digitalWrite(motorPinLeft2, LOW);

  digitalWrite(motorPinRight1, LOW);
  digitalWrite(motorPinRight2, LOW);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  for (int i = 0; i < nrSensors; i++)
        pinMode( sensor[i], INPUT);

  Serial.begin(9600);
  Serial.println("Welcom to experiment - Line Following");
  
}

void loop () {
  
  goFront();
  for ( int i = 0; i < nrSensors; i++)
  {
        valSensor[ i ] = analogRead( sensor[ i ] );
        if ( valSensor[i] < 900){ // daca masina a deviat de pe traseu 
              if ( i == 0  || i == 1 || i == 2){
                        do{
                          turnLeft();
                          valSensor[ i ] = analogRead( sensor[ i ] );
                        }while( valSensor[i] > 900); 
                        goFront();
              }
               if ( i == 3  || i == 4 || i == 5){
                        do{
                          turnRight();
                          valSensor[ i ] = analogRead( sensor[ i ] );
                        }while( valSensor[i] > 900); 
                        goFront();
         }
       }
  }
}

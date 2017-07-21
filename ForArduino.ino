// motor one
int enA = 3;
int in1 = A0;
int in2 = A1;
// motor two
int enB = 5;
int in3 = A2;
int in4 = A3;

//motor three
int enC = 6;
int in5 = 10;
int in6 = 11;
//motor four
int enD = 9;
int in7 = 12;
int in8 = 13;


char remote;


void setup()
{
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  //XBee.begin(9600);
  //Serial.begin(9600);
  //while(!Serial){};
  Serial1.begin(9600);
  while(!Serial1){};

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
}

void loop()
{
  /*if (Serial.available())
  { // If data comes in from serial monitor, send it out to XBee
    XBee.write(Serial.read());
  }
  if (XBee.available())
  { // If data comes in from XBee, send it out to serial monitor
    Serial.write(XBee.read());
  }//*/
 

  
  if(Serial1.available())
  {
  //Serial.println((char)Serial1.read());  
  remote = Serial1.read();
  }
  //Serial.println(remote);

  switch(remote){
      case 'A': //left stick
      // turn on motor B
      // turn on motor A
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enA, 255);
      // turn on motor D
      digitalWrite(in7, HIGH);
      digitalWrite(in8, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enD, 255);
        break;
        
      case 'B': //right stick
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enB, 255);
      // turn on motor C
      digitalWrite(in5, HIGH);
      digitalWrite(in6, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enC, 255);
        break;
        
      case 'C': //both sticks
      // turn on motor B
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enB, 255);
      // turn on motor C
      digitalWrite(in5, HIGH);
      digitalWrite(in6, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enC, 255);
      // turn on motor A
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enA, 255);
      // turn on motor D
      digitalWrite(in7, HIGH);
      digitalWrite(in8, LOW);
      // set speed to 200 out of possible range 0~255
      analogWrite(enD, 255);
        break;
        
      case 'D': //both not foward
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);  
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      digitalWrite(in5, LOW);
      digitalWrite(in6, LOW);  
      digitalWrite(in7, LOW);
      digitalWrite(in8, LOW);
        break;  

      case 'E':
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); 
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH); 
      digitalWrite(in5, LOW);
      digitalWrite(in6, HIGH);
      digitalWrite(in7, LOW);
      digitalWrite(in8, HIGH);
        break;

       case 'F':
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); 
      digitalWrite(in7, LOW);
      digitalWrite(in8, HIGH);
        break;

       case 'G':
      digitalWrite(in3, LOW); 
      digitalWrite(in4, HIGH); 
      digitalWrite(in5, LOW);
      digitalWrite(in6, HIGH);
        break;
  } // */
  
  //delay(1000);
}


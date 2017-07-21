#define LeftJoystick A3
#define RightJoystick A0

int analogRight;
int analogLeft;

void setup() {
  
  SerialUSB.begin(9600);
  while(!Serial){};
  Serial1.begin(9600);
  delay(500);
  
}

void loop() {

//Serial1.write(analogRead(PIN_ANALOG_X));
//delay(1000); 

analogLeft = analogRead(LeftJoystick);
analogRight = analogRead(RightJoystick);


if(((analogLeft > 520) && (analogLeft < 550)) && ((analogRight > 440) && (analogRight < 500)))
{
  Serial1.write('D'); //both not moving 
  //SerialUSB.println('D');
} 



else if((analogLeft >= 550) && (analogRight >= 550))
{
  Serial1.write('C'); //both moving foward
  //SerialUSB.println('C');
}



else if(analogLeft >= 550)
{
  Serial1.write('A'); //left forwrd
  //SerialUSB.println('A');
}
else if(analogRight >= 550)
{
  Serial1.write('B'); //right forward
  //SerialUSB.println('B');
}// */




else if((analogLeft <= 520 ) && (analogRight <= 440 ))
{      
  Serial1.write('E'); //both down (reversing)
  //SerialUSB.println('E');
}


else if (analogLeft <= 520)
{
  Serial1.write('F'); //left down  
  //SerialUSB.println('F');
}


else if (analogRight <= 440)
{
  Serial1.write('G'); //right down  
  //SerialUSB.println('G');
}



 // */

}

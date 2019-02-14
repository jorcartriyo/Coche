


#include <AFMotor.h>

/*
PROYECTO: CONSTRUIR UN COCHE AUTOINMOLABLE
AUTHORS: GRUPO HOMMER 2DAM

*/

#include <AFMotor.h>//libreria del motor
#define trigPin 14 // define los pines del sensor
#define echoPin 15 // define los pines del sensor

//Objects
AF_DCMotor motorTraseraIzquierda(1, MOTOR12_64KHZ); // crea motor #1, 64KHz pwm
AF_DCMotor motorTraseraDerecha(2, MOTOR12_64KHZ); // crea motor #2, 64KHz pwm
AF_DCMotor motorDelanteroDerecho(3, MOTOR12_64KHZ);  // crea motor #3, 64KHz pwm
AF_DCMotor motorDelanteroIzquierdo(4, MOTOR12_64KHZ);  // crea motor #4, 64KHz pwm

//Constants and variable
char dataIn = 'S';//Char que pone el coche en la posición de stop
char determinant;
char det;
int vel = 255; //Bluetooth Stuff
void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)

  //Initalization messages
  Serial.println(" Mr.robot");
  Serial.println(" Reday for working!");
  Serial.println(" VAMOS ILLO QUE ESTO FUNCIONA!");
  //turn off motors
   motorTraseraIzquierda.setSpeed(0);
   motorTraseraDerecha.setSpeed(0);
   motorDelanteroDerecho.setSpeed(0);
   motorDelanteroIzquierdo.setSpeed(0);
   motorTraseraIzquierda.run(RELEASE);
   motorDelanteroDerecho.run(RELEASE);
   motorTraseraDerecha.run(RELEASE);
   motorDelanteroIzquierdo.run(RELEASE);
}

void loop() {
    det = check(); //call check() subrotine to get the serial code
  //serial code analysis
  switch (det){
    case 'F': // F, move forward FUNCIONA
    motorTraseraIzquierda.setSpeed(vel);
    motorDelanteroDerecho.setSpeed(vel);
    motorTraseraDerecha.setSpeed(vel);
    motorDelanteroIzquierdo.setSpeed(vel);
    motorTraseraIzquierda.run(FORWARD);
    motorDelanteroDerecho.run(FORWARD);
    motorTraseraDerecha.run(FORWARD);
    motorDelanteroIzquierdo.run(FORWARD);
    det = check();
   break;

    case 'B': // B, move back FUNCIONA
     motorTraseraIzquierda.setSpeed(vel);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(BACKWARD);
     motorDelanteroDerecho.run(BACKWARD);
     motorTraseraDerecha.run(BACKWARD);
     motorDelanteroIzquierdo.run(BACKWARD);
     det = check();
    break;

    case 'L':// L, move wheels left FUNCIONA
     motorTraseraIzquierda.setSpeed(vel);
     motorDelanteroDerecho.setSpeed(vel/4);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(FORWARD);
     motorDelanteroDerecho.run(FORWARD);
     motorTraseraDerecha.run(FORWARD);
     motorDelanteroIzquierdo.run(BACKWARD);
     det = check();
    break;

    case 'R': // R, move wheels right FUNCIONA
     motorTraseraIzquierda.setSpeed(vel/4);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(FORWARD);
     motorDelanteroDerecho.run(FORWARD);
     motorTraseraDerecha.run(BACKWARD);
     motorDelanteroIzquierdo.run(FORWARD);
     det = check();
    break;

    case 'I': // I, turn right forward
     motorTraseraIzquierda.setSpeed(vel);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(BACKWARD);
     motorDelanteroDerecho.run(FORWARD);
     motorTraseraDerecha.run(BACKWARD);
     motorDelanteroIzquierdo.run(FORWARD);
     det = check();
    break;

    case 'J': // J, turn right back
     motorTraseraIzquierda.setSpeed(vel/4);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(BACKWARD);
     motorDelanteroDerecho.run(BACKWARD);
     motorTraseraDerecha.run(FORWARD);
     motorDelanteroIzquierdo.run(BACKWARD);
     det = check();
    break;

    case 'G': // G, turn left forward
     motorTraseraIzquierda.setSpeed(vel);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(FORWARD);
     motorDelanteroDerecho.run(BACKWARD);
     motorTraseraDerecha.run(FORWARD);
     motorDelanteroIzquierdo.run(BACKWARD);
     det = check();
    break;

    case 'H': // H, turn left back
     motorTraseraIzquierda.setSpeed(vel/4);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.run(BACKWARD);
     motorDelanteroDerecho.run(BACKWARD);
     motorTraseraDerecha.run(BACKWARD);
     motorDelanteroIzquierdo.run(FORWARD);
     det = check();
    break;

    case 'S':
    //S, stop FUNCIONA 
     motorTraseraDerecha.setSpeed(vel);
     motorDelanteroIzquierdo.setSpeed(vel);
     motorTraseraIzquierda.setSpeed(vel);
     motorDelanteroDerecho.setSpeed(vel);
     motorTraseraIzquierda.run(RELEASE);
     motorDelanteroDerecho.run(RELEASE);
     motorTraseraDerecha.run(RELEASE);
     motorDelanteroIzquierdo.run(RELEASE);
     det = check();
    break;

    case 'm':

  //for wall follower robot.
    motorTraseraIzquierda.setSpeed(vel); //establece la velocidad del motor entre 0-255
    motorDelanteroDerecho.setSpeed (vel);
    motorTraseraDerecha.setSpeed(vel);
    motorDelanteroIzquierdo.setSpeed (vel);


  long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 30)/*The distance that need to to keep with the wall */ {
  Serial.println ("Wall is ditected!" );
  Serial.println (" Started following the wall ");
  Serial.println (" Turning !");
  motorTraseraIzquierda.setSpeed(vel);
  motorDelanteroDerecho.setSpeed(0);
  motorTraseraDerecha.setSpeed(vel);
  motorDelanteroIzquierdo.setSpeed(0);
  motorTraseraIzquierda.run(FORWARD);
  motorDelanteroDerecho.run(RELEASE);
  motorTraseraDerecha.run(FORWARD);
  motorDelanteroIzquierdo.run(RELEASE);
  delay(500); // wait for a second
}

  else {
   Serial.println ("No Wall detected. turning round");
   delay (15);
    motorTraseraIzquierda.setSpeed(0);
    motorDelanteroDerecho.setSpeed(vel);
    motorTraseraIzquierda.run(RELEASE);
    motorDelanteroDerecho.run (FORWARD);

  }
     break;

    case 'b':
  //obstacle avoider robot

  // motorTraseraIzquierda.setSpeed(vel); //set the speed of the motors, between 0-255
   //motorDelanteroDerecho.setSpeed (vel);

  long Aduration, Adistance; // start the scan
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  Aduration = pulseIn(echoPin, HIGH);
  Adistance = (Aduration/2) / 29.1;// convert the distance to centimeters.
  if (Adistance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ {
Serial.println ("Close Obstacle detected!" );
Serial.println ("Obstacle Details:");
Serial.print ("Distance From Robot is " );
Serial.print ( Adistance);
Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");
Serial.println (" Turning !");
    motorTraseraIzquierda.setSpeed(vel);
    motorDelanteroDerecho.setSpeed(vel);
    motorDelanteroDerecho.run(BACKWARD);  // Turn as long as there's an obstacle ahead.
    motorTraseraIzquierda.run (FORWARD);

}
  else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
   motorTraseraIzquierda.setSpeed(vel);
   motorDelanteroDerecho.setSpeed(vel);
   motorTraseraIzquierda.run(FORWARD); //if there's no obstacle ahead, Go Forward!
   motorDelanteroDerecho.run(FORWARD);

    }
   break;
  }
}

//get bluetooth code received from serial port
int check(){
  if (Serial.available() > 0){// if there is valid data in the serial port
  dataIn = Serial.read();// stores data into a varialbe

//check the code
    if (dataIn == 'F'){//Forward
      determinant = 'F';
    }
    else if (dataIn == 'B'){//Backward
      determinant = 'B';
    }
    else if (dataIn == 'L'){//Left
      determinant = 'L';
    }
    else if (dataIn == 'R'){//Right
      determinant = 'R';
    }
    else if (dataIn == 'I'){//Froward Right
      determinant = 'I';
    }
    else if (dataIn == 'J'){//Backward Right
      determinant = 'J';
    }
    else if (dataIn == 'G'){//Forward Left
      determinant = 'G';
    }
    else if (dataIn == 'H'){//Backward Left
      determinant = 'H';
    }
    else if (dataIn == 'S'){//Stop
      determinant = 'S';
    }
    else if (dataIn == '0'){//Speed 0
      vel = 0;
    }
    else if (dataIn == '1'){//Speed 25
      vel = 25;
    }
    else if (dataIn == '2'){//Speed 50
      vel = 50;
    }
    else if (dataIn == '3'){//Speed 75
      vel = 75;
    }
    else if (dataIn == '4'){//Speed 100
      vel = 100;
    }
    else if (dataIn == '5'){//Speed 125
      vel = 125;
    }
    else if (dataIn == '6'){//Speed 150
      vel = 150;
    }
    else if (dataIn == '7'){//Speed 175
      vel = 175;
    }
    else if (dataIn == '8'){//Speed 200
      vel = 200;
    }
    else if (dataIn == '9'){//Speed 225
      vel = 225;
    }
    else if (dataIn == 'b'){//Extra On
      determinant = 'b';
    }
    else if (dataIn == 'm'){//Extra On
      determinant = 'm';
    }

  }
  return determinant;
}

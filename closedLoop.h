#include <PID_v1.h>
#define PIN_SETPOINT A1
#define PIN_FEEDBACK A2
#define PIN_OUTPUT 3

double Setpoint, Feedback, Output;
double Kp=0.3, Ki=2.3, Kd=0.15;
PID myPID(&Feedback, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
unsigned long timet;
unsigned long previousTime;
boolean enterFunction= true;

void setup()
{
    Serial.begin(115200);
    Feedback = 0;
    Setpoint = 0;
    myPID.SetMode(AUTOMATIC);
}

void loop()
{
    Feedback = map(analogRead(PIN_FEEDBACK),561,926,0,255);
    Setpoint = map(analogRead(PIN_SETPOINT),0,1023,0,255);
    floor(Setpoint*0.8/2);
    floor(Feedback*0.8/2);
    myPID.Compute();
    analogWrite(PIN_OUTPUT, Output);
    timet = micros();
    
    if (enterFunction == true){
        previousTime= timet;
        Serial.print("Setpoint: ");
        Serial.print(floor(Setpoint*0.8/2));
        Serial.print(" Saida: ");
        Serial.print(floor(Feedback*0.8/2));
        Serial.print(" Tempo: ");
        Serial.println(timet/1000000.0);
        delay(8);
    }
    if (timet - previousTime < 9999){
        enterFunction= false;
    }
    else {
        enterFunction= true;
    }
}
#define PIN_SETPOINT A1
#define PIN_FEEDBACK A2
#define PIN_OUTPUT 3

double Setpoint, Feedback, Output;
unsigned long timet;

void setup()
{
    Serial.begin(115200);
    Feedback = 0;
    Setpoint = 0;
}

void loop()
{
    Feedback = map(analogRead(PIN_FEEDBACK),566,926,0,255);
    Setpoint = map(analogRead(PIN_SETPOINT),0,1023,0,255);
    analogWrite(PIN_OUTPUT,Setpoint);
    timet = micros();
    Serial.print("Setpoint: ")
    Serial.print(analogRead(PIN_SETPOINT)*4.89/1023);
    Serial.print(" Saida: ");
    Serial.print(floor(Feedback*0.8/2));
    Serial.print(" Tempo: ");
    Serial.println(timet/1000000.0);
    delay(8);
}

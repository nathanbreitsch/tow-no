// ------------
// Tow No
// ------------

/*-------------

Tow No! uses a tilt sensor to determine whether your car is being towed.


-------------*/

int led = D0;
int tilt = A0;
int power = A5;

int isTilting = 0;



void setup() {


    pinMode(led, OUTPUT);
    pinMode(tilt, INPUT);
    pinMode(power, OUTPUT);

    digitalWrite(power, HIGH);
    digitalWrite(led, LOW);

}


void loop() {

    isTilting = digitalRead(tilt);
    digitalWrite(led, isTilting);
}

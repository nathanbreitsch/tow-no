// ------------
// Tow No
// ------------

/*-------------

Tow No! uses a tilt sensor to determine whether your car is being towed.


-------------*/

int tilt_led = D0;
int towing_led = D3;
int tilt = A0;
int reset_in = A2;
int power = A5;

bool is_tilting = true;
bool sent_alert = false;
bool press_reset = false;

void setup() {

    pinMode(tilt_led, OUTPUT);
    pinMode(towing_led, OUTPUT);
    pinMode(tilt, INPUT);
    pinMode(reset_in, INPUT);
    pinMode(power, OUTPUT);

    digitalWrite(power, HIGH);
    digitalWrite(tilt_led, HIGH);
    digitalWrite(towing_led, HIGH);

}


void loop() {

    is_tilting = ( digitalRead(tilt) == HIGH );
    press_reset = ( digitalRead(reset_in) == HIGH );

    if(is_tilting && !sent_alert){
        Particle.publish("TowStatus","Towing",60,PUBLIC);
        sent_alert = true;
        digitalWrite(towing_led, HIGH);
    }

    if(press_reset){
        sent_alert = false;
        digitalWrite(towing_led, LOW);
    }

    digitalWrite(tilt_led, is_tilting);
}

const int beat1 = 36;  // C2
const int beat2 = 37;  // C#2

const int sw1 = 2;
const int sw2 = 3;
const int led = 13;

void setup() {
  //  Set MIDI baud rate:
  Serial1.begin(31250);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop1() {
  noteOn(0x99, beat1, 0x45);
  delay(500);
  noteOn(0x99, beat1, 0x00);
  delay(500);
}

void loop2() {
  noteOn(0x99, beat2, 0x45);
  delay(250);
  noteOn(0x99, beat2, 0x00);
  delay(250);
}

void loop() {
  int sw1st = digitalRead(sw1);
  int sw2st = digitalRead(sw2);
  // Serial.write(pin2);
  if (!sw1st || !sw2st) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  // delay(100);
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(velocity);
}


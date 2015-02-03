const int interval = 1000;  // [ms]
const int interval_highbeat = 500;

const int note = 36;  // C2
const int note_highbeat = 37;  // C#2

const int sw1 = 2;
const int light = 3;
const int led = 13;

const int sensor = A0;

void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(light, OUTPUT);
  pinMode(led, OUTPUT);
  //  Set MIDI baud rate:
  Serial1.begin(31250);
}

void beat() {
  digitalWrite(light, HIGH);
  noteOn(0x99, note, 0x45);
  delay(interval);
  digitalWrite(light, LOW);
  noteOn(0x99, note, 0x00);
  delay(interval);
}

void highbeat() {
  digitalWrite(light, HIGH);
  noteOn(0x99, note_highbeat, 0x45);
  delay(interval_highbeat);
  digitalWrite(light, LOW);
  noteOn(0x99, note_highbeat, 0x00);
  delay(interval_highbeat);
}

void loop() {
  int sw1st = digitalRead(sw1);
  if (sw1st) {
    digitalWrite(led, HIGH);
    highbeat();
  }
  else {
    digitalWrite(led, LOW);
    beat();
  }
}

//  plays a MIDI note.  Doesn't check to see that
//  cmd is greater than 127, or that data values are  less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial1.write(cmd);
  Serial1.write(pitch);
  Serial1.write(velocity);
}


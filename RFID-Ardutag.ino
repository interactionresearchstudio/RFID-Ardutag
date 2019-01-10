/* Simple RFID tag sketch to send spoof data for Naturewatch RFID freader */

/* data layout
  9  1 bits
  50 bits split into 10 half bytes ending with parity bit which is 0 if even amount of 1 bits, 1 if odd amount of 1 bits
  4  bits for column parity. 0 if even amount of 1 bits, 1 if odd amount of 1 bits
  1  0 bit
*/

byte data[64] =
{ 1, 1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0,
  1, 1, 1, 1, 0,
  0, 0, 0, 0, 0,
  1, 1, 1, 1, 0,
  0, 0, 0, 0, 0,
  1, 1, 1, 1, 0,
  0, 0, 0, 0, 0,
  1, 1, 1, 1, 0,
  0, 0, 0, 0, 0,
  1, 1, 1, 1, 0,
  1, 1, 1, 1, 0,
};

int coil_pin = 9;



void set_pin(int clock_half, byte sig) {
  if (clock_half == 1) {
    digitalWrite(coil_pin, sig);
  } else {
    digitalWrite(coil_pin, ~sig - 0xFE);
  }
}


void setup() {
  pinMode(coil_pin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 64; i++)
  {
    set_pin(1, data[i]);
    delayMicroseconds(256);

    set_pin(0, data[i]);
    delayMicroseconds(256);
  }
}



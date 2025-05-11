void setup(){
  // Begin the serial monitor at 9600 baud for viewing output
  Serial.begin(9600);  

  // Begin hardware serial communication on Serial2
  // RX pin = 16, TX pin = 17 (change if your wiring is different)
  Serial2.begin(9600, SERIAL_8N1, 16, 17);  // 9600 baud, 8 data bits, no parity, 1 stop bit
}

void loop(){
  // Check if data is available on Serial2 (connected to GPS)
  while (Serial2.available() > 0){
    byte gpsData = Serial2.read();  // Read data byte from GPS module
    Serial.write(gpsData);          // Send the byte to the Serial Monitor
  }
}

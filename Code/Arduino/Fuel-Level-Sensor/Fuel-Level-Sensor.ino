float tank_level=0;
void setup() {
pinMode(LED_BUILTIN,OUTPUT);
Serial.begin(9600);
 Serial.println("UART BEGIN");
}

void loop() {
  if(analogRead(0) > 0 && analogRead(0) <= 520)
  {
  tank_level = map(analogRead(0),50,520,6220,0);
  tank_level = tank_level/1000;
  Serial.print("Fuel Level: ");
  Serial.print(tank_level);
  Serial.println(" L");
  Serial.print("adc value: ");
  Serial.println(analogRead(0));
  }
 else
 {
  Serial.print("Full Tank");
  Serial.println(analogRead(0));
 }
  delay(1000);
}

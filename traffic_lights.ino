void setup ()
{
pinMode (5, OUTPUT); // a
pinMode (18, OUTPUT); //b
pinMode (4, OUTPUT); //c
pinMode (2, OUTPUT); // d
pinMode (15, OUTPUT); // e
pinMode (27, OUTPUT); // f
pinMode (26, OUTPUT); // g
pinMode(21, OUTPUT); // red
pinMode(22, OUTPUT); // yellow
pinMode(23, OUTPUT); // green

pinMode(13, OUTPUT); // green 2
pinMode(12, OUTPUT); // yellow 2
pinMode(14, OUTPUT); // red 2
}
void loop()
{
  //STOP
  digitalWrite(21, HIGH);
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);

  //GO (other road)
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);

  //5
  digitalWrite(5, LOW);
  digitalWrite(18, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  delay(1000);
  //4
  digitalWrite(5, HIGH);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  delay(1000);
  //3
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(26, LOW);
  delay(1000);
  //2
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(27, HIGH);
  digitalWrite(26, LOW);
  delay(1000);
  //1
  digitalWrite(5, HIGH);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(26, HIGH);
  delay(1000);
  //0
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(27, LOW);
  digitalWrite(26, HIGH);
  delay(1000);

  //YELLOW
  digitalWrite(21, LOW);
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);

  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(14, LOW);

  //2
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(27, HIGH);
  digitalWrite(26, LOW);
  delay(1000);
  //1
  digitalWrite(5, HIGH);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(26, HIGH);
  delay(1000);
  //0
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(27, LOW);
  digitalWrite(26, HIGH);
  delay(1000);

  //GO
  digitalWrite(21, LOW);
  digitalWrite(22, LOW);
  digitalWrite(23, HIGH);
  // STOP(other road)
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, HIGH);

  //5
  digitalWrite(5, LOW);
  digitalWrite(18, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  delay(1000);
  //4
  digitalWrite(5, HIGH);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  delay(1000);
  //3
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(26, LOW);
  delay(1000);
  //2
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(27, HIGH);
  digitalWrite(26, LOW);
  delay(1000);
  //1
  digitalWrite(5, HIGH);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(26, HIGH);
  delay(1000);
  //0
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(27, LOW);
  digitalWrite(26, HIGH);
  delay(1000);
}
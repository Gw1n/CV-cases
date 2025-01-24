String str_light[3] = {"", "", ""};
int light[3] = {0, 0, 0};
int j = 0;

void setup() {
  
for(int i = 3; i < 12; i++)
{
  pinMode(i, OUTPUT);
  digitalWrite(i, LOW);
}

pinMode(4, INPUT);
Serial.begin(9600);

}

void loop() {

while (!Serial.available()) {}

while (Serial.available())
  {
    String receivedData = Serial.readString();
  for (int i = 0; i < receivedData.length(); i++)
  {
    if (receivedData[i] != ' ')
    {
      str_light[j] += receivedData[i];
    }
    else
    {
      j += 1;
    }
  }
  
  for (int i = 0; i < 3; i++)
  {
    light[i] = atoi(str_light[i].c_str());
  }
  for (int i = 0; i < 3; i++)
  {
    Serial.println(light[i]);
  }
    
  }

  analogWrite(5, light[2]);
  analogWrite(6, light[1]);
  analogWrite(3, light[0]);

  analogWrite(9, light[0]);
  analogWrite(10, light[2]);
  analogWrite(11, light[1]);
}

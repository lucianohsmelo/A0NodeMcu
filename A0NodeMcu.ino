#define n 50 //numero de pontos da média móvel

int original, filtered;
int numbers[n];

long moving_avg();

void setup() {
 Serial.begin(115200);
 pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  original = analogRead(A0);
  filtered = moving_avg(original);
  original = (original * 285.0f) / 1023.0f;
  filtered = (filtered * 285.0f) / 1023.0f;
  Serial.print(original);
  Serial.print(" ");
  Serial.println(filtered);
  delay(20);
}

long moving_avg(int value){
  for(int i = n-1; i>0; i--){
    numbers[i] = numbers[i-1];
  }
  numbers[0] = value;
  long acc = 0;
  for (int i = 0; i < n; i++){
    acc += numbers[i];
  }
  return acc/n;
}

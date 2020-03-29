void setup() {
  // put your setup code here, to run once:
Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial1.println("Hello, world!");
//wait 100 milliseconds so we don't drive ourselves crazy
delay(100);
}

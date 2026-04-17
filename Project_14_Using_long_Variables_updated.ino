// Project 14 - Using long Variables

long number = 0;
long a = 0;
long exponent = 0;
long b = 0 ;
float finalProduct = 0;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  number = 0;     // zero the incoming number ready for a new read
  Serial.flush(); // clear any "junk" out of the serial buffer before waiting
  while (Serial.available() == 0)
  {
    // do nothing until something comes into the serial buffer- 
    // when something does come in, Serial.available will return how many
    // characters are waiting in the buffer to process
  }
    // one character of serial data is available, begin calculating
  while (Serial.available() > 0)
  {
    // move any previous digit to the next column on the left; 
    // in other words, 1 becomes 10 while there is data in the buffer
    number = number * 10; 
    // read the next number in the buffer and subtract the character 0 
    // from it to convert it to the actual integer number
    a = Serial.read() - '0';
    // add this value a into the accumulating number
    number = number + a;
    // allow a short delay for more serial data to come into Serial.available
    delay(5);
  }
  exponent = 0;     // zero the incoming exponent ready for a new read
  Serial.flush(); // clear any "junk" out of the serial buffer before waiting
  while (Serial.available() == 0)
  {
    // do nothing until something comes into the serial buffer- 
    // when something does come in, Serial.available will return how many
    // characters are waiting in the buffer to process
  }
    // one character of serial data is available, begin calculating
  while (Serial.available() > 0)
  {
    // move any previous digit to the next column on the left; 
    // in other words, 1 becomes 10 while there is data in the buffer
    exponent = exponent * 10; 
    // read the next exponent in the buffer and subtract the character 0 
    // from it to convert it to the actual integer exponent
    a = Serial.read() - '0';
    // add this value a into the accumulating exponent
    exponent = exponent + a;
    // allow a short delay for more serial data to come into Serial.available
    delay(5);
  }
  

  Serial.print("You entered this number: ");
  Serial.println(number);
    Serial.print("You entered this exponent: ");
    Serial.println(exponent);
  Serial.print(number);
  Serial.print(" to the power of ");
  Serial.print(exponent);
  Serial.println(" is: ");
  finalProduct = round(pow(number, exponent));
  Serial.println(finalProduct);
}
  
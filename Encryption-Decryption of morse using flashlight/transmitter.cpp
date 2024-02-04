unsigned int led_pin =13;
char *letters[]={
".-", // A1
"-...", // B2
"-.-.", // C3
"-..", // D4
".", // E5
"..-.", // F6
"--.", // G7
"....", // H8
"..", // I9
".---", // J10
"-.-", // K11
".-..", // L12
"--", // M13
"-.", // N14
"---", // O15
".--.", // P16
"--.-", // Q17
".-.", // R18
"...", // S19
"-", // T20
"..-", // U21
"...-", // V22
".--", // W23
"-..-", // X24
"-.--", // Y25
"--.." // Z26
};

char *numbers[]={
"-----", // 0
".----", // 1
"..---", // 2
"...--", // 3
"....-", // 4
".....", // 5
"-....", // 6
"--...", // 7
"---..", // 8
"----.", // 9
};

unsigned int dot_duration=200;
bool done = false;

void setup(){
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Morse code to led conversion");
  Serial.println("enter yout txt");
}
void loop()
{
  char ch;
  while(!done)
  {
    if(Serial.available())
    {
      ch= Serial.read();
      if(ch>='A' && ch <='Z')
      {
        Serial.println(ch);
        flash_morse_code(letters[ch - 'A']);
      }
      else if(ch>='a' && ch <='z')
      {
        Serial.println(ch);
        flash_morse_code(letters[ch - 'a']);
      }
      else if(ch>='0'&& ch <='9')
      {
        Serial.println(ch);
        flash_morse_code(letters[ch - '0']);
      }
      else if(ch ==' ')
      { 
        delay(dot_duration * 7);
      }
      else if(ch =='!')
      { 
        done =true;
        Serial.println("msg sent successfully!!");
      }
     }
	}
              while(true){}
}
void flash_morse_code(char *morse_code)
{
  unsigned int i=0;
  while (morse_code[i]!=NULL){
    flash_dot_or_dash(morse_code[i]);
    i++;
  }
  delay(dot_duration*3);
}
void flash_dot_or_dash(char dot_dash){
                digitalWrite(led_pin, HIGH);
                if(dot_dash == '.')
                {
                  delay(dot_duration);
                }
                else{
                  delay(dot_duration*3);
                }
                digitalWrite(led_pin, LOW);
                delay(dot_duration);
}
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
      
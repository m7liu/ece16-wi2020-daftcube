#define CHALLENGE_1 false
#define OTHER_CHALLENGES true
#define FIREWORKS false
#define OLED_ADVANCED true

#if OTHER_CHALLENGES

// ========   Main   ======== //

int timer_seconds = 0;

void setup()
{
  setupADC();
  setupLed();
  setupOled();
  setupSerial();

  delay(2000);
}

void loop()
{
  Lab3();
}

/*
 * Lab 3 Challenges
 */
void Lab3()
{
  receiveMessage();
  sendData();
  checkMessage();
}

// Contains logic for last lab.
void Lab2_ChallengesFinal()
{
  readADC();
  printADC();
  executeTimerTask();
}

// I did lab C2 and C3 in parallel.
void Lab2_C2C3()
{
  readADC();
  //printADC();

  if ( detectTap() )
  {
    //addTimerOLED();
  }

  runTimerOLED();
  receiveMessage();
}


/*
void Lab_C4()
{
  readADC();
  printADC();

  if ( detectTap() )
  {
    addTimerOLED();
  }

  runTimerOLED();
}
*/
#endif

#include "Animation.h"

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}

AnimationSD::AnimationSD(CRGB* ledsArray, int ledArrayCount)
{
    Serial.println('Initializing Animation');
    leds = ledsArray;
    ledCount = ledArrayCount;
    Serial.print("LedsCount");
    Serial.print(ledCount, DEC);
    Serial.print("array");
    Serial.print((int)leds, HEX);
    pinMode(10,OUTPUT); //CS/SS pin as output for SD library to work.
    digitalWrite(10,HIGH); //workaround for sdcard failed error...
    
    Serial.print("Initializing SD card...");
    if (!SD.begin(10)) {
      Serial.println("initialization failed!");
      while (1);
    }
    Serial.println("initialization done.");
    File root = SD.open("/");
    printDirectory(root,0);
    root.close();
    
    Serial.print("AnimationDir:");
    Serial.println(AnimationDir);
    animationRoot = SD.open(AnimationDir);
    Serial.print("Opening:");
    Serial.print(animationRoot);
    Serial.print("Success?:");
    Serial.println(animationRoot.name());
    animation = animationRoot.openNextFile();
    Serial.println(animation.name());
    //NextAnimation();
    Serial.println("Initialization Animation... done..");
}

void AnimationSD::NextFrame()
{
  //Rewind to the begining of the animation if we aren't able to read from it.
  if(!animation.available())
  {
    //Serial.println("Rewind Animation");
    animation.seek(0);
  }
  size_t bytesRead = animation.readBytes((char*)leds,ledCount*sizeof(CRGB));
  if(bytesRead != (ledCount*sizeof(CRGB)))
  {
    //Serial.print("bytesRead:");
    //Serial.print(bytesRead, DEC);
    //Serial.println("failed");
  }
  
}

void AnimationSD::NextAnimation()
{
  Serial.println("NextAnimation");
    if(animation)
    {
        animation.close();
    }
    
    animation = animationRoot.openNextFile();
    if(!animation) //We have gone through all animations so reopen to loop
    {
      Serial.println("openNextFile() failed");
        animationRoot.close();
        animationRoot = SD.open(AnimationDir);
        animation = animationRoot.openNextFile();
    }
}

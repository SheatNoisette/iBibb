/*
Copyright 2017 iBibb Team

Permission is hereby granted, free of charge, to any person obtaining a 
copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall 
be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
DEALINGS IN THE SOFTWARE.
 */

void InitRelais ()
{
  //bool RelaisLedOn, RelaisPompeOn;
  pinMode(RELAISLED, OUTPUT); //Définition des sorties
  pinMode(RELAISPOMPE, OUTPUT);
  digitalWrite(RELAISLED, LOW);
  digitalWrite(RELAISPOMPE, LOW);
  RelaisLedOn = false;
  RelaisPompeOn = false;
  Serial.println("Relais initalises");
}

//Relais ON / OFF

void AllumerRelais(int Relais)
{
  if (Relais == 1)
  {
    digitalWrite(RELAISLED, HIGH);
    Serial.println("Relay 'led' on!");
    RelaisLedOn = true;
  }
  if (Relais == 2)
  {
    digitalWrite(RELAISPOMPE, HIGH);
    Serial.println("Relay 'pompe' on!");
    RelaisPompeOn = true;
  }
}

//éteindre
void EteindreRelais(int Relais)
{
  if (Relais == 1)
  {
    digitalWrite(RELAISLED,LOW);
    Serial.println("Relay 'led' off!");
    RelaisLedOn = false;
  }
  if (Relais == 2)
  {
    digitalWrite(RELAISPOMPE, LOW);
    Serial.println("Relay 'pompe' off!");
    RelaisPompeOn = false;
  }
}


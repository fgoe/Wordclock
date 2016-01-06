

//=========================================================
//
// GoFlo Wordclock Version 1.5
// -------------------------------
//
//
// GoFlo 28.09.14
//
//
// File für zweite Uhr !!!!
//
// Updates:
// ----------
// 
// - Einsatz von neuer DCF Library
// - Funktionen in Functions ausgelagert
// - setBrightness Funktion
// - Dimmung der LEDs mit Tageszeitsteuerung
//
//==========================================================


// DCF77 Library einbinden
#include <DCF77.h>
#include <Time.h>

// Eingangspin für den DCF Empfänger
#define DCF_PIN 2

// Interrupt für den Empfänger
#define DCF_INTERRUPT 0


// Variablen definieren für LED Ausgänge und PIN Nummer zuweisen
const int es          = 53;
const int ist         = 49;
const int fuenfmin    = 33;
const int zehnmin     = 47;
const int viertel     = 28;
const int zwanzig     = 24;
const int halb        = 50;
const int dreiv       = 44;
const int vor         = 45;
const int nach        = 34;

const int ein         = 46;
const int s           = 51;
const int zwei        = 31;
const int drei        = 52;
const int vier        = 30;
const int fuenf       = 26;
const int f           = 32;
const int sechs       = 40;
const int sieben      = 43;
const int acht        = 29;
const int neun        = 38;
const int zehn        = 42;
const int neunzehnN   = 48;
const int elf         = 35;
const int zwoelf      = 25;
const int uhr         = 27;


// Uhrenvariablen initialisieren
int tmpmonth = 8;
int tmphour = 11;
int tmpminute = 12;
int tmpyear = 2014;
int tmpday = 21;
int tmpsecond = 0;
int displaydelay = 1;
int timeon = 1000;
int timeoff = 1;

// Variable für den Anzeigentest
int testdelay = 2000;

// Neues DCF Objekt erstellen, Variable ist der digitale 
// Eingangspin auf dem Arduino-Board
DCF77 funkuhr=DCF77(DCF_PIN,DCF_INTERRUPT,true);




// Arduino Setup
// -----------------------------------------------------
void setup() {                

  // Serial starten
  Serial.begin(9600);

  // Ausgabe auf serieller Konsole
  Serial.println("-- Wordclock 1.5 by GoFlo -- "); 
  Serial.println("---------------------------- "); 
  Serial.println(" "); 
  Serial.println("-- Setup wird durchgefuehrt -- "); 
  Serial.println("    . Variablen initialisiert");
  
  // LED Pins als Outputs festlegen
  pinMode(es, OUTPUT); 
  pinMode(ist, OUTPUT); 
  pinMode(fuenfmin, OUTPUT); 
  pinMode(zehnmin, OUTPUT); 
  pinMode(viertel, OUTPUT); 
  pinMode(zwanzig, OUTPUT); 
  pinMode(halb, OUTPUT);
  pinMode(dreiv, OUTPUT);
  pinMode(viertel, OUTPUT); 
  pinMode(vor, OUTPUT); 
  pinMode(nach, OUTPUT); 
  pinMode(ein, OUTPUT); 
  pinMode(s, OUTPUT); 
  pinMode(f, OUTPUT);
  pinMode(zwei, OUTPUT);
  pinMode(drei, OUTPUT);  
  pinMode(vier, OUTPUT);
  pinMode(fuenf, OUTPUT); 
  pinMode(sechs, OUTPUT); 
  pinMode(sieben, OUTPUT); 
  pinMode(acht, OUTPUT); 
  pinMode(neun, OUTPUT); 
  pinMode(zehn, OUTPUT); 
  pinMode(elf, OUTPUT); 
  pinMode(zwoelf, OUTPUT); 
  pinMode(uhr, OUTPUT); 
  pinMode(neunzehnN, OUTPUT);
  
  Serial.println("    . Pinmodes festgelegt"); 
 
  // Ausgänge auf LOW setzen / ausschalten
  digitalWrite(fuenfmin, LOW);
  digitalWrite(zehnmin, LOW);
  digitalWrite(dreiv, LOW);
  digitalWrite(viertel, LOW);
  digitalWrite(zwanzig, LOW);
  digitalWrite(halb, LOW);
  digitalWrite(vor, LOW);
  digitalWrite(nach, LOW);
  digitalWrite(ein, LOW);
  digitalWrite(s, LOW);
  digitalWrite(f, LOW);
  digitalWrite(zwei, LOW);
  digitalWrite(drei, LOW);
  digitalWrite(vier, LOW);
  digitalWrite(fuenf, LOW);
  digitalWrite(sechs, LOW);
  digitalWrite(sieben, LOW);
  digitalWrite(acht, LOW);
  digitalWrite(neun, LOW);
  digitalWrite(zehn, LOW);
  digitalWrite(elf, LOW);
  digitalWrite(zwoelf, LOW);
  digitalWrite(uhr, LOW);
  digitalWrite(neunzehnN, LOW);
  digitalWrite(es, LOW);
  digitalWrite(ist, LOW);
  
  Serial.println("    . Alle Ausgaenge auf LOW");
  
  // Uhr starten
  funkuhr.Start();
  Serial.println("    . Uhr starten");
  
  // Ausgabe Setup fertig
  Serial.println("-- Setup done -- "); 
  Serial.println(" "); 
  
  testled();
    
}  //Ende void setup()




// Anzeigentest
// ----------------------------------------------------------
void testled() {
  
  // Die einzelnen Anzeige einmal durchschalten
     Serial.println(" ");
     Serial.println("-- Anzeigentest gestartet -- "); 
  
     digitalWrite(es, LOW);
     digitalWrite(ist, LOW);
  
     Serial.println("    . Wort ES");
     digitalWrite(es, HIGH);
     delay(testdelay);
     digitalWrite(es,LOW);
  
     Serial.println("    . Wort IST");
     digitalWrite(ist, HIGH);
     delay(testdelay);
     digitalWrite(ist,LOW);
     
     Serial.println("    . Wort FUENF");
     digitalWrite(fuenfmin, HIGH);
     delay(testdelay);
     digitalWrite(fuenfmin,LOW);
     
     Serial.println("    . Wort ZEHN");
     digitalWrite(zehnmin, HIGH);
     delay(testdelay);
     digitalWrite(zehnmin,LOW);
     
     Serial.println("    . Wort VIERTEL");
     digitalWrite(viertel, HIGH);
     delay(testdelay);
     digitalWrite(viertel,LOW);
          
     Serial.println("    . Wort ZWANZIG");
     digitalWrite(zwanzig, HIGH);
     delay(testdelay);
     digitalWrite(zwanzig,LOW);          
     
     Serial.println("    . Wort VOR");
     digitalWrite(vor, HIGH);
     delay(testdelay);
     digitalWrite(vor,LOW);
     
     Serial.println("    . Wort NACH");
     digitalWrite(nach, HIGH);
     delay(testdelay);
     digitalWrite(nach,LOW);
     
     Serial.println("    . Wort HALB");
     digitalWrite(halb, HIGH);
     delay(testdelay);
     digitalWrite(halb,LOW);
     
     Serial.println("    . Wort DREIVIERTEL");
     digitalWrite(dreiv, HIGH);
     digitalWrite(viertel, HIGH);
     delay(testdelay);
     digitalWrite(dreiv,LOW);
     digitalWrite(viertel, LOW);
     
     Serial.println("    . Wort EIN");
     digitalWrite(ein, HIGH);
     delay(testdelay);
     digitalWrite(ein,LOW);
     
     Serial.println("    . Wort EINS");
     digitalWrite(ein, HIGH);
     digitalWrite(s, HIGH);
     delay(testdelay);
     digitalWrite(ein,LOW);
     digitalWrite(s, LOW);
     
     Serial.println("    . Wort ZWEI");
     digitalWrite(zwei, HIGH);
     delay(testdelay);
     digitalWrite(zwei,LOW);
     
     Serial.println("    . Wort DREI");
     digitalWrite(drei, HIGH);
     delay(testdelay);
     digitalWrite(drei,LOW);
     
     Serial.println("    . Wort VIER");
     digitalWrite(vier, HIGH);
     delay(testdelay);
     digitalWrite(vier,LOW);
     
     Serial.println("    . Wort FUENF");
     digitalWrite(fuenf, HIGH);
     digitalWrite(f, HIGH);
     delay(testdelay);
     digitalWrite(fuenf,LOW);
     digitalWrite(f, LOW);
     
     Serial.println("    . Wort SECHS");
     digitalWrite(sechs, HIGH);
     delay(testdelay);
     digitalWrite(sechs,LOW);
     
     Serial.println("    . Wort SIEBEN");
     digitalWrite(sieben, HIGH);
     delay(testdelay);
     digitalWrite(sieben,LOW);
     
     Serial.println("    . Wort ACHT");
     digitalWrite(acht, HIGH);
     delay(testdelay);
     digitalWrite(acht,LOW);
     
     Serial.println("    . Wort NEUN");
     digitalWrite(neun, HIGH);
     digitalWrite(neunzehnN, HIGH);
     delay(testdelay);
     digitalWrite(neun, LOW);
     digitalWrite(neunzehnN, LOW);
     
     Serial.println("    . Wort ZEHN");
     digitalWrite(zehn, HIGH);
     digitalWrite(neunzehnN, HIGH);
     delay(testdelay);
     digitalWrite(zehn,LOW);
     digitalWrite(neunzehnN, LOW);
     
     Serial.println("    . Wort ELF");
     digitalWrite(elf, HIGH);
     digitalWrite(f, HIGH);
     delay(testdelay);
     digitalWrite(elf,LOW);
     digitalWrite(f, LOW);
     
     Serial.println("    . Wort ZWOELF");
     digitalWrite(zwoelf, HIGH);
     delay(testdelay);
     digitalWrite(zwoelf,LOW);
     
     Serial.println("    . Wort UHR");
     digitalWrite(uhr, HIGH);
     delay(testdelay);
     digitalWrite(uhr,LOW);
          
     Serial.println("-- Anzeigentest beendet -- ");
     Serial.println(" ");
          
} //Ende ledtest()




// Berechnung der Uhrzeit
// ----------------------------------------------------------
void readclock() {
  
  // Zeit aus Empfänger lesen
  time_t DCFtime = funkuhr.getTime();
  if (DCFtime!=0)
  {
    //Serial.println("Time is updated");
    setTime(DCFtime);
    }
  
  // In Zwischenvariablen kopieren
  tmpmonth = month();
  tmphour = hour();
  tmpminute = minute();
  tmpyear = year();
  tmpday = day();
  tmpsecond = second();
  
  // Zeit auf Konsole ausgeben
  //Serial.print(hour());
  //printDigits(minute());
  //printDigits(second());
  //Serial.print(" ");
  //Serial.print(day());
  //Serial.print(" ");
  //Serial.print(month());
  //Serial.print(" ");
  //Serial.print(year());
  //Serial.println(); 
    
}  // Ende readclock()


// Zahlanpassung für Konsole
// ---------------------------------------------------
void printDigits(int digits){
  
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
  
}  // Ende printDigits()


// Displayanzeigedauer für Helligkeit
// ---------------------------------------------------
void setBrightness(){
  
  // Tagmodus
  if ( tmphour >= 8 && tmphour < 20 ) {
    
      // timeon=9999, timeon=
    
      // set brightness delay
      timeon = 1000;
      timeoff= 1;
  }
  
  
  // Nachtmodus
   if ( tmphour >= 23 && tmphour < 4 ) {
    
      // set brightness delay
      timeon = 50;
      timeoff = 1000;
   }
   
   
  // Dämmerungsmodus
   if ( (tmphour >= 4 && tmphour <= 7) || ( tmphour >= 20 && tmphour < 23 )) {
   
      // set brightness delay
      timeon = 300;
      timeoff = 1000;
   }
     
   // Ausgabe der aktuellen Werte auf serielle Konsole
   //Serial.print("Delaywert: ");
   //Serial.print(timeon);
   //Serial.print(" microseconds");
   //Serial.println();  
   
}  // Ende setBrightness()



// Alle LEDs aus
// ----------------------------------------------------------
void allLEDoff() {
  
   digitalWrite(fuenfmin, LOW);
   digitalWrite(zehnmin, LOW);
   digitalWrite(dreiv, LOW);
   digitalWrite(viertel, LOW);
   digitalWrite(zwanzig, LOW);
   digitalWrite(halb, LOW);
   digitalWrite(vor, LOW);
   digitalWrite(nach, LOW);
   digitalWrite(ein, LOW);
   digitalWrite(s, LOW);
   digitalWrite(f, LOW);
   digitalWrite(zwei, LOW);
   digitalWrite(drei, LOW);
   digitalWrite(vier, LOW);
   digitalWrite(fuenf, LOW);
   digitalWrite(sechs, LOW);
   digitalWrite(sieben, LOW);
   digitalWrite(acht, LOW);
   digitalWrite(neun, LOW);
   digitalWrite(zehn, LOW);
   digitalWrite(elf, LOW);
   digitalWrite(zwoelf, LOW);
   digitalWrite(uhr, LOW);
   digitalWrite(neunzehnN, LOW);
   digitalWrite(es, LOW);
   digitalWrite(ist, LOW);
   
}


// LEDs schalten
// -----------------------------------------------------------
void switchled() {
  
  // "Es ist" anschalten
  digitalWrite(es, HIGH);
  digitalWrite(ist, HIGH);
  
  // Auswertung Stunden und Schalten der LEDs
  switch (tmphour) {
      case 1:
      case 13:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, HIGH);
          digitalWrite(f, LOW);
          digitalWrite(ein, HIGH);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, HIGH);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW); 
        }
      break;
    
      case 2:
      case 14:
        if ( tmpminute >= 0 && tmpminute <=24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, HIGH);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, HIGH);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
    
      case 3:
      case 15:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, HIGH);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, HIGH);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
    
      case 4:
      case 16:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, HIGH);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, HIGH);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, HIGH);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
        
      case 5:
      case 17:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, HIGH);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, HIGH);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, HIGH);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
    
      case 6:
      case 18:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, HIGH);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, HIGH);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
        
      case 7:
      case 19:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, HIGH);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, HIGH);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
        
      case 8:
      case 20:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, HIGH);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, HIGH);
          digitalWrite(neunzehnN, HIGH);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
    
      case 9:
      case 21:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, HIGH);
          digitalWrite(neunzehnN, HIGH);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, HIGH);
          digitalWrite(zehn, HIGH);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
        
      case 10:
      case 22:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, HIGH);
          digitalWrite(zehn, HIGH);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, HIGH);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, HIGH);
          digitalWrite(zwoelf, LOW);
        }
      break;
        
      case 11:
      case 23:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, HIGH);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, HIGH);
          digitalWrite(zwoelf, LOW);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, HIGH);
        }
      break;
        
      case 12:
      case 0:
        if ( tmpminute >= 0 && tmpminute <= 24 ) {
          digitalWrite(s, LOW);
          digitalWrite(f, LOW);
          digitalWrite(ein, LOW);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, HIGH);
        }
        if ( tmpminute >= 25 && tmpminute <= 59 ) {
          digitalWrite(s, HIGH);
          digitalWrite(f, LOW);
          digitalWrite(ein, HIGH);
          digitalWrite(zwei, LOW);
          digitalWrite(drei, LOW);
          digitalWrite(vier, LOW);
          digitalWrite(fuenf, LOW);
          digitalWrite(sechs, LOW);
          digitalWrite(sieben, LOW);
          digitalWrite(acht, LOW);
          digitalWrite(neun, LOW);
          digitalWrite(neunzehnN, LOW);
          digitalWrite(zehn, LOW);
          digitalWrite(elf, LOW);
          digitalWrite(zwoelf, LOW);
        }
      break;
      
      default:
        Serial.println("Case Hour hat nicht gegriffen");
     }
         
    // Auswertung der Minuten und schalten der LEDs
      
	// Punkt xy Uhr
        if (tmpminute >=0 && tmpminute <= 4) {
		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, HIGH);
	}

	// 5 nach
    	if (tmpminute >=5 && tmpminute <= 9) {
      		digitalWrite(fuenfmin, HIGH);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, HIGH);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
	}

	// 10 nach
    	if (tmpminute >= 10 && tmpminute <= 14) {
      		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, HIGH);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, HIGH);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}

    	// 15 nach
    	if (tmpminute >= 15 && tmpminute <= 19) {
      		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, HIGH);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, HIGH);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}
    
	// 20 nach
    	if (tmpminute >= 20 && tmpminute <= 24) {
      		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, HIGH);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, HIGH);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}
    
    	// 25 nach
    	if (tmpminute >= 25 && tmpminute <= 29) {
      		digitalWrite(fuenfmin, HIGH);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, HIGH);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, HIGH);
      		digitalWrite(uhr, LOW);
	}
        
    	// halb
    	if (tmpminute >= 30 && tmpminute <= 34) {
	      	digitalWrite(fuenfmin, LOW);
	      	digitalWrite(zehnmin, LOW);
     		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, HIGH);
      		digitalWrite(uhr, LOW);
    	}

    	// 35 nach
    	if (tmpminute >= 35 && tmpminute <= 39) {
      		digitalWrite(fuenfmin, HIGH);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, HIGH);
      		digitalWrite(halb, HIGH);
      		digitalWrite(uhr, LOW);
    	}
    
    	// zwanzig vor
    	if (tmpminute >= 40 && tmpminute <= 44) {
      		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, HIGH);
      		digitalWrite(vor, HIGH);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}
    
    	// viertel vor
    	if (tmpminute >= 45 && tmpminute <= 49) {
		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, HIGH);
      		digitalWrite(viertel, HIGH);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, LOW);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}
 
    	// 10 vor
     	if (tmpminute >= 50 && tmpminute <= 54) {
      		digitalWrite(fuenfmin, LOW);
      		digitalWrite(zehnmin, HIGH);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, HIGH);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}
  
    	// 5 vor
    	if (tmpminute >= 55 && tmpminute <= 59) {
      		digitalWrite(fuenfmin, HIGH);
      		digitalWrite(zehnmin, LOW);
      		digitalWrite(dreiv, LOW);
      		digitalWrite(viertel, LOW);
      		digitalWrite(zwanzig, LOW);
      		digitalWrite(vor, HIGH);
      		digitalWrite(nach, LOW);
      		digitalWrite(halb, LOW);
      		digitalWrite(uhr, LOW);
    	}
  
}


// Hauptloop
// -----------------------------------------------------------
void loop() {
  
  // Uhrzeit berechnen
  readclock();
  
  // Helligkeit einstellen
  setBrightness();
    
  // LEDs schalten
  switchled();
  delayMicroseconds(timeon);
  allLEDoff();
  delayMicroseconds(timeoff); 
   
} // Ende Hauptloop 


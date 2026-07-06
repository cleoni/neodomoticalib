#ifndef NEODOMOTICALIB_H
#define NEODOMOTICALIB_H

#include <Arduino.h> // Serve per riconoscere i comandi Arduino come pinMode, digitalWrite, ecc.

class NeodomoticaLib {
  public:
    // Costruttore
    NeodomoticaLib();

    // Una funzione di esempio per fare il lampeggio di un LED senza usare delay()
    void lampeggiaLed(int pin, unsigned long intervallo);

    // Una funzione per calcolare una percentuale (es. per sensori)
    float calcolaPercentuale(float valore, float massimo);
	
	String urlencode(String str);	

	String urldecode(String str);
    
  private:
    unsigned long _precedenteMillis; // Variabile interna privata
};

#endif
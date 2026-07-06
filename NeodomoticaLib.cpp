#include "NeodomoticaLib.h"

// Costruttore: inizializza le variabili interne
NeodomoticaLib::NeodomoticaLib() {
  _precedenteMillis = 0;
}

// Implementazione del lampeggio non bloccante
void NeodomoticaLib::lampeggiaLed(int pin, unsigned long intervallo) {
  pinMode(pin, OUTPUT); // Assicura che il pin sia in modalità OUTPUT
  
  unsigned long correnteMillis = millis();
  if (correnteMillis - _precedenteMillis >= intervallo) {
    _precedenteMillis = correnteMillis;
    digitalWrite(pin, !digitalRead(pin)); // Inverte lo stato attuale del LED
  }
}

// Implementazione della funzione percentuale
float NeodomoticaLib::calcolaPercentuale(float valore, float massimo) {
  if (massimo == 0) return 0; // Evita la divisione per zero
  return (valore / massimo) * 100.0;
}

String NeodomoticaLib::urldecode(String str) {
    String decoded = "";
    char ch;
    int i, j;
    for (i = 0; i < str.length(); i++) {
        if (str[i] == '+') {
            decoded += ' '; // Il '+' nel form era uno spazio
        } else if (str[i] == '%') {
            // Gestisce i caratteri codificati in esadecimale (es. %2B per il '+')
            sscanf(str.substring(i + 1, i + 3).c_str(), "%x", &j);
            ch = static_cast<char>(j);
            decoded += ch;
            i += 2;
        } else {
            decoded += str[i];
        }
    }
    return decoded;
}


String NeodomoticaLib::urlencode(String str) {
  String encodedString = "";
  for (int i = 0; i < str.length(); i++) {
    char c = str.charAt(i);
    if (c == ' ') {
      encodedString += "%20";
    } else if (isalnum(c)) {
      encodedString += c;
    } else {
      encodedString += '%';
      
      // Se il valore è inferiore a 16, aggiunge lo zero di riempimento (es. %0A)
      if ((unsigned char)c < 16) {
        encodedString += '0'; 
      }
      
      // Converte il singolo carattere speciale in HEX
      String hex = String((unsigned char)c, HEX);
      hex.toUpperCase(); // Rende maiuscola SOLO la parte esadecimale (es. "3f" -> "3F")
      encodedString += hex;
    }
    yield(); 
  }
  return encodedString;
}

// Sette segmenti evoluto
// made by: Prof. Michele Maffucci  
  
// Conteggio 9 secondi con display 7 segmenti a catodo comune  
  
// definizione delle variabili a cui collegare ogni segmento del display  
// la lettera rappresenta il segmento del display il numero il pin  
// digitale di Arduino a cui è collegato il corrispondente pin del display  
  
const int a=7;  
const int b=6;  
const int c=4;  
const int d=2;  
const int e=1;  
const int f=9;  
const int g=10;  
  
void LedAcceso(int n)  
{  
  switch(n)  
  {  
  case 0:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, HIGH);  
    digitalWrite(f, HIGH);  
    digitalWrite(g, LOW);  
    break;  
  
  case 1:  
    digitalWrite(a, LOW);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, LOW);   
    digitalWrite(e, LOW);  
    digitalWrite(f, LOW);  
    digitalWrite(g, LOW);  
    break;  
  
  case 2:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, LOW);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, HIGH);  
    digitalWrite(f, LOW);  
    digitalWrite(g, HIGH);  
    break;  
  case 3:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, LOW);  
    digitalWrite(f, LOW);  
    digitalWrite(g, HIGH);  
    break;  
  
  case 4:  
    digitalWrite(a, LOW);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, LOW);   
    digitalWrite(e, LOW);  
    digitalWrite(f, HIGH);  
    digitalWrite(g, HIGH);  
    break;  
  
  case 5:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, LOW);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, LOW);  
    digitalWrite(f, HIGH);  
    digitalWrite(g, HIGH);  
    break;  
  
  case 6:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, LOW);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, HIGH);  
    digitalWrite(f, HIGH);  
    digitalWrite(g, HIGH);  
    break;  
  
  case 7:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, LOW);   
    digitalWrite(e, LOW);  
    digitalWrite(f, LOW);  
    digitalWrite(g, LOW);  
    break;  
  
  case 8:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, HIGH);  
    digitalWrite(f, HIGH);  
    digitalWrite(g, HIGH);  
    break;  
  
  case 9:  
    digitalWrite(a, HIGH);  
    digitalWrite(b, HIGH);  
    digitalWrite(c, HIGH);   
    digitalWrite(d, HIGH);   
    digitalWrite(e, LOW);  
    digitalWrite(f, HIGH);  
    digitalWrite(g, HIGH);  
    break;  
  }  
};  
  
void setup()  
{  
  pinMode(a, OUTPUT);   
  pinMode(b, OUTPUT);   
  pinMode(c, OUTPUT);   
  pinMode(d, OUTPUT);   
  pinMode(e, OUTPUT);   
  pinMode(f, OUTPUT);   
  pinMode(g, OUTPUT);  
}  
  
void loop ()  
{  
  for (int i=0;i<10;i++)   
  {  
    LedAcceso(i);  
    delay (1000);  
  }  
}  


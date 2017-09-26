# VJ9-Strukture-podataka
Vjezba 9

Napisati program koji čita iz datoteke dio teksta, te kreira binarno stablo pretraživanja. Binarno stablo se //DIO TEKSTA, JA SAM ODABRA CITAT MAX 50 RICI, AKO IMA VISE TO NECE BI PROCITANO
kreira na način da se u njega upisuju sve različite riječi iz teksta koji je zapisan u datoteci s pripadajućim
duljinama unesene riječi.
struct _Cvor{char *rijec; int length; struct _Cvor *Left; struct _Cvor *Right;};
Potrebno je izračunati prosječnu duljinu svake riječi zapisane u binarnom stablu.
Napisati program koji iz tako kreiranog binarnog stabla u vezanu listu puni samo one riječi koje su dulje
od prosječne duljine svih riječi, te ispisati tu vezanu listu.

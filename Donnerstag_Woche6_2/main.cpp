#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


// main
int main()
{
	cout << "Programm zum Donnerstag Woche 6_2" << endl << endl;

	// C-Array
	int zahlenArray[] = { 4,2,8,5 }; // Speicher reservieren für 4 Zahlen (16 Byte)

	int ersteZahl = zahlenArray[0];
	int zweiteZahl = zahlenArray[1];

	// Arrays sind nur die Adreese des 1.Elementes

	int* pZahl = zahlenArray;

	int ersteZahlMitZeiger = *pZahl;


	// Zeiger um eine int erhöhnen , 4 Byte weiterschieben
	pZahl++;
	int zweiteZahlMitZeiger = *pZahl;


	for (int i = 0; i < 4; i++)
	{
		cout << "Zahl                      " << i+1 << ".: " << zahlenArray[i] << endl;
		
		cout <<	"Zahl mit Zeigerarithmetik " << i+1 << ".: " << *(zahlenArray + i) << endl;
	}


	//////////////////////////////////////////////////////////////////////////////////////////////////////


	// Vector aus der C++ Standardbibliothek
	vector<int> zahlenVector = { 13,8,18,9 };

	// Wörterbuch
	map<int, double> dic = { {3, 6.6}, {4,5.5} };


	// Zugriff auf einzelne Werte des Vectors
	int ersteZahlImVector = zahlenVector[0];
	int zweiteZahlImVector = zahlenVector.at(1);


	// Iterator = Zeiger, der auf ein Listenelement zeigt
	// Mehtode begin liefert einen Zeiger auf das erste Element zurück
	vector<int>::iterator iterator = zahlenVector.begin();

	// Zugriff aus den Wert an dieser Adresse mit Dereferzierung
	int ersteZahlMitIterator = *iterator;

	cout << ersteZahlMitIterator << " " << iterator._Ptr << " " << &(*iterator) << endl;

	// zum nächsten Element in der Liste gehen
	iterator++;

	int zweiteZahlMitIterator = *iterator;

	// von der angangsadrese zwei Elemente weiter gehen
	int dritteZahlImVector = *(zahlenVector.begin() + 2);

	cout << dritteZahlImVector << endl;

	// am Ende der Liste eine neue Zahl anfügen
	zahlenVector.push_back(99);

	// zuweisung des iterators ganz oben,
	// danach wurde die liste, durch pushback geändert
	// beim ausführen wird dann hier gemecket und das programm kackt ab

	// also quasi nochmal die geänderte liste neu zuweisen
	// um im anschluss sooweit weiter schieben, wo eine zahl geinsertrt werden soll
	iterator = zahlenVector.begin();
	iterator++;
	// Zahl an der zweiten Stelle anfügen
	zahlenVector.insert(iterator, 40);


	// geht auch so , zahl an vierter Stelle einfügen
	zahlenVector.insert(zahlenVector.begin() + 3, 55);

	
	for (int i = 0; i < zahlenVector.size(); i++)
	{
		cout << "Zahl an der " << i + 1 << ". Stelle: " << zahlenVector[i] << endl;
	}


	// Liste der Zahlen sortieren

	sort(zahlenVector.begin(), zahlenVector.end());


	// Methode end liefert das gedachte Elemente hinter der Liste zurück
	//zahlenVector.end()

	for (vector<int>::iterator iter = zahlenVector.begin(); iter != zahlenVector.end(); iter++)
	{
		cout << "Iteratorschleife: " << *iter << endl;
	}





	// Reihenfolge der Liste umdrehen
	reverse(zahlenVector.begin(), zahlenVector.end());

	
	for (vector<int>::iterator iter = zahlenVector.begin(); iter != zahlenVector.end(); iter++)
	{
		cout << "Iteratorschleife: " << *iter << endl;
	}


	auto AdresseKleinstesElement = min_element(zahlenVector.begin(), zahlenVector.end());
	cout << "Kleinste Zahl: " << *AdresseKleinstesElement << endl;




	vector<string> namesVector = {"Daniel","Esel","Unicorn","Squirrel","Bla"};
	sort(namesVector.begin(), namesVector.end());
	
	for (auto iter : namesVector)
	{
		cout << iter << endl;
	}





	system("pause");
	return 0;
}
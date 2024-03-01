#include<iostream>
#include<clocale>

using namespace std;
typedef struct Element* po;
struct Element {
	int Pole1;
	float Pole2;
	char Pole3;
};
void main() {
	setlocale(LC_ALL, "Bulgarian");
	po p;
	p = new  Element;
	cin >> p->Pole1;
	cin >> p->Pole2;
	cin >> p->Pole3;
	cout << p->Pole1 << " " << p->Pole2 << " " << p->Pole3 << endl;
	cout << endl;
	po q;
	q = new Element;
	cin >> q->Pole1;
	cin >> q->Pole2;
	cin >> q->Pole3;
	cout << q->Pole1 << " " << q->Pole2 << " " << q->Pole3 << endl;
	q = p;
	cout << endl;
	cout << p->Pole1 << " " << p->Pole2 << " " << p->Pole3 << endl;
	cout << q->Pole1 << " " << q->Pole2 << " " << q->Pole3 << endl;
	p->Pole1 = int(p->Pole2);
	cout << p->Pole1 << " " << p->Pole2 << " " << p->Pole3 << endl;
}

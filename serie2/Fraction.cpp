/*
Exercice 1 : Surcharge des operateurs
--------------------------------------------------------------------------------------
L'objectif de cet exercice est de définir les opérateurs de comparaisons et les opérateurs arithmétiques d'une classe Fraction en utilisant les fonctions membres et les fonctions amies.
1. Créer la classe Fraction possédant deux données membres « num » et « den » qui correspondent respectivement au numérateur et au dénominateur de la fraction.
2. Définir un constructeur d'initialisation
3. Définir une fonction membre afficher() sous form de num / den.
4. Définir les opérateurs arithmétiques (+, - , *, et / ) entre deux fractions
5. Définir les opérateurs arithmétiques (+, - , *, et / ) entre une fraction et un nombre
6. Définir les opérateurs de comparaison (==, !=, <, >, <=, >=) sur deux fractions.
7. Créer un programme de test.
*/
#include <iostream>

using namespace std;

// 1. Créer la classe Fraction possédant deux données membres « num » et « den » qui correspondent respectivement au numérateur et au dénominateur de la fraction.
class Fraction {
private:
	int num;
	int den;
public:
	// 2. Définir un constructeur d'initialisation
	Fraction(int num = 0, int den=1) {
		this->num = num;
		this->den = den;
	}
	// 3. Définir une fonction membre afficher() sous form de num / den.
	void afficher() {
		cout << num << '/' << den;
	}
	// 4. Définir les opérateurs arithmétiques(+, -, *, et / ) entre deux fractions
	Fraction operator+(Fraction& f) {
		int n = this->num * f.den + this->den * f.num;
		int d = this->den * f.den;

		Fraction f3(n, d);
		return f3;
	}
	Fraction operator-(Fraction& f) {
		int n = this->num * f.den - this->den * f.num;
		int d = this->den * f.den;

		Fraction f3(n, d);
		return f3;
	}
	Fraction operator*(Fraction& f) {
		int n = this->num * f.num;
		int d = this->den * f.den;

		Fraction f3(n, d);
		return f3;
	}
	Fraction operator/(Fraction& f) {
		int n = this->num * f.den;
		int d = this->den * f.num;
		Fraction f3(n, d);
		return f3;
	}
	// 5. Définir les opérateurs arithmétiques (+, - , *, et / ) entre une fraction et un nombre
	Fraction operator+(int a) {
		Fraction f(a); // den == 1 par defaut
		Fraction f2 = *this + f;
		return f2;
	}
	Fraction operator-(int a) {
		Fraction f3(this->num - this->den * a, this->den);
		return f3;
	}
	Fraction operator*(int a) {
		Fraction f2(this->num * a, this->den);
		return f2;
	}
	Fraction operator/(int a) {
		Fraction f(1, a);
		Fraction f2 = *this * f;
		return f2;
	}
	friend Fraction operator+(int a, Fraction& f) {
		return f + a;
	}
	friend Fraction operator-(int a, Fraction& f) {
		Fraction f2(a * f.den - f.num, f.den);
		return f2;
	}
	friend Fraction operator*(int a, Fraction& f) {
		Fraction f2(a * f.num, f.den);
		return f2;
	}
	friend Fraction operator/(int a, Fraction& f) {
		Fraction f1(f.den, f.num), f2(a);
		Fraction f3 = f2 / f1;
		return f3;
	}
	// 6. Définir les opérateurs de comparaison (==, !=, <, >, <=, >=) sur deux fractions.
	bool operator==(Fraction& f) {
		int n1 = this->num * f.den;
		int n2 = f.num * this->den;
		return n1 == n2;
	}
	bool operator!=(Fraction& f) {
		return !(*this == f);
	}
	bool operator<(Fraction& f) {
		int n1 = this->num * f.den;
		int n2 = f.num * this->den;
		return n1 < n2;
	}
	bool operator>(Fraction& f) {
		int n1 = this->num * f.den;
		int n2 = f.num * this->den;
		return n1 > n2;
	}
	bool operator<=(Fraction& f) {
		return *this < f || *this == f;
	}
	bool operator>=(Fraction& f) {
		return *this > f || *this == f;
	}
};

int main() {
	// 7. Créer un programme de test.
	Fraction f1(1, 2);
	cout << "Fraction F1 : ";
	f1.afficher();
	Fraction f2(3, 5);
	cout << endl << "Fraction F2 : ";
	f2.afficher();
	cout <<endl<< "F1 + F2 : ";
	Fraction f3 = f1 + f2;
	f3.afficher();
	cout << endl << "F1 - F2 : ";
	Fraction f4 = f1 - f2;
	f4.afficher();
	cout << endl << "F1 * F2 : ";
	Fraction f5 = f1 * f2;
	f5.afficher();
	cout << endl << "F1 / F2 : ";
	Fraction f6 = f1 / f2;
	f6.afficher();
	cout << endl << "F1 + 5 : ";
	Fraction f7 = f1 + 5;
	f7.afficher();
	cout << endl << "3 * F2 : ";
	Fraction f8 = 3 * f2;
	f8.afficher();
	if (f1 != f2) {
		cout <<endl<< "Les fractions ne sont pas egales";
	}
	if (f2 > f1) {
		cout << endl << "La fraction la plus grande est : ";
		f2.afficher();
	}

	return 0;
}

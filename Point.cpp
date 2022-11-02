/*
Exercice 2 : Création de classe (programmation oriente objet)
------------------------------------------------------------
1. Créer une classe Point de deux attributs private: x et y
2. Créer les constructeurs de la classe Point (public): Constructeur par default, constructeur d'initialisation, constructeur de copie
3. Créer la fonction getter et setter de l'attribut x (public)
4. Créer la fonction getter et setter de l'attribut y (public)
5. Créer 3 objects 
		le premier en utilisant le constructeur par default
		le deuxieme en utilisant le constructeur d'initialisation
		le troixieme en utilisant le constructeur de copie
6. Créer une fonction pour return les coordonnées d'une point sous forme (x, y) (public)
7. Créer la fonction distance qui calcule la distance entre le point courant et le point donnée en paramètres (public)
RAPPEL: la distance entre deux points = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))
8. Afficher la distance entre deux points de votre choix
*/
#include <iostream>
#include<string>

using namespace std;

//// 1. Créer une classe Point de deux attributs private: x et y
class Point {
private:
	double x;
	double y;
//// 2. Créer les constructeurs de la classe Point (public): Constructeur par default, constructeur d'initialisation, constructeur de copie
public:
	// Constructeur par default
	Point() {
		this->x = 0;
		this->y = 0;
	}
	// constructeur d'initialisation
	Point(double abs, double ord) {
		this->x = abs;
		this->y = ord;
	}
	// constructeur de copie
	Point(const Point& p) {
		this->x = p.x;
		this->y = p.y;
	}
	//// 3. Créer la fonction getter et setter de l'attribut x (public)
	double getX() {
		return this->x;
	}
	void setX(double abs) {
		this->x = abs;
	}
	//// 4. Créer la fonction getter et setter de l'attribut y (public)
	double getY() {
		return this->y;
	}
	void setY(double ord) {
		this->y = ord;
	}
	//// 6. Créer une fonction pour return les coordonnées d'une point sous forme (x, y) (public)
	string coordonnees() {
		// La fonction to_string() pour convertir le type double et devenir de type string
		return "(" + to_string(this->x)+", "+ to_string(this->y)+")";
	}
	//// 7. Créer la fonction distance qui calcule la distance entre le point courant et le point donnees en parametres (public)
	double distance(Point p) {
		return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y,2));
	}
};

int main() {
	//// 5. Créer 3 objects
	// le premier en utilisant le constructeur par default
	Point p0;
	// le deuxieme en utilisant le constructeur d'initialisation
	Point p1(3, 9.2);
	// le troixieme en utilisant le constructeur de copie
	Point p2 = p1;

	//// 8. Afficher la distance entre deux points de votre choix
	p0.setX(2);
	p0.setY(8);
	cout << "La distance entre les points "<<p0.coordonnees()<<" et "<<p1.coordonnees()<<" est: "<<p0.distance(p1)<<endl;

	return 0;
}
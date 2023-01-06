#include <iostream>
using namespace std;
#define PI 3.14

class Figure {
protected:
	double x;
	double y;
	double z;
public:
	Figure(double x=0, double y=0, double z=0) :x(x), y(y), z(z){}
	virtual string description() {
		return "Figure";
	}
	virtual void affiche() {
		cout << x << " " << y << " " << z<<" ";
	}
	virtual double perimetre() =0;
	virtual double aire() =0;
	virtual double volume() =0;
};
class Triangle : public Figure {
private:
	double base, cote1, cote2, hauteur;
public:
	Triangle(double x, double y, double z, double b, double c1, 
		double c2, double h): Figure(x, y, z), base(b), cote1(c1), cote2(c2), 
	hauteur(h){}
	string description() {
		return "Triangle";
	}
	void affiche() {
		Figure::affiche();
		cout << base << " " << hauteur << " ";
	}
	double perimetre() {
		return base + cote1 + cote2;
	}
	double aire() {
		return (base * hauteur) / 2;
	}
	double volume() {
		return NULL;
	}
};
class Carre : public Figure {
protected:
	double largeur;
public:
	Carre(double x, double y, double z, double l) 
		: Figure(x, y, z), largeur(l) {}
	string description() {
		return "Carre";
	}
	void affiche() {
		Figure::affiche();
		cout << largeur << " ";
	}
	double perimetre() {
		return largeur * 4;
	}
	double aire() {
		return largeur * largeur;
	}
	double volume() {
		return NULL;
	}
};
class Cercle: public Figure {
protected:
	double rayon;
public:
	Cercle(double x, double y, double z, double rayon):Figure(x, y, z) {
		this->rayon = rayon;
	}
	string description() {
		return "Cercle";
	}
	void affiche() {
		Figure::affiche();
		cout << rayon << " ";
	}
	double perimetre() {
		return 2 * PI * rayon;
	}
	double aire() {
		return PI * rayon * rayon;
	}
	double volume() {
		return NULL;
	}
};
class Cube: public Carre {
public:
	Cube(double x, double y, double z, double largeur) :Carre(x, y, z, largeur) {}
	string description() {
		return "Cube";
	}
	// pas besoin de fonction affiche()
	double perimetre() {
		return NULL;
	}
	double aire() {
		return Carre::aire() * 6; // 6 faces
	}
	double volume() {
		return largeur * largeur * largeur;
	}
};

class Rectangle: public Carre {
protected:
	double longueur;
public:
	Rectangle(double x, double y, double z, double largeur, double longueur) :Carre(x, y, z, largeur) {
		this->longueur = longueur;
	}
	string description() {
		return "Rectangle";
	}
	void affiche() {
		Carre::affiche();
		cout << longueur << " ";
	}
	double perimetre() {
		return (longueur + largeur ) * 2;
	}
	double aire() {
		return largeur * longueur;
	}
	double volume() {
		return NULL;
	}
};
class Sphere : public Cercle {
public:
	Sphere(double x, double y, double z, double rayon):Cercle(x, y, z, rayon){}
	string description() {
		return "Sphere";
	}
	// pas besoin de redefinir la fonction affiche()
	double perimetre() {
		return NULL;
	}
	double aire() {
		return 4 * PI * rayon * rayon;
	}
	double volume() {
		return (4 * PI * rayon * rayon * rayon) / 3;
	}
};
class Parallelepipedes : public Rectangle {
private:
	double hauteur;
	double dx;
	double dy;
public:
	Parallelepipedes(double x, double y, double z, double largeur, double longueur,
		double hauteur, double dx, double dy) :
		Rectangle(x, y, z, largeur, longueur) {
		this->hauteur = hauteur;
		this->dx = dx;
		this->dy = dy;
	}
	string description() {
		return "Parallelepipedes";
	}
	void affiche() {
		Rectangle::affiche();
		cout << hauteur << " ";
		cout << dx << " ";
		cout << dy << " ";
	}
	double perimetre() {
		return largeur + longueur + dx + dy;
	}
	double aire() {
		return (dx + dy)*hauteur/2;
	}
	double volume() {
		return NULL;
	}
};

// function
void afficherInfos(Figure& f) {
	cout << "Je suis un(e) " << f.description() << endl;
	cout << "Mes attributs sont : ";
	f.affiche();
	cout << endl;
}

int main() {
	Triangle t(0, 0, 0, 5, 0, 0, 8);
	afficherInfos(t);
	Carre c(0, 0, 0, 4);
	afficherInfos(c);
	return 0;
}


using namespace System::Drawing;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };
class CComponentes {
protected:
	int x, y, dx, dy;
	int ancho, alto;
	int indicex, indicey;
	Direcciones ultimaTecla;
	Direcciones direccion;

public:
	CComponentes() {};
	CComponentes(int _x, int _y) {
		x = _x;
		y = _y;
		dx = 0;
		dy = 0;
		ultimaTecla = Abajo;
		direccion = Ninguna;
		indicex = 0;
		indicey = 0;
	}
	~CComponentes() {};
	void setX(int x) {this->x = x;}
	void setY(int y) {this->y = y;}

	int getX() {return this->x;}
	int getY() {return this->y;}

	void setDirecciones(Direcciones _direccion) { x = _direccion; }
	int getDireccion() { return direccion; }

	void pintar(BufferedGraphics^ bf, Bitmap^mapa) {
		Rectangle areaUsar = Rectangle(ancho * indicex, alto * indicey, ancho, alto);
		Rectangle areaDibujar = Rectangle(ancho * indicex, alto * indicey, ancho * 1.2, alto * 1.2);
		bf->Graphics->DrawImage(mapa, areaDibujar, areaUsar, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}

	void cambioPosicion(BufferedGraphics^ bf, Bitmap^ mapa) {
		
	}
};

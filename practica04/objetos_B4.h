//**************************************************************************
// Pr�ctica IG usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "file_ply_stl.hpp"

using namespace std;

const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID_CHESS,SOLID,SOLID_ILLUMINATED_FLAT,
             SOLID_ILLUMINATED_GOURAUD} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase tri�ngulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw_iluminacion_plana( );
void 	draw_iluminacion_suave( );

void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

void	calcular_normales_caras();
void 	calcular_normales_vertices();

//void setCoeficients(_vertex4f ambiente_difusa, _vertex4f especular, float brillo);

vector<_vertex3i> caras;

vector<_vertex3f> normales_caras;
vector<_vertex3f> normales_vertices;

bool b_normales_caras;
bool b_normales_vertices;

_vertex4f ambiente_difusa;     //coeficientes ambiente y difuso
_vertex4f especular;           //coeficiente especular
float brillo;                  //exponente del brillo 

};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

int   parametros(char *archivo);
};

//************************************************************************
// objeto por revoluci�n
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
void  parametros(vector<_vertex3f> perfil1, int num1, int tapas);

vector<_vertex3f> perfil; 
int num;
};


//************************************************************************
// objeto articulado: tanque
//************************************************************************

class _chasis: public _triangulos3D
{
public:
       _chasis();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;

protected:
_rotacion  rodamiento;
_cubo  base;
};

//************************************************************************

class _torreta: public _triangulos3D
{
public:
       _torreta();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float altura;
float anchura;

protected:
_cubo  base;
_piramide parte_trasera;
};

//************************************************************************

class _tubo: public _triangulos3D
{
public:
       _tubo();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

protected:
_rotacion tubo_abierto; // ca�a del ca��n
};

//************************************************************************

class _tanque: public _triangulos3D
{
public:
       _tanque();
void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

float giro_tubo;
float giro_torreta;

float giro_tubo_min;
float giro_tubo_max;

protected:
_chasis  chasis;
_torreta  torreta;
_tubo     tubo;
};


//*************************************************************************
// clase cono
//*************************************************************************

class _cono: public _triangulos3D
{
public:
       _cono();
void  parametros(vector<_vertex3f> perfil, int numero_rotaciones);
_vertex3f proyeccion_y(const _vertex3f &vertice);

};

//*************************************************************************
// clase cilindro
//*************************************************************************

class _cilindro: public _triangulos3D
{
public:
       _cilindro();
void  parametros(vector<_vertex3f> perfil, int numero_rotaciones, const int eje);
_vertex3f proyeccion_eje(const _vertex3f &vertice, const int eje);
};


//*************************************************************************
// clase esfera
//*************************************************************************

class _esfera: public _triangulos3D
{
public:
       _esfera();
void  parametros(vector<_vertex3f> perfil, int numero_rotaciones);
_vertex3f proyeccion_y(const _vertex3f &vertice);
};

//***************************************************************************
class _pierna: public _triangulos3D 
{
       public:
       _pierna();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, int orientacion);

       protected:
       _cilindro pierna;
       _cilindro pie;
};


class _cabeza: public _triangulos3D 
{
       public:
       _cabeza();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);

       protected:
       _cono sombrero, nariz;
       _esfera cabeza, ojo_derecho, ojo_izquierdo;
};


class _brazo: public _triangulos3D 
{
       public:
       _brazo();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, int orientacion);

       protected:
       _cilindro brazo, mano;
};

class _espantapajaros: public _triangulos3D
{
       public:
       _espantapajaros();
       void 	draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor);
       void animacion();

       float giro_cabeza;
       float giro_brazos;
       float giro_piernas;
       float mover;
       bool animar;
       bool animar_brazos, animar_piernas;

       float giro_pierna_min, giro_pierna_max;
       float giro_brazo_min, giro_brazo_max;
       float giro_cabeza_min, giro_cabeza_max;

       protected:
       _pierna derecha, izquierda;
       _brazo derecho, izquierdo;
       _cabeza cabeza;
       _cilindro tronco;
};

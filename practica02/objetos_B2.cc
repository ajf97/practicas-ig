//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (unsigned int i=0; i<vertices.size(); i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (unsigned int i=0; i<caras.size(); i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLES);
	for (unsigned int i=0; i<caras.size(); i++)
	{
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(r1, g1, b1);
	glBegin(GL_TRIANGLES);
	for (unsigned int i=0; i<caras.size(); i++)
	{
		if(i % 2 == 0)
			glColor3f(r1, g1, b1);
		else
			glColor3f(r2, g2, b2);

		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
	glEnd();
}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r1, g1, b1, grosor);break;
	case EDGES:draw_aristas(r1, g1, b1, grosor);break;
	case SOLID_CHESS:draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);break;
	case SOLID:draw_solido(r1, g1, b1);break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
  // Vértices del cubo
	vertices.resize(8);

	vertices[0].x = tam; vertices[0].y = tam; vertices[0].z = tam;
	vertices[1].x = 0; vertices[1].y = tam; vertices[1].z = tam;
	vertices[2].x = 0; vertices[2].y = 0; vertices[2].z = tam;
	vertices[3].x = tam; vertices[3].y = 0; vertices[3].z = tam;
	vertices[4].x = tam; vertices[4].y = 0; vertices[4].z = 0;
	vertices[5].x = tam; vertices[5].y = tam; vertices[5].z = 0;
	vertices[6].x = 0; vertices[6].y = tam; vertices[6].z = 0;
	vertices[7].x = 0; vertices[7].y = 0; vertices[7].z = 0;

	// Caras

	caras.resize(12);

	// Cara frontal
	caras[0]._0 = 0; caras[0]._1 = 1; caras[0]._2 = 2;
	caras[1]._0 = 0; caras[1]._1 = 2; caras[1]._2 = 3;

	// Cara inferior
	caras[2]._0 = 2; caras[2]._1 = 3; caras[2]._2 = 4;
	caras[3]._0 = 2; caras[3]._1 = 4; caras[3]._2 = 7;

	// Cara trasera
	caras[4]._0 = 7; caras[4]._1 = 4; caras[4]._2 = 5;
	caras[5]._0 = 7; caras[5]._1 = 6; caras[5]._2 = 5;

	// Cara superior
	caras[6]._0 = 1; caras[6]._1 = 0; caras[6]._2 = 5;
	caras[7]._0 = 1; caras[7]._1 = 6; caras[7]._2 = 5;

	// Cara lateral izquierda
	caras[8]._0 = 1; caras[8]._1 = 7; caras[8]._2 = 6;
	caras[9]._0 = 1; caras[9]._1 = 2; caras[9]._2 = 7;

	// Cara lateral derecha
	caras[10]._0 = 0; caras[10]._1 = 4; caras[10]._2 = 3;
	caras[11]._0 = 0; caras[11]._1 = 4; caras[11]._2 = 5;

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



int _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);

// Volcamos los datos en los vectores que usamos para dibujar las caras y vértices.

int coordenada = 0;
for(int i = 0; i < n_ver; i++){
  vertices[i].x = ver_ply[coordenada];
  vertices[i].y = ver_ply[coordenada+1];
  vertices[i].z = ver_ply[coordenada+2];

  coordenada = coordenada + 3;
}


coordenada = 0;
for(int i = 0; i < n_car; i++){
  caras[i]._0 = car_ply[coordenada];
  caras[i]._1 = car_ply[coordenada+1];
  caras[i]._2 = car_ply[coordenada+2];

  coordenada = coordenada + 3;
}

return(0);
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


_vertex3f _rotacion::proyeccion_y(const _vertex3f &vertice)
{
	return _vertex3f(0, vertice.y, 0);
}


void _rotacion::parametros(vector<_vertex3f> perfil, int numero_rotaciones)
{
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*numero_rotaciones);
for (int j=0;j<numero_rotaciones;j++)
  {for (int i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*numero_rotaciones));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*numero_rotaciones));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras
for(int i = 0; i < numero_rotaciones; i++){
	for(int j = 0; j < num_aux - 1; j++){
		cara_aux.x = j + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.y = j + 1 + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.z = j + 1 + i * num_aux;

		caras.push_back(cara_aux);

		cara_aux.x = j + 1 + i * num_aux;
		cara_aux.y = j + i * num_aux;
		cara_aux.z = j + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}

     
 // tapa inferior
if (fabs(perfil[0].x)>0.0)
{
	vertices.push_back(proyeccion_y(vertices.front()));

	for(int i = 0; i < numero_rotaciones; i++) {
		cara_aux.x = i*num_aux;
		cara_aux.y = vertices.size() - 1;
		cara_aux.z = ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}
 
// tapa superior
if (fabs(perfil[num_aux-1].x)>0.0)
{
	vertices.push_back(proyeccion_y(perfil[num_aux - 1]));

	for(int i = 0; i < numero_rotaciones; i++){
		cara_aux.x = (num_aux - 1) + i * num_aux;
		cara_aux.y = (vertices.size() - 1);
		cara_aux.z = (num_aux - 1) + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}
}


//*************************************************************************
// clase cono
//*************************************************************************

_cono::_cono() {

}

_vertex3f _cono::proyeccion_y(const _vertex3f &vertice)
{
	return _vertex3f(0, vertice.y, 0);
}

void _cono::parametros(vector<_vertex3f> perfil, int numero_rotaciones)
{
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*numero_rotaciones);
for (int j=0;j<numero_rotaciones;j++)
  {for (int i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*numero_rotaciones));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*numero_rotaciones));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras
for(int i = 0; i < numero_rotaciones; i++){
	for(int j = 0; j < num_aux - 1; j++){
		cara_aux.x = j + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.y = j + 1 + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.z = j + 1 + i * num_aux;

		caras.push_back(cara_aux);

		cara_aux.x = j + 1 + i * num_aux;
		cara_aux.y = j + i * num_aux;
		cara_aux.z = j + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}

     
 // tapa inferior
if (fabs(perfil[0].x)>0.0)
{
	vertices.push_back(proyeccion_y(vertices.front()));

	for(int i = 0; i < numero_rotaciones; i++) {
		cara_aux.x = i*num_aux;
		cara_aux.y = vertices.size() - 1;
		cara_aux.z = ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}
 
// tapa superior
if (fabs(perfil[num_aux-1].x)>0.0)
{
	vertices.push_back(proyeccion_y(perfil[num_aux - 1]));

	for(int i = 0; i < numero_rotaciones; i++){
		cara_aux.x = (num_aux - 1) + i * num_aux;
		cara_aux.y = (vertices.size() - 1);
		cara_aux.z = (num_aux - 1) + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}
}


//*************************************************************************
// clase cilindro
//*************************************************************************

_cilindro::_cilindro() {

}

_vertex3f _cilindro::proyeccion_eje(const _vertex3f &vertice, const int eje)
{
	if(eje == 0){
		return _vertex3f(vertice.x, 0, 0);
	}
	else if (eje == 1){
		return _vertex3f(0, vertice.y, 0);
	}
	else{
		return _vertex3f(0, 0, vertice.z);
	}
}


void _cilindro::parametros(vector<_vertex3f> perfil, int numero_rotaciones, const int eje)
{
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*numero_rotaciones);
for (int j=0;j<numero_rotaciones;j++)
  {for (int i=0;i<num_aux;i++)
     {
	  if (eje == 1){
		   vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*numero_rotaciones));
			vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*numero_rotaciones))+
							perfil[i].z*cos(2.0*M_PI*j/(1.0*numero_rotaciones));
			vertice_aux.y=perfil[i].y;
			vertices[i+j*num_aux]=vertice_aux;
	  }
	  else if (eje == 0){
		  // Cambiamos x por y para rotar el cilindro sobre el eje x 
		   vertice_aux.y=perfil[i].y*cos(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*numero_rotaciones));
			vertice_aux.z=-perfil[i].y*sin(2.0*M_PI*j/(1.0*numero_rotaciones))+
							perfil[i].z*cos(2.0*M_PI*j/(1.0*numero_rotaciones));
			vertice_aux.x=perfil[i].x;
			vertices[i+j*num_aux]=vertice_aux;

	  }
	  else {
		 vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].y*sin(2.0*M_PI*j/(1.0*numero_rotaciones));
			vertice_aux.y=-perfil[i].x*sin(2.0*M_PI*j/(1.0*numero_rotaciones))+
							perfil[i].y*cos(2.0*M_PI*j/(1.0*numero_rotaciones));
			vertice_aux.z=perfil[i].z;
			vertices[i+j*num_aux]=vertice_aux;
	  }
     
     }
  }

// tratamiento de las caras
for(int i = 0; i < numero_rotaciones; i++){
	for(int j = 0; j < num_aux - 1; j++){
		cara_aux.x = j + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.y = j + 1 + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.z = j + 1 + i * num_aux;

		caras.push_back(cara_aux);

		cara_aux.x = j + 1 + i * num_aux;
		cara_aux.y = j + i * num_aux;
		cara_aux.z = j + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}

     
 // tapa inferior
if (fabs(perfil[0].x)>0.0)
{
	vertices.push_back(proyeccion_eje(vertices.front(), eje));

	for(int i = 0; i < numero_rotaciones; i++) {
			cara_aux.x = i*num_aux;
			cara_aux.y = vertices.size() - 1;
			cara_aux.z = ((i + 1) % numero_rotaciones) * num_aux;

			caras.push_back(cara_aux);
	}
}
 
// tapa superior
if (fabs(perfil[num_aux-1].x)>0.0)
{
	vertices.push_back(proyeccion_eje(perfil[num_aux - 1], eje));

	for(int i = 0; i < numero_rotaciones; i++){
			cara_aux.x = (num_aux - 1) + i * num_aux;
			cara_aux.y = (vertices.size() - 1);
			cara_aux.z = (num_aux - 1) + ((i + 1) % numero_rotaciones) * num_aux;

			caras.push_back(cara_aux);
	}
}
}

//*************************************************************************
// clase esfera
//*************************************************************************

_esfera::_esfera() {

}

_vertex3f _esfera::proyeccion_y(const _vertex3f &vertice)
{
	return _vertex3f(0, vertice.y, 0);
}

void _esfera::parametros(vector<_vertex3f> perfil, int numero_rotaciones)
{
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*numero_rotaciones);
for (int j=0;j<numero_rotaciones;j++)
  {for (int i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*numero_rotaciones));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*numero_rotaciones))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*numero_rotaciones));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras
for(int i = 0; i < numero_rotaciones; i++){
	for(int j = 0; j < num_aux - 1; j++){
		cara_aux.x = j + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.y = j + 1 + ((i + 1) % numero_rotaciones) * num_aux;
		cara_aux.z = j + 1 + i * num_aux;

		caras.push_back(cara_aux);

		cara_aux.x = j + 1 + i * num_aux;
		cara_aux.y = j + i * num_aux;
		cara_aux.z = j + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}

     
 // tapa inferior
if (fabs(perfil[0].x)>0.0)
{
	vertices.push_back(proyeccion_y(vertices.front()));

	for(int i = 0; i < numero_rotaciones; i++) {
		cara_aux.x = i*num_aux;
		cara_aux.y = vertices.size() - 1;
		cara_aux.z = ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}
 
// tapa superior
if (fabs(perfil[num_aux-1].x)>0.0)
{
	vertices.push_back(proyeccion_y(perfil[num_aux - 1]));

	for(int i = 0; i < numero_rotaciones; i++){
		cara_aux.x = (num_aux - 1) + i * num_aux;
		cara_aux.y = (vertices.size() - 1);
		cara_aux.z = (num_aux - 1) + ((i + 1) % numero_rotaciones) * num_aux;

		caras.push_back(cara_aux);
	}
}
}
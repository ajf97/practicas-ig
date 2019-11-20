//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B4.h"


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
//**** usando vertex_array ****
glPointSize(grosor);
glColor3f(r,g,b);

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawArrays(GL_POINTS,0,vertices.size()); 

/*int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();*/
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
//**** usando vertex_array ****
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);

glEnableClientState(GL_VERTEX_ARRAY);
glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);


/*int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();*/
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
int i;

glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
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
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	if (i%2==0) glColor3f(r1,g1,b1);
	else glColor3f(r2,g2,b2);
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
//vertices
vertices.resize(8);
vertices[0].x=-tam;vertices[0].y=-tam;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=-tam;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=tam;vertices[2].z=tam;
vertices[3].x=-tam;vertices[3].y=tam;vertices[3].z=tam;
vertices[4].x=-tam;vertices[4].y=-tam;vertices[4].z=-tam;
vertices[5].x=tam;vertices[5].y=-tam;vertices[5].z=-tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=-tam;
vertices[7].x=-tam;vertices[7].y=tam;vertices[7].z=-tam;

// triangulos
caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=3;
caras[1]._0=3;caras[1]._1=1;caras[1]._2=2;
caras[2]._0=1;caras[2]._1=5;caras[2]._2=2;
caras[3]._0=5;caras[3]._1=6;caras[3]._2=2;
caras[4]._0=5;caras[4]._1=4;caras[4]._2=6;
caras[5]._0=4;caras[5]._1=7;caras[5]._2=6;
caras[6]._0=0;caras[6]._1=7;caras[6]._2=4;
caras[7]._0=0;caras[7]._1=3;caras[7]._2=7;
caras[8]._0=3;caras[8]._1=2;caras[8]._2=7;
caras[9]._0=2;caras[9]._1=6;caras[9]._2=7;
caras[10]._0=0;caras[10]._1=1;caras[10]._2=4;
caras[11]._0=1;caras[11]._1=5;caras[11]._2=4;  
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

//if (n_ver<3 || n_car<1){
//	printf("Error %d %d\n",__FILE__,__LINE__);
//	exit(-1);
//	}

vertices.resize(n_ver);
caras.resize(n_car);

_vertex3f ver_aux;
_vertex3i car_aux;

for (int i=0;i<n_ver;i++)
	{ver_aux.x=ver_ply[i*3];
	 ver_aux.y=ver_ply[i*3+1];
	 ver_aux.z=ver_ply[i*3+2];
	 vertices[i]=ver_aux;
	}

for (int i=0;i<n_car;i++)
	{car_aux.x=car_ply[i*3];
	 car_aux.y=car_ply[i*3+1];
	 car_aux.z=car_ply[i*3+2];
	 caras[i]=car_aux;
	}

return(0);
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tapa)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*num);
for (j=0;j<num;j++)
  {for (i=0;i<num_aux;i++)
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
  }

// tratamiento de las caras 

for (j=0;j<num;j++)
  {for (i=0;i<num_aux-1;i++)
     {cara_aux._0=i+((j+1)%num)*num_aux;
      cara_aux._1=i+1+((j+1)%num)*num_aux;
      cara_aux._2=i+1+j*num_aux;
      caras.push_back(cara_aux);
      
      cara_aux._0=i+1+j*num_aux;
      cara_aux._1=i+j*num_aux;
      cara_aux._2=i+((j+1)%num)*num_aux;
      caras.push_back(cara_aux);
     }
  }
     
 // tapa inferior
if (fabs(perfil[0].x)>0.0 && tapa==1)
  {
  }
 
 // tapa superior
 if (fabs(perfil[num_aux-1].x)>0.0 && tapa==1)
  {
  }
}

//************************************************************************
// objeto articulado: tanque
//************************************************************************

_chasis::_chasis()
{
// perfil para un cilindro
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.107;aux.y=-0.5;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.107;aux.y=0.5;aux.z=0.0;
perfil.push_back(aux);
rodamiento.parametros(perfil,12,1);
altura=0.22;
};

void _chasis::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(1.0,0.22,0.95);
base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.25,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.5,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.25,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,0.0,0.0);
glRotatef(90.0,1,0,0);
rodamiento.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}

//************************************************************************

_torreta::_torreta()
{
altura=0.18;
anchura=0.65;
};

void _torreta::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
glScalef(0.65,0.18,0.6);
base.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.325,0,0);
glRotatef(90.0,0,0,1);
glScalef(0.18,0.16,0.6);
parte_trasera.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}

//************************************************************************

_tubo::_tubo()
{
// perfil para un cilindro
vector<_vertex3f> perfil;
_vertex3f aux;
aux.x=0.04;aux.y=-0.4;aux.z=0.0;
perfil.push_back(aux);
aux.x=0.04;aux.y=0.4;aux.z=0.0;
perfil.push_back(aux);
tubo_abierto.parametros(perfil,12,0);
};

void _tubo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{

glPushMatrix();
glTranslatef(0.4,0,0);
glRotatef(90.0,0,0,1);
tubo_abierto.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
}


//************************************************************************

_tanque::_tanque()
{
giro_tubo=2.0;
giro_torreta=0.0;
giro_tubo_min=-9;
giro_tubo_max=20;
};

void _tanque::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor)
{
glPushMatrix();
chasis.draw(modo, r1, g1, b1, r2, g2, b2, grosor);

glRotatef(giro_torreta,0,1,0);
glPushMatrix();
glTranslatef(0.0,(chasis.altura+torreta.altura)/2.0,0.0);
torreta.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();

glPushMatrix();
glTranslatef(torreta.anchura/2.0,(chasis.altura+torreta.altura)/2.0,0.0);
glRotatef(giro_tubo,0,0,1);
tubo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
glPopMatrix();
glPopMatrix();

};


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


//////////////////////////// Implementación práctica 3

/********************************************
 * Clase espantapájaros
 * *****************************************/

_espantapajaros::_espantapajaros(){
	giro_cabeza = 0.0;
	giro_brazos = 0.0;
	giro_piernas = 0.0;
	mover = 0.0;
	animar = false;
	animar_brazos = true;
	animar_piernas = true;
	
	giro_pierna_min=-45.0;
	giro_pierna_max=45.0;
	giro_brazo_min=-10.0;
	giro_brazo_max=10.0;
	giro_cabeza_min=-90.0;
	giro_cabeza_max=90.0;

	// Crear perfil del tronco

	vector<_vertex3f> perfilTronco;
	_vertex3f vertice;

	vertice.x=1.0; vertice.y=-1.0; vertice.z=0.0;
	perfilTronco.push_back(vertice);
	vertice.x=1.0; vertice.y=1.0; vertice.z=0.0;
	perfilTronco.push_back(vertice);

	tronco.parametros(perfilTronco, 20, 1);

}


void _espantapajaros::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	
	glTranslatef(0.0,0.0,mover);
	// Cabeza
	glPushMatrix();
	glRotatef(giro_cabeza,0,1,0);
	cabeza.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	// Tronco
	glPushMatrix();
	glScalef(0.27, 1.25, 0.27);
	glTranslatef(0.0, 1.0, 0.0);
	tronco.draw(modo, 1.0, 0.5, 0.0, 0.1, 0.0, 0.0, grosor);
	glPopMatrix();
	
	// Pierna derecha
	glPushMatrix();
	glRotatef(giro_piernas,0,1,0);
	glTranslatef(-0.65,-0.2,0.0);
	glRotatef(-45.0,0,0,1);
	derecha.draw(modo, 0.0, 0.0, 1.0, 0.65, 0.23, 1.0, grosor, 0);
	glPopMatrix();

	// Pierna izquierda
	glPushMatrix();
	glRotatef(giro_piernas,0,1,0);
	glTranslatef(0.65,-0.2,0.0);
	glRotatef(45.0,0,0,1);
	izquierda.draw(modo, 0.0, 0.0, 1.0, 0.65, 0.23, 1.0, grosor, 1);
	glPopMatrix();

	// Brazo derecho
	glPushMatrix();
	glRotatef(giro_brazos,0,0,1);
	glTranslatef(-0.5,1.5,0.0);
	glRotatef(90.0,0,0,1);
	derecho.draw(modo, r1, g1, b1, r2, g2, b2, grosor, 0);
	glPopMatrix();

	// Brazo izquierdo
	glPushMatrix();
	glRotatef(-giro_brazos,0,0,1);
	glTranslatef(0.5,1.5,0.0);
	glRotatef(90.0,0,0,1);
	izquierdo.draw(modo, r1, g1, b1, r2, g2, b2, grosor, 1);
	glPopMatrix();

}


void _espantapajaros::animacion() {
	if(animar){

		giro_cabeza+=1;

		if(animar_piernas){
			giro_piernas+=1;
			if(giro_piernas > giro_pierna_max){
				giro_piernas = giro_pierna_max;
				animar_piernas = false;
			}
		}
		if(!animar_piernas){
			giro_piernas-=1;
			if(giro_piernas < giro_pierna_min){
				animar_piernas = true;
				giro_piernas = giro_pierna_min;
			}
		}


		if(animar_brazos){
			giro_brazos+=1;
			if(giro_brazos > giro_brazo_max){
				giro_brazos = giro_brazo_max;
				animar_brazos = false;
			}
		}
		if(!animar_brazos){
			giro_brazos-=1;
			if(giro_brazos < giro_brazo_min){
				animar_brazos = true;
				giro_brazos = giro_brazo_min;
			}
		}

		glutPostRedisplay();
	}
}


/*********************************************
 * Clase pierna
 * *******************************************/

_pierna::_pierna(){
	vector<_vertex3f> perfilPierna, perfilPie;
	_vertex3f vertice;

	// Pierna derecha

	vertice.x=1.0; vertice.y=-1.0; vertice.z=0.0;
	perfilPierna.push_back(vertice);
	vertice.x=1.0; vertice.y=1.0; vertice.z=0.0;
	perfilPierna.push_back(vertice);

	pierna.parametros(perfilPierna, 20, 1);
	pie.parametros(perfilPierna, 20, 1);
}

void _pierna::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, int orientacion){
	glPushMatrix();
	glScalef(0.27,1.0,0.27);
	pierna.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.08,1.0,0.08);
	if(orientacion == 0){
		glTranslatef(0.0,-1.0,0.0);
	}
	if (orientacion == 1) {
		glTranslatef(0.0,-1.0,0.0);
	}
	pie.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

}

/*********************************************
 * Clase cabeza
 * *******************************************/

_cabeza::_cabeza(){
	// Creamos el perfil de los objetos de la cabeza

	vector<_vertex3f> perfilCabeza, perfilSombrero;
	_vertex3f vertice;

	// Creación del perfil de la esfera 

	for(float i = 0.0; i < 1; i+=0.01){
		vertice.x = i;
		vertice.y = (-1)*sqrt(1-i*i);
		vertice.z = 0.0;
		perfilCabeza.push_back(vertice);
	}

	for(float i = 1; i >= 0; i-=0.01){
		vertice.x = i;
		vertice.y = sqrt(1-i*i);
		vertice.z = 0.0;
		perfilCabeza.push_back(vertice);
	}

	cabeza.parametros(perfilCabeza, 20);
	ojo_derecho.parametros(perfilCabeza, 20);
	ojo_izquierdo.parametros(perfilCabeza, 20);

	// Creación del perfil cono

	vertice.x=1.0;vertice.y=-1.0;vertice.z=0.0;
	perfilSombrero.push_back(vertice);
	vertice.x=0.0;vertice.y=1.0;vertice.z=0.0;
	perfilSombrero.push_back(vertice);

	sombrero.parametros(perfilSombrero, 20);
	nariz.parametros(perfilSombrero,20);
}

void _cabeza::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor){
	//Dibujar cabeza
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(0,8.0,0);
	cabeza.draw(modo, r1, g1, b1, r2, g2, b2, grosor);

	//Dibujar sombrero
	glScalef(0.8,0.8,0.8);
	glTranslatef(0,1.5,0);
	sombrero.draw(modo, 1.0, 0.0, 0.0, 0.1, 0.0, 0.0, grosor);

	//Dibujar nariz
	glPushMatrix();
	glScalef(0.3,0.3,0.3);
	glTranslatef(0.0,-4,4.7);
	glRotatef(90,1,0,0);
	nariz.draw(modo, 1.0, 0.0, 0.0, 0.1, 0.0, 0.0, grosor);
	glPopMatrix();

	//Dibujar ojos
	glPushMatrix();
	glScalef(0.2,0.2,0.2);
	glTranslatef(-2.0,-4,4.7);
	glRotatef(90,1,0,0);
	ojo_derecho.draw(modo, 1.0, 0.0, 0.0, 0.1, 0.0, 0.0, grosor);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2,0.2,0.2);
	glTranslatef(2.0,-4,4.7);
	glRotatef(90,1,0,0);
	ojo_izquierdo.draw(modo, 1.0, 0.0, 0.0, 0.1, 0.0, 0.0, grosor);
	glPopMatrix();


}

/*********************************************
 * Clase brazo
 * *******************************************/

_brazo::_brazo(){
	vector<_vertex3f> perfilBrazo;
	_vertex3f vertice;

	// Brazo

	vertice.x=1.0; vertice.y=-1.0; vertice.z=0.0;
	perfilBrazo.push_back(vertice);
	vertice.x=1.0; vertice.y=1.0; vertice.z=0.0;
	perfilBrazo.push_back(vertice);

	brazo.parametros(perfilBrazo, 20, 1);
	mano.parametros(perfilBrazo, 20, 1);
}


void _brazo::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, float grosor, int orientacion){
	
	// Brazo

	glPushMatrix();
	glScalef(0.2,0.5,0.2);
	brazo.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();

	// Mano

	glPushMatrix();
	glScalef(0.08,0.5,0.08);
	if(orientacion == 0){ //Mano derecha
		glTranslatef(0,1,0);
	}
	if(orientacion == 1){
		glTranslatef(0,-1,0); //Mano izquierda
	}
	mano.draw(modo, r1, g1, b1, r2, g2, b2, grosor);
	glPopMatrix();
}

/********************************************************************
 * Implementación de funciones de la práctica 4
 *******************************************************************/

void _triangulos3D::draw_iluminacion_plana() {

}

void _triangulos3D::draw_iluminacion_suave() {

}

void _triangulos3D::calcular_normales_vertices() {

	if(normales_caras.empty())
		calcular_normales_caras();

	normales_caras.resize(vertices.size());

	for(unsigned int i = 0; i < caras.size(); i++){
		int a = caras[i]._0;
		int b = caras[i]._1;
		int c = caras[i]._2;

		normales_vertices[a] += normales_caras[i];
		normales_vertices[b] += normales_caras[i];
		normales_vertices[c] += normales_caras[i];
	}
}

void _triangulos3D::calcular_normales_caras() {

	for(int i=0; i < caras.size(); i++){
		_vertex3f p = vertices[caras[i]._0];
		_vertex3f q = vertices[caras[i]._1];
		_vertex3f r = vertices[caras[i]._2];

		_vertex3f a = q - p;
		_vertex3f b = r - p;

		normales_caras.push_back(a.cross_product(b).normalize());
	}
}
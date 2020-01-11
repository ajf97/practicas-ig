//**************************************************************************
// Práctica 1
//
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "user_code.h"
#include "file_ply_stl.hpp"

// tamaño de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=450,UI_window_height=450;

int estadoRaton[3], xc, yc, modo[15], cambio=0;

solido *cabeza, *sombrero, *nariz, *ojo_derecho, *ojo_izquierdo;
solido *tronco, *pierna_derecha, *pierna_izquierda, *pie_izquierdo, *pie_derecho;
solido *brazo_derecho, *brazo_izquierdo, *mano_derecha, *mano_izquierda;

bool planta = false;
int Ancho=450, Alto=450;
float factor=1.0;

void pick_color(int x, int y);

//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
//change_projection();
glViewport(0,0,Ancho,Alto);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glLineWidth(1);
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

void draw_objects()
{
   // Cabeza
	glPushMatrix();
	glRotatef(0.0, 0, 1, 0);
	//Dibujar cabeza
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(0, 8.0, 0);
     draw_solido(cabeza,0.9,0.6,0.2,1);
     draw_solido(cabeza,cabeza->r,cabeza->g,cabeza->b,2);

	//Dibujar sombrero
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(0, 1.5, 0);
     draw_solido(sombrero,0.1,0.1,0.1,1);
     draw_solido(sombrero,sombrero->r,sombrero->g,sombrero->b,2);

	//Dibujar nariz
	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(0.0, -4, 4.7);
	glRotatef(90, 1, 0, 0);
     draw_solido(nariz,0.1,0.1,0.1,1);
     draw_solido(nariz,nariz->r,nariz->g,nariz->b,2);
	glPopMatrix();

	//Dibujar ojos
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-2.0, -4, 4.7);
	glRotatef(90, 1, 0, 0);
     draw_solido(ojo_derecho,0.1,0.1,0.1,1);
     draw_solido(ojo_derecho,ojo_derecho->r,ojo_derecho->g,ojo_derecho->b,2);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(2.0, -4, 4.7);
	glRotatef(90, 1, 0, 0);
     draw_solido(ojo_izquierdo,0.1,0.1,0.1,1);
     draw_solido(ojo_izquierdo,ojo_izquierdo->r,ojo_izquierdo->g,ojo_izquierdo->b,2);
	glPopMatrix();
	glPopMatrix();

	// // Tronco
	glPushMatrix();
	glScalef(0.27, 1.25, 0.27);
	glTranslatef(0.0, 1.0, 0.0);
	draw_solido(tronco,0.1,0.1,0.1,1);
     draw_solido(tronco,tronco->r,tronco->g,tronco->b,2);
	glPopMatrix();

	// // Pierna derecha
	glPushMatrix();
	glRotatef(0.0, 0, 1, 0);
	glTranslatef(-0.65, -0.2, 0.0);
	glRotatef(-45.0, 0, 0, 1);
	glPushMatrix();
	glScalef(0.27, 1.0, 0.27);
	draw_solido(pierna_derecha,0.1,0.1,0.1,1);
     draw_solido(pierna_derecha,pierna_derecha->r,pierna_derecha->g,pierna_derecha->b,2);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.08, 1.0, 0.08);
     glTranslatef(0.0, -1.0, 0.0);
	draw_solido(pie_derecho,0.1,0.1,0.1,1);
     draw_solido(pie_derecho,pie_derecho->r,pie_derecho->g,pie_derecho->b,2);
	glPopMatrix();
	glPopMatrix();

	// // Pierna izquierda
	glPushMatrix();
	glRotatef(0.0, 0, 1, 0);
	glTranslatef(0.65, -0.2, 0.0);
	glRotatef(45.0, 0, 0, 1);
	glPushMatrix();
	glScalef(0.27, 1.0, 0.27);
	draw_solido(pierna_izquierda,0.1,0.1,0.1,1);
     draw_solido(pierna_izquierda,pierna_izquierda->r,pierna_izquierda->g,pierna_izquierda->b,2);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.08, 1.0, 0.08);
     glTranslatef(0.0, -1.0, 0.0);
	draw_solido(pie_izquierdo,0.1,0.1,0.1,1);
     draw_solido(pie_izquierdo,pie_izquierdo->r,pie_izquierdo->g,pie_izquierdo->b,2);
	glPopMatrix();
	glPopMatrix();

	// // Brazo derecho
	glPushMatrix();
	glRotatef(0.0, 0, 0, 1);
	glTranslatef(-0.5, 1.5, 0.0);
	glRotatef(90.0, 0, 0, 1);
	// Brazo
	glPushMatrix();
	glScalef(0.2, 0.5, 0.2);
	draw_solido(brazo_derecho,0.1,0.1,0.1,1);
     draw_solido(brazo_derecho,brazo_derecho->r,brazo_derecho->g,brazo_derecho->b,2);
	glPopMatrix();
	// Mano
	glPushMatrix();
	glScalef(0.08, 0.5, 0.08);
     glTranslatef(0, 1, 0);
	draw_solido(mano_derecha,0.1,0.1,0.1,1);
     draw_solido(mano_derecha,mano_derecha->r,mano_derecha->g,mano_derecha->b,2);
	glPopMatrix();
	glPopMatrix();

	// // Brazo izquierdo
	glPushMatrix();
	glRotatef(0.0, 0, 0, 1);
	glTranslatef(0.5, 1.5, 0.0);
	glRotatef(90.0, 0, 0, 1);
	// Brazo
	glPushMatrix();
	glScalef(0.2, 0.5, 0.2);
	draw_solido(brazo_izquierdo,0.1,0.1,0.1,1);
     draw_solido(brazo_izquierdo,brazo_izquierdo->r,brazo_izquierdo->g,brazo_izquierdo->b,2);
	glPopMatrix();
	// Mano
	glPushMatrix();
	glScalef(0.08, 0.5, 0.08);
     glTranslatef(0, -1, 0); //Mano izquierda
	draw_solido(mano_izquierda,0.1,0.1,0.1,1);
     draw_solido(mano_izquierda,mano_izquierda->r,mano_izquierda->g,mano_izquierda->b,2);
	glPopMatrix();
	glPopMatrix(); 
}

//**************************************************************************
// Funcion que dibuja los objetos en el buffer trasero
//***************************************************************************


void draw_objects_seleccion()
{
int inc=0;
     
     glPushMatrix();
	glRotatef(0.0, 0, 1, 0);
	//Dibujar cabeza
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(0, 8.0, 0);
     draw_seleccion_color(cabeza,100,100,100);
     inc+=10;

     //Dibujar sombrero
   
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(0, 1.5, 0);
     draw_seleccion_color(sombrero,100+inc,100+inc,100+inc);
     inc+=10;

     //Dibujar nariz
	glPushMatrix();
	glScalef(0.3, 0.3, 0.3);
	glTranslatef(0.0, -4, 4.7);
	glRotatef(90, 1, 0, 0);
     draw_seleccion_color(nariz,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;

     //Dibujar ojos
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-2.0, -4, 4.7);
	glRotatef(90, 1, 0, 0);
     draw_seleccion_color(ojo_derecho,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;

	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(2.0, -4, 4.7);
	glRotatef(90, 1, 0, 0);
     draw_seleccion_color(ojo_izquierdo,100+inc,100+inc,100+inc);
	glPopMatrix();
	glPopMatrix();
     inc+=10;

     // // Tronco
	glPushMatrix();
	glScalef(0.27, 1.25, 0.27);
	glTranslatef(0.0, 1.0, 0.0);
	draw_seleccion_color(tronco,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;

     // // Pierna derecha
	glPushMatrix();
	glRotatef(0.0, 0, 1, 0);
	glTranslatef(-0.65, -0.2, 0.0);
	glRotatef(-45.0, 0, 0, 1);
	glPushMatrix();
	glScalef(0.27, 1.0, 0.27);
	draw_seleccion_color(pierna_derecha,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;

     glPushMatrix();
	glScalef(0.08, 1.0, 0.08);
     glTranslatef(0.0, -1.0, 0.0);
	draw_seleccion_color(pie_derecho,100+inc,100+inc,100+inc);
	glPopMatrix();
	glPopMatrix();
     inc+=10;

     // // Pierna izquierda
	glPushMatrix();
	glRotatef(0.0, 0, 1, 0);
	glTranslatef(0.65, -0.2, 0.0);
	glRotatef(45.0, 0, 0, 1);
	glPushMatrix();
	glScalef(0.27, 1.0, 0.27);
	draw_seleccion_color(pierna_izquierda,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;

	glPushMatrix();
	glScalef(0.08, 1.0, 0.08);
     glTranslatef(0.0, -1.0, 0.0);
	draw_seleccion_color(pie_izquierdo,100+inc,100+inc,100+inc);
	glPopMatrix();
	glPopMatrix();
     inc+=10;

     // // Brazo derecho
	glPushMatrix();
	glRotatef(0.0, 0, 0, 1);
	glTranslatef(-0.5, 1.5, 0.0);
	glRotatef(90.0, 0, 0, 1);
	// Brazo
	glPushMatrix();
	glScalef(0.2, 0.5, 0.2);
	draw_seleccion_color(brazo_derecho,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;
	// Mano
	glPushMatrix();
	glScalef(0.08, 0.5, 0.08);
     glTranslatef(0, 1, 0);
	draw_seleccion_color(mano_derecha,100+inc,100+inc,100+inc);
	glPopMatrix();
	glPopMatrix();
     inc+=10;

     // // Brazo izquierdo
	glPushMatrix();
	glRotatef(0.0, 0, 0, 1);
	glTranslatef(0.5, 1.5, 0.0);
	glRotatef(90.0, 0, 0, 1);
	// Brazo
	glPushMatrix();
	glScalef(0.2, 0.5, 0.2);
	draw_seleccion_color(brazo_izquierdo,100+inc,100+inc,100+inc);
	glPopMatrix();
     inc+=10;
	// Mano
	glPushMatrix();
	glScalef(0.08, 0.5, 0.08);
     glTranslatef(0, -1, 0); //Mano izquierda
	draw_seleccion_color(mano_izquierda,100+inc,100+inc,100+inc);
	glPopMatrix();
	glPopMatrix(); 


     glPopMatrix();
}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

if(planta==true ){
     clear_window();
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(Observer_distance*-1.0, Observer_distance*1.0, Observer_distance*-1.0, Observer_distance*1.0,-100.0,100.0);
     glViewport(0,0,Ancho,Alto);
     glRotatef(90,1,0,0);
     glScalef(factor,factor,1.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     draw_axis();
     draw_objects();

     glFlush();
     
}
else {
     
     clear_window();
     clear_window();
     clear_window();
     change_observer();
     draw_axis();
     draw_objects();


     glDrawBuffer(GL_BACK);
     clear_window();
     change_observer();
     draw_objects_seleccion();
     glDrawBuffer(GL_FRONT);

     glFlush();

     
}

}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
Ancho=Ancho1;
Alto=Alto1;
draw_scene();
}  


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

if (toupper(Tecla1)=='Q') exit(0);
if (Tecla1=='+') 
   {factor*=0.9;
    glutPostRedisplay();}
if (Tecla1=='-') 
   {factor*=1.1;
    glutPostRedisplay();}
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
     case GLUT_KEY_F1:planta=true;break;
     case GLUT_KEY_F2:planta=false;break;
	}
glutPostRedisplay();
}


//***************************************************************************
// Funciones para manejo de eventos del ratón
//***************************************************************************

void clickRaton( int boton, int estado, int x, int y )
{
if(boton== GLUT_RIGHT_BUTTON) {
   if( estado == GLUT_DOWN) {
      estadoRaton[2] = 1;
      xc=x;
      yc=y;
     } 
   else estadoRaton[2] = 1;
   }
if(boton== GLUT_LEFT_BUTTON) {
  if( estado == GLUT_DOWN) {
      estadoRaton[2] = 2;
      xc=x;
      yc=y;
      pick_color(xc, yc);
    } 
  }

 // Hacer zoom con la rueda del ratón
 if(!planta){
  if(boton == 3 || boton == 4){
    if(estado == GLUT_DOWN){
      if(boton == 3)
        Observer_distance-=0.5;

      if(boton == 4)
        Observer_distance+=0.5;

      glutPostRedisplay();
    }
  }
 }
}

/*************************************************************************/

void getCamara (GLfloat *x, GLfloat *y)
{
*x=Observer_angle_x;
*y=Observer_angle_y;
}

/*************************************************************************/

void setCamara (GLfloat x, GLfloat y)
{
Observer_angle_x=x;
Observer_angle_y=y;
}



/*************************************************************************/

void RatonMovido( int x, int y )
{
float x0, y0, xn, yn; 
if(estadoRaton[2]==1) 
    {getCamara(&x0,&y0);
     yn=y0+(y-yc);
     xn=x0-(x-xc);
     setCamara(xn,yn);
     xc=x;
     yc=y;
     glutPostRedisplay();
    }
}


//***************************************************************************
// Funciones para la seleccion
//************************************************************************


void procesar_color(unsigned char color[3])
{
 int i;
 solido *obj;

 obj=(solido *)malloc(sizeof(solido));
 
 switch (color[0])
      {case 100: obj=cabeza;
                 if (modo[0]==0) 
                      {modo[0]=1;
                       cambio=1;
                      }
                  else 
                      {modo[0]=0;
                       cambio=0;
                      }
                  break; 
        case 110: obj=sombrero;
                  if (modo[1]==0) 
                       {modo[1]=1;
                        cambio=1;
                       }
                  else 
                       {modo[1]=0;
                        cambio=0;
                       } 
                  break;
        case 120: obj=nariz;
                  if (modo[2]==0) 
                       {modo[2]=1;
                        cambio=1;
                       }
                  else 
                       {modo[2]=0;
                        cambio=0;
                       }
                  break; 
        case 130: obj=ojo_derecho;
                  if (modo[3]==0) 
                       {modo[3]=1;
                        cambio=1;
                       }
                  else 
                       {modo[3]=0;
                        cambio=0;
                       }
                  break;
        case 140: obj=ojo_izquierdo;
                  if (modo[4]==0) 
                       {modo[4]=1;
                        cambio=1;
                       }
                  else 
                       {modo[4]=0;
                        cambio=0;
                       }
                  break;
          case 150: obj=tronco;
                  if (modo[5]==0) 
                       {modo[5]=1;
                        cambio=1;
                       }
                  else 
                       {modo[5]=0;
                        cambio=0;
                       }
                  break;
          case 160: obj=pierna_derecha;
                  if (modo[6]==0) 
                       {modo[6]=1;
                        cambio=1;
                       }
                  else 
                       {modo[6]=0;
                        cambio=0;
                       }
                  break;
          case 170: obj=pie_derecho;
                  if (modo[7]==0) 
                       {modo[7]=1;
                        cambio=1;
                       }
                  else 
                       {modo[7]=0;
                        cambio=0;
                       }
                  break;
          case 180: obj=pierna_izquierda;
                  if (modo[8]==0) 
                       {modo[8]=1;
                        cambio=1;
                       }
                  else 
                       {modo[8]=0;
                        cambio=0;
                       }
                  break;
          case 190: obj=pie_izquierdo;
                  if (modo[9]==0) 
                       {modo[9]=1;
                        cambio=1;
                       }
                  else 
                       {modo[9]=0;
                        cambio=0;
                       }
                  break;
          case 200: obj=brazo_derecho;
                  if (modo[10]==0) 
                       {modo[10]=1;
                        cambio=1;
                       }
                  else 
                       {modo[10]=0;
                        cambio=0;
                       }
                  break;
          case 210: obj=mano_derecha;
                  if (modo[11]==0) 
                       {modo[11]=1;
                        cambio=1;
                       }
                  else 
                       {modo[11]=0;
                        cambio=0;
                       }
                  break;
          case 220: obj=brazo_izquierdo;
                  if (modo[12]==0) 
                       {modo[12]=1;
                        cambio=1;
                       }
                  else 
                       {modo[12]=0;
                        cambio=0;
                       }
                  break;
          case 230: obj=mano_izquierda;
                  if (modo[13]==0) 
                       {modo[13]=1;
                        cambio=1;
                       }
                  else 
                       {modo[13]=0;
                        cambio=0;
                       }
                  break;
     }         
               
        if (cambio==1) 
                  {obj->r=0.3;
                   obj->g=0.9;
                   obj->b=0.3;
                  }
        if (cambio==0)
                  {obj->r=0.9;
                   obj->g=0.6;
                   obj->b=0.2;
                  }
                 
 }



void pick_color(int x, int y)
{
GLint viewport[4];
unsigned char pixel[3];

glGetIntegerv(GL_VIEWPORT, viewport);
glReadBuffer(GL_BACK);
glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_UNSIGNED_BYTE,(GLubyte *) &pixel[0]);
printf(" valor x %d, valor y %d, color %d, %d, %d \n",x,y,pixel[0],pixel[1],pixel[2]);

procesar_color(pixel);
glutPostRedisplay();
}


//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=.5;
Window_height=.5;
Front_plane=1;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=3*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
change_projection();
glViewport(0,0,UI_window_width,UI_window_height);

for (int i=0;i<15;i++) modo[i]=0;
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{
    // se llama a la inicialización de glut
    cabeza=new solido[sizeof(solido)];
    construir_esfera(20, cabeza);

    sombrero=new solido[sizeof(solido)];
    construir_cono(1.0,1.0,8,1,sombrero);

    nariz=new solido[sizeof(solido)];
    construir_cono(1.0,1.0,20,1,nariz);

    ojo_derecho=new solido[sizeof(solido)];
    construir_esfera(20, ojo_derecho);

    ojo_izquierdo=new solido[sizeof(solido)];
    construir_esfera(20, ojo_izquierdo);

    tronco=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,tronco);

    pierna_derecha=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,pierna_derecha);

    pierna_izquierda=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,pierna_izquierda);

    pie_izquierdo=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,pie_izquierdo);

    pie_derecho=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,pie_derecho);

    brazo_derecho=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,brazo_derecho);

    brazo_izquierdo=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,brazo_izquierdo);

    mano_derecha=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,mano_derecha);

    mano_izquierda=new solido[sizeof(solido)];
    construir_cilindro(1.0,1.0,20,3,mano_izquierda);

    glutInit(&argc, argv);

    // se indica las caracteristicas que se desean para la visualización con OpenGL
    // Las posibilidades son:
    // GLUT_SIMPLE -> memoria de imagen simple
    // GLUT_DOUBLE -> memoria de imagen doble
    // GLUT_INDEX -> memoria de imagen con color indizado
    // GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
    // GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
    // GLUT_DEPTH -> memoria de profundidad o z-bufer
    // GLUT_STENCIL -> memoria de estarcido
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    // posicion de la esquina inferior izquierdad de la ventana
    glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

    // tamaño de la ventana (ancho y alto)
    glutInitWindowSize(UI_window_width,UI_window_height);

    // llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
    // al bucle de eventos)
    glutCreateWindow("Ejemplo");

    // asignación de la funcion llamada "dibujar" al evento de dibujo
    glutDisplayFunc(draw_scene);
    // asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
    glutReshapeFunc(change_window_size);
    // asignación de la funcion llamada "tecla_normal" al evento correspondiente
    glutKeyboardFunc(normal_keys);
    // asignación de la funcion llamada "tecla_Especial" al evento correspondiente
    glutSpecialFunc(special_keys);

    // eventos ratón
    glutMouseFunc( clickRaton );
    glutMotionFunc( RatonMovido );


    // funcion de inicialización
    initialize();

    // inicio del bucle de eventos
    glutMainLoop();
    return 0;
}

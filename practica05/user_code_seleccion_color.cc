//**************************************************************************
// Codigo del usuario
//
//
//
// GPL
//**************************************************************************

#include "user_code.h"
#include "file_ply_stl.hpp"


//**************************************************************************
// Funcciones para construir modelos sólidos poligonales
//**************************************************************************

void construir_cubo(float tam, solido *cubo)
{

cubo->n_v=8;
cubo->n_c=12;
cubo->ver=(vertices *)malloc(8*sizeof(vertices));
cubo->car=(caras *)malloc(12*sizeof(caras));

cubo->ver[0].coord[0]=-tam;cubo->ver[0].coord[1]=-tam;cubo->ver[0].coord[2]=tam;
cubo->ver[1].coord[0]=tam;cubo->ver[1].coord[1]=-tam;cubo->ver[1].coord[2]=tam;
cubo->ver[2].coord[0]=tam;cubo->ver[2].coord[1]=tam;cubo->ver[2].coord[2]=tam;
cubo->ver[3].coord[0]=-tam;cubo->ver[3].coord[1]=tam;cubo->ver[3].coord[2]=tam;
cubo->ver[4].coord[0]=-tam;cubo->ver[4].coord[1]=-tam;cubo->ver[4].coord[2]=-tam;
cubo->ver[5].coord[0]=tam;cubo->ver[5].coord[1]=-tam;cubo->ver[5].coord[2]=-tam;
cubo->ver[6].coord[0]=tam;cubo->ver[6].coord[1]=tam;cubo->ver[6].coord[2]=-tam;
cubo->ver[7].coord[0]=-tam;cubo->ver[7].coord[1]=tam;cubo->ver[7].coord[2]=-tam;

cubo->car[0].ind_c[0]=0;cubo->car[0].ind_c[1]=1;cubo->car[0].ind_c[2]=3;
cubo->car[1].ind_c[0]=3;cubo->car[1].ind_c[1]=1;cubo->car[1].ind_c[2]=2;
cubo->car[2].ind_c[0]=1;cubo->car[2].ind_c[1]=5;cubo->car[2].ind_c[2]=2;
cubo->car[3].ind_c[0]=5;cubo->car[3].ind_c[1]=6;cubo->car[3].ind_c[2]=2;
cubo->car[4].ind_c[0]=5;cubo->car[4].ind_c[1]=4;cubo->car[4].ind_c[2]=6;
cubo->car[5].ind_c[0]=4;cubo->car[5].ind_c[1]=7;cubo->car[5].ind_c[2]=6;
cubo->car[6].ind_c[0]=0;cubo->car[6].ind_c[1]=7;cubo->car[6].ind_c[2]=4;
cubo->car[7].ind_c[0]=0;cubo->car[7].ind_c[1]=3;cubo->car[7].ind_c[2]=7;
cubo->car[8].ind_c[0]=3;cubo->car[8].ind_c[1]=2;cubo->car[8].ind_c[2]=7;
cubo->car[9].ind_c[0]=2;cubo->car[9].ind_c[1]=6;cubo->car[9].ind_c[2]=7;
cubo->car[10].ind_c[0]=0;cubo->car[10].ind_c[1]=1;cubo->car[10].ind_c[2]=4;
cubo->car[11].ind_c[0]=1;cubo->car[11].ind_c[1]=5;cubo->car[11].ind_c[2]=4;  

}


void construir_piramide(float tam, float al, solido *piramide)
{
piramide->n_v=5;
piramide->n_c=6;
piramide->ver=(vertices *)malloc(5*sizeof(vertices));
piramide->car=(caras *)malloc(6*sizeof(caras));

piramide->r=0.9;piramide->g=0.6;piramide->b=0.2;

// asignar puntos y caras  
piramide->ver[0].coord[0]=-tam;piramide->ver[0].coord[1]=0;piramide->ver[0].coord[2]=tam;
piramide->ver[1].coord[0]=tam;piramide->ver[1].coord[1]=0;piramide->ver[1].coord[2]=tam;
piramide->ver[2].coord[0]=tam;piramide->ver[2].coord[1]=0;piramide->ver[2].coord[2]=-tam;
piramide->ver[3].coord[0]=-tam;piramide->ver[3].coord[1]=0;piramide->ver[3].coord[2]=-tam;
piramide->ver[4].coord[0]=0;piramide->ver[4].coord[1]=al;piramide->ver[4].coord[2]=0;

piramide->car[0].ind_c[0]=0;piramide->car[0].ind_c[1]=1;piramide->car[0].ind_c[2]=4;
piramide->car[1].ind_c[0]=1;piramide->car[1].ind_c[1]=2;piramide->car[1].ind_c[2]=4;
piramide->car[2].ind_c[0]=2;piramide->car[2].ind_c[1]=3;piramide->car[2].ind_c[2]=4;
piramide->car[3].ind_c[0]=3;piramide->car[3].ind_c[1]=0;piramide->car[3].ind_c[2]=4;
piramide->car[4].ind_c[0]=3;piramide->car[4].ind_c[1]=1;piramide->car[4].ind_c[2]=0;
piramide->car[5].ind_c[0]=3;piramide->car[5].ind_c[1]=2;piramide->car[5].ind_c[2]=1;
  
}


void construir_cono(float r, float h, int n, int tapas, solido *cono) {

	int num = n;
	_vertex3f aux;
	vector<_vertex3f> perfil;

	aux.x=r; aux.y=-h; aux.z=0.0;
	perfil.push_back(aux);
	aux.x=0.0; aux.y=h; aux.z=0.0;
	perfil.push_back(aux);

	// rotación
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

	// tratamiento de los vértice

	num_aux=perfil.size();	// número de vértices que tenemos en el perfil inicial
	cono->n_v=num_aux*num+2;
	cono->n_c=n*2;
	cono->ver=new vertices[cono->n_v*sizeof(vertices)];
	cono->car=new caras[cono->n_c*sizeof(caras)];
	cono->r=0.9;cono->g=0.6;cono->b=0.2;

	for (j=0;j<num;j++)
	  {for (i=0;i<num_aux;i++)	
	     {
	      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
	                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
	      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
	                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
	      vertice_aux.y=perfil[i].y;

	      cono->ver[i+j*num_aux].coord[0]=vertice_aux.x;
	      cono->ver[i+j*num_aux].coord[1]=vertice_aux.y;
	      cono->ver[i+j*num_aux].coord[2]=vertice_aux.z;
	     }
	  }

	// tratamiento de las caras 

	int numero_cara = 0;

	for (j=0;j<num;j++)
	  {for (i=0;i<num_aux-1;i++)
	     {cara_aux._0=i+((j+1)%num)*num_aux;
	      cara_aux._1=i+1+((j+1)%num)*num_aux;
	      cara_aux._2=i+1+j*num_aux;
	      cono->car[numero_cara].ind_c[0]=cara_aux._0;
	      cono->car[numero_cara].ind_c[1]=cara_aux._1;
	      cono->car[numero_cara].ind_c[2]=cara_aux._2;
	      numero_cara++;
	      
	      cara_aux._0=i+1+j*num_aux;
	      cara_aux._1=i+j*num_aux;
	      cara_aux._2=i+((j+1)%num)*num_aux;
	      cono->car[numero_cara].ind_c[0]=cara_aux._0;
	      cono->car[numero_cara].ind_c[1]=cara_aux._1;
	      cono->car[numero_cara].ind_c[2]=cara_aux._2;
	      numero_cara++;
	      
	     }
	  }

	
	// tapa inferior
	if (fabs(perfil[0].x)>0.0 && tapas ==1)
	{
		vertice_aux.x=0;
		vertice_aux.y=perfil[0].y;
		vertice_aux.z=0;
		cono->ver[cono->n_v-2].coord[0]=vertice_aux.x;
	    cono->ver[cono->n_v-2].coord[1]=vertice_aux.y;
	    cono->ver[cono->n_v-2].coord[2]=vertice_aux.z;

		for(i=0; i<num_aux*num; i+=2){
			cara_aux._0=cono->n_v-2;
			cara_aux._1=i;
			cara_aux._2=(i+2)%(cono->n_v-2);
			cono->car[numero_cara].ind_c[0]=cara_aux._0;
	      	cono->car[numero_cara].ind_c[1]=cara_aux._1;
	      	cono->car[numero_cara].ind_c[2]=cara_aux._2;
	      	numero_cara++;
		}
	}
 
}


void construir_cilindro(float r, float h, int n, int tapas, solido *cilindro) {

	int num = n;		// numero de caras		
	_vertex3f aux;
	vector<_vertex3f> perfil;

	aux.x=r; aux.y=h; aux.z=0.0;
	perfil.push_back(aux);
	aux.x=r; aux.y=-h; aux.z=0.0;
	perfil.push_back(aux);

	// rotación
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

	// tratamiento de los vértice

	num_aux=perfil.size();	// número de vértices que tenemos en el perfil inicial
	cilindro->n_v=num_aux*num+2;
	cilindro->n_c=n*4;
	cilindro->ver=new vertices[cilindro->n_v*sizeof(vertices)];
	cilindro->car=new caras[cilindro->n_c*sizeof(caras)];
	cilindro->r=0.9;cilindro->g=0.6;cilindro->b=0.2;

	for (j=0;j<num;j++)
	  {for (i=0;i<num_aux;i++)	
	     {
	      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
	                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
	      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
	                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
	      vertice_aux.y=perfil[i].y;

	      cilindro->ver[i+j*num_aux].coord[0]=vertice_aux.x;
	      cilindro->ver[i+j*num_aux].coord[1]=vertice_aux.y;
	      cilindro->ver[i+j*num_aux].coord[2]=vertice_aux.z;
	     }
	  }

	// tratamiento de las caras 

	int numero_cara = 0;

	for (j=0;j<num;j++)
	  {for (i=0;i<num_aux-1;i++)
	     {cara_aux._0=i+((j+1)%num)*num_aux;
	      cara_aux._1=i+1+((j+1)%num)*num_aux;
	      cara_aux._2=i+1+j*num_aux;
	      cilindro->car[numero_cara].ind_c[0]=cara_aux._0;
	      cilindro->car[numero_cara].ind_c[1]=cara_aux._1;
	      cilindro->car[numero_cara].ind_c[2]=cara_aux._2;
	      numero_cara++;
	      
	      cara_aux._0=i+1+j*num_aux;
	      cara_aux._1=i+j*num_aux;
	      cara_aux._2=i+((j+1)%num)*num_aux;
	      cilindro->car[numero_cara].ind_c[0]=cara_aux._0;
	      cilindro->car[numero_cara].ind_c[1]=cara_aux._1;
	      cilindro->car[numero_cara].ind_c[2]=cara_aux._2;
	      numero_cara++;
	      
	     }
	  }
     

 // tapa inferior
	if (fabs(perfil[0].x)>0.0 && (tapas == 1 || tapas == 3))
	{
		vertice_aux.x=0;
		vertice_aux.y=perfil[0].y;
		vertice_aux.z=0;
		cilindro->ver[cilindro->n_v-2].coord[0]=vertice_aux.x;
	    cilindro->ver[cilindro->n_v-2].coord[1]=vertice_aux.y;
	    cilindro->ver[cilindro->n_v-2].coord[2]=vertice_aux.z;

		for(i=0; i<num_aux*num; i+=2){
			cara_aux._0=cilindro->n_v-2;
			cara_aux._1=i;
			cara_aux._2=(i+2)%(cilindro->n_v-2);
			cilindro->car[numero_cara].ind_c[0]=cara_aux._0;
	      	cilindro->car[numero_cara].ind_c[1]=cara_aux._1;
	      	cilindro->car[numero_cara].ind_c[2]=cara_aux._2;
	      	numero_cara++;
		}
	}
 
 // tapa superior
	if (fabs(perfil[num_aux-1].x)>0.0 && (tapas == 2 || tapas == 3))
	{
		vertice_aux.x=0;
		vertice_aux.y=perfil[1].y;
		vertice_aux.z=0;
		cilindro->ver[cilindro->n_v-1].coord[0]=vertice_aux.x;
	    cilindro->ver[cilindro->n_v-1].coord[1]=vertice_aux.y;
	    cilindro->ver[cilindro->n_v-1].coord[2]=vertice_aux.z;


		for(i=1; i<num_aux*num; i+=2){
			cara_aux._0=cilindro->n_v-1;
			cara_aux._1=(i+2)%(cilindro->n_v-2);
			cara_aux._2=i;
			cilindro->car[numero_cara].ind_c[0]=cara_aux._0;
	      	cilindro->car[numero_cara].ind_c[1]=cara_aux._1;
	      	cilindro->car[numero_cara].ind_c[2]=cara_aux._2;
	      	numero_cara++;
		}
	}


}


void construir_esfera(int numero_rotaciones , solido *esfera) {

	_vertex3f aux;
	vector<_vertex3f> perfil;

	// Creación del perfil de la esfera

	for (float i = 0.0; i < 1; i += 0.01)
	{
		aux.x = i;
		aux.y = (-1) * sqrt(1 - i * i);
		aux.z = 0.0;
		perfil.push_back(aux);
	}

	for (float i = 1; i >= 0; i -= 0.01)
	{
		aux.x = i;
		aux.y = sqrt(1 - i * i);
		aux.z = 0.0;
		perfil.push_back(aux);
	}

	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

	// tratamiento de los vértice

	num_aux = perfil.size();
	esfera->n_v=num_aux * numero_rotaciones;
	esfera->n_c=numero_rotaciones*num_aux*2;
	esfera->ver=new vertices[esfera->n_v*sizeof(vertices)];
	esfera->car=new caras[esfera->n_c*sizeof(caras)];
	esfera->r=0.9;esfera->g=0.6;esfera->b=0.2;

	for (int j = 0; j < numero_rotaciones; j++)
	{
		for (int i = 0; i < num_aux; i++)
		{
			vertice_aux.x = perfil[i].x * cos(2.0 * M_PI * j / (1.0 * numero_rotaciones)) +
							perfil[i].z * sin(2.0 * M_PI * j / (1.0 * numero_rotaciones));
			vertice_aux.z = -perfil[i].x * sin(2.0 * M_PI * j / (1.0 * numero_rotaciones)) +
							perfil[i].z * cos(2.0 * M_PI * j / (1.0 * numero_rotaciones));
			vertice_aux.y = perfil[i].y;

			esfera->ver[i+j*num_aux].coord[0]=vertice_aux.x;
	      	esfera->ver[i+j*num_aux].coord[1]=vertice_aux.y;
	      	esfera->ver[i+j*num_aux].coord[2]=vertice_aux.z;
		}
	}

	int num_cara = 0;

	// tratamiento de las caras
	for (int i = 0; i < numero_rotaciones; i++)
	{
		for (int j = 0; j < num_aux - 1; j++)
		{
			cara_aux.x = j + ((i + 1) % numero_rotaciones) * num_aux;
			cara_aux.y = j + 1 + ((i + 1) % numero_rotaciones) * num_aux;
			cara_aux.z = j + 1 + i * num_aux;


			esfera->car[num_cara].ind_c[0]=cara_aux._0;
	      	esfera->car[num_cara].ind_c[1]=cara_aux._1;
	      	esfera->car[num_cara].ind_c[2]=cara_aux._2;
			num_cara++;

			cara_aux.x = j + 1 + i * num_aux;
			cara_aux.y = j + i * num_aux;
			cara_aux.z = j + ((i + 1) % numero_rotaciones) * num_aux;

			esfera->car[num_cara].ind_c[0]=cara_aux._0;
	      	esfera->car[num_cara].ind_c[1]=cara_aux._1;
	      	esfera->car[num_cara].ind_c[2]=cara_aux._2;
			num_cara++;
		}
	}

}



//**************************************************************************
// Funciones de visualización
//**************************************************************************


void draw_puntos(vertices *ver, int n_v)
{
   
    glColor3f(0,0,0);
    glPointSize(10);

    glBegin(GL_POINTS);
    for (unsigned i=0;i<n_v;i++){
        glVertex3f(ver[i].coord[0],ver[i].coord[1],ver[i].coord[2]);
        }
    glEnd();
}


void draw_solido(solido *malla, float r, float g, float b, int modo)
{
  
  int n_c,n_v,i;
  n_c=malla->n_c;
  if (modo==1) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(r,g,b);
  glLineWidth(3);
  glBegin(GL_TRIANGLES);
  for (i=0;i<n_c;i++)
      { n_v=malla->car[i].ind_c[0];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[i].ind_c[1];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[i].ind_c[2];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
    }
   glEnd();
  
}

void draw_solido_ajedrez(solido *malla, float r1, float g1, float b1, float r2, float g2, float b2)
{
  
  int n_c,n_v,i;
  n_c=malla->n_c;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glBegin(GL_TRIANGLES);
  for (i=0;i<n_c;i++)
      { if (i%2==0)  glColor3f(r1,g1,b1);
         else glColor3f(r2,g2,b2);  
	n_v=malla->car[i].ind_c[0];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[i].ind_c[1];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[i].ind_c[2];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
    }
   glEnd();
  
}


void draw_seleccion_color(solido *malla, int r, int g, int b)
{
  
  int n_c,n_v,i;
  n_c=malla->n_c;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3ub(r,g,b);
  glBegin(GL_TRIANGLES);
 
  for (i=0;i<n_c;i++)
      { n_v=malla->car[i].ind_c[0];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[i].ind_c[1];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[i].ind_c[2];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
    }
   glEnd();
}


void draw_cara(solido *malla, float r1, float g1, float b1, int numCara){

  int n_v;

  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glColor3f(r1,g1,b1);
  glBegin(GL_TRIANGLES);
	n_v=malla->car[numCara].ind_c[0];
	glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[numCara].ind_c[1];
	glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
	n_v=malla->car[numCara].ind_c[2];
	glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
  glEnd();

}

void  draw_seleccion_color_cara(solido *malla ,float r1, float g1, float b1, int numCara){
  
  int n_c,n_v;
  n_c=malla->n_c;
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

  for (int i=0;i<n_c;i++){
    glBegin(GL_TRIANGLES);
      glColor3ub(r1+numCara,g1,b1);
	  	n_v=malla->car[i].ind_c[0];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
		n_v=malla->car[i].ind_c[1];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
		n_v=malla->car[i].ind_c[2];
        glVertex3f(malla->ver[n_v].coord[0], malla->ver[n_v].coord[1], malla->ver[n_v].coord[2]);
      	numCara++;
    glEnd();
  }
}
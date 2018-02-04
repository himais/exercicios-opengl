#include <windows.h>
#include <stdio.h>
#include <GL\glut.h>

   float a = 50.0, b = 60.0;


void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glLoadIdentity (); 		// carrega a matriz de identidade
   gluPerspective(1.0, 1.0, 1.0, 1.0);
   glMatrixMode (GL_MODELVIEW);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glPushMatrix();
   glTranslatef (0.0, 0.0, -10.0);
   glRotatef (a, 0.0, 1.0, 0.0);
   glutWireSphere(2.0, 30, 16);   //raio, divisoes em torno e ao longo de z
   glPopMatrix();


   glPushMatrix();
   glTranslatef (3.0, 0.0, -10.0);
   glRotatef (b, 1.0, 1.0, 0.0);
//   glutWireSphere(2.0, 30, 16);   //raio, divisoes em torno e ao longo de z
   glutSolidCube(2.0); 			  //tamanho
//   glutWireCone(2, 5, 30, 16); 			  //raio, altura, divisoes
//   glutWireTorus(1, 2, 20, 20); 			  //raio, altura, divisoes
   glPopMatrix();



   glFlush ();
}

void reshape (int w, int h)
{
   glLoadIdentity (); 		// carrega a matriz de identidade
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode (GL_MODELVIEW);
}



int main()
{
//   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Objetos 3D");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
}

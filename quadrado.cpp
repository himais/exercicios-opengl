#include <windows.h>
#include <stdio.h>
#include <GL\glut.h>

float moveY = 0;
float moveX = 0;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();                   
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);
     glTranslatef(moveX, moveY, 0.0f);

     glBegin(GL_QUADS);
               glVertex2i(100,150);
               glVertex2i(100,100);
               // Especifica que a cor corrente é azul
               glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(150,100);
               glVertex2i(150,150);               
     glEnd();
     glFlush();
}	


// Inicializa parâmetros de rendering
void Inicializa (void)
{   
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
                   // Evita a divisao por zero
                   if(h == 0) h = 1;
                           
                   // Especifica as dimensões da Viewport
                   glViewport(0, 0, w, h);

                   // Inicializa o sistema de coordenadas
                   glMatrixMode(GL_PROJECTION);
                   glLoadIdentity();

                   // Estabelece a janela de seleção (left, right, bottom, top)
                   if (w <= h) 
                           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
                   else 
                           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}
// Função callback chamada para gerenciar eventos do teclado   
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
		moveY += 5;
    if(key == GLUT_KEY_DOWN) 
		moveY -= 5;
    if(key == GLUT_KEY_LEFT)
		moveX -= 5;
    if(key == GLUT_KEY_RIGHT)
		moveX += 5;
	
    glutPostRedisplay();
}



// Programa Principal 
int main(int argc, char** argv)
{
     glutInit(&argc, argv);				// Inicia o modo gráfico de exibição
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(400,350);
     glutInitWindowPosition(10,10);
     glutCreateWindow("Quadrado");
     glutDisplayFunc(Desenha);
     glutSpecialFunc(TeclasEspeciais); 	// tratamento das teclas especiais
     glutReshapeFunc(AlteraTamanhoJanela);
     Inicializa();
     glutMainLoop();
}


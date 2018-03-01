#include <GL/glut.h>

#include <stdlib.h>



void init(void) 

{

   glClearColor (0.0, 0.0, 0.0, 0.0);

   glShadeModel (GL_FLAT);

}


float contadorx=0, contadory=0, escalax=1, escalay=1;

void hexagonofila() {
	hexagonofila();
	for (int contador = 0; contador<6; contador++) {
		glTranslatef(contadorx=contadorx+27.0,contadory,0.0);
		glScalef(escalax=escalax-0.01,escalay=escalay-0.01,0.0);
		hexagonofila();
		glLoadIdentity();
	}
}
void draw_triangle(void)

{

   glBegin (GL_LINE_LOOP);

   glVertex2f(0.0, 15.0);

   glVertex2f(15.0, -15.0);

   glVertex2f(-15.0, -15.0);

   glEnd();

}



void hexagono(){
	glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 1.0, 1.0);



   glLoadIdentity ();//CARGA LA MATRIZ DE IDENTIDAD

   glColor3f (0.0, 1.0, 0.0);

   draw_triangle ();



  /* glEnable (GL_LINE_STIPPLE);

   glLineStipple (1, 0x0001);

   glLoadIdentity ();

   glTranslatef (-20.0, 0.0, 0.0);

   draw_triangle ();



   glLineStipple (1, 0xF00F);

   glLoadIdentity ();

   glScalef (1.5, 0.5, 0.0);

   draw_triangle ();*/



   //glLineStipple (1, 0x8888);

   glLoadIdentity ();

   glTranslatef(-15.0,30.0,1.0);

   glRotatef (0, 0.0, 0.0, 1.0);

   draw_triangle ();

   

   glLoadIdentity ();

   glTranslatef(15.0,30.0,1.0);

   glRotatef (0, 0.0, 0.0, 1.0);

   draw_triangle ();

   

   glLoadIdentity ();

   glTranslatef(0.0,30.0,1.0);

   glRotatef (180, 0.0, 0.0, 1.0);

   draw_triangle ();

   

   glLoadIdentity ();

   glTranslatef(15.0,0.0,1.0);

   glRotatef (180, 0.0, 0.0, 1.0);

   draw_triangle ();

   

   glLoadIdentity ();

   glTranslatef(15.0,0.0,1.0);

   glRotatef (180, 0.0, 0.0, 1.0);

   draw_triangle ();

   

   glLoadIdentity ();

   glTranslatef(-15.0,0.0,1.0);

   glRotatef (180, 0.0, 0.0, 1.0);

   draw_triangle ();

   //glDisable (GL_LINE_STIPPLE);



   glFlush (); //HACE UN VOLCADO DE PANTALLA

}


void display(void)

{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.50, 0.70, 0.0);
	glLoadIdentity();
	hexagono();
	glLoadIdentity();
   
}


void reshape (int w, int h)

{

   glViewport (0, 0, (GLsizei) w, (GLsizei) h);//VENTANA DE RECORTE (O DE VISUALIZACIÓN)

   glMatrixMode (GL_PROJECTION);

   glLoadIdentity ();

   if (w <= h)

      glOrtho (-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w,

         50.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);

   else

      glOrtho (-50.0*(GLfloat)w/(GLfloat)h,

         50.0*(GLfloat)w/(GLfloat)h, -50.0, 50.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);

}



void keyboard(unsigned char key, int x, int y)

{

   switch (key) {

      case 27:

         exit(0);

         break;

   }

}



int main(int argc, char** argv)

{

   glutInit(&argc, argv);

   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1360, 700);
	glutInitWindowPosition(0, 60);

   glutCreateWindow (argv[0]);

   init ();

   glutDisplayFunc(display); 

   glutReshapeFunc(reshape); //HACE UN RE-DIBUJADO SOBRE EL DIBUJO ORIGINAL

   glutKeyboardFunc (keyboard);

   glutMainLoop();

   return 0;

}


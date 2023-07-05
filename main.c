#include "headers/includeHeaders.h"
#include "headers/constants.h"
#include "headers/stb_img.h"

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	//this gives the gradient background color
	glBegin(GL_QUADS);
	 glColor3ub(0,252,227);
	glVertex3f(-1.0,1.0,0.0);
	glVertex3f(-1.0,-1.0,0.0);
	 glColor3ub(37, 150, 190);
	glVertex3f(1.0,-1.0,0.0);
	glVertex3f(1.0,1.0,0.0);
	glEnd();
	
	
	glutSwapBuffers();

}
void pointer_init()
	{
	width=(int*)malloc(sizeof(int));
	*width=200;
        height=(int*)malloc(sizeof(int));
        *height=100;
        channels=(int*)malloc(sizeof(int));
        *channels=200;

}

void myInit()
{	
	GLuint texture2D;// variable created
	glGenTextures(1,&texture2D);//generates 1  texture id and place it to texture2D
	glBindTexture(GL_TEXTURE_2D,texture2D);//used to select the current texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//helps in scaling down and make smooth
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//helps to display scaled up images and make it smooth
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(-0.5, -0.5);
	glTexCoord2f(1, 0); glVertex2f(0.5, -0.5);
	glTexCoord2f(1, 1); glVertex2f(0.5, 0.5);
	glTexCoord2f(0, 1); glVertex2f(-0.5, 0.5);
	glEnd();

}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	pointer_init();
	unsigned char* image = stbi_load("icons/plane.bmp",width,height,channels,STBI_rgb);

	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(X_LENGTH,Y_LENGTH);
	glutCreateWindow("Flappy Cloud");
	glutDisplayFunc(display);

	glEnable(GL_TEXTURE_2D);

	glutMainLoop();
	
}

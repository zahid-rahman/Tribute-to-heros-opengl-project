#include <iostream>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>



void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float HumanAngle=0.0f;
float TankAngle=0.0f;
float airSpeed=0.0f;
float cloudAngle = 0.0f;
float humanArmMove=0.0f;
float carMove = 0.0f;
float flagAngle = 0.0f;

/// writing text in windows
void displayRasterText(float x ,float y ,float z ,char *stringToDisplay) {
	int length;
	glRasterPos3f(x, y, z);
		length = strlen(stringToDisplay);

	for(int i=0 ;i<length ;i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24 ,stringToDisplay[i]);
	}
}


void line()
{
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    glVertex3f(0.20,0.20,0);
    glVertex3f(0.30,0.20,0);
    glVertex3f(0.27,.24,0);
    glVertex3f(0.17,0.24,0);
    glEnd();
}

void line_row()
{
    glPushMatrix();
	glTranslatef(0.0,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5,-1,0.0);
    glScalef(5.0,2.5,0.0);

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-1,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.3,-2,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,-2,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.3,-2,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2,-2,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.7,-2,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.2,-2,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.7,-2.0,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.2,-2.0,0.0);
    glScalef(5.0,2.5,0.0);
    line();
    glPopMatrix();

}

/// plane

void AirCraft(){
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(5,0.8,0);

    glColor3ub(0,104,0);
    glutSolidCube(0.2);

    glPopMatrix();

    //head
    glPushMatrix();
    glTranslatef(0.5,-0.92,0);
    glScalef(0.15,0.16,1);
    glRotatef(90,0,0,-1);
    glColor3ub(0,104,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0.5,1,0);
    glEnd();
    glPopMatrix();

    //tail
    glPushMatrix();
    glTranslatef(-0.5,-0.92,0);
    glScalef(0.2,0.2,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glVertex3f(0.3,1,0);
    glVertex3f(1,0,0);
    glEnd();
    glPopMatrix();

    //tail2
/*
    glPushMatrix();
    glTranslatef(-0.53,-1.2,0.0);
    glScalef(0.15,0.25,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(0.7,0,0);
    glVertex3f(1.5,1,0);
    glVertex3f(0.5,1,0);
    glEnd();
    glPopMatrix();
*/

    //left wing
    glPushMatrix();
    glTranslatef(0,-0.92,0);
    glScalef(0.2,0.3,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0.2,1,0);
    glVertex3f(-0.5,1,0);
    glEnd();
    glPopMatrix();

    //left wing
    glPushMatrix();
    glTranslatef(-0.1,-1.48,0);
    glScalef(0.2,0.4,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(0.7,0,0);
    glVertex3f(1.5,1,0);
    glVertex3f(0.5,1,0);
    glEnd();
    glPopMatrix();


}

///chief guest

void guest_human(){

glPushMatrix();
 glScalef(0.2,0.2,0.2);
//glRotatef(-60, 0.0, 1.0, 0.0);
glPushMatrix();
glTranslatef(0.0,0.0,0.3);


  ///head
     glPushMatrix();
   glColor3ub(244, 191, 66);
    glTranslatef(0.0,1,0);
   // glRotatef(60,0.8,0.6,1.0);
    glutSolidSphere(0.3,10,10);

   ///body

    glTranslatef(0,-0.65,0);
    glScalef(1,1,0.8);
     glColor3f(0,0,0);
    glutSolidCube(0.9);

    glPopMatrix();

    ///human leg
    glPushMatrix();
    // left leg
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.5,1,1.5);

    glColor3f(0,0,0);
    glutSolidCube(0.4);

    glPopMatrix();

    glPushMatrix();
     //right leg
    glTranslated(0.2,-0.3,0.0);
    glScalef(0.5,1,1.5);
     glColor3f(0,0,0);
    glutSolidCube(0.4);

    glPopMatrix();


    /// foot
    glPushMatrix();

    glTranslatef(0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
     glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
    glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    ///arms
    glPushMatrix();

    glTranslatef(0.55,0.5,0);
    glScalef(0.5,1,1.5);
    glColor3f(0,0,0);
    glutSolidCube(0.5);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-0.55,0.5,0);
    glScalef(0.5,1,1.5);
   glColor3f(0,0,0);
    glutSolidCube(0.5);

    glPopMatrix();

    ///human hand
    glPushMatrix();

    glTranslatef(0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

glPopMatrix();
glPopMatrix();

}


/// car
void big_van(){


/// car body part 1

    glPushMatrix();

     glPushMatrix();
    glTranslatef(0,-1,0);

    glColor3ub(0, 51, 102);
    glutSolidCube(0.45);
    glPopMatrix();

    ///car body part 2
     glPushMatrix();
    glTranslatef(0.3,-1,0);


    glColor3ub(0, 51, 102);
    glutSolidCube(0.45);
    glPopMatrix();

     ///car body part 3
     glPushMatrix();
    glTranslatef(0.7,-1.0,0);


    glColor3ub(0, 51, 102);
    glutSolidCube(0.45);
    glPopMatrix();


     ///first engine side
     glPushMatrix();
    glTranslatef(-0.25,-1.15,0);
    glColor3ub(0, 51, 0);
    glutSolidCube(0.2);
    glPopMatrix();
      ///second engine side
     glPushMatrix();
    glTranslatef(-0.25,-1.15,0);
    glColor3ub(0, 51, 0);
    glutSolidCube(0.2);
    glPopMatrix();


     ///first tire
     glPushMatrix();
     glTranslatef(0.0,-1.26,0);
     glColor3f(0,0,0);
     glScalef(0.25,0.25,0);
     glutSolidTorus(0.1,0.3,10,10);
     glPopMatrix();


     ///second tire
     glPushMatrix();
     glTranslatef(0.6,-1.26,0);
     glColor3f(0,0,0);
     glScalef(0.25,0.25,0);
     glutSolidTorus(0.1,0.3,10,10);
     glPopMatrix();



  glPopMatrix();

}

void ship_demo(){

	glPushMatrix(); //Save the current state of transformations
    //glColor3f(1,0,0);

    glBegin(GL_POLYGON);

	glVertex3f(-2.0, 1.0, 0.0);
	glVertex3f(-1.5, 0.3, 0.0);
	glVertex3f(1.5, 0.3, 0.0);
	glVertex3f(2.0, 1.0, 0.0);

    glEnd();
    glColor3ub(0,0,0);
    glTranslatef(-1,1.1,0);
    glutSolidSphere(.3,20,20);

    glBegin(GL_POLYGON);

	glVertex3f(-0.6, 0.1, 0.0);
	glVertex3f(0.0, 0.1, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-0.6, 0.0, 0.0);

    glEnd();

    glTranslatef(1.5,0,0);
    glutSolidCube(.6);
/*
    //glColor3ub(99,109,101);
    glBegin(GL_POLYGON);

    glVertex3f(-2.5, 0.3, 0.0);
	glVertex3f(2.5, 0.3, 0.0);
	glVertex3f(2.5, 0.0, 0.0);
	glVertex3f(-2.5, 0.0, 0.0);
*/
    glPopMatrix();



}

void flag(){

   glPushMatrix();
       glTranslatef(60,-1,0);

       glPushMatrix();


       glTranslatef(-flagAngle,0,0);

       //glColor3f(0,0,0);
       //displayRasterText(-0.5,0,0,"press S button to start again");

       glScalef(.4, .4, 0);
       glColor3f(0,1,0);
       glBegin(GL_POLYGON);
       glVertex3f(-2,.5,0);
       glVertex3f(4,.5,0);
       glVertex3f(4,-.5,0);
       glVertex3f(-2,-.5,0);
       glEnd();

        glColor3ub(20,35,20);
       glBegin(GL_POLYGON);
       glVertex3f(-2.1,1,0);
       glVertex3f(-2,1,0);
       glVertex3f(-2,-4,0);
       glVertex3f(-2.1,-4,0);
       glEnd();

       glPopMatrix();

        glPopMatrix();

}
void tank(){

   	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 0.0, 0.0); //Move to the center of the pentagon
	glColor3ub(5,114,22);

    glBegin(GL_POLYGON);

    glVertex3f(-1.5, 1.0, 0.0);
	glVertex3f(-2.0, 0.7, 0.0);
	glVertex3f(-2.0, 0.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(1.5, 1.0, 0.0);
	glVertex3f(2.0, 0.7, 0.0);
	glVertex3f(2.0, 0.5, 0.0);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3f(-1.8, 1.0, 0.0);
	glVertex3f(1.8, 1.0, 0.0);
	glVertex3f(1.8, 0.8, 0.0);
	glVertex3f(-1.8, 0.8, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.3,0);
    glBegin(GL_POLYGON);

    glVertex3f(-1.6, 1.0, 0.0);
	glVertex3f(1.6, 1.0, 0.0);
	glVertex3f(1.6, 0.7, 0.0);
	glVertex3f(-1.6, 0.7, 0.0);
    glEnd();

    glTranslatef(0,0.3,0);
    glBegin(GL_POLYGON);

    glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(1.6, 1.0, 0.0);
	glVertex3f(1.6, 0.7, 0.0);
	glVertex3f(-1.6, 0.7, 0.0);
    glEnd();

    glTranslatef(-1.2,0.75,0);
    glRotatef(-20,0,0,1);
    glBegin(GL_POLYGON);
    glColor3ub(24,84,33);
    glVertex3f(-1.7, 0.2, 0.0);
	glVertex3f(0.0, 0.2, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(-1.7, 0.0, 0.0);
    glEnd();



    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0,-0.8,0);
    glutSolidTorus(0.1,0.2,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6,-0.6,0);
    glutSolidTorus(0.1,0.2,20,20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1.2,-0.45,0);
    glutSolidTorus(0.1,0.2,20,20);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(1.7,-0.25,0);
    glutSolidTorus(0.1,0.2,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.2,-0.1,0);
    glutSolidTorus(0.1,0.2,20,20);
    glPopMatrix();

     glPushMatrix();
    glTranslatef(2.7,0.1,0);
    glutSolidTorus(0.1,0.2,20,20);
    glPopMatrix();



/*


    glPushMatrix();
    glTranslatef(0.8,-0.8,0);
    glutSolidTorus(0.3,0.3,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2,-0.8,0);
    glutSolidTorus(0.3,0.3,10,10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,-0.8,0);
    glutSolidTorus(0.3,0.3,10,10);
    glPopMatrix();

*/
    glPopMatrix();



}

///-------------------------army portion --------------------
///human for army
void army_human(){

glPushMatrix();
 glScalef(0.2,0.2,0.2);
glRotatef(-60, 0.0, 1.0, 0.0);
glPushMatrix();
glTranslatef(0.0,0.0,0.3);


  ///head
     glPushMatrix();
   glColor3ub(244, 191, 66);
    glTranslatef(0.0,1,0);
   // glRotatef(60,0.8,0.6,1.0);
    glutSolidSphere(0.3,10,10);

   ///body

    glTranslatef(0,-0.65,0);
    glScalef(1,1,0.8);
     glColor3ub(0, 153, 51);
    glutSolidCube(0.9);

    glPopMatrix();

    ///human leg
    glPushMatrix();
    // left leg
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.5,1,1.5);

    glColor3ub( 0, 102, 0);
    glutSolidCube(0.4);

    glPopMatrix();

    glPushMatrix();
     //right leg
    glTranslated(0.2,-0.3,0.0);
    glScalef(0.5,1,1.5);
     glColor3ub( 0, 102, 0);
    glutSolidCube(0.4);

    glPopMatrix();


    /// foot
    glPushMatrix();

    glTranslatef(0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
     glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
    glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    ///arms
    glPushMatrix();

    glTranslatef(0.55,0.5,0);
    glScalef(0.5,1,1.5);
    glColor3ub(0, 102, 0);
    glutSolidCube(0.5);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-0.55,0.5,0);
    glScalef(0.5,1,1.5);
   glColor3ub(0, 102, 0);
    glutSolidCube(0.5);

    glPopMatrix();

    ///human hand
    glPushMatrix();

    glTranslatef(0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

glPopMatrix();
glPopMatrix();
}

void army_front_man(){
///front man

glPushMatrix();
glTranslatef(0,-1.2,0.0);
army_human();
glPopMatrix();

}
void army_gird_human(){

///  row 1


glPushMatrix();
glTranslatef(1.0,-0.5,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(1.5,-1.0,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.5,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-2.0,0.0);
army_human();
glPopMatrix();

///row 2


glPushMatrix();
glTranslatef(1.5,-0.5,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.0,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1.5,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-2,0.0);
army_human();
glPopMatrix();


/// row 3

glPushMatrix();
glTranslatef(2,-0.5,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1,0.0);

army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-1.5,0.0);
army_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3.5,-2,0.0);
army_human();
glPopMatrix();


}


void navy_human(){

glPushMatrix();
 glScalef(0.2,0.2,0.2);
glRotatef(-60, 0.0, 1.0, 0.0);
	glPushMatrix();
glTranslatef(0.0,0.0,0.3);


  ///head
     glPushMatrix();
   glColor3ub(244, 191, 66);
    glTranslatef(0.0,1,0);
   // glRotatef(60,0.8,0.6,1.0);
    glutSolidSphere(0.3,10,10);

   ///body

    glTranslatef(0,-0.65,0);
    glScalef(1,1,0.8);
     glColor3ub(31, 33, 122);
    glutSolidCube(0.9);

    glPopMatrix();

    ///human leg
    glPushMatrix();
    // left leg
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.5,1,1.5);

    glColor3ub(66, 69, 24);
    glutSolidCube(0.4);

    glPopMatrix();

    glPushMatrix();
     //right leg
    glTranslated(0.2,-0.3,0.0);
    glScalef(0.5,1,1.5);
     glColor3ub(66, 69, 24);
    glutSolidCube(0.4);

    glPopMatrix();


    /// foot
    glPushMatrix();

    glTranslatef(0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
     glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
    glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();


    ///---rotate hands with arms ---
    ///arms

    glPushMatrix();

    glPushMatrix();

    glTranslatef(0.55,0.5,0);
    glScalef(0.5,1,1.5);
    glColor3ub(250, 249, 255);
    glutSolidCube(0.5);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-0.55,0.5,0);
    glScalef(0.5,1,1.5);
   glColor3ub(31, 33, 122);
    glutSolidCube(0.5);

    glPopMatrix();

    ///human hand
    glPushMatrix();

    glTranslatef(0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();
    glPopMatrix();

glPopMatrix();
glPopMatrix();
}

void navy_front_man(){
///front man

glPushMatrix();
glTranslatef(0,-1,0.0);
navy_human();
glPopMatrix();

}

void navy_gird_human(){

///  row 1


glPushMatrix();
glTranslatef(1.0,-0.5,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(1.5,-1.0,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.5,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-2.0,0.0);
navy_human();
glPopMatrix();

///row 2



glPushMatrix();
glTranslatef(1.5,-0.5,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.0,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1.5,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-2,0.0);
navy_human();
glPopMatrix();


/// row 3




glPushMatrix();
glTranslatef(2,-0.5,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1,0.0);

navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-1.5,0.0);
navy_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3.5,-2,0.0);
navy_human();
glPopMatrix();


}

///--------------------airforce human -------------------------///



void airforce_human(){

glPushMatrix();
 glScalef(0.2,0.2,0.2);
glRotatef(-60, 0.0, 1.0, 0.0);
	glPushMatrix();
glTranslatef(0.0,0.0,0.3);


  ///head
     glPushMatrix();
   glColor3ub(244, 191, 66);
    glTranslatef(0.0,1,0);
   // glRotatef(60,0.8,0.6,1.0);
    glutSolidSphere(0.3,10,10);

   ///body

    glTranslatef(0,-0.65,0);
    glScalef(1,1,0.8);
     glColor3ub(252, 252, 252);
    glutSolidCube(0.9);

    glPopMatrix();

    ///human leg
    glPushMatrix();
    // left leg
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.5,1,1.5);

    glColor3ub(252, 252, 252);;
    glutSolidCube(0.4);

    glPopMatrix();

    glPushMatrix();
     //right leg
    glTranslated(0.2,-0.3,0.0);
    glScalef(0.5,1,1.5);
     glColor3ub(252, 252, 252);
    glutSolidCube(0.4);

    glPopMatrix();


    /// foot
    glPushMatrix();

    glTranslatef(0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
     glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
    glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    ///arms
    glPushMatrix();

    glTranslatef(0.55,0.5,0);
    glScalef(0.5,1,1.5);
   glColor3ub(252, 252, 252);
    glutSolidCube(0.5);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-0.55,0.5,0);
    glScalef(0.5,1,1.5);
  glColor3ub(252, 252, 252);
    glutSolidCube(0.5);

    glPopMatrix();

    ///human hand
    glPushMatrix();

    glTranslatef(0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

glPopMatrix();
glPopMatrix();
}

void airforce_front_man(){
///front man

glPushMatrix();
glTranslatef(0,-1,0.0);
airforce_human();
glPopMatrix();

}

void airforce_gird_human(){

///  row 1


glPushMatrix();
glTranslatef(1.0,-0.5,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(1.5,-1.0,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.5,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-2.0,0.0);
airforce_human();
glPopMatrix();

///row 2



glPushMatrix();
glTranslatef(1.5,-0.5,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.0,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1.5,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-2,0.0);
airforce_human();
glPopMatrix();


/// row 3


glPushMatrix();
glTranslatef(2,-0.5,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1,0.0);

airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-1.5,0.0);
airforce_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3.5,-2,0.0);
airforce_human();
glPopMatrix();


}


void police_human(){

glPushMatrix();
 glScalef(0.2,0.2,0.2);
glRotatef(-60, 0.0, 1.0, 0.0);
glPushMatrix();
glTranslatef(0.0,0.0,0.3);


  ///head
     glPushMatrix();
   glColor3ub(244, 191, 66);
    glTranslatef(0.0,1,0);
   // glRotatef(60,0.8,0.6,1.0);
    glutSolidSphere(0.3,10,10);

   ///body

    glTranslatef(0,-0.65,0);
    glScalef(1,1,0.8);
     glColor3ub(6, 28, 155);
    glutSolidCube(0.9);

    glPopMatrix();

    ///human leg
    glPushMatrix();
    // left leg
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.5,1,1.5);

    glColor3ub(0, 0, 0);
    glutSolidCube(0.4);

    glPopMatrix();

    glPushMatrix();
     //right leg
    glTranslated(0.2,-0.3,0.0);
    glScalef(0.5,1,1.5);
     glColor3ub(0, 0, 0);
    glutSolidCube(0.4);

    glPopMatrix();


    /// foot
    glPushMatrix();

    glTranslatef(0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
     glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
    glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    ///arms
    glPushMatrix();

    glTranslatef(0.55,0.5,0);
    glScalef(0.5,1,1.5);
    glColor3ub(6, 28, 155);
    glutSolidCube(0.5);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-0.55,0.5,0);
    glScalef(0.5,1,1.5);
   glColor3ub(6, 28, 155);
    glutSolidCube(0.5);

    glPopMatrix();

    ///human hand
    glPushMatrix();

    glTranslatef(0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

glPopMatrix();
glPopMatrix();

}


void police_front_man(){

   glPushMatrix();
   glTranslatef(0,-1,0.0);
   police_human();
   glPopMatrix();

}


void police_grid_human(){

///  row 1


glPushMatrix();
glTranslatef(1.0,-0.5,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(1.5,-1.0,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.5,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-2.0,0.0);
police_human();
glPopMatrix();

///row 2


glPushMatrix();
glTranslatef(1.5,-0.5,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.0,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1.5,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-2,0.0);
police_human();
glPopMatrix();


/// row 3

glPushMatrix();
glTranslatef(2,-0.5,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1,0.0);

police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-1.5,0.0);
police_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3.5,-2,0.0);
police_human();
glPopMatrix();


}


///--------Rab human force



void rab_human(){

glPushMatrix();
 glScalef(0.2,0.2,0.2);
glRotatef(-60, 0.0, 1.0, 0.0);
	glPushMatrix();
glTranslatef(0.0,0.0,0.3);


  ///head
     glPushMatrix();
   glColor3ub(244, 191, 66);
    glTranslatef(0.0,1,0);
   // glRotatef(60,0.8,0.6,1.0);
    glutSolidSphere(0.3,10,10);

   ///body

    glTranslatef(0,-0.65,0);
    glScalef(1,1,0.8);
     glColor3f(0, 0, 0);
    glutSolidCube(0.9);

    glPopMatrix();

    ///human leg
    glPushMatrix();
    // left leg
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.5,1,1.5);

    //glColor3ub(252, 252, 252);;
    glutSolidCube(0.4);

    glPopMatrix();

    glPushMatrix();
     //right leg
    glTranslated(0.2,-0.3,0.0);
    glScalef(0.5,1,1.5);
     glColor3f(0, 0, 0);
    glutSolidCube(0.4);

    glPopMatrix();


    /// foot
    glPushMatrix();

    glTranslatef(0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
     glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.2,-0.63,0);
    glScalef(0.5,1.4,1.5);
    glColor3ub(51, 51, 0);
    glutSolidCube(0.25);

    glPopMatrix();

    ///arms
    glPushMatrix();

    glTranslatef(0.55,0.5,0);
    glScalef(0.5,1,1.5);
   glColor3f(0, 0, 0);
    glutSolidCube(0.5);

    glPopMatrix();


    glPushMatrix();

    glTranslatef(-0.55,0.5,0);
    glScalef(0.5,1,1.5);
  glColor3ub(252, 252, 252);
    glutSolidCube(0.5);

    glPopMatrix();

    ///human hand
    glPushMatrix();

    glTranslatef(0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.59,0.15,0);
    glScalef(0.4,1,1.5);
    glColor3ub(244, 191, 66);
    glutSolidCube(0.25);

    glPopMatrix();

glPopMatrix();
glPopMatrix();
}

void rab_front_man(){

   glPushMatrix();
   glTranslatef(0,-1,0.0);
   rab_human();
   glPopMatrix();

}


void rab_grid_human(){

///  row 1


glPushMatrix();
glTranslatef(1.0,-0.5,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(1.5,-1.0,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.5,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-2.0,0.0);
rab_human();
glPopMatrix();

///row 2


glPushMatrix();
glTranslatef(1.5,-0.5,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2,-1.0,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1.5,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-2,0.0);
rab_human();
glPopMatrix();


/// row 3

glPushMatrix();
glTranslatef(2,-0.5,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(2.5,-1,0.0);

rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3,-1.5,0.0);
rab_human();
glPopMatrix();

glPushMatrix();
glTranslatef(3.5,-2,0.0);
rab_human();
glPopMatrix();


}


///--------------------------------------------------------
/// green ground

void GreenGround(){
    glPushMatrix();
    glTranslatef(0,-0.08,-0.25);
    glScalef(25,1,1);
    glScalef(25,1,1);
    glColor3ub(22, 135, 26);
    glutSolidCube(0.5);
    glPopMatrix();

}

/// tree 1
void Tree(){
glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, -0.5, 0.0); //Move to the center of the trapezoid
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.0, 0.0);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.1, -0.4, 0.0);
	glVertex3f(-0.1, -0.4, 0.0);
	glEnd();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glColor3ub(0,152,0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();

	glTranslatef(0.0, 0.6, 0.0); //Move to the center of the trapezoid
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();

	glTranslatef(0.0, 0.6, 0.0); //Move to the center of the trapezoid
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();
	glPopMatrix();


//-------------------------------------------------------------------



//---------------------------------------------------



}

/// tree 2
void Tree2(){


	    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, -0.5, 0.0); //Move to the center of the trapezoid
	glColor3ub(102,102,0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.0, 0.0);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.1, -0.4, 0.0);
	glVertex3f(-0.1, -0.4, 0.0);
	glEnd();
	glPopMatrix();

    	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glColor3ub(90,208,0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();

	glTranslatef(0.0, 0.6, 0.0); //Move to the center of the trapezoid
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();

	glTranslatef(0.0, 0.6, 0.0); //Move to the center of the trapezoid
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();
	glPopMatrix();

}

///stage for chief guest
void Stage(){
 glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, 0.0, 0.0); //Move to the center of the trapezoid
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.2, 0.0);
	glVertex3f(2.0, 0.2, 0.0);
	glEnd();

    glTranslatef(0.0, -0.2, 0.0); //Move to the center of the trapezoid
    glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(2.3, 0.0, 0.0);
	glVertex3f(-2.3, 0.0, 0.0);
	glVertex3f(-2.0, 0.2, 0.0);
	glVertex3f(2.0, 0.2, 0.0);
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, 2.0, 0.0); //Move to the center of the trapezoid
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-1.7, 0.2, 0.0);
	glVertex3f(1.7, 0.2, 0.0);
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(1.7, 0.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(-0.1, 0.0, 0.0);
	glVertex3f(-0.1, 1.8, 0.0);
	glVertex3f(0.1, 1.8, 0.0);
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(-1.7, 0.2, 0.0); //Move to the center of the trapezoid
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(-0.1, 0.0, 0.0);
	glVertex3f(-0.1, 1.8, 0.0);
	glVertex3f(0.1, 1.8, 0.0);
	glEnd();
	glPopMatrix();

    glPushMatrix(); //Save the transformations performed thus far
	glTranslatef(0.0, 0.2, 0.0); //Move to the center of the trapezoid
    glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
	glVertex3f(1.7, 0.0, 0.0);
	glVertex3f(-1.7, 0.0, 0.0);
	glVertex3f(-1.7, 1.8, 0.0);
	glVertex3f(1.7, 1.8, 0.0);
	glEnd();
	glPopMatrix();


}
///sky blue
void Sky(){

    glPushMatrix();
    glScalef(6,1.5,1);
    glTranslatef(0,1.21,0);
    glColor3ub(128, 174, 247);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -3.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -3.0, 0.0);
    glEnd();
    glPopMatrix();


}
///cloud
void Cloud(){
	glPushMatrix(); //Save the transformations performed thus far
	glColor3ub(252,252,252);
	glTranslatef(1.0, 0.0, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.5, 20, 20);
	glTranslatef(-2.0, 0.0, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.5, 20, 20);
	glTranslatef(0.5, 0.5, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.5, 20, 20);
	glTranslatef(0.5, 0.0, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.5, 20, 20);
	glTranslatef(0.5, 0.0, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.5, 20, 20);
	glTranslatef(-0.2, -0.9, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.7, 20, 20);
	glTranslatef(-0.6, 0.0, 0.0); //Move to the center of the trapezoid
	glutSolidSphere(.7, 20, 20);
    glPopMatrix();
}
///sun
void Sun(){
    glPushMatrix();
    glTranslatef(4,3,0.01);
    glScalef(1,1,0.1);
    glColor3ub(255, 225, 5);
    glutSolidSphere(0.4,40,40);
    glPopMatrix();


}

void drawScene() {

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 unit*/
	//glRotatef(60, 1.0, 0.0, 0.0);






/// parade round army

    glPushMatrix();

     glTranslatef(-HumanAngle,0,0);
     glTranslatef(0,-0.3,0);

     glPushMatrix();
    // glTranslatef(3.0,2.62,0.0);
     army_front_man();
     glPopMatrix();

        glPushMatrix();
        army_gird_human();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(1.5,0.0,0.0);
        army_gird_human();
        glPopMatrix();

      glPopMatrix();



/// parade round airforce
      glPushMatrix();

     glTranslatef(-HumanAngle,0,0);
      glTranslatef(0,-0.3,0);
     glPushMatrix();
    // glTranslatef(3.0,2.62,0.0);
     glTranslatef(7,-0.2,0.0);
     airforce_front_man();
     glPopMatrix();

        glPushMatrix();
         glTranslatef(7,0.0,0.0);
        airforce_gird_human();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(8.5,0.0,0.0);
        airforce_gird_human();
        glPopMatrix();

      glPopMatrix();



/// parade round navy
      glPushMatrix();

     glTranslatef(-HumanAngle,0,0);
      glTranslatef(0,-0.3,0);
     glPushMatrix();
    // glTranslatef(3.0,2.62,0.0);
      glTranslatef(14,-0.3,0.0);
     navy_front_man();
     glPopMatrix();

        glPushMatrix();
         glTranslatef(14.5,0.0,0.0);
        navy_gird_human();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(16,0.0,0.0);
        navy_gird_human();
        glPopMatrix();

      glPopMatrix();

      /// big van moving
        glPushMatrix();
         glTranslatef(-HumanAngle,0,0);

       //  glRotatef(7,1,0,0);
          glPushMatrix();
            glTranslatef(37,0.0,0.0);
           big_van();

        glPopMatrix();

         glPushMatrix();
            glTranslatef(37.5,-0.8,0.0);
           big_van();
          glPopMatrix();

        glPopMatrix();


        glPopMatrix();


      ///parade round police

       glPushMatrix();

     glTranslatef(-HumanAngle,0,0);
      glTranslatef(0,-0.3,0);
     glPushMatrix();
    // glTranslatef(3.0,2.62,0.0);
      glTranslatef(25,-0.3,0.0);
     police_front_man();
     glPopMatrix();

        glPushMatrix();
         glTranslatef(25.5,0.0,0.0);
        police_grid_human();
    glPopMatrix();

        glPushMatrix();
        glTranslatef(26.5,0.0,0.0);
        police_grid_human();
        glPopMatrix();

      glPopMatrix();


      ///rab parade ground

       glPushMatrix();

     glTranslatef(-HumanAngle,0,0);
      glTranslatef(0,-0.3,0);
     glPushMatrix();
    // glTranslatef(3.0,2.62,0.0);
      glTranslatef(45,-0.3,0.0);
     rab_front_man();
     glPopMatrix();

        glPushMatrix();
         glTranslatef(46,0.0,0.0);
        rab_grid_human();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(47.5,0.0,0.0);
        rab_grid_human();
        glPopMatrix();

      glPopMatrix();


       ///flag
       glPushMatrix();
       glTranslatef(65,-1,0);

       glPushMatrix();


       glTranslatef(-flagAngle,0,0);

       glColor3f(0,0,0);
       displayRasterText(-0.5,0,0,"press S button to start again");

       glScalef(.4, .4, 0);
       glColor3f(0,1,0);
       glBegin(GL_POLYGON);
       glVertex3f(-2,.5,0);
       glVertex3f(4,.5,0);
       glVertex3f(4,-.5,0);
       glVertex3f(-2,-.5,0);
       glEnd();


       glPopMatrix();



        glPopMatrix();

   /// tank for army

      glPushMatrix();
       glTranslatef(-HumanAngle,0,0);
          glPushMatrix();

          glTranslatef(55,-2,0);
          glScalef(0.7,0.7,0);
             tank();
           glPopMatrix();


            glPushMatrix();

          glTranslatef(59,-2,0);
          glScalef(0.7,0.7,0);
             tank();
           glPopMatrix();
      glPopMatrix();





    ///Road line
    glPushMatrix();
    glTranslatef(0.0, -0.7, 0.0);
    line_row();
    glPopMatrix();

    ///Nflag

    glPushMatrix();
    glTranslatef(1.3,.5,0);
    glScalef(.2,.2,0);


       glBegin(GL_POLYGON);
       glColor3f(1,0,0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/40 ;
		float r=0.6;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

        glColor3ub(0,102,0);
       glBegin(GL_POLYGON);
       glVertex3f(-2,1,0);
       glVertex3f(2,1,0);
       glVertex3f(2,-1,0);
       glVertex3f(-2,-1,0);
       glEnd();

    glColor3f(100,100,100);
       glBegin(GL_POLYGON);
       glVertex3f(-2,1,0);
       glVertex3f(-2.1,1,0);
       glVertex3f(-2.1,-4,0);
       glVertex3f(-2,-4,0);
       glEnd();


       glTranslatef(-2.05,-4,0);
       glColor3f(0,0,0);
       glutSolidCube(.3);
    glPopMatrix();


///tree



//left side tree
    glPushMatrix();
    glTranslatef(-3.0, 0.2, 0.0);
    glScalef(0.4,0.3,0);
    Tree();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-4.0, 0.2, 0.0);
    glScalef(0.4,0.3,0);
    Tree();
    glPopMatrix();

   // right side tree
     glPushMatrix();
    glTranslatef(2.0, 0.2, 0.0);
    glScalef(0.4,0.3,0);
    Tree2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(3.0, 0.2, 0.0);
    glScalef(0.4,0.3,0);
    Tree2();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(4.0, 0.2, 0.0);
    glScalef(0.4,0.3,0);
    Tree2();
    glPopMatrix();




    ///text
    glPushMatrix();
    glColor3f(1,0,0);
    displayRasterText(-1.6,1,0 ,"16th December");
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,1.11,0);
    glScalef(4.8,0.92,0);

    glColor3ub(0,104,0);
    glutSolidCube(0.5);

    glPopMatrix();



    /// chief guests on stage
     glPushMatrix();
     glRotated(10,0,1,0);

      glPushMatrix();
      glTranslatef(-0.9,-0.2,0);
     guest_human();
     glPopMatrix();

    glPushMatrix();
      glTranslatef(-1.7,0.2,0);
     guest_human();
     glPopMatrix();
      glPushMatrix();
      glTranslatef(-1.2,0.2,0);
     guest_human();
     glPopMatrix();

       glPushMatrix();
        glTranslatef(-0.7,0.2,0);
     guest_human();
     glPopMatrix();

       glPushMatrix();
        glTranslatef(-0.2,0.2,0);
     guest_human();
     glPopMatrix();

     glPopMatrix();


    ///stage



     glPushMatrix();
    glTranslatef(-1.0,0.0, 0.0);
   // glRotatef(30,1.0,1.0, 0.0);
    glScalef(0.7,0.4,0);
    Stage();
    glPopMatrix();



	///main road
	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(0,0.0, 1.0, 0.0);


	glBegin(GL_POLYGON);
	glColor3ub(128,128,128);

	glVertex3f(6.0,-3.0, 0.0);
	glVertex3f(-6.0,-3.0, 0.0);
	glVertex3f(-6.0, -0.5, 0.0);
	glVertex3f(6.0, -0.5, 0.0);

	glEnd();
	glPopMatrix();



    ///green grounds
     glPushMatrix();
     glTranslatef(0,-0.2,0);
     GreenGround();
    glPopMatrix();


        ///sun
     glPushMatrix();
     glTranslatef(-5,-1,0);
    Sun();
    glPopMatrix();

      ///clouds
    glPushMatrix();

    glTranslatef(cloudAngle,0,0);
    glPushMatrix();
    glTranslatef(-3,2,1);
    glScalef(0.5,0.3,0);
    Cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,2,1);
    glScalef(0.3,0.2,0);
    Cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,2,1);
    glScalef(0.6,0.2,0);
    Cloud();
    glPopMatrix();

    glPopMatrix();



    ///plane

    glPushMatrix();
    glTranslatef(airSpeed,0,0);
    //glRotatef(20,1,1,0);
    glPushMatrix();
    glTranslatef(-1.5,2.6,0.5);
    glScalef(0.9,0.5,0);
    AirCraft();
    glPopMatrix();

    ///last two plane
    glPushMatrix();
    glTranslatef(-3,2.9,0.5);
    glScalef(0.9,0.5,0);
    AirCraft();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-3.0,2.4,0.5);
    glScalef(0.9,0.5,0);
    AirCraft();
    glPopMatrix();


    glPopMatrix();


   ///sky
    glPushMatrix();
    Sky();
    glPopMatrix();


    glPopMatrix();

	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;


    case 83:     /// S for start
        //_moveCY -= 0.1f;
        //glutPostRedisplay();
        //FindClash(7);

        //glutDisplayFunc(drawScene);
         _angle = 0.0;
         _cameraAngle = 0.0;
         _ang_tri = 0.0;
         HumanAngle=0.0f;
         TankAngle=0.0f;
         airSpeed=0.0f;
         cloudAngle = 0.0f;
         humanArmMove=0.0f;
         carMove = 0.0f;
         flagAngle = 0.0f;

        //drawScene();

        break;


   }
}


void HumanUpdate(int value) {
	HumanAngle+= 0.01f;
	if (HumanAngle > 100.0f) {
		HumanAngle -= 5.0f;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(15, HumanUpdate, 0);
}

void TankUpdate(int value) {
	TankAngle+= 0.01f;
	if (TankAngle > 100.0f) {
		TankAngle -= 5.0f;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, TankUpdate, 0);
}

void flagUpdate(int value) {

     flagAngle+= 0.01f;
    if(flagAngle>100.0f){
        //move=true;
        flagAngle=-5.0f;
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed



    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(15, flagUpdate, 0);
}


void HumanBodyMoveUpdate(int value) {
	humanArmMove+= 0.01f;
	if (humanArmMove > 100.0f) {
		humanArmMove -= 5.0f;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(15, HumanBodyMoveUpdate, 0);
}

void AirPlaneUpdate(int value){

    airSpeed += 0.03f;
    if(airSpeed>50.0f){
        //move=true;
        airSpeed=-2.5f;
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(10, AirPlaneUpdate, 0);

}

void CarUpdate(int value){

    carMove += 0.01f;
    if(carMove>100.0f){
        //move=true;
        carMove=-5.0f;
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, CarUpdate, 0);

}

void CloudUpdate(int value){

     cloudAngle+=0.001f;
    if(cloudAngle>14.0f){
        //move=true;
        cloudAngle=-5.0f;
    }

    glutPostRedisplay(); //Tell GLUT that the display has changed



    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, CloudUpdate, 0);
}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1360, 760);

	//Create the window
	glutCreateWindow("Tribute to Hero's");
	initRendering();
	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, HumanUpdate, 0);
	glutTimerFunc(100, CloudUpdate, 0); //Add a timer
    glutTimerFunc(15, AirPlaneUpdate, 0);
    glutTimerFunc(25, HumanBodyMoveUpdate, 0);
    glutTimerFunc(25, CarUpdate, 0);
    glutTimerFunc(25, TankUpdate, 0);
    glutTimerFunc(25, flagUpdate, 0);
    glutFullScreen();
    glutKeyboardFunc(keyboard);


	glutMainLoop();
	return 0;
}



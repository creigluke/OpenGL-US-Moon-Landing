#include<windows.h>

#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

const float DEG2RAD = 3.14159/180;
void stars();
int p;
void stars1();



float PI=3.1415;

void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius);

void static_rocket();
void rocket_to_cam_pos();
void rocket_in_motion();

void moon(float radius);

void satellite();

void manwalking(float i);
void usflag();

float i,j,count=0,count1=0,count3=0,flag=0,flag1=0,t=0,f=0,flag3=0;

int x=0;//counter for the astronaut

int h=0; //counter for the satellite

// fucntion to display the text content of the home screen
void drawstring(int x, int y, char *s)
{
	char *c;
	glRasterPos2i(x, y);
	for (c = s; *c != '\0'; *c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
}

void semicircle(float radius,float u,float v)
{

	glColor3f(1.0 ,1.0 ,1.0);
   glBegin(GL_POLYGON);

   for (int i=135; i<=315; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(u+cos(degInRad)*radius,v+(sin(degInRad))*radius);//100,100 specifies centre of the circle
   }

   glEnd();
}

//determines the state of rocket launch
void control()
{
	count1++;
	if(count1==250)
      		flag=1;



	else if (flag == 1 && (count1 == 600 || count1 == 601))
		rocket_to_cam_pos();

	else if (flag == 1 && count1 >= 1000)
		rocket_in_motion();

}

void stars()
{

	glColor3f(1.0,1.0,1.0);
	glPointSize(1.37);
	glBegin(GL_POINTS);
	glVertex2i(10,20);
	glVertex2i(20,100);
	glVertex2i(30,10);
	glVertex2i(15,150);
	glVertex2i(17,80);
	glVertex2i(200,200);
	glVertex2i(55,33);
	glVertex2i(400,300);
	glVertex2i(330,110);
	glVertex2i(125,63);
	glVertex2i(63,125);
	glVertex2i(20,10);
	glVertex2i(110,330);
	glVertex2i(440,430);
	glVertex2i(32,65);
	glVertex2i(110,440);
	glVertex2i(210,230);
	glVertex2i(390,490);
	glVertex2i(12,90);
	glVertex2i(400,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(20,20);
	glVertex2i(111,120);
	glVertex2i(401,200);
	glVertex2i(230,30);
	glVertex2i(220,20);
	glVertex2i(122,378);
	glVertex2i(133,340);
	glVertex2i(345,420);
	glVertex2i(130,360);
	glVertex2i(333,120);
	glVertex2i(250,22);
	glVertex2i(242,11);
	glVertex2i(280,332);
	glVertex2i(233,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);
	glEnd();
}

void stars1()
{
	int l;
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.0);
	glBegin(GL_POINTS);

	glVertex2i(50,20);
	glVertex2i(70,100);
	glVertex2i(80,10);
	glVertex2i(65,150);
	glVertex2i(67,80);
	glVertex2i(105,33);
	glVertex2i(450,300);
	glVertex2i(380,110);
	glVertex2i(175,63);
	glVertex2i(113,125);
	glVertex2i(70,10);
	glVertex2i(160,330);
	glVertex2i(490,430);
	glVertex2i(82,65);
	glVertex2i(160,440);
	glVertex2i(440,490);
	glVertex2i(62,90);
	glVertex2i(450,322);
	glVertex2i(420,366);
	glVertex2i(455,400);
	glVertex2i(60,20);
	glVertex2i(111,120);
	glVertex2i(451,200);
	glVertex2i(280,30);
	glVertex2i(220,20);
	glVertex2i(132,378);
	glVertex2i(173,340);
	glVertex2i(325,420);
	glVertex2i(180,360);
	glVertex2i(383,120);
	glVertex2i(200,22);
	glVertex2i(342,11);
	glVertex2i(330,332);
	glVertex2i(283,40);
	glVertex2i(210,418);
	glVertex2i(256,12);
	glVertex2i(288,232);
	glVertex2i(247,36);
	glVertex2i(229,342);
	glVertex2i(257,47);
	glVertex2i(290,63);
	glVertex2i(232,72);
	glVertex2i(243,143);
	glVertex2i(100,200);
	glVertex2i(90,250);
	glVertex2i(80,225);
	glVertex2i(50,333);
	glVertex2i(60,350);
	glVertex2i(243,143);
	glVertex2i(243,143);

	glEnd();
	for(l=0;l<=10000;l++)
		;
}
void static_rocket()
{
    //drawstring(100, 400, "Apollo SpaceCraft Launching from NASA launch site");

count1++;
if(count1==150)
flag=1;
  if(flag==0 && count<150)
  {
	glClearColor(0.196078  ,0.6 ,0.8,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(0.4,0.25,0.1);
		glBegin(GL_POLYGON);//green ground
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,250.0);
		glVertex2f(270.0,250.0);
		glVertex2f(500.0,50.0);
		glVertex2f(500.0,0.0);
		glEnd();
		glBegin(GL_POLYGON);//green ground
		glVertex2f(280.0,250.0);
		glVertex2f(500.0,250.0);
		glVertex2f(500.0,60.0);
		glEnd();
		glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);//road
		glVertex2f(260.0,250.0);
		glVertex2f(290.0,250.0);
		glVertex2f(500.0,70.0);
		glVertex2f(500.0,40.0);
		glEnd();
		glColor3f(0.0,0.0,0.0);


		glColor3f(0.8,0.498039 ,0.196078);
			glBegin(GL_POLYGON);//house 1
		glVertex2f(250.0,250.0);
		glVertex2f(300.0,250.0);
		glVertex2f(300.0,350.0);
		glVertex2f(250.0,350.0);
		glEnd();

		glColor3f(0.7,0.7,0.7);
		glBegin(GL_POLYGON);//HOUSE A
			glVertex2f(255,267.5);
			glVertex2f(275.0,267.5);
			glVertex2f(275.0,277.5);
			glVertex2f(255.0,277.5);
			glEnd();
		glBegin(GL_POLYGON);//HOUSE B
			glVertex2f(255,285.0);
			glVertex2f(275.0,285);
			glVertex2f(275.0,295);
			glVertex2f(255.0,295);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE C
			glVertex2f(255,302.5);
			glVertex2f(275.0,302.5);
			glVertex2f(275.0,312.5);
			glVertex2f(255.0,312.5);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE D
			glVertex2f(255,320.0);
			glVertex2f(275.0,320.0);
			glVertex2f(275.0,330.0);
			glVertex2f(255.0,330.0);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE E
			glVertex2f(285,267.5);
			glVertex2f(295.0,267.5);
			glVertex2f(295.0,277.5);
			glVertex2f(285.0,277.5);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE F
			glVertex2f(285,285.0);
			glVertex2f(295.0,285);
			glVertex2f(295.0,295);
			glVertex2f(285.0,295);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE G
			glVertex2f(285,302.5);
			glVertex2f(295.0,302.5);
			glVertex2f(295.0,312.5);
			glVertex2f(285.0,312.5);
			glEnd();

		glBegin(GL_POLYGON);//HOUSE H
			glVertex2f(285,320.0);
			glVertex2f(295.0,320.0);
			glVertex2f(295.0,330.0);
			glVertex2f(285.0,330.0);
			glEnd();
			glColor3f(0.647059 ,0.164706  ,0.164706);
			glBegin(GL_POLYGON);//solid cone
			glVertex2f(26,250);
			glVertex2f(52,250);
			glVertex2f(39,290);
			glEnd();
			semicircle(20.0,50,300);

	glColor3f(0.0,0.0 ,0.0);
			glBegin(GL_LINES);//wires
			glVertex2f(37,313);
			glVertex2f(62,310);
			glVertex2f(63,287);
			glVertex2f(62,310);
			glEnd();
		glColor3f(1.0,1.0,1.0);

		glEnd();
		glPointSize(2.0);

	glColor3f(1.0,1.0 ,1.0);
			glBegin(GL_POINTS);//road paint
			glVertex2f(497,56);
			glVertex2f(488,65);
			glVertex2f(479,74);
			glVertex2f(470,83);
			glVertex2f(460,92);
			glVertex2f(450,101);
			glVertex2f(439,110);
			glVertex2f(428,119);
			glVertex2f(418,128);
			glVertex2f(408,137);
			glVertex2f(398,146);
			glVertex2f(388,155);
			glVertex2f(378,164);
			glVertex2f(366,173);
			glVertex2f(356,182);
			glVertex2f(346,191);
			glVertex2f(336,200);
			glVertex2f(324,209);
			glVertex2f(314,218);
			glVertex2f(304,227);
			glVertex2f(294,234);
			glVertex2f(284,243);
	        glVertex2f(278,248);

			glEnd();


	glColor3f(0.0,0.0,0.0);//stand object
	glBegin(GL_POLYGON);
	glVertex2f(130,10.0);
	glVertex2f(160,10.0);
	glVertex2f(160,180.0);
	glVertex2f(130,180.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(130,30.0);
	glVertex2f(262,30.0);

	glVertex2f(130,130.0);
	glVertex2f(260,130.0);
	glEnd();

/*
	//THE BUILDING

	// Front Facing Building
	glBegin(GL_POLYGON);
	glColor3ub(30, 120, 182);
	glVertex2f(550, 125);
	glColor3ub(4, 36, 86);
	glVertex2f(850, 125);
	glColor3ub(0, 22, 52);
	glVertex2f(850, 650);
	glColor3ub(2, 36, 80);
	glVertex2f(550, 650);
	glEnd();

	// Front Facing Building Mesh
	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);

	// Vertical Lines - 4
	glVertex2f(550, 650);
	glVertex2f(550, 125);

	glVertex2f(625, 650);
	glVertex2f(625, 125);

	glVertex2f(700, 650);
	glVertex2f(700, 125);

	glVertex2f(775, 650);
	glVertex2f(775, 125);

	glVertex2f(850, 650);
	glVertex2f(850, 125);

	// Horizontal Lines - 10
	glVertex2f(550, 125);
	glVertex2f(850, 125);

	glVertex2f(550, 177.5);
	glVertex2f(850, 177.5);

	glVertex2f(550, 230);
	glVertex2f(850, 230);

	glVertex2f(550, 282.5);
	glVertex2f(850, 282.5);

	glVertex2f(550, 335);
	glVertex2f(850, 335);

	glVertex2f(550, 387.5);
	glVertex2f(850, 387.5);

	glVertex2f(550, 440);
	glVertex2f(850, 440);

	glVertex2f(550, 492.5);
	glVertex2f(850, 492.5);

	glVertex2f(550, 545);
	glVertex2f(850, 545);

	glVertex2f(550, 598);
	glVertex2f(850, 598);

	glVertex2f(550, 650);
	glVertex2f(850, 650);
	glEnd();

	// Door
	glBegin(GL_POLYGON);
	glColor3ub(23, 99, 152);
	glVertex2f(626, 125);
	glColor3ub(11, 57, 110);
	glVertex2f(774, 125);
	glColor3ub(8, 49, 92);
	glVertex2f(774, 282);
	glColor3ub(21, 99, 144);
	glVertex2f(626, 282);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);
	glVertex2f(700, 282);
	glVertex2f(700, 125);
	glEnd();

	drawCircle(690, 206, 240, 240, 240, 1, 1, 3);
	drawCircle(690, 202, 240, 240, 240, 1, 1, 3);
	drawCircle(690, 198, 240, 240, 240, 1, 1, 3);

	drawCircle(710, 206, 240, 240, 240, 1, 1, 3);
	drawCircle(710, 202, 240, 240, 240, 1, 1, 3);
	drawCircle(710, 198, 240, 240, 240, 1, 1, 3);

*/


	////////////////////////////////////
	/* ROCKET DESIGNING*/

	glColor3f(0.73,0.12 ,0.12);
	glBegin(GL_POLYGON);//core
		glVertex2f(237.5,20.0);
		glVertex2f(262.5,20.0);
		glVertex2f(262.5,120.0);
		glVertex2f(237.5,120.0);
	glEnd();

	//BONNET
	glColor3f(0.8,0.12 ,0.12);//bonnet
	glBegin(GL_POLYGON);//front

	glVertex2f(237.5,120.0); //LEFT POINTS
	glVertex2f(240.0,140.0);
	glVertex2f(245.0,170.0);
	glVertex2f(248.0, 188.0);
    glVertex2f(249.0, 189.0);

	glVertex2f(250,190.0);  //TOP POINT

    glVertex2f(251.0, 189.0);
    glVertex2f(252.0, 188.0);
    glVertex2f(255.0,170.0);
	glVertex2f(260.0,140.0);
	glVertex2f(262.5,120.0);  //RIGHT POINTS



	glEnd();

	glColor3f(1.0,0.0,0.0);

	/*  //LEFT TOP
	glBegin(GL_POLYGON);//left_side_top
	glVertex2f(237.5,120.0);
	glVertex2f(217.5,95.0);
	glVertex2f(237.5,95.0);
	glEnd();*/

	//LEFT BOTTOM
		glBegin(GL_POLYGON);//left_side_bottom
	glVertex2f(237.5,20.0);
	glVertex2f(227.5,20.0);
	glVertex2f(237.5,70.0);
	glEnd();


	//RIGHT BOTTOM
		glBegin(GL_POLYGON);//right_side_bottom
	glVertex2f(262.5,20.0);
	glVertex2f(272.5,20.0);
	glVertex2f(262.5,70.0);
	glEnd();

	/*
	//RIGHT TOP
		glBegin(GL_POLYGON);//right_side_top
	glVertex2f(262.5,120.0);
	glVertex2f(262.5,95.0);
	glVertex2f(282.5,95.0);
	glEnd();
	*/


	glColor3f(0.556863 ,0.137255  ,0.419608);
		glBegin(GL_POLYGON);//bottom_1_exhaust
	glVertex2f(237.5,20.0);
	glVertex2f(244.5,20.0);
	glVertex2f(241,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_2_exhaust
	glVertex2f(246.5,20.0);
	glVertex2f(253.5,20.0);
	glVertex2f(249.5,0.0);
	glEnd();
		glBegin(GL_POLYGON);//bottom_3_exhaust
	glVertex2f(262.5,20.0);
	glVertex2f(255.5,20.0);
	glVertex2f(258.5,0.0);
	glEnd();

	glBegin(GL_POLYGON);//left_stand_holder
	glVertex2f(182.5,85.0);
	glVertex2f(182.5,0.0);
	glVertex2f(187.5,0.0);
	glVertex2f(187.5,80.0);
	glVertex2f(237.5,80.0);
	glVertex2f(237.5,85.0);
	glVertex2f(182.5,85.0);
	glEnd();
	glBegin(GL_POLYGON);
glVertex2f(312.5,85.0);//right_stand_holder
	glVertex2f(312.5,0.0);
	glVertex2f(307.5,0.0);
	glVertex2f(307.5,80.0);
	glVertex2f(262.5,80.0);
	glVertex2f(262.5,85.0);
	glVertex2f(312.5,85.0);
	glEnd();

	for(j=0;j<=1000000;j++)
		;
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}

}
void rocket_to_cam_pos()
{
	    count++;
    count3++;

  for(i=0;i<=200;i++)
  {
         Sleep(2);





     /*    //THE BUILDING

	// Front Facing Building
	glBegin(GL_POLYGON);
	glColor3ub(30, 120, 182);
	glVertex2f(550, 125);
	glColor3ub(4, 36, 86);
	glVertex2f(850, 125);
	glColor3ub(0, 22, 52);
	glVertex2f(850, 650);
	glColor3ub(2, 36, 80);
	glVertex2f(550, 650);
	glEnd();

	// Front Facing Building Mesh
	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);

	// Vertical Lines - 4
	glVertex2f(550, 650);
	glVertex2f(550, 125);

	glVertex2f(625, 650);
	glVertex2f(625, 125);

	glVertex2f(700, 650);
	glVertex2f(700, 125);

	glVertex2f(775, 650);
	glVertex2f(775, 125);

	glVertex2f(850, 650);
	glVertex2f(850, 125);

	// Horizontal Lines - 10
	glVertex2f(550, 125);
	glVertex2f(850, 125);

	glVertex2f(550, 177.5);
	glVertex2f(850, 177.5);

	glVertex2f(550, 230);
	glVertex2f(850, 230);

	glVertex2f(550, 282.5);
	glVertex2f(850, 282.5);

	glVertex2f(550, 335);
	glVertex2f(850, 335);

	glVertex2f(550, 387.5);
	glVertex2f(850, 387.5);

	glVertex2f(550, 440);
	glVertex2f(850, 440);

	glVertex2f(550, 492.5);
	glVertex2f(850, 492.5);

	glVertex2f(550, 545);
	glVertex2f(850, 545);

	glVertex2f(550, 598);
	glVertex2f(850, 598);

	glVertex2f(550, 650);
	glVertex2f(850, 650);
	glEnd();

	// Door
	glBegin(GL_POLYGON);
	glColor3ub(23, 99, 152);
	glVertex2f(626, 125);
	glColor3ub(11, 57, 110);
	glVertex2f(774, 125);
	glColor3ub(8, 49, 92);
	glVertex2f(774, 282);
	glColor3ub(21, 99, 144);
	glVertex2f(626, 282);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(0, 30, 60);
	glVertex2f(700, 282);
	glVertex2f(700, 125);
	glEnd();

	drawCircle(690, 206, 240, 240, 240, 1, 1, 3);
	drawCircle(690, 202, 240, 240, 240, 1, 1, 3);
    drawCircle(690, 198, 240, 240, 240, 1, 1, 3);

	drawCircle(710, 206, 240, 240, 240, 1, 1, 3);
	drawCircle(710, 202, 240, 240, 240, 1, 1, 3);
	drawCircle(710, 198, 240, 240, 240, 1, 1, 3);


    */


	  glClearColor(0.196078  ,0.6 ,0.8,1.0);
	  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	  glColor3f(0.73,0.12 ,0.12);
	  glBegin(GL_POLYGON);//core
	  	  glVertex2f(237.5,20.0+i);
		  glVertex2f(262.5,20.0+i);
		  glVertex2f(262.5,120.0+i);
		  glVertex2f(237.5,120.0+i);


	  glEnd();

      glColor3f(0.8,0.12 ,0.12);//bonnet
	  glBegin(GL_POLYGON);//front
	  glVertex2f(237.5, 120.0+i);
	  glVertex2f(240.0, 140.0+i);
	  glVertex2f(245.0, 170.0+i);
	  glVertex2f(248.0, 188.0+i);
	  glVertex2f(249.0, 189.0+i);

	  glVertex2f(250.0, 190.0+i);

	  glVertex2f(251.0, 189.0+i);
	  glVertex2f(252.0, 188.0+i);
      glVertex2f(255.0, 170.0+i);
	  glVertex2f(260.0, 140.0+i);
	  glVertex2f(262.5, 120.0+i);

      glEnd();


	  glColor3f(1.0,0.0,0.0);

	  /* //LEFT TOP
	  glBegin(GL_POLYGON);//left_side_top
	  glVertex2f(237.5,120.0+i);
	  glVertex2f(217.5,95.0+i);
	  glVertex2f(237.5,95.0+i);
	  glEnd();
	  */

	  //LEFT BOTTOM
		glBegin(GL_POLYGON);//left_side_bottom
	  glVertex2f(237.5,20.0+i);
	  glVertex2f(227.5,20.0+i);
	  glVertex2f(237.5,70.0+i);
	  glEnd();


	//RIGHT BOTTOM
		glBegin(GL_POLYGON);//right_side_bottom
	  glVertex2f(262.5,20.0+i);
	  glVertex2f(272.5,20.0+i);
	  glVertex2f(262.5,70.0+i);
	  glEnd();

	/*
	//RIGHT TOP
		glBegin(GL_POLYGON);//right_side_top
	  glVertex2f(262.5,120.0+i);
	  glVertex2f(262.5,95.0+i);
	  glVertex2f(282.5,95.0+i);
	  glEnd();*/


	  glColor3f(0.556863 ,0.137255  ,0.419608);


		glBegin(GL_POLYGON);//bottom_1_exhaust
	  glVertex2f(237.5, 20.0+i);
	  glVertex2f(244.5, 20.0+i);
	  glVertex2f(241.0, 15.0+i);
	  glEnd();


		glBegin(GL_POLYGON);//bottom_2_exhaust
	   glVertex2f(246.5, 20.0+i);
	   glVertex2f(253.5, 20.0+i);
	   glVertex2f(249.5, 15.0+i);
	  glEnd();


		glBegin(GL_POLYGON);//bottom_3_exhaust
	  glVertex2f(262.5, 20.0+i);
	  glVertex2f(255.5, 20.0+i);
	  glVertex2f(258.5, 15.0+i);
	  glEnd();


	 //OUTER FUME DESIGN
	  if((p%4)==0)
         {glColor3f(1.0,0.25,0.0);
         }

        else
          {glColor3f(1.0,0.816,0.0);
          }

				 glBegin(GL_POLYGON);//outer fume

		glVertex2f(237.5,20+i);
		glVertex2f(234.16,16.66+i);
		glVertex2f(230.82,13.32+i);
		glVertex2f(227.48,9.98+i);
		glVertex2f(224.14,6.64+i);
		glVertex2f(220.8,3.3+i);
		glVertex2f(217.5,0+i);
		glVertex2f(221.56,-5+i);
		glVertex2f(225.62,-10+i);
		glVertex2f(229.68,-15+i);
		glVertex2f(233.74,-20+i);
		glVertex2f(237.8,-25+i);
		glVertex2f(241.86,-30+i);
		glVertex2f(245.92,-35+i);
		glVertex2f(250,-40+i);
		glVertex2f(254.06,-35+i);
		glVertex2f(258.12,-30+i);
		glVertex2f(262.18,-25+i);
		glVertex2f(266.24,-20+i);
		glVertex2f(270.3,-15+i);
		glVertex2f(274.36,-10+i);
		glVertex2f(278.42,-5+i);
		glVertex2f(282.5,0+i);
		glVertex2f(278.5,4+i);
		glVertex2f(274.5,8+i);
		glVertex2f(270.5,12+i);
		glVertex2f(266.5,16+i);
		glVertex2f(262.5,20+i);//28 points

		  glEnd();


		  //MIDDLE FUME
		  if( ((p%4)==1) || ((p%4)==3)  )
         {glColor3f(1.0,0.25,0.0);
         }

        else
          {glColor3f(1.0,0.816,0.0);
          }


        glVertex2f(237.5, 16+i);
		glVertex2f(230.16, 14.66+i);
		glVertex2f(226.82, 9.32+i);
		glVertex2f(223.48, 5.98+i);
		glVertex2f(220.14, 2.64+i);
		glVertex2f(216.8, -1.3+i);
		glVertex2f(213.5, -4+i);
		glVertex2f(217.56, -9+i);
		glVertex2f(221.62, -14+i);
		glVertex2f(225.68, -19+i);
		glVertex2f(229.74, -24+i);
		glVertex2f(233.8, -29+i);
		glVertex2f(237.86, -34+i);
		glVertex2f(241.92, -39+i);
		glVertex2f(246.0, -44+i);
		glVertex2f(250.06, -39+i);
		glVertex2f(254.12, -34+i);
		glVertex2f(258.18, -29+i);
		glVertex2f(262.24, -24+i);
		glVertex2f(266.3, -19+i);
		glVertex2f(270.36, -14+i);
		glVertex2f(274.42, -9+i);
		glVertex2f(278.5, -4+i);
		glVertex2f(274.5, 0+i);
		glVertex2f(270.5, 4+i);
		glVertex2f(266.5, 9+i);
		glVertex2f(263.5, 15+i);
		glVertex2f(262.5, 20+i);//28 points


		  //INNER FUME DESIGN
				 	if((p%4)==2)
				 {glColor3f(1.0,0.25,0.0);}
				 else
					{
                    glColor3f(1.0,0.816,0.0);
					}


		  glBegin(GL_POLYGON);//inner fume
		  glVertex2f(237.5,20+i);
		  glVertex2f(236.5,17.5+i);
		  glVertex2f(235.5,15+i);
		  glVertex2f(234.5,12.5+i);
		  glVertex2f(233.5,10+i);
		  glVertex2f(232.5,7.5+i);
		  glVertex2f(236,5+i);
		  glVertex2f(239.5,2.5+i);
		  glVertex2f(243,0+i);
		  glVertex2f(246.5,-2.5+i);
		  glVertex2f(250,-5+i);
		  glVertex2f(253.5,-2.5+i);
		  glVertex2f(257,0+i);
		  glVertex2f(260.5,2.5+i);
		  glVertex2f(264,5+i);
		  glVertex2f(267.5,7.5+i);
		  glVertex2f(266.5,10+i);
		  glVertex2f(265.5,12.5+i);
		  glVertex2f(264.5,15+i);
		  glVertex2f(263.5,17.5+i);
		  glVertex2f(262.5,20+i);//21 points

		  glEnd();
		  p=p+1;
	  for(j=0;j<=1000000;j++)
		  ;
	  glutSwapBuffers();
	  glutPostRedisplay();
	  glFlush();
   }
}



//ROCKET MOTION TRAJECTORY
void rocket_in_motion()
{
	count++;


for(i=195;i<=200;i++)
{
     Sleep(2);

    if( count<170)
    {


       if(count>=5)
	   {
		 	glClearColor(0.0 ,0.0 ,0.0,1.0);
	        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	       if(flag1==0)
	         {
	           stars();
	           flag1=1;
	         }
	       else
	        {
		       stars1();

		       flag1=0;
	         }

	    }

	    else
	    {
	      glClearColor(0.196078  ,0.6 ,0.8,1.0);
	      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	    }

	    if(count>=90)
	    { moon(100.0);
	    }


	    if(count>50)
        {   //displaying the satellite

            satellite();
        }

	glColor3f(0.73,0.12 ,0.12);


	glBegin(GL_POLYGON);//core
		glVertex2f(237.5,20.0+i);
		glVertex2f(262.5,20.0+i);
		glVertex2f(262.5,120.0+i);
		glVertex2f(237.5,120.0+i);
	glEnd();






	//Top part of rocket
	glColor3f(0.8,0.12 ,0.12);//bonnet
	glBegin(GL_POLYGON);//front
	glVertex2f(237.5,120.0+i); //LEFT POINTS
	glVertex2f(240.0,140.0+i);
	glVertex2f(245.0,170.0+i);
	glVertex2f(248.0, 188.0+i);
    glVertex2f(249.0, 189.0+i);

	glVertex2f(250,190.0+i); //TOP POINT

    glVertex2f(251.0, 189.0+i);
    glVertex2f(252.0, 188.0+i);
    glVertex2f(255.0,170.0+i);
	glVertex2f(260.0,140.0+i);
	glVertex2f(262.5,120.0+i); //RIGHT POINTS



	glEnd();
	//}


	     glColor3f(1.0,0.0,0.0);

	     /* //LEFT TOP
	     glBegin(GL_POLYGON);//left_side_top
	     glVertex2f(237.5,120.0+i);
	     glVertex2f(217.5,95.0+i);
	     glVertex2f(237.5,95.0+i);
	    glEnd();
	    */
	   //LEFT BOTTOM
		glBegin(GL_POLYGON);//left_side_bottom
        glVertex2f(237.5,20.0+i);
        glVertex2f(227.5,20.0+i);
	    glVertex2f(237.5,70.0+i);
	     glEnd();

	    //RIGHT BOTTOM
		glBegin(GL_POLYGON);//right_side_bottom
	     glVertex2f(262.5,20.0+i);
	     glVertex2f(272.5,20.0+i);
	     glVertex2f(262.5,70.0+i);
	     glEnd();

	     /* //RIGHT TOP
         glBegin(GL_POLYGON);//right_side_top
	     glVertex2f(262.5,120.0+i);
	     glVertex2f(262.5,95.0+i);
	     glVertex2f(282.5,95.0+i);
	     glEnd();
	    */





	      glColor3f(0.556863 ,0.137255  ,0.419608);
		  glBegin(GL_POLYGON);//bottom_1_exhaust
	      glVertex2f(237.5,20.0+i);
	      glVertex2f(244.5,20.0+i);
	      glVertex2f(241,15.0+i);
	      glEnd();

          glBegin(GL_POLYGON);//bottom_2_exhaust
	      glVertex2f(246.5,20.0+i);
	      glVertex2f(253.5,20.0+i);
	      glVertex2f(249.5,15.0+i);
	      glEnd();

		  glBegin(GL_POLYGON);//bottom_3_exhaust
	      glVertex2f(262.5,20.0+i);
	      glVertex2f(255.5,20.0+i);
	      glVertex2f(258.5,15.0+i);
	      glEnd();


    }

    if (count==170)
    {
        printf("The value:%f",i);
    }

   //if count>150
    else if (count>170)
   {
       Sleep(2);


       if(flag1==0)
	         {
	           stars();
	           flag1=1;
	         }
	       else
	        {
		       stars1();

		       flag1=0;
	         }

        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
	     /*static int k = i;
	     glColor3f(1.0,1.0,1.0);//satellite
	     glBegin(GL_POLYGON);//core
		glVertex2f(237.5,150.0+k);
		glVertex2f(252.5,150.0+k);
		glVertex2f(252.5,120.0+k);
		glVertex2f(237.5,120.0+k);
	    glEnd();

	    glBegin(GL_POLYGON);//side-panels
		glVertex2f(237.5,140.0+k);
		glVertex2f(230,140.0+k);
		glVertex2f(230,130.0+k);
		glVertex2f(237.5,130.0+k);

		glVertex2f(262.5,140.0+k);
		glVertex2f(227.5,140.0+k);
		glVertex2f(227.5,130.0+k);
		glVertex2f(262.5,130.0+k);
	glEnd();*/


	//MOON LANDING REPRESENTATION

	glColor3f(0.87,0.96,0.95);

	glBegin(GL_POLYGON); //MOON SURFACE

	glVertex2f(0.0 , 100.0);

	glVertex2f(60.0, 110.0);
	glVertex2f(80.0, 105.0);
	glVertex2f(140.0, 98.0);
	glVertex2f(156.0, 108.0);
	glVertex2f(183.0, 103.0);
	glVertex2f(208.0, 111.0);
	glVertex2f(222.0, 104.0);
	glVertex2f(295.0, 98.0);
	glVertex2f(346.0, 106.0);
	glVertex2f(428.0, 111.0);
	glVertex2f(464.0, 101.0);
	glVertex2f(527.0, 106.0);
	glVertex2f(601.0, 110.0);
	glVertex2f(662.0, 96.0);
	glVertex2f(803.0, 110.0);
	glVertex2f(879.0, 104.0);

	glVertex2f(1000.0 , 100.0);
	glVertex2f(1000.0 , 0.0);
	glVertex2f(0.0 , 0.0);
	glEnd();

	//ROCKET LANDING

        glColor3f(0.73,0.12 ,0.12);


	   glBegin(GL_POLYGON);//core
		glVertex2f(237.5,80.0);
		glVertex2f(262.5,80.0);
		glVertex2f(262.5,180.0);
		glVertex2f(237.5,180.0);
	   glEnd();


      //Top part of rocket
	    glColor3f(0.8,0.12 ,0.12);//bonnet
	     glBegin(GL_POLYGON);//front
	   glVertex2f(237.5, 180.0); //LEFT POINTS
	   glVertex2f(240.0, 200.0);
	   glVertex2f(245.0, 230.0);
	   glVertex2f(248.0, 248.0);
       glVertex2f(249.0, 249.0);

	   glVertex2f(250,250.0); //TOP POINT

       glVertex2f(251.0, 249.0);
       glVertex2f(252.0, 248.0);
       glVertex2f(255.0, 230.0);
	   glVertex2f(260.0, 200.0);
	   glVertex2f(262.5, 180.0); //RIGHT POINTS



	   glEnd();
	   //}


	     glColor3f(1.0,0.0,0.0);

	     /* //LEFT TOP
	     glBegin(GL_POLYGON);//left_side_top
	     glVertex2f(237.5,120.0+i);
	     glVertex2f(217.5,95.0+i);
	     glVertex2f(237.5,95.0+i);
	    glEnd();
	    */
	   //LEFT BOTTOM
		glBegin(GL_POLYGON);//left_side_bottom
        glVertex2f(237.5, 80.0);
        glVertex2f(227.5, 80.0);
	    glVertex2f(237.5, 130.0);
	     glEnd();

	    //RIGHT BOTTOM
		glBegin(GL_POLYGON);//right_side_bottom
	     glVertex2f(262.5, 80.0);
	     glVertex2f(272.5, 80.0);
	     glVertex2f(262.5, 130.0);
	     glEnd();

	     /* //RIGHT TOP
         glBegin(GL_POLYGON);//right_side_top
	     glVertex2f(262.5,120.0+i);
	     glVertex2f(262.5,95.0+i);
	     glVertex2f(282.5,95.0+i);
	     glEnd();
	    */





	      glColor3f(0.556863 ,0.137255  ,0.419608);
		  glBegin(GL_POLYGON);//bottom_1_exhaust
	      glVertex2f(237.5, 80.0);
	      glVertex2f(244.5, 80.0);
	      glVertex2f(241.5, 75.0);
	      glEnd();

          glBegin(GL_POLYGON);//bottom_2_exhaust
	      glVertex2f(246.5, 80.0);
	      glVertex2f(253.5, 80.0);
	      glVertex2f(249.5, 75.0);
	      glEnd();

		  glBegin(GL_POLYGON);//bottom_3_exhaust
	      glVertex2f(262.5, 80.0);
	      glVertex2f(255.5, 80.0);
	      glVertex2f(258.5, 75.0);
	      glEnd();

	      //rocket door

	      glColor3f(0.1264 ,0.1314  ,0.1215);
	      glBegin(GL_POLYGON);
	      glVertex2f(240.0,80.0);
		  glVertex2f(247.5,80.0);
		  glVertex2f(247.5,140.0);
		  glVertex2f(240.0,140.0);
	      glEnd();



	      if (count<=198)
	      {manwalking(i);
	      }


	      if(count>198)
          {
              usflag();


              //man stationary representation

        glColor3f(0.9443 ,0.8816 ,0.8499);

        glBegin(GL_POLYGON);       //left leg
        glVertex2f(250.0-x , 80.0);
	    glVertex2f(255.0-x , 80.0);
	    glVertex2f(255.0-x , 95.0);
	    glVertex2f(250.0-x , 95.0);
	    glEnd();

	    glBegin(GL_POLYGON);      //right leg
	    glVertex2f(257.0-x , 80.0);
	    glVertex2f(263.0-x , 80.0);
	    glVertex2f(263.0-x , 95.0);
	    glVertex2f(257.0-x , 95.0);
	    glEnd();

	    glBegin(GL_POLYGON);          //body
	    glVertex2f(250.0-x , 95.0);
	    glVertex2f(263.0-x , 95.0);
	    glVertex2f(263.0-x , 130.0);
	    glVertex2f(250.0-x , 130.0);
	    glEnd();

	    glColor3f(0.1443 ,0.1416 ,0.9999);

	     glBegin(GL_POLYGON);           //head helmet
	    glVertex2f(252.0-x , 130.0);
	    glVertex2f(251.0-x , 135.0);
	    glVertex2f(250.0-x , 139.0);
	    glVertex2f(251.0-x , 143.0);
	    glVertex2f(252.0-x , 147.0);

	    glVertex2f(255.0-x , 148.0);
	    glVertex2f(257.0-x , 150.0);
	    glVertex2f(259.0-x , 148.0);
	    glVertex2f(261.0-x , 147.0);

	    glVertex2f(262.0-x , 143.0);
	    glVertex2f(263.0-x , 139.0);
	    glVertex2f(262.0-x , 135.0);


	    glVertex2f(261.0-x , 130.0);
	  /*  glVertex2f(252.0-x , 140.0);

	    glVertex2f(261.0-x , 144.0);
	    glVertex2f(262.0-x , 142.0);

	    glVertex2f(261.0-x , 136.0);
        glVertex2f(261.0-x , 130.0);*/
	    glEnd();


          }//if


	}



	for(j=0;j<=1000000;j++)
		;
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
 }
}//functiom


void satellite()
{   h++;

       glColor3f(0.4000 ,0.6000 ,1.0000);
    	glBegin(GL_POLYGON);
    glVertex2f(-120.0+h , 300.0);   //LEFT SATELLITE PANEL
    glVertex2f(-90.0+h , 340.0);
    glVertex2f(-90.0+h , 280.0);
    glVertex2f(-120.0+h , 240.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-30.0+h , 300.0);   //RIGHT SATELLITE PANEL
    glVertex2f(  0.0+h , 340.0);
    glVertex2f(  0.0+h , 280.0);
    glVertex2f(-30.0+h , 240.0);
    glEnd();


  glColor3f(0.0846 ,0.0758 , 0.0821);
    glBegin(GL_POLYGON);
    glVertex2f(-90.0+h , 290.0);   //CONNECTOR
    glVertex2f(-30.0+h , 290.0);
    glVertex2f(-30.0+h , 285.0);
    glVertex2f(-90.0+h , 285.0);
    glEnd();

    glColor3f(0.5642,0.4821,0.5836);

    glBegin(GL_POLYGON);
    glVertex2f(-80.0+h , 300.0);   //MAIN PAYLOAD
    glVertex2f(-80.0+h , 260.0);
    glVertex2f(-83.0+h , 263.0);
    glVertex2f(-87.0+h , 265.0);
    glVertex2f(-47.0+h , 265.0);
    glVertex2f(-43.0+h , 263.0);
    glVertex2f(-40.0+h , 260.0);
    glVertex2f(-40.0+h , 300.0);
    glEnd();




}



void usflag()
{

    //RED BANDS OF THE FLAG
    glColor3f(1.0000 ,0.0000 ,0.0199);

    glBegin(GL_POLYGON);
    glVertex2f(110.0 ,134.0);   //FIRST BAND
    glVertex2f(124.0 ,134.0);
    glVertex2f(124.0 ,132.0);
    glVertex2f(110.0 ,132.0);
    glEnd();

    glBegin(GL_POLYGON);        //2ND
    glVertex2f(110.0 ,130.0);
    glVertex2f(124.0 ,130.0);
    glVertex2f(124.0 ,128.0);
    glVertex2f(110.0 ,128.0);
    glEnd();

    glBegin(GL_POLYGON);        //3RD
    glVertex2f(110.0 ,126.0);
    glVertex2f(124.0 ,126.0);
    glVertex2f(124.0 ,124.0);
    glVertex2f(110.0 ,124.0);
    glEnd();

    //
    glBegin(GL_POLYGON);        //4TH
    glVertex2f(100.0 ,122.0);
    glVertex2f(124.0 ,122.0);
    glVertex2f(124.0 ,120.0);
    glVertex2f(100.0 ,120.0);
    glEnd();

    glBegin(GL_POLYGON);         //5TH
    glVertex2f(100.0 ,118.0);
    glVertex2f(124.0 ,118.0);
    glVertex2f(124.0 ,116.0);
    glVertex2f(100.0 ,116.0);
    glEnd();

     glBegin(GL_POLYGON);      //6TH
    glVertex2f(100.0 ,114.0);
    glVertex2f(124.0 ,114.0);
    glVertex2f(124.0 ,112.0);
    glVertex2f(100.0 ,112.0);
    glEnd();


    //WHITE BANDS OF THE FLAG
    glColor3f(1.0000 ,1.0000 ,1.0000);

    glBegin(GL_POLYGON);      //1ST
    glVertex2f(110.0 ,132.0);
    glVertex2f(124.0 ,132.0);
    glVertex2f(124.0 ,130.0);
    glVertex2f(110.0 ,130.0);
    glEnd();

    glBegin(GL_POLYGON);      //2ND
    glVertex2f(110.0 ,128.0);
    glVertex2f(124.0 ,128.0);
    glVertex2f(124.0 ,126.0);
    glVertex2f(110.0 ,126.0);
    glEnd();

    glBegin(GL_POLYGON);       //3RD
    glVertex2f(110.0 ,124.0);
    glVertex2f(124.0 ,124.0);
    glVertex2f(124.0 ,122.0);
    glVertex2f(110.0 ,122.0);
    glEnd();

    //
    glBegin(GL_POLYGON);       //4TH
    glVertex2f(100.0 ,120.0);
    glVertex2f(124.0 ,120.0);
    glVertex2f(124.0 ,118.0);
    glVertex2f(100.0 ,118.0);
    glEnd();

    glBegin(GL_POLYGON);       //5TH
    glVertex2f(100.0 ,116.0);
    glVertex2f(124.0 ,116.0);
    glVertex2f(124.0 ,114.0);
    glVertex2f(100.0 ,114.0);
    glEnd();

     glBegin(GL_POLYGON);       //6TH
    glVertex2f(100.0 ,112.0);
    glVertex2f(124.0 ,112.0);
    glVertex2f(124.0 ,110.0);
    glVertex2f(100.0 ,110.0);
    glEnd();

    //BLUE STAR PART OF THE FLAG
    glColor3f(0.0166 ,0.0166 ,1.0000);

    glBegin(GL_POLYGON);      //BLUE PART
    glVertex2f(100.0 ,134.0);
    glVertex2f(110.0 ,134.0);
    glVertex2f(110.0 ,122.0);
    glVertex2f(100.0 ,122.0);
    glEnd();

    //STARS
    glColor3f(1.0000 ,1.0000 ,1.0000);

    glBegin(GL_POINTS);
    glVertex2f(103.0 ,131.0);
    glVertex2f(105.0 ,131.0);
    glVertex2f(107.0 ,131.0);

    glVertex2f(102.0 ,127.0);
    glVertex2f(104.0 ,127.0);
    glVertex2f(106.0 ,127.0);
    glVertex2f(108.0 ,127.0);

    glVertex2f(103.0 ,124.0);
    glVertex2f(105.0 ,124.0);
    glVertex2f(107.0 ,124.0);
    glEnd();

    //FLAGPOLE
    glColor3f(0.4000 ,0.6000 ,1.0000);

    glBegin(GL_POLYGON);       //6TH
    glVertex2f(99.0 , 134.0);
    glVertex2f(100.0 , 134.0);
    glVertex2f(100.0 , 80.0);
    glVertex2f(99.0 , 80.0);
    glEnd();




}

void manwalking(float i)
{
    Sleep(2);
     x++;

     glColor3f(0.8443 ,0.8816 ,0.8499);

        glBegin(GL_POLYGON);       //left leg
        glVertex2f(250.0-x , 80.0);
	    glVertex2f(255.0-x , 80.0);
	    glVertex2f(255.0-x , 95.0);
	    glVertex2f(250.0-x , 95.0);
	    glEnd();

	    if(x%2==0)
      {


	    glBegin(GL_POLYGON);      //right leg
	    glVertex2f(257.0-x , 80.0);
	    glVertex2f(263.0-x , 80.0);
	    glVertex2f(263.0-x , 95.0);
	    glVertex2f(257.0-x , 95.0);
	    glEnd();
      }

        else
        {
           glBegin(GL_POLYGON);      //right leg
	    glVertex2f(248.0-x , 80.0);
	    glVertex2f(254.0-x , 80.0);
	    glVertex2f(254.0-x , 95.0);
	    glVertex2f(248.0-x , 95.0);
	    glEnd();
        }



	    glBegin(GL_POLYGON);          //body
	    glVertex2f(250.0-x , 95.0);
	    glVertex2f(263.0-x , 95.0);
	    glVertex2f(263.0-x , 130.0);
	    glVertex2f(250.0-x , 130.0);
	    glEnd();

	    glColor3f(0.1443 ,0.1416 ,0.9999);

	     glBegin(GL_POLYGON);           //head helmet
	    glVertex2f(252.0-x , 130.0);
	    glVertex2f(251.0-x , 135.0);
	    glVertex2f(250.0-x , 139.0);
	    glVertex2f(251.0-x , 143.0);
	    glVertex2f(252.0-x , 147.0);

	    glVertex2f(255.0-x , 148.0);
	    glVertex2f(257.0-x , 150.0);
	    glVertex2f(259.0-x , 148.0);
	    glVertex2f(261.0-x , 147.0);

	    glVertex2f(262.0-x , 143.0);
	    glVertex2f(263.0-x , 139.0);
	    glVertex2f(262.0-x , 135.0);


	    glVertex2f(261.0-x , 130.0);

	  /*  glVertex2f(252.0-x , 140.0);

	    glVertex2f(261.0-x , 144.0);
	    glVertex2f(262.0-x , 142.0);

	    glVertex2f(261.0-x , 136.0);
        glVertex2f(261.0-x , 130.0);*/

	    glEnd();

	    glColor3f(0.4556,0.4265,0.4326);
	    glBegin(GL_POLYGON);
	    glVertex2f(263.0-x , 150.0);
	    glVertex2f(263.0-x , 95.0 );
        glVertex2f(268.0-x , 95.0);
	    glVertex2f(268.0-x , 150.0 );
       glEnd();



}


void drawCircle(GLfloat x, GLfloat y,
	GLfloat r, GLfloat g, GLfloat b,
	GLfloat sx, GLfloat sy,
	GLfloat radius) {
		glPushMatrix();

		glTranslatef(x, y, 0);
		glScalef(sx, sy, 0);




    glBegin(GL_POLYGON);
		glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

		glPopMatrix();
}


void moon(float radius)
{


   glBegin(GL_POLYGON);

   for (int i=0; i<=359; i++)
   {
      float degInRad = i*DEG2RAD;
      glVertex2f(200+f+cos(degInRad)*radius,500-t+(sin(degInRad))*radius);
      //100,100 specifies centre of the circle
   }

   glEnd();
   t=t+0.1;
   f=f+0.1;
}

//keys that trigger manual Lanch
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'S' || key == 's'){
		for(int i=0;i<100;i++)
			static_rocket();
		flag = 1;

	}

	if (key == 'L' || key == 'l')
	{
		for(int i=0;i<100;i++)
			static_rocket();
	}

	if (key == 'Q' || key == 'q')
		exit(0);

}

//design of homescreen
void page()
{
	glColor3f(0.4, 0.2, 0.6);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex2d(75, 425);
	glVertex2d(375, 425);
	glVertex2d(375, 325);
	glVertex2d(75, 325);
	glEnd();

	drawstring(100, 400, "Lunar SpaceCraft Landing");
	drawstring(100, 380, "NAME : Creig Luke 4NM18CS042,     Bharath Kulkarni 4NM18CS036");
	drawstring(100, 340, "SEM : VI A");



	glBegin(GL_LINE_LOOP);
	glVertex2d(75, 75);
	glVertex2d(375, 75);
	glVertex2d(375, 225);
	glVertex2d(75, 225);
	glEnd();

	drawstring(100, 200, "KEYS");
	drawstring(100, 180, "Press S to START");
	drawstring(100, 160, "Press L to LAUNCH");
	drawstring(100, 100, "Press Q to Exit");



	drawstring(100,60, "One small step for man, one giant leap for mankind");

	glFlush();
}

//display all components
void display()
{
	if (flag == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		page();
		glutSwapBuffers();
	}
	else
		control();
	glFlush();
}


void myinit()
{
	//int i;
	glClearColor(0.196078  ,0.6 ,0.8,1.0);


	glPointSize(1.0);
	gluOrtho2D(0.0,499.0,0.0,499.0);
}


int main(int argc,char*argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1500,1500);
	glutCreateWindow("Lunar Launch");

	myinit();

	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(display);



   glutMainLoop();
   return 0;
}

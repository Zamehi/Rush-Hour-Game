/*
Name : Zunaira Amir
Rollno. : i210780
*/
#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <string>
#include <cmath>
//#include <sstring>
//#include <graphics.h>
using namespace std;
void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void MouseClicked(int button, int state, int x, int y);
//Global variables and arrays
int xI = 94, yI = 775;
int grid_x1[24]= {0/*0*/ ,42/*1*/, 84/*2*/,126/*3*/,168/*4*/, 210/*5*/, 252/*6*/, 294/*7*/, 336/*8*/, 378/*9*/, 420/*10*/, 462/*11*/, 504/*12*/, 546/*13*/, 588/*14*/, 630/*15*/, 672/*16*/, 714/*17*/, 756/*18*/, 798/*19*/, 840/*20*/, 882/*21*/,924/*22*/,966/*23*/};
int grid_y1[22]= {0, 38, 76, 114, 152, 190, 228, 266, 304, 342, 380, 418, 456,494,532,570,608,646,684,722,760,798};
int check1, check2, check3, check4, check5;//Variables to check axis of passenger and destination.
int x1 = 714, x2 = 734;                                             //Coordinates of enemy1
int x2_1 = 620, x2_2 = 640;                                         //Coordinates of enemy2
int x3_1 = grid_x1[2]+10, x3_2 = grid_x1[2]+30, y3_1 = grid_y1[12]; //Coordinates of enemy3
int x4_1 = grid_x1[15]+10, x4_2=grid_x1[15]+30 ,y4_1 =grid_y1[20];  //Coordinates of enemy4
int x5_1 = grid_x1[10]+10, x5_2=grid_x1[10]+30 ,y5_1 =grid_y1[14];  //Coordinates of enemy5
int destinationx1, destinationy1, destinationx2,destinationy2,destinationx3,destinationy3,destinationx4,destinationy4,destinationx5,destinationy5;//Coordinates of destination.
int passangers, score=0 , var;
int obs1_x, obs1_y, obs2_x,obs2_y, obs3_x, obs3_y,obs4_x, obs4_y;// Cordinates of obstacles
int p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y,p5x,p5y;//Cordinates of passengers.
bool flag = true, flag1=true, flag2=true, flag3=true, flag4 =true;  //Declaring bool variables to validate movement of enemy cars



void drawCar()
{
	DrawSquare(xI, yI, 20, colors[ORANGE]);
	glutPostRedisplay(); //call this function again to draw anything in the screen
}
void drawCar_red()
{
	DrawSquare(xI, yI, 20, colors[RED]);
	glutPostRedisplay(); //call this function again to draw anything in the screen
}
//drawing enemy car1
void drawCar1()
{
	int y1 = 380;
	DrawSquare(x1, y1, 20, colors[RED]);
	DrawCircle(x1, y1, 7, colors[BLACK]);
	DrawCircle(x2, y1, 7, colors[BLACK]);
	glutPostRedisplay();
}
//Drawing enemy car2
void drawCar2()
{
	int y2_1 = grid_y1[2];
	DrawSquare(x2_1, y2_1, 20, colors[BLUE]);
	DrawCircle(x2_1, y2_1, 7, colors[BLACK]);
	DrawCircle(x2_2, y2_1, 7, colors[BLACK]);
	glutPostRedisplay();
}
//Drawing enemy car3
void drawCar3()
{
	
	DrawSquare(x3_1, y3_1, 20, colors[GREEN_YELLOW]);
	DrawCircle(x3_1, y3_1, 7, colors[BLACK]);
	DrawCircle(x3_2, y3_1, 7, colors[BLACK]);
	glutPostRedisplay();
}
//Drawing enemy car4
void drawCar4()
{
	
	DrawSquare(x4_1, y4_1, 20, colors[BROWN]);
	DrawCircle(x4_1, y4_1, 7, colors[BLACK]);
	DrawCircle(x4_2, y4_1, 7, colors[BLACK]);
	glutPostRedisplay();
}
//Drawing  enemy car5
void drawCar5()
{
	DrawSquare(x5_1, y5_1, 20, colors[MAGENTA]);
	DrawCircle(x5_1, y5_1, 7, colors[BLACK]);
	DrawCircle(x5_2, y5_1, 7, colors[BLACK]);
	glutPostRedisplay();
}
//Drawing Passengers

void drawPassanger1()
{
	InitRandomizer();
	if(check1==0)
	{
	   DrawRectangle(p1x,p1y,21,38, colors[RED]);
	}
	else if(check1==1)
	{
		p1x=1000, p1y=1000;
		DrawRectangle(p1x,p1y,21,38, colors[RED]);
	}
	else if(check1==2)
	{
		p1x=xI, p1y=yI;
		DrawRectangle(p1x,p1y,21,38, colors[RED]);
	}
	glutPostRedisplay();
}
void drawPassanger2()
{
	InitRandomizer();
	if(check2==0)
	{
	   DrawRectangle(p2x,p2y,21,38, colors[GREEN]);
	}
	else if(check2==1)
	{
		p2x=1000, p2y=1000;
		DrawRectangle(p2x,p2y,21,38, colors[GREEN]);
	}
	else if(check2==2)
	{
		p2x=xI, p2y=yI;
		DrawRectangle(p2x,p2y,21,38, colors[GREEN]);
	}
	glutPostRedisplay();
}
void drawPassanger3()
{
	InitRandomizer();
	if(check3==0)
	{
	   DrawRectangle(p3x,p3y,21,38, colors[BLUE]);
	}
	else if(check3==1)
	{
		p3x=1000, p3y=1000;
		DrawRectangle(p3x,p3y,21,38, colors[BLUE]);
	}
	else if(check3==2)
	{
		p3x=xI, p3y=yI;
		DrawRectangle(p3x,p3y,21,38, colors[BLUE]);
	}
	glutPostRedisplay();
}
void drawPassanger4()
{
	InitRandomizer();
	if(check4==0)
	{
	   DrawRectangle(p4x,p4y,21,38, colors[DARK_VIOLET]);
	}
	else if(check4==1)
	{
		p4x=1000, p4y=1000;
		DrawRectangle(p4x,p4y,21,38, colors[DARK_VIOLET]);
	}
	else if(check4==2)
	{
		p4x=xI, p4y=yI;
		DrawRectangle(p4x,p4y,21,38, colors[DARK_VIOLET]);
	}
	glutPostRedisplay();
}
void drawPassanger5()
{
	InitRandomizer();
	if(check5==0)
	{
	   DrawRectangle(p5x,p5y,21,38, colors[YELLOW]);
	}
	else if(check5==1)
	{
		p5x=1000, p5y=1000;
		DrawRectangle(p5x,p5y,21,38, colors[YELLOW]);
	}
	else if(check5==2)
	{
		p5x=xI, p5y=yI;
		DrawRectangle(p5x,p5y,21,38, colors[YELLOW]);
	}
	glutPostRedisplay();
}
void drawPassanger()
{
	if (passangers==4)
		{
	       drawPassanger1();
		   drawPassanger3();
		   drawPassanger4();
		   drawPassanger5();
		}
		else if(passangers==2)
		{
			drawPassanger1();
			drawPassanger3();
		}
		else if(passangers==3)
		{
			drawPassanger3();
			drawPassanger2();
			drawPassanger4();
		}
		else 
		{
			drawPassanger3();
			drawPassanger2();
			drawPassanger1();
			drawPassanger4();
			drawPassanger5();
		}
}
//Drawing  Obstacles
void drawObstacles1()
{
	obs1_y = grid_y1[9];
	DrawCircle(obs1_x, obs1_y, 19, colors[DARK_ORANGE]);
}
void drawObstacles2()
{
	obs2_x = grid_x1[10]+2;
	DrawCircle(obs2_x, obs2_y, 19, colors[DARK_ORANGE]);
}
void drawObstacles3()
{
	obs3_x = grid_x1[13]+2;
	DrawCircle(obs3_x, obs3_y, 19, colors[DARK_ORANGE]);
}
void drawObstacles4()
{
	obs4_x=grid_x1[3]+2;
	DrawCircle(obs4_x, obs4_y, 19, colors[DARK_ORANGE]);
}

void moveCar()
{
	//For car1
	if (x1 > 672 && flag)
	{
		x1 -= 7;
		x2 -= 7;
		cout << "going left";
		if (x1 <700)
		{
			flag = false;
		}
	}
	else if (x1 < 882 &&!flag)
	{
		cout << "go right";
		x1 += 7;
		x2 += 7;
		if (x1 > 840)
			flag = true;
	}
	//for car2
	if (x2_1 > 546  && flag1)
	{
		x2_1 -= 7;
		x2_2 -= 7;
		cout << "going left";
		if (x2_1 < 546)
		{
			flag1 = false;
		}
	}
	else if (x2_1 < 756 &&!flag1)
	{
		cout << "go right";
		x2_1 += 7;
		x2_2 += 7;
		if (x2_1 > 716)
			flag1 = true;
	}
	//For car3
	if (y3_1 > grid_y1[6]  && flag2)
	{
		y3_1 -= 7;
		//y3_2 -= 7;
		cout << "going left";
		if (y3_1 < grid_y1[6])
		{
			flag2 = false;
		}
	}
	else if (y3_1 < grid_y1[17] &&!flag2)
	{
		cout << "go up";
		y3_1 += 7;
		//y3_2 += 7;
		if (y3_1 > grid_y1[17])
			flag2 = true;
	}
	//For Car4
		if (x4_1 > grid_x1[11]  && flag3)
	{
		x4_1 -= 7;
		x4_2 -= 7;
		cout << "going left";
		if (x4_1 < grid_x1[11])
		{
			flag3 = false;
		}
	}
	else if (x4_1 < grid_x1[20] &&!flag3)
	{
		cout << "go right";
		x4_1 += 7;
		x4_2 += 7;
		if (x4_1 > grid_x1[20])
			flag3 = true;
	}
	//For car5
	if (y5_1 > grid_y1[11]  && flag4)
	{
		y5_1 -= 7;
		cout << "going down";
		if (y5_1 < grid_y1[11])
		{
			flag4 = false;
		}
	}
	else if (y5_1 < grid_y1[17] &&!flag4)
	{
		cout << "go up";
		y5_1 += 7;
		//y3_2 += 7;
		if (y5_1 > grid_y1[17])
			flag4 = true;
	}
	glutPostRedisplay();

}
void drawdestination()
{
	if (passangers==2)
	{
	DrawSquare(destinationx1, destinationy1, 42, colors[RED]);
	DrawSquare(destinationx3, destinationy3, 42, colors[BLUE]);
	}
	else if(passangers==3)
	{
		DrawSquare(destinationx2, destinationy2, 42, colors[GREEN]);
		DrawSquare(destinationx3, destinationy3, 42, colors[BLUE]);
		DrawSquare(destinationx4, destinationy4, 42, colors[DARK_VIOLET]);
	}
	else if(passangers ==4)
	{
		DrawSquare(destinationx1, destinationy1, 42, colors[RED]);
		DrawSquare(destinationx3, destinationy3, 42, colors[BLUE]);
		DrawSquare(destinationx4, destinationy4, 42, colors[DARK_VIOLET]);
		DrawSquare(destinationx5, destinationy5, 42, colors[YELLOW]);
	}
		else
	{
		DrawSquare(destinationx1, destinationy1, 42, colors[RED]);
		DrawSquare(destinationx3, destinationy3, 42, colors[BLUE]);
		DrawSquare(destinationx4, destinationy4, 42, colors[DARK_VIOLET]);
		DrawSquare(destinationx5, destinationy5, 42, colors[YELLOW]);
		DrawSquare(destinationx2, destinationy2, 42, colors[GREEN]);
	}
}

/*
 * Main Canvas drawing function.
 * */
//int check;
bool var1=true;
void GameDisplay()
{
	passangers=0;
	//Declaring arrays
	int grid_y[24][22];
	int grid_x[24][22];
	for (int i = 1; i < 24; i++)
	{
		for (int j = 1; j < 22; j++)
		{
			grid_x[i][j] = 42 + (42 * (i - 1));
			grid_y[i][j] = 38 + (38 * (j - 1));
		}
	}
	
if(var1==true){
	   glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	   glLoadIdentity();
	   glFlush();
	   glClearColor(1.2, 0.5, 1.0,0);
	   
	   DrawRectangle(grid_x1[6], grid_y1[14],126,76, colors[ORANGE]);
	   DrawRectangle(grid_x1[6]+5, grid_y1[14]+5,116,66, colors[WHITE]);
	   DrawRectangle(grid_x1[15], grid_y1[14],126,76, colors[RED]);
	   DrawRectangle(grid_x1[15]+5, grid_y1[14]+5,116,66, colors[WHITE]);
	   string menu = "MENU";
       DrawString( grid_x1[11]+4, grid_y1[20]+8,menu, colors[GREEN]);
	   string select = "Select a color for your taxi";
       DrawString( grid_x1[9]+2, grid_y1[17]+8,select, colors[BLACK]);
	   string yellow = "Yellow";
	   DrawString( grid_x1[6]+30, grid_y1[14]+25, yellow,colors[BLACK]);
	   string red = "Red";
	   DrawString( grid_x1[15]+40, grid_y1[14]+25,red, colors[BLACK]);
	   string leaderboard = "LeaderBoard";
	   DrawString( grid_x1[10]+16, grid_y1[9],leaderboard, colors[BLACK]);
	   glutSwapBuffers();
}
else{
	if (var==0)

	{
        glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	    glLoadIdentity();
	    glFlush();
	    glClearColor(1.0, 1.0, 1.0, 1.0);
	    //Drawing grid vertical lines                                            
	    for (int i = 1; i < 22; i++)
	    {
	    	DrawLine(42 + (42 * i), 38, 42 + (42 * i), 798, 12, colors[BLACK]);
	    }
	    //Drawing grid horizontal line.
	    DrawLine(42 + (42 * 1), 38, 42 + (42 * 21), 38, 12, colors[BLACK]);
	    DrawLine(42 + (42 * 1), 798, 42 + (42 * 21), 798, 12, colors[BLACK]);
	    //Drawing Score
	    //int score =0;
	    string Score = "Score =";
	    DrawString( grid_x1[2], grid_y1[21]+8,Score, colors[BLACK]);
		DrawString(grid_x1[6], grid_y1[21]+8, to_string(score), colors[BLACK]);
	    // Drawing Map and buildings
	    DrawRectangle(grid_x[4][18], grid_y[4][18], 126, 38, colors[BLACK]);
	    DrawRectangle(462, 684, 462, 38, colors[BLACK]);
	    DrawRectangle(168, 190, 84, 114, colors[BLACK]);
	    DrawRectangle(grid_x[7][3], grid_y[7][3], 42, 294,     colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[11][1], grid_y[11][1], 42, 114,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[9][6], grid_y[9][6], 210, 38,     colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[13][6], grid_y[13][6], 42, 76,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[9][10], grid_y[9][10], 84, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[16][7], grid_y[16][7], 252, 38,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[16][4], grid_y[16][4], 42, 114,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[19][2], grid_y[19][2], 84, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[20][12], grid_y[20][12], 42, 190, colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[14][11], grid_y[14][11], 42, 228, colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[15][14], grid_y[15][14], 126, 38, colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[5][12], grid_y[5][12], 42, 114,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[4][14], grid_y[4][14], 42, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[7][14], grid_y[7][14], 84, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(378, 532, 42, 152, colors[BLACK]);
    
	    drawCar();
	    drawCar1();//Drawing enemy cars moving continuously moving.
	    drawCar2();//Drawing enemy cars moving continuously moving.
	    drawCar3();//Drawing enemy cars moving continuously moving.
	    drawCar4();//Drawing enemy cars moving continuously moving.
	    drawCar5();//Drawing enemy cars moving continuously moving.
		//Drawing Random Passangers.
		drawPassanger();
		//Drawing destination of the passangers.
		drawdestination();
		drawObstacles1();//Drawing obstacles.
		drawObstacles2();//Drawing obstacles.
		drawObstacles3();//Drawing obstacles.
		drawObstacles4();//Drawing obstacles.

	    glutSwapBuffers(); // do not modify this line..
	}
	else if (var==1)

	{
        glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	    glLoadIdentity();
	    glFlush();
	    glClearColor(1.0, 1.0, 1.0, 1.0);
	    //Drawing grid vertical lines                                            
	    for (int i = 1; i < 22; i++)
	    {
	    	DrawLine(42 + (42 * i), 38, 42 + (42 * i), 798, 12, colors[BLACK]);
	    }
	    //Drawing grid horizontal line.
	    DrawLine(42 + (42 * 1), 38, 42 + (42 * 21), 38, 12, colors[BLACK]);
	    DrawLine(42 + (42 * 1), 798, 42 + (42 * 21), 798, 12, colors[BLACK]);
	    //Drawing Score
	     string Score = "Score =";
	    DrawString( grid_x1[2], grid_y1[21]+8,Score, colors[BLACK]);
		DrawString(grid_x1[6], grid_y1[21]+8, to_string(score), colors[BLACK]);
    
	    // Drawing Map and buildings
	    DrawRectangle(grid_x[4][18], grid_y[4][18], 126, 38, colors[BLACK]);
	    DrawRectangle(462, 684, 462, 38, colors[BLACK]);
	    DrawRectangle(168, 190, 84, 114, colors[BLACK]);
	    DrawRectangle(grid_x[7][3], grid_y[7][3], 42, 294,     colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[11][1], grid_y[11][1], 42, 114,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[9][6], grid_y[9][6], 210, 38,     colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[13][6], grid_y[13][6], 42, 76,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[9][10], grid_y[9][10], 84, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[16][7], grid_y[16][7], 252, 38,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[16][4], grid_y[16][4], 42, 114,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[19][2], grid_y[19][2], 84, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[20][12], grid_y[20][12], 42, 190, colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[14][11], grid_y[14][11], 42, 228, colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[15][14], grid_y[15][14], 126, 38, colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[5][12], grid_y[5][12], 42, 114,   colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[4][14], grid_y[4][14], 42, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(grid_x[7][14], grid_y[7][14], 84, 38,    colors[BLACK]);//Drawing maps and buildings.
	    DrawRectangle(378, 532, 42, 152, colors[BLACK]);
    
	    drawCar_red();
	    drawCar1();//Drawing enemy cars moving continuously moving.
	    drawCar2();//Drawing enemy cars moving continuously moving.
	    drawCar3();//Drawing enemy cars moving continuously moving.
	    drawCar4();//Drawing enemy cars moving continuously moving.
	    drawCar5();//Drawing enemy cars moving continuously moving.
		//Drawing Random Passangers.
		drawPassanger();
	    //Drawing destination of the passangers.
		drawdestination();
		drawObstacles1();//Drawing obstacles.
		drawObstacles2();//Drawing obstacles.
		drawObstacles3();//Drawing obstacles.
		drawObstacles4();//Drawing obstacles.

	    glutSwapBuffers(); // do not modify this line..
	}
	else if (var==2)

	{
        glClear(GL_COLOR_BUFFER_BIT); //Update the colors
	    glLoadIdentity();
	    glFlush();
	    glClearColor(1.0, 1.0, 1.0, 1.0);
		string leaderboard1 = "Leaderboard";
        DrawString( grid_x1[10]+16, grid_y1[9],leaderboard1, colors[BLACK]);
	}
}
}    

//Drawing obstacles.

void NonPrintableKeys(int key, int x, int y)
{
	//declaring array.
	int grid_x[24][22];
	int grid_y[24][22];
	grid_x[0][0] = 0;
	grid_y[0][0] = 0;
	for (int i = 1; i < 24; i++)
	{
		for (int j = 1; j < 22; j++)
		{
			grid_x[i][j] = 42 + (42 * (i - 1));
			grid_y[i][j] = 38 + (38 * (j - 1));
		}
	}

	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		if (((yI >= 38 && xI == 84) && (yI <= 798 && xI == 84)) || // For left wall
			((yI >= 664 && xI == 294) && (yI <= 722 && xI == 294)) ||
			((yI >= 664 && xI == 924) && (yI <= 722 && xI == 924)) ||
			((yI >= 170 && (xI >= 225 && xI <= 227)) && (yI <= 304 && (xI >= 223 && xI <= 225)) )||
			((yI >= 512 && (xI >= 418 && xI <= 420)) && (yI <= 684 && (xI >= 418 && xI <= 420))) ||
			((yI >= 100 && (xI >= 334 && xI <= 338)) && (yI <= 400 && (xI >= 334 && xI <= 338))) ||
			((yI >= 436 && (xI >= 880 && xI <= 882)) && (yI <= 646 && (xI >= 880 && xI <= 882))) || //1.
			((yI >= 512 && (xI >= 588 && xI <= 756)) && (yI <= 570 && (xI >= 588 && xI <= 756))) || //2.
			((yI >= 550 && (xI >= 588 && xI <= 630)) && (yI <= 646 && (xI >= 588 && xI <= 630))) || //2.1.
			((yI >= 398 && (xI >= 588 && xI <= 630)) && (yI <= 532 && (xI >= 588 && xI <= 630))) || //2.2.
			((yI >= 132 && (xI >= 672 && xI <= 714)) && (yI <= 266 && (xI >= 672 && xI <= 714))) || //3.
			((yI >= 56 && (xI >= 798 && xI <= 882)) && (yI <= 114 && (xI >= 798 && xI <= 882))) ||	//4.
			((yI >= 18 && (xI >= 462 && xI <= 504)) && (yI <= 152 && (xI >= 462 && xI <= 504))) ||	//5.
			((yI >= 208 && (xI >= 378 && xI <= 588)) && (yI <= 304 && (xI >= 378 && xI <= 588))) || //6.
			((yI >= 418 && (xI >= 378 && xI <= 462)) && (yI <= 380 && (xI >= 378 && xI <= 462)))	//7.

		)
		{
			xI = xI + 0;
			cout << "noleft" << endl;
		}
		// what to do when left key is pressed...
		else
		{
			xI = xI - 5;
			cout << "Left key" << endl;
		}
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		if (((xI == 904 && yI >= 38) && (xI == 904 && yI <= 798)) ||								// For right wall
			((yI >= 436 && (xI <= 845 && xI >= 820)) && (yI <= 646 && (xI <= 845 && xI >= 820))) || //1.
			((yI >= 398 && (xI <= 590 && xI >= 568)) && (yI <= 646 && (xI <= 590 && xI >= 568))) || //2.
			((yI >= 132 && (xI <= 678 && xI >= 652)) && (yI <= 304 && (xI <= 678 && xI >= 652))) || //3.
			((yI >= 56 && (xI <= 882 && xI >= 778)) && (yI <= 114 && (xI <= 882 && xI >= 778))) ||	//4.
			((yI >= 18 && (xI <= 470 && xI >= 442)) && (yI <= 152 && (xI <= 470 && xI >= 442))) ||	//5.
			((yI >= 208 && (xI <= 380 && xI >= 358)) && (yI <= 266 && (xI <= 380 && xI >= 358))) || //6.1.
			((yI >= 266 && (xI <= 550 && xI >= 526)) && (yI <= 342 && (xI <= 550 && xI >= 526))) || //6.2.
			((yI >= 360 && (xI <= 360 && xI >= 358)) && (yI <= 418 && (xI <= 360 && xI >= 358))) || //7
			((yI >= 664 && (xI <= 444 && xI >= 442)) && (yI <= 722 && (xI <= 444 && xI >= 442))) || //8
			((yI >= 550 && (xI <= 360 && xI >= 358)) && (yI <= 684 && (xI <= 360 && xI >= 358))) || //9.1.
			((yI >= 512 && (xI <= 280 && xI >= 274)) && (yI <= 570 && (xI <= 280 && xI >= 274))) || //9.2.
			((yI >= 644 && (xI <= 150 && xI >= 148)) && (yI <= 722 && (xI <= 150 && xI >= 148))) || //10.
			((yI >= 512 && (xI <= 150 && xI >= 148)) && (yI <= 570 && (xI <= 150 && xI >= 148))) || //11.1
			((yI >= 436 && (xI <= 200 && xI >= 190)) && (yI <= 532 && (xI <= 200 && xI >= 190))) || //11.2
			((yI >= 170 && (xI <= 155 && xI >= 148)) && (yI <= 304 && (xI <= 155 && xI >= 148))) || //12
			((yI >= 94 && (xI <= 280 && xI >= 274)) && (yI <= 380 && (xI <= 280 && xI >= 274)))		//13
		)

		{
			xI = xI + 0;
			cout << "right" << endl;
		}
		else
		{
			xI += 5;
			cout << "Right key" << endl;
		}
	}
	else if (key == GLUT_KEY_UP /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		if (((xI >= 84 && yI >= 778) && (xI <= 924 && yI >= 778)) ||
			((xI >= 840 && (yI <= 440 && yI >= 434)) && (xI <= 882 && (yI <= 440 && yI >= 434))) || //1.
			((xI >= 588 && (yI <= 400 && yI >= 396)) && (xI <= 630 && (yI <= 400 && yI >= 396))) || //2.1.
			((xI >= 630 && (yI <= 520 && yI >= 510)) && (xI <= 756 && (yI <= 520 && yI >= 510))) || //2.2.
			((xI >= 672 && (yI <= 133 && yI >= 130)) && (xI <= 714 && (yI <= 133 && yI >= 130))) || //3.1.
			((xI >= 714 && (yI <= 250 && yI >= 244)) && (xI <= 924 && (yI <= 250 && yI >= 244))) || //3.2.
			((xI >= 820 && (yI <= 440 && yI >= 434)) && (xI <= 882 && (yI <= 440 && yI >= 434))) || //4.
			((xI >= 798 && (yI <= 57 && yI >= 54)) && (xI <= 882 && (yI <= 57 && yI >= 54))) ||		//5.
			((xI >= 378 && (yI <= 210 && yI >= 206)) && (xI <= 588 && (yI <= 210 && yI >= 206))) || //6.
			((xI >= 378 && (yI <= 360 && yI >= 358)) && (xI <= 462 && (yI <= 360 && yI >= 358))) || //7.
			((xI >= 462 && (yI <= 670 && yI >= 662)) && (xI <= 924 && (yI <= 670 && yI >= 662))) || //8.
			((xI >= 294 && (yI <= 513 && yI >= 510)) && (xI <= 420 && (yI <= 513 && yI >= 510))) || //9.
			((xI >= 168 && (yI <= 670 && yI >= 662)) && (xI <= 294 && (yI <= 670 && yI >= 662))) || //10.
			((xI >= 820 && (yI <= 440 && yI >= 434)) && (xI <= 862 && (yI <= 440 && yI >= 434))) || //11.1.
			((xI >= 820 && (yI <= 440 && yI >= 434)) && (xI <= 862 && (yI <= 440 && yI >= 434))) || //11.2.
			((xI >= 168 && (yI <= 170 && yI >= 168)) && (xI <= 252 && (yI <= 170 && yI >= 168))) || //12.
			((xI >= 294 && (yI <= 100 && yI >= 92)) && (xI <= 336 && (yI <= 100 && yI >= 92)))		//13.
		)

		{
			yI = yI + 0;
			cout << "no down" << endl;
		}
		else
		{
			yI += 5;
			cout << "Up key" << endl;
		}
	}
	else if (key == GLUT_KEY_DOWN /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		if (((xI >= 84 && yI == 38) && (xI <= 924 && yI == 38)) ||// for collision with walls.
			((xI >= 840-20 && (yI <= 646 && yI >= 640)) && (xI <= 882 && (yI <= 646 && yI >= 640))) || //1.
			((xI >= 630-20 && (yI <= 570 && yI >= 560)) && (xI <= 756 && (yI <= 570 && yI >= 560))) || //2.1.
			((xI >= 588-20 && (yI <= 646 && yI >= 630)) && (xI <= 630 && (yI <= 646 && yI >= 630))) || //2.2.
			((xI >= 672-20 && (yI <= 304 && yI >= 300)) && (xI <= 924 && (yI <= 304 && yI >= 300))) || //3.
			((xI >= 798-20 && (yI <= 114 && yI >= 112)) && (xI <= 882 && (yI <= 114 && yI >= 110))) || //4.
			((xI >= 462-20 && (yI <= 152 && yI >= 151)) && (xI <= 504 && (yI <=152  && yI >= 151))) || //5.
			((xI >= 378-20 && (yI <= 266 && yI >= 264)) && (xI <= 546 && (yI <= 266 && yI >= 264))) || //6.
			((xI >= 546-20 && (yI <= 342 && yI >= 340)) && (xI <= 588 && (yI <= 342 && yI >= 340))) || //6.1
			((xI >= 378-20 && (yI <= 418 && yI >= 412)) && (xI <= 462 && (yI <= 418 && yI >= 412))) || //7.
			((xI >= 462-20 && (yI <= 722 && yI >= 720)) && (xI <= 924 && (yI <= 722 && yI >= 720))) || //8.
			((xI >= 294-20 && (yI <= 570 && yI >= 567)) && (xI <= 378 && (yI <= 570 && yI >= 567))) || //9.1
			((xI >= 378-20 && (yI <= 684 && yI >= 682)) && (xI <= 420 && (yI <= 684 && yI >= 682))) || //9.2
			((xI >= 168-20 && (yI <= 722 && yI >= 721)) && (xI <= 294 && (yI <= 722 && yI >= 721))) || //10.
			((xI >= 168-20 && (yI <= 570 && yI >= 568)) && (xI <= 252 && (yI <= 570 && yI >= 568))) || //11.
			((xI >= 168-20 && (yI <= 304 && yI >= 302)) && (xI <= 252 && (yI <= 304 && yI >= 302))) || //12.
			((xI >= 294-20 && (yI <= 380 && yI >= 379)) && (xI <= 336 && (yI <= 380 && yI >= 379)))    //13.
		)

		{
			yI = yI + 0;
			cout << "no down" << endl;
		}
		// what to do when left key is pressed...
		else
		{
			yI -= 5;
			cout << "Down key" << endl;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y)
{
	// For passanger1.
	if (key == ' ' /* Escape key ASCII*/&& ((xI>=p1x-20 && xI<=p1x+20)&& (yI>=p1y-20 && yI<=p1y+20)))
	{
		//score = score+1;
		check1 =1;
		//exit(1); // exit the program when escape key is pressed.
	}
	else if(key == ' ' /* Escape key ASCII*/&&(xI >= destinationx1-10 && xI<=destinationx1+10)&&(yI>=destinationy1-10 && yI <=destinationy1+10))
	{
		check1=2;
		score = score+1;
	}
	//For passanger2
	if(key == ' ' /* Escape key ASCII*/&&((xI>=p2x-20 && xI<=p2x+20)&& (yI>=p2y-20 && yI<=p2y+20)))
	{
      //score = score+1;
	  check2=1;
	}
	else if(key == ' ' /* Escape key ASCII*/&&(xI >= destinationx2-10 && xI<=destinationx2+10)&&(yI>=destinationy2-10 && yI <=destinationy2+10))
	{
		check2=2;
		score = score+1;


	}
	//For passanger3
	if(key == ' ' /* Escape key ASCII*/&&((xI>=p3x-20 && xI<=p3x+10)&& (yI>=p3y-20 && yI<=p3y+20)))
	{
		//score = score+1;
		check3=1;
	}
	else if(key == ' ' /* Escape key ASCII*/&&(xI >= destinationx3-10 && xI<=destinationx3+10)&&(yI>=destinationy3-10 && yI <=destinationy3+10))
	{
		check3=2;
		score = score+1;

	}
	//For passanger4
	if(key == ' ' /* Escape key ASCII*/&&((xI>=p4x-20 && xI<=p4x+20)&& (yI>=p4y-20 && yI<=p4y+20)))
	{
		//score = score+1;
		check4=1;
	}
	else if(key == ' ' /* Escape key ASCII*/&&(xI >= destinationx4-10 && xI<=destinationx4+10)&&(yI>=destinationy4-10 && yI <=destinationy4+10))
	{
		check4=2;
		score = score+1;
	}
	//For Passanger 5
	if(key == ' ' /* Escape key ASCII*/&&((xI>=p5x-20 && xI<=p5x+20)&& (yI>=p5y-20 && yI<=p5y+20)))
	{
		//score = score+1;
		check5=1;
	}
	else if(key == ' ' /* Escape key ASCII*/&&(xI >= destinationx5-10 && xI<=destinationx5+10)&&(yI>=destinationy5-10 && yI <=destinationy5+10))
	{
		check5=2;
		score = score+1;
	}

	if (key == 'y' || key == 'Y') //Key for placing the bomb
	{
		var1=false;
		//do something if b is pressed
		var=0;
		cout << "y pressed" << endl;
	}
	else if (key == 'r' || key == 'R') //Key for placing the bomb
	{
		var1=false;
		//do something if b is pressed
		var=1;
		cout << "r pressed" << endl;
	}
	else if (key == 'L' || key == 'l') //Key for placing the bomb
	{
		var1=false;
		//do something if b is pressed
		var=2;
		cout << "l pressed" << endl;
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m)
{
	// implement your functionality here
	moveCar();
	drawPassanger1();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON)
	{
		var =1;
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;
	}
	glutPostRedisplay();
}
//RGBmixmap pix[6];
int main(int argc, char *argv[])
{

	int width = 1020, height = 836; // i have set my window size to be 800 x 600
    
	InitRandomizer();									   // seed the random number generator...
	glutInit(&argc, argv);								   // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);		   // we will be using color display mode
	glutInitWindowPosition(50, 50);						   // set the initial position of our window
	glutInitWindowSize(width, height);					   // set the size of our window
	glutCreateWindow("Rush Hour by i210780_Zunaira Amir"); // set the title of our game window
	SetCanvasSize(width, height);		
	//RAndomly generating positionof the passangers.

	p1x=GetRandInRange( grid_x1[15], grid_x1[19]);
	p1y=GetRandInRange( grid_y1[15], grid_y1[17]);	
	p2x=GetRandInRange( grid_x1[17], grid_x1[21]);
	p2y=GetRandInRange( grid_y1[5],  grid_y1[7]);	
	p3x=GetRandInRange( grid_x1[12], grid_x1[15]);
	p3y=GetRandInRange( grid_y1[4],  grid_y1[2]);	
	p4x=GetRandInRange( grid_x1[3],  grid_x1[7]);
	p4y=GetRandInRange( grid_y1[19], grid_y1[20]);	
	p5x=GetRandInRange( grid_x1[6],  grid_x1[9]);
	p5y=GetRandInRange( grid_y1[11], grid_y1[13]);	
	//Random positions of destinations of destinations
	destinationx1= GetRandInRange( grid_x1[2], grid_x1[6]);
	destinationy1= GetRandInRange( grid_y1[1], grid_y1[3]);	
	destinationx2= GetRandInRange( grid_x1[3], grid_x1[6]);
	destinationy2= GetRandInRange( grid_y1[15], grid_y1[17]);
	destinationx3= GetRandInRange( grid_x1[15], grid_x1[19]);
	destinationy3= GetRandInRange( grid_y1[10], grid_y1[13]);
	destinationx4= GetRandInRange( grid_x1[2], grid_x1[6]);
	destinationy4= GetRandInRange( grid_y1[1], grid_y1[3]);	
	destinationx5= GetRandInRange( grid_x1[7], grid_x1[10]);
	destinationy5= GetRandInRange( grid_y1[18], grid_y1[20]);
	//Randomly generating number of passangers.
	//srand(10);
	srand(5);
	passangers = (rand() % 3) + 3;
	//Randomly generating position of obstacles.
	obs1_x=	GetRandInRange( grid_x1[9], grid_x1[11]);
	obs2_y=	GetRandInRange( grid_y1[1], grid_y1[4]);
	obs3_y=	GetRandInRange( grid_y1[11], grid_y1[16]);
	obs4_y=	GetRandInRange( grid_y1[5], grid_y1[7]);		
   // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay);	   // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys);   // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);	  // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */

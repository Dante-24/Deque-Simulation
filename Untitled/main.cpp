#include <GL\glut.h>
#include <iostream>
#include <time.h>

using namespace std;

void init(void)
{
	glClearColor(0, 0, 0, 1);
}

bool fl = true;
int r1, g1, b1, ch, hd, tl, cnt;
int colarr[4][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0} };
string ele;

void drawBitmap(string s, int x, int y)
{
	glColor3f(255, 255, 255);
	glRasterPos2f(x, y);
	for (int i = 0; i < s.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void act(int y, int r, int g, int b) {
	glPointSize(1.0);
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2f(300, y);
	glVertex2f(300, 50 + y);
	glVertex2f(500, 50 + y);
	glVertex2f(500, y);
	glEnd();
}

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	hd = 50; tl = 50;
	cnt = 0;

	while (fl) {
		cout << "Enter your choice from the following options:\n1. Push\n2. Pop from Queue\n3. Pop from Stack\n4. Exit\n>>>";
		cin >> ch;
		switch (ch) {
		case 1:
			srand(time(NULL));
			cout << "Enter the element: ";
			cin >> ele;
			act(tl, colarr[cnt % 4][0], colarr[cnt % 4][1], colarr[cnt % 4][2]);
			drawBitmap(ele, 385, tl + 20);
			glFlush();
			cnt++;
			tl += 50;
			break;
		case 2:
			act(hd, 0, 0, 0);
			glFlush();
			if (hd != tl) {
				hd += 50;
			}
			break;
		case 3:
			act(tl - 50, 0, 0, 0);
			glFlush();
			if (hd != tl) {
				tl -= 50;
			}
			break;
		case 4:
			fl = false;
			break;
		default:
			break;
		}
	}
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f(0.0, 0.4, 0.2); // Set line segment color to green.
	glBegin(GL_LINES);
	glTranslatef(25.0, -10.0, 0.0);
	glVertex2i(180, 15); // Specify line-segment geometry.
	glVertex2i(10, 145);
	glEnd();
	glFlush(); // Process all OpenGL routines as quickly as possible.
}

void reshape(int w, int h)
{
	//use whole window
	glViewport(0, 0, w, h);
	//projection
	glMatrixMode(GL_PROJECTION);
	//clear projection matrix
	glLoadIdentity();
	gluOrtho2D(0, 1000, 0, 700);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 700);

	glutCreateWindow("window1");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	init();
	glutMainLoop();
	return 0;
}
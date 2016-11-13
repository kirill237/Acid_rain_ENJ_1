#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "global_data.h"
#include "enp.h"
#include <string>
#include <cstring>
#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>




using std::string;
using std::cout;
using std::endl;
using std::vector;

//vector<Enp>obj;

int movex=3;
//Enp pers(0,20,50,120);

void renderbitmapstring(float x,float y,char* str)
{
    int len;

    glColor4f(0.0,0.0,0.0,1.0);

    glRasterPos2i(x,y);
    glDisable(GL_TEXTURE|GL_TEXTURE_2D);
    for(int i=0,len = strlen(str);i<len;i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 ,(int)str[i]);
    }
    glEnable(GL_TEXTURE_2D|GL_TEXTURE);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,0.0,1.0);
    for(vector<Enp>::iterator i=all_obj.begin();i<all_obj.end();i++)
    {
        glColor3f(1.0,0.0,0.0);
        i->draw();
        /*
        char * writable = new char[i->obj_name.size() + 1];
        std::copy(i->obj_name.begin(), i->obj_name.end(), writable);
        writable[i->obj_name.size()] = '\0';
        renderbitmapstring(-screenW/2+i->x_pos,screenH/2-i->y_pos+i->size_y+15,writable);
        delete[] writable;
        */
    }
    //pers.draw(-screenW/2+pers.x_pos,screenH/2-(pers.size_y+pers.y_pos));
    glutSwapBuffers();
}


void keyboard_st(unsigned char c,int x,int y)
{
    switch (c)
    {
        case 'd':
            for(vector<Enp>::iterator i=all_obj.begin();i<all_obj.end();i++)
            {
                i->move(5,0);
            }
            break;
        case 'a':
            for(vector<Enp>::iterator i=all_obj.begin();i<all_obj.end();i++)
            {
                i->move(-5,0);
            }
            break;
        case 'w':
            for(vector<Enp>::iterator i=all_obj.begin();i<all_obj.end();i++)
            {
                i->move(0,-5);
            }
            break;
        case 's':
            for(vector<Enp>::iterator i=all_obj.begin();i<all_obj.end();i++)
            {
                i->move(0,5);
            }
            break;
        default:
            break;
    }
}


void Timer_draw(int)
{
    glutPostRedisplay();
    glutTimerFunc(int(1000/60),Timer_draw,0);
}

void Init()
{
    for(int i=0;i<1;i++)
    {
        for(int y=0;y<1;y++)
        {
            Enp c(i*50,y*120,50,120,"Red box");
            all_obj.push_back(c);
        }
    }
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-screenW/2,screenW/2,-screenH/2,screenH/2,-screenW/2,screenH/2);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "UTF-8");

    char a[256];
    cout << sizeof(a)*237*237 << endl;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(screenW,screenH);
    glutInitWindowPosition(0,0);
    glutCreateWindow("ng");
    glutDisplayFunc(Draw);
    glutTimerFunc(10,Timer_draw,0);
    glutKeyboardFunc(keyboard_st);
    Init();
    glutMainLoop();
    return 0;
}

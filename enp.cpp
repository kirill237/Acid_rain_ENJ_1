#include "enp.h"
#include <GL/glut.h>
#include "global_data.h"

void Enp::draw()
{
    if(this->in_screen)
    {
        glPushMatrix();
        //glLoadIdentity();
        glBegin(GL_QUADS);
        glVertex2f(-screenW/2+this->x_pos,screenH/2-this->y_pos);
        glVertex2f(-screenW/2+this->x_pos+this->size_x,screenH/2-this->y_pos);
        glVertex2f(-screenW/2+this->x_pos+this->size_x,screenH/2-this->y_pos+this->size_y);
        glVertex2f(-screenW/2+this->x_pos,screenH/2-this->y_pos+this->size_y);
        glEnd();
        glPopMatrix();
    }
}

void Enp::move(int ax, int ay)
{
    this->x_pos+=ax;
    this->y_pos+=ay;
    if((this->x_pos >= screenW+this->size_x || this->y_pos >= screenH+this->size_y)||
     (this->x_pos+this->size_x < 0 || this->y_pos+this->size_y < 0))
    {
        this->in_screen=false;
    }
    else
    {
        this->in_screen=true;
    }
}

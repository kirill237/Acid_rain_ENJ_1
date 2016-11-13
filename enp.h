#ifndef ENP_H
#define ENP_H
#include <string>
using std::string;

class Enp
{
public:
    string obj_name;
    int x_pos=0;
    int y_pos=0;
    int size_x=0;
    int size_y=0;
    bool in_screen=true;
    Enp(int _x,int _y,int _s_x,int _s_y,string _name):x_pos(_x),y_pos(_y),size_x(_s_x),size_y(_s_y),obj_name(_name){}
    ~Enp(){}
    void draw();
    void move(int ax,int ay);
};

#endif // ENP_H

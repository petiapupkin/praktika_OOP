#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::string;
using std::endl;
//                               ТОЧКА
//=================================================================

class point{
  
  public:
  
  float x;
  float y;
  float z;

      
  point (float x1 = 0, float y1 = 0, float z1 = 0){
    x = x1;
    y = y1;
    z = z1;
    
    cout << "  •   created/getted" << endl;
  }
  
  void print() const {cout << "              " << x << ' ' << y << ' ' << z << "  ⚝     point coordinates" << endl;}
  
  float get_x() const {return x;}
  float get_y() const {return y;}
  float get_z() const {return z;}
  
  void set_x (float s_x){x = s_x; cout << "•(x) changed  " << endl;}
  void set_y (float s_y){y = s_y; cout << "•(y) changed  " << endl;}
  void set_z (float s_z){z = s_z; cout << "•(z) changed  " << endl;}
};
//                               ОТРЕЗОК
//=========================================================================
//a- начало b - конец
class line : protected point{
   
  protected:
  
  point line_a;
  point line_b;
  float length ;
  
  public:
  // отрезок точка-точка
  line (point line_a1, point line_b1): line_a(line_a1), line_b(line_b1){ 
    
    line_a = line_a1;
    line_b = line_b1;
    cout << "----- created" << endl;
  }
  // отрезок точка-длинна-азимут-угол наклона
  line (point line_a2, float l, float azi, float nakl): line_a(line_a2) {
    line_a = line_a2;
    float x1 = line_a.get_x() + l * cos(azi) * cos(nakl);
    float y1 = line_a.get_y() + l * sin(azi) * cos(nakl);
    float z1 = line_a.get_z() + l * sin(nakl);
    line_b = point(x1, y1, z1);
    cout << "---- created" << endl;
  }
//  line_a — начальная точка вектора.
//  l — длина вектора.
//  azi — азимутальный угол (угол поворота вокруг оси Z).
//  nakl — угол наклона от плоскости XY.
  
  void print_length(){cout << "              " <<  sqrt(pow(line_b.get_x() - line_a.get_x(), 2) + pow(line_b.get_y() - line_a.get_y(), 2) + pow(line_b.get_z() - line_a.get_z(), 2)) << " length" << endl;}
  
  void print() const {cout << "              line ot ⚝ " << line_a.get_x() << " " << line_a.get_y() << " " << line_a.get_z() << 
  " ⚝ do ⚝ "   << line_b.get_x() << " " << line_b.get_y() << " " << line_b.get_z() << " ⚝   " <<  endl;}
  
  point get_line_a() const {return line_a;}
  point get_line_b() const {return line_b;}
  
  void set_line_a(point new_a) { line_a = new_a; cout << "----  (x,y,z) changed  " << endl; }
  void set_line_b(point new_b) { line_b = new_b; cout << "----  (x1,y1,z1) changed  " << endl; }
  
  
};

//                                      КВАДРАТ
//====================================================================================== 

class square : public line {
protected:

  line a_square;
  line b_square;

public:
  square(line a1_square, line b1_square) : line(a1_square.get_line_a(), a1_square.get_line_b()), a_square(a1_square), b_square(b1_square) {
    
    a_square = a1_square;
    b_square = b1_square;
    
    cout << "  ⊞  created"  << endl;
  }
  
  // void print_sq() {cout << a_square.print() << b_square.print()<< endl;}
    void print() const {cout << "              square: " <<  endl 
    <<"                        ⚝ "<< a_square.get_line_a().x <<" "<< a_square.get_line_a().y <<" "<< a_square.get_line_a().z << " ⚝   " <<   endl 
    <<"                        ⚝ "<< a_square.get_line_b().x <<" "<< a_square.get_line_b().y <<" "<< a_square.get_line_b().z << " ⚝   " <<   endl 
    <<"                        ⚝ "<< b_square.get_line_a().x <<" "<< b_square.get_line_a().y <<" "<< b_square.get_line_a().z << " ⚝   " <<   endl 
    <<"                        ⚝ "<< b_square.get_line_b().x <<" "<< b_square.get_line_b().y <<" "<< b_square.get_line_b().z<< " ⚝   " <<   endl ;}
    
    line get_a_square() const {return a_square;}
    line get_b_square() const {return b_square;}
    
    void set_a_square(line new_a1) {a_square = new_a1; cout << " ----  (x,y,z,v,e,d) changed  " << endl; }
    void set_b_square(line new_b1) {b_square = new_b1; cout << " ----  (x1,y1,z1,v1,e1,d1) changed  " << endl; }
    
};

//                                   Параллелограм
//===============================================================================

class par : public square {
protected:
  square a_par;
  square b_par;
public:
  par(square a1_par, square b1_par) : square(a1_par.get_a_square(), a1_par.get_b_square()), a_par(a1_par), b_par(b1_par){
    a_par = a1_par;
    b_par = b1_par;
    
    cout << "  ⊞  ⊞ created"  << endl;
  }
  
  void print() const {cout  << "              parelelogram: " <<  endl 
  <<"                        "<< a_par.get_a_square().x <<" "<< a_par.get_a_square().y <<" "<< a_par.get_a_square().z << "   " <<   endl 
    <<"                        "<< a_par.get_b_square().x <<" "<< a_par.get_b_square().y <<" "<< a_par.get_b_square().z << "   " <<   endl 
    <<"                        "<< b_par.get_a_square().x <<" "<< b_par.get_a_square().y <<" "<< b_par.get_a_square().z << "   " <<   endl 
    <<"                         "<< b_par.get_b_square().x <<" "<< b_par.get_b_square().y <<" "<< b_par.get_b_square().z<< "   " <<   endl ;}
    
  
};

int main(){
  
  cout << R"(---------------------------------------
    ⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⢀⡀⠀⠀⠀
⣤⣶⣶⡿⠿⠿⠿⠿⣶⣶⣶⠄⠀⠀⠐⢶⣶⣶⣿⡿⠿⠿⠿⠿⢿⣷⠦⠀
⠙⠏⠁⠀⣤⣶⣶⣶⣶⣒⢳⣆⠀⠀⠀⠀⢠⡞⣒⣲⣶⣖⣶⣦⡀⠀⠉⠛⠁
⠀⠀⠴⢯⣁⣿⣿⣿⣏⣿⡀⠟⠀⠀⠀⠀⠸⠀⣼⣋⣿⣿⣿⣦⣭⠷⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠟⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡄⠀⢰⠏⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠟⠁⢀⡟⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠸⡗⠶⠶⠶⠶⠶⠖⠚⠛⠛⠋⠉⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀
--------------------------------------⠀⠀)" << endl;



  square pof(line(point(1, 1, 1), point( 3, 3, 3)), line(point(2, 2, 2), point(5, 5, 5)));
  pof.print();
  pof.set_a_square(line(point(0, 0, 0), point( 3, 3, 3)));
  pof.print();
  
  line lox (point(1,-1,0), point(0,0,0));
  lox.print();
  lox.print_length();
  
  line pox (point(2,1,4), 7, 45, 23);
  pox.print();
  pox.print_length();
  
  lox.set_line_a(point(2, 2, 6));
  lox.set_line_b(point(-1, -1, -1));
  lox.print();
  lox.print_length();
  
  point a(1,1,1);
  a.print();
  
  return 0;
}

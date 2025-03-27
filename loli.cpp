//     cout << R"(---------------------------------------
//     ⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⢀⡀⠀⠀⠀
// ⣤⣶⣶⡿⠿⠿⠿⠿⣶⣶⣶⠄⠀⠀⠐⢶⣶⣶⣿⡿⠿⠿⠿⠿⢿⣷⠦⠀
// ⠙⠏⠁⠀⣤⣶⣶⣶⣶⣒⢳⣆⠀⠀⠀⠀⢠⡞⣒⣲⣶⣖⣶⣦⡀⠀⠉⠛⠁
// ⠀⠀⠴⢯⣁⣿⣿⣿⣏⣿⡀⠟⠀⠀⠀⠀⠸⠀⣼⣋⣿⣿⣿⣦⣭⠷⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠟⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡄⠀⢰⠏⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠟⠁⢀⡟⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠸⡗⠶⠶⠶⠶⠶⠖⠚⠛⠛⠋⠉⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠀⠀
// --------------------------------------⠀⠀)" << endl;

#include <iostream>
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::string;
using std::endl;

//=================================================================

class point{
  
  protected:
  
  float x;
  float y;
  float z;
  
  public:
  
  point (float x1 = 0, float y1 = 0, float z1 = 0){
    x = x1;
    y = y1;
    z = z1;
    
    cout << "•⩊•" << endl;
  }
  
  void print() const {cout << x << ' ' << y << ' ' << z << " - point coordinates" << endl;}
  
  float get_x() const {return x;}
  float get_y() const {return y;}
  float get_z() const {return z;}
  
  void set_x (float s_x){x = s_x;}
  void set_y (float s_y){y = s_y;}
  void set_z (float s_z){z = s_z;}
};

//=======================================================
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
    cout << "----" << endl;
  }
  // отрезок точка-длинна-азимут-угол наклона
  line(point line_a2, float l, float azi, float nakl): line_a(line_a2) {
    line_a = line_a2;
    float x1 = line_a.get_x() + l * cos(azi) * cos(nakl);
    float y1 = line_a.get_y() + l * sin(azi) * cos(nakl);
    float z1 = line_a.get_z() + l * sin(nakl);
    line_b = point(x1, y1, z1);
    cout << "----" << endl;
  }
//  line_a — начальная точка вектора.
//  l — длина вектора.
//  azi — азимутальный угол (угол поворота вокруг оси Z).
//  nakl — угол наклона от плоскости XY.
  
  void print_length(){cout << sqrt(pow(line_b.get_x() - line_a.get_x(), 2) + pow(line_b.get_y() - line_a.get_y(), 2) + pow(line_b.get_z() - line_a.get_z(), 2)) << endl;}
  
  void print() const {cout << "line ot ⚝ " << line_a.get_x() << " " << line_a.get_y() << " " << line_a.get_z() << 
  " ⚝ do ⚝ "   << line_b.get_x() << " " << line_b.get_y() << " " << line_b.get_z() << " ⚝   " <<  endl;}
  
  point get_line_a() const {return line_a;}
  point get_line_b() const {return line_b;}
  
  void set_line_a(point new_a) { line_a = new_a; }
  void set_line_b(point new_b) { line_b = new_b; }
  
  
};

//========================================================

class square : public line {
protected:
    point c_square, d_square;

public:
    // Конструктор квадрата по двум точкам
    square(point a, point b) : line(a, b) {
        // Вычисляем оставшиеся две точки
        float dx = b.get_x() - a.get_x();
        float dy = b.get_y() - a.get_y();

        c_square = point(a.get_x() - dy, a.get_y() + dx, a.get_z());
        d_square = point(b.get_x() - dy, b.get_y() + dx, b.get_z());

        cout << "==== (Создан квадрат) ====" << endl;
    }

    void print()
};
//========================================================

int main(){
  
  line lox (point(1,1,0), point(0,0,0));
  lox.print();
  lox.print_length();
  
  line pox (point(1,1,0), 7);
  pox.print();

  
  lox.set_line_a(point(2, 2, 6));
  lox.set_line_b(point(-1, -1, -1));
  lox.print();
  lox.print_length();
  
  point a(1,1,1);
  a.print();
  
  return 0;
}
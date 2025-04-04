#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
enum class post {smak, nesmak}; //реализация перечя имен (бесполезно)

string postTostring(post p){ //штука которая преобразует enum в строки
  switch(p){
    case post::smak:return "smak";
    case post::nesmak:return "nesmak";
    default: return "unknown";
  }
}

class goods { //адекватный класс
  
  int ID;
  string name;
  float money;
  string post;
  string newpost;
  
  static inline unsigned count{}; //умный счетчик statik - статическая inline -одна unsigned - значение 0 целое число без знака
  
  public:
  
  goods (int new_id = 0, string new_name = "unknown", float new_money = 0, string new_post = "unknown", string newnew_post = "unknown"){ //конструктор, что  с него взять
    ID = new_id;
    name = new_name;
    money = new_money;
    post = new_post;
    newpost = newnew_post;
    ++count;
    cout << "товар " << name << " СОЗДАН. count: " << count << endl;
    
  }
  
  ~goods (){ //деструктор акка ликвидирован
    --count;
    cout << "товар " << name << " ЛИКВИДИРОВАН. count: " << count << endl;
  }
  
  //вывод принт питон юху
  void print(){
    cout << ID << " " << name << " " << money << " " << post << " " << newpost << endl;
  }
  
  //обращение к обьектам геттеры
  int get_id(){
    return ID;
  }
  
  string get_name(){
    return name;
  }
  
  float get_money(){
    return money;
  }
  
  string get_post(){
    return post;
  }
  
  //создание параметров сеттеры
  void set_id(int s_id){
    ID = s_id;
  }
  
  void set_name(string s_name){
    name = s_name;
  }
  
  void set_money(float s_money){
    money = s_money;
  }
  
  void set_post(string s_post){
    newpost = s_post;
  }
  
};

//список товаров через узлы
class list{
  goods value;
  list* next;
  list* prev;
};


int main() 
{
  goods milk;
  
  milk.set_id(1);
  milk.set_name("milk");
  milk.set_money(100);
  milk.set_post("smak"); //обращение через сетторы
  
  goods bread(2, "bread", 66, "smak");
  goods vshutin(3, "Владимир Владимирович Шутин", 0, "Мария Ивановна Шутина" );//обращение через конструктор...
  
  cout << milk.get_id()<< endl; //вывод через сеттор
  
  milk.print(); //вывод через функцию
  bread.print();
  vshutin.print();
  
  return 0;
  
}


#include <iostream>
#include <vector>
using namespace std;
class Display{
  public:
  float sum(int a,int b){
    cout<<"sum of two numbers "<<a+b<<" ";
    return a+b;
  }
  void sum(int a,int b,int c){
    cout<<"sum of three numbers "<<a+b+c<<" ";
  }
  void display(){
      cout<<"parent";
  }
};
class Disp : public Display{
    public:
    void display(){
        cout<<"child class";
    }
};

int main()
{
    int a,b;
    cout<<"enter two numbers ";
    cin>>a>>b;
    Display ds;
    cout<<ds.sum(a,b);
    cout<<endl;
    cout<<"enter another number ";
    int c;
    cin>>c;
    ds.sum(a,b,c);
    cout<<endl;
    Disp d;
    d.display();    
    return 0;
}
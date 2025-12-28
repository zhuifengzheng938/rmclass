#include <iostream>

using namespace std;

class Book {
    public:
        string name;
        string author;
        int pages ;

        void show_detail(){

            cout<<"name: "<<name<<" author: "<<author<<" pages: "<<pages<<endl;


        }



        bool is_thick(){
            
            if (pages >= 500){
                 return 1;
            }


            else{
                return 0;
            }


            
        }

        int ret = is_thick();
        
        void output(){
            if (ret == 1) {
            cout<<"Thick Book!"<<endl;
            }
            else{
            cout<<"Is not Thick Book!"<<endl;

            }
        }


};









int main(){


    Book b1;
    b1.name = "c++";
    b1.author = "zhangsan";
    b1.pages = 300;
    b1.show_detail();
    b1.is_thick();
    b1.output();




    Book b2;
    b2.name = "python";
    b2.author = "lisi";
    b2.pages = 600;
    b2.show_detail();
    b2.is_thick();
    b2.output();





    return 0;
}
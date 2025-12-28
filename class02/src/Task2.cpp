#include <iostream>

using namespace std;
int total = 0;
int PassNumber(int a, int b, int c){
    if (a >= 60){
        total ++;
        cout<<"first student pass! "<<a<<endl;
    }
    else{
        cout<<"first student fail!"<<endl;
    }
    
    
    if (b >= 60){
        total ++;
        cout<<"second student pass! "<<b<<endl;
    }
    else{
        cout<<"second student fail!"<<endl;
    }
    


    if (c >= 60){
        total ++;
        cout<<"third student pass! "<<c<<endl;
    }
    else{
        cout<<"third student fail!"<<endl;
    }
    
    return total;
}




int main(){
    
    int a = 0;
    int b = 0;
    int c = 0;
    cout<<"Enter the scores of 3 students(in inteder form)"<<endl;

    cin>>a >>b >>c;

    int total = PassNumber(a, b, c);
    cout<<"There are "<<total<<" students who passed the exam"<<endl;






    
    return 0;
}
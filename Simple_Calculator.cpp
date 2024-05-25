#include<iostream>
using namespace std;

int main(){
    float num1,num2;
    cout<<"\t\t\t\t\t\t\t\t  ..CALCULATOR.."<<endl;
    cout<<"\nEnter First Number: ";
    cin>>num1;
    cout<<"Enter Second Number: ";
    cin>>num2;
    cout<<"\nOperation Menu:-"<<endl;
    cout<<"1. Press 1 to perform Addition"<<endl;
    cout<<"2. Press 2 to perform Subtraction"<<endl;
    cout<<"3. Press 3 to perform Multiplication"<<endl;
    cout<<"4. Press 4 to perform Division"<<endl;
    int choice;
    float answer;
    cout<<"Enter Your Choice:";
    cin>>choice;
    switch(choice){
        case 1:
        answer=num1+num2;
        cout<<"The Addition of the given numbers is: "<<answer<<endl;
        break;
        case 2:
        answer=num1-num2;
        cout<<"The Difference of the given numbers is: "<<answer<<endl;
        break;
        case 3:
        answer=num1*num2;
        cout<<"On Multiplication of the given numbers we get: "<<answer<<endl;
        break;
        case 4:
        answer=num1/num2;
        cout<<"Dividing the given numbers we get: "<<answer<<endl;
        break;
        default:
        cout<<"Only a number from 1 to 4 will be accepted as choice."<<endl;
        break;
    }
    return 0;
}
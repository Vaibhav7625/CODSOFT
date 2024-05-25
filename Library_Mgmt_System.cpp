#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    cout<<"\t\t\t\t\t\t\t\t..Library Management System.."<<endl;
    char s='Y';
    vector<vector<string>> Books_Details;
    vector<vector<string>> Books_Exchange_Detail;
    while(s=='Y' || s=='y'){
        cout<<"\nOperation Menu:-"<<endl;
        cout<<"1. Store a Book Information."<<endl;
        cout<<"2. Search for a Book."<<endl;
        cout<<"3. Check out a Book for borrower."<<endl;
        cout<<"4. Record Books return, Update Availability Status and calculate Fine for overdue Books."<<endl;
        int choice,var=-1,x,num1,num2,num3,num4,fine;
        string Title,Author,ISBN,Status,Var,Date;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter Title of Book: ";
            cin.get();
            getline(cin,Title);
            cout<<"Enter Name of Author: ";
            getline(cin,Author);
            cout<<"Enter ISBN number(Format: DDD-D-DD-DDDDDD-D): ";
            getline(cin,ISBN);
            Books_Details.push_back({Title,Author,ISBN,"Available"});
            cout<<"Book Details entered Successfully"<<endl;
            break;
            case 2:
            if(Books_Details.empty()){
                cout<<"Currently, there is no Book in the database."<<endl;
            }
            else{
                cout<<"Enter any Detail of Book (Either Title, Author or ISBN number):";
                cin.get();
                getline(cin,Var);
                for (size_t i = 0; i < Books_Details.size(); ++i) {
                    for (size_t j = 0; j < Books_Details[i].size()-1; ++j) {
                        if(Books_Details[i][j]==Var){
                            cout<<"Title, Author, ISBN Number"<<endl;
                            cout<<Books_Details[i][0]<<", "<<Books_Details[i][1]<<", "<<Books_Details[i][2]<<endl;
                            var=1;
                            break;
                        }
                        if(var==1){
                            break;
                        }
                    }
                }
                if(var==-1){
                    cout<<"We can't find out the Book you entered in our database."<<endl;
                }
                var=-1;
            }
            break;
            case 3:
            if(Books_Details.empty()){
                cout<<"Currently, there is no Book in the database."<<endl;
            }
            else{
                cout<<"Enter any Detail of Book (Either Title, Author or ISBN number) you want to borrow:";
                cin.get();
                getline(cin,Var);
                for (size_t i = 0; i < Books_Details.size(); ++i) {
                    for (size_t j = 0; j < Books_Details[i].size()-1; ++j) {
                        if(Books_Details[i][j]==Var && Books_Details[i][3]=="Available"){
                            cout<<"Book is available to be borrowed."<<endl;
                            cout<<"Changing Status to 'Not Available'."<<endl;
                            Books_Details[i][3]="Not Available";
                            cout<<"Enter Date of Borrow(Format: DD-MM-YYYY): ";
                            getline(cin,Date);
                            Books_Exchange_Detail.push_back({Books_Details[i][2],Date," "});
                            cout<<"Please return the book before the end of next month else fine of ₹75 per month will be imposed from day 1 of that month. Thank You!!"<<endl;
                            var=1;
                            break;
                        }
                        if(var==1){
                            break;
                        }
                    }
                }
                if(var==-1){
                    cout<<"We can't find out the Book you entered in our database."<<endl;
                }
                var=-1;
            }
            break;
            case 4:
            cout<<"Enter any Detail of Book (Either Title, Author or ISBN number) you want to return:";
            cin.get();
            getline(cin,Var);
            for (size_t i = 0; i < Books_Details.size(); ++i) {
                for (size_t j = 0; j < Books_Details[i].size()-1; ++j) {
                    if(Books_Details[i][j]==Var){
                        cout<<"Changing Status to 'Available'."<<endl;
                        Books_Details[i][3]="Available";
                        cout<<"Enter Date of Return(Format: DD-MM-YYYY): ";
                        getline(cin,Date);
                        for(size_t k=0;k<Books_Exchange_Detail.size();k++){
                            if(Books_Exchange_Detail[k][0]==Books_Details[i][2]){
                                Books_Exchange_Detail[k][2]=Date;
                                num1=Books_Exchange_Detail[k][2][9]-'0';
                                num2=Books_Exchange_Detail[k][1][9]-'0';
                                num3=(Books_Exchange_Detail[k][2][3]-'0')*10+(Books_Exchange_Detail[k][2][4]-'0');
                                num4=(Books_Exchange_Detail[k][1][3]-'0')*10+(Books_Exchange_Detail[k][1][4]-'0');
                                x=num3-num4;
                                if(num1-num2>0 && x>0){
                                    cout<<"Kindly pay fine of ₹1000 for late book return. Thank You."<<endl;
                                }
                                else if(num1-num2==0 && x>1){
                                    fine=x*75;
                                    cout<<"Kindly pay fine of ₹"<<fine<<" for late book return. Thank You."<<endl;
                                }
                                else if(num1-num2>0 &&x<1){
                                    fine=(12-num3+num4)*75;
                                    cout<<"Kindly pay fine of ₹"<<fine<<" for late book return. Thank You."<<endl;
                                }
                                else{
                                    cout<<"No fine need to be paid. Thank You!!"<<endl;
                                }
                                break;
                            }
                        }
                        var=1;
                        break;
                    }
                }
                if(var==1){
                    break;
                }
            }
            if(var==-1){
                cout<<"We can't find out the details of Book you entered in our database."<<endl;
            }
            var=-1;
            break;
            default:
            cout<<"Only a number from 1 to 4 will be accepted as choice."<<endl;
            break;
        }
        cout<<"Do you want to continue (y/n): ";
        cin>>s;
    }
    cout<<"Program Executed Successfully."<<endl;
    return 0;
}
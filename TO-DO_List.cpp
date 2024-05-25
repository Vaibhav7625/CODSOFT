#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    cout<<"\t\t\t\t\t\t\t\t  ..TO-DO LIST.."<<endl;
    char s='Y';
    vector<vector<string>> list;
    while(s=='Y' || s=='y'){
        cout<<"\nOperation Menu:-"<<endl;
        cout<<"1. Press 1 to add a Task to the List"<<endl;
        cout<<"2. Press 2 to view the List"<<endl;
        cout<<"3. Press 3 to mark any Task in the list as 'Completed'"<<endl;
        cout<<"4. Press 4 to remove a Task from the List"<<endl;
        int choice,var=-1;
        string Task;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter Task: ";
            cin.get();
            getline(cin,Task);
            list.push_back({Task, "Pending"});
            cout<<"Task entered Successfully"<<endl;
            break;
            case 2:
            if(list.empty()){
                cout<<"The List is empty"<<endl;
            }
            else{
                cout<<"Task, Status :"<<endl;
                for (size_t i = 0; i < list.size(); ++i) {
                    for (size_t j = 0; j < list[i].size(); ++j) {
                        cout << list[i][j] << ", ";
                    }
                cout << endl;
                }
            }
            break;
            case 3:
            cout<<"Enter the Task (Case-Sensitive so write here exactly how it's in the list i.e. take Care of Caps and Spaces): ";
            cin.get();
            getline(cin,Task);
            for(size_t i = 0; i < list.size(); ++i){
                if(list[i][0]==Task){
                    list[i][1]="Completed";
                    var=1;
                    break;
                }
            }
            if(var!=1){
                cout<<"We can't find out the task you mentioned in the list. Check if you entered any letter/word wrong like without caps or you missed any space/word/leteer."<<endl;
            }
            else{
                cout<<"Task '"<<Task<<"' marked as 'Completed' successfully."<<endl;
            }
            var=-1;
            break;
            case 4:
            cout<<"Enter the Task (Case-Sensitive so write here exactly how it's in the list i.e. take Care of Caps and Spaces): ";
            cin.get();
            getline(cin,Task);
            for(int i=0;i<list.size();i++){
                if(list[i][0]==Task){
                    list.erase(list.begin()+i);
                    var=i;
                    break;
                }
            }
            if(var==-1){
                cout<<"We can't find out the task you mentioned in the list. Check if you entered any letter/word wrong like without caps or you missed any space/word/leteer."<<endl;
            }
            else{
                cout<<"Task '"<<Task<<"' removed from the List successfully."<<endl;
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
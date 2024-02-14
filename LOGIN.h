#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>

//#include"LMS.h"
using namespace std;

class Login{
    public:
    void login();
    void registration();
    void forgot_password();
};

void Login::login(){
    int count=0;
    char choice;
    string userId, password,id, pass,line;
    cout<<"please enter username and password"<<endl;
    cout<<"Username: ";
    cin.ignore();
    getline(cin,userId);
    cout<<"Password:";
    cin.ignore();
    getline(cin,password);
    
    ifstream input("login_records.txt");
    
    while(getline(input,line)){
        stringstream strm(line);
        getline(strm,id,':');
        strm.ignore();
		getline(strm,pass);
        if(id==userId && pass==password){
            count=1;
            
        }
    }
    input.close();
    if(count==1){
        cout<<"Your login is successful"<<endl;
        do{
            cout<<"1.Search Book"<<endl<<"2.Display"<<endl<<"3.exit"<<endl;
            int choice;
            cout<<"Enter choice: ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    cout<<"****************"<<endl;
                    cout<<"-----------------SEARCH BOOK------------------"<<endl;
                    cout<<"****************"<<endl;
                    
                    Search library;
                	string book_name, author_name;
                	int choice,book_id;
                	do
                	{
                	    cout<<"\nSearch Book\n1. by name\n2. by id\n3. by author"<<endl;
                        cin>>choice;
                	    switch(choice)
                	    {
                	        case 1:
                	        {
                	            cout<<"Enter Book name: ";
                    			cin.ignore();
                    			getline(cin,book_name);
                    		transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
	library.search_bookname(book_name);
                	            break;
                	        }
                	        case 2:
                	        {
                	            cout<<"Enter Book ID: ";
                    		    cin>>book_id;
                    		    library.search_bookId(book_id);
                	            break;
                	        }
                	        case 3:
                	        {
                	            cout<<"Enter Author name: ";
                        		cin.ignore();
                        		getline(cin,author_name);
                        	transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
	library.search_author(author_name);
                        		break;
                	        }
                	        default:
                	        {
                	            cout<<"Enter Valid choice"<<endl;
                	            break;
                	        }
                	    }
                	   cout<<"do you want to search another book"<<endl;
                	   cin>>choice;
                	 }while(choice=='y');
                	    
                	 break;
                }
                case 2:
                {
                    cout<<"**************"<<endl;
                    cout<<"------------DISPLAY BOOKS-------------"<<endl;
                    cout<<"**************"<<endl;
                    addbooks lib;
                    lib.display_books();
                    break;
                }
                case 3:
                {
                    exit(0);
                }
                default:
                {
                    cout<<"Enter Valid Choice"<<endl;
                    break;
                }
            
            }
            cout<<"Do you want to continue with search or display books 'y' or 'n'"<<endl;
            cin>>choice;
            
        }while(choice=='y');
        
    }
    else{
        cout<<"Login error. Please check usedId and password"<<endl;
    }
}

void Login::registration(){
    string ruserId, rpassword, rid, rpass;
    cout<<"Enter username: ";
    cin>>ruserId;
    cout<<"Enter password: ";
    cin>>rpassword;
    ofstream file("login_records.txt",ios::app);
    file<<ruserId<<":"<<rpassword<<endl;
    cout<<"registration is successful";
    
}

void Login::forgot_password(){
    int option,count=0;
    string suserId, sid,spass;
    
    cout<<"You forgot the password?No worries"<<endl;
    cout<<"enter username which you remebered:";
    cin>>suserId;
    ifstream f("login_records.txt");
    while(f>>sid>>spass){
        if(sid==suserId){
            count=1;
        }
    }
    f.close();
    if(count==1){
        cout<<"your account is found"<<endl;
        cout<<"your password is : "<<spass;
    }
    else{
        cout<<"sorry account is not found"<<endl;
    }
}


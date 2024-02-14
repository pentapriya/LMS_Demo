#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

#include"LMS.h"
#include"LOGIN.h"
using namespace std;

int main()
{
    char yes;
    string book_name;
    cout<<"***************************"<<endl;
    cout<<"LIBRARY MANAGEMENT SYSTEM "<<endl;
    cout<<"***************************"<<endl;
    do{
    cout<<"1.Admin Login"<<endl<<"2.Student Access"<<endl;
    int Login_Type;
    cout<<"Enter Login Type: ";
    cin>>Login_Type;
    switch(Login_Type)        
    {
        case 1:
        {
            cout<<"Hello, Admin "<<endl;
                int Pin=1234;
                int Input_Pin=0;
                int Warning=1;
                do
                {
                    cout<<"Enter Pin: ";
                    cin>>Input_Pin;
                    if(Input_Pin==Pin)
                    {
                        cout<<"Login Succesful"<<endl;
                    }
                    else
                    {
                        Warning++;
                        cout<<"You have entered wrong pin.Try Again!!!"<<endl;
                    }
                }
                while(Warning<=3 && Input_Pin!=Pin);
                {
                    if(Warning>3)
                    {
                            cout<<"You have entered incorrect pin more than 3 times"<<endl;
                            cout<<"So Your Account Is Blocked!!! "<<endl;
                            exit(0);
                    }
                }
                cout<<"-------------------------------------------------------------"<<endl;
                cout<<"--------------------------ADMIN MENU-------------------------"<<endl;
                cout<<"-------------------------------------------------------------"<<endl;
                do{
                 cout<<"1.Add Books" <<endl<<"2.display books"<<endl<<"3.Search Book"<<endl<<"4.Issue Book"<<endl<<"5.Return Books "<<endl<<"6.Delete Books"<<endl<<
                 "7.Exit"<<endl;
                
                 int Choice;
                 cout<<"Enter Your Choice: ";
                 cin>>Choice;
                 switch(Choice)
                 {
                    case 1:
                    {
                        
                        cout<<"************************************"<<endl;
                        cout<<"------------ADD BOOKS-------------"<<endl;
                        cout<<"************************************"<<endl;
                        do
                        {
                          addbooks library;
                          library.insert_books();
                          cout<<"do you want to append another book.If yes enter 'y' else enter 'n'"<<endl;
                          cin>>yes;
                        }while(yes=='y');
                        break;
                    }
                    case 2:
                    {
                        cout<<"**************************************"<<endl;
                        cout<<"------------DISPLAY BOOKS-------------"<<endl;
                        cout<<"**************************************"<<endl;
                        addbooks library;
                        library.display_books();
                        break;
                    }
                    case 3:
                    {
                        cout<<"************"<<endl;
                        cout<<"---------SEARCH BOOK ---------"<<endl;
                        cout<<"************"<<endl;
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
                    	            
                    	            cout<<"Enter Book Name To Search "<<endl;
                    		        cout<<"------------------------"<<endl;
                    	            cout<<"Enter Book name"<<endl;
                        			cin.ignore();
                        			getline(cin,book_name);
                        			transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
                        			library.search_bookname(book_name);
                    	            break;
                    	        }
                    	        case 2:
                    	        {
                    	            cout<<"Enter Book Id To Search "<<endl;
                    		        cout<<"------------------------"<<endl;
                    	            cout<<"Enter Book ID"<<endl;
                        		    cin>>book_id;
                        		    library.search_bookId(book_id);
                    	            break;
                    	        }
                    	        case 3:
                    	        {
                    	            cout<<"Enter Book Author To Search "<<endl;
                    		        cout<<"------------------------"<<endl;
                    	            cout<<"Enter Author name"<<endl;
                        		    cin.ignore();
                        		    getline(cin,author_name);
                        		    transform(author_name.begin(),author_name.end(),author_name.begin(), ::toupper);
                        		    library.search_author(author_name);
                    	            break;
                    	        }
                    	        default:
                    	        {
                    	            cout<<"Enter Valid Choice"<<endl;
                    	            break;
                    	        }
                    	    }
                    	    cout<<"do you want to search another book"<<endl;
                    	    cin>>yes;
                    	}while(yes=='y');
	
                        break;
                    }
                    case 4:
                    {
                        student s;
                        char ch;
                        string str;
                        fstream file;
                        int book_id;
                        int opt;
                        cout<<"************************************************************************"<<endl;
                        cout<<"---------------------ISSUE BOOK MENU----------------------------------"<<endl;
                        cout<<"************************************************************************"<<endl;
                        do{
                            cout<<"enter required choice: "<<endl<<"1.Issue book to student"<<endl<<"2.Display issued books"<<endl<<"3.Search issued book by bookid"<<endl<<"4.exit"<<endl;
                            cin>>opt;
                            switch(opt)
                            {
                                case 1:
                                {
                                    cout<<"******************************"<<endl;
                                    cout<<"---------Issue book to student-------------"<<endl;
                                    cout<<"**********************************"<<endl;
                                    cout<<"Enter Data "<<endl;
                    		        cout<<"-----------"<<endl;
                                   
                                    do
                                    {
                                        s.create();
                                        cout<<"do you want to issue another book (y/n)"<<endl;
                                        cin>>ch;
                                    }
                                    while(ch=='y');
                                    
                                        
                                    break;
                                }
                                case 2:
                                {
                                    cout<<"**********************************"<<endl;
                                    cout<<"-----DISPLAY ISSUED BOOKS------"<<endl;
                                    cout<<"**********************************"<<endl;
                                    cout<<"Display Issued Data "<<endl;
                    		        cout<<"-----------"<<endl;
                                   
                                    s.display();
                                  
                                    break;
                                }
                                case 3:
                                {
                                    cout<<"**********************************"<<endl;
                                    cout<<"---------SEARCH BOOK FROM ISSUED LIST----------"<<endl;
                                    cout<<"**********************************"<<endl;
                                    cout<<"Search book by bookid"<<endl;
                                  
                                    cout<<"Enter Book id"<<endl;
                                    cin.ignore();
                                    cin>>book_id;
                                    //getline(cin,book_name);
                                    s.search_bookId(book_id);
                                  
                                    break;
                                }
                                case 4:
                                {
                                   exit(0);
                                    break;
                                }
                                default:
                                {
                                    cout<<"Enter Valid Choice"<<endl;
                                    break;
                                }
                            }
                        cout<<"Do you want to continue with issued books database (Y/N)";
                        cin>>yes;
                        }
                        while(yes=='y');
                        file.close();
                        break;
                    }
                    case 5:
                    {
                        cout<<"******************************"<<endl;
                        cout<<"--------RETURN BOOK -------"<<endl;
                        cout<<"******************************"<<endl;
                     do{
                        returnBook rb;
                        rb.showdate();
                        rb.Return();
                        cout<<"Do you want to return another book (Y/N)"<<endl;
                        cin>>yes;
                       }while(yes=='y');
                        break;
                    }
                    case 6:
                    {
                        cout<<"********************************"<<endl;
                        cout<<"---------DELETE BOOK ---------"<<endl;
                        cout<<"********************************"<<endl;
                        Delete library;
                        int choice, book_id;
                        string book_name;
                     do{
                        cout<<"Delete\n1. by id\n2. by name"<<endl;
                        cin>>choice;
                        
                        switch(choice)
                    	{
                    		case 1:
                    		    cout<<"Enter Book Id To Delete "<<endl;
                    		    cout<<"------------------------"<<endl;
                    			cout<<"Enter Book ID"<<endl;
                    		    cin>>book_id;
                    		    library.delete_bookId(book_id);
                    		    break;
                    
                    		case 2:
                    		    cout<<"Enter Book Name To Delete "<<endl;
                    		    cout<<"------------------------"<<endl;
                    		    cout<<"Enter Book name"<<endl;
                    			cin.ignore();
                    			getline(cin,book_name);
                    			transform(book_name.begin(),book_name.end(),book_name.begin(), ::toupper);
                    			library.delete_bookName(book_name);
                    			break;
                    		    
                    		default:
                    			cout<<"Invalid choice"<<endl;
                    			break;
                    	}
                    	cout<<"Do you want to delete another book (Y/N)"<<endl;
                    	cin>>yes;
                     }while(yes=='y');
    
                        break;
                    }
                    
                    
                    
                    case 7:
                    {
                        
                        exit(0);
                    }
                    default:
                    {
                        cout<<"Enter Valid Choice"<<endl;
                        break;
                    }
                  
                 }
                cout<<"do u want to continue with admin option list"<<endl;
                cin>>yes;
                }while(yes=='y');
            break;
        }
        case 2:
        {
            int choice;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"--------------------------STUDENT MENU-------------------------"<<endl;
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"--------------------------Welcome To Login Page--------------"<<endl;
            cout<<"1.Login"<<endl<<"2.Registration"<<endl<<"3.If you forgot your password"<<endl<<"4.exit"<<endl;
            cout<<"Please enter your choice"<<endl;
            cin>>choice;
            Login log_in;
            switch(choice){
                case 1:log_in.login();
                       break;
                       
                case 2:log_in.registration();
                        break;
                case 3:log_in.forgot_password();
                        break;
                case 4:cout<<"\t\t\tthank you\t";
                        exit(0);
                        break;
                default:
                    cout<<"please enter valid option"<<endl;
            }
        }
        
        default:
        {
           cout<<"Enter Valid Choice"<<endl;
           break;  
        }
    }
    cout<<"do you want to continue as admin or user"<<endl;
    cin>>yes;
    }while(yes=='y');
}
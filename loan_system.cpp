#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class loaning
{
private:
    int total;
    struct person
    {
        string name, ID;
        int contact, time;
        float cash, rate;
    } 
    person[100];

public:
    loaning()
    {
        total = 0;
    }
    void lender_choice();
    void borrower_choice();
    // void choice();
    void start();
    // void signUp();
    // void login();
    void Data();
    void update();
    void search();
    void del();
    void type();
    void interest();
    void show(int n);
};
// class lending:public loaning{
// private:
//     int total;
//     struct person
//     {
//         string name, ID;
//         int contact, time;
//         float cash, rate;
//     } 
//     person[100];
// public:
//     lending(){}
//     void lender_choice();
//     void Data();
//     void update();
//     void search();
//     void del();
// };
// class borrowing:public loaning{
//     void borrower_choice();
//     void show(int n);
// };
int main(){
    loaning p;
    p.start();
}
void loaning::lender_choice(){
	char ch;
	while(true){
    cout<<"Hello"<<endl;
   	cout<<"\n\nPRESS..!!"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. Update information of existing account"<<endl;
	cout<<"3. Check the details of an existing account"<<endl;
	cout<<"4. Remove existing account"<<endl;
    cout<<"5. Lender/Borrower window"<<endl;
	cout<<"6. Exit"<<endl;

	cin>>ch;
	system("ClS");
	switch(ch){
		case '1':
			loaning::Data();
			break;
		case '2':
			loaning::update();
			break;
		case '3':
			loaning::search();
			break;
		case '4':
			loaning::del();
			break;
		case '6':
            cout<<"THANK YOU"<<endl;
			exit(0);
			break;
        case '5':
            loaning::type();
            break;
		default:
			cout<<"\aInvalid input"<<endl;
	        break;
	}
    }
}
void loaning::start(){
    system("ClS");
    cout<<"WELCOME TO"<<endl<<endl;
    char arr[]={'T','H', 'E',' ','N','E','W',' ','L','O','A','N','I','N','G',' ','S','Y','S','T','E','M'};
    for (size_t i = 0; i < 22; i++){
        cout<<arr[i];
        Sleep(30);
    }
    cout<<endl<<endl;
    loaning::type();
}
void loaning::type(){
    int n;
    while(true){
    cout<<"Please select 1 if you are a lender and 2 if you are a borrower"<<endl;
    cin>>n;
    system("ClS");
	if(n==1){
        loaning::lender_choice();
    }
    else if(n==2){
        loaning::borrower_choice();
    }
    else{
        cout<<"Invalid Input"<<endl;
        loaning::type();
    }
    }
}

void loaning::Data(){
	cout<<"\nEnter The Details"<<endl<<endl;
	cout<<"Name: ";
	cin>>person[total].name;
	cout<<"Enter userID: ";
	cin>>person[total].ID;
	cout<<"Enter Contact Number: ";
	cin>>person[total].contact;
	cout<<"Enter the amount you want to lend: ";
	cin>>person[total].cash;
    cout<<"Enter the time in years upto which you want to lend: ";
    cin>>person[total].time;
    cout<<"Enter the rate at which you want to lend: ";
    cin>>person[total].rate;
    // float rate = 1+ (person[total].rate)/100;
    // int time = person[total].time;
    // long long int ci = pow(rate,time);              //Operator overloading can be used here
    // person[total].amount = ci;
    // person[total].interest = ci - person[total].cash;     //Operator overloading can be used here
    // cout<<endl<<endl;
    // cout<<"The interest that you will get is "<<person[total].interest<<endl;
    // cout<<"The total amount will become "<<person[total].amount<<endl;
    // cout<<"Congrats! Your account has been created"<<endl;
    total++;
    loaning::interest();
}

void loaning::update(){
			string id;
			cout<<"Enter your current ID"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
				cout<<"\nPrevious data of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Cash: "<<person[i].cash<<endl;
				cout<<"Time: "<<person[i].time<<endl;
                cout<<"Rate: "<<person[i].rate<<endl;
				cout<<"\nEnter new data"<<endl<<endl;
				cout<<"Enter new Name: ";
			    cin>>person[i].name;
			    cout<<"Enter new ID: ";
			    cin>>person[i].ID;
			    cout<<"Enter new Contact: ";
			    cin>>person[i].contact;
			    cout<<"Enter the amount you want to lend: ";
	            cin>>person[total].cash;
                cout<<"Enter the time in years upto which you want to lend: ";
                cin>>person[total].time;
                cout<<"Enter the rate at which you want to lend: ";
                cin>>person[total].rate;
                // float r = 1+ (person[total].rate)/100;
                // int t = person[total].time;
                // long long int ci = pow(r,t);              //Operator overloading can be used here
                // cout<<r<<t<<ci<<endl;
                // person[total].interest = ci;
                // person[total].amount = person[total].cash + ci;     //Operator overloading can be used here
                // cout<<endl<<endl;
                // cout<<"The interest that you will get is "<<person[total].interest<<endl;
                // cout<<"The total amount will become "<<person[total].amount<<endl;
			    // cout<<endl<<endl<<"Your Data has been Successfully Updated"<<endl;
                loaning::interest();
			    break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}

		void loaning::search(){
			string id;
			cout<<"Enter ID of person for check"<<endl;
			cin>>id;
			for(int i=0;i<total;i++){
				if(id==person[i].ID){
				cout<<"\nData of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Cash: "<<person[i].cash<<endl;
				cout<<"Time: "<<person[i].time<<endl;
                cout<<"Rate: "<<person[i].rate<<endl;
                // cout<<"Interest: "<<person[i].interest<<endl;
                // cout<<"Amount: "<<person[i].amount<<endl;
				break;
				}
				if(i==total-1){
					cout<<"No such record found"<<endl;
				}
			}
		}
		void loaning::del(){
                    system("CLS");
					string id;
					cout<<"Enter id of person which you want to remove"<<endl;
					cin>>id;
					for(int i=0;i<total;i++){
						if(id==person[i].ID){
								for(int j=i;j<total;j++){
									person[j].name=person[j+1].name;
									person[j].ID=person[j+1].ID;
									person[j].contact=person[j+1].contact;
									person[j].cash=person[j+1].cash;
                                    person[j].time=person[j+1].time;
                                    person[j].rate=person[j+1].rate;
                                    // person[j].interest=person[j+1].interest;
                                    // person[j].amount=person[j+1].amount;
									total--;
									cout<<"Your desired record has been deleted"<<endl;
									break;
								}
						}
						if(i==total-1){
				         	cout<<"No such record found"<<endl;
				        }
					}
		}

void loaning::interest(){
       system("CLS");
       string id;
       cout<<"Enter your ID:"<<endl;
         cin >> id;
      for (int i = 0; i < total; i++) {
          if (id == person[i].ID) {
              cout << "Hello " << person[i].name <<"At the end you will get ";
             
              int p=person[i].cash;
              double r= person[i].rate ;
              int t= person[i].time ;
             double cal=1+r/100;
             double val=pow(cal,t);
              double amount=p*val;
              double intr=amount-p;
              cout<<"Intrest = "<<intr<<endl;
              cout<<"Amount = "<<amount<<endl;
              cout<<"Congrats! Your account has been successfully created/updated"<<endl;
            //   cout<<"Press enter to go to home page" <<endl;
            //   char c;
            //   cin>>c;
              loaning::lender_choice();
              break;
          }  
          if (i == total - 1) {
              cout << "Wrong User ID" << endl;
          }
   }
    
   }
void loaning::borrower_choice(){
	char ch;
    int bor;
    cout<<"Hello"<<endl;
   	cout<<"\n\nEnter the amount you want to borrow: "<<endl;
    cin>>bor;
	system("ClS");
    loaning::show(bor);
    loaning::type();
}

void loaning::show(int n){
    if(total==0){
        cout<<"Sorry! There are no lenders yet!";
    }
    else{
        int flag = 0;
        for(int i=0; i<total; i++){
            if(n<person[i].cash){
				cout<<"\nData of person "<<i+1<<endl;
				cout<<"Name: "<<person[i].name<<endl;
				cout<<"ID: "<<person[i].ID<<endl;
				cout<<"Contact: "<<person[i].contact<<endl;
				cout<<"Cash: "<<person[i].cash<<endl;
				cout<<"Time: "<<person[i].time<<endl;
                cout<<"Rate: "<<person[i].rate<<endl;
                flag++;
            }
        }
        if(flag==0){
            cout<<"Sorry no lender can give you this amount"<<endl;
        }
    }
}
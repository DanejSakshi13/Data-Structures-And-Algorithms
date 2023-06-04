/*There are flight paths between cities. If there is a flight betwee ncity A and city B then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a grap. The node can be represented by the city name. Use representation of graph. Check whether the graph is connected or not. Justify the storage representation used. */

//USING ADJACENCY MATRIX

#include <iostream>
  #include<bits/stdc++.h>
  #include<string.h>
  #define n 25
  using namespace std;
  class flight
  {
    public:
        int mat[n][n],visited[n];
        int num=0;
        char city[n][50];
        float time[n][n],fuel[n][n];
        flight()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]=0;
                    time[i][j]=0;
                    fuel[i][j]=0;
                }
            }
        }
        void readGraph(int );
        void showGraph(int );
        void isConnected(int);
};


void flight::readGraph(int num)
{
    int ans;
    int no=num;
    cout<<"ENTER FLIGHT DETAILS";
    cout<<"\nEnter city :\n";
    for(int i=0;i<num;i++)
    {
        cin>>city[i];
    }
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            cout<<"\nIs there route between "<<city[i]<<" & "<<city[j]<<"?(1/0) : ";
            cin>>ans;
            if(ans==1)
            {
                mat[i][j]=mat[j][i]=1;
                cout<<"Enter time taken for journey: ";
                cin>>time[i][j];
                time[j][i]=time[i][j];
                cout<<"Enter fuel required : ";
                cin>>fuel[i][j];
                fuel[j][i]=fuel[i][j];
            }
            else
            {
            	continue;
            }	
        }
    }
}
void flight::showGraph(int num){

	cout<<"\nMatrix for flight:\n";
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				cout<<mat[i][j]<<" ";
				if(j==num-1){
					cout<<"\n";
				}
			}
		}
	cout<<"\nTime matrix:\n";
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				cout<<time[i][j]<<" ";
				if(j==num-1){
					cout<<"\n";
				}
			}	
		}
	cout<<"\nFuel matrix:\n";
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				cout<<fuel[i][j]<<" ";
				if(j==num-1){
					cout<<"\n";
				}
			}
   		}
}

void flight:: isConnected(int num){
    for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
                if(mat[i][j] != 0){
                    cout<<"Flight available between "<<i<<" and "<<j<<endl;
                    cout<<"Time req: "<<time[i][j]<<" hrs"<<endl;
                    cout<<"Fuel req: "<<fuel[i][j]<<" litres"<<endl;
                }
                // else{
                //     cout<<"Flight not available between "<<i<<"and "<<j<<endl;
                // }
            }
    }
}

int main(){
    flight f1;
    int num;
    char ch,ct[20];

int choice;
do {
    cout << "\n------MENU------\n";
    cout << "1. Enter flight details\n";
    cout << "2. Show flight details\n";
    cout << "3. See connected flights\n";
    
    cout << "4. Exit\n";
    
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
           cout<<"\nEnter No Of Cities You Want Add: \n";
            cin>>num;
            f1.readGraph(num);
            break;
        }

        case 2: {
            f1.showGraph(num);
            break;
        }

        case 3: {
            f1.isConnected(num);
            break;
        }
        default: {
            cout << "Invalid choice! Try again." << endl;
        }
    }
} while (choice != 4);

return 0;

}

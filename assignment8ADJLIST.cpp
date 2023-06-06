/*There are flight paths between cities. If there is a flight betwee ncity A and city B
 then there is an edge between the cities. The cost of the edge can be the time that
  flight takes to reach city B from A, or the amount of fuel used for the journey.
   Represent this as a grap. The node can be represented by the city name. 
   Use representation of graph. Check whether the graph is connected or not.
    Justify the storage representation used. */

//USING ADJACENCY LIST
#include <iostream>
using namespace std;
const int maxCT = 10;


struct edge{
int dest;
int cost;
int distance;
edge* next;
};

edge* adjL[maxCT];
string cities[maxCT];
int numCities = 0;

class flight{	
	public:
	int getCityIndex(string); 
	void addCity();
	void addFlight();
	void displayList();
	bool isConnected();
};

int flight :: getCityIndex(string city){
	for (int i = 0; i < numCities; i++) {
       		if (cities[i] == city) {
           		return i;
           	}
        }
   	return -1;
}

void flight :: addCity(){
	string city;
	cout<<"Enter the name of the city :";
	cin>>city;
	if(getCityIndex(city)!=-1){cout<<"City already exists"; return;}
	cities[numCities] = city;
	numCities++;	
}

void flight :: addFlight(){
	string src, dest;
	int cost,distance;

	cout<<"Enter src city:";
	cin >> src;
	int srcIndex = getCityIndex(src);
        if (srcIndex == -1) {
        cout << "Source city not found.\n";
        return;
	}

	cout<<"Enter dest city:";
	cin >> dest;
	int destIndex = getCityIndex(dest);
	if(destIndex == -1){
	cout<< "Desination city not found/\n";
	return;
	}

	cout<<"Enter cost of flight:";
	cin>>cost;
	
	cout<<"Enter distance btwn both flight:";
	cin>>distance;

    	edge* newEdge = new edge;
	newEdge->dest = destIndex;
   	newEdge->cost = cost;
	newEdge->distance = distance;
        newEdge->next = adjL[srcIndex];
        adjL[srcIndex] = newEdge;
}

void flight :: displayList(){
	cout<<"\nFORMAT\nSRC->destination[cost][distance]"<<endl;;
	for (int i = 0; i < numCities; i++) {
        cout << cities[i] << " ";
        edge* curr = adjL[i];
        while (curr != NULL) {
	
            cout <<"-> "<< cities[curr->dest] <<"("<< curr->cost <<")"<<"("<< curr->distance <<")";
            curr = curr->next;
        }
        cout << endl;
    }
}

bool flight :: isConnected(){
bool visited[maxCT];
    int numVisited = 0;
    visited[0] = true;
    numVisited++;
    for (edge* curr = adjL[0]; curr != NULL; curr = curr->next) {
        if (!visited[curr->dest]) {
            visited[curr->dest] = true;
            numVisited++;
        }
    }
    while (numVisited < numCities) {
        bool foundNew = false;
        for (int i = 0; i < numCities; i++) {
            if (visited[i]) {
                for (edge* curr = adjL[i]; curr != NULL; curr = curr->next) {
                    if (!visited[curr->dest]) {
                        visited[curr->dest] = true;
                        numVisited++;
                        foundNew = true;
                    }
                }
            }
        }
        if (!foundNew) {
            return false;
        }
    }
    return true;
}


int main(){
    flight f1;
    int num;
    char ch,ct[20];

int choice;
do {
    cout << "\n------MENU------\n";
    cout << "1. Add city\n";
    cout << "2. Add flight\n";
    cout << "3. Display list\n";
    cout << "4. Flight availability\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
           f1.addCity();
            break;
        }

        case 2: {
            f1.addFlight();
            break;
        }

        case 3: {
            f1.displayList();
            break;
        }
	
	case 4: {
	    if (f1.isConnected()) {
                cout << "Graph is connected.\n";
            } else {
                cout << "Graph is not connected.\n";
            }
            break;	
	}

	case 5: {
		cout<<"Exit.";
		break;
	}

        default: {
            cout << "Invalid choice! Try again." << endl;
        }
    }
} while (choice != 5);

return 0;

}

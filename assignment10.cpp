/*Read the marks obtained by students for second year in an online examination of a particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.*/

#include <iostream>
using namespace std;

// A heap data structure
struct Heap {
  int* data;                                    //a dynamic array to store the heap elements
  int size;

  Heap(int capacity) {                          // constructor 
    data = new int[capacity];                   //initializes the data array with a given capacity 					
    size = 0;                                   //sets the size to 0.
  }

  void push(int value) {
    data[size++] = value;                       //adds a new element to the heap by inserting it at the next available index
    heapifyUp(size - 1);                        // calling the heapifyUp function to maintain the heap property.
  }

  int pop() { 
    int maxValue = data[0];                      //function removes and returns the maximum element from the heap (which is always the root element)
    data[0] = data[--size];                       //replaces the root with the last element in the array , reduces the size of the heap,
    heapifyDown(0);
    return maxValue;
  }

  void heapifyUp(int index) {                     //called after inserting a new element to move it up the heap if necessary,
    while (index > 0 && data[index] > data[(index - 1) / 2]) {
      swap(data[index], data[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

void heapifyDown(int index) {
  int leftChild = 2 * index + 1;
  int rightChild = 2 * index + 2;
  int smallest = index;  // Change variable name from "largest" to "smallest"

  if (leftChild < size && data[leftChild] < data[smallest]) {  // Use '<' instead of '>'
    smallest = leftChild;
  }

  if (rightChild < size && data[rightChild] < data[smallest]) {  // Use '<' instead of '>'
    smallest = rightChild;
  }

  if (smallest != index) {
    swap(data[index], data[smallest]);
    heapifyDown(smallest);
  }
}

};

int main() {
  int n;
  cout<<"\nEnter number of elements:";
  cin >> n;

  // Create a heap to store the marks
  Heap heap(n);

  // Read the marks and push them into the heap
  cout<<"\nEnter marks:";
  for (int i = 0; i < n; i++) {
    int mark;
    cin >> mark;
    heap.push(mark);
  }

  // Get the maximum and minimum marks
  int maxMark = heap.pop();
  int minMark = heap.pop();

  // Print the maximum and minimum marks
  cout << "Maximum mark: " << maxMark << endl;
  cout << "Minimum mark: " << minMark << endl;

  return 0;
}

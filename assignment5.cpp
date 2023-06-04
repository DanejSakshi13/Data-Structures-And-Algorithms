/*Construct an expression tree from the given prefix expression eg:+-a*bc/def and traverse it using post order traversal (non recursive) 
and then delete the entire tree.*/

 #include <iostream>
#include <cstring>
using namespace std;

// Expression tree node
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

// Function to construct an expression tree from a prefix expression
Node* constructTree(string prefix) {                    //takes prefix exp as input
    int n = prefix.length();
    Node* stack[n];
    int top = -1;
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c) || isalpha(c)) {             //if char push push onto stack
            stack[++top] = new Node(c);
        } 
        else {
            Node* left = stack[top--];               //if operator pop two nodes from stack
            Node* right = stack[top--];
            Node* newNode = new Node(c);               //new internal node
            newNode->left = left;
            newNode->right = right;
            stack[++top] = newNode;
        }
    }
    return stack[top];
}

// Function to traverse the expression tree in post-order (non-recursive)
void postorder(Node* root) {                              //(left-right-root)
    Node* stack1[100];
    int top1 = -1;
    Node* stack2[100];
    int top2 = -1;
    stack1[++top1] = root;                               //push root node on stack1     
    while (top1 >= 0) {
        Node* curr = stack1[top1--];                     
        stack2[++top2] = curr;                          
        if (curr->left) stack1[++top1] = curr->left;
        if (curr->right) stack1[++top1] = curr->right;
    }                                                              //pop node from stack1 and push on stack2
    while (top2 >= 0) {
        Node* curr = stack2[top2--];
        cout << curr->data << " ";
        delete curr;                      //delete each node to free up memory allocated for the tree
    }
}

int main() {
   string prefix;

    cout << "Enter the prefix expression: ";
    getline(cin, prefix);

    Node* root = constructTree(prefix);
    postorder(root);
    cout << endl;
    return 0;
}

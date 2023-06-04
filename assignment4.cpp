/*Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
vi. Search a value*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) : data(data), left(NULL), right(NULL) {}
};

class t{
    public:
    Node* root;
    t(){
        root=NULL;
    }
    void insertNode(Node*& , int );
    int findHeight(Node* );
    int findMin(Node* );
    bool search(Node* , int );
    void postOrder(Node* ) ;
    void preOrder(Node* ) ;
    void inOrder(Node* ) ;
};

// User-defined stack
struct StackNode {
    Node* node;
    StackNode* next;
    StackNode(Node* node) : node(node), next(NULL) {}
};

class Stack {
private:
    StackNode* top;
public:
    Stack() : top(NULL) {}
    bool isEmpty();
    void push(Node* node);
    Node* pop();
};

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack::push(Node* node) {
    StackNode* newNode = new StackNode(node);
    newNode->next = top;
    top = newNode;
}

Node* Stack::pop() {
    if (isEmpty()) {
        return NULL;
    }

    Node* node = top->node;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return node;
}

// Insert a new node
void t :: insertNode(Node*& root, int data) {
    Node* newNode = new Node(data);

    if (root == NULL) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Find the number of nodes in the longest path
int t :: findHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Find the minimum data value
int t :: findMin(Node* root) {
    if (root == NULL) {
        return -1;
    }

    Node* current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current->data;
}

// Search for a value
bool t :: search(Node* root, int data) {
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Non-recursive post-order traversal
void t :: postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    Stack stack1, stack2;
    stack1.push(root);

    while (!stack1.isEmpty()) {
        Node* node = stack1.pop();
        stack2.push(node);

        if (node->left != NULL) {
            stack1.push(node->left);
        }

        if (node->right != NULL) {
            stack1.push(node->right);
        }
    }

    while (!stack2.isEmpty()) {
        Node* node = stack2.pop();
        cout << node->data << " ";
    }

    cout << endl;
}

// Non-recursive in-order traversal
void t :: inOrder(Node* root) {
if (root == NULL) {
return;
}
Stack stack;
Node* current = root;

while (current != NULL || !stack.isEmpty()) {
    while (current != NULL) {
        stack.push(current);
        current = current->left;
    }

    current = stack.pop();
    cout << current->data << " ";
    current = current->right;
}
cout << endl;
}


// Non-recursive pre-order traversal
void t :: preOrder(Node* root) {
if (root == NULL) {
return;
}
Stack stack;
stack.push(root);

while (!stack.isEmpty()) {
    Node* node = stack.pop();
    cout << node->data << " ";

    if (node->right != NULL) {
        stack.push(node->right);
    }

    if (node->left != NULL) {
        stack.push(node->left);
    }
}

cout << endl;

}


// Main function
int main() {
    t obj;
Node* root = NULL;
int choice;
do {
    cout << "\n------MENU------\n";
    cout << "1. Insert a new node\n";
    cout << "2. Find the number of nodes in the longest path\n";
    cout << "3. Find the minimum data value\n";
    cout << "4. Search for a value\n";
    cout << "5. Non-recursive post-order traversal\n";
    cout << "6. Non-recursive in-order traversal\n";
    cout << "7. Non-recursive pre-order traversal\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int data;
            cout << "Enter the data to be inserted: ";
            cin >> data;
            obj.insertNode(root, data);
            break;
        }

        case 2: {
            int height = obj.findHeight(root);
            cout << "The number of nodes in the longest path is: " << height << endl;
            break;
        }

        case 3: {
            int min = obj.findMin(root);
            if (min == -1) {
                cout << "The tree is empty!" << endl;
            } else {
                cout << "The minimum data value is: " << min << endl;
            }
            break;
        }

        case 4: {
            int data;
            cout << "Enter the data to be searched: ";
            cin >> data;
            bool found = obj.search(root, data);
            if (found) {
                cout << "The data is present in the tree!" << endl;
            } else {
                cout << "The data is not present in the tree!" << endl;
            }
            break;
        }

        case 5: {
            cout << "Non-recursive post-order traversal: ";
            obj.postOrder(root);
            break;
        }

        case 6: {
            cout << "Non-recursive in-order traversal: ";
            obj.inOrder(root);
            break;
        }

        case 7: {
            cout << "Non-recursive pre-order traversal: ";
            obj.preOrder(root);
            break;
        }

        case 8: {
            cout << "Exiting...";
            break;
        }

        default: {
            cout << "Invalid choice! Try again." << endl;
        }
    }
} while (choice != 8);

return 0;

}

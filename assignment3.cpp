/*Implement all the functions of a dictionary (ADT) using hashing. Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique Standard Operations: Insert(key, value), Find(key), Delete(key)*/

#include <iostream>
#include <string.h>
#define MAX 26
#define limit 30
using namespace std;
class node
{
    public:
        char word[limit], meaning[limit];
        node *next;
};
class hashtable
{
    node *table[MAX];
    int pos;

public:
    hashtable()
    {
        for (int i = 0; i < MAX; i++)
        {
            table[i] = new node;
            table[i] = NULL;
        }
    }
    void display();
    void create();
    void insert(node *);
    int hash(char[]);
    void del(char[]);
    void search(char[]);
    void deleteAll();
};
void hashtable::deleteAll(){
    for (int i = 0; i < MAX; i++)
        {
            table[i] = NULL;
        }
}
void hashtable::display()
{
    node *temp;
    cout << "\nLetter :\t\tWord\t\tMeaning" << endl;
    for (int i = 0; i < MAX; i++)
    {
        temp = table[i];
        cout << char(i + 65) << " :\t\t ";
        if (table[i] == NULL)
        {
            cout << "";
        }
        else
        {
            while (temp->next != NULL)
            {
                cout << temp->word << " : " << temp->meaning << "->";
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
                cout << temp->word << " : " << temp->meaning << "->";
            }
        }
        cout << endl;
    }
}
void hashtable::create()
{
    node *New;
    New = new node;
    cout << "ENTER WORD : ";
    cin >> New->word;
    cin.ignore();
    cout << "ENTER MEANING : ";
    cin.getline(New->meaning,30);
    New->next = NULL;
    insert(New);
}
int hashtable::hash(char word[limit])
{
    return (toupper(word[0]) - 65);
}
void hashtable::insert(node *New)
{
    pos = hash(New->word);
    node *temp;
    temp = table[pos];
    if (table[pos] == NULL)
    {
        table[pos] = New;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New;
    }
}
void hashtable::del(char word[])
{
    int count;
    count = 0;
    pos = hash(word);
    node *temp, *prev;
    temp = table[pos];
    if (table[pos] == NULL)
    {
        cout << "No Such Element Is Found" << endl;
    }
    else
    {
        if (strcmp(temp->word, word) == 0)
        {
            if (temp->next == NULL)
            {
                table[pos] = NULL;
            }
            else
            {
                table[pos] = temp->next;
            }
        }
        else
        {
            while (temp != NULL)
            {
                prev = temp;
                temp = temp->next;
                if (strcmp(temp->word, word) == 0)
                {
                    prev->next = temp->next;
                    break;
                }
                else
                {
                    count = -1;
                }
            }
            if (temp == NULL)
            {
                count = -1;
            }
        }
        if (count == -1)
        {
            cout << "No Such Element Is Found" << endl;
        }
        else
        {
            cout << word << "  Is Deleted!!!" << endl;
        }
    }
}
void hashtable::search(char word[])
{
    pos = hash(word);
    node *temp;
    temp = table[pos];

    if (table[pos] == NULL)
    {
        cout << "NO RESULTS FOUND";
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->word, word) == 0)
            {
                cout << "Meaning of " << word << " is:" << temp->meaning << endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp == NULL)
        {
            cout << "Word Not Found In Dictionary" << endl;
        }
    }
}
int main()
{
    hashtable linkl;
    char key[limit];
    int ch;
    do
    {
        cout << "\n----------------DICTIONARY OPERATIONS----------------------------" << endl;
        cout << "\n 1.Insert \n 2.Display\n 3.Delete \n 4.Search" << endl;
        cout << "Enter Your Choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            linkl.create();
            break;
        case 2:
            linkl.display();
            break;
        case 3:
            cout << "Enter Word To Delete : " << endl;
            cin >> key;
            linkl.del(key);
            break;
        case 4:
            cout << "Enter Word To Search : " << endl;
            cin >> key;
            linkl.search(key);
            break;
        default:
            cout << "Invalid Choice!!!" << endl;
            break;
        }
    } while (ch>0&&ch<5);
    return 0;
}

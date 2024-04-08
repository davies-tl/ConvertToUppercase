/*
Program name: ConvertToUppercase.cpp
Programmer: Tyler Davies
Date: 12-5-21
Version: 1.0
Description: This program contains a class called CharacterQueue, which is a dynamic queue that
             holds the characters of a string. The main program tests the CharacterQueue; prompting
             the user for a sentence, and inserting its characters into the queue. Afterwhich, it
             dequeues the characters, converting them to uppercase, and printing the results.
*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//The CharacterQueue class makes use of a linked list, and has a structure named QueueNode that
//holds a character and a pointer to the next node. The class also has pointers to the front and
//rear nodes, and an integer to hold the number of items in the queue.
class CharacterQueue
{
private:
    struct QueueNode
    {
        char character;
        QueueNode *next;
    };
    QueueNode *front, *rear;
    int numItems;
public:
    CharacterQueue();
    void enqueue(char);
    void dequeue(char &);
    bool isEmpty() const;
    void clear();
    ~CharacterQueue()    //Destructor
        { clear(); }
};

//Constructor
CharacterQueue::CharacterQueue()
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

//The enqueue function inserts a character at the rear of the CharacterQueue.
void CharacterQueue::enqueue(char c)
{
    QueueNode *newNode;
    newNode = new QueueNode;
    newNode->character = c;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    numItems += 1;
}

//The dequeue function removes a character from the front of the CharacterQueue.
void CharacterQueue::dequeue(char &c)
{
    QueueNode *temp;

    if (isEmpty())
        cout << left << "The are no characters in the queue. \nThe queue is empty!\n";
    else
    {
        c = front->character;
        temp = front;
        front = front->next;
        delete temp;
        numItems -= 1;
    }
}

//The isEmpty function returns true is the CharacterQueue is empty; otherwise, it returns false.
bool CharacterQueue::isEmpty() const
{
    if (numItems > 0)
        return false;
    else
        return true;
}

//The clear function clears the linked list. It is called by the destructor.
void CharacterQueue::clear()
{
    char c;
    while (!isEmpty())
        dequeue(c);
}

//The main function acts as a driver program.
int main()
{
    CharacterQueue queue;
    string sentence;
    char character;
    int i, numChar;

    cout << left << "Please enter a sentence:\n";
    getline(cin, sentence);
    if (sentence.empty())
    {
        cout << setw(7) << "Error: Nothing was entered.\n";
        cout << setw(7) << " " << "Program will now terminate!\n";
        exit(0);
    }
    else
        numChar = size(sentence);

    for (i = 0; i < numChar; i++)
        queue.enqueue(sentence[i]);

    sentence.clear();    //Clears sentence, getting it ready to add the dequeued characters. 

    for (i = 0; i < numChar; i++)
    {
        queue.dequeue(character);
        sentence.push_back(toupper(character));
    }

    cout << "\nUppercase:\n" << sentence << endl;

    exit(0);
}
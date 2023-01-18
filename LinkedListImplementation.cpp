#include <iostream>
using namespace std;

// Node class. Each node has four fields: row, column, value, and next node.
class Node
{
public:
    int row;
    int column;
    int value;
    Node *nextNode;
};

int main()
{
    // Store sparse matrix given into 2D array for testing
    int sparseMatrix[4][5] =
        {{0, 0, 3, 0, 4},
         {0, 0, 5, 7, 0},
         {0, 0, 0, 0, 0},
         {0, 2, 6, 0, 0}};

    // Create Linked List Implementation for Sparse Matrix
    Node *list = NULL;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (sparseMatrix[x][y] != 0)
            {
                Node *tempNode = list;
                Node *newNode;

                // If the linked list is empty
                if (list == NULL)
                {
                    tempNode = new Node();
                    tempNode->row = x;
                    tempNode->column = y;
                    tempNode->value = sparseMatrix[x][y];
                    tempNode->nextNode = NULL;
                    list = tempNode;
                }

                // The linked list is not empty
                else
                {
                    // Traverse to end of list
                    while (tempNode->nextNode != NULL)
                    {
                        tempNode = tempNode->nextNode;
                    }
                    // Add new node to end of list
                    newNode = new Node();
                    newNode->row = x;
                    newNode->column = y;
                    newNode->value = sparseMatrix[x][y];
                    newNode->nextNode = NULL;
                    tempNode->nextNode = newNode;
                }
            }
        }
    }
    // Testing the Linked List Implementation for Sparse Matrix
    while (list->nextNode != NULL)
    {
        cout << list->row << " " << list->column << " " << list->value << endl;
        list = list->nextNode;
    }
    cout << list->row << " " << list->column << " " << list->value << endl;
}
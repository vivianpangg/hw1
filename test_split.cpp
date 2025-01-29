/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
struct Node {
    int value;
    Node *next;
};

int main(int argc, char* argv[])
{
  Node* head = new Node(1);
  head->next = new Node(4);
  head->next->next = new Node(3);
  head->next->next->next = new Node(2);

  Node* oddsHead = nullptr;
  Node* evenshead = nullptr;

  split(head, oddsHead, evensHead);

}

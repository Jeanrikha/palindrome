#ifndef PALINDROME_H_INCLUDED
#define PALINDROME_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
#define top(p) (p).top      // stack
#define infoS(p) (p).infoS
#define infoQ(p) (p)->infoQ // queue
#define next(p) (p)->next
#define head(p) ((p).head)
#define tail(p) ((p).tail)

// stack
typedef char infotypeS;

struct stack{
    infotypeS infoS[20];
    int top;
};

// queue
typedef struct elmQ *adrQ;

typedef string infotypeQ;

struct elmQ {
    infotypeQ infoQ;
    adrQ next;
};

struct queue {
    adrQ head, tail;
};

// primitif stack
void createStack(stack &s);
bool isEmptyStack(stack s);
bool isFullStack(stack s);
void push(stack &s, infotypeS x);
infotypeS pop(stack &s);
void printStack(stack s);
infotypeS popAll(stack &s);

// primitif queue
void createQueue(queue &q);
void createElmQ(infotypeQ x, adrQ &pKata);
void enqueue(queue &q, adrQ pKata);
void dequeue(queue &q, adrQ &pKata);
void printQueue(queue q);
void cekAllQueue(queue q, stack &s);

// cek apakah termasuk palindrome
bool isPalindrome(stack &s);

#endif // PALINDROME_H_INCLUDED

#ifndef PREF_H_INCLUDED
#define PREF_H_INCLUDED

#include <math.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define Top(S) (S).top
#define infoStack(S) (S).info
#define head(Q) (Q).head
#define tail(Q) (Q).tail
#define infoQueue(Q) (Q) -> info
#define next(Q) (Q) -> next
#define nil NULL

typedef struct elmQueue *adrQ;

struct StackChar{
    int top;
    char info[100];
};
struct StackInt{
    int top;
    double info[100];
};
struct elmQueue{
    string info;
    adrQ next;
};
struct Queue{
    adrQ head;
    adrQ tail;
};

void createStackChar(StackChar &S);
void createStackInt(StackInt &S);
void createQueue(Queue &Q);
adrQ alokasiElemenQueue(string x);

bool isEmptyStackChar(StackChar S);
bool isEmptyStackInt(StackInt S);
bool isEmptyQueue(Queue Q);

void PushChar(StackChar &S, char x);
char PopChar(StackChar &S);
void PushFloat(StackInt &S, double x);
double PopInt(StackInt &S);
void Enqueue(Queue &Q, string x);
string Dequeue(Queue &Q);

bool isOperator(char x);
int precedence(char x);
string infixToPrefix(string infix);
double calculatePrefix(string prefix);
int selectMenu ();

#endif // PREF_H_INCLUDED

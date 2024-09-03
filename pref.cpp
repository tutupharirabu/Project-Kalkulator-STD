#include "pref.h"

void createStackChar(StackChar &S){
    Top(S) = -1;
}
void createStackInt(StackInt &S){
    Top(S) = -1;
}
void createQueue(Queue &Q){
    head(Q) = nil;
    tail(Q) = nil;
}
adrQ alokasiElemenQueue(string x){
    adrQ Q = new elmQueue;
    infoQueue(Q) = x;
    next(Q) = nil;
    return Q;
}
bool isEmptyStackChar(StackChar S){
    return Top(S) == -1;
}
bool isEmptyStackInt(StackInt S){
    return Top(S) == -1;
}
bool isEmptyQueue(Queue Q){
    return head(Q) == nil;
}
void PushChar(StackChar &S, char x){
    if(Top(S) == 99){
        cout << "Stack penuh" << endl;
    }else{
        Top(S)++;
        infoStack(S)[Top(S)] = x;
    }
}
char PopChar(StackChar &S){
    if(isEmptyStackChar(S)){
        cout << "Stack kosong" << endl;
        return ' ';
    }else{
        char x = infoStack(S)[Top(S)];
        Top(S)--;
        return x;
    }
}
void PushFloat(StackInt &S, double x){
    if(Top(S) == 99){
        cout << "Stack penuh" << endl;
    }else{
        Top(S)++;
        infoStack(S)[Top(S)] = x;
    }
}
double PopFloat(StackInt &S){
    if(isEmptyStackInt(S)){
        cout << "Stack kosong" << endl;
        return 0;
    }else{
        double x = infoStack(S)[Top(S)];
        Top(S)--;
        return x;
    }
}
void Enqueue(Queue &Q, string x){
    adrQ Qnew = alokasiElemenQueue(x);
    if(isEmptyQueue(Q)){
        head(Q) = Qnew;
        tail(Q) = Qnew;
    }else{
        next(tail(Q)) = Qnew;
        tail(Q) = Qnew;
    }
}
string Dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return " ";
    }else{
        string x = infoQueue(head(Q));
        head(Q) = next(head(Q));
        return x;
    }
}
bool isOperator(char x){
    // % untuk operasi mod
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')' || x == '%';
}
int precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }else if(x == '*' || x == '/' || x == '%'){
        return 2;
    }else if(x == '^'){
        return 3;
    }else{
        return 0;
    }
}
string infixToPrefix(string infix){
    // Prefix adalah operator diletakkan di sebelah kiri operand, sehingga kita perlu membalikkan infix menjadi postfix, lalu membalikkan postfix tersebut menjadi prefix
    StackChar S;
    createStackChar(S);
    Queue Q;
    createQueue(Q);
    string prefix = "";
    for(int i = infix.length() - 1; i >= 0; i--){
        if(infix[i] == ' '){
            continue;
        }else if(isdigit(infix[i])){
            string temp = "";
            while(i >= 0 && isdigit(infix[i]) || infix[i] == '.'){
                temp = infix[i] + temp;
                i--;
            }
            i++;
            Enqueue(Q, temp);
        }else if(isOperator(infix[i])){

            if(isEmptyStackChar(S)){
                PushChar(S, infix[i]);
            }else{
                if(infix[i] == ')'){
                    PushChar(S, infix[i]);
                }else if(infix[i] == '('){
                    while(infoStack(S)[Top(S)] != ')'){
                        Enqueue(Q, string(1, PopChar(S)));
                    }
                    PopChar(S);
                }else{
                    if(precedence(infix[i]) > precedence(infoStack(S)[Top(S)])){
                        PushChar(S, infix[i]);
                    }else{
                        while(!isEmptyStackChar(S) && precedence(infix[i]) <= precedence(infoStack(S)[Top(S)])){
                            Enqueue(Q, string(1, PopChar(S)));
                        }
                        PushChar(S, infix[i]);
                    }
                }
            }
        }
    }
    while(!isEmptyStackChar(S)){
        Enqueue(Q, string(1, PopChar(S)));
    }
    while(!isEmptyQueue(Q)){
        prefix = Dequeue(Q) + " " + prefix;
    }
    return prefix;
}
double calculatePrefix(string prefix){
    // Prefix adalah operator diletakkan di sebelah kiri operand, cara menghitungnya adalah kita membaca dari kanan ke kiri
    StackInt S;
    createStackInt(S);
    Queue Q;
    createQueue(Q);
    for(int i = prefix.length() - 1; i >= 0; i--){
        if(prefix[i] == ' '){
            continue;
        }else if(isdigit(prefix[i]) || prefix[i] == '.'){
            string temp = "";
            while(i >= 0 && isdigit(prefix[i]) || prefix[i] == '.'){
                temp = prefix[i] + temp;
                i--;
            }
            i++;
            PushFloat(S, stod(temp)); // ubah angka dalam string menjadi angka dalam double / float
        }else if(isOperator(prefix[i])){
            double x = PopFloat(S);
            double y = PopFloat(S);
            if(prefix[i] == '+'){
                PushFloat(S, x + y);
            }else if(prefix[i] == '-'){
                PushFloat(S, x - y);
            }else if(prefix[i] == '*'){
                PushFloat(S, x * y);
            }else if(prefix[i] == '/'){
                PushFloat(S, ((1.0 * x) / y));
            }else if(prefix[i] == '^'){
                PushFloat(S, pow(x, y));
            }else if(prefix[i] == '%'){
                PushFloat(S, fmod(x, y));
            }
        }
    }
    return PopFloat(S);
}
int selectMenu() {

    cout << "\t===== MENU =====" << endl << endl;
    cout << "1. Isikan Ekspresi Infix" << endl;
    cout << "2. Tampilkan Ekspresi Prefix" << endl;
    cout << "3. Menampilkan Hasil Kalkulator" << endl;
    cout << "0. Exit" << endl << endl;

    int input = 0;
    cout << "Masukkan Menu Yang Diinginkan : "; cin >> input; cout << endl;

    return input;
}

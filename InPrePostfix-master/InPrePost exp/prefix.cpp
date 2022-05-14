#include <bits/stdc++.h> 
using namespace std; 
  
bool isOperand(char c) 
{ 
    // If the character is a digit then it must 
    // be an operand 
    return isdigit(c); 
} 
  
double evaluatePrefix(string exprsn) 
{ 
    stack<double> Stack; 
  
    for (int j = exprsn.size() - 1; j >= 0; j--) { 
  
        // Push operand to Stack 
        // To convert exprsn[j] to digit subtract 
        // '0' from exprsn[j]. 
        if (isOperand(exprsn[j])) 
            Stack.push(exprsn[j] - '0'); 
  
        else { 
  
            // Operator encountered 
            // Pop two elements from Stack 
            double o1 = Stack.top(); 
            Stack.pop(); 
            double o2 = Stack.top(); 
            Stack.pop(); 
  
            // Use switch case to operate on o1 
            // and o2 and perform o1 O o2. 
            switch (exprsn[j]) { 
            case '+': 
                Stack.push(o1 + o2); 
                break; 
            case '-': 
                Stack.push(o1 - o2); 
                break; 
            case '*': 
                Stack.push(o1 * o2); 
                break; 
            case '/': 
                Stack.push(o1 / o2); 
                break; 
            } 
        } 
    } 
  
    return Stack.top(); 
} 
  
 
int main() 
{ 
    string exprsn;
	getline(cin,exprsn) ;
    cout <<"prefix evaluation: "<<evaluatePrefix(exprsn) << endl; 
    return 0; 
} 
/*Program by Abhishek Prakash*/
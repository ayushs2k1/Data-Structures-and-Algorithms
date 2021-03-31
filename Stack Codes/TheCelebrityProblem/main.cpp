/*
Approach:

--> If A knows B, then A can’t be a celebrity. Discard A, 
    and B may be celebrity.

--> If A doesn’t know B, then B can’t be a celebrity. 
    Discard B, and A may be celebrity. Repeat above two 
    steps till there is only one person. Ensure the remained
    person is a celebrity. (What is the need of this step?)

Algorithm: 

1.) Create a stack and push all the id’s in the stack.
2.) Run a loop while there are more than 1 element in the 
    stack.
3.) Pop top two element from the stack (represent them as 
    A and B)
4.) If A knows B, then A can’t be a celebrity and push B 
    in stack. Else if A doesn’t know B, then B can’t be a 
    celebrity push A in stack.
5.) Assign the remaining element in the stack as the 
    celebrity.
6.) Run a loop from 0 to n-1 and find the count of persons 
    who knows the celebrity and the number of people whom 
    the celebrity knows. if the count of persons who knows 
    the celebrity is n-1 and the count of people whom the 
    celebrity knows is 0 then return the id of celebrity 
    else return -1.

*/

#include<bits/stdc++.h>
#include<list>
using namespace std;

//Max number of persons in the party
#define N 8

bool MATRIX[N][N]={{0,0,1,0},
                   {0,0,1,0},
                   {0,0,0,0},
                   {0,0,1,0}};

bool knows(int a, int b){
    return MATRIX[a][b];
}

int findCelebrity(int n){
    stack<int> s;
    
    //Celebrity
    int C;

    for(int i=0;i<n;i++){
        s.push(i);
    }

    //Extract top 2
    int A=s.top();
    s.pop();
    int B=s.top();
    s.pop();

    //Find potential celebrity
    while(s.size() > 1){
        if(knows(A,B)){
            A=s.top();
            s.pop();
        }
        else{
            B=s.top();
            s.pop();
        }
    }

    //If there are only two people and no potential celebrity
    if(s.empty()){
        return -1;
    }

    //Potential celebrity?
    C=s.top();
    s.pop();

    /*
    Last Candidiate was not examined, it leads one excess
    comparison
    */

    if(knows(C,B)){
        C=B;
    }
    if(knows(C,A)){
        C=A;
    }

    for(int i=0;i<n;i++){
        /*
        If any person doesn't know 'C' or 'C' doesn't know
        any person, return -1 
        */
        if((i!=C) && (knows(C,i) || !knows(i,C))){
            return -1;
        }
    }
    return C;
}

int main(){
    int n=4;
    int id=findCelebrity(n);
    id == -1 ? cout<<"No Celebrity" :
               cout<<"Celebrity ID: "<<id<<endl;
    return 0;
}
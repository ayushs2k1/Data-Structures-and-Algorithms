#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n){
    //Create an empty stack to hold the indices of hist[] array
    //The bars stored in the stack is always in the increasing order of their heights

    stack<int> s;

    int max_area=0;
    int tp;  //To store the top of the stack
    int area_with_top;   //To store the area with top bar as the smallest bar

    //Run through all bars of the histogram
    int i=0;
    while(i<n){
        if(s.empty() || hist[s.top()]<=hist[i]){
            //If this bar is higher than the bar on the top of the stack, push it to the stack
            s.push(i);
            i++;
        }
        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else{
            tp=s.top();
            s.pop();
            area_with_top=hist[tp]*(s.empty()? i:i-s.top()-1);

            if(max_area<area_with_top){
                max_area=area_with_top;
            }
        }
    }
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i :
                                i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}


int main(){
    int hist[]={6,2,5,4,5,1,6};
    int n=sizeof(hist)/sizeof(hist[0]);
    cout<<"Maximum Area is: "<< getMaxArea(hist,n);
    return 0;
}
//Tyler Evans
//programing for fun project
//it was made to help explain my skillset
//thanks to think geek for helping with this project
//it is largly a copy of the origianal code
//however I added a function that gets the highest and the lowest that I did on my own
//There is a diffrence in using the swap function
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
//here these functions get the least and greatest in vector array
int getMax(vector<int> x);
//gets the most in the vector
int getMin(vector<int> x);
//gets the least in the vector
//here is some stuct work
void swap(vector<int> a, vector<int> b);
//this swaps vector items
int piv(vector<int> a, int low, int high);
//here this is the comparison
void QuickSort(vector<int>& _a, int low, int high);
//this is the decding order of the function
void QuickSortDec(vector<int>& _a, int low, int high);
//does the exsact same thing as the other but in reverse.
int pivDec(vector<int>& _a, int low, int high);
//made for doing a pivot that does the opposite.
void printall(vector<int> a);
//prints all the things
struct point{
    //random points some practice
    float x = 0;
    float y = 0;
    //here are the itl
    point(int a, int b){
        x = a;
        y = b;
    }
    //here are the getter functions
    //gets the x float
    float getx(){
        return x;
    }
    //gets the y float
    float gety(){
        return y;
    }
};
int main(){
    //this is a list
    //for testing
    vector<int> list ={55, 38, 75, 99, 100, 500, 1};
    cout << "Hello This is a quick sort example" << endl;
    cout << "it is based of the Think geeks Exsample" << endl;
    cout << "The link to the website is https://www.geeksforgeeks.org/quick-sort/" << endl;
    cout << "Thank you, Tyler Evans..." << endl;
    cout << "here is the max value" << endl;
    cout << getMax(list) << endl;
    cout << "Here is the min value" << endl;
    cout << getMin(list) << endl;
    //cout << endl;
    //this sets the value up
    point value(5,3);
    //prints out the values passed into the stuct
    cout << "printing out x, y value " << endl;
    cout << value.getx() << "\t";
    cout << value.gety();
    cout << endl;
    //here is the quick sort algor.
    int high  = int(list.size());
    int low = 0;
    cout << "This is the list that will be sorted" << endl;
    printall(list);
    QuickSort(list, low, high -1);
    cout <<  "Here is the list in Ace. order" << endl;
    printall(list);
    QuickSortDec(list, low, high -1);
    cout << "Here is the list in Dec. order" << endl;
    printall(list);
    cout << "press enter to exit" << endl;
    cin.get();
    return 0;
}
int getMax(vector<int> _a){
    int max = 0;
    //this gets the max value
    max = _a[0];
    //goes through each item
    for(size_t b = 0; b < _a.size(); b++){
        if(max < _a[b]){
            //finds all the max value makes it the varible
            max = _a[b];
        }
    }
    //returns that value
    return max;
}
int getMin(vector<int> _a){
    //this gets the min
    int min = 0;
    //makes a var
    min = _a[0];
    //sets it to the first item
    for(size_t b = 0; b < _a.size(); b++){
        //goes through all of the items
        if(min > _a[b]){
            //compares them
            min = _a[b];
            //makes it the value if it is less then the item
        }
    }
    //returns it
    return min;
}
void swap(vector<int>& a, vector<int>& b){
    //this swaps items
    vector<int> swap;
    swap = a;
    a = b;
    b = swap;
    
}
int par(vector<int>& _a, int low, int high){
    int pi = _a[high];
    //here above is the pivot
    int i = low -1;
    //here is the lowest value you set it up so that you
    //can use the smallest element
    for(int x = low; x <= high-1; x++){
        if(_a[x] < pi){
            //this compares the piv to the rest of the items
            //adds one to the compare loop value or compare value
            //dependent on how you look at it
            i++;
            //here is the swap function
            swap(_a[i], _a[x]);
        }
    }
    swap(_a[high], _a[(i+1)]);
    return (i+1);
}
//this is the main quick sort option
void QuickSort(vector<int>& _a, int low, int high){
    //cout << high << endl;
    if(low < high){
        int p;
        //this compares the pivot
        p = par(_a, low, high);
        //here is the piv functions
        QuickSort(_a, low, p - 1);
        //this compares the stuff lower then the piv
        QuickSort(_a, p + 1, high);
        //this compares the stuff higher then the piv
        
    }
}
void printall(vector<int> a){
    //prints all the items
    for(size_t i =0; i < a.size(); i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}
void QuickSortDec(vector<int>& _a, int low, int high){
    if(low < high){
        int p;
        p = pivDec(_a, low, high);
        QuickSortDec(_a, low, p-1);
        QuickSortDec(_a, p+1, high);
    }
}
int pivDec(vector<int>& _a, int low, int high){
    int i = low -1;
    int pivo = _a[high];
    for(int h = low; h < _a.size() -1; h++){
        if(_a[h] > pivo){
            i++;
            swap(_a[h], _a[i]);
        }
    }
    swap(_a[i+1], _a[high]);
    return (i+1);
}

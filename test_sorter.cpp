#include <iostream>
#include <vector>
#include <stdlib.h>  // for std::rand
#include <algorithm> // for std::sort
#include "sorter.h"
#include "mytimer.h"
using namespace std;

template<typename T>
void Imprimirvector(vector<T> arr, int n)
{
    for (size_t i = 0; i < arr.size() && i<n; i++)
    {
        cout<<arr[i]<<",";
    }
    cout<< endl;
    

}

template <typename T>
void compare_vectors(vector<T> a, vector<T> b, string message = "")
{
    cout << message << " ";
    // check if equal
    if (a == b)
        cout << "CONGRATS, your implementation is correct!" << endl;
    else
        cout << "Ops, sorry cowboy (cowgirl), it seems that something is still missing in your implementation" << endl;
}



int main()
{
    int count=10000;
    vector<int> arr_1;
    for (size_t i = 0; i < count; i++)
    {
        arr_1.push_back((int)rand()%10000+1);    
    }
    cout<<"Vector sin ordenar"<<endl;

    Imprimirvector(arr_1,10000);

    DECLARE_TIMING(t);
    START_TIMING(t);
    std::sort(arr_1.begin(), arr_1.end());
    STOP_TIMING(t);
    SHOW_TIMING(t, "std::sort");
    cout<<"__________________"<<endl;


    vector<int> arr_2(arr_1);
    vector<int> arr_3(arr_1);
    vector<int> arr_4(arr_1);
    vector<int> arr_5(arr_1);

    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelectionSort<int> selsort;
    selsort.sort(arr_2);
    cout<<"Ordenamiento Selection"<<endl;
    Imprimirvector(arr_2,10000);
    STOP_TIMING(t1);
    compare_vectors(arr_1, arr_2, "Selection sort");
    SHOW_TIMING(t1, "SelectionSort:");
    cout<<"__________________"<<endl;

    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BubbleSort<int> bubble;
    bubble.sort(arr_3);
    cout<<"Ordenamiento Bubble: "<<endl;
    Imprimirvector(arr_3,10000);
    STOP_TIMING(t2);
    compare_vectors(arr_1, arr_3, "Bubble sort:");
    SHOW_TIMING(t2, "BubbleSort");
 
    cout<<"__________________"<<endl;

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    InsertionSort<int> insetion;
    insetion.sort(arr_4);
    cout<<"Ordenamiento Insertion: "<<endl;
    Imprimirvector(arr_4,10000);
    STOP_TIMING(t3);
    compare_vectors(arr_1, arr_4, "InsertionSort sort:");
    SHOW_TIMING(t3, "InsertionSort");

    cout<<"__________________"<<endl;

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort<int> merge;
    int arr_size = sizeof(arr_5) / sizeof(arr_5[0]);
    merge.mergesort(arr_5, 0, arr_size - 1);
    cout<<"Ordenamiento Merge: "<<endl;
    Imprimirvector(arr_5,10000);
    STOP_TIMING(t4);
    compare_vectors(arr_1, arr_5, "MergeSort sort:");
    SHOW_TIMING(t4, "MergeSort");

    cout<<"__________________"<<endl;


    
    return 0;
}







#include <iostream>
#include <utility>
#include <queue>
using namespace std;

// simple things to create a min and max heap

//min Heap
//priority_queue<int,vector<int>,std::greater<int>>min_pq1;

//max heap
//priority_queue<int> max_heap;
////////////////////////////////////////////////////////////////////////////////////////////////
// or one single comparartor for both,
struct compare
{
    bool m_greater;
    compare(bool greater = false) : m_greater(greater)
    {
    }
    bool operator()(int a, int b)
    {
        if (m_greater)
        {
            return a > b;
        }
        else
        {
            return a < b;
        }
    }
};

//priority_queue<int, vector<int>, compare> min_pq(compare(true));
/////////////////////////////////////////////////////////////////////////////////////////////////////
// with lambda  also but use decltype
auto compare1 = [](int a, int b) {
    return a > b; // pls note that this is for min Heap
};
using pq = priority_queue<int, vector<int>, decltype(compare1)>;
pq min_pq(compare1);
///////////////////////////////////////////////////////////////////////////////////////////////////

// now function to get kth smallest elemnet

int kthSmallestelemnt(vector<int> v, int K)
{
    // for smallest elemnt we needed maxHeap , so that maximum can be execluded from list
    priority_queue<int> max_heap;
    for (int i = 0; i < v.size(); i++)
    {
        max_heap.push(v[i]);
        if (max_heap.size() > K)
        {
            max_heap.pop();
        }
    }

    return max_heap.top();
}

int kthLargetelemnt(vector<int> v, int K)
{
    // for smallest elemnt we needed minHeap , so that maximum can be execluded from list
    priority_queue<int, vector<int>, std::greater<int>> min_heap;
    for (int i = 0; i < v.size(); i++)
    {
        min_heap.push(v[i]);
        if (min_heap.size() > K)
        {
            min_heap.pop();
        }
    }

    return min_heap.top();
}

int sortANearlySortedArray(vector<int>v, int k)
{
    priority_queue<int, vector<int>,greater<int>> min_heap;

    for(int i =0; i<v.size(); i++)
    {
        min_heap.push(v[i]);
        if(min_heap.size()>k)
        {
            cout<< "Sorted elements are " << min_heap.top() << endl;
            min_heap.pop();
        }
    }
    while(min_heap.size()>0)
    {
        cout << "Sorted elements are in " << min_heap.top() << endl;
        min_heap.pop();
    }
    return 0;
}void kClosetNumber(vector<int>v, int K, int N)
{
    priority_queue<pair<int,int>>max_heap;

    for(int i =0; i<v.size(); i++)
    {
        int abs_num = std::abs(v[i]-N);
        max_heap.push({abs_num,v[i]});

        if(max_heap.size()>K)
        {
            max_heap.pop();
        }
    }

    while (max_heap.size() > 0)
    {
        cout << "closest elements are in " << max_heap.top().second << endl;
        max_heap.pop();
    }
}
void Call_Heap_from_main()
{

    min_pq.push(20);
    min_pq.push(80);
    min_pq.push(100);

    while (min_pq.size() > 0)
    {
        cout << "Heap elements are " << min_pq.top() << endl;
        min_pq.pop();
    }

    vector<int> v{50, 2, 30, 4, 1};
    cout << "Kth Smallest elemt is " << kthLargetelemnt(v, 4) << endl;

    vector<int> v1{6, 5, 3, 2, 8,10,9};
    cout << "Kth Smallest elemt is " << sortANearlySortedArray(v1, 3) << endl;

    vector<int>v2{5,6,7,8,9};
    kClosetNumber(v2,3,7);
}

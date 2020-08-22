class Solution {
public:
    // //Method 1: sort
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     vector<int> res;
    //     sort(arr.begin(), arr.end());
    //     for(int i=0; i<k; ++i) {
    //         res.push_back(arr[i]);
    //     }
    //     return res;
    // }

    //Method 2: heap.
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k,0);
        if(k==0) return res;
        //defaut comparisor: less<int>
        priority_queue< int, vector<int>, greater<int> > pq;
        for(int &i : arr) {
            pq.push(i);
        }
        for(int i=0; i<k; ++i) {
            res[i]=pq.top();
            //the element popped is the last according to this strict weak ordering
            pq.pop();
        }
        return res;
    }

    // //Method 3: heap. only push k element in heap.
    // vector<int> getLeastNumbers(vector<int>& arr, int k) {
    //     vector<int> res(k,0);
    //     if(k==0) return res;
    //     priority_queue<int> pq;
    //     for(int i=0; i<k; ++i) {
    //         pq.push(arr[i]);
    //     }
    //     for(int i=k; i<arr.size(); ++i) {
    //         if(arr[i]<pq.top()) {
    //             pq.pop();
    //             pq.push(arr[i]);
    //         }
    //     }
    //     for(int i=0; i<k; ++i) {
    //         res[i]=pq.top();
    //         pq.pop();
    //     }
    //     return res;
    // }
};
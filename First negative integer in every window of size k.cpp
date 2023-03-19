//TC: O(N)
//SC: O(K)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    long long int i=0, j=0;
    queue<long long> q; //stores list of negative numbers in the window
    vector<long long> ans;
    
    while(j<N){
        if(A[j] < 0)
           q.push(A[j]);
            
        if(j-i+1 < K)
            j++;
            
        else if(j-i+1 == K){
            if(!q.size())  //if No negative number present in the window, store 0
                ans.push_back(0);
            else
                ans.push_back(q.front());  //First negative number will be in the beginning of the queue
                
            if(q.front() == A[i])  //If the element to be excluded is in the front, it won't be the first hegative no. of the next window, so pop it
                q.pop();
           i++;
           j++;
        }
    }
    return ans;                                             
 }

//TC: O(N)
//SC: O(1)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    long long int i=0, j=0;
    queue<long long> q;
    vector<long long> ans;
    
    while(j<N){
        if(A[j] < 0)
           q.push(A[j]);
            
        if(j-i+1 < K)
            j++;
            
        else if(j-i+1 == K){
            if(!q.size())
                ans.push_back(0);
            else
                ans.push_back(q.front());
                
            if(q.front() == A[i])
                q.pop();
           i++;
           j++;
        }
    }
    return ans;                                             
 }

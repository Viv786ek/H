	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_set<int>s;
	    for(int i=0;i<n;i++)
	    {
	        int temp = x-arr[i];
	        if(s.find(temp) != s.end())
	            return true;
	       s.insert(arr[i]);
	    }
	    return false;
	    
	}

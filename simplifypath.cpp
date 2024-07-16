class Solution {
public:
    string simplifyPath(string path) {
        vector<string> arr;
        string s;
        for (int i=1;i<path.size();i++){
            if (path[i]=='/'){
                if (s.size()>0){
                    if (s==".."){
                        if (arr.size()>0)arr.pop_back();
                    }
                    else if (s!="."){
                        arr.push_back(s);
                    }
                }
                s.clear();
            }
            else{s+=path[i];}
            for (string  x:arr){cout<<x<<" ";}
            cout<<endl;
        }
        if (s.size()>0){
            if (s==".."){
                if (arr.size()>0)arr.pop_back();
            }
            else if (s!="."){
                arr.push_back(s);
            }
        }
        string ans="/";
        for (int i=0;i<arr.size();i++){
            if (i!=arr.size()-1){
                ans+=arr[i];
                ans+='/';
            }
            else{ans+=arr[i];}
        }
        return ans;
    
        
    }
};

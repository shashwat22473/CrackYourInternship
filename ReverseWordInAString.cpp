class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        string f;
        for (char x:s){
            if (x==' '){
                if (f.size()>0){
                    arr.push_back(f);
                    f.clear();
                }
            }
            else{f+=x;}
        }
        if (f.size()>0){arr.push_back(f);}
        reverse(arr.begin(),arr.end());
        string ans;
        for (int i=0;i<arr.size();i++){
            if (i!=arr.size()-1){
                ans+=arr[i];
                ans+=' ';
            }
            else{ans+=arr[i];}
        }
        return ans;
    }
};

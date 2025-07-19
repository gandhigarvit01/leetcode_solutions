class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(),folder.end());
        vector<string> result;

        for(auto currfolder : folder){
            bool issubfolder = false;
            string temp = currfolder;
            while(!currfolder.empty()){
                size_t position = currfolder.find_last_of('/');
                currfolder = currfolder.substr(0,position);

                if(st.find(currfolder)!=st.end()){
                    issubfolder = true;
                    break;
                }
            }
            if(!issubfolder){
                result.push_back(temp);
            }
        }
        return result;
    }
};
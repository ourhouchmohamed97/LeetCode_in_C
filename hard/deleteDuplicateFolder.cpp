// Delete Duplicate Folders in System


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    struct trienode{
        string folder;
        bool remove = false;
        map<string,trienode*> child;
        trienode(string folder){
            this->folder = folder;
        }
    };
    void trieInsert(trienode* root,vector<string>& path){
        for(auto &s: path){
            if(!root->child.count(s))
                root->child[s] = new trienode(s);
            
            root = root->child[s];
        }
    }
    string markRepeating(trienode* root,unordered_map<string,trienode*>& visited){
        string subfolder;
        for(auto &[childfolder,childnode]: root->child)
            subfolder += markRepeating(childnode,visited);
        
        if(subfolder.size()){
            if(visited.count(subfolder)){
                visited[subfolder]->remove = true;
                root->remove = true;
            }else{
                visited[subfolder] = root;
            }
        }
        return "[" + root->folder + subfolder + "]";
    }
    void savePath(trienode* root,vector<string>& curr_path,vector<vector<string>>& res){
        if(root->remove)
            return;
        
        curr_path.push_back(root->folder);
        res.push_back(curr_path);
        for(auto &[subfolder,childnode]: root->child)
            savePath(childnode,curr_path,res);
        
        curr_path.pop_back();
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        //Step-1: Insert all paths in TRIE
        trienode* root = new trienode("/");
        for(auto &path: paths)
            trieInsert(root,path);
        
        //Step-2: Mark repeating paths
        unordered_map<string,trienode*> visited;
        markRepeating(root,visited);

        //Step-3: Save the path after deletion
        vector<vector<string>> res;
        vector<string> curr_path;
        for(auto &[subfolder,childnode]: root->child)
            savePath(childnode,curr_path,res);

        return res;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<vector<string>> paths = {
        {"a"},
        {"c"},
        {"d"},
        {"a", "b"},
        {"c", "b"},
        {"d", "a"}
    };
    
    // Call the function
    vector<vector<string>> result = sol.deleteDuplicateFolder(paths);
    
    // Print the result
    cout << "Result after deleting duplicate folders:" << endl;
    for (const auto& path : result) {
        for (const auto& folder : path) {
            cout << folder << "/";
        }
        cout << endl;
    }
    
    return 0;
}
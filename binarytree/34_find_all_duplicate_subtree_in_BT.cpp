unordered_map<string,int> m;
vector<Node*> v;
    string solve(Node* root){
    
        if(!root)
         return "$";
        
           string ans = solve(root->left) + solve(root->right) + to_string(root->data);
        m[ans]++;
        if(m[ans] == 2)
         v.push_back(root);
         
        return ans;
    }
vector<Node*> printAllDups(Node* root)
{
    m.clear();
    v.clear();
         solve(root);
         return v;
       

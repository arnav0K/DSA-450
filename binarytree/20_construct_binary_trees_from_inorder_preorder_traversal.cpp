class Solution{
    public:
    int findPos(int in[],int s,int e,int x)
    {
        for(int i=s;i<=e;i++)
        {
            if(in[i]==x)
            return i;
        }
        return -1;
    }
    Node*solve(int in[], int pre[], int &index,int s,int e,
int n)
{
    if(index>=n || s>e)
    return NULL;
    
    int element=pre[index++];
    Node*root=new Node(element);
    
    // int pos=mp[element];
    int pos=findPos(in,s,e,element);
    root->left=solve(in,pre,index,s,pos-1,n);
    root->right=solve(in,pre,index,pos+1,e,n);
    return root;
}

    Node* buildTree(int in[],int pre[], int n)
    {
    //      map<int,int>mp;
    // for(int i=0;i<n;i++)
    // {
    //     mp[in[i]]=i;
    // }
    
    int index=0;
    return solve(in,pre,index,0,n-1,n);
        // Code here
    }
};

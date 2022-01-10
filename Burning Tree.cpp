/*
Problem :
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes 
connected to a given node get burned. That is its left child, right child, and parent.

https://practice.geeksforgeeks.org/problems/burning-tree/1/
*/

Solution :
Node* t=NULL;
  void markParents(Node* root,unordered_map<Node*,Node*>&parent,int target)
  {
      queue<Node*>q;
      q.push(root);
      while(!q.empty())
      {
          int sz=q.size();
          while(sz--)
          {
              Node* curr=q.front();
              q.pop();
          
          if(curr->data==target)
          t=curr;
          
          if(curr->left)
          {
              parent[curr->left]=curr;
              q.push(curr->left);
          }
          
          if(curr->right)
          {
              parent[curr->right]=curr;
              q.push(curr->right);
          }
          }
      }
  }

    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parent;
        markParents(root,parent,target);
        unordered_map<Node*,bool>visited;
     
        queue<Node*>q;
        q.push(t);
        visited[t]=true;
        int time=0;
        while(!q.empty())
        {
            int sz=q.size();
            int flag=0;
            while(sz--)
            {
                Node* curr=q.front();
                q.pop();
                
                if(curr->left && visited[curr->left]==false)
                {
                    flag=1;
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                
                if(curr->right && visited[curr->right]==false)
                {
                    flag=1;
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                
                if(parent[curr] && visited[parent[curr]]==false)
                {
                    flag=1;
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
            if(flag==1)
                time++;
        }
     return time;   
    }

Time Complexity : O(N)
 
Space Complexity : O(H) 

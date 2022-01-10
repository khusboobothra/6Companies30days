/*
Problem :
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function 
serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.

Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
*/

Solution :
//SERIALIZE
    vector<int> ret;
    void shelper(Node *root){
        if(!root){
            ret.push_back(-1);
            return ;
        }
        ret.push_back(root->data);
        shelper(root->left);
        shelper(root->right);
    }
    vector<int> serialize(Node *root) 
    {
        ret.clear();
        shelper(root);
        return ret;
    }

//DESERIALIZE
    Node* dhelper(vector<int> &A,int &ind){
        if(ind >= A.size() or A.size() == 0)
            return NULL;
        if(A[ind] == -1)
            return NULL;
        Node *temp = new Node(A[ind]);
        ind ++;
        temp->left = dhelper(A,ind);
        ind++;
        temp->right = dhelper(A,ind);
        return temp;
    }
    Node * deSerialize(vector<int> &A)
    {
    int ind = 0;
    return dhelper(A,ind);
    }

Time Complexity : O(N)

Space Complexity :O(N)

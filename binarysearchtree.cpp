#include <c++/v1/bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
};

Node *create(int data){
    
    Node * root=new Node();
    root->data=data;
    root->left=root->right=NULL;
    
    return root;
}

Node * insert(Node * root,int data){
    
    if(root==NULL){
        root=create(data);
    }
    else if (data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

void inorder(Node * root){
    
    if(root!=NULL){
        
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);

    }
}
void postorder(Node * root){
    
    if(root!=NULL){
        
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";


    }
}
void preorder(Node * root){
    
    if(root!=NULL){
        
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);

    }
}

int minroot(Node*root){
    Node * temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    cout<<"Minimum Value in BST is : "<<temp->data<<"\n";
    
    return temp->data;
}

int maxroot(Node*root){
    Node * temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    cout<<"Maximum Value in BST is : "<<temp->data<<"\n";
    
    return temp->data;

}
Node* minValueNode( Node* node)
{
     Node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
Node* deleteNode(Node* root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
 

    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
  
    else {

        if (root->left==NULL && root->right==NULL)
            return NULL;
       
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
 
         Node* temp = minValueNode(root->right);
         root->data = temp->data;
         root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int height(Node*root){
    if(root==NULL) return -1;
    
return max(height(root->left),height(root->right))+1;

}
void LOT(Node *root){
    if(root==NULL) return;
    
    queue<Node *> Q;
    Q.push(root);//pusing address of root
    while(!Q.empty()){
        Node *current =Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
}
bool IsBSTorNOT(Node*root,int minv,int maxv){
    if(root==NULL) return true;
    
    if(root->data<minv && root->data>maxv && IsBSTorNOT(root->left,minv,root->data) && IsBSTorNOT(root->right,root->data,maxv)){
        return true;
    }
    else return false;
}

int main()
{   int h=0;
    Node * root=NULL;
    
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,8);
    root=insert(root,12);
    root=insert(root,17);
    root=insert(root,25);
    root=insert(root,7);
    root=insert(root,9);
    
    cout<<"INORDER\n";
    inorder(root);
    cout<<"\nPREORDER\n";
    preorder(root);
    cout<<"\nPOSTORDER\n";
    postorder(root);
    cout<<"\n\nFINDING MIN AND MAX OF THE BST\n\n";
    minroot(root);maxroot(root);
    cout<<"\n\nFINDING THE HEIGHT OF BST\n";
    h=height(root);
    cout<<h;
    cout<<"\n\nFINDING THE LEVEL ORDER TRAVERSAL OF BST\n";
    LOT(root);

        int ans= IsBSTorNOT(root,minroot(root),maxroot(root));

    if(ans==false){cout<<"\n\nTHE GIVEN TREE IS A BST";
    }else {
        cout<<"\n\nTHE GIVEN TREE IS NOT A BST";
    }
    cout<<endl;
        cout<<"DELETE NODE 5";

    root=deleteNode(root, 5);
        cout<<endl;
     inorder(root);

 return 0;

}

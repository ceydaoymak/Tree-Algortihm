    #include <iostream>
    #include <stack>
    using namespace std;
    struct node{
        int data;
        struct node* left;
        struct node* right;
    };
    struct node* newNode(int data){
        struct node* node= new struct node;
        node->data= data;
        node->left=NULL;
        node->right=NULL;
        return(node);
    };
    void Preorder(node* root) {
        if(root==NULL){
            return;
        }
        stack<node*> s;
        s.push(root);
        while(!s.empty()){
            struct node* current= s.top();
            s.pop();
            cout<<current->data<<" ";
            if(current->right){
                s.push(current->right);
            }if(current->left)
            {
                s.push(current->left);
            }
        }
    }
    void Inorder(node* root){
        if(root==NULL){
            return;
        }
        stack <node*> S;
      struct node* current= root;
        while(current!=NULL || !S.empty()){
            while(current!=NULL ){
                S.push(current);
                current = current->left;
            }
            current=S.top();
            S.pop();
            cout<<current->data<<" ";
            current=current->right;
        }
    }
    void Postorder(node* root){
        if(root==NULL){
            return;
        }
        stack<node*> s1;
        stack<node*> s2;
        s1.push(root);
        while(!s1.empty()){
            struct node* temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left){
                s1.push(temp->left);
            }if(temp->right){
                s1.push(temp->right);
            }

        }
     while(!s2.empty()) {
         struct node *temp = s2.top();
         cout << temp->data<<" ";
         s2.pop();
     }
    }
    int height(node* root){
        if(root==NULL){
            return -1;
        }
        int lefth=height(root->left);
        int righth=height(root->right);
        int theight = 1+max(lefth,righth);
        return theight;
    }
    int main() {
        struct node *root = newNode(3);
        root->left = newNode(8);
        root->right = newNode(5);
        root->left->left = newNode(4);
        root->left->right = newNode(2);
        root->right->left = newNode(6);
        root->right->right = newNode(1);
        root->left->left->left = newNode(7);
        Inorder(root);
        cout<<endl;
        Postorder(root);
        cout<<endl;
        Preorder(root);
        cout<<endl;
        int treeHeight = height(root);
        cout<<treeHeight<<endl;
        return 0;

    }

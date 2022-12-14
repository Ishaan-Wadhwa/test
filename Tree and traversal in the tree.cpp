#include <iostream>
#include<queue>
using namespace std;

class node 
{
public:
  int data;
  node *left;
  node *right;
  node(int d) 
{
    data = d;
    left = NULL;
    right = NULL;
  }
};

node *BuildTree(node *root) 
{
  int data;
  cout << " Enter the data :" << endl;
  cin >> data;
  root = new node(data);
  if (data == -1)
    return NULL;
  cout << "Enter the data to be inserted to the left of " << data << endl;
  root->left = BuildTree(root->left);

  cout << "Enter the data to be inserted to the right of " << data << endl;
  root->right = BuildTree(root->right);

  return root;
}

void levelOrderTraversal(node *root)
{
queue<node*>q;
q.push(root);
q.push(NULL);
while(!q.empty())
{
    node *temp = q.front();
    q.pop();
    if(temp == NULL)
    {
        cout<<endl;
        if(!q.empty())
        {
            q.push(NULL);
        }
    }

else
{
   cout<<" "<<temp->data<<" ";
if(temp->left)
{
    q.push(temp->left);
}

if(temp->right)
{
    q.push(temp->right);
}
}

}
}
int main() 
{
  node *root = NULL;
  root = BuildTree(root);
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  levelOrderTraversal(root);
  return 0;
}
#include<iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    vector<Node *> children;
};

Node *newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    return temp;
}

void BFS(Node *root) {
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> currlevel;
        for (int i = 0; i < size; i++) {
            Node *tmp = q.front();
            cout << tmp->data << endl;
            q.pop();
            currlevel.push_back(tmp->data);
            int chSize = tmp->children.size();
            for (int k = 0; k < chSize; k++)
                q.push(tmp->children[k]);
        }
    }
}

void DFS(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << endl;
    int chSize = root->children.size();
    for (int k = 0; k < chSize; k++) {
        DFS(root->children[k]);
    }
}

int main(int argc, const char *argv[]) {
    Node *root = newNode(1);
    root->children.push_back(newNode(2));
    root->children.push_back(newNode(7));
    root->children.push_back(newNode(8));
    root->children[0]->children.push_back(newNode(3));
    root->children[0]->children.push_back(newNode(6));

    root->children[2]->children.push_back(newNode(9));
    root->children[2]->children.push_back(newNode(12));

    root->children[0]->children[0]->children.push_back(newNode(4));
    root->children[0]->children[0]->children.push_back(newNode(5));

    root->children[2]->children[0]->children.push_back(newNode(10));
    root->children[2]->children[0]->children.push_back(newNode(11));

   // if (argc < 2) {
        cout << "Please provide at least one argument 1 or 2" << endl;
     //   exit(0);
   // }

   // int val = atoi(argv[1]);
    int val;
    cin>>val;
    switch (val) {
        case 1:
            cout << "Printing tree in DFS...." << endl;
            DFS(root);
            break;
        case 2:
            cout << "Printing tree in BFS...." << endl;
            BFS(root);
            break;
        default:
            cout << "Invalid option. Please select 1 for DFS and 2 for BFS." << endl;
            break;
    }
    
    return 0;
}
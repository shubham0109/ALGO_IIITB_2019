# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;

struct node{
    int key;
    int num;
    int sum;
    int min;
    int max;
    int mingap;
    node* left, *right;
};

node* insert(node* root, int key){
    if (root == NULL){
        node* newNode = new node();
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        
        root = newNode;
        return root;
    }
    
    if (root->key > key){
        root->left = insert(root->left, key);
    }else{
        root->right = insert(root->right, key);
    }
    
    return root;
}

void initializeNum(node* root){
    if (root == NULL){
        return;
    }
    
    initializeNum(root->left);
    initializeNum(root->right);
    
    int s = 0;
    if (root->left){
        s += root->left->num;
    }
    if (root->right){
        s += root->right->num;
    }
    
    s += 1;
    
    root->num = s;
    
    return;
}

void traverse(node* root){
    if (!root)return;
    
    traverse(root->left);
    cout<<"key: "<<root->key<<" num: "<<root->num<<" sum: "<<root->sum<<" max: "<<root->max
    <<" min: "<<root->min<<" mingap: "<<root->mingap<<endl;
    traverse(root->right);
    
    return;
}

int findRank(node* root, int key){
    
    int rank = 0;
    bool flag = false;
    
    while (root != NULL){
        if (root->key == key){
            if (root->right)rank += root->right->num;
            
            rank += 1;
            break;
        }else if(root->key > key){
            if (root->right){
                rank += root->right->num;
            }
            rank += 1;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    
    return rank;
}

int findNode(node* root, int rank){
    if (root == NULL){
        return -1;
    }
    
    int n = 0;
    if (root->right){
        n += root->right->num;
    }
    
    if (n + 1 == rank){
        return root->key;
    }else if (n + 1 > rank){
        return findNode(root->right, rank);
    }else {
        return findNode(root->left, rank - (n + 1));
    }
}

bool search(node* root, int x){
    if (root == NULL){
        return false;
    }
    
    if (root->key == x){
        return true;
    }else if(root->key < x){
        return search(root->right, x);
    }else{
        return search(root->left, x);
    }
}


void initializeSum(node* root){
    if (root == NULL){
        return;
    }
    
    initializeSum(root->left);
    initializeSum(root->right);
    
    root->sum = 0;
    if (root->left){
        root->sum += root->left->sum;
    }
    
    if (root->right){
        root->sum += root->right->sum;
    }
    
    root->sum += root->key;
    
    return;
}

int prefixSum(node* root, int x){
    if (root == NULL){
        return 0;
    }
    
    int p_sum = 0;
    while (root != NULL){
        if (root->key == x){
            p_sum += root->sum;
            
            if (root->right){
                p_sum -= root->right->sum;
            }
            break;
        }else if (root->key > x){
            root = root->left;
        }else{
            p_sum += root->sum;
            if (root->right){
                p_sum -= root->right->sum;
            }
            root = root->right;
        }
    }
    
    return p_sum;
}

int initializeMax(node* root){
    if (root == NULL)return INT_MIN;
    
    if (root->left == NULL && root->right == NULL){
        root->max = root->key;
        return root->max;
    }
    
    int l_mx = initializeMax(root->left);
    int r_mx = initializeMax(root->right);
    
    root->max = max(l_mx, r_mx);
    root->max = max(root->max, root->key);
    
    return root->max;
}

int initializeMin(node* root){
    if (root == NULL)return INT_MAX;
    
    if (root->left == NULL && root->right == NULL){
        root->min = root->key;
        return root->min;
    }
    
    int l_mn = initializeMin(root->left);
    int r_mn = initializeMin(root->right);
    
    root->min = min(l_mn, r_mn);
    root->min = min(root->min, root->key);
    
    return root->min;
}

int initializeMingap(node* root){
    //if (root == NULL)return 10000;
    
    if (root->left == NULL && root->right == NULL){
        root->mingap = INT_MAX;
        return root->mingap;
    }
    
    int l_mng = INT_MAX;
    if (root->left){
        l_mng = initializeMingap(root->left);
    }
    
    int r_mng = INT_MAX;
    if (root->right){
        r_mng = initializeMingap(root->right);
    }
    
    root->mingap = min(l_mng, r_mng);
    int rlmx = INT_MIN;
    //cout<<"rlmx: "<<rlmx<<endl;
    if (root->left){
        rlmx = root->left->max;
    }
    
    int rrmn = INT_MAX;
    if (root->right){
        rrmn = root->right->min;
    }
    root->mingap = min(root->mingap, min(abs(root->key - rlmx), abs(rrmn - root->key)));
    
    return root->mingap;
}

int main(){
    node* root = NULL;
    
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 15);
    root = insert(root, 6);
    root = insert(root, 45);
    root = insert(root, 3);
    root = insert(root, 1);
    
    // initialize the num(x) (no. of nodes in the subtree rooted at x)
    initializeNum(root);
    
    // initialize the sum of every node (sum of nos. which are less than or equal to x)
    initializeSum(root);
    
    // initialize the max of every node  (max that it has seen below it including itself)
    initializeMax(root);
    
    // initialize the min of every node  (min that it has seen below it including itself)
    initializeMin(root);

    // initialize the mingap of every node  (mingap encountered uptil that node)
    initializeMingap(root);

    // traverse the BST inorder
    traverse(root);
    
    // find rank of x
    cout<<endl;
    cout<<"rank: "<<findRank(root, 2)<<endl;
    cout<<"rank: "<<findRank(root, 3)<<endl;
    cout<<"rank: "<<findRank(root, 0)<<endl;
    
    // find the node whose rank is r
    cout<<endl;
    cout<<"node: "<<findNode(root, 2)<<endl;
    cout<<"node: "<<findNode(root, 4)<<endl;
    cout<<"node: "<<findNode(root, 5)<<endl;

    
    // find the no. of nodes between [l,r]
    int left_rank = 0, right_rank = 0;
    int l = 3;
    int r = 15;
    
    left_rank = findRank(root, l);
    right_rank = findRank(root, r);
    int nodes = left_rank - right_rank;
    
    if (search(root, l) || search(root, r)){
        nodes += 1;
    }
    
    cout<<endl;
    cout<<"The no. of nodes in between are: " <<nodes<<endl;
    
    // prefix sum of x (sum of nos. which are less than or equal to x)
    cout<<endl;
    cout<<"prefix sum: "<<prefixSum(root, 0)<<endl;
    
    // find the sum between [l,r]
    l = 7;
    r = 25;
    int left_sum = prefixSum(root, l);
    int right_sum = prefixSum(root, r);
    
    cout<<endl;
    cout<<"sum between the range is: "<<right_sum - left_sum<<endl;
    
    // average between [l,r]
    l = 0;
    r = 45;
    
    left_rank = findRank(root, l);
    right_rank = findRank(root, r);
    nodes = left_rank - right_rank;
    
    if (search(root, l) || search(root, r)){
        nodes += 1;
    }
    
    left_sum = prefixSum(root, l);
    right_sum = prefixSum(root, r);
    
    int p_sum = right_sum - left_sum;
    
    cout<<endl;
    cout<<p_sum<<" "<<nodes<<endl;
    cout<<"Average: "<<(p_sum/nodes)<<endl;
    
    
    
    
    return 0;
}

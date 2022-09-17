#include <iostream>
#include <fstream>

using namespace std;

struct KTree {
	explicit KTree(long _info = 0, KTree* _left = 0, KTree* _right = 0) :
		info(_info), right(_right), left(_left) {}

	int info;
	KTree* left;
	KTree* right;
};

class KbinTree {
public:
	KbinTree() : pTree(nullptr) {}
	~KbinTree() { Delete(pTree); }


	void Delete(KTree*& t) {
		if (t) { Delete(t->left); Delete(t->right); delete t; }
	}

	void Insert(int info) {
		KTree** pp = &pTree;
		while (*pp) {
			if (info < (*pp)->info) pp = &(*pp)->left;
			else if (info > (*pp)->info) pp = &(*pp)->right;
            else if(info == (*pp)->info) {
                // pp = nullptr;
                return;
            }
		}
		*pp = new KTree(info);
	}

    KTree* FinMin(KTree* root){
        if(root->left != nullptr){
            return FinMin(root->left);
        }
        else{
            return root;
        }
    }

    KTree* DeleteRoot(KTree* root, int x){
        if(root == nullptr){
            return root;
        }
        if(root->info > x){
            root->left = DeleteRoot(root->left, x);
            return root;
        }
        else if(root->info < x){
            root->right = DeleteRoot(root->right, x);
            return root;
        }
    
        if(root->left == nullptr){
            return root->right;
        }
        else if(root->right == nullptr){
            return root->left;
        }
        else{
            int min_key = FinMin(root->right)->info;
            root->info = min_key;
            root->right = DeleteRoot(root->right, min_key);
            
            return root;
        }
    }

    void DeleteElem(int x){
        KTree **pp = &pTree;
        pTree = DeleteRoot(*pp, x);
    }

    void PrintLeftSide(KTree *root){
        if (root != nullptr) {
            out << root->info << endl;
            PrintLeftSide(root->left);
            PrintLeftSide(root->right);
        } 
    }

    void PrintLeftSide(){
        KTree **pp = &pTree;
        PrintLeftSide(*pp);
    }

    ofstream out;

private:
	KTree* pTree;
};

int main() {

    KbinTree main;

    ifstream in("input.txt");
    main.out = ofstream("output.txt");

    int DeleteNumber;
    int amount;

    string str;

    in >> DeleteNumber;
    
    while(in){
        in >> amount;
        main.Insert(amount);
    }

    main.DeleteElem(DeleteNumber);
    main.PrintLeftSide();
}
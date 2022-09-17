#include <iostream>
#include <fstream>

using namespace std;

struct KTree {
	explicit KTree(int _info = 0, KTree* _left = 0, KTree* _right = 0) :
		info(_info), right(_right), left(_left) {}

	int info;
	KTree* left;
	KTree* right;
};

class KbinTree {
public:
	KbinTree() : pTree(nullptr) {}
	~KbinTree() { Delete(pTree); }

	bool is_empty(KTree* pTree) {
		if (pTree == nullptr) {
			return true;
		}
		return false;
	}

	void Delete(KTree*& t) {
		if (t) { Delete(t->left); Delete(t->right); delete t; }
	}

	void Insert(int info) {
		KTree** pp = &pTree;
		while (*pp) {
			if (info < (*pp)->info) pp = &(*pp)->left;
			else if (info > (*pp)->info) pp = &(*pp)->right;
			else
				return;
		}
		*pp = new KTree(info);
	}


	bool is_leaf(KTree* p) {
		if (p->right == nullptr && p->left == nullptr) {
			return true;
		}
		return false;
	}

    void PrintLeftSide(KTree *root){
        if(root){
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

    // ifstream in("input.txt");
    // main.out = ofstream("output.txt");

    int i;
    string str;
    
   

    main.PrintLeftSide();


}
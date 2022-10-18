#include <iostream>
#include <fstream>

using namespace std;

struct KTree {
	explicit KTree(long _info = 0, KTree* _left = nullptr, KTree* _right = nullptr) :
		info(_info), right(_right), left(_left) {}

	int info = 0;
    int height = 0;
    int MinHeightValue = 0;

    KTree *First = nullptr;
    KTree *Second = nullptr;
	KTree* left = nullptr;
	KTree* right = nullptr;
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
                return;
            }
		}
		*pp = new KTree(info);
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

    KTree* FinMin(KTree* root){
        if(root->left != nullptr){
            return FinMin(root->left);
        }
        else{
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

    void SetHeightRevLeftSide(KTree *root){
        if (root != nullptr) {
            SetHeightRevLeftSide(root->left);
            SetHeightRevLeftSide(root->right);
            if(root->left == nullptr && root->right == nullptr){
                root->height = 0;
            }else if(root->left != nullptr && root->right == nullptr){
                root->height = root->left->height + 1;
            }else if(root->left == nullptr && root->right != nullptr){
                root->height = root->right->height + 1;
            }else if(root->left != nullptr && root->right != nullptr){
                root->height = min(root->right->height, root->left->height) + 1;
            }
        }
    }

    long long SummingKeys(KTree* root, int x){
        KTree* proot = root;
         
        long long sum = 0ll;

        while(proot){
            if(proot->info > x){
                proot = proot->left;
                sum += proot->info;
            }
            else if(proot->info < x){
                proot = proot->right;
                sum += proot->info;
            }
            if(proot->info == x){
                break;
            }
        }

        return sum;
    }

    void ChangeKey(KTree *root){
        if (root != nullptr) {
            ChangeKey(root->left);
            ChangeKey(root->right);
            
            if(root->left != nullptr && root->right == nullptr){
                root->First = root->left->First;
                root->Second = root;
            }else if(root->left == nullptr && root->right != nullptr){
                root->First = root->right->First;
                root->Second = root;
            }else if(root->left == nullptr && root->right == nullptr){
                root->First = root;
            }else if(root->left != nullptr && root->right != nullptr){
                if(root->right->height < root->left->height){
                    root->First = root->right->First;
                    root->Second = root->left->First;
                    root->MinHeightValue = root->right->height + root->left->height;
                }else if(root->right->height >= root->left->height){
                    root->First = root->left->First;
                    root->Second = root->right->First;
                    root->MinHeightValue = root->right->height + root->left->height;
                }

                long long sum = 0ll;

                sum += SummingKeys(root, root->First->info);
                sum += SummingKeys(root, root->Second->info);
                
                if(root->MinHeightValue <= GlobalHeight){
                    if(sum + root->info < MinSum){
                        MinSum = sum + root->info;
                        last_root = root;
                    }
                    else if(sum + root->info == MinSum){
                        last_root = root->info < last_root->info ? root : last_root;
                    }
                    GlobalHeight = root->MinHeightValue;
                }
            }
        }
    }

    void DeleteThisShit(){
        if(last_root != nullptr){
            cout << last_root->left->height << " " << last_root->right->height << endl;
            long long delta = last_root->left->height - last_root->right->height;
            KTree* temp = last_root;
            if(delta % 2 == 0){
                delta /= 2;
                while(delta != 0){
                    if(delta < 0){
                        temp = temp->right;
                        delta++;
                    }
                    else{
                        temp = temp->left;
                        delta--;
                    }
                }
                DeleteElem(temp->info);
            }
        }
    }
    
    void PrintRevLeftSide(){
        KTree **pp = &pTree;
        SetHeightRevLeftSide(*pp);
    }

    void hui(){
        KTree **pp = &pTree;
        ChangeKey(*pp);
    }

    void PrintLeftSide(){
        KTree **pp = &pTree;
        PrintLeftSide(*pp);
    }

    int GlobalHeight = INT_MAX;
    KTree* last_root = nullptr;
    long long MinSum = LLONG_MAX;
    ofstream out;

private:
	KTree* pTree;
};

int main() {

    KbinTree main;

    ifstream in("in.txt");
    main.out = ofstream("out.txt");

    int amount;

    string str;
    
    while(in){
        in >> amount;
        main.Insert(amount);
    }

    main.PrintRevLeftSide();
    main.hui();
    main.DeleteThisShit();
    main.PrintLeftSide();
   
}
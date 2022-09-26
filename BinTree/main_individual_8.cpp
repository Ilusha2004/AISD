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

    long long FPM(KTree* root, long long min, long long amount){
        long long Min = min;
        long long sum = 0;
        long long sum_key = 1;
        long long amount_key = amount;
        static long long DelAmount = 0;
        long long Root;

        if(root->right != nullptr && root->left != nullptr){
            Root = root->info;
            cout << "Root " << root->info << endl;

            KTree *temp_0 = root->right; 
            KTree *temp_1 = root->left;
            cout  << "left " << temp_1->info << " right " << temp_0->info << endl;
            sum = root->info + temp_0->info + temp_1->info;
            sum_key += 2;

            while(temp_0->right != nullptr || temp_1->left != nullptr){
                
                if(temp_1->left != nullptr && temp_0->right != nullptr){
                    sum += temp_0->info + temp_1->info;
                    temp_1 = temp_1->left;
                    temp_0 = temp_0->right;
                    cout  << "left " << temp_1->info << " right " << temp_0->info << endl;
                    sum += temp_0->info + temp_1->info;
                    sum_key += 2;
                }
                else if(temp_1->left == nullptr && temp_0->right != nullptr){
                    sum += temp_1->info;
                    temp_0 = temp_0->right;
                    cout << "right " << temp_0->info << endl;
                    sum += temp_1->info;
                    sum_key += 1;
                }
                else if(temp_1->left != nullptr && temp_0->right == nullptr){
                    sum += temp_1->info;
                    temp_1 = temp_1->left;
                    cout << "left " << temp_1->info << endl;
                    sum += temp_1->info;
                    sum_key += 1;
                }
            }

            cout << "Sum " << sum << endl << "amount_key " << amount_key << " sum_key " << sum_key << endl; 
            
            if(sum_key < amount_key){
                Min = sum;
                amount_key = sum_key;
                DelAmount = Root;
            }
            else if(sum == Min && amount_key == sum_key){
                
            }

            cout << "Min " << Min << endl;
            cout << "Min_lenght " << amount_key << endl;
            cout << "Min_Root " << DelAmount;
        }

        if(root->right != nullptr){
            FPM(root->right, Min, amount_key);
        }
        if(root->left != nullptr){
            FPM(root->left, Min, amount_key);
        }//находим ключи которые являются родителями листьев
        
        return DelAmount;
    }

    long long PFPM(){
        return FPM(pTree, LONG_MAX, LONG_MAX);
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

    ifstream in("in.txt");
    main.out = ofstream("out.txt");

    int DeleteNumber;
    int amount;

    string str;
    
    while(in){
        in >> amount;
        main.Insert(amount);
    }

    cout << main.PFPM() << endl;

    main.DeleteElem(main.PFPM());
    main.PrintLeftSide();
}
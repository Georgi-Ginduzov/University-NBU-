#include <iostream>

using namespace std;

typedef int DataT;
typedef struct node* po;

struct node {
	DataT data;
	po left;
	po right;
};

// func(Add an element)
//		search for the element with loop
//			if not there add it with function

int main() {

}







































/*typedef int idata;
typedef struct Node* po;

struct Node
{
	idata data;
	po left;
	po right;
};
po DdpRoot = NULL;


po DDP(int x, po DDProot) {
	cout << "tursq " << x << endl;
	po help, otzad = NULL;
	if (DdpRoot == NULL) {
		help = new Node;
		help->data = x;
		help->left = NULL;
		help->right = NULL;
		DdpRoot = help;
		cout << "koren  " << DdpRoot->data << endl;
	}
	else {
		help = DdpRoot;//vlqzoh v durvoto
		cout << "vlqzoh v durvoto, koren " << DdpRoot->data << endl;
		while (help != NULL && help->data != x) {
			cout << "Vlqzoh v while-a \n";
			otzad = help;
			//cout << "zakacham za" << otzad->data;
			cout << "tursia nadolu, ukazatel help " << help->data << endl;
			if (help->data > x) {
				help = help->left;
				cout << "nalqvo\n";
			}
			else {
				help = help->right;
				cout << "dqsno\n";
			}
		}cout << help;
		if (help == NULL) {


			help = new Node;
			help->data = x;
			cout << "zakatcham" << help->data;

			help->left = NULL;
			help->right = NULL;
			if (otzad->data > x) {
				otzad->left = help;
			}
			else {
				otzad->right = help;
			}
		}
	}

	return help;
}
	

void OBH(po ptr)
{
	po help = ptr;
	if (help != nullptr) {
		cout << help->data;//prefix
		OBH(help->left);
		//cout << help->data;//infix
		OBH(help->right);
		//cout << help->data;//postfix
	}
	return;
}

void print(po root, int space)
{

	if (root == nullptr)
		return;
	int COUNT = 10;
	space += COUNT;
	print(root->right, space);
	cout << " ";
	for (int i = COUNT; i < space; i++) {
		cout << " ";
	}
	cout << root->data << "\n";
	print(root->left, space);
}

int main()
{
	po root = NULL, here;
	int tursia = 5;
	while (tursia != 0) {
		cin >> tursia;
		here = DDP(tursia, DdpRoot);
	}
	OBH(DdpRoot);
	//int n;
	//cout << "Enter n value:";
	//cin >> n;
	//root = IBD(n);
	print(DdpRoot, 2);
	//cout << "obhojdane" << "\n";
	//OBH(root);
	//cout << endl;
	//bool find = false;

	return 0;
}
*/
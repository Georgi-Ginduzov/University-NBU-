#include <iostream>

typedef int DataT;
typedef struct node* po;

struct node {
	DataT data;
	po left;
	po right;
};

void prefix(po help) {
	if (help)
	{
		std::cout << help->data << "\n";
		prefix(help->left);
		prefix(help->right);
	}
}

void infix(po help) {
	if (help)
	{
		infix(help->left);
		std::cout << help->data << "\n";
		infix(help->right);
	}
}

void postfix(po help){
	if (help)
	{
		postfix(help->left);
		postfix(help->right);
		std::cout << help->data << "\n";
	}
}

//int count1 = 0;
//void print(po root1) {
//	if (root1) {
//		std::cout << "\t" << root1->data;
//		count1++;
//		print(root1->right);
//		count1--;
//		std::cout << std::endl;
//		for (int i = 1; i <= count1; i++) 
//			std::cout << "\t";
//		count1++;
//		print(root1->left);
//		count1--;
//	}
//}

po ibd(int n) {
	po darj;
	DataT x;

	if (n > 0)
	{
		int nl = n / 2, nd = n - nl - 1;
		darj = new node;
		std::cout << "x=";
		std::cin >> x;
		darj->data = x;
		darj->left = ibd(nl);
		darj->right = ibd(nd);
		return darj;
	}
	else
	{
		return NULL;
	}
}

int main() {
	int n;
	po root;
	std::cout << "n=";
	std::cin >> n;
	root = ibd(n);

	//print(root);
}
#include <iostream>

typedef char DataT;
typedef struct node* po;

struct node {
	DataT data;
	po left;
	po right;
};

void print(po root, int space)
{
	if (root == NULL)
		return;

	space += 10;

	print(root->right, space);

	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	print(root->left, space);
}

void rowPrint(po root, int i) {
	if (root == NULL)
		return;

	rowPrint(root->right, i++);

	if (i%2==0)
	{
		std::cout << "(" << root->data << ")";
	}
	else
	{
		std::cout << root->data;
	}

	rowPrint(root->left, i++);
}

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

	rowPrint(root, 0);
}
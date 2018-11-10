// 트리의 node 클래스
class node
{
public:					// 각 node는
	int key;			// 그 node의 값과
	node* left;			// left node와
	node* right;		// right node를 갖는다.

	node(int key)
	{
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}
	node()
	{
		this->key = 0;
		this->left = NULL;
		this->right = NULL;
	}
};

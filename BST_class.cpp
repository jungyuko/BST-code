// BST 클래스
class BST
{
public:
	node* root;		// 트리의 root 노드

	void Insert_Start() const
	{
		cout << "-------------------- 삽입 --------------------" << endl;
	}
	
	void Insert_End() const
	{
		cout << "-------------------- 삽입 끝 --------------------" << endl;
	}

	void Delete_Start() const
	{
		cout << "-------------------- 삽입과 같은 순으로 삭제 --------------------" << endl;
	}

	void Delete_End() const
	{
		cout << "-------------------- 삭제 끝 --------------------" << endl;;
	}
	void ReverseDelete_Start() const
	{
		cout << "-------------------- 삽입과 반대 순으로 삭제 ---------------------" << endl;
	}

	// Inorder 연선 결과 출력
	void printInorder()
	{
		Inorder(root);
		cout << endl;
	}

	// Inorder 연산 결과 출력 : 재귀호출
	void Inorder(node* T)
	{
		if (T == NULL)
			return;
		else
		{
			Inorder(T->left);
			cout << T->key << " ";
			Inorder(T->right);
		}
	}
	
	// searchKey에 해당하는 값을 가진 노드를 반환하는 함수
	node* searchBST(node* T, int searchKey)		//T는 BST, searchKey는 검색 키 값
	{
		node* p = T;
		if (p == NULL)		// 공백 이진 트리로 실패
			return NULL;
		if (p->key == searchKey)	// 검색이 성공
			return p;
		if (p->key < searchKey)		// 오른쪽 서브트리 검색
			return searchBST(p->right, searchKey);
		else                        // 왼쪽 서브트리 검색
			return searchBST(p->left, searchKey);
	}

	// searchKey에 해당하는 값을 가진 노드를 자식으로 둔 노드를반환하는 함수
	node* searchParentBST(node* T, int searchKey)
	{
		node* q = NULL;
		node* p = T;
		while (p != NULL)		// 찾으려는 키 값을 가진 노드가 이미 있는지 검사
		{
			if (searchKey == p->key)
			{
				if (q == NULL)
				{
					q = searchBST(root, searchKey);
					return q;
				}
				else
					return q;
			}
			q = p;		// q는 p의 부모 노드르 ㄹ지시
			if (searchKey < p->key)
				p = p->left;
			else
				p = p->right;
		}
		return NULL;
	}

	// 피라미터의 노드를 포함하여 좌, 우측 트리가 포함하는 총 노드의 갯수를 반환한다.
	int noNodes(node* T)
	{
		if (T == NULL)		// T가 비어있다면
			return 0;		// 갯수는 0
		else
			return noNodes(T->left) + noNodes(T->right) + 1;
	}

	// 트리의 높이를 반환하는 함수
	int height(node* T)
	{
		if (T == NULL)		// T가 비어있다면
			return 0;		// 높이는 0
		else
		{
			int height_left = height(T->left);		// 왼쪽 트리의 높이
			int height_right = height(T->right);	// 오른쪽 트리의 높이
			
			if (height_left > height_right)			// 왼쪽트리의 높이가 더 크다면
				return height_left + 1;				// 왼쪽트리의 높이를 반환
			else                                    // 오른쪽트리의 높이가 더 크다면 
				return height_right + 1;			// 오른쪽트리의 높이를 반환
		}
	}
	
	// 해당 노드의 child노드중 가장 큰 값의 노드를 반환
	node* maxNode(node* T)	
	{
		node* p = T;
		while (p->right != NULL)
			p = p->right;

		return p;
	}

	// 해당 노드의 child노드중 가장 작은 값의 노드를 반환
	node* minNode(node* T)
	{
		node* p = T;
		while (p->left != NULL)
			p = p->left;
		
		return p;

	}

	// 삽입 함수
	void InsertBST(node* T, int newKey)		// T는 BST, newKey는 삽입할 키 값
	{
		node* p = T;
		node* q = new node();		// q 노드 생성
		while (p != NULL)			// 삽입하려는 키 값을 가진 노드가 이미 있는지 검사
		{
			if (newKey == p->key)
				return;
			q = p;					// q는 p의 부모 노드를 지시
			if (newKey < p->key)
				p = p->left;
			else
				p = p->right;
		}							// q(탐색이 실패로 종료하게 된 노드)를 찾아냄

		node* newNode = new node(newKey);	// newNode생성
		if (T == NULL)						// 공백 이원 탐색 트리인 경우
			root = newNode;
		else if (newKey < q->key)
			q->left = newNode;
		else
			q->right = newNode;
	}

	// 삭제 함수
	void deleteBST(node* T, int deleteKey)
	{
		node* p = searchBST(T, deleteKey);			// 삭제하고자하는 노드
		node* q = searchParentBST(T, deleteKey);	// 삭제하고자하는 노드의 부모노드
		node* r;
		string flag = "";

		if (noNodes(root) == 0)		// 트리가 비어있다면
			return;					// 종료
		
		if (noNodes(root) == 1)		// root노드만 남아있을경우 
		{
			root = NULL;			// 트리를 빈트리로 만들어준다.
			return;
		}
		
		if (p->left == NULL && p->right == NULL)		// 자식 노드가 없다면
		{
			if (q->left == p)							
				q->left = NULL;
			else
				q->right = NULL;
		}
		else if (p->left == NULL || p->right == NULL)	// 자식 노드가 하나라면 
		{
			if (p->left != NULL)
			{
				if (q->left == p)
					q->left = p->left;
				else
					q->right = p->left;
			}
			else
			{
				if (q->left == p)
					q->left = p->right;
				else
					q->right = p->right;
			}

			if (noNodes(root) == 2)		// 총 노드의 수가 2개이고 이 때 루트 노드를 삭제하고자 한다면
			{
				if (root->right != NULL)
					root->key = root->right->key;
				else
					root->key = root->left->key;
				root->right = NULL;
				root->left = NULL;
			}
		}
		else if (p->left != NULL && p->right != NULL)	// 자식 노드가 2개라면
		{
			if (height(p->left) > height(p->right))		// 왼쪽트리의 높이가 더 크다면
			{
				r = maxNode(p->left);					// 왼쪽 트리에서 최댓값
				flag = "LEFT";
			}
			else if (height(p->left) < height(p->right))	// 오른쪽 트리의 높이가 더 크다면
			{
				r = minNode(p->right);						// 오른쪽 트리에서 최솟값
				flag = "RIGHT";
			}
			else                                            // 좌우측 트리의 높이가 같은 경우    
			{												// 좌우측의 트리의 노드의 갯수를 비교
				if (noNodes(p->left) >= noNodes(p->right))	// 왼쪽의 노드갯수가 많거나 같다면
				{
					r = maxNode(p->left);					// 왼쪽트리에서 최댓값을 갖는다.
					flag = "LEFT";
				}
				else                                        // 오른쪽의 노드갯수가 많다면
				{
					r = minNode(p->right);					// 오른쪽트리에서 최솟값을 갖는다.
					flag = "RIGHT";
				}
			}
			p->key = r->key;		// 삭제하려는 노드에 최소 혹은 최댓값의 값을 복사
			if (flag == "LEFT")				// 왼쪽 트리에서 최댓값을 갖는다면
				deleteBST(p->left, r->key);	
			else                            // 오른쪽 트리에서 최솟값을 갖는다면
				deleteBST(p->right, r->key);
		}
	}
};

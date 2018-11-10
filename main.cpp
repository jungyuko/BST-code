int main()
{
	BST* t = new BST();
	t->Insert_Start();		// 삽입시작
	t->InsertBST(t->root, 8); t->printInorder();
	t->InsertBST(t->root, 18); t->printInorder();
	t->InsertBST(t->root, 11); t->printInorder();
	t->InsertBST(t->root, 5); t->printInorder();
	t->InsertBST(t->root, 15); t->printInorder();
	t->InsertBST(t->root, 4); t->printInorder();
	t->InsertBST(t->root, 9); t->printInorder();
	t->InsertBST(t->root, 1); t->printInorder();
	t->InsertBST(t->root, 7); t->printInorder();
	t->InsertBST(t->root, 17); t->printInorder();
	t->InsertBST(t->root, 6); t->printInorder();
	t->InsertBST(t->root, 14); t->printInorder();
	t->InsertBST(t->root, 10); t->printInorder();
	t->InsertBST(t->root, 3); t->printInorder();
	t->InsertBST(t->root, 19); t->printInorder();
	t->InsertBST(t->root, 20); t->printInorder();
	t->Insert_End();
	cout << endl;

	t->Delete_Start();		// 삭제 시작
	t->deleteBST(t->root, 8); t->printInorder();
	t->deleteBST(t->root, 18); t->printInorder();
	t->deleteBST(t->root, 11); t->printInorder();
	t->deleteBST(t->root, 5); t->printInorder();
	t->deleteBST(t->root, 15); t->printInorder();
	t->deleteBST(t->root, 4); t->printInorder();
	t->deleteBST(t->root, 9); t->printInorder();
	t->deleteBST(t->root, 1); t->printInorder();
	t->deleteBST(t->root, 7); t->printInorder();
	t->deleteBST(t->root, 17); t->printInorder();
	t->deleteBST(t->root, 6); t->printInorder();
	t->deleteBST(t->root, 14); t->printInorder();
	t->deleteBST(t->root, 10); t->printInorder();
	t->deleteBST(t->root, 3); t->printInorder();
	t->deleteBST(t->root, 19); t->printInorder();
	t->deleteBST(t->root, 20); t->printInorder();
	t->Delete_End();
	cout << endl;

	t->Insert_Start();		// 삽입시작
	t->InsertBST(t->root, 8); t->printInorder();
	t->InsertBST(t->root, 18); t->printInorder();
	t->InsertBST(t->root, 11); t->printInorder();
	t->InsertBST(t->root, 5); t->printInorder();
	t->InsertBST(t->root, 15); t->printInorder();
	t->InsertBST(t->root, 4); t->printInorder();
	t->InsertBST(t->root, 9); t->printInorder();
	t->InsertBST(t->root, 1); t->printInorder();
	t->InsertBST(t->root, 7); t->printInorder();
	t->InsertBST(t->root, 17); t->printInorder();
	t->InsertBST(t->root, 6); t->printInorder();
	t->InsertBST(t->root, 14); t->printInorder();
	t->InsertBST(t->root, 10); t->printInorder();
	t->InsertBST(t->root, 3); t->printInorder();
	t->InsertBST(t->root, 19); t->printInorder();
	t->InsertBST(t->root, 20); t->printInorder();
	t->Insert_End();
	cout << endl;

	t->ReverseDelete_Start();		// 역순 삭제 시작
	t->deleteBST(t->root, 20); t->printInorder();
	t->deleteBST(t->root, 19); t->printInorder();
	t->deleteBST(t->root, 3); t->printInorder();
	t->deleteBST(t->root, 10); t->printInorder();
	t->deleteBST(t->root, 14); t->printInorder();
	t->deleteBST(t->root, 6); t->printInorder();
	t->deleteBST(t->root, 17); t->printInorder();
	t->deleteBST(t->root, 7); t->printInorder();
	t->deleteBST(t->root, 1); t->printInorder();
	t->deleteBST(t->root, 9); t->printInorder();
	t->deleteBST(t->root, 4); t->printInorder();
	t->deleteBST(t->root, 15); t->printInorder();
	t->deleteBST(t->root, 5); t->printInorder();
	t->deleteBST(t->root, 11); t->printInorder();
	t->deleteBST(t->root, 18); t->printInorder();
	t->deleteBST(t->root, 8); t->printInorder();
	t->Delete_End();
}

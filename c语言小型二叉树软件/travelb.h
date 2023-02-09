void ShowBtreeOrder(BtreeQueue* lpQueue)
{
	BtreeNode* BNode1,*BNode2;
	popQueueNode(lpQueue,&BNode1);
	SetColorAndShape(&BNode1,BNode1,4,4,15);
	while(popQueueNode(lpQueue,&BNode2))
	{
		SetColorAndShape(&BNode2,BNode1,4,4,15);
		BNode1 = BNode2;	
	}
}
/*先序递归遍历二叉树*/
void PreOrder(BtreeNode* lpStree,BtreeQueue* lpQueue)
{
	if(lpStree)
	{
		pushQueueNode(lpQueue,NewQueueNode(lpStree));
		PreOrder(lpStree->lchild,lpQueue);
		PreOrder(lpStree->rchild,lpQueue);
	}
}
/*中序递归遍历二叉树*/
void InOrder(BtreeNode* lpStree,BtreeQueue* lpQueue)
{
	if(lpStree)
	{
		InOrder(lpStree->lchild,lpQueue);
		pushQueueNode(lpQueue,NewQueueNode(lpStree));
		InOrder(lpStree->rchild,lpQueue);
	}
}
/*中序递归遍历二叉树*/
void PostOrder(BtreeNode* lpStree,BtreeQueue* lpQueue)
{
	if(lpStree)
	{
		PostOrder(lpStree->lchild,lpQueue);
		PostOrder(lpStree->rchild,lpQueue);
		pushQueueNode(lpQueue,NewQueueNode(lpStree));
	}
}
int LevelOrder(BtreeNode* lpStree,BtreeQueue* lpQueue)
{
	QueueNode* lpQNode;
	BtreeNode* BNode1,*BNode2;
	if(!lpStree)
		return 0;
	pushQueueNode(lpQueue,NewQueueNode(lpStree));
	lpQNode = lpQueue->front->next;
	while(lpQNode!=0)
	{
		if(lpQNode->BNode->lchild)
			pushQueueNode(lpQueue,NewQueueNode(lpQNode->BNode->lchild));
		if(lpQNode->BNode->rchild)
			pushQueueNode(lpQueue,NewQueueNode(lpQNode->BNode->rchild));
		lpQNode = lpQNode->next;
	}
	return 1;
}
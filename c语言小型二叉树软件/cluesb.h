void PromptWord()
{
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(500,20,"no pre & next");
	outtextxy(500,40,"pre exist");
	outtextxy(500,60,"next exist");
	outtextxy(500,80,"pre & next exist");
	
	setcolor(RED);        /*设置不同作图色*/
	circle(480,16,5);
	setfillstyle(1,RED);
	floodfill(480,16,RED); /*填充图形*/
	line(450,16,470,16);
	
	setcolor(LIGHTBLUE);        /*设置不同作图色*/
	circle(480,36,5);
	setfillstyle(1,LIGHTBLUE);
	floodfill(480,36,LIGHTBLUE); /*填充图形*/
	line(450,36,470,36);
	
	setcolor(DARKGRAY);        /*设置不同作图色*/
	circle(480,56,5);
	setfillstyle(1,DARKGRAY);
	floodfill(480,56,DARKGRAY); /*填充图形*/
	line(450,56,470,56);
	
	setcolor(CYAN);        /*设置不同作图色*/
	circle(480,76,5);
	setfillstyle(1,CYAN);
	floodfill(480,76,CYAN); /*填充图形*/
	line(450,76,470,76);
}
void ThreadQueue(BtreeQueue* lpQueue,BtreeNode** BNode1,BtreeNode** BNode2)
{
	BtreeNode* head;
	popQueueNode(lpQueue,BNode2);
	head = *BNode2;
	if((*BNode2)->rtag==1&&lpQueue->front!=lpQueue->rear)
		(*BNode2)->rchild = lpQueue->front->next->BNode;
	while(popQueueNode(lpQueue,BNode1))
	{
		if((*BNode1)->ltag==1)
			(*BNode1)->lchild = *BNode2;
		if((*BNode1)->rtag==1&&lpQueue->front!=lpQueue->rear)
			(*BNode1)->rchild = lpQueue->front->next->BNode;
		*BNode2 = *BNode1;
	}
	*BNode1 = head;
}
/*图形演示先序遍历线索化后二叉树*/
void ShowPreThread(BtreeQueue* lpQueue)
{
	BtreeNode* BNode1,*BNode2,*lpNode;
	PromptWord();
	ThreadQueue(lpQueue,&BNode1,&BNode2);
	lpNode = BNode1;
	SetColorAndShape(&lpNode,BNode1,RED,RED,15);/*没有前驱没有后继*/
	while(1)
	{
		if(BNode1==BNode2)
			break;
		if(BNode1->ltag)
		{
			lpNode = BNode1->rchild;
			if(lpNode->ltag)
			{
				if(BNode1->rtag)
				{
					if(!lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,CYAN,15); /*有前驱没有后继*/
					else
					{
						if(lpNode->rchild)
							SetColorAndShape(&lpNode,BNode1,CYAN,CYAN,15); /*有前驱有后继*/
						else
							SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,CYAN,15); /*有前驱没有后继*/
					}
				}
				else
				{
					if(!lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
					else
					{
						if(lpNode->rchild)
							SetColorAndShape(&lpNode,BNode1,CYAN,DARKGRAY,15); /*有前驱有后继*/
						else
							SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
					}
				}
			}
			else
			{
				if(BNode1->rtag)
				{
					if(!lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,RED,LIGHTBLUE,15); /*没有前驱没有后继*/
					else
					{
						if(lpNode->rchild)
							SetColorAndShape(&lpNode,BNode1,DARKGRAY,LIGHTBLUE,15); /*没有前驱有后继*/
						else
							SetColorAndShape(&lpNode,BNode1,RED,LIGHTBLUE,15); /*没有前驱没有后继*/
					}
				}
				else
				{
					if(!lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,RED,RED,15); /*没有前驱没有后继*/
					else
					{
						if(lpNode->rchild)
							SetColorAndShape(&lpNode,BNode1,DARKGRAY,RED,15); /*没有前驱有后继*/
						else
							SetColorAndShape(&lpNode,BNode1,RED,RED,15); /*没有前驱没有后继*/
					}
				}
			}
		}
		else
		{
			lpNode = BNode1->lchild;
			if(lpNode->ltag)
			{
				if(!lpNode->rtag)
					SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
				else
				{
					if(lpNode->rchild)
						SetColorAndShape(&lpNode,BNode1,CYAN,DARKGRAY,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
				}
			}
			else
			{
				if(!lpNode->rtag)
					SetColorAndShape(&lpNode,BNode1,RED,RED,15); /*没有前驱没有后继*/
				else
				{
					if(lpNode->rchild)
						SetColorAndShape(&lpNode,BNode1,DARKGRAY,RED,15); /*没有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,RED,RED,15); /*没有前驱没有后继*/
				}
			}
		}
		BNode1 = lpNode;
	}
}
 void ShowInThread(BtreeQueue* lpQueue)
{
	BtreeNode* BNode1,*BNode2,*lpNode;
	PromptWord();
	ThreadQueue(lpQueue,&BNode1,&BNode2);
	lpNode = BNode1;
	SetColorAndShape(&lpNode,BNode1,DARKGRAY,DARKGRAY,15);/*没有前驱有后继*/
	while(1) 
	{
		if(BNode1==BNode2)
			break;
		lpNode = BNode1->rchild;
		if(lpNode->ltag)
		{
			if(BNode1->rtag)
			{
				if(lpNode->rtag)
				{
					if(lpNode->rchild)
						SetColorAndShape(&lpNode,BNode1,CYAN,CYAN,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,CYAN,15); /*有前驱没有后继*/
				}
				else
					SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,CYAN,15); /*有前驱没有后继*/
			}
			else
			{
				while(!lpNode->ltag)
					lpNode = lpNode->lchild;
				if(lpNode->rtag)
				{
					if(lpNode->rchild)
						SetColorAndShape(&lpNode,BNode1,CYAN,DARKGRAY,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
				}
				else
					SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
			}
		}
		else
		{
			if(BNode1->rtag)
			{
				if(lpNode->rtag)
				{
					if(lpNode->rchild)
						SetColorAndShape(&lpNode,BNode1,DARKGRAY,LIGHTBLUE,15); /*没有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,RED,LIGHTBLUE,15); /*没有前驱没有后继*/
				}
				else
					SetColorAndShape(&lpNode,BNode1,RED,LIGHTBLUE,15); /*没有前驱没有后继*/
			}
			else
			{
				while(!lpNode->ltag)
					lpNode = lpNode->lchild;
				if(lpNode->rtag)
				{
					if(lpNode->rchild)
						SetColorAndShape(&lpNode,BNode1,CYAN,DARKGRAY,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
				}
				else
					SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,DARKGRAY,15); /*有前驱没有后继*/
			}
		}
		BNode1 = lpNode;
	}
}
	
void ShowPostThread(BtreeList* lpBtree,BtreeQueue* lpQueue)
{
	BtreeNode* BNode1,*BNode2,*lpNode,*LastB;
	BtreeQueue* lpQueueS;
	PromptWord();
	lpQueueS = CreateQueue();
	PostOrder(lpBtree->head->lchild,lpQueueS);
	ThreadQueue(lpQueue,&BNode1,&BNode2);
	lpNode = BNode1;
	SetColorAndShape(&lpNode,BNode1,DARKGRAY,DARKGRAY,15);/*没有前驱有后继*/
	popQueueNode(lpQueueS,&LastB);
	while(1)
	{
		if(BNode1==BNode2)
			break;
		if(lpNode->rtag)
		{
			lpNode = lpNode->rchild;
			if(lpNode->ltag)
			{
				if(BNode1->rtag)
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,CYAN,CYAN,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,CYAN,15); /*有前驱没有后继*/
				}
				else
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,CYAN,LIGHTBLUE,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,LIGHTBLUE,15); /*有前驱没有后继*/
				}
			}
			else
			{
				if(BNode1->rtag)
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,DARKGRAY,DARKGRAY,15); /*没有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,RED,DARKGRAY,15); /*没有前驱没有后继*/
				}
				else
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,DARKGRAY,RED,15); /*没有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,RED,RED,15); /*没有前驱没有后继*/
				}		
			}
			popQueueNode(lpQueueS,&LastB);
		}
		else
		{
			lpNode = lpQueueS->front->next->BNode;
			if(lpNode->ltag)
			{
				if(BNode1->rtag)
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,CYAN,CYAN,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,CYAN,15); /*有前驱没有后继*/
				}
				else
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,CYAN,LIGHTBLUE,15); /*有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,LIGHTBLUE,LIGHTBLUE,15); /*有前驱没有后继*/
				}
			}
			else
			{
				if(BNode1->rtag)
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,DARKGRAY,LIGHTBLUE,15); /*没有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,RED,LIGHTBLUE,15); /*没有前驱没有后继*/
				}
				else
				{
					if(lpNode->rtag)
						SetColorAndShape(&lpNode,BNode1,DARKGRAY,RED,15); /*没有前驱有后继*/
					else
						SetColorAndShape(&lpNode,BNode1,RED,RED,15); /*没有前驱没有后继*/
				}
			}
			popQueueNode(lpQueueS,&LastB);
		}
		BNode1 = lpNode;
	}
	DeleteQueue(lpQueueS);
}
void lrThread(BtreeNode**  lpStree)
{
	if(!(*lpStree)->lchild)
		(*lpStree)->ltag = 1;
	else
		(*lpStree)->ltag = 0;
	if(!(*lpStree)->rchild)
		(*lpStree)->rtag = 1;
	else
		(*lpStree)->rtag = 0;
	
}
/*先序线索化二叉树*/
void BtreePreThread(BtreeNode** lpStree,BtreeQueue* lpQueue)
{
	if(*lpStree)
	{
		lrThread(lpStree);
		pushQueueNode(lpQueue,NewQueueNode(*lpStree));
		BtreePreThread(&(*lpStree)->lchild,lpQueue);
		BtreePreThread(&(*lpStree)->rchild,lpQueue);
	}
}
/*中序线索化二叉树*/
void BtreeInThread(BtreeNode** lpStree,BtreeQueue* lpQueue)
{
	if(*lpStree)
	{
		BtreeInThread(&(*lpStree)->lchild,lpQueue);
		lrThread(lpStree);
		pushQueueNode(lpQueue,NewQueueNode(*lpStree));
		BtreeInThread(&(*lpStree)->rchild,lpQueue);
	}
}
/*后序线索化二叉树*/
void BtreePostThread(BtreeNode** lpStree,BtreeQueue* lpQueue)
{
	if(*lpStree)
	{
		BtreePostThread(&(*lpStree)->lchild,lpQueue);
		BtreePostThread(&(*lpStree)->rchild,lpQueue);
		lrThread(lpStree);
		pushQueueNode(lpQueue,NewQueueNode(*lpStree));
	}
}
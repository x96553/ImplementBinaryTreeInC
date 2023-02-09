typedef char EleType;
/*定义二叉树节点*/
typedef struct Btree{
	int x,y,X,Y;
	EleType dataC;
	int ltag,rtag;
	struct Btree *lchild,*rchild;
	void (*func)(struct Btree* ,int ,int );
}BtreeNode;
/*定义指向二叉树的指针*/
typedef struct{
	BtreeNode *head;
}BtreeList;
/*作图函数*/
void SetColorAndShape(BtreeNode* NewNode,int Gr,int Cr)
{
	char ch[1];

	setbkcolor(BLACK);
	
	setcolor(Gr);        /*设置不同作图色*/
	circle(NewNode->x,NewNode->y,10);
	setfillstyle(1,Gr);
	floodfill(NewNode->x,NewNode->y,Gr); /*填充图形*/

	setcolor(Cr);       /*作图色为白色*/
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	sprintf(ch,"%c",NewNode->dataC);
	outtextxy(NewNode->x,NewNode->y, ch);
	
	setcolor(Gr);
	line(NewNode->x, NewNode->y, NewNode->X, NewNode->Y); 
	
	delay(100);
}


/*创建二叉树节点*/
BtreeNode* NewBtreeNode(EleType dataC,int x,int y,int X,int Y)
{
	BtreeNode* NewNode;
	NewNode = (BtreeNode* )malloc(sizeof(BtreeNode));
	if(!NewNode)
		return 0;
	NewNode->dataC = dataC;
	NewNode->x = x;
	NewNode->y = y;
	NewNode->X = X;
	NewNode->Y = Y;
	NewNode->ltag = 0;
	NewNode->rtag = 0;
	if(dataC!=0)
	{
		NewNode->func = SetColorAndShape;
		NewNode->func(NewNode,2,15);
	}
	NewNode->lchild = 0;
	NewNode->rchild = 0;
	return NewNode;
}
/*先序递归遍历创建二叉树*/
void FirstRecursiveCreate(BtreeNode** lpChild,BtreeNode* lpNode,EleType dataC,
FILE* BtreeTxt,void (*BackFunc)(BtreeNode* ,BtreeNode*))
{
	if(dataC!='.')
	{
		(*lpChild) = NewBtreeNode(dataC,x,y,X,Y);
		xy = xy/2;
 		if(!feof(BtreeTxt))
		{
			FirstRecursiveCreate(&(*lpChild)->lchild,getc(BtreeTxt),BtreeTxt,
			CallBackl);
			FirstRecursiveCreate(&(*lpChild)->rchild,getc(BtreeTxt),BtreeTxt,
			CallBackr); 
		}
	}
}
void CallBackl()
{
	
}
void CallBackr()
{
	
}
/*创建指向二叉树的头节点*/
BtreeList* CreateBtree(char* argv)
{
	BtreeList* lpBtree;
	FILE* BtreeTxt = fopen(argv,"r");
	lpBtree = (BtreeList* )malloc(sizeof(BtreeList));
	if(!lpBtree)
		return 0;
	lpBtree->head = NewBtreeNode(0,640,60);
	if(!lpBtree->head)
	{
		free(lpBtree);
		return 0;
	}
	fseek(BtreeTxt,0,SEEK_SET);
	if(!feof(BtreeTxt)&&ftell(BtreeTxt)==0)
	{
		FirstRecursiveCreate(&(lpBtree->head->lchild),lpBtree->head,
		getc(BtreeTxt),BtreeTxt,CallBackl);
	}
	fclose(BtreeTxt);
	return lpBtree;
}
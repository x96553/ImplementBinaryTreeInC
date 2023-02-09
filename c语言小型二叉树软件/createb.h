/*定义字符类型*/
typedef char EleType;
/*定义二叉树节点*/
typedef struct Btree{
	int x,y,Gr,Lr,Cr;
	EleType dataC;
	int ltag,rtag;
	struct Btree *lchild,*rchild;
}BtreeNode;
/*定义指向二叉树的头指针*/
typedef struct{
	BtreeNode *head;
}BtreeList;
/*作图函数*/
void SetColorAndShape(BtreeNode** lpStree,BtreeNode* lpFtree,int Gr,int Lr,int Cr)
{
	char ch[1];
	(*lpStree)->Gr = Gr;
	(*lpStree)->Lr = Lr;
	(*lpStree)->Cr = Cr;
	setbkcolor(BLACK);
	setcolor(Gr);        /*设置不同作图色*/
	circle((*lpStree)->x,(*lpStree)->y,10);
	setfillstyle(1,Gr);
	floodfill((*lpStree)->x,(*lpStree)->y,Gr); /*填充图形*/
	setcolor(Cr);       /*作图色为白色*/
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	sprintf(ch,"%c",(*lpStree)->dataC);
	outtextxy((*lpStree)->x,(*lpStree)->y, ch);
	setcolor(Lr);
	if(lpFtree->x==640&&lpFtree->y==0&&lpFtree->dataC==0)
		line((*lpStree)->x, (*lpStree)->y, (*lpStree)->x,(*lpStree)->y); 
	else
	{
		line((*lpStree)->x, (*lpStree)->y, lpFtree->x,lpFtree->y);
		setcolor(lpFtree->Gr);        /*设置不同作图色*/
		circle(lpFtree->x,lpFtree->y,10);
		setfillstyle(1,lpFtree->Gr);
		floodfill(lpFtree->x,lpFtree->y,lpFtree->Gr); /*填充图形*/
		setcolor(lpFtree->Cr);       /*作图色为白色*/
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		sprintf(ch,"%c",lpFtree->dataC);
		outtextxy(lpFtree->x,lpFtree->y, ch);
	}
	delay(100);
}
/*创建二叉树节点*/
BtreeNode* NewBtreeNode(EleType dataC,int x,int y)
{
	BtreeNode* NewNode;
	NewNode = (BtreeNode* )malloc(sizeof(BtreeNode));
	if(!NewNode)
		return 0;
	NewNode->dataC = dataC;
	NewNode->x = x;
	NewNode->y = y;
	NewNode->Cr = 0;
	NewNode->Gr = 0;
	NewNode->Lr = 0;
	NewNode->ltag = 0;
	NewNode->rtag = 0;
	NewNode->lchild = 0;
	NewNode->rchild = 0;
	return NewNode;
}
/*删除树中的节点*/
void DeleteBtreeNode(BtreeNode** lpStree)
{
	if(*lpStree)
	{
		DeleteBtreeNode(&(*lpStree)->lchild);
		DeleteBtreeNode(&(*lpStree)->rchild);
		free(*lpStree);
	}
}
/*销毁树*/
void DeleteBtree(BtreeList** lpBtree)
{
	if((*lpBtree)->head->lchild)
		DeleteBtreeNode(&(*lpBtree)->head->lchild);
	if((*lpBtree)->head)
		free((*lpBtree)->head);
	if((*lpBtree))
		free(*lpBtree);
}
BtreeNode* CallBackl(BtreeNode* lpFtree,EleType dataC)
{
	BtreeNode* lpStree;
	int wideX,cX;
	cX = (lpFtree->y+80)/80;
	wideX = 640;
	while(cX>0)
	{
		wideX = wideX/2;
		cX--;
	}
	lpStree = NewBtreeNode(dataC,lpFtree->x-wideX,lpFtree->y+80);
	if(!lpStree)
		return 0;
	return lpStree;
}
BtreeNode* CallBackr(BtreeNode* lpFtree,EleType dataC)
{
	BtreeNode* lpStree;
	int wideX,cX;
	cX = (lpFtree->y+80)/80;
	wideX = 640;
	while(cX>0)
	{
		wideX = wideX/2;
		cX--;
	}
	lpStree = NewBtreeNode(dataC,lpFtree->x+wideX,lpFtree->y+80);
	if(!lpStree)
		return 0;
	return lpStree;
}
/*先序递归遍历创建二叉树*/
void PreOrderCreate(BtreeNode** lpStree,BtreeNode* lpFtree,FILE* BtreeTxt,
BtreeNode* (*BackFunc)(BtreeNode* ,EleType ))
{
	EleType dataC;
	dataC = getc(BtreeTxt);
	if(dataC!='.'&&dataC!=-1)
	{
 		(*lpStree) = BackFunc(lpFtree,dataC);
		SetColorAndShape(lpStree,lpFtree,2,2,15);
		PreOrderCreate(&(*lpStree)->lchild,*lpStree,BtreeTxt,CallBackl);	
		PreOrderCreate(&(*lpStree)->rchild,*lpStree,BtreeTxt,CallBackr); 
	}
}
/*对将要创建的树进行判断*/
int JudgeBtree(BtreeNode** lpStree,FILE* BtreeTxt)
{
	EleType dataC;
	int height1,height2;
	dataC = getc(BtreeTxt);
	if(dataC!='.'&&dataC!=-1)
	{
		(*lpStree) = NewBtreeNode(dataC,0,0);
		height1 = JudgeBtree(&(*lpStree)->lchild,BtreeTxt);
		height2 = JudgeBtree(&(*lpStree)->rchild,BtreeTxt);
		if(height1>height2)
			return height1 + 1;
		return height2 + 1;
	}
	return 0;
}
/*创建指向二叉树的头节点*/
BtreeList* CreateBtree(char* argv)
{
	EleType dataC1,dataC2,SpaceC1,SpaceC2;
	int BtreeTxtI;
	BtreeList* lpBtree;	
	FILE* BtreeTxt = fopen(argv,"r");
	lpBtree = (BtreeList* )malloc(sizeof(BtreeList));
	if(!lpBtree)
		return 0;
	lpBtree->head = NewBtreeNode(0,640,0);
	if(!lpBtree->head)
	{
		free(lpBtree);
		return 0;
	}
	fseek(BtreeTxt,0,SEEK_SET);
	if(ftell(BtreeTxt)==0)
	{
		if(JudgeBtree(&(lpBtree->head->lchild),BtreeTxt)<=5)
		{
			BtreeTxtI = 0;
			dataC1 = 0;
			dataC2 = 0;
			SpaceC1 = ftell(BtreeTxt)-1;
			fseek(BtreeTxt,BtreeTxtI,SEEK_SET);
			while(1)
			{
				dataC1 = getc(BtreeTxt);
				if(SpaceC1==BtreeTxtI||dataC1==-1)
					break;
				while(1)
				{
					SpaceC2 = ftell(BtreeTxt);
					dataC2 = getc(BtreeTxt);
					if(SpaceC1==SpaceC2||dataC2==-1)
						break;
					if(dataC1==dataC2)
						if(dataC1!='.'&&dataC2!='.')
							break;
				}
				if(dataC1==dataC2)
					if(dataC1!='.'&&dataC2!='.')
						break;
				BtreeTxtI++;
				fseek(BtreeTxt,BtreeTxtI,SEEK_SET);
			}
			if(SpaceC1==BtreeTxtI&&SpaceC2==BtreeTxtI||dataC1==-1&&dataC2==-1)
			{
				fseek(BtreeTxt,0,SEEK_SET);
				if(ftell(BtreeTxt)==0)
				{
					DeleteBtreeNode(&(lpBtree->head->lchild));
					fseek(BtreeTxt,0,SEEK_SET);
					if(ftell(BtreeTxt)==0)
						PreOrderCreate(&(lpBtree->head->lchild),lpBtree->head,BtreeTxt,CallBackl);
					fclose(BtreeTxt);
					return lpBtree;
				}
			}
			else
			{
				DeleteBtree(&lpBtree);
				fclose(BtreeTxt);
				cleardevice();
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(CENTER_TEXT,CENTER_TEXT);
				outtextxy(320,80,"Failed to build a tree");
				outtextxy(320,240,"Has the same elements");
				outtextxy(320,280,"OR");
				outtextxy(320,320,"There are no elements in the file");
			}
		}
		else
		{
			DeleteBtree(&lpBtree);
			fclose(BtreeTxt);
			cleardevice();
			/*在图形中编写字体*/
			setcolor(YELLOW);       /*作图色为黄色*/
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			outtextxy(320,80,"Failed to build a tree");
			outtextxy(320,240,"Is more than five levels high");
		}
	}
	return 0;
}
void PreOrderRe(BtreeNode** lpStree,BtreeNode* lpFtree)
{
	if(*lpStree)
	{
		SetColorAndShape(lpStree,lpFtree,2,2,15);
		if((*lpStree)->ltag==0)
			PreOrderRe(&(*lpStree)->lchild,*lpStree);
		else
		{
			(*lpStree)->lchild = 0;
			(*lpStree)->ltag = 0;
		}
		if((*lpStree)->rtag==0)		
			PreOrderRe(&(*lpStree)->rchild,*lpStree); 
		else
		{
			(*lpStree)->rchild = 0;
			(*lpStree)->rtag = 0;
		}
	}
}
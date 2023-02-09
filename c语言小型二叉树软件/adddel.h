/*求树高*/
int TreeHeight(BtreeNode*lpStree)
{
	int height1,height2;
	if(!lpStree)
		return 0;
	else
	{
		height1 = TreeHeight(lpStree->lchild);
		height2 = TreeHeight(lpStree->rchild);
		if(height1>height2)
			return height1 + 1;
		return height2 + 1;
	}
}
/*先序搜索用户需要查找的节点*/
void PreFindNode(BtreeNode* lpStree,BtreeNode** FindNode,EleType FindC)
{
	if(lpStree)
	{
		SetColorAndShape(&lpStree,lpStree,4,2,15);
		if(lpStree->dataC==FindC)
			*FindNode = lpStree;
		else
			SetColorAndShape(&lpStree,lpStree,2,2,15);
		PreFindNode(lpStree->lchild,FindNode,FindC);
		PreFindNode(lpStree->rchild,FindNode,FindC);
	}
}
/*中序搜索用户需要查找的节点*/
void InFindNode(BtreeNode* lpStree,BtreeNode** FindNode,EleType FindC)
{
	if(lpStree)
	{
		InFindNode(lpStree->lchild,FindNode,FindC);
		SetColorAndShape(&lpStree,lpStree,4,2,15);
		if(lpStree->dataC==FindC)
			*FindNode = lpStree;
		else
			SetColorAndShape(&lpStree,lpStree,2,2,15);
		InFindNode(lpStree->rchild,FindNode,FindC);
	}
}
/*后序搜索用户需要查找的节点*/
void PostFindNode(BtreeNode* lpStree,BtreeNode** FindNode,EleType FindC)
{
	if(lpStree)
	{
		PostFindNode(lpStree->lchild,FindNode,FindC);
		PostFindNode(lpStree->rchild,FindNode,FindC);
		SetColorAndShape(&lpStree,lpStree,4,2,15);
		if(lpStree->dataC==FindC)
			*FindNode = lpStree;
		else
			SetColorAndShape(&lpStree,lpStree,2,2,15);
	}
}
/*层次搜索用户需要查找的节点*/
BtreeNode* LevelFindNode(BtreeQueue* lpQueue,EleType FindC)
{
	BtreeNode* BNode1,*FindNode;
	FindNode = 0;
	popQueueNode(lpQueue,&BNode1);
	SetColorAndShape(&BNode1,BNode1,4,2,15);
	if(BNode1->dataC==FindC)
		FindNode = BNode1;
	else
		SetColorAndShape(&BNode1,BNode1,2,2,15);
	while(popQueueNode(lpQueue,&BNode1))
	{
		SetColorAndShape(&BNode1,BNode1,4,2,15);
		if(BNode1->dataC==FindC)
			FindNode = BNode1;
		else
			SetColorAndShape(&BNode1,BNode1,2,2,15);
	}
	return FindNode;
}
/*更改图形显示时左孩子字符的坐标*/
void CallBackChangeX(BtreeNode** lpStree,BtreeNode* lpFtree)
{
	int wideX,cX;
	cX = (lpFtree->y+80)/80;
	wideX = 640;
	while(cX>0)
	{
		wideX = wideX/2;
		cX--;
	}
	(*lpStree)->x = lpFtree->x-wideX,
	(*lpStree)->y = lpFtree->y+80;
}
/*更改图形显示时右孩子字符的坐标*/
void CallBackChangeY(BtreeNode** lpStree,BtreeNode* lpFtree)
{
	int wideX,cX;
	cX = (lpFtree->y+80)/80;
	wideX = 640;
	while(cX>0)
	{
		wideX = wideX/2;
		cX--;
	}
	(*lpStree)->x = lpFtree->x+wideX;
	(*lpStree)->y = lpFtree->y+80;
}
/*遍历并显示插入节点后的树*/
void ShowInertBtree(BtreeNode** lpStree,BtreeNode* lpFtree,void (*BackFuncXY)(BtreeNode** lpStree,BtreeNode* lpFtree))
{
	if(*lpStree)
	{
		BackFuncXY(lpStree,lpFtree);
		SetColorAndShape(lpStree,lpFtree,6,6,15);
		ShowInertBtree(&(*lpStree)->lchild,*lpStree,CallBackChangeX);	
		ShowInertBtree(&(*lpStree)->rchild,*lpStree,CallBackChangeY); 
	}
}
/*清除节点图形*/
void ClearInsertShap(BtreeNode* lpStree,BtreeNode* lpFtree)
{
	if(lpStree)
	{
		ClearInsertShap(lpStree->lchild,lpStree);
		ClearInsertShap(lpStree->rchild,lpStree);
		SetColorAndShape(&lpStree,lpFtree,0,0,0);
	}
}
/*在树中插入节点*/
int InsertBtreeNode(BtreeNode** lpStree,EleType SpaceC,EleType InsertC,char Fatherlr,char Childlr)
{
	BtreeNode* FindNode,*InsertNode;
	FindNode = 0;
	setfillstyle(SOLID_FILL,BLACK); 
	bar(10,452,639,460);
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(10,460,"See if the Btree has the same elements as the insert node.");
	PreFindNode(*lpStree,&FindNode,InsertC);
	if(FindNode->dataC==InsertC)
		return 1;
	FindNode = 0; 
	setfillstyle(SOLID_FILL,BLACK); 
	bar(10,452,639,460); 
	bar(10,472,639,480);
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(10,460,"No element in the Btree is the same as the insert element.Now look for the in-");
	outtextxy(10,480,"sert location.");
	PreFindNode(*lpStree,&FindNode,SpaceC); 
	setfillstyle(SOLID_FILL,BLACK); 
	bar(10,452,639,460); 
	bar(10,472,639,480);
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(10,460,"The insertion location was found successfully.If the tree height of the inser-");
	outtextxy(10,480,"ted node is less than 5, the node will be inserted.");
	if(FindNode==0)
		return 2;
	if(Fatherlr=='l')
	{
		if((FindNode->y/80+TreeHeight(FindNode->lchild))>=5)
			return 3;
		InsertNode = CallBackl(FindNode,InsertC);
		if(Childlr=='l')
		{
			if(FindNode->lchild)
				InsertNode->lchild = FindNode->lchild;
			FindNode->lchild = InsertNode;
		}
		if(Childlr=='r')
		{
			if(FindNode->lchild)
				InsertNode->rchild = FindNode->lchild;
			FindNode->lchild = InsertNode;
		}
		ClearInsertShap(FindNode->lchild,FindNode);
		ShowInertBtree(&InsertNode,FindNode,CallBackChangeX);
	}
	if(Fatherlr=='r')
	{
		if((FindNode->y/80+TreeHeight(FindNode->rchild))>=5)
			return 3;
		InsertNode = CallBackr(FindNode,InsertC);
		if(Childlr=='l')
		{
			if(FindNode->rchild)
				InsertNode->lchild = FindNode->rchild;
			FindNode->rchild = InsertNode;
		}
		if(Childlr=='r')
		{
			if(FindNode->rchild)
				InsertNode->rchild = FindNode->rchild;
			FindNode->rchild =InsertNode;
		}
		ClearInsertShap(FindNode->rchild,FindNode);
		ShowInertBtree(&InsertNode,FindNode,CallBackChangeY);
	}
	return 0;
}
/*删除子树*/
void DeleteSubTree(BtreeNode** lpStree,BtreeNode* lpFtree)
{
	if(*lpStree)
	{
		DeleteSubTree(&(*lpStree)->lchild,*lpStree);
		DeleteSubTree(&(*lpStree)->rchild,*lpStree);
		SetColorAndShape(lpStree,lpFtree,0,0,0);
		free(*lpStree);
	}
}
/*初始化指向删除节点的父节点对应的左右孩子为0*/
void InitChild(BtreeNode** lpStree,BtreeNode* lpDtree)
{
	if(*lpStree)
	{
		if((*lpStree)->lchild->dataC==lpDtree->dataC)
		{
			DeleteSubTree(&(*lpStree)->lchild,(*lpStree));
			(*lpStree)->lchild = 0;
		}
		if((*lpStree)->rchild->dataC==lpDtree->dataC)
		{
			DeleteSubTree(&(*lpStree)->rchild,(*lpStree));
			(*lpStree)->rchild = 0;
		}
		InitChild(&(*lpStree)->lchild,lpDtree);
		InitChild(&(*lpStree)->rchild,lpDtree);
	}
}	
/*查找叶子节点*/
void FindLeafNode(BtreeNode* lpStree)
{
	if(lpStree)
	{
		SetColorAndShape(&lpStree,lpStree,4,2,15);
		if(lpStree->lchild||lpStree->rchild)
			SetColorAndShape(&lpStree,lpStree,2,2,15);
		FindLeafNode(lpStree->lchild);
		FindLeafNode(lpStree->rchild);
	}
}
/*修改对应节点域*/
void AssignNode(BtreeNode** lpStree,BtreeNode** FindNode,EleType CurrentC,EleType AssignC)
{
	if(*lpStree)
	{
		SetColorAndShape(lpStree,*lpStree,4,2,15);
		if((*lpStree)->dataC==CurrentC)
		{
			(*lpStree)->dataC = AssignC;
			SetColorAndShape(lpStree,*lpStree,4,2,15);
			*FindNode = (*lpStree);
			
		}
		else
			SetColorAndShape(lpStree,*lpStree,2,2,15);
		AssignNode(&(*lpStree)->lchild,FindNode,CurrentC,AssignC);
		AssignNode(&(*lpStree)->rchild,FindNode,CurrentC,AssignC);
	}
}
/*显示节点的度*/
void DegreeNode(BtreeNode* lpStree)
{
	if(lpStree)
	{
		if(lpStree->lchild&&lpStree->rchild)
		{
			setcolor(4);        /*设置不同作图色*/
			circle(lpStree->x,lpStree->y+21,7);
			setfillstyle(1,4);
			floodfill(lpStree->x,lpStree->y+21,4); /*填充图形*/
			setcolor(15);       /*作图色为白色*/
			settextjustify(CENTER_TEXT, CENTER_TEXT);
			outtextxy(lpStree->x,lpStree->y+21,"2");
		}
		if(lpStree->lchild&&!lpStree->rchild||!lpStree->lchild&&lpStree->rchild)
		{
			setcolor(4);        /*设置不同作图色*/
			circle(lpStree->x,lpStree->y+21,7);
			setfillstyle(1,4);
			floodfill(lpStree->x,lpStree->y+21,4); /*填充图形*/
			setcolor(15);       /*作图色为白色*/
			settextjustify(CENTER_TEXT, CENTER_TEXT);
			outtextxy(lpStree->x,lpStree->y+21,"1");
		}
		if(!lpStree->lchild&&!lpStree->rchild)
		{
			setcolor(4);        /*设置不同作图色*/
			circle(lpStree->x,lpStree->y+21,7);
			setfillstyle(1,4);
			floodfill(lpStree->x,lpStree->y+21,4); /*填充图形*/
			setcolor(15);       /*作图色为白色*/
			settextjustify(CENTER_TEXT, CENTER_TEXT);
			outtextxy(lpStree->x,lpStree->y+21,"0");
		}
		DegreeNode(lpStree->lchild);
		DegreeNode(lpStree->rchild);
	}
}
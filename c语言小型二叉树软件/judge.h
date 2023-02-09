void AccessInput(char* Mstored,char* Order)
{
	char GetC[1],InC;
	int MstoredC,ScreenOutC,MstartC,MendC;
	setfillstyle(SOLID_FILL,BLACK); 
	bar(82,432,639,440); 
	bar(10,452,639,460); 
	bar(10,472,639,480);
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(10,440,"Command: ");
	outtextxy(10,460,Order);
	for(MstoredC=0 ; MstoredC!=100 ; MstoredC++)
		Mstored[MstoredC] = '\0';
	ScreenOutC= 0;
	MstoredC = 0;
	while(1)
	{
		InC = getch();
		if(InC==0x0d)
			break;
		if(InC==0x08)
		{
			if(MstoredC>0)
			{
				ScreenOutC = ScreenOutC - 8;
				MstoredC--;
				Mstored[MstoredC] = '\0';
				setfillstyle(SOLID_FILL,BLACK); 
				bar(82+ScreenOutC,432,90+ScreenOutC,440); 
			}
		}
		else
		{
			Mstored[MstoredC] = InC;
			sprintf(GetC,"%c",InC);
			outtextxy(82+ScreenOutC,440,GetC);
			ScreenOutC = ScreenOutC + 8;
			MstoredC++;
		}
	}
	Mstored[MstoredC] = '\0';
	MstoredC = 0;
	for(MendC=strlen(Mstored) ; Mstored[MendC]==' ' ; MendC--);
	for(MstartC=0 ; Mstored[MstartC]==' ' ; MstartC++);
	for( ; MstartC<=MendC ; MstartC++)
	{
		Mstored[MstoredC] = Mstored[MstartC];
		MstoredC++;
	}
	Mstored[MstoredC] = '\0';
}
int AskInsert(char* Mstored,char* Fatherlr,char* Childlr,EleType* SpaceC,EleType* InsertC)
{
	char Mcopy[100];
	int MstoredC;
	for(MstoredC=0 ; MstoredC!=100 ; MstoredC++)
		Mcopy[MstoredC] = 0;
	for(MstoredC=0 ; Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0' ; MstoredC++)
		Mcopy[MstoredC] = Mstored[MstoredC];
	Mcopy[MstoredC] = '\0';
	if(!strcmp(Mcopy,"insert"))
	{
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]!='l'&&Mstored[MstoredC]!='r')
			return 0;
		if(Mstored[MstoredC]=='l')
		{
			*Fatherlr = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' ')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]!='l'&&Mstored[MstoredC]!='r')
				return 0;
			if(Mstored[MstoredC]=='l')
			{
				*Childlr = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*SpaceC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*InsertC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				if(Mstored[MstoredC]=='\0')
					return 1;
			}
			if(Mstored[MstoredC]=='r')
			{
				*Childlr = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*SpaceC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*InsertC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				if(Mstored[MstoredC]=='\0')
					return 1;
			}			
		}
		if(Mstored[MstoredC]=='r')
		{
			*Fatherlr = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' ')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]!='l'&&Mstored[MstoredC]!='r')
				return 0;
			if(Mstored[MstoredC]=='l')
			{
				*Childlr = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*SpaceC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*InsertC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				if(Mstored[MstoredC]=='\0')
					return 1;
			}
			if(Mstored[MstoredC]=='r')
			{
				*Childlr = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*SpaceC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' ')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				*InsertC = Mstored[MstoredC];
				MstoredC++;
				if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
					return 0;
				while(Mstored[MstoredC]==' ')
					MstoredC++;
				if(Mstored[MstoredC]=='\0')
					return 1;
			}			
		}
	}
	return 0;
}
int AskFind(char* Mstored,char* FindW,EleType* FindC)
{
	char Mcopy[100];
	int MstoredC;
	for(MstoredC=0 ; MstoredC!=100 ; MstoredC++)
		Mcopy[MstoredC] = 0;
	for(MstoredC=0 ; Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0' ; MstoredC++)
		Mcopy[MstoredC] = Mstored[MstoredC];
	Mcopy[MstoredC] = '\0';
	if(!strcmp(Mcopy,"find"))
	{
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]!='p'&&Mstored[MstoredC]!='i'&&Mstored[MstoredC]!='n'&&
			Mstored[MstoredC]!='l')
			return 0;
		if(Mstored[MstoredC]=='p')
		{
			*FindW = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' ')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 0;
			*FindC = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 1;
		}
		if(Mstored[MstoredC]=='i')
		{
			*FindW = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' ')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 0;
			*FindC = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 1;
		}
		if(Mstored[MstoredC]=='n')
		{
			*FindW = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' ')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 0;
			*FindC = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 1;
		}
		if(Mstored[MstoredC]=='l')
		{
			*FindW = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' ')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 0;
			*FindC = Mstored[MstoredC];
			MstoredC++;
			if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
				return 0;
			while(Mstored[MstoredC]==' ')
				MstoredC++;
			if(Mstored[MstoredC]=='\0')
				return 1;
		}
	}
	return 0;
}
int AskDelete(char* Mstored,EleType* DeleteC)
{
	char Mcopy[100];
	int MstoredC;
	for(MstoredC=0 ; MstoredC!=100 ; MstoredC++)
		Mcopy[MstoredC] = 0;
	for(MstoredC=0 ; Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0' ; MstoredC++)
		Mcopy[MstoredC] = Mstored[MstoredC];
	Mcopy[MstoredC] = '\0';
	if(!strcmp(Mcopy,"del"))
	{
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]=='\0')
			return 0;
		*DeleteC = Mstored[MstoredC];
		MstoredC++;
		if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
			return 0;
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]=='\0')
			return 1;
	}
	return 0;
}
int AskAssign(char* Mstored,EleType* CurrentC,EleType* AssignC)
{
	char Mcopy[100];
	int MstoredC;
	for(MstoredC=0 ; MstoredC!=100 ; MstoredC++)
		Mcopy[MstoredC] = 0;
	for(MstoredC=0 ; Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0' ; MstoredC++)
		Mcopy[MstoredC] = Mstored[MstoredC];
	Mcopy[MstoredC] = '\0';
	if(!strcmp(Mcopy,"assign"))
	{
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]=='\0')
			return 0;
		*CurrentC = Mstored[MstoredC];
		MstoredC++;
		if(Mstored[MstoredC]!=' ')
			return 0;
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]=='\0')
			return 0;
		*AssignC = Mstored[MstoredC];
		MstoredC++;
		if(Mstored[MstoredC]!=' '&&Mstored[MstoredC]!='\0')
			return 0;
		while(Mstored[MstoredC]==' ')
			MstoredC++;
		if(Mstored[MstoredC]=='\0')
			return 1;
	}
	return 0;
}
/*判断命令输入，执行用户需要的功能*/
void JudgeInput(BtreeList* lpBtree)
{
	/*定义变量*/

	char Fatherlr,Childlr,SpaceC,InsertC,FindC,FindW;
	char Mstored[100],*text;
	int InsertF;
	BtreeQueue* lpQueue;	
	BtreeNode* FindNode;
	lpQueue = CreateQueue();
	setfillstyle(SOLID_FILL,BLACK); 
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
	while(1)
	{
		AccessInput(Mstored,text);
		if(!strcmp(Mstored,"exit"))
			break;
		else if(!strcmp(Mstored,"btree"))
		{
			if(lpBtree->head->lchild)
			{	
				cleardevice();
				PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
				text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
			}
			else
				text = "Tip:Create Btree false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"preorder"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Is traversing first in order");
				PreOrder(lpBtree->head->lchild,lpQueue);
				ShowBtreeOrder(lpQueue);
				AccessInput(Mstored,"Tip:Preorder success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Preorder false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"inorder"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Middle order traversal in progress");
				InOrder(lpBtree->head->lchild,lpQueue);
				ShowBtreeOrder(lpQueue);
				AccessInput(Mstored,"Tip:Inorder success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Inorder false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"postorder"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Is traversing in post order");
				PostOrder(lpBtree->head->lchild,lpQueue);
				ShowBtreeOrder(lpQueue);
				AccessInput(Mstored,"Tip:Postorder success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Postorder false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"levorder"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Level traversing");
				LevelOrder(lpBtree->head->lchild,lpQueue);
				ShowBtreeOrder(lpQueue);
				AccessInput(Mstored,"Tip:Levelorder success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Levelorder false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"prethread"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Is preordering cue traversal");
				BtreePreThread(&lpBtree->head->lchild,lpQueue);
				ShowPreThread(lpQueue);
				AccessInput(Mstored,"Tip:Prethread success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Prethread false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"inthread"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"In the middle of the sequence of clues traversal");
				BtreeInThread(&lpBtree->head->lchild,lpQueue);
				ShowInThread(lpQueue); 
				AccessInput(Mstored,"Tip:Inthread success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Inthread false!No element in the Btree!";
		} 
		else if(!strcmp(Mstored,"postthread"))
		{
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Post - sequential cue traversal is under way");
				BtreePostThread(&lpBtree->head->lchild,lpQueue);
				ShowPostThread(lpBtree,lpQueue);
				AccessInput(Mstored,"Tip:Postthread success!");
				while(1)
				{
					if(!strcmp(Mstored,"btree"))
					{
						cleardevice();
						PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
						text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
						break;
					}
					AccessInput(Mstored,"Tip:Input error!please input angin!");
				}
			}
			else
				text = "Tip:Postthread false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"height"))
		{
			if(lpBtree->head->lchild)
				sprintf(text,"Tip:Height of the Btree is:%d!",TreeHeight(lpBtree->head->lchild));
			else
				text = "Tip:Height false!No element in the Btree!";
		}
	    else if(AskFind(Mstored,&FindW,&FindC))
		{ 
			if(lpBtree->head->lchild)
			{
				FindNode = 0;
				if(FindW=='p')
				{
					setfillstyle(SOLID_FILL,BLACK); 
					bar(10,452,639,460); 
					/*在图形中编写字体*/
					setcolor(YELLOW);       /*作图色为黄色*/
					settextjustify(LEFT_TEXT,LEFT_TEXT);
					outtextxy(10,460,"Looking for nodes is being iterated first");
					PreFindNode(lpBtree->head->lchild,&FindNode,FindC);
					if(FindNode!=0)
						text = "Tip:Preorder to find data success!";
					else
						text = "Tip:Preorder to find data false!";
				}
				if(FindW=='i')
				{
					setfillstyle(SOLID_FILL,BLACK); 
					bar(10,452,639,460); 
					/*在图形中编写字体*/
					setcolor(YELLOW);       /*作图色为黄色*/
					settextjustify(LEFT_TEXT,LEFT_TEXT);
					outtextxy(10,460,"The lookup node is being traversed in mid-order");
					InFindNode(lpBtree->head->lchild,&FindNode,FindC);
					if(FindNode!=0)
						text="Tip:Inorder to find data success!";
					else
						text = "Tip:Inorder to find data false!";
				}
				if(FindW=='n')
				{
					setfillstyle(SOLID_FILL,BLACK); 
					bar(10,452,639,460); 
					/*在图形中编写字体*/
					setcolor(YELLOW);       /*作图色为黄色*/
					settextjustify(LEFT_TEXT,LEFT_TEXT);
					outtextxy(10,460,"The lookup node is being iterated in backward order");
					PostFindNode(lpBtree->head->lchild,&FindNode,FindC);
					if(FindNode!=0)
						text = "Tip:Postorder to find data success!";
					else
						text = "Tip:Postorder to find data false!";
				}
				if(FindW=='l')
				{
					setfillstyle(SOLID_FILL,BLACK); 
					bar(10,452,639,460); 
					/*在图形中编写字体*/
					setcolor(YELLOW);       /*作图色为黄色*/
					settextjustify(LEFT_TEXT,LEFT_TEXT);
					outtextxy(10,460,"Searching nodes are being iterated hierarchically");
					LevelOrder(lpBtree->head->lchild,lpQueue);
					FindNode = LevelFindNode(lpQueue,FindC);
					if(FindNode!=0)
						text = "Tip:Levelorder to find data success!";
					else
						text = "Tip:Levelorder to find data false!";
				}
			}
			else
				text = "Tip:Find false!No element in the Btree!";
		} 
		else if(AskInsert(Mstored,&Fatherlr,&Childlr,&SpaceC,&InsertC))
		{ 
			if(!lpBtree->head->lchild)
			{
				lpBtree->head->lchild = CallBackl(lpBtree->head,InsertC);
				SetColorAndShape(&lpBtree->head->lchild,lpBtree->head->lchild,2,2,15);
				text = "Tip:Insert data success!";
			}
			else
			{
				InsertF = InsertBtreeNode(&lpBtree->head->lchild,SpaceC,InsertC,Fatherlr,Childlr);
				if(InsertF==0)
					text = "Tip:Insert data success!";
				if(InsertF==1)
					text = "Tip:Insert data false! Element in the Btree is the same as the insert element!";
				if(InsertF==2)
					text = "look for the insert location false!";
				if(InsertF==3)
					text = "The tree height of the inserted node is more than 5!";
			}
		}
		else if(AskDelete(Mstored,&SpaceC))
		{ 
			if(lpBtree->head->lchild)
			{
				FindNode = 0;
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"See if the Btree has the same elements as the delete node!");
				PreFindNode(lpBtree->head->lchild,&FindNode,SpaceC);
				if(FindNode)
				{
					setfillstyle(SOLID_FILL,BLACK); 
					bar(10,452,639,460); 
					/*在图形中编写字体*/
					setcolor(YELLOW);       /*作图色为黄色*/
					settextjustify(LEFT_TEXT,LEFT_TEXT);
					outtextxy(10,460,"The Btree has the same elements as the delete node! Deleting node!");
					if(lpBtree->head->lchild==FindNode)
					{
						DeleteSubTree(&lpBtree->head->lchild,FindNode);
						lpBtree->head->lchild = 0;
					}
					else
						InitChild(&lpBtree->head->lchild,FindNode);
					text = "Tip:Delete data success!";
				}
				else
					text = "Tip:Delete data false!There are no nodes in the Btree to delete";
			}
			else
				text = "Tip:Delete false!No element in the Btree!";
		}
		else if(AskAssign(Mstored,&SpaceC,&InsertC))
		{ 
			if(lpBtree->head->lchild)
			{
				FindNode = 0;
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"See if the Btree has the same elements as the insert node.");
				PreFindNode(lpBtree->head->lchild,&FindNode,InsertC);
				if(!FindNode)
				{
					setfillstyle(SOLID_FILL,BLACK); 
					bar(10,452,639,460); 
					/*在图形中编写字体*/
					setcolor(YELLOW);       /*作图色为黄色*/
					settextjustify(LEFT_TEXT,LEFT_TEXT);
					outtextxy(10,460,"No element in the Btree is the same as the insert element.Assigning");
					AssignNode(&lpBtree->head->lchild,&FindNode,SpaceC,InsertC);
					if(FindNode)
						text = "Tip:Assign data success!";
					else
						text = "Tip:Assign data false!";
				}
				else
					text = "Tip:Assign data false!";
			}
			else
				text = "Tip:Assign false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"leaf"))
		{ 
			if(lpBtree->head->lchild)
			{
				setfillstyle(SOLID_FILL,BLACK); 
				bar(10,452,639,460); 
				/*在图形中编写字体*/
				setcolor(YELLOW);       /*作图色为黄色*/
				settextjustify(LEFT_TEXT,LEFT_TEXT);
				outtextxy(10,460,"Finding Leaf Node!");
				FindLeafNode(lpBtree->head->lchild);
				text = "Tip:Find Leaf Node success!";
			}
			else
				text = "Tip:Leaf false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"degree"))
		{ 
			if(lpBtree->head->lchild)
			{
				DegreeNode(lpBtree->head->lchild);
				text = "Tip:Emphasize display success! In the red circle is the degree!";
			}
			else
				text = "Tip:Degree false!No element in the Btree!";
		}
		else if(!strcmp(Mstored,"help"))
		{
			HelpTxt();
			cleardevice();
			PreOrderRe(&lpBtree->head->lchild,lpBtree->head->lchild);
			text = "Tip:Create Btree success!You could input [help] to consult assist documents!";
		}
		else
			text = "Tip:Input error!please input angin!";
	}
	DeleteQueue(lpQueue);
}
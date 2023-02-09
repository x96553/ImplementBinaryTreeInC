int PageOne()
{
	cleardevice();
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(180,20,"Binary Tree Demo v1.0 Help Decument");
	outtextxy(52,60,"Welcome to help document! This software provides the basic operation o-");
	outtextxy(20,80,"f binary tree. You can input commands to control the operation of the bina-");
	outtextxy(20,100,"ry tree and see the results at the graphical interface. The detailed comma-");
	outtextxy(20,120,"nd information is on the next page. Please press the + or - key to switch -");
	outtextxy(20,140,"the page display. and press ESC to return to the main view. however. you n-");
	outtextxy(20,160,"eed to provide a preorder sequence of extend binary trees in tree.txt.");
	outtextxy(52,240,"* Software Instructions:");
	outtextxy(68,280,"Environment:    Windows operation systen/DOS");
	outtextxy(68,300,"Premise:        A preorder sequence of extend btree in tree.txt");
	outtextxy(68,320,"Command:        The next page");
	outtextxy(68,440,"Press [+] or [-] turn to next/previous page.");
	outtextxy(68,460,"Press [ESC] to exit help document");
	return 1;
}
int PageTwo()
{
	cleardevice();
	cleardevice();
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(180,20,"Binary Tree Demo v1.0 Help Decument");
	outtextxy(20,60,"Binary Tree Demo provide the following function:");
	outtextxy(20,80,"01. preorder                             Preorder traverse");
	outtextxy(20,100,"02. preorder                             Inorder traverse");
	outtextxy(20,120,"03. postorder                            Postorder traverse");
	outtextxy(20,140,"04. levorder                             Levelorder traverse");
	outtextxy(20,160,"05. height                               Calculate btree height");
	outtextxy(20,180,"06. btree                                Go back the btree view");
	outtextxy(20,200,"07. insert [l/r] [l/r] [Felem] [Celem]   Insert right/left node ");
	outtextxy(20,220,"    in Felem and put Felem right/left btree in Celem");
	outtextxy(20,240,"    First [l/r]       Put Celem insert Felem right or left");
	outtextxy(20,260,"    Second [l/r]      Put Felem right/left btree insert Celem right or left");
	outtextxy(20,280,"08. del [elem]                           Delete node");
	outtextxy(20,300,"    [elem]            Delete element");
	outtextxy(20,320,"09. assign [oldelem] [newelem]           Assign node value");
	outtextxy(20,340,"    [oldelem]         Old element");
	outtextxy(20,360,"    [newelem]         New element");
	outtextxy(20,380,"10. find [p/i/n/l] [elem]                Find node by traverse");
	outtextxy(20,400,"    [p/i/n/l]         Traverse by pre/in/post/level order");
	outtextxy(20,420,"    [elem]            Find element");
	outtextxy(20,440,"11. degree                               Find node by degree number");
	outtextxy(20,460,"    [0/1/2]           The degree of node");
	outtextxy(20,480,"12. prethread                            Preorder threading");
	return 2;
}
int PageThree()
{
	cleardevice();
	/*在图形中编写字体*/
	setcolor(YELLOW);       /*作图色为黄色*/
	settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(180,20,"Binary Tree Demo v1.0 Help Decument");
	outtextxy(20,60,"Binary Tree Demo provide the following function:");
	outtextxy(20,80,"13. inthread                             inorder traverse");
	outtextxy(20,100,"14. postthread                           postorder traverse");
	outtextxy(20,120,"15. leaf                                 Show all leaf node");
	outtextxy(20,140,"16. exit                                 exit Binary Tree Demo");
	outtextxy(244,160,"[press ESC to exit]");
	return 3;
}
void HelpTxt()
{
	int TurnP,WhereP;
	cleardevice();
	WhereP = PageOne();
	while(1)
	{
		TurnP = getch();
		if(TurnP == 0x1B)/*ESC*/
			break;
		if(TurnP == 0x2B)/*+*/
		{ 
			if(WhereP==2)
				WhereP = PageThree();
			if(WhereP==1)
				WhereP = PageTwo();
		}
		if(TurnP == 0x2D)/*-*/
		{
			if(WhereP==2)
				WhereP = PageOne();
			if(WhereP==3)
				WhereP = PageTwo();
		}	
	}
}
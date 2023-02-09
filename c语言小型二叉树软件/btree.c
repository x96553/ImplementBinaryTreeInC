#include<graphics.h>
#include<stdio.h>
#include<createb.h>
#include<createq.h>
#include<travelb.h>
#include<cluesb.h>
#include<adddel.h>
#include<help.h>
#include<judge.h>
main(int argc,char **argv)
{
	BtreeList* lpBtree;
	char Mstored[100],*text;
	int gdriver=DETECT,gmode;
    registerbgidriver(EGAVGA_driver);/*建立独立图形运行程序*/
    initgraph(&gdriver,&gmode,"");
	setbkcolor(BLACK); 
	cleardevice();
	if(argc==1)
	{
		lpBtree = CreateBtree("tree.txt");
		if(lpBtree)
		{
			JudgeInput(lpBtree);
			DeleteBtree(&lpBtree);
		}
		else
		{
			text = "Tip:Failed to build a tree!Please enter [exit] to exit!";
			while(1)
			{
				AccessInput(Mstored,text);
				if(!strcmp(Mstored,"exit"))
					break;
				text = "Tip:Input error!please input angin!Please enter [exit] to exit!";
			}
		}
	}
	if(argc==2)
	{
		lpBtree = CreateBtree(*(argv + 1));
		if(lpBtree)
		{
			JudgeInput(lpBtree);
			DeleteBtree(&lpBtree);
		}
		else
		{
			text = "Tip:Failed to build a tree,Please enter [exit] to exit!";
			while(1)
			{
				AccessInput(Mstored,"Failed to build a tree");
				if(!strcmp(Mstored,"exit"))
					break;
				text = "Tip:Input error!please input angin!Please enter [exit] to exit!";
			}
		}
	}
	closegraph();
}
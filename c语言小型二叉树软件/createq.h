typedef struct Queue{
	BtreeNode* BNode;
	struct Queue* next;
}QueueNode;
typedef struct{
	QueueNode* front;
	QueueNode* rear;
}BtreeQueue;
/*创建队列节点*/
QueueNode* NewQueueNode(BtreeNode* BNode)
{
	QueueNode* QNode;
	QNode= (QueueNode* )malloc(sizeof(QueueNode));
	if(!QNode)
		return 0;
	QNode->BNode = BNode;
	QNode->next = 0;
	return QNode;
}
/*创建队列*/
BtreeQueue* CreateQueue()
{
	BtreeQueue* lpQueue;
	lpQueue = (BtreeQueue* )malloc(sizeof(BtreeQueue));
	if(!lpQueue)
		return 0;
	lpQueue->front = NewQueueNode(NewBtreeNode(0,0,0));
	if(!lpQueue->front)
		return 0;
	lpQueue->rear = lpQueue->front;
	return lpQueue;
}
/*在队列中添加节点*/
void pushQueueNode(BtreeQueue* lpQueue,QueueNode* QNode)
{
	lpQueue->rear->next = QNode;
	lpQueue->rear = lpQueue->rear->next;
}
/*在队列中删除节点*/
int popQueueNode(BtreeQueue* lpQueue,BtreeNode** BNode)
{
	QueueNode* QNode;
	if(lpQueue->rear==lpQueue->front) 
		return 0;
	QNode = lpQueue->front->next;
	*BNode = QNode->BNode;
	lpQueue->front->next = lpQueue->front->next->next;
	if(QNode==lpQueue->rear)
		lpQueue->rear  = lpQueue->front;
	free(QNode);
	return 1; 
}
/*销毁队列*/
int DeleteQueue(BtreeQueue* lpQueue)
{
	QueueNode* QNode;
	while(1)
	{
		if(lpQueue->rear==lpQueue->front)
			break;	
		QNode = lpQueue->front->next;
		lpQueue->front->next = lpQueue->front->next->next;
		if(QNode==lpQueue->rear)
			lpQueue->rear  = lpQueue->front;
		free(QNode);
	}
	if(lpQueue->front)
		free(lpQueue->front); 
	if(lpQueue)
		free(lpQueue);
	return 1;
}
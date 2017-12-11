#include <stdlib.h>
#include <stdio.h>

typedef char DataType;

typedef struct Node {
	DataType data;		/*数据域 */
	struct Node *leftChild;	/*左子树指针 */
	struct Node *rightChild;	/*右子树指针 */
} BiTreeNode;			/*结点的结构体定义 */

/*初始化创建二叉树的头结点*/
void Initiate(BiTreeNode ** root)
{
	*root = (BiTreeNode *) malloc(sizeof(BiTreeNode));
	(*root)->leftChild = NULL;
	(*root)->rightChild = NULL;
}

void Destroy(BiTreeNode ** root)
{
	if ((*root) != NULL && (*root)->leftChild != NULL)
		Destroy(&(*root)->leftChild);

	if ((*root) != NULL && (*root)->rightChild != NULL)
		Destroy(&(*root)->rightChild);

	free(*root);
}

/*若当前结点curr非空，在curr的左子树插入元素值为x的新结点*/
/*原curr所指结点的左子树成为新插入结点的左子树*/
/*若插入成功返回新插入结点的指针，否则返回空指针*/
BiTreeNode *InsertLeftNode(BiTreeNode * curr, DataType x)
{
	BiTreeNode *s, *t;
	if (curr == NULL)
		return NULL;

	t = curr->leftChild;	/*保存原curr所指结点的左子树指针 */
	s = (BiTreeNode *) malloc(sizeof(BiTreeNode));
	s->data = x;
	s->leftChild = t;	/*新插入结点的左子树为原curr的左子树 */
	s->rightChild = NULL;

	curr->leftChild = s;	/*新结点成为curr的左子树 */
	return curr->leftChild;	/*返回新插入结点的指针 */
}

/*若当前结点curr非空，在curr的右子树插入元素值为x的新结点*/
/*原curr所指结点的右子树成为新插入结点的右子树*/
/*若插入成功返回新插入结点的指针，否则返回空指针*/
BiTreeNode *InsertRightNode(BiTreeNode * curr, DataType x)
{
	BiTreeNode *s, *t;

	if (curr == NULL)
		return NULL;

	t = curr->rightChild;	/*保存原curr所指结点的右子树指针 */
	s = (BiTreeNode *) malloc(sizeof(BiTreeNode));
	s->data = x;
	s->rightChild = t;	/*新插入结点的右子树为原curr的右子树 */
	s->leftChild = NULL;

	curr->rightChild = s;	/*新结点成为curr的右子树 */
	return curr->rightChild;	/*返回新插入结点的指针 */
}



void PreOrder(BiTreeNode * t, void visit(DataType item))
{
	if (t != NULL) {	//此小段有一处错误
		visit(t->data);
		PreOrder(t->leftChild, visit);
		PreOrder(t->rightChild, visit);
	}
}

void InOrder(BiTreeNode * t, void visit(DataType item))
//使用visit(item)函数中序遍历二叉树t
{
	if (t != NULL) {	//此小段有一处错误
		InOrder(t->leftChild, visit);
		visit(t->data);
		InOrder(t->rightChild, visit);
	}
}

void PostOrder(BiTreeNode * t, void visit(DataType item))
//使用visit(item)函数后序遍历二叉树t
{
	if (t != NULL) {	//此小段有一处错误
		PostOrder(t->leftChild, visit);
		PostOrder(t->rightChild, visit);
		visit(t->data);
	}
}


void Visit(DataType item)
{
	printf("%c ", item);
}

BiTreeNode *Search(BiTreeNode * root, DataType x)	//需找元素x是否在二叉树中
{
	BiTreeNode *find = NULL;
	if (root != NULL) {
		if (root->data == x)
			find = root;
		else {
			find = Search(root->leftChild, x);
			if (find == NULL)
				find = Search(root->rightChild, x);
		}
	}
	return find;
}

void main(void)
{
	BiTreeNode *root, *p, *pp, *find;
	char x = 'E';

	Initiate(&root);
	p = InsertLeftNode(root, 'A');
	p = InsertLeftNode(p, 'B');
	p = InsertLeftNode(p, 'D');
	p = InsertRightNode(p, 'G');
	p = InsertRightNode(root->leftChild, 'C');
	pp = p;
	InsertLeftNode(p, 'E');
	InsertRightNode(pp, 'F');

	printf("前序遍历：");
	PreOrder(root->leftChild, Visit);
	printf("\n中序遍历：");
	InOrder(root->leftChild, Visit);
	printf("\n后序遍历：");
	PostOrder(root->leftChild, Visit);

	find = Search(root, x);
	if (find != NULL)
		printf("\n数据元素%c在二叉树中 \n", x);
	else
		printf("\n数据元素%c不在二叉树中 \n", x);

	Destroy(&root);

}

#include <stdio.h>
#define MaxLength	100 
typedef int DataType;

struct SequenceList{
	DataType data[MaxLength];
	int length;
};

int insert(struct SequenceList *list, int index, DataType ch)
{
	int size = list->length;
	if (list->length > MaxLength || index < 0 || index > length - 1 )
	
	
	list->data[index] = ch;
	list->length++;
	



}


void main()
{
	struct SequenceList list = {{3,534,4,64,2,543,2,654,2,43,},10};
	

}

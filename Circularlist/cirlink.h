#ifndef cirlink_H
#define cirlink_H
#include "node.h"
#include <iostream>

struct cirlink {
	
	node *last=NULL;
	
void create_list(long	long	int);
void addatbeg(long	long	int);
void addafter(long	long	int,long	long	int);
void del(long	long	int);
void display();
	
};

#endif

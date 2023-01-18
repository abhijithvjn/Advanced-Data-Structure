#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

void insert(int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
void search(int);
void delete(int);
struct node* min_val_node(struct node*);

void main(){
	int ch=0,key;
	do{
		printf("\n Binary Search Tree\n\t1.INSERTION\n\t2.INORDER TRAVERSAL\n\t3.PREORDER TRAVERSAL\n\t4.POSTORDER TRAVERSAL");
		printf("\n\t5.SEARCH\n\t6.DELETE AN ELEMENT\n\t7.EXIT");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\n ENTER THE DATA TO BE INSERTEd :");
				scanf("%d",&key);
				insert(key);
				break;
			case 2: inorder(root);
				break;
			case 3: preorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5: printf("\n ENTER THE KEY TO BE SEARCHED:");
				scanf("%d",&key);
				search(key);
				break;
			case 6: printf("\n ENTER THE KEY TO BE DELETED:");
				scanf("%d",&key);
				delete(key);
				break;
			case 7: exit;
				printf("\n EXIT! \n");
				break;
			default:printf("\n INVALID CHOICE!! ");				
		}		
	}while(ch!=7);
}

void insert(int key){
	struct node *new=NULL,*parent=NULL,*ptr=NULL;
	new=(struct node*)malloc(sizeof(struct node));
	if(new==NULL){
		printf("\n INSUFFICIENT MEMORY!!");
		return;	
	}
	else{
		new->data=key;
		new->left=NULL;
		new->right=NULL;
		if(root==NULL)
			root=new;
		else{
			ptr=root;
			while(ptr!=NULL){
				if(key==ptr->data){
					printf("\n DUPLICATE ELEMENTS NOT ALLOWED..");
					break;				
				}
				else if(key>ptr->data){
					parent=ptr;
					ptr=ptr->right;
				}
				else{
					parent=ptr;
					ptr=ptr->left;				
				}
			}
			if(ptr==NULL){
				if(key>parent->data)
					parent->right=new;
				else
					parent->left=new;
			}	
		}	
	}	
}

void inorder(struct node *ptr){
	if(root==NULL)
		printf("\n TREE IS EMPTY!!");	
	else{
		if(ptr!=NULL){	
			inorder(ptr->left);
			printf("%d ",ptr->data);
			inorder(ptr->right);			
		}
	}
}

void preorder(struct node *ptr){
	if(root==NULL)
		printf("\n TREE IS EMPTY!!");	
	else{
		if(ptr!=NULL){	
			printf("%d ",ptr->data);
			preorder(ptr->left);
			preorder(ptr->right);	
		}		
	}
}

void postorder(struct node *ptr){
		if(root==NULL)
		printf("\n TREE IS EMPTY!!");	
	else{
		if(ptr!=NULL){	
			postorder(ptr->left);
			postorder(ptr->right);
			printf("%d ",ptr->data);	
		}		
	}
}

void search(int key){
	struct node *ptr=NULL,*parent=NULL;
	if(root==NULL)
		printf("\n TREE IS EMPTY!!");
	else{
		ptr=root;
		while(ptr!=NULL){
			if(key==ptr->data){
				printf("\n %d PRESENT IN THE TREE.",ptr->data);
				break;				
			}
			else if(key>ptr->data){
				parent=ptr;
				ptr=ptr->right;
			}
			else{
				parent=ptr;
				ptr=ptr->left;				
			}
		}
		if(ptr==NULL)
			printf("\n %d NOT PRESENT IN TREE.",key);
	}
}

void delete(int key){
	struct node *ptr=NULL;
	if(root==NULL)
		printf("\n TREE IS EMPTY!!");
	else{
		struct node *parent=NULL;
		ptr=root;
		while(ptr!=NULL){
			
			if(ptr->data==key){
				break;
			}
			else{
				parent=ptr;
				if(key > ptr->data)
					ptr=ptr->right;
				else
					ptr=ptr->left;
			}
		}
		if(ptr==NULL){
			printf("%d IS NOT PRESENT IN THE TREE",key);
		}
		else
		{
				if(ptr->right==NULL && ptr->left==NULL){
					if(parent==NULL)
						root=NULL;
					else if(parent->right==ptr)
						parent->right=NULL;
					else 
						parent->left=NULL;
					free(ptr);
				}
				else if(ptr->right!=NULL && ptr->left!=NULL){
					struct node *p=NULL;
					p=ptr->right;
					while(p->left!=NULL)
						p=p->left;
					int dat=p->data;
					delete(dat);
					ptr->data=dat;	
				}
				
				else{
					if(parent==NULL)
					{
						if(ptr->right==NULL)
							root=ptr->left;
						else
							root=ptr->right;					
					}
					else{
						if(parent->right==ptr){
							if(ptr->right==NULL)
								parent->right=ptr->left;
							else
								parent->right=ptr->right;			
						}	
						else{
							if(ptr->left==NULL)
								parent->left=ptr->right;
							else
								parent->left=ptr->left;				
						}
						free(ptr);
					}
				}
		}
		printf("\n ELEMENT DELETED");
	}

}

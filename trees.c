#include<stdio.h>
#include<stdlib.h>

//binary search tree using linked list
typedef struct node
{
    /* data */
    int data;
    struct node *left;
    struct node *right;

}node;

//
node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert(node *root, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
        return root;
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// inorder traversal
void inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// preorder traversal
void preorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// postorder traversal
void postorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}



//driver code

void main(){
    node *root =NULL;
    int data;
    while(1)
    {
        // menu driven
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
        scanf("%d", &data);
        switch(data)
        {
            case 1:
                printf("Enter data to be inserted\n");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder traversal\n");
                inorder(root);
                break;
            case 3:
                printf("Preorder traversal\n");
                preorder(root);
                break;
            case 4:
                printf("Postorder traversal\n");
                postorder(root);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

}

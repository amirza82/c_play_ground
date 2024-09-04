#include "header.h"

void nadd(struct tnode *np, char *key);
struct tnode *tnodealloc();
struct llist *llistalloc();
int fnprint (FILE *fp, struct tnode *node);

// tadd: add key to tree
struct tnode *tadd(struct tnode *root, char *id, char *key)
{
    if (!root) { // root is NULL
        struct tnode *np = tnodealloc(); // make new node
        strcpy((np->ID = (char *) malloc(strlen(id) + 1)), id);
        np->left = np->right = NULL;
        np->vars = NULL;
        nadd(np, key);
        return np;
    }
    int comp = strcmp(root->ID, id);
    if (comp == 0)
        nadd(root, key);
    else if (comp < 0)
        root->left = tadd(root->left, id, key);
    else
        root->right = tadd(root->right, id, key);
    return root;
}

// tnodealloc: allocate memory for tnode and return pointer to it
struct tnode *tnodealloc()
{
    return (struct tnode *) malloc(sizeof (struct tnode));
}

// nadd: add keyword to node
void nadd(struct tnode *np, char *key)
{
    if (!np->vars) {
        np->vars = llistalloc();
        np->vars->next = NULL;
        strcpy(np->vars->var = (char *) malloc(strlen(key) + 1), key);
        return;
    } else {
        struct llist *lp = np->vars;
        while (lp->next)
            lp = lp->next;
        lp->next = llistalloc();
        lp->next->next = NULL;
        strcpy(lp->next->var = (char *) malloc(strlen(key) + 1), key); 
    }
}

// ftprint: print out the tree to file
void ftprint(FILE *fp, struct tnode *root)
{
    if (!root) // if root is null then return
        return;
    ftprint(fp, root->left);
    fnprint(fp, root);
    ftprint(fp, root->left);
}

// fnprint: print out the tnode keys to file
int fnprint (FILE *fp, struct tnode *node)
{
    int sum = 0;
    fprintf(fp, "---------------------------\nID: %s\n", node->ID);
    while (node->vars) {
        if ((sum += fprintf(fp, "\t%s\n", node->vars->var)) <= 0)
            exit(1);
        node->vars = node->vars->next;
    }
    return sum;
}

// llistalloc: allocate memory for llist and return pointer to it
struct llist *llistalloc()
{
    return (struct llist *) malloc(sizeof (struct llist));
}

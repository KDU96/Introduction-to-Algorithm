#include    <stdio.h>
#include    <stdlib.h>
#define     INPUT_ITEM_SIZE     4

char    inputItem[INPUT_ITEM_SIZE + 1]  =   {-1, 'A', 'B', 'C', 'D'};
float   costTable[INPUT_ITEM_SIZE+1][INPUT_ITEM_SIZE+1];
int     minmumKeyTable[INPUT_ITEM_SIZE+1][INPUT_ITEM_SIZE+1];
float   probability[INPUT_ITEM_SIZE+1]     =   {0, 0.1, 0.2, 0.3, 0.4};
float    costFunction(int i, int j);

typedef struct TreeNode{
    char charcater;
    struct TreeNode* leftChild;
    struct TreeNode* rightHcild;
}TreeNode;

void OptimalBST(){
    int i, j, k;
    int count = 1;
    //initialization
    for(i=0; i<=INPUT_ITEM_SIZE; i++)
        for(j=0; j<=INPUT_ITEM_SIZE; j++){
            costTable[i][j]         =   0;
            minmumKeyTable[i][j]    =   0;
        }
    for(i=1; i<=INPUT_ITEM_SIZE; i++){
        costTable[i][i] =   probability[i];
        minmumKeyTable[i][i]    =   i;
    }
    while(count <= INPUT_ITEM_SIZE){
        i = 1;
        for(j=i+count; j <=4; j++, i++)
            costTable[i][j] =   costFunction(i, j);
        count++;
    }
}
float costFunction(int i, int j){
    int k;
    float probSum   =   0;
    for(int idx=i; idx<=j; idx++) probSum += probability[idx];
    float least = costTable[i][i-1] + costTable[i+1][j];
    for(k = i+1; k <= j; k++){
        if(least > costTable[i][k-1] + costTable[k+1][j]){
            least   =   costTable[i][k-1] + costTable[k+1][j]; 
            minmumKeyTable[i][j]  =   k;
        }
    }
    return least + probSum;
}
void printTable(){
    printf("costTable\n");
    for(int i=1; i<=INPUT_ITEM_SIZE; i++){
        for(int j=1; j<=INPUT_ITEM_SIZE; j++)
            printf("%f", costTable[i][j]);
        printf("\n");
    }
    printf("minmunkeyTable\n");
    for(int i=1; i<=INPUT_ITEM_SIZE; i++){
         for(int j=1; j<=INPUT_ITEM_SIZE; j++)
            printf("%d ", minmumKeyTable[i][j]);
        printf("\n");
     }
}
TreeNode* BuildTree(int i, int j){
    int k;
    TreeNode* p;
    k   =   minmumKeyTable[i][j];

    if(k == 0)  return NULL;
    p   =   (TreeNode*)malloc(sizeof(TreeNode));
    p->charcater    =   inputItem[k];
    p->leftChild    =   BuildTree(i, k-1);
    p->rightHcild   =   BuildTree(k+1, j);
    return p;
}
void deleteTree(TreeNode *root){
   if(!root)    return;
   printf("%c ", root->charcater);
   deleteTree(root->leftChild);
   deleteTree(root->rightHcild);
   free(root);
}
int main(){
    OptimalBST();
    printTable();
    TreeNode *root  =   BuildTree(1, 4);
    deleteTree(root);
}

    



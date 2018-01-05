//1002. A+B for Polynomials (25)
//This time, you are supposed to find A+B where A and B are two polynomials.
//
//Input
//
//Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.
//
//Output
//
//For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
//
//Sample Input
//2 1 2.4 0 3.2
//2 2 1.5 1 0.5
//Sample Output
//3 2 1.5 1 2.9 0 3.2
#include <cstdio>
#include <cstdlib>
struct ListNode{
    int exp;
    double coef;
    struct ListNode *next;
};
int main()
{
    int n;
    struct ListNode* head1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode* head2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode* sumList = (struct ListNode *) malloc(sizeof(struct ListNode));
    head1 -> next = NULL;
    head2 -> next = NULL;
    sumList -> next = NULL;
    int count = 0;
    
    
    scanf("%d",&n);
    struct ListNode *walk = head1;
    for (int i = 0; i < n; i++)
    {
        struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        scanf("%d%lf",&tempNode -> exp, &tempNode -> coef);
        tempNode -> next = walk -> next;
        walk -> next = tempNode;
        walk = tempNode;
    }
    
    scanf("%d",&n);
    walk = head2;
    for (int i = 0; i < n; i++)
    {
        struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        scanf("%d%lf",&tempNode -> exp, &tempNode -> coef);
        tempNode -> next = walk -> next;
        walk -> next = tempNode;
        walk = tempNode;
    }
    
    struct ListNode* walkSum = sumList;
    struct ListNode *walkList1 = head1 -> next, *walkList2 = head2 -> next;
    while (walkList1 && walkList2)
    {
        if (walkList1 -> exp == walkList2 -> exp)
        {
            double totalCoef = walkList1 -> coef + walkList2 -> coef;
            if (totalCoef == 0.0)
            {
                walkList1 = walkList1 -> next;
                walkList2 = walkList2 -> next;
                continue;
            }
            struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
            tempNode -> exp = walkList1 -> exp; tempNode -> coef = totalCoef;
            tempNode -> next = walkSum -> next;
            walkSum -> next = tempNode;
            walkSum = tempNode;
            walkList1 = walkList1 -> next;
            walkList2 = walkList2 -> next;
        }else if (walkList1 -> exp > walkList2 -> exp){
            if (walkList1 -> coef == 0.0)
            {
                walkList1 = walkList1 -> next;
                continue;
            }
            struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
            tempNode -> exp = walkList1 -> exp; tempNode -> coef = walkList1 -> coef;
            tempNode -> next = walkSum -> next;
            walkSum -> next = tempNode;
            walkSum = tempNode;
            walkList1 = walkList1 -> next;
        }else{
            if (walkList2 -> coef == 0.0)
            {
                walkList2 = walkList2 -> next;
                continue;
            }
            struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
            tempNode -> exp = walkList2 -> exp; tempNode -> coef = walkList2 -> coef;
            tempNode -> next = walkSum -> next;
            walkSum -> next = tempNode;
            walkSum = tempNode;
            walkList2 = walkList2 -> next;
        }
        count ++;
        
    }
    while (walkList1)
    {
        if (walkList1 -> coef == 0.0)
        {
            walkList1 = walkList1 -> next;
            continue;
        }
        struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        tempNode -> exp = walkList1 -> exp; tempNode -> coef = walkList1 -> coef;
        tempNode -> next = walkSum -> next;
        walkSum -> next = tempNode;
        walkSum = tempNode;
        walkList1 = walkList1 -> next;
        count ++;
    }
    while (walkList2)
    {
        if (walkList2 -> coef == 0.0)
        {
            walkList2 = walkList2 -> next;
            continue;
        }
        struct ListNode* tempNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        tempNode -> exp = walkList2 -> exp; tempNode -> coef = walkList2 -> coef;
        tempNode -> next = walkSum -> next;
        walkSum -> next = tempNode;
        walkSum = tempNode;
        walkList2 = walkList2 -> next;
        count ++;
    }
    walk = sumList -> next;
    if (count == 0)
    {
        printf("%d",0);
        return 0;
    }
    printf("%d ", count);
    while (walk)
    {
        printf("%d %.1lf",walk -> exp,walk -> coef);
        if (walk -> next)
            printf(" ");
        walk = walk -> next;
    }
    return 0;
    
}
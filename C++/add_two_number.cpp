class Solution {
public:

void insertTail(ListNode * &head, ListNode * &tail, int val)
{
    ListNode *temp = new ListNode(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

ListNode *add(ListNode *first, ListNode *second)
{
    int caary = 0;
    ListNode *ansHead = NULL;
    ListNode *ansTail = NULL;

    while (first != NULL || second != NULL || caary != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->val;

        int val2 = 0;
        if (second != NULL)
            val2 = second->val;

        int sum = caary + val1 + val2;
        int digit = sum % 10;

        insertTail(ansHead, ansTail, digit);
        caary = sum / 10;

        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = add(l1, l2);
    return ans;
}
};
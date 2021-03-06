/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //you guys havent learned hash tables just yet so I brute forced ,
        // you can use hash tables if youve taken CS32 already!
        int lA = 1,lB = 1;
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }
		
        ListNode *tempA = headA, *tempB = headB;
        
        while(tempA->next != NULL) //get the length of the branch A
        {
            lA++;
            tempA = tempA->next;
        }
        while(tempB->next != NULL) //get the length of the branch B
        {
            lB++;
            tempB = tempB->next;
        }
        if (tempB != tempA){
            return NULL; //if they dont end at the same node, then you know theres no intersection
        }
        int skip = abs(lA - lB); //this is to see if one branch is longer than the other
        //if one branch is longer, than we can skip "skip" number of values as it wont converge
        //before then
        
        if(lA > lB) //if the length of branch A is longer, go from there
        {
            while(skip-- > 0)
            {
                headA = headA->next;
                //skip--;
            }
        }
        else if (lB > lA){ // if the length of branch B is longer, go from there
            while(skip-- > 0)
            {
                headB = headB->next;
                //skip--;
            }
        }
		//no else as that is if lA and lB are the same length
		
        while(headB != headA) 
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
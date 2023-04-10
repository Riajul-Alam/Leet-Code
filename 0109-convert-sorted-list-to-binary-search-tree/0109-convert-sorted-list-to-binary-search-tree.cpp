/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    // Finds the middle of the linked list
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast and fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

    TreeNode *build(ListNode *head)
    {
        // If the list is empty then return null
        if (!head)
            return NULL;

        // If the list contains only one element then return TreeNode of that value
        if (middleNode(head) == head)
            return new TreeNode(head->val);
        ListNode *middle = middleNode(head);
        TreeNode *root = new TreeNode(middle->val);
        ListNode *ptr = head;
        while (ptr->next != middle)
            ptr = ptr->next;

        ListNode *first = head;
        ListNode *second = middle->next;
        
        ptr->next = NULL;
        middle->next = NULL;

        root->left = build(first);
        root->right = build(second);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        return build(head);
    }
};
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int result = 0;
        vector<int> mv;

        while (head != nullptr)
        {
            mv.push_back(head->val);
            head = head->next;
        }

        int power = mv.size() - 1; 
        for (int i = 0; i < mv.size(); ++i)
        {
            result += mv[i] * pow(2, power);
            power--;
        }

        return result;
    }
};

int main()
{
    // Creating linked list 1 -> 0 -> 1
    ListNode *node3 = new ListNode(1);
    ListNode *node2 = new ListNode(0, node3);
    ListNode *head = new ListNode(1, node2);

    Solution s;
    int decimalValue = s.getDecimalValue(head);
    cout << "Decimal Value: " << decimalValue;

    return 0;
}

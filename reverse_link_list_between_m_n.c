/*
 *  Reverse Link list between position m and n; 1<= m <= n<= length(list)
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *
reverse_sublink(struct ListNode * l, struct ListNode * after)
{
    struct ListNode *a, *b, *c;
    a = l;
    b = l->next;
    if(b == NULL) {
        return a;
    }
    c = b->next;

    while(b) {
        b->next = a;
        a = b;
        if(!c) {
            break;
        }
        b = c;
        c = c->next;
    }
    l->next = after;
    return b;
}


struct ListNode *
reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *before, *after, *p;
    before = after = NULL;
    if(m == n) {
        return head;
    }

    p = head;

    for (int i = 1; i < m; i++) {
        before = p;
        p = p->next;
    }

    int cnt = n - m;

    while(cnt--) {
        p = p->next;
    }

    after = p->next;
    p->next = NULL;

    if(!before) {
        before = reverse_sublink(head, after);
        return before;
    } else {
        before->next = reverse_sublink(before->next, after);
        return head;
    }
}

void
print_link(struct ListNode * l) {
    while(l) {
        printf("#%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

struct ListNode *
new_node(struct ListNode *head, int val) {
    struct ListNode *new = (struct ListNode *) malloc(sizeof(*new));
    new->next = head;
    new->val = val;
    return new;
}


int
main()
{
    struct ListNode *l;
    l = NULL;
    l = new_node(l, 1);
    l = new_node(l, 2);
    l = new_node(l, 3);
    l = new_node(l, 4);
    print_link(l);
    l = reverseBetween(l, 1, 3);
    print_link(l);
    return 0;
}

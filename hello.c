#include<stdio.h>
int main(){
    int b=5;
    char a='a';
    printf("%d",atoi(a));
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *t=head;
        int num=0;
        while(t!=NULL){
            t=t->next;
            num++;
        }
        ListNode *temhead;
        for(int part=1;part<num;part*=2){
            t=head;     //head of 2*part
            for(int i=0;i<num;i+=2*part){
                ListNode *left=t;   
                for(int j=0;j<part-1;j++){
                    t=t->next;
                    if(t==nullptr)
                        break;
                }
                if(t==nullptr||t->next==nullptr)
                    break;          //没有右队列
                ListNode *left_tail=t;      //left的结尾的判断
                ListNode* right=t->next;
                if(right==nullptr)  break;
                ListNode *right_tail;    
                int arrive_right=0;
                for(int j=0;j<part;j++){
                    if(t->next==nullptr)
                        break;
                    t=t->next;
                    if(j==part-1)
                        arrive_right=1;
                } 
                right_tail=t;
                if(arrive_right==1) t=t->next;
                while(left!=left_tail&&right!=right_tail){
                    if(left->val>right->val){
                        while(right!=right_tail&&right->next->val<=left->val)
                            right=right->next;  //直到right->next->val>=left->val or right->next==nullptr
                        if(right->val<=left->val){   //把right接到left前面
                            right->next=left;
                            left=left->next;
                            //right没有存在的意义
                        }
                        else{   //right->val>left->val
                            ListNode* rn=right->next;
                            ListNode* ln=left->next;
                            right->next=left;
                            left->next=rn;
                            left=ln;    right=rn;
                        }
                    }
                    else{   //left->val<=right->val
                    // find left where left->next > right->val
                        while(left!=left_tail&&left->val<=right->val)
                            left=left->next;
                        if(left->val<=right->val){
                        //把left接到right前面
                            ListNode right_next=right->next;
                            left->next=right;
                        }
                        else{   //left->val>right->val
                            ListNode* rn=right->next;
                            ListNode* ln=left->next;
                            left->next=rn;
                            rn->next=ln;
                            rn=rn;        
                            left=ln;                
                        }
                    }
                }
                if(left!=left_tail){
                    left_tail->next=nh;
                    t=nh;
                }
                else if(right!=nullptr){
                    t=nh;
                }
                else t=left;
            }
        }
    }
};
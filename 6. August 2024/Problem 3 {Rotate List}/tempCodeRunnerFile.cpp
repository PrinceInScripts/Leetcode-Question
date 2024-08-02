if(head==NULL || head->next==NULL) return head;
       ListNode* tail;
       int len=0;
       ListNode* temp=head;
       while(temp->next!=NULL){
          len++;
          temp=temp->next;
       }

       len++;
       tail=temp;
       k=k%len;
       if(k==0) return head;
       temp=head;
       for(int i=0;i<len-k;i++){
          temp=temp->next;
       }
       tail->next=head;
       head=temp->next;
       temp->next=NULL;       
       
       return head;
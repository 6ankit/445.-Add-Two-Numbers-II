 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp=l1;
        vector<int> arr1;
        while(temp!=NULL)
        {
            arr1.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> arr2;
        temp=l2;
        while(temp!=NULL)
        {
            arr2.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> ans;
        int i=arr1.size()-1;
        int j=arr2.size()-1;
        while(i>=0&&j>=0)
        {
            if(i==0&&j==0)
            {
                if(arr1[i]+arr2[j]>=10)
                {
                int m=arr1[i]+arr2[j];
                // cout<<i<<" "<<j<<endl;
                m=m%10;
    
                ans.push_back(m%10);
                 int k=arr1[i]+arr2[j];
                k=k/10;
                ans.push_back(k);
                }
                else  ans.push_back(arr1[i]+arr2[i]);
            }
          else  if(arr1[i]+arr2[j]>=10)
            {
              int m=arr1[i]+arr2[j];
                // cout<<i<<" "<<j<<endl;
                m=m%10;
    
                ans.push_back(m%10);
                int k=arr1[i]+arr2[j];
                k=k/10;
                if(i-1>=0) arr1[i-1]=arr1[i-1]+k;
                else if(j-1>=0) arr2[j-1]+=k;
            }
            else if(arr1[i]+arr2[j]<10)
            {
                ans.push_back(arr1[i]+arr2[j]);
            }
            i--;
            j--;
        }
        if(i<0)
        {
            while(j>=0)
            {
                if(arr2[j]>=10&&j==0)
                {
                    ans.push_back(0);
                    ans.push_back(1);
                }
                else if(arr2[j]>=10&&j!=0)
                {
                    int m=arr2[j];
                    m=m%10;
                    ans.push_back(m);
                    int k=arr2[j];
                    k=k/10;
                    arr2[j-1]+=k;
                }
                else ans.push_back(arr2[j]);
                j--;
            }
        }
        else if(j<0)
        {
            while(i>=0)
            {
                if(arr1[i]>=10&&i==0)
                {
                    ans.push_back(0);
                    ans.push_back(1);
                }

                else if(arr1[i]>=10&&i!=0)
                {
                    int m=arr1[i];
                    m=m%10;
                    ans.push_back(m);
                    int k=arr1[i];
                    k=k/10;
                    arr1[i-1]+=k;
                }
                else ans.push_back(arr1[i]);
                i--;
            }
        }
        ListNode*newnode=new ListNode(ans[ans.size()-1]);
        ListNode*head=newnode;
        for(int i=ans.size()-2;i>=0;i--)
        {
            ListNode*temp=new ListNode(ans[i]);
            newnode->next=temp;
            newnode=temp;
        }
        newnode->next=NULL;
        return head;
    }

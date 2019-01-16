nclude<bits/stdc++.h>
using namespace std;
bool walk[1000];
queue<int> q;

typedef struct nodes1
{
    int no;
    struct nodes1 *next,*nextno;
} n1;

class adj
{
public:
    n1 root;
    adj()
    {
        root.no=0;
        root.next=NULL;
        root.nextno=NULL;
    }
    void push(int a,int b)
    {
        n1 *temp=&root;
        while(temp->nextno!=NULL&&temp->no!=0&&temp->no!=a)temp=temp->nextno;
        if(temp->no==0||temp->no==a){
            temp->no=a;
            push2(temp,b);
        }
        else
        {
            n1 *temp2=new n1;
            temp2->no=a;
            temp2->nextno=NULL;
            temp2->next=NULL;
            temp->nextno=temp2;
            push2(temp2,b);
        }
    }
    void pop(int x)
    {
        n1 *temp=&root;
        while(temp->nextno!=NULL&&temp->no!=0&&temp->no!=x)temp=temp->nextno;
        if(temp->no==x)
        {
            while(temp->next!=NULL)
            {
                if(walk[temp->next->no-1])
                {
                    walk[temp->next->no-1]=false;
                    q.push(temp->next->no);
                }
                temp=temp->next;
            }
        }
        if(q.size())
            q.pop();
    }
private:
    void push2(n1 *temp,int b)
    {
        n1 *temp2=new n1;
        if(temp->next!=NULL)
            temp2->next=temp->next;
        else
            temp2->next=NULL;
        temp->next=temp2;
        temp2->no=b;
    }
};
void reset(int n)
{
    for(int i=0; i<n; i++)walk[i]=true;
}
int main()
{
    int n,m,q,t1,t2;
    adj lis;
    scanf("%d%d%d",&n,&m,&q);
    while(m--)
    {
        scanf("%d%d",&t1,&t2);
        lis.push(t1,t2);
    }
    while(q--)
    {
        reset(n);
        bool t=false;
        scanf("%d%d",&t1,&t2);
        ::q.push(t1);
        while(::q.size()>0)
        {
            if(::q.front()==t2)
            {
                t=true;
                break;
            }
            else
            {
                lis.pop(::q.front());
            }
        }
        if(t)printf("Yes\n");
        else
        printf("No\n");
    }
}

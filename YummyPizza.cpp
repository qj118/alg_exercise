#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int checkn = 16;
struct tria
{
    short x,y,z;//三角形三条线，每条线一个值
    tria() {}
    tria(short _x,short _y,short _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }
    tria add(short d)//d -> direction
    {
        short mov = (x+y+z == 0?1:-1);
        if(d == 0)
        {
            return tria(x,y+mov,z+mov);
        }
        else if(d==1)
        {
            return tria(x+mov,y,z+mov);
        }
        else
        {
            return tria(x+mov,y+mov,z);
        }
    }

    void rotate()//120度，线变换
    {
        int tmp=x;
        x=y;
        y=z;
        z=tmp;
    }
    void updown()//180度，上下三角形变换
    {
        x=-x+1,y=-y+1,z=-z;
    }

    void mov(short mx,short my,short mz)
    {
        x=x+mx,y=y+my,z=z+mz;
    }
};
bool operator ==(const tria &a,const tria &b)
{
    return a.x==b.x&&a.y==b.y&&a.z==b.z;
}
bool operator <(const tria &a,const tria &b)
{
    if(a.x!=b.x)return a.x<b.x;
    else if(a.y!=b.y)return a.y<b.y;
    else return a.z<b.z;
}
const int maxn = 16;

struct hashnode
{
    short h[16];
    short hn;
};
bool operator <(const hashnode &a,const hashnode &b)
{
    if(a.hn!=b.hn) return a.hn < b.hn;
    for(int i=0;i<a.hn;i++)
    {
        if(a.h[i]<b.h[i])
            return true;
        else if(a.h[i]>b.h[i])
            return false;
    }
    return false;
}

struct pizza
{
    tria arr[maxn];
    short an;
    pizza()
    {
        an = 0;
    }

    bool add(const tria &t)
    {
        for(short i=0; i < an; i++)
        {
            if(arr[i]==t)//已经添加过该三角形
            {
                return false;
            }
        }
        arr[an++]=t;
        return true;
    }

    void remove()
    {
        an--;
    }
    hashnode Hash()
    {
        hashnode ret;
        ret.hn = an;
        for(short i=0;i < an;i++)
        {
            ret.h[i]=arr[i].x+8;
            ret.h[i]<<=4;
            ret.h[i]+=arr[i].y+8;
            ret.h[i]<<=4;
            ret.h[i]+=arr[i].z+8;
        }
        return ret;
    }
};


bool operator <(const pizza &a,const pizza &b)
{
    if(a.an!=b.an)return a.an<b.an;
    for(short i=0; i<a.an; i++)
    {
        if(a.arr[i]<b.arr[i])
        {
            return true;
        }
        else if(b.arr[i]<a.arr[i])
        {
            return false;
        }
    }
    return false;
}
int ans[maxn+9]= {0};

set<hashnode> sp;

bool canFind(pizza p)
{
    for(short i=0; i<3; i++)
    {
        sort(p.arr,p.arr+p.an);
        if(sp.find(p.Hash())!=sp.end())
            return true;

        for(short j=0; j<p.an; j++)
        {
            p.arr[j].rotate();
        }
    }
    return false;
}

bool Find(pizza tmp)
{
    for(short i=0; i<tmp.an; i++)
    {
        short x=tmp.arr[i].x,y=tmp.arr[i].y,z=tmp.arr[i].z;
        if(x+y+z==0)
        {
            pizza t2=tmp;

            for(short j=0; j<t2.an; j++)
            {
                t2.arr[j].mov(-x,-y,-z);
            }

            if(canFind(t2))
                return true;

        }
        else
        {
            pizza t2=tmp;
            for(short j=0; j<t2.an; j++)
            {
                t2.arr[j].updown();
                t2.arr[j].mov(x-1,y-1,z);
            }

            if(canFind(t2))
                return true;
        }

    }
    return false;
}
void Insert(pizza p)
{
    sort(p.arr,p.arr+p.an);
    sp.insert(p.Hash());
    for(short i=0;i<p.an;i++)
    {
        p.arr[i].rotate();
    }
    sort(p.arr,p.arr+p.an);
    sp.insert(p.Hash());
    for(short i=0;i<p.an;i++)
    {
        p.arr[i].rotate();
    }
    sort(p.arr,p.arr+p.an);
    sp.insert(p.Hash());
}
void dfs(pizza p)
{
    if(p.an == checkn+1)return ;
    if(Find(p))
    {
        return;
    }
    ans[p.an]++;
    Insert(p);

    for(short i=0; i<p.an; i++)
    {
        for(short j=0; j<3; j++)
        {
            tria t=p.arr[i].add(j);
            if(p.add(t))
            {
                dfs(p);
                p.remove();
            }
        }
    }
}
int ans2[maxn+10]={0,1,1,1,4,6,19,43,120,307,866,
                   2336,6588,18373,52119,147700,422016};
int main()
{
    pizza p;
    p.add(tria(0,0,0));
    dfs(p);
    printf("{");
    for(int i=0; i<=maxn; i++)
    {
        printf("%d,",ans[i]);
    }
    cout<<"};"<<endl;
    return 0;
}


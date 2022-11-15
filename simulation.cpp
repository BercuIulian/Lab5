#include <stdio.h>
#include <iostream>

using namespace std;

// hp - health , reg - regeneration/sec, sld - slow duration, csd - cast duration, as - atack speed, y - yes, n - no, s - single, m - multiple, fb - fireball

class Base
{
public:
    int hp;
    float reg;
public:
    void setHp(int a){
        hp = a;
    }
};

class Money
{
public:
    int total, income;
};

class Troops
{
public:
    int hp,range, damage, speed, nr, position;
    float as;
public:
    void setDamage(int a){
        damage=a;
    }
    void setHp(int a){
        hp=a;
    }
    void setRange(int a){
        range=a;
    }
};

class Ninja: public Troops{
public:
    void atack()
    {
        cout << "I'm a ninja, ninja chop! - " << nr <<endl;
    }

    /*void nr()
    {
        cout<<"We are "<<nr<<endl;
    }*/


};

class Warrior: public Troops{
public:
    void atack()
    {
        cout << "I will cut you! - " << damage <<endl;
    }
};

class Archer: public Troops{
public:
    void atack()
    {
        cout << "Eat my arrow! - " << damage <<endl;
    }
};

class Cannoneer: public Troops{
public:
    void atack()
    {
        cout << "Check out my cannon! - " << damage <<endl;
    }
};

class Monster: public Troops{
public:
    void atack()
    {
        cout << "Monster must eat you!!! - " << damage <<endl;
    }
};

class Tower
{
public:
    int range, damage, cost, upgrade,nr;
    char spawn, target;
public:
    void setRange (int a){
        range=a;
    }
    void setDamage (int a){
        damage=a;
    }
};

class Castele: public Tower{
public:
    void protect()
    {
    	cout<<"I will defend my base! - "<<damage<<endl;
    }
};

class Arch: public Tower{
public:
    void protect()
    {
    	cout<<"I will take you down with my arrows! - "<<damage<<endl;
    }
};

class Wizzard: public Tower{
public:
    void protect(int damage)
    {
    	printf("My magic is stronger then you! - %d",damage);
    	//cout<<"My magic is stronger then you! - "<<damage<<endl;
    }

};

class Spells
{
public:
    int cost, damage, sld, csd;
    char target;
};

int main()
{
    int aux,castleDmg,archDmg,wizzardDmg,pos=10,sec=0;
    float mHp,nHp,wHp,aHp,cHp,enemyHp;

    Base base;
    base.setHp(5000);

    Ninja n;
    Warrior w;
    Archer a;
    Cannoneer c;
    Monster m;

    Troops *enemy1 = &n;
    Troops *enemy2 = &w;
    Troops *enemy3 = &a;
    Troops *enemy4 = &c;
    Troops *enemy5 = &m;

    enemy1->setDamage(50);
    enemy2->setDamage(60);
    enemy3->setDamage(40);
    enemy4->setDamage(75);
    enemy5->setDamage(100);

    enemy1->setHp(120);
    enemy2->setHp(150);
    enemy3->setHp(100);
    enemy4->setHp(200);
    enemy5->setHp(300);

    enemy1->setRange(3);
    enemy2->setRange(1);
    enemy3->setRange(8);
    enemy4->setRange(5);
    enemy5->setRange(0);

    printf("How many Ninja troops: ");
    scanf("%d",&n.nr);

    printf("How many Worrier troops: ");
    scanf("%d",&w.nr);

    printf("How many Archer troops: ");
    scanf("%d",&a.nr);

    printf("How many Cannoneer troops: ");
    scanf("%d",&c.nr);

    printf("How many monsters troops: ");
    scanf("%d",&m.nr);

    nHp = n.nr * n.hp;
    wHp = w.nr * w.hp;
    aHp = a.nr * a.hp;
    cHp = c.nr * c.hp;
    mHp = m.nr * m.hp;

    Castele castle;
    Arch arch;
    Wizzard wizzard;

    Tower *tower1 = &castle;
    Tower *tower2 = &arch;
    Tower *tower3 = &wizzard;

    tower1->setRange(3);
    tower2->setRange(7);
    tower3->setRange(5);

    tower1->setDamage(50);
    tower2->setDamage(65);
    tower3->setDamage(50);

    printf("How many Castle towers: ");
    scanf("%d",&castle.nr);

    printf("How many Arch towers: ");
    scanf("%d",&arch.nr);

    printf("How many Wizard towers: ");
    scanf("%d",&wizzard.nr);

    castleDmg = castle.nr * castle.damage;
    archDmg = arch.nr * arch.damage;
    wizzardDmg = wizzard.nr * wizzard.damage;


    enemyHp=nHp+aHp+cHp+mHp+wHp;


    while(enemyHp>0&&base.hp>0)
    {

        if(pos<=3)
        {
            base.hp -= n.nr * n.damage;
            n.position=3;
        }
        if(pos<=1)
        {
            base.hp -= w.nr * w.damage;
            w.position = 1;
        }
        if(pos<=7)
        {
            base.hp -= a.nr * a.damage;
            a.position = 7;
        }
        if(pos<=5)
        {
            base.hp -= c.nr * c.damage;
            c.position = 5;
        }
        if(pos<=0)
        {
            base.hp -= m.nr * m.damage;
            m.position = 0;
        }

        //Archer tower atack sistem
        if(pos<=7)
        {
            if(mHp>0&&m.position<=7)
            {
                mHp -= arch.nr * arch.damage;
                m.nr = int(mHp/300+0.5);
            }

            else if (wHp>0&&w.position<=7)
            {
                wHp -= arch.nr * arch.damage;
                w.nr = int(wHp/150 + 0.5);
            }

            else if (nHp>0&&n.position<=7)
            {
                nHp -= arch.nr * arch.damage;
                n.nr = int(nHp/120 + 0.5);
            }

            else if (cHp>0&&c.position<=7)
            {
                cHp -= arch.nr * arch.damage;
                c.nr = int(cHp/200 + 0.5);
            }

            else if (aHp>0&&a.position<=7)
            {
                aHp -= arch.nr * arch.damage;
                a.nr = int(aHp/100 + 0.5);
            }
        }

        //Wizzard tower atack sistem
        if(pos<=5)
        {
            if(mHp>0&&m.position<=5)
            {
                mHp -= wizzard.nr * wizzard.damage;
                m.nr = int(mHp/300+0.5);
            }

            else if (wHp>0&&w.position<=5)
            {
                wHp -= wizzard.nr * wizzard.damage;
                w.nr = int(wHp/150 + 0.5);
            }

            else if (nHp>0&&n.position<=5)
            {
                nHp -= wizzard.nr * wizzard.damage;
                n.nr = int(nHp/120 + 0.5);
            }

            else if (cHp>0&&c.position<=5)
            {
                cHp -= wizzard.nr * wizzard.damage;
                c.nr = int(cHp/200 + 0.5);
            }

            else if (aHp>0&&a.position<=5)
            {
                aHp -= wizzard.nr * wizzard.damage;
                a.nr = int(aHp/100 + 0.5);
            }
        }

        //Castle tower atack sistem
        if(pos<=3)
        {
            if(mHp>0&&m.position<=3)
            {
                mHp -= castle.nr * castle.damage;
                m.nr = int(mHp/300+0.5);
            }

            else if (wHp>0&&w.position<=3)
            {
                wHp -= castle.nr * castle.damage;
                w.nr = int(wHp/150 + 0.5);
            }

            else if (nHp>0&&n.position<=3)
            {
                nHp -= castle.nr * castle.damage;
                n.nr = int(nHp/120 + 0.5);
            }

            else if (cHp>0&&c.position<=3)
            {
                cHp -= castle.nr * castle.damage;
                c.nr = int(cHp/200 + 0.5);
            }

            else if (aHp>0&&a.position<=3)
            {
                aHp -= castle.nr * castle.damage;
                a.nr = int(aHp/100 + 0.5);
            }

        }
        sec++;
        enemyHp=nHp+aHp+cHp+mHp+wHp;
        printf("total enemy HP: %d | base HP: %d\n", int(enemyHp+0.5),base.hp);
        printf("-------------------------------\n");

        if (enemyHp<=0) {printf("victory\n"); printf("game lasted: %d seconds",sec);}
        if (base.hp<=0) {printf("you lost\n");printf("game lasted: %d seconds",sec);}
        pos--;
    }
}

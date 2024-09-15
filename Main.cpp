#include<iostream>
using namespace std;

class Grass
{
protected:
    int weight;
    bool life;

public:
    Grass() : weight(0), life(true) {}

    Grass(int w, bool l) : weight(w), life(l) {}

    int getWeight() {
        return weight;
    }


    virtual void Eat() {
        weight += 10;
        cout << "+ New weight: " << weight << "kg" << endl;
    }


    virtual ~Grass() = 0;
};


Grass::~Grass() {
    cout << " ------ Grass Dest ------\n";
}

class Meet
{
protected:
    int power;

public:
    Meet() : power(0) {}  

    Meet(int p) : power(p) {} 

    
    virtual void Ñonsume(Grass& obj) {
        if (obj.getWeight() > power) {
            power -= 10;
            cout << " + losing 10 power. New power: " << power << endl;
        }
        else {
            power += 10;
            cout << " - gaining 10 power. New power: " << power << endl;
        }
    }

    int getPower() {
        return power;
    }

    
    virtual ~Meet() = 0;
};


Meet::~Meet() {
    cout << " ------| Meet Dest |------\n";
}




class Antil : public Grass
{
public:
    Antil(int w) : Grass(w, true) {} 

    void EatGrass() {
        Grass::Eat(); 
    }
};

class Bison : public Grass
{
public:
    Bison(int w) : Grass(w, true) {}  

    void EatGrass() {
        Grass::Eat();  
    }
};

class Lion : public Meet
{
public:
    Lion(int p) : Meet(p) {} 

  
    void EatMeet(Grass* obj) {
        Ñonsume(*obj);  
    }
};

class Wolf : public Meet
{
public:
    Wolf(int p) : Meet(p) {}  


    void EatMeet(Grass* obj) {
        Ñonsume(*obj);  
    }
};

int main()
{
    Antil antil(100);  
    Bison bison(150);  
    Lion lion(120);    
    Wolf wolf(110);   

    
    antil.EatGrass();
    cout << " Antil " << antil.getWeight() << " êã." << endl;

    bison.EatGrass();
    cout << " Bison " << bison.getWeight() << " êã." << endl;

    
    lion.EatMeet(&antil);
    cout << " Lion " << lion.getPower() << endl;

    wolf.EatMeet(&bison);
    cout << " Wolf " << wolf.getPower() << endl;

}

//Q.1 Create abstract class Fruit with abstract function taste Create derived classes for 
//Fruit: Apple, Mango and Orange
//implement abstract method in derived class, add specific methods like juice(),jam(),pulp() in respective derived class
//Create tester program. 
//Create fruit basket and invoke method Use dynamic cast,typeid

#include<iostream>
#include<typeinfo>

using namespace std;
class fruit{
    public :
        virtual void taste(){}
};
class apple : public fruit{
    public :
        void taste(){
            cout<<"Apple is sweet."<<endl;
         }
        void jam(){
            cout<<"apple has a jam"<<endl;
         }
};
class mango : public fruit{
    public :
         void taste(){
            cout<<"mango is awsomely sweet."<<endl;
         }
         void pulp(){
            cout<<"mango has a pulp"<<endl;
        }
};
class orange : public fruit{
    public :
         void taste(){
            cout<<"orange is sweet & sour."<<endl;
         }
         void juice(){
            cout<<"orange has a juice"<<endl;
         }
};
int main(){
    apple a;
    a.taste();
    mango m;
    m.taste();
    orange o;
    o.taste();

    fruit *basket[3];
    basket[0]=&a;
    basket[1]=&m;
    basket[2]=&o;

    for(int i=0; i<3; i++){
        basket[i]->taste();

        if(typeid(*basket[i])==typeid(apple)){
            dynamic_cast<apple*>(basket[i])->jam();
        } else if(typeid(*basket[i])==typeid(mango)){
            dynamic_cast<mango*>(basket[i])->pulp();
        } else if(typeid(*basket[i])==typeid(orange)){
            dynamic_cast<orange*>(basket[i])->juice();
        }
    }
    return 0;
}



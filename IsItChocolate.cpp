#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Prop {
    public:
        string name;
        string sight;
        string sound;
        string smell;
        string touch;
        string taste;
        bool isChocolate;
    Prop(string a, string i, string e, string n, string t, string m, bool c){
        name = a;
        sight = i;
        sound = e;
        smell = n;
        touch = t;
        taste = m;
        isChocolate = c;
    }
    string getName() { return name; }
    string see() { return sight; }
    string hear() { return sound; }
    string sniff() { return smell; }
    string poke() { return touch; }
    virtual string bite() { return taste; }
    bool getChocolate() { return isChocolate; }
};


class NotChocolate: public Prop {
    public:
    NotChocolate(string a, string i, string e, string n, string t, string m, bool c):Prop(a,i,e,n,t,m,c){ }
    string bite() override {
        return taste + "\nIT IS NOT CHOCOLATE!!!";
    }
};

class Chocolate: public Prop {
    public:
    Chocolate(string a, string i, string e, string n, string t, string m, bool c):Prop(a,i,e,n,t,m,c){ }
    string bite() override {
        return taste + "\nIT'S CHOCOLATE!!!";
    }
};

vector<Prop> shuf(vector<Prop> deck) {
        random_device rd;
        mt19937 gen(rd());
        shuffle(deck.begin(), deck.end(), gen);
        return deck;
}

int main()
{
    //Create a list of items
    vector<Prop> mundaneProps = {
        NotChocolate("Alarm Clock","It's a red alarm clock, with two shiny bells. It has two hands, for minutes and hours.","The clock is making a quiet ticking sound.","You can't smell much of anything from the Clock.","The clock is smooth and hard to the touch.","Your tooth slides against the hard, metal surface of the Clock.",false),
        NotChocolate("Stool","A brown, wooden stool with four legs and a circular seat.","You knock your hand on the stool, it sounds like wood.","There is no smell coming from the Stool.","The Stool is smooth to the touch.","Your tooth hurts as you bite into the wood of the Stool.",false),
        NotChocolate("Doorknob","A round doorknob, made of some yellow-colored material.","There are no sounds coming from the doorknob.","There is no smell coming from the Doorknob.","The Doorknob is smooth, it feels heavy too.","The Doorknob's metallic taste is far from chocolate, though not exactly unpleasant.",false),
        NotChocolate("Shoe","A black, leather shoe, no laces.","There is no sound coming from the shoe.","The shoe smells slightly of leather, and grass.","The shoe's texture is smooth, though with just enough friction to be percieved as leather.","It tastes like shoe.",false),
        NotChocolate("Pencil","A yellow pencil, its eraser looks used.","There is no sound coming from the pencil.","There is no smell coming from the pencil.","The pencil is light, it certainly feels like wood.","You bite into the pencil with a satisfying crunch, though the taste of wood and graphite is less pleasant.",false),
        NotChocolate("Table Lamp","A purple table lamp, with a white, cylindrical shade. Its currently on, and glowing.","There is a very faint humming sound coming from the lightbulb.","The lamp doesn't smell like much of anything.","The lightbulb explodes when you touch it. After a few minutes, a staff member walks over with a spare bulb and replaces it.","You bite into the lamp and taste nothing other than ceramic.",false),
    };
    
    vector<Prop> chocolateProps = {
        Chocolate("Alarm Clock","It's a red alarm clock, with two shiny bells. It has two hands, for minutes and hours.","There is no sound coming from the clock.","You can't smell much of anything from the Clock.","The clock is smooth and hard to the touch.","Your teeth bite into the clock, sinking into the rich, milky chocolate below.",true),
        Chocolate("Stool","A brown, wooden stool with four legs and a circular seat.","You knock your hand against the stool, it sounds hollow.","There is no smell coming from the Stool.","The Stool is smooth to the touch.","After a hard bite, you manage to take a chunk out of the stool's leg, revealing a hollow structure made of dark chocolate.",true),
        Chocolate("Doorknob","A round doorknob, made of some yellow-colored material.","There are no sounds coming from the doorknob.","There is no smell coming from the Doorknob.","The Doorknob is smooth, it feels light.","The Doorknob's fake golden texture peels away, with a shape of milk chocolate underneath.",true),
        Chocolate("Shoe","A black, leather shoe, no laces.","There is no sound coming from the shoe.","The shoe smells slightly sweet.","The shoe's texture is smooth, though with just enough friction to be percieved as leather.","To your relief, the shoe is made out of chocolate.",true),
        Chocolate("Pencil","A yellow pencil, it looks sharpened and with a full eraser.","There is no sound coming from the pencil.","There is no smell coming from the pencil.","The pencil is light, it certainly feels like wood.","You bite into the pencil with a satisfying crunch, its made out of brittle chocolate.",true),
        Chocolate("Table Lamp","A purple table lamp, with a white, cylindrical shade.","The lamp is not making any noise.","The lamp doesn't smell like much of anything.","You pull the lamp's chain, though despite having a lightbulb, it does not turn on.","You bite into the lamp. It has a crunchy exterior, though a soft creamy interior.",true),
    };
    
    
    
    //Define Variables
    vector<Prop> selection;
    int index;
    string choice;
    srand(time(0));
    bool gameEnd = false;

    //Grab 2 Props and 1 Chocolate
    selection.push_back(chocolateProps[rand()%6]);
    selection.push_back(mundaneProps[rand()%6]);
    selection.push_back(mundaneProps[rand()%6]);
    selection = shuf(selection);
    
    //Begin
    cout << "Welcome to...\nIS\nIT\nCHOCOLAAAAAAATE!!!\n\nYou have been given three items. One of them is chocolate, two are not.\nYou may examine these three as long as you wish, but you only have one chance to taste one to determine if it is truly chocolate!\n\n";
    
    //Item Choice Loop
    while (gameEnd == false) {
        cout << "Choose an item\n[1] - " << selection[0].getName() << "\n[2] - " << selection[1].getName() << "\n[3] - " << selection[2].getName() << endl;
        cin >> choice;
        index = stoi(choice);
        
        if (index < 1 or index > 3) { continue; }
        
        //Item Sense Loop
        while (gameEnd == false) {
            index -= 1;
            cout << "\nExamine the " << selection[index].getName() << "...\n[i] - Look\n[e] - Sound\n[n] - Smell\n[f] - Touch\n[b] - BITE\n";
            cin >> choice;
            cout << "\n";
            if (choice == "i") { cout << selection[index].see(); }
            else if (choice == "e") { cout << selection[index].hear(); }
            else if (choice == "n") { cout << selection[index].sniff(); }
            else if (choice == "f") { cout << selection[index].poke(); }
            else if (choice == "b") { 
                //Item is Chocolate, Victory
                if (selection[index].getChocolate()) {
                    Chocolate final = Chocolate("","","","","",selection[index].bite(),true);
                    cout << final.bite();
                }
                ///Item is not Chocolate, Defeat
                else {
                    NotChocolate final = NotChocolate("","","","","",selection[index].bite(),false);
                    cout << final.bite();
                }
                gameEnd = true;
            }
            
            cout << "\n\n";
            break;
        }
        
    }
    
    return 0;
}
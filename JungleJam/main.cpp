//Liam Slyne
//Final Project
//Jungle Jam
//League of Legends Jungle Simulator
//Prof. Hoenigman


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "JungleGraph.h"

using namespace std;

//all your player data is stored here
struct summoner{
    string name;
    string champion;
    string items [6];
    string currentLocation;
    int gold;
    int time;
}summoner1;

int main()
{
    Graph g; // creating the map as a Graph I have no idea why this isn't working
    g.addVertex("Base");
    g.addVertex("Top");
    g.addVertex("Middle");
    g.addVertex("Bottom");
    g.addVertex("Gromp");
    g.addVertex("Blue");
    g.addVertex("Wolves");
    g.addVertex("Raptors");
    g.addVertex("Red");
    g.addVertex("Krugs");

    g.addEdge("Base", "Top", 30); // the weight is determined by how long it takes to travel in seconds from one point to another
    g.addEdge("Base", "Middle", 27);
    g.addEdge("Base", "Bottom", 30);
    g.addEdge("Base", "Wolves", 25);
    g.addEdge("Base", "Krugs", 25);
    g.addEdge("Top", "Gromp", 8);
    g.addEdge("Top", "Middle", 24);
    g.addEdge("Gromp", "Blue", 5);
    g.addEdge("Gromp", "Wolves", 8);
    g.addEdge("Blue", "Wolves", 7);
    g.addEdge("Blue", "Middle", 15);
    g.addEdge("Wolves", "Middle", 10);
    g.addEdge("Wolves", "Raptors", 12);
    g.addEdge("Wolves", "Red", 15);
    g.addEdge("Raptors", "Red", 6);
    g.addEdge("Raptors", "Middle", 8);
    g.addEdge("Red", "Krugs", 7);
    g.addEdge("Middle", "Bottom", 24);
    g.addEdge("Red", "Bottom", 16);
    g.addEdge("Krugs", "Bottom", 12);

    summoner1.items[0] = " ";//setting up for the win requirements and at the end of the game
    summoner1.items[1] = " ";
    summoner1.items[2] = " ";
    summoner1.items[3] = " ";
    summoner1.items[4] = " ";
    summoner1.items[5] = " ";

    int j = 0;
    int minutes = 0;
    int seconds = 0;
    summoner1.time = 1300;
    summoner1.gold = 475;
    summoner1.currentLocation = "Base";

    cout << "Welcome to the League of Legends Jungle Simulation." << endl;
    cout << "First we need to know your name summoner." << endl;
    cin >> summoner1.name;

    string option = "";
    while(option != "start")//loop for user to confirm name and start champion select
    {
        cout << "OK so your name is: " << summoner1.name << "    yes/no" << endl;
        cin >> option;

        if(option == "no")
        {
            cout << "OK what would you like your name to be?" << endl;
            cin >> summoner1.name;
            cout << "OK so your name is: " << summoner1.name << "  yes/no" << endl;
            cin >> option;
        }
        if(option == "yes")
        {
            cout << "Great, to begin simply type start." << endl;
            cin >> option;
        }
        else
        {
            cout << "I'm sorry that is not a valid answer." << endl;
        }

    }
    string choice = "";
    while(choice != "start") // user loop for champion select
    {
        cout << "Next you need to pick your champion " << summoner1.name << "." << endl;
        cout << "There are three different types of champions you can choose from." << endl;
        cout << "1. Ability Power Champions:" << endl;
        cout << "Sejuani, Zac, Nunu, or Amumu." << endl;
        cout << "2. Attack Speed Champions:" << endl;
        cout << "Warwick, Udyr, or Nocturne." << endl;
        cout << "3. Physical Damage Champions:" << endl;
        cout << "LeeSin, RekSai, Rammus, Volibear, Vi, Shaco, Pantheon, or Hecarim." << endl;
        cout << "Pick your champion" << endl;
        cin >> summoner1.champion;
        cout << "Now that you have chosen your champion it is time to start." << endl;
        cout << "Type start to begin the simulation." << endl;
        cin >> choice;
    }
    string pick = "";
    while((pick != "7") || (summoner1.time > 1500))//simulation menu
    {
        cout << "What do you want to do " << summoner1.name << "?" << endl;
        cout << "1. View current gold." << endl;
        cout << "2. View current items, store, and buy items." << endl;
        cout << "3. View current location on the map." << endl;
        cout << "4. View current time." << endl;
        cout << "5. View Map" << endl;
        cout << "6. Choose where to go next." << endl;
        cout << "7. Surrender." << endl;
        cin >> pick;
        if(pick == "1") // option to see how much current gold you have
        {
            cout << "You have " << summoner1.gold << " gold." << endl;
        }else if(pick == "2")//item shopping
        {
            cout << "You have the following items:" << endl;//cout for the your items
            for(int i=0; i < 6; i++)
            {
                cout << i+1 << ". " << summoner1.items[i] << endl;
            }
            if(summoner1.currentLocation == "Base")
            {
                int wChoice; // store
                cout << "Pick a number corresponding with the item you wish to purchase." << endl;
                cout << "Ability Power Items:" << endl;
                cout << "1. Trailblazer:1500  2. Echo:2000     3. Deathcap:2500" << endl;
                cout << "4. Hourglass:2000    5. Rod:2250      6. VoidStaff:1750" << endl;
                cout << "Attack Speed Items:" << endl;
                cout << "7. Blade:1500        8. Zephyr:2250   9. Ghostblade:2000" << endl;
                cout << "10.Phantom:2500      11.Statikk:1750  12.WitsEnd:2000" << endl;
                cout << "Physical Damage Items:" << endl;
                cout << "13.Poacher:1500      14.Trinity:2500  15.Bloodthirster:2250" << endl;
                cout << "16.Reaver:2000       17.Whispers:1750 18.Scimitar:2000" << endl;
                cout << "19.Exit Store" << endl;
                cin >> wChoice; // weapon choice must be an integer


                if(wChoice == 1)//lots of if and else if statements that will add items to your inventory array
                {
                    if(summoner1.gold >= 1500)
                    {
                        summoner1.items[j] = "Trailblazer";
                        summoner1.gold = summoner1.gold - 1500;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 2)
                {
                    if(summoner1.gold >= 2000)
                    {
                        summoner1.items[j] = "Echo";
                        summoner1.gold = summoner1.gold - 2000;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 3)
                {
                    if(summoner1.gold >= 2500)
                    {
                        summoner1.items[j] = "Deathcap";
                        summoner1.gold = summoner1.gold - 2500;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 4)
                {
                    if(summoner1.gold >= 2000)
                    {
                        summoner1.items[j] = "Hourglass";
                        summoner1.gold = summoner1.gold - 2000;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 5)
                {
                    if(summoner1.gold >= 2250)
                    {
                        summoner1.items[j] = "Rod";
                        summoner1.gold = summoner1.gold - 2250;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 6)
                {
                    if(summoner1.gold >= 1750)
                    {
                        summoner1.items[j] = "VoidStaff";
                        summoner1.gold = summoner1.gold - 1750;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 7)
                {
                    if(summoner1.gold >= 1500)
                    {
                        summoner1.items[j] = "Blade";
                        summoner1.gold = summoner1.gold - 1500;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 8)
                {
                    if(summoner1.gold >= 2250)
                    {
                        summoner1.items[j] = "Zephyr";
                        summoner1.gold = summoner1.gold - 2250;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 9)
                {
                    if(summoner1.gold >= 2000)
                    {
                        summoner1.items[j] = "Ghostblade";
                        summoner1.gold = summoner1.gold - 2000;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 10)
                {
                    if(summoner1.gold >= 2500)
                    {
                        summoner1.items[j] = "Phantom";
                        summoner1.gold = summoner1.gold - 2500;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 11)
                {
                    if(summoner1.gold >= 1750)
                    {
                        summoner1.items[j] = "Statikk";
                        summoner1.gold = summoner1.gold - 1750;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 12)
                {
                    if(summoner1.gold >= 2000)
                    {
                        summoner1.items[j] = "WitsEnd";
                        summoner1.gold = summoner1.gold - 2000;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 13)
                {
                    if(summoner1.gold >= 1500)
                    {
                        summoner1.items[j] = "Poacher";
                        summoner1.gold = summoner1.gold - 1500;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 14)
                {
                    if(summoner1.gold >= 2500)
                    {
                        summoner1.items[j] = "Trinity";
                        summoner1.gold = summoner1.gold - 2500;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 15)
                {
                    if(summoner1.gold >= 2250)
                    {
                        summoner1.items[j] = "Bloodthirster";
                        summoner1.gold = summoner1.gold - 2250;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 16)
                {
                    if(summoner1.gold >= 2000)
                    {
                        summoner1.items[j] = "Reaver";
                        summoner1.gold = summoner1.gold - 2000;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 17)
                {
                    if(summoner1.gold >= 1750)
                    {
                        summoner1.items[j] = "Whisperer";
                        summoner1.gold = summoner1.gold - 1750;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 18)
                {
                    if(summoner1.gold >= 2000)
                    {
                        summoner1.items[j] = "Scimitar";
                        summoner1.gold = summoner1.gold - 2000;
                        j++;
                    }else
                    {
                        cout << "Sorry you do not have enough gold to purchase that item." << endl;
                    }
                }else if(wChoice == 19)
                {
                    cout << "Returning" << endl;
                }
            }else
            {
                cout << "You must return to Base in order to purchase items" << endl;
            }

        }else if(pick == "3")
        {
            cout << "Your current location is: " << summoner1.currentLocation << endl;

        }else if(pick == "4")
        {
            minutes = summoner1.time / 60;
            seconds = summoner1.time % 60;
            cout << "The current time is: " << minutes << " minutes and " << seconds << " seconds." <<endl;
        }else if(pick == "5")
        {
            g.displayEdges();
        }else if(pick == "6")
        {
            string destination = " ";
            cout << "Where would you like to go?" << endl;
            cin >> destination;
            if(summoner1.currentLocation == destination)
            {
                cout << "You are already located at " << summoner1.currentLocation << "." << endl;
            }
            else
            {
                g.findShortestDistance(summoner1.currentLocation, destination);
                summoner1.currentLocation = destination;
                if(destination == "Blue")
                {
                    summoner1.time = summoner1.time + 8;
                    summoner1.gold = summoner1.gold + 100;
                }else if(destination == "Gromp")
                {
                    summoner1.time = summoner1.time + 5;
                    summoner1.gold = summoner1.gold +60;
                }else if(destination == "Wolves")
                {
                    summoner1.time = summoner1.time + 5;
                    summoner1.gold = summoner1.gold +75;
                }else if(destination == "Raptors")
                {
                    summoner1.time = summoner1.time + 4;
                    summoner1.gold = summoner1.gold + 75;
                }else if(destination == "Red")
                {
                    summoner1.time = summoner1.time + 8;
                    summoner1.gold = summoner1.gold + 100;
                }else if(destination == "Krugs")
                {
                    summoner1.time = summoner1.time + 6;
                    summoner1.gold = summoner1.gold + 75;
                }else if(destination == "Top")
                {
                    int gankChance = rand() % 100;
                    if(gankChance >= 75)
                    {
                        cout << "Top Lane gank SUCCESS you gain 300 gold." << endl;
                        summoner1.gold = summoner1.gold + 300;
                        summoner1.time = summoner1.time + 10;
                    }else
                    {
                        cout << "Top Lane gank FAIL you only gain 50 gold." << endl;
                        summoner1.gold = summoner1.gold + 50;
                        summoner1.time = summoner1.time + 5;
                    }
                }else if(destination == "Middle")
                {
                    int gankChance = rand() % 100;
                    if(gankChance >= 75)
                    {
                        cout << "Middle Lane gank SUCCESS you gain 300 gold." << endl;
                        summoner1.gold = summoner1.gold + 300;
                        summoner1.time = summoner1.time + 10;
                    }else
                    {
                        cout << "Middle Lane gank FAIL you only gain 50 gold." << endl;
                        summoner1.gold = summoner1.gold + 50;
                        summoner1.time = summoner1.time + 5;
                    }
                }else if(destination == "Bottom")
                {
                    int gankChance = rand() % 100;
                    if(gankChance >= 75)
                    {
                        cout << "Bottom Lane gank SUCCESS you gain 300 gold." << endl;
                        summoner1.gold = summoner1.gold + 300;
                        summoner1.time = summoner1.time + 10;
                    }else
                    {
                        cout << "Bottom Lane gank FAIL you only gain 50 gold." << endl;
                        summoner1.gold = summoner1.gold + 50;
                        summoner1.time = summoner1.time + 5;
                    }
                }
                summoner1.time = summoner1.time + g.clockTemp; // adds the time
            }
        }else if(pick == "7")//  "FF at 20" surrender at any time
        {
            cout << "DEFEAT" << endl;
            return 0;
        }else if(summoner1.time >= 1500) //25 minutes
        {
            int winChance = rand() % 100;
            int win = 40;
            for(int i = 0; i < 6; i++)
            {
                if(summoner1.items[i] != " ")//every item you have gives you a 10% better chance to win the game
                {
                    win = win + 10;
                }
            }
            if(win >= winChance)
            {
                cout << "VICTORY" << endl;
            }else
            {
                cout << "DEFEAT" << endl;
            }
            return 0;
        }
    }
}

#include<iostream> //used to perform input output operation
#include<fstream>  //used for file handling
#include<string>  //to use string datatype
#include<iomanip> //to use setw we include this library


using namespace std;

const int arraySize = 4; // Set array size for id, matches, runs, and sixes
const int numPlayers = 11; // Set the number of players, you can change this as needed
int rows = 0;

struct Player
{
    int id;
    string name;
    string team;
    string role;
};

struct Playerinfo
{
    Player data;
    double matches;
    double runs;
    int sixes;
};

struct PlayerRecord
{
    Player data;
    Playerinfo data1;
    double average;
};


Player player;
Playerinfo playerinfo[numPlayers][arraySize];
PlayerRecord Player1;
void addfunction()

{


    ofstream fout; //to use file for storing output
    fout.open("players.txt", ios::app); //giving file name and also using append with it
    if (fout.is_open()) {
        cout << "enter player id = "; //asking user to enter player id 
        cin >> player.id; //storing value in id
        cout << "enter player name = "; //asking user to enter player id 
        cin >> player.name;  //storing value in name
        cout << "enter player team = \n"; //asking user to enter player id 
        cin >> player.team; //storing value in team
        cout << "enter player role = "; //asking user to enter player id 
        cin >> player.role; //storing value in role
        fout << player.id << setw(15) << player.name << setw(15) << player.team << setw(15) << player.role << endl; //storing values of all variables in file 
        // setw() is used to enter specified spaces between variables and entities 
        fout.close(); // closing the file
    }
    else {
        cout << "Error in opening file" << endl;//if there will be some error in opening in file it will display this message
    }
}


void viewfuntion()
{

    ifstream fin; //to use file for taking input
    fin.open("players.txt"); //opening file with the file name

    fin >> player.id >> player.name >> player.team >> player.role; //reading the values of variables from the file
    cout << "ID" << "\t" << setw(10) << "NAME" << "\t" << setw(10) << "TEAM" << "\t" << setw(10) << "ROLE" << endl; //displaying 
    cout << player.id << "\t" << setw(10) << player.name << "\t" << setw(10) << player.team << "\t" << setw(10) << player.role << endl; //displaying
    while (fin >> player.id >> player.name >> player.team >> player.role) //using loop so we read every value from the file one by one 
    {
        cout << "ID" << "\t" << setw(10) << "NAME" << "\t" << setw(10) << "TEAM" << "\t" << setw(10) << "ROLE" << endl; // displaying every variable and its entities 
        cout << player.id << "\t" << setw(10) << player.name << "\t" << setw(10) << player.team << "\t" << setw(10) << player.role << endl;  // displaying every variable and its entities
    }
    fin.close(); // closing the file

}
void findplayer()
{

    int IDfind; //declraing variables

    cout << "Enter ID of player to find: "; //asking user to enter the id he wants to find
    cin >> IDfind; //storing value in IDIn

    ifstream fin; //to use file for taking input
    fin.open("players.txt"); //opening file with the file name

    while (fin >> player.id >> player.name >> player.team >> player.role)
    {
        if (player.id == IDfind)
        {
            // Read and display the entire record associated with the matched name

            cout << "Match found:\n";
            cout << "ID" << "\t" << setw(10) << "NAME" << "\t" << setw(10) << "TEAM" << "\t" << setw(10) << "ROLE" << endl; // displaying every variable and its entities 
            cout << player.id << "\t" << setw(10) << player.name << "\t" << setw(10) << player.team << "\t" << setw(10) << player.role << endl;

            fin.close(); // Close the file
            return;
        }
    }
    cout << "Match not found" << endl; // Display this when match is not found
    fin.close(); // Close the file
}

void updateplayer()
{

    int IDfind; //declraing variables
    cout << "Enter the ID of the player to update: "; //asking user to enter the id he wants to update
    cin >> IDfind; //storing value in IDfind

    ifstream fin;
    fin.open("players.txt"); // to use file for taking input
    ofstream temp;
    temp.open("temp.txt");  // Open the temporary file 



    bool matchFound = false; // Initialized to false, as no match has been found yet.

    while (fin >> player.id >> player.name >> player.team >> player.role)
    {
        if (player.id == IDfind)
        {
            // Read and display the entire record associated with the matched ID


            cout << "Match found:\n";
            cout << "ID" << "\t" << setw(10) << "NAME" << "\t" << setw(10) << "TEAM" << "\t" << setw(10) << "ROLE" << endl; //displaying 
            cout << player.id << "\t" << setw(10) << player.name << "\t" << setw(10) << player.team << "\t" << setw(10) << player.role << endl; //displaying



            cout << "enter player id = "; //asking user to enter player id 
            cin >> player.id; //storing value in id
            cout << "enter player name = "; //asking user to enter player id 
            cin >> player.name;  //storing value in name
            cout << "enter player team = "; //asking user to enter player id 
            cin >> player.team; //storing value in team
            cout << "enter player role = "; //asking user to enter player id 
            cin >> player.role; //storing value in role
            temp << player.id << setw(15) << player.name << setw(15) << player.team << setw(15) << player.role << endl; //storing values of all variables in file using fout
            matchFound = true;  //if the idfile matches idfind bool will turn true
        }
        else {

            temp << player.id << setw(15) << player.name << setw(15) << player.team << setw(15) << player.role << endl;
        }
    }

    fin.close();   // Close the original file
    temp.close();  // Close the temp file

    if (!matchFound) //it will run when IDFile != IDfind
    {
        cout << "Match not found.\n"; //if id in file does not match the idfind it will display this
    }
    else {
        remove("players.txt");      // Remove the original file
        rename("temp.txt", "players.txt"); // Rename the temp file to the original file

    }
}

void deleteplayer()
{

    int IDfind; //declaring variables
    cout << "Enter the ID of the player to delete: "; //asking user to enter the id he wants to delete 
    cin >> IDfind; //storing value in variable

    ifstream fin;
    fin.open("players.txt"); //opeing file for taking input
    ofstream temp;
    temp.open("temp.txt", ios::app); // Open the temporary file in append mode

    bool matchFound = false; // Initialized to false, as no match has been found yet.



    while (fin >> player.id >> player.name >> player.team >> player.role) {
        if (player.id == IDfind) {
            // Read and display the entire record associated with the matched ID
            cout << "Match found:\n";
            cout << "ID" << "\t" << setw(10) << "NAME" << "\t" << setw(10) << "TEAM" << "\t" << setw(10) << "ROLE" << endl; //displaying 
            cout << player.id << "\t" << setw(10) << player.name << "\t" << setw(10) << player.team << "\t" << setw(10) << player.role << endl; //displaying

            matchFound = true; //if the idfile matches idfind bool will turn true
        }
        else {
            temp << player.id << setw(15) << player.name << setw(15) << player.team << setw(15) << player.role << endl; // Write non-matching records to the temporary file
        }
    }

    fin.close();   // Close the original file
    temp.close();  // Close the temp file

    if (!matchFound) {
        cout << "Match not found.\n"; //if id in file does not match the idfind it will display this
    }
    else {
        remove("players.txt");      // Remove the original file
        rename("temp.txt", "players.txt"); // Rename the temp file to the original file
    }
}

void addfunction(Playerinfo playerData[][arraySize])
{
    ofstream fout;
    fout.open("playersinfo.txt", ios::app);
    cout << "Enter player id: ";
    cin >> playerData[rows][0].data.id;

    cout << "Enter player matches: ";
    cin >> playerData[rows][1].matches;

    cout << "Enter player total runs: ";
    cin >> playerData[rows][2].runs;

    cout << "Enter player total sixes: ";
    cin >> playerData[rows][3].sixes;

    fout << playerData[rows][0].data.id << " " << playerData[rows][1].matches << " " << playerData[rows][2].runs << " " << playerData[rows][3].sixes << endl;


    rows++;

    fout.close();
}

void viewfunction(Playerinfo playerData[][arraySize])
{
    ifstream fin;
    fin.open("playersinfo.txt");


    cout << "ID" << "\t" << setw(10) << "Matches" << "\t" << setw(10) << "Runs" << "\t" << setw(10) << "Sixes" << endl;
    while (fin >> playerData[rows][0].data.id >> playerData[rows][1].matches >> playerData[rows][2].runs >> playerData[rows][3].sixes)
    {
        cout << playerData[rows][0].data.id << "\t" << setw(10) << playerData[rows][1].matches << "\t" << setw(10) << playerData[rows][2].runs << "\t" << setw(10) << playerData[rows][3].sixes << endl;
        rows++; // Increment the row for the next iteration
    }
    fin.close();

}

void findPlayer(Playerinfo playerData[][arraySize])
{
    ifstream fin;
    fin.open("playersinfo.txt");

    int idToFind;
    cout << "Enter ID of player to find: "; //asking user to enter player id he wants to search
    cin >> idToFind;
    while (fin >> playerData[rows][0].data.id >> playerData[rows][1].matches >> playerData[rows][2].runs >> playerData[rows][3].sixes) {

        rows++;
    }
    for (int i = 0; i < rows; ++i) {
        if (playerData[i][0].data.id == idToFind) {
            // Display the found player's information
            cout << "Match found" << endl;
            cout << playerData[i][0].data.id << "\t" << setw(10) << playerData[i][1].matches << "\t" << setw(10) << playerData[i][2].runs << "\t" << setw(10) << playerData[i][3].sixes << endl;

            fin.close();
            return;
        }
    }

    cout << "Match not found" << endl; // When id not get matched we will display this
    fin.close();
}

void updatePlayer(Playerinfo playerData[][arraySize]) {
    ifstream fin;
    fin.open("playersinfo.txt");

    ofstream temp;
    temp.open("temp.txt");

    int idToFind;
    cout << "Enter the ID of the player to update: ";
    cin >> idToFind;

    bool matchFound = false;

    for (int i = 0; i < rows; ++i) {
        if (playerData[i][0].data.id == idToFind) {
            cout << "Match found:\n";
            cout << playerData[i][0].data.id << "\t" << setw(10) << playerData[i][1].matches << "\t" << setw(10) << playerData[i][2].runs << "\t" << setw(10) << playerData[i][3].sixes << endl;

            cout << endl;

            cout << "Enter new information:\n";
            cout << "Enter player ID: ";
            cin >> playerData[i][0].data.id;
            cout << "Enter player Matches: ";
            cin >> playerData[i][1].matches;
            cout << "Enter player Runs: ";
            cin >> playerData[i][2].runs;
            cout << "Enter player Sixes: ";
            cin >> playerData[i][3].sixes;

            temp << playerData[i][0].data.id << " " << playerData[i][1].matches << " " << playerData[i][2].runs << " " << playerData[i][3].sixes << endl;

            matchFound = true;
        }
        else {
            temp << playerData[i][0].data.id << "\t" << setw(10) << playerData[i][1].matches << "\t" << setw(10) << playerData[i][2].runs << "\t" << setw(10) << playerData[i][3].sixes << endl;
        }
    }

    fin.close();   // Close the original file
    temp.close();  // Close the temp file

    if (!matchFound) {
        cout << "Match not found.\n";
    }
    else {
        remove("playersinfo.txt");      // Remove the original file
        rename("temp.txt", "playersinfo.txt"); // Rename the temp file to the original file
    }
}

void playeraverage(Playerinfo playerData[][arraySize]) {
    ifstream fin;
    fin.open("players.txt");

    ifstream finn;
    finn.open("playersinfo.txt");

    ofstream fout;
    fout.open("playerrecord.txt", ios::app);

    int idavg;
    cout << "Enter ID of the player you want to find the average of: ";
    cin >> idavg;

    bool matchFound = false;


    // Read player data from "players.txt" file

    while (fin >> player.id >> player.name >> player.team >> player.role) {
        if (player.id == idavg) {



            // Read player info from "playersinfo.txt" file

            while (finn >> playerData[rows][0].data.id >> playerData[rows][1].matches >> playerData[rows][2].runs >> playerData[rows][3].sixes) {
                if (idavg == player.id && idavg == playerData[rows][0].data.id) {
                    // Display the found player's information
                    cout << "ID" << "\t" << setw(10) << "NAME" << "\t" << setw(10) << "TEAM" << "\t" << setw(10) << "ROLE" << endl;
                    cout << player.id << "\t" << setw(10) << player.name << "\t" << setw(10) << player.team << "\t" << setw(10) << player.role << setw(10) << "\nData in file 1\n" << endl;
                    cout << playerData[rows][0].data.id << "\t" << setw(10) << playerData[rows][1].matches << "\t" << setw(10) << playerData[rows][2].runs << "\t" << setw(10) << playerData[rows][3].sixes << setw(10) << "\nData in file 2" << endl;
                    cout << "Match found" << endl;
                    // Calculate and display the average

                    Player1.average = (playerData[rows][2].runs) / playerData[rows][1].matches;
                    cout << "The average of the player is " << Player1.average << endl;

                    // Write the average to the file
                    fout << Player1.average << endl;

                    matchFound = true;
                }
                rows++;
            }
        }
    }

    if (!matchFound) {
        cout << "Player not found" << endl;
    }

    fin.close();
    finn.close();
    fout.close();
}

void viewplayeraverage(Playerinfo playerData[][arraySize])
{
    ifstream fin;
    fin.open("playerrecord.txt");
    cout << "The average of the Players are:\n";
    while (fin >> Player1.average)
    {
        cout << Player1.average << endl;
    }

}

void firstmenu() //writing this function to ask user to perform which activity 
{

    cout << "1.to add player \n2.to view player\n 3.to find player\n 4.to update player\n 5.to delete player\n 6.back\n"; // asking user to press the following number to perform a certain task as given
    int option; // decalring variable
    cin >> option; // storing value in variable 
    switch (option) //using switch statement to use menu
    {
    case 1:
        cout << "CALLING ADD FUNCTION" << endl; // if user press 1 we will call the add function 
        addfunction(); // if user press 1 we will call the add function 
        break; // so other cases dont run 
    case 2:
        cout << "CALLING view FUNCTION" << endl; // if user press 2 we will call the view function
        viewfuntion(); // if user press 2 we will call the add function
        break; // so other cases dont run
    case 3:
        cout << "calling find function" << endl; // if user press 3 we will call the find function
        findplayer(); // if user press 3 we will call the add function
        break; // so other cases dont run
    case 4:
        cout << "calling update function" << endl; // if user press 4 we will call the update function
        updateplayer(); // if user press 4 we will call the add function
        break; // so other cases dont run

    case 5:
        cout << "calling delete function" << endl; // if user press 5 we will call the delete function
        deleteplayer();  // if user press 5 we will call the delete function
        break; // so other cases dont run 
    case 6:

        break; // returns to main menu
    default:
        cout << "invalid option" << endl; //if user select other number than given than we'll display this

    }
}

void secondmenu(Playerinfo playerData[][arraySize]) {
    // Display options for the second menu
    cout << "Cricket management system" << endl;
    cout << "1. to add player\n2. to view player\n3. to find player\n4. to update player\n5. back\n";
    int option;
    cin >> option;

    // Switch case for handling user choices
    switch (option) {
    case 1:
        cout << "CALLING ADD FUNCTION" << endl;
        addfunction(playerData);
        break;
    case 2:
        cout << "CALLING VIEW FUNCTION" << endl;
        viewfunction(playerData);
        break;
    case 3:
        cout << "Calling find function" << endl;
        findPlayer(playerData);
        break;
    case 4:
        cout << "Calling update function" << endl;
        updatePlayer(playerData);
        break;
    case 5:
        break; // returns to main menu
    default:
        cout << "Invalid option. Try again." << endl; //if user select other number than given than we'll display this
    }
}

void thirdmenu(Playerinfo playerData[][arraySize])
{
    cout << "Cricket management system" << endl;
    cout << "1. to caclulate average\n2. to view player average\n3. back\n";
    int option;
    cin >> option;

    // Switch case for handling user choices
    switch (option) {
    case 1:
        cout << "CALLING Average FUNCTION" << endl;
        playeraverage(playerData);
        break;
    case 2:
        cout << "CALLING VIEW FUNCTION" << endl;
        viewplayeraverage(playerData);
        break;
    case 3:
        break; // returns to main menu
    default:
        cout << "Invalid option. Try again." << endl; //if user select other number than given than we'll display this
    }
}
void mainmenu(Playerinfo playerData[][arraySize]) {
    // Infinite loop for the main menu
    while (true) {
        cout << "Cricket management system" << endl; // giving my program a label
        cout << "Main Menu" << endl;
        cout << "1. Continue to Menu 1\n2. Continue to Menu 2\n3. Continue to Menu 3\n4.  Exit\n";
        int mainMenuOption;
        cin >> mainMenuOption;

        // Switch case for handling user choices in the main menu
        switch (mainMenuOption) {
        case 1:
            firstmenu();  // Fixed the function name
            break;
        case 2:
            cout << "CALLING MENU 2" << endl;
            secondmenu(playerData);  // Passed playerData to the function
            break;
        case 3:
            cout << "CALLING MENU 3" << endl;
            thirdmenu(playerData);  // Passed playerData to the function
            break;
        case 4:
            exit(0); // to exit function 
        default:
            cout << "Invalid option. Try again." << endl; //if user select other number than given than we'll display this
        }
    }
}

int main() {

    Playerinfo playerData[numPlayers][arraySize]; // Declaration of a 2D array to store player data




    // Infinite loop to repeatedly display the menu
    while (true) {
        mainmenu(playerData);
    }

    return 0;
}
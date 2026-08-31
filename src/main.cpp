#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to hold information about each team
struct Team {
    string name;
    string fact;
    string color;
    string sponsor;
    int driversTitles;
    int constructorsTitles;
};

// Function prototypes
vector<Team> loadTeams();
void showMenu();
void showTeams(const vector<Team> &teams);
void showTeamInfo(const Team &team);
void compareTeams(vector<Team> &teams);
void addTeam(vector<Team> &teams);
string chooseColor();
void sortTeams(vector<Team> &teams);
int getChoice(const vector<Team> &teams, string message);

int main() {
    vector<Team> teams = loadTeams();
    int choice = 0;
    
    cout << "F1 TEAM SELECTOR" << endl;
    
    while (choice != 5) {
        showMenu();
        cin >> choice;
        
        if (choice == 1) {
            showTeams(teams);
            int teamNumber = getChoice(teams, "Pick a team number: ");
            showTeamInfo(teams[teamNumber]);
        } 
        else if (choice == 2) {
            compareTeams(teams);
        } 
        else if (choice == 3) {
            addTeam(teams);
        } 
        else if (choice == 4) {
            sortTeams(teams);
            cout << "\nTeams sorted by constructors championships!" << endl;
            showTeams(teams);
        } 
        else if (choice == 5) {
            cout << "\nThanks for using the F1 Team Selector!" << endl;
        } 
        else {
            cout << "Not a valid option. Try again." << endl;
        }
    }
    return 0;
}

// Loads the starting teams
vector<Team> loadTeams() {
    vector<Team> teams;
    
    Team ferrari;
    ferrari.name = "Ferrari";
    ferrari.fact = "Ferrari is the oldest and one of the most successful teams in F1.";
    ferrari.color = "red";
    ferrari.sponsor = "Shell";
    ferrari.driversTitles = 15;
    ferrari.constructorsTitles = 16;
    teams.push_back(ferrari);
    
    Team mercedes;
    mercedes.name = "Mercedes";
    mercedes.fact = "Mercedes had two seven-time world champions: Lewis Hamilton and Michael Schumacher.";
    mercedes.color = "silver/teal";
    mercedes.sponsor = "Petronas";
    mercedes.driversTitles = 9;
    mercedes.constructorsTitles = 9;
    teams.push_back(mercedes);
    
    Team mclaren;
    mclaren.name = "McLaren";
    mclaren.fact = "McLaren was founded by Bruce McLaren, a Formula 1 driver from the 1960s.";
    mclaren.color = "papaya orange";
    mclaren.sponsor = "Google";
    mclaren.driversTitles = 12;
    mclaren.constructorsTitles = 9;
    teams.push_back(mclaren);
    
    Team redBull;
    redBull.name = "Red Bull";
    redBull.fact = "Red Bull won 21 out of 22 races during the 2023 F1 season.";
    redBull.color = "navy blue";
    redBull.sponsor = "Oracle";
    redBull.driversTitles = 6;
    redBull.constructorsTitles = 6;
    teams.push_back(redBull);
    
    return teams;
}

// Displays the menu
void showMenu() {
    cout << "\n1. View a team's information" << endl;
    cout << "2. Compare two teams" << endl;
    cout << "3. Add a new team" << endl;
    cout << "4. Sort teams by constructors championships" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Displays the team names
void showTeams(const vector<Team> &teams) {
    cout << endl;
    for (size_t i = 0; i < teams.size(); i++) {
        cout << i + 1 << ". " << teams[i].name << endl;
    }
}

// Displays the information for a team
void showTeamInfo(const Team &team) {
    cout << "\n--- " << team.name << " ---" << endl;
    cout << "Fact: " << team.fact << endl;
    cout << "Car color: " << team.color << endl;
    cout << "Main sponsor: " << team.sponsor << endl;
    cout << "Drivers championships: " << team.driversTitles << endl;
    cout << "Constructors championships: " << team.constructorsTitles << endl;
}

// Gets a valid team choice
int getChoice(const vector<Team> &teams, string message) {
    int choice;
    cout << message;
    cin >> choice;
    while (choice < 1 || choice > static_cast<int>(teams.size())) {
        cout << "Invalid choice. Enter a number from 1 to " << teams.size() << ": ";
        cin >> choice;
    }
    return choice - 1; // Return 0-indexed for vector placement
}

// Compares two teams
void compareTeams(vector<Team> &teams) {
    showTeams(teams);
    int firstTeam = getChoice(teams, "Pick the first team: ");
    int secondTeam = getChoice(teams, "Pick the second team: ");
    
    cout << "\n" << teams[firstTeam].name << " vs " << teams[secondTeam].name << endl;
    cout << "Drivers championships: " << teams[firstTeam].driversTitles << " vs " << teams[secondTeam].driversTitles << endl;
    cout << "Constructors championships: " << teams[firstTeam].constructorsTitles << " vs " << teams[secondTeam].constructorsTitles << endl;
    
    if (teams[firstTeam].constructorsTitles > teams[secondTeam].constructorsTitles) {
        cout << teams[firstTeam].name << " has more constructors championships." << endl;
    } else if (teams[secondTeam].constructorsTitles > teams[firstTeam].constructorsTitles) {
        cout << teams[secondTeam].name << " has more constructors championships." << endl;
    } else {
        cout << "The two teams are tied!" << endl;
    }
}

// Allows the user to add a team
void addTeam(vector<Team> &teams) {
    Team newTeam;
    cin.ignore(); // Clear stream buffer
    
    cout << "\nTeam name: ";
    getline(cin, newTeam.name);
    
    cout << "Fun fact: ";
    getline(cin, newTeam.fact);
    
    newTeam.color = chooseColor();
    cin.ignore(); // Clear buffer after numeric choice inside chooseColor
    
    cout << "Main sponsor: ";
    getline(cin, newTeam.sponsor);
    
    cout << "Drivers championships: ";
    cin >> newTeam.driversTitles;
    while (newTeam.driversTitles < 0) {
        cout << "Number must be 0 or more. Enter again: ";
        cin >> newTeam.driversTitles;
    }
    
    cout << "Constructors championships: ";
    cin >> newTeam.constructorsTitles;
    while (newTeam.constructorsTitles < 0) {
        cout << "Number must be 0 or more. Enter again: ";
        cin >> newTeam.constructorsTitles;
    }
    
    teams.push_back(newTeam);
    cout << "\nTeam added successfully!" << endl;
}

// Lets the user choose a car color
string chooseColor() {
    int colorChoice;
    cout << "\nPick a car color:" << endl;
    cout << "1. red\n2. blue\n3. black\n4. white\n5. green" << endl;
    cout << "Choice: ";
    cin >> colorChoice;
    
    switch (colorChoice) {
        case 1: return "red";
        case 2: return "blue";
        case 3: return "black";
        case 4: return "white";
        case 5: return "green";
        default: return "unknown";
    }
}

// Sorts teams by constructors championships (descending order - highest first)
void sortTeams(vector<Team> &teams) {
    for (size_t i = 0; i < teams.size() - 1; i++) {
        for (size_t j = 0; j < teams.size() - 1 - i; j++) {
            // Flipped to '<' so that highest championship teams bubble to top
            if (teams[j].constructorsTitles < teams[j + 1].constructorsTitles) {
                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
}

//Priscilla Cook
//UserCalorie Implementation File
//February 5th, 2023
//This class defines the functions
//found in "UserCalorie.h"

#include <iostream>
#include "UserCalorie.h"
#include <iostream>
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

UserCalorie::UserCalorie()
{
    //initialize variables to zero so they can be used in the program
    CalorieTotal=0;
    MenuEntry=0;
    totalFoodItems = 0;
    numOfNewFoodItems = 0;
    addMore = 0;
    calcOrNo = 0;
    CaloriesBurnt = 0;
    CalDeficit = 0;
    recalc = 0;
    viewhis = 0;
    modify = 0;
    gender = 0;
    age = 0;
    weight = 0;
    itemCals = 0;
    activity = 0;

    DeficitWords = " ";

    foodItems[0].name = " ";
    foodItems[0].itemCals = 0;
}

void UserCalorie::Welcome()
{
    //welcome user
   cout << "*******************************************" << endl;
    cout << "Welcome to the Calorie Tracker Program!" << endl;
    cout << "*******************************************" << endl << endl;

    //explain program to user
    cout << "*******************************************" << endl;
    cout << " With this program you can " << endl;
    cout << " track your daily caloric intake," << endl;
    cout << " create a record of your eating habits," << endl;
    cout << " and set a caloric goal." << endl;
    cout << "*******************************************" << endl<< endl;

    //display menu options
    Menu();

}
void UserCalorie::Menu()
{
    //output menu options
    cout << "*******************MENU********************" << endl;
    cout << " Set caloric goal . . . . . . . . . press 1" << endl;
    cout << " Enter new food item . . . . . . .  press 2" << endl;
    cout << " Display caloric intake . . . . . . press 3" << endl;
    cout << " Display food history . . . . . . . press 4" << endl;
    cout << " Quit program . . . . . . . . . . . press 5" << endl;
    cout << "*******************************************" << endl;

    //get input from user
    cin >> MenuEntry;
    ValidateEntry(MenuEntry, 1, 5); //validate user input is between 1 and 5

    if (MenuEntry==1) //if user entry is 1
        SetCalGoal(); // proceed to set calorie goal
    if (MenuEntry==2) //if user entry is 2
        NewFood(); //proceed to let user add new food
    if (MenuEntry==3) //if user entry is 2
        PrintCalTotal(); //proceed to user displaying calories
    if (MenuEntry==4) //if user entry is 2
        FoodHistory(); //display food history
    if (MenuEntry==5) //if user entry is 2
        Quit(); //quit program

    return;

}
void UserCalorie::SetCalGoal()
{
    //while recalc is not equal to 2
    while (recalc != 2){ //while user does not want to return to menu

    //display options to user
    cout << "**********************************************************" << endl;
    cout << "Would you like a calorie goal to be calculated for you?" << endl;
    cout << "Please and thank you! . . . . . . . . . . . . . press 1" << endl;
    cout << "No thanks! I know my calorie goal . . . . . . . press 2" << endl;

    //get user input
    cin >> calcOrNo;
    ValidateEntry(calcOrNo, 1, 2); // validate entry is between 1 and 2
    cout << "**********************************************************" << endl << endl;

    //if calcOrNo is 2, let user set goal manually
       if (calcOrNo == 2)
        ManualGoal();
     //if calcOrNo is 2, let user calculate goal
       if (calcOrNo == 1)
        CalculateGoal();

    //*****************************************
    // GO BACK AND FORMAT THIS BETTER
    // ITS CROOKED!!
    //******************************************

//output options to user
    cout << "*******************************************************************" << endl;
        cout << " Would you like to modify your calorie goal? " << endl;
        cout << " Modify calorie goal . . . . . . . . press 1" << endl;
        cout << " Return to Menu . . .. . . . . . . . press 2" << endl;
       //get user input
        cin >> recalc;
        ValidateEntry(recalc, 1, 2); //validate if entry is between 1 and 2
        cout << "*******************************************************************" << endl;

        }
        //if recalc is 2, return to menu
        if(recalc == 2)
            Menu();

    return;
}

void UserCalorie::CalcDeficit()
{
    //prompt user for how much weight they want to lose
        cout << "*****************************************************" << endl;
        cout << "How many pounds would you like to lose each week?" << endl;
        cout << "Half of a pound per week . . . . . . . . press 1" << endl;
        cout << "One pound per week . . . . . . . . . . . press 2" << endl;
        cout << "One and a half pounds per week . . . . . press 3" << endl;
        cout << "Two pounds per week . . . . . . . . . .  press 4" << endl;
        //get user input
        cin >> CalDeficit;
        ValidateEntry(CalDeficit, 1, 4); //validate entry is between 1 and 4
        cout << endl << "*****************************************************" << endl;

        //if user entered 1, set CalDeficit to 250.
         if(CalDeficit == 1)
            {CalDeficit = 250;
            DeficitWords = "half of a pound per week";}

    //if user entered 1, set CalDeficit to 250.
        if(CalDeficit == 2)
            {CalDeficit = 500;
            DeficitWords = "one pound per week";}

            //if user entered 1, set CalDeficit to 250.
        if(CalDeficit == 3)
            {CalDeficit = 750;
            DeficitWords = "one and a half pounds per week";}

            //if user entered 1, set CalDeficit to 250.
        if(CalDeficit == 4)
            {CalDeficit = 1000;
            DeficitWords = "two pounds per week";}

    return;
}
void UserCalorie::ManualGoal()
{
    while (modify != 2){ //while modify is not equal to 2, proceed into while loop
    cout << endl<< "*******************************************************************" << endl;
    //prompt user for calorie goal
     cout << "Please enter a calorie goal between 500 and 10,000" << endl;
     cin >>  CalGoal;
     ValidateEntry(CalGoal, 500, 10000); //validate user entry is between 500 and 10000

     //display calorie goal to user
     cout << endl << "Your calorie goal is set as " << CalGoal << " calories." << endl;
     cout << "*******************************************************************" << endl << endl;

     //prompt user to modify calorie goal
     cout << "*******************************************************************" << endl;
        cout << " Would you like to modify your calorie goal? " << endl;
        cout << " Modify calorie goal . . . . . . . . press 1" << endl;
        cout << " Return to Menu . . .. . . . . . . . press 2" << endl;
        //get user input
        cin >> modify;
        ValidateEntry(modify, 1, 2); //validate user entry is between 1 and 2
        cout << "*******************************************************************" << endl << endl;
}

        //if modify is equal to 2, return to menu
        if(modify == 2)
            Menu();

    return;
}
void UserCalorie::CalculateGoal()
{
    //prompt user for gender
        cout << "*******************************" << endl;
        cout << "What is your gender?" << endl;
        cout << "Female . . . . . press 1" << endl;
        cout << "Male . . . . . . press 2" << endl;
        cout << "*******************************" << endl;
        //get user input
        cin >> gender;
        ValidateEntry(gender, 1, 2); //validate if entry is between 1 and 2
        userGoal.gender = gender; //set gender and userGoal.gender to be equal

        //prompt user for age
        cout << endl<< "**************************************************" << endl;
        cout << "How old are you? Please enter an age between 12 and 150." << endl;
        //get user inpute
        cin >> age;
        ValidateEntry(age, 12, 150); //validate if entry is between 12 and 150
        userGoal.age = age; //set age and userGoal.age to be equal

        cout << endl<< "*******************************" << endl;

        cout << endl<< "*******************************" << endl;

        //prompt user for height
        cout << "How tall are you?" << endl;
        cout << "Feet (1-13): ";
        //get user input
        cin >> userGoal.heightFt;
        ValidateEntry(userGoal.heightFt, 1, 13); // validate of entry is between 1 and 13
        cout << "Inches (0-12): ";
        //get user input
        cin >> userGoal.heightIn;
        ValidateEntry(userGoal.heightIn, 1, 12); // validate of entry is between 1 and 13
        cout << endl<< "*******************************" << endl;

        //convert height to inches
        userGoal.height = (userGoal.heightFt * 12) + userGoal.heightIn;

        //prompt user for weight
        cout << endl<< "*******************************" << endl;
        cout << "How much do you weigh? (Between 50-700)" << endl;
        //get user input
        cin >> weight;
        ValidateEntry(weight, 50, 700); //validate entry is between 50 and 700
        userGoal.weight = weight; //set weight and userGoal.weight to be equal

        cout << endl<< "*******************************" << endl;

        //prompt user for activity level
        cout << "**********************************************" << endl;
        cout << "How would you rate your activity level?" << endl;
        cout << "Little to no exercise . . . . . press 1" << endl;
        cout << "Slightly active . . . . . . . . press 2" << endl;
        cout << "Moderately active . . . . . . . press 3" << endl;
        cout << "Very active . . . . . . . . . . press 4" << endl;
        cout << "Extra active . . . . . . . . . .press 5" << endl;
        cout << "*******************************************" << endl;
        //get user input
        cin >> activity;
        ValidateEntry(activity, 1, 5); //validate that entry is between 1 and 5
        userGoal.activity = activity; //set activity and userGoal.activity to be equal

        //if user entered 1, set userGoal.activity to 1.2
        if(userGoal.activity == 1)
            userGoal.activity = 1.2;

        //if user entered 2, set userGoal.activity to 1.37
        if(userGoal.activity == 2)
            userGoal.activity = 1.37;

        //if user entered 3, set userGoal.activity to 1.55
        if(userGoal.activity == 3)
            userGoal.activity = 1.55;

        //if user entered 4, set userGoal.activity to 1.725
        if(userGoal.activity == 4)
            userGoal.activity = 1.725;

        //if user entered 5, set userGoal.activity to 1.9
        if(userGoal.activity == 5)
            userGoal.activity = 1.9;

//if gender is 1, calculate with this equation
if(userGoal.gender==1)
    CaloriesBurnt = (655.1 + (4.35 * userGoal.weight) + (4.7 * userGoal.height) - (4.7 * userGoal.age)) * userGoal.activity;

//if gender is 2, calculate with this equation
if(userGoal.gender==2)
    CaloriesBurnt = (66 + (6.2 * userGoal.weight) + (12.7 * userGoal.height) - (6.76 * userGoal.age)) * userGoal.activity;

    //calculate appropriate calorie deficit
    CalcDeficit();

    //output results to user
    cout << "It is estimated that you burn an average of " << CaloriesBurnt << " calories each day." << endl;
    cout << "In order to lose " << DeficitWords << " you need to decrease your " << endl;
    cout << "Calorie intake by " << CalDeficit << endl;

    //calculate calorie goal based on results
    CalGoal = CaloriesBurnt - CalDeficit;

    //output calorie goal to user
    cout << "Your personal calorie goal is calculated to be " << CalGoal << " calories." << endl;

    return;
}
void UserCalorie::NewFood()
{
     if (totalFoodItems == 0) //if totalFoodItems is 0, output "very first food item" message
    {cout << "*******************************************************************" << endl;
     cout << "Let's start by adding your very first food item!" << endl;
     cout << "In order to do this you will need to know the caloric" << endl;
     cout << "content of your meals. This can usually be found on the" << endl;
     cout << "back of packaging labels or the manufacturers website." << endl;
     cout << "*******************************************************************" << endl << endl;
    }
while (addMore != 2){ //while addMore is not 2, proceed into loop to get another food item
    cout << "************************************************************************" << endl;
    cout << "How many new food items would you like to add? (Between 1-10 at a time)" << endl;
    //prompt user for how many food items they want to add
    cin >> numOfNewFoodItems;
    ValidateEntry(numOfNewFoodItems, 1, 10); //validate that entry is between 1 and 10
    cout << "************************************************************************" << endl << endl;

    //update totalFoodItems to reflect new items being added
    totalFoodItems = numOfNewFoodItems + totalFoodItems;

//if totalFoodItems is equal to numOfNewFoodItems, use this loop
if ( totalFoodItems == numOfNewFoodItems ){
        //loop through the number of new food items to add the items into the array
   for (int i = 0; i < numOfNewFoodItems ; i++)
       {string name;
        cout << "Food Item #" << i+1<< ":" << endl;
        cout << "Please enter the name of this meal: " << endl;
        cin.ignore(); //clear input stream
        getline (cin, foodItems[i].name); //get food name

        //prompt user for food item calories
        cout << endl << "How many calories are in this meal?" << endl;
        //get user input
        cin >> itemCals;
        ValidateEntry(itemCals, 0, 10000); //validate that entry is between 0 and 10000
        foodItems[i].itemCals = itemCals; //set foodItems[i].itemCals equal to itemCals

        cout << endl<< "You entered: " << endl; //output user entry

        //loop that displays all the food items added to food history
   for (int x = 0; x <= i ; x++)
        {
        cout << x+1 << ". " << foodItems[x].name << " . . . . . " << foodItems[x].itemCals << " calories." << endl << endl;}
       }}

//if totalFoodItems is not equal to numOfNewFoodItems, use this loop
if ( totalFoodItems != numOfNewFoodItems ){
        //z is equal to the total food items minus the number of new food items
        int z = totalFoodItems - numOfNewFoodItems;

        //loop through array starting at the last entry which is equal to foodItems[z]
   for (int i = z; i < totalFoodItems ; i++)
       {string name;
        cout << "Food Item #" << i+1<< ":" << endl;
        //prompt user for food name
        cout << "Please enter the name of this meal: " << endl;
        cin.ignore(); //clear input stream
        getline (cin, foodItems[i].name);
        //prompt user for calories in food
        cout << endl << "How many calories are in this meal? (Between 0-10000)" << endl;
        //get user entry
        cin >> itemCals;
        ValidateEntry(itemCals, 0, 10000); //validate that entry is between 0 and 10000
        foodItems[i].itemCals = itemCals; //set foodItems[i].itemCals equal to itemCals

        cout << endl<< "You entered: " << endl; //output user entry

        //loop that displays all the food items added to food history
   for (int x = 0; x <= i ; x++)
        {
        cout << x+1 << ". " << foodItems[x].name << " . . . . . " << foodItems[x].itemCals << " calories." << endl << endl;}
       }}

        cout << "*******************************************************************" << endl << endl;

        //prompt user to return to menu or add another food item
        cout << "*******************************************************************" << endl;
        cout << " Would you like to add another food item? " << endl;
        cout << " Add another item . . . . . . . . . press 1" << endl;
        cout << " Return to Menu . . .. . . . . . .  press 2" << endl;
        //get user input
        cin >> addMore;
        ValidateEntry(addMore, 1, 2); //validate entry is between 1 and 2
}
        //if addMore is 2, return to Menu
        if (addMore == 2)
            Menu();

    return;
}
void UserCalorie::PrintCalTotal()
{
    //for loop that traverses through the foodItems array to add up all the calories
    //loop ends when x is not less than totalFoodItems
    for (int x = 0; x < totalFoodItems ; x++)
        //formula to calculate calorie total
        {CalorieTotal = CalorieTotal + foodItems[x].itemCals;}

        //output calorie total to user
        cout << endl<< "*******************************************************************" << endl;
        cout << "You have consumed a total of " << CalorieTotal << " calories." << endl;
        cout << "*******************************************************************" << endl << endl;

        //prompt user to view food history
        cout << "*******************************************************************" << endl;
        cout << " Would you like to view your Food History? " << endl;
        cout << " View Food History . . . . . . . . press 1" << endl;
        cout << " Return to Menu . . .. . . . . . . press 2" << endl;
        //get user input
        cin >> viewhis;
        ValidateEntry(viewhis, 1, 2); //validate entry is between 1 and 2

        cout << "*******************************************************************" << endl << endl;

        //if viewhis is 1, go to food history
        if(viewhis == 1)
            FoodHistory();
            //if viewhis is 1, go to menu
        if(viewhis == 2)
            Menu();

    return;
}
void UserCalorie::FoodHistory()
{
    //output total food items
    cout << "*******************************************************************" << endl;
    cout << "You currently have " << totalFoodItems << " items in your Food History. " << endl;
    cout << "*******************************************************************" << endl << endl;

    //for loop that traverses through foodItems to display food history to user
     for (int x = 0; x < totalFoodItems ; x++)
        {
        cout << x+1 << ". " << foodItems[x].name << " . . . . . " << foodItems[x].itemCals << " calories." << endl << endl;}

        //prompt user to add to food history
        cout << "*******************************************************************" << endl;
        cout << " Would you like to add to your Food History? " << endl;
        cout << " Add to Food History . . . . . . . . . press 1" << endl;
        cout << " Return to Menu . . .. . . . . . . . . press 2" << endl;
        //get user input
        cin >> addMore;
        ValidateEntry(addMore, 1, 2); //validate entry is between 1 and 2
        cout << "*******************************************************************" << endl;

        //if addMore is 1, add new food item
        if(addMore == 1)
            NewFood();
        //if addMore is 1, go to menu
        if(addMore == 2)
            Menu();

   return;
}

void UserCalorie::ValidateEntry(int &obj, int lower, int upper)
{
do { //do the following while obj is less than lower or more than upper

//if obj is less than lower or more than upper display invalid entry
    if (obj < lower || obj > upper)
    {cout << "Invalid Entry!" << endl;
    //prompt user for valid entry
    cout << "Please enter a valid entry!" << endl;
    //get user input
    cin >> validEntry;
    //set obj and validEntry to be equal
        obj = validEntry;}

//do the following above while obj is less than lower or more than upper
} while (obj < lower || obj > upper);

   return;
}
void UserCalorie::Quit()
{
    //OUTPUT PROMPT TO ABORT QUIT PROCESS
        cout << "***************************************************" << endl;
        cout << setw(27) <<  "Leaving already?" << endl;
        cout << "Yes . . . . . . . . . . . . press 1" << endl;
        cout << "No  . . . . . . . . . . . . press 2" << endl;
        cout << "***************************************************" << endl;

        //GET USER'S INPUT AND STORE IN quit.
        cin >> quit;



        ValidateEntry(quit, 1, 2); //validate if entry is between 1 and 2


        if (quit == 2) //IF quit IS EQUALS 2
        Menu(); //PASS CONTROL TO Menu().

        if (quit == 1) //if quit is 1, output concluding message to user
        {cout << "***************************************************" << endl;

        //IF calorie total is greater than calorie goal, display this message
        if (CalorieTotal > CalGoal)
        {cout << setw(30) << " You exceeded your calorie goal!" << endl;
        cout << setw(30) << " Consider taking a jog around the neighborhood" << endl;
        cout << setw(30) << " to decrease your caloric intake." << endl;}

        //IF calorie total is less than calorie goal, display this message
        if (CalorieTotal < CalGoal)
        {cout << setw(30) << "Congratulations, you consumed less than" << endl;
        cout << setw(30) << "your calorie goal. Feel free to enjoy " << endl;
        cout << setw(30) << "a snack to increase your caloric intake." << endl;}

        //IF calorie total is equal to calorie goal, display this message
        if (CalorieTotal == CalGoal)
        {cout << setw(35) << "You have met your calorie goal!" << endl;
        cout << setw(30) << "Only water for the rest of the day!" << endl;}

        //OUTPUT GOODBYE MESSAGE TO USER
        cout<<setw(44) << "Thank you for using the Calorie Tracker program!" << endl;
        cout<<setw(30) << "Come back soon!" << endl;


        cout << "***************************************************" << endl;}

        //TERMINATE PROGRAM
        exit(0);
        abort();


}

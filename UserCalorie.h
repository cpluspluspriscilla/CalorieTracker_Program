//Priscilla Cook
//UserCalorie Implementation File
//February 5th, 2023
//This class declares the class UserCalorie
//and all of its members.

#ifndef USERCALORIE_H
#define USERCALORIE_H

using namespace std;

class UserCalorie
{


    public:
        UserCalorie();

        struct FoodItem{
        int itemCals;
        string name;};

        struct Goal{
        float gender;
        float age;
        float weight;
        float height;
        int heightFt;
        int heightIn;
        float activity;
        };

        void Welcome();
        void Menu();
        void SetCalGoal();
        void CalculateGoal();
        void ManualGoal();
        void PrintCalTotal();
        void FoodHistory();
        void NewFood();
        void Quit();
        void ValidateEntry(int &obj, int lower, int upper);
        void CalcDeficit();

    protected:

    private:
        int CalorieTotal;
        int CalGoal;
        int MenuEntry;
        int quit;
        int totalFoodItems;
        int numOfNewFoodItems;
        string name;
        int addMore;
        int calcOrNo;
        int CaloriesBurnt;
        int CalDeficit;
        string DeficitWords;
        int recalc;
        int viewhis;
        int modify;
        int validEntry;
        int gender;
        int age;
        int weight;
        int itemCals;
        int activity;


        FoodItem foodItems[10000];
        Goal userGoal;

};

#endif // USERCALORIE_H

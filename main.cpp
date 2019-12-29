//
//  main.cpp
//  Temperature
//
//  Created by Lukács Zsombor on 2019. 12. 28..
//  Copyright © 2019. Lukács Zsombor. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct days_temperatures {
    
    int day;
    int temperature;
    
};

int main(int argc, const char * argv[]) {
    
    //Declarations
    int places;
    //cout << "Places: \n";
    cin >> places;
    
    
    int days;
    //cout << "Days: \n";
    cin >> days;
    
    
    int temperatures[1200][1200];
    
    int temp;
    
    //Fill array with temperatues
    //cout << "Enter temperatures: \n";
    for(int i = 0; i < places; i++){
        for(int j = 0; j < days; j++){
            
            cin >> temp;
            temperatures[i][j] = temp;
        }
    }
    
    
    //Check the highets temperatures and store the days to a vector
    days_temperatures highest_temperature = {0, temperatures[0][0]};
    vector<days_temperatures> highest_days;
    
    highest_days.push_back(highest_temperature);
    int temp_highest_counter = 0;
    int full_highest_counter = 0;
    
    for(int i = 0; i < days; i++){
        for(int j = 0; j < places; j++){
            
            if(i != 0 || j != 0) {
            //cout << "Actual: " << temperatures[j][i] << "\n";
            
            if(highest_temperature.temperature < temperatures[j][i]) {
                highest_temperature = {i,temperatures[j][i]};
                highest_days.clear();
                highest_days.push_back(highest_temperature);
                temp_highest_counter = 0;
                temp_highest_counter++;
                

            }
            else if(highest_temperature.temperature == temperatures[j][i]) {
                days_temperatures current = {i, temperatures[j][i]};
                highest_days.push_back(current);
                temp_highest_counter++;

            }
                
            }
            
        }
        if (temp_highest_counter > full_highest_counter) {
            full_highest_counter = temp_highest_counter;
        }
        temp_highest_counter = 0;
    }
    
//    cout << "Highest counter: " << full_highest_counter << "\n";
//
//    for(int i = 0; i < highest_days.size(); i++){
//
//        cout << "Days: " << highest_days[i].day+1;
//        cout << " Temperatures: " << highest_days[i].temperature << "\n";
//
//    }
    
    //Check for similar items
    vector<int> final_highest_days;
    
    int day_counter = 1;
    int actual_day = highest_days[0].day;
    for (int i = 1; i < highest_days.size(); i++){
        
        if(actual_day != highest_days[i].day) {
            day_counter = 1;
            actual_day = highest_days[i].day;
        }
        
        if (highest_days[i].day == actual_day) {
            day_counter++;
        }
        
        if(day_counter == full_highest_counter) {
            final_highest_days.push_back(highest_days[i].day);
        }
    }
    
    cout << final_highest_days.size() << " ";
    for (int i = 0; i < final_highest_days.size(); i++) {
        
        cout << final_highest_days[i]+1 << " ";
        
    }

    cout << "\n";
    
//    vector<int> single_highest_days;
//    single_highest_days.push_back(highest_days[0]);
//
//    int counter = 0;
//    for(int i = 1; i < highest_days.size(); i++){
//        while(counter < single_highest_days.size() && single_highest_days[counter] != highest_days[i]) {
//            counter++;
//        }
//        if(counter == single_highest_days.size()) {
//            single_highest_days.push_back(highest_days[i]);
//        }
//        counter = 0;
//    }
//
//    //Result
//    cout << single_highest_days.size() << " ";
//    for (int i = 0; i < single_highest_days.size(); i++) {
//        cout << single_highest_days[i]+1 << " ";
//    }
//    cout << "\n";
//
//
//    return 0;
}

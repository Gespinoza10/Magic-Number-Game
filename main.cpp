/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Gerardo Espinoza
//Assignment #2 Magic Number Game 
//March 13, 2022

#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

const int MIN_VALUE{1};
const int MAX_VALUE{1000};

int main()
{
    // This is used to seed the random number generator
    random_device myRandomDevice;
    // Creates a random number generator 
    default_random_engine randomEngine{myRandomDevice()};
    uniform_int_distribution<unsigned int> randomInt{MIN_VALUE,MAX_VALUE};
    
    // define and assign variables 
    char response; 
    unsigned int numberedGuessed;
    unsigned int timesGuessed=0;
    unsigned int timesPlayed=0;
    unsigned int totalGuesses=0;
    unsigned int leastGuesses;
    unsigned int greatestGuesses;
    
    //Prompt user if they'd like to guess the magic number
    do{
        cout<<"Do you want to guess the magic number? Press Y or y for yes, press N or n for no: ";
        cin>>response;
    
         //If they response Yes, we generate the next steps
         if (response == 'Y' || response == 'y'){
            unsigned int randomNumber = randomInt(randomEngine);
            //cout<<randomNumber<<endl;
            cout<<"Guess the magic number 1-1000? ";
            cin>>numberedGuessed;
            timesGuessed=1;
            timesPlayed++;
            
            //If they guess wrong give users a hint, have them guess again        
            while(numberedGuessed!=randomNumber){
                if(numberedGuessed>randomNumber){
                    cout<<"Incorrect the magic number is lower than " <<numberedGuessed<<endl;
                    cout<<"Guess the magic number 1-1000? "<<endl;
                    cin>>numberedGuessed;
                    timesGuessed++;
                }
                else{
                    cout<<"Incorrect the magic number is higher than " <<numberedGuessed<<endl;
                    cout<<"Guess the magic number 1-1000? "<<endl;
                    cin>>numberedGuessed;
                    timesGuessed++;
                }
            }
            //When they have guessed correctly we output the correct number and how many guesses it took to get it correct
            cout<<"Correct, the magic number is " <<randomNumber<< " and you guessed it in " <<timesGuessed<< " tries."<<endl;
            
            //Keep track of total guesses from all the games by assigning to total guesses
            totalGuesses += timesGuessed;
            
            //keeping track of the largest and least amount of guesses
            if(timesPlayed == 1){
                leastGuesses = timesGuessed;
                greatestGuesses = timesGuessed;
            }
            if(timesGuessed>leastGuesses){
                greatestGuesses = timesGuessed;
            }
            else {
                leastGuesses = timesGuessed;
            }
            
        }
        //Display the users stats if they no longer chose to play, but played atleast once   
        else if(response =='N'||response =='n' && timesPlayed >= 1){
            
            float averageGuesses = static_cast<float>(totalGuesses)/timesPlayed;
            int precision = 1;
            
            cout<<"Number of games played: " <<timesPlayed<< endl;
            cout<<"Average number of guesses: " <<fixed<<setprecision(precision)<<averageGuesses<<endl;
            cout<<"Largest amount of guesses: "<<greatestGuesses<<endl;
            cout<<"Least amount of guesses: " <<leastGuesses<<endl;
            break;
        }
        else if(response=='N'||response=='n'){
            cout<<"Good Bye"<<endl;
            break;
            
        }
        else{
            cout<<"Invalid Response!!!"<<endl;
            
        }
    }while(true);
}






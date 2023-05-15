/*
    Christian Chacon | 5/13/23

    Practice - Create a program that will take a persons order of coffee with cream and sugar.
*/

#include <iostream>
#include <limits>

void orderCoffee(char &coffeeSize, short int &coffeeFlavor, bool &cream, bool &sugar);
float displayOrder(char coffeeSize, short int coffeeFlavor, bool cream, bool sugar);

int main(){    
    char input, coffeeSize;
    short int coffeeFlavor;
    short int countLoop = 0;
    float totalSales = 0.00;
    bool cream = false, sugar = false;

    do{
        orderCoffee(coffeeSize, coffeeFlavor, cream, sugar);//references all arguments
        totalSales += displayOrder(coffeeSize, coffeeFlavor, cream, sugar);

        std::cout<<"\nWould you like another coffee? (Y/N)";
            std::cin>>input;
            input = toupper(input);

            while(std::cin.fail() || (input != 'Y' && input != 'N')){
                std::cout<<"\nInvalid. Try again.";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout<<"\nWould you like another coffee? (Y/N)";
                    std::cin>>input;
                    input = toupper(input);
            }
        
        countLoop++;
        cream = false;//reset boolean values
        sugar = false;

    }while(input != 'N');

    std::cout<<"\nYou sold "<<countLoop<<" coffee's, with $"<<totalSales<<" in gross sales."<<std::endl;

    return 0;
}

void orderCoffee(char &coffeeSize, short int &coffeeFlavor, bool &cream, bool &sugar){
    std::string flavors[5] = {"House   ", "Iced    ", "Vanilla ", "Hazelnut", "Mocha   "};
    char inputCream, inputSugar;

    std::cout<<"\nWhat size of coffee would you like?"<<std::endl;
    std::cout<<"\n (S)mall\n (M)edium\n (L)arge\n  ->";
        std::cin>>coffeeSize;
        coffeeSize = toupper(coffeeSize);

        while(std::cin.fail() || (coffeeSize != 'S' && coffeeSize != 'M' && coffeeSize != 'L')){
            std::cout<<"\nInvalid. Try again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat size of coffee would you like?"<<std::endl;
            std::cout<<"\n (S)mall\n (M)edium\n (L)arge\n  ->";
                std::cin>>coffeeSize;
                coffeeSize = toupper(coffeeSize);
        }
    
    std::cout<<"\nWhat flavor would you like?"<<std::endl;
    for(int x = 0; x < 5; x++){std::cout<<" "<<flavors[x]<<" - "<<x+1<<std::endl;}
    std::cout<<"  ->";
        std::cin>>coffeeFlavor;

        while(std::cin.fail() || (coffeeFlavor < 1 || coffeeFlavor > 5)){
            std::cout<<"\nInvalid. Try again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat flavor would you like?"<<std::endl;
            for(int x = 0; x < 5; x++){std::cout<<" "<<flavors[x]<<" - "<<x+1<<std::endl;}
            std::cout<<"  ->";
                std::cin>>coffeeFlavor;
        }

    std::cout<<"\nWould you like cream? (Y/N) ";
        std::cin>>inputCream;
        inputCream = toupper(inputCream);

        while(std::cin.fail() || (inputCream != 'Y' && inputCream != 'N')){
            std::cout<<"\nInvalid. Try again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWould you like cream? (Y/N) ";
                std::cin>>inputCream;
                inputCream = toupper(inputCream);
        }

    if(inputCream == 'Y'){cream = true;}

    std::cout<<"\nWould you like sugar? (Y/N) ";
        std::cin>>inputSugar;
        inputSugar = toupper(inputSugar);

        while(std::cin.fail() || (inputSugar != 'Y' && inputSugar != 'N')){
            std::cout<<"\nInvalid. Try again.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWould you like sugar? (Y/N) ";
                std::cin>>inputSugar;
                inputSugar = toupper(inputSugar);
        }

    if(inputSugar == 'Y'){sugar = true;}
}

float displayOrder(char coffeeSize, short int coffeeFlavor, bool cream, bool sugar){
    float totalPrice;

    std::cout<<"\nYour coffee order: "<<std::endl;

    switch(coffeeSize){
        case 'S':
            std::cout<<"      Small ";
            totalPrice = 3.00;
                break;
        case 'M':
            std::cout<<"      Medium ";
            totalPrice = 4.50;
                break;
        case 'L':
            std::cout<<"      Large ";
            totalPrice = 6.00;
                break;
        default:
            std::cout<<"Error"<<std::endl;
                break;
    }

    switch(coffeeFlavor){
        case 1:
            std::cout<<"house coffee ";
                break;
        case 2:
            std::cout<<"iced coffee ";
                break;
        case 3:
            std::cout<<"vanilla coffee ";
                break;
        case 4:
            std::cout<<"hazelnut coffee ";
                break;
        case 5:
            std::cout<<"mocha coffee ";
                break;
        default:
            std::cout<<"Error"<<std::endl;
                break;
    }

    if(cream && (sugar == false)){
        std::cout<<"with cream"<<std::endl;
    }
    else if(sugar && (cream == false)){
        std::cout<<"with sugar"<<std::endl;
    }
    else if(cream == true && sugar == true){
        std::cout<<"with cream and sugar"<<std::endl;
    }
    else{
        std::cout<<""<<std::endl;
    }

    std::cout<<"      Total Due: $"<<totalPrice<<std::endl;
    return totalPrice;
}


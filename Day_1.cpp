#include <iostream>
#include <string>

void menu(){
  std::cout << "-----Menu----\n";
  std::cout << "1. Append Your Reminder\n";
  std::cout << "2. View Your List\n";
  std::cout << "3. Remove Your Reminder\n";
  std::cout << "4. Turn off the Menu To-do-List\n";
}

void Append(std::string list[],int &count,int &note){
  int i=1,j;
  char choice;
  while(i){
    std::string work;
    std::cout << "Input Your Work-note: \n";
      for(j=1;j<=note;j++){
        std::cout<< j <<". ";
        std::getline(std::cin, work);
        if (work.empty()) {
            std::cout << "Cannot be empty. Please type again.\n";
            j--;
            continue;
        }
        count++;
        list[count-1]=work;
      }
      std::cout<<"Append Successfully!\n";
      std::cout<<"Do you want to add more? (y/n):";
      std::cin>>choice;
      std::cin.ignore();
      if (choice == 'y'||choice == 'Y'){
        std::cout<< "How many more note you want to append: ";
        std::cin >> note;
        std::cin.ignore();
      }
      else{
        i=0; 
      }
  }
}

void View(std::string list[],int &count){
  bool empty = true;
  for(int i = 0; i < count; i++) {
    if (!list[i].empty()) {
        empty = false;
        break;
    }
  }
  if (empty){
    std::cout << "Your To-do-List is empty!\n";
  }
  else{
    std::cout << "Your To-do-List:\n";
  }
  for (int i = 0; i <count; i++){
    if (!list[i].empty()){
      std::cout << i+1 << ". " << list[i] << '\n';
    }
  }
}

void Remove(std::string list[],int &count){
  View(list,count);
  int i;
  bool empty = true;
  for(int i = 0; i < count; i++) {
    if (!list[i].empty()) {
        empty = false;
        break;
    }
  } 
  if (empty){
    std::cout << "Nothing to remove! Your To-do-List is empty!\n";
    return;
  }
  while(1){
    std::cout << "Input the note number you want to remove(0 escape this option): ";
    std::cin >> i;
    std::cin.ignore();
    if(i>0 && i<=count && !list[i-1].empty()){
      list[i-1].clear();
      std::cout << "-------------Remove Successfully!-------------\n";
    }
    else if(i==0)
      return;
    else{
      std::cout << "Invalid note number! Try again.\n";
    }
  }
}

int main(){
  int n,i=1,count=0,note;
  char choice;
  std::string list[1000];
  menu();
  while(i){
    std::cout << "\nChoose your option: ";
    std::cin >> n;
    std::cin.ignore();
    std::cout<<'\n';
    switch(n){
      case 1:
        std::cout<< "Enter how many note you want to append: ";
        std::cin >> note;
        std::cin.ignore();
        Append(list,count,note);
        break;
      case 2:
        View(list,count);
        menu();
        break;
      case 3:
        Remove(list,count);
        break;
      case 4:
        i=0;
        break;
      default:
        std::cout<<"Invalid option! Try again\n";
    }
    if (n==4){
      continue;
    }
    std::cout<<'\n';
    std::cout<<"Return to Menu? (y/n): ";
    std::cin>>choice;
    std::cin.ignore();
    if (choice=='y'||choice=='Y'){
      menu();
    }
    else{
      i=0;
    }
  }
  std::cout<<"-----Hope you satisfied!------\n";
  return 0;
}
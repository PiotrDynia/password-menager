#pragma once
#include <iostream>
struct passInfo{
    std::string name;
    std::string password;
    std::string category;
    passInfo *next;
    passInfo();
};

passInfo::passInfo() {
    next = nullptr;
}

struct list{
    passInfo *first;
    void addPassword(std::string name, std::string password, std::string category);
    void deletePassword (int nr);
    void showList() const;
    void filter(const std::string& category) const;
    void deleteCategory(const std::string& category);
    void writeToFile(std::ofstream &file) const;
    void addCategory(std::string category);
    void passLengthSort() const;
    void nameLengthSort() const;
    list();
};

list::list() {
    first = nullptr;
}

void list::addPassword(std::string name, std::string password, std::string category) {
    auto *newInfo = new passInfo;
    newInfo->name = name;
    newInfo->password = password;
    newInfo->category = category;

    if (first == nullptr){
        first = newInfo;
    }
    else{
        passInfo *temp = first;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = newInfo;
        newInfo->next = nullptr;
    }
}

void list::showList() const {
    passInfo *temp = first;

    while(temp){
        std::cout << "Name: " << temp->name << " Password: " << temp->password << " Category: "
        << temp->category << std::endl;
        temp=temp->next;
    }
}
void list::filter(const std::string& category) const{
    passInfo *temp = first;

    while(temp){
        if (temp->category == category){
            std::cout << "Name: " << temp->name << " Password: "
                 << temp->password << " Category: " << temp->category << std::endl;
            temp=temp->next;
        }
        else{
            temp=temp->next;
        }
    }
}

void list::addCategory(std::string category){
    auto *newInfo = new passInfo;
    newInfo->name = nullptr;
    newInfo->password = nullptr;
    newInfo->category = category;

    if (first == nullptr){
        first = newInfo;
    }
    else{
        passInfo *temp = first;

        while(temp->next){
            temp = temp->next;
        }
        temp->next = newInfo;
        newInfo->next = nullptr;
    }
}
void list::deleteCategory(const std::string& category){
    passInfo *previous = nullptr;
    passInfo *temp = first;

    while(temp){
        passInfo *toDelete = nullptr;
        if (temp->category == category){
            if(previous){
                previous->next = temp->next;
            }
            else{
                first = first->next;
            }
            toDelete = temp;
        }
        if (toDelete) {
            temp = temp->next;
            delete toDelete;
        }
        else{
            previous = temp;
            temp = temp->next;
        }
    }
}

void list::deletePassword(int nr) {
    if (nr==1){
        passInfo *temp = first;
        first = temp->next;
        delete temp;
    }
    else if (nr>=2){
        int j = 1;
        passInfo *temp = first;

        while(temp){
            if ((j+1)==nr) break;

            temp = temp->next;
            j++;
        }
        if (temp->next->next==nullptr){
            delete temp->next;
            temp->next = nullptr;
        }
        else{
            passInfo *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
}

void list::writeToFile (std::ofstream &file) const{
    passInfo *temp = first;
    while (temp){
        file << temp->name << "," << temp->password << "," << temp->category << std::endl;
        temp = temp->next;
    }
    file.close();
}

void list::passLengthSort() const{
    passInfo* temp = first;
    std::string tempName;
    std::string tempPassword;
    std::string tempCategory;
    int counter = 0;

    while (temp){
        temp = temp->next;
        counter++;
    }

    temp = first;

    for (int i = 0; i<counter; i++){
        while (temp->next){
            if (temp->password.length() > temp->next->password.length()){
                tempName = temp->name;
                temp->name = temp->next->name;
                temp->next->name = tempName;

                tempPassword = temp->password;
                temp->password = temp->next->password;
                temp->next->password = tempPassword;

                tempCategory = temp->category;
                temp->category = temp->next->category;
                temp->next->category = tempCategory;
            }
            else
                temp=temp->next;
        }
        temp = first;
    }
}

void list::nameLengthSort() const{
    passInfo* temp = first;
    std::string tempName;
    std::string tempPassword;
    std::string tempCategory;
    int counter = 0;

    while (temp){
        temp = temp->next;
        counter++;
    }

    temp = first;

    for (int i = 0; i<counter; i++){
        while (temp->next){
            if (temp->name.length() > temp->next->name.length()){
                tempName = temp->name;
                temp->name = temp->next->name;
                temp->next->name = tempName;

                tempPassword = temp->password;
                temp->password = temp->next->password;
                temp->next->password = tempPassword;

                tempCategory = temp->category;
                temp->category = temp->next->category;
                temp->next->category = tempCategory;
            }
            else
                temp=temp->next;
        }
        temp = first;
    }
}
void encrypt(int key, char tab[]){
    int length = strlen(tab);

    if(!(key >= -26 && key <= 26))
        return;

    if(key >= 0)
        for(int i=0;i<length;i++)
            if(tab[i] + key <= 'Z')
                tab[i] += key;
            else
                tab[i] = tab[i] + key - 26;
    else
        for(int i=0;i<length;i++)
            if(tab[i] + key >= 'A')
                tab[i] += key;
            else
                tab[i] = tab[i] + key + 26;
}
